#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> Q;
queue<int> V;


int Select_Process(int AT[],int time,int n);
void Add_to_queue(int AT[]);
void show_process(int AT[],int BT[],int CT[],int TA[],int WT[],int n);

int main()

{
    int n,time = 0,TQ;

    cout << "Enter No of process: ";
    cin  >> n;
    cout << "\nEnter Time quantum: ";
    cin  >> TQ;

    int AT[n+5],AT_dup[n+5],BT[n+5],BT_dup[n+5],CT[n+5],TA[n+5],WT[n+5];

    for (int i=1 ;i<=n; i++)
    {
        cout << "\n Enter Arrival Time and Burst Time of  process no  "<< i <<" ";
        cin  >> AT[i] >> BT[i];
        AT_dup[i] = AT[i];
        BT_dup[i] = BT[i];
     }


    while (AT[n]!=-1)
    {
        int res = Select_Process(AT,time,n);

        if (res == -1) time +=1;

        else if (res == 1)
        {
            Add_to_queue(AT);
            while(Q.empty() == false)
            {
                int x = Q.front();
                Q.pop();

                if (BT[x] <= TQ)
                {
                    time += BT[x];
                    CT[x] = time;
                    TA[x] = CT[x] - AT_dup[x];
                    WT[x] = TA[x] - BT_dup[x];
                    BT[x] = 0;

                }

                else
                {
                    BT[x] = BT[x] -TQ;
                    time   += TQ;

                    if (AT[n]!=-1 )
                    {
                        int res = Select_Process(AT,time,n);

                        if (res == -1)time +=1;

                        else
                        {
                            Add_to_queue(AT);
                        }
                    }
                    Q.push(x);
                }
            }
        }
    }

show_process(AT_dup,BT_dup,CT,TA,WT,n);

}


int Select_Process(int AT[],int time,int n)
{   int Arrived_process = 0;
    for(int i=0 ;i<= n; i++)
    {
        if (AT[i] <= time and AT[i]!=-1)
        {
           V.push(i);
           Arrived_process += 1;
        }

    }

    if (Arrived_process == 0)return -1;

    else
    {
        return 1;
    }

}

void Add_to_queue(int AT[])

{
   while(V.empty() == false)

   {
    int x = V.front();
    AT[x] =-1;
    V.pop();
    Q.push(x);
    }

}


void show_process(int AT[],int BT[],int CT[],int TA[],int WT[],int n)
{


printf("\n ________________________ROUND ROBIN ALGORITHM______________________________");

printf ("\n\n");
printf("S.NO\tAT\tBT\tCT\tTA\tWT");
float wt_sum=0,ta_sum=0;

for(int i=1 ;i <= n ; i++)
{
printf("\n%d\t%d\t%d\t%d\t%d\t%d",i,AT[i],BT[i],CT[i],TA[i],WT[i]);

wt_sum+=WT[i];
ta_sum+=TA[i];

}

printf("\n Average weighting time is %f",wt_sum/n);
printf("\n Average turn around time is %f",ta_sum/n);

}





