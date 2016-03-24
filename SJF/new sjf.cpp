#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> V;
priority_queue <pair <int,int> > P;

int Select_Process(int AT[],int time,int n);
void Add_to_queue(int AT[],int BT[]);
void show_process(int AT[],int BT[],int CT[],int TA[],int WT[],int n);

int main(){

    int n,time=0;
    pair<int,int> out;

    cout << "\nEnter No of process: ";
    cin  >> n;

    int AT[n+5],AT_dup[n+5],BT[n+5],CT[n+5],TA[n+5],WT[n+5];

    for (int i=1 ;i<=n; i++){

        cout << "\n Enter Arrival Time and Burst Time of  process no  "<< i <<" ";
        cin  >> AT[i] >> BT[i];
        AT_dup[i] = AT[i];
    }

    while (AT[n]!=-1){
        int res = Select_Process(AT,time,n);

        if (res == -1)time +=1;
        else if (res == 1){

        Add_to_queue(AT,BT);

        while(P.empty() == false)
        {
             out = P.top();
             P.pop();

             time += -1*out.first;
             CT[out.second] = time;
             TA[out.second] = CT[out.second] - AT_dup[out.second];
             WT[out.second] = TA[out.second] - BT[out.second];

             if ( AT[n] != -1 )
             { int res = Select_Process(AT,time,n);

                if (res == -1)time +=1;

                else{

                    Add_to_queue(AT,BT);

                    }
              }
        }
        }


    }
    show_process(AT_dup,BT,CT,TA,WT,n);
}

int Select_Process(int AT[],int time,int n)
{
    int Arrived_process = 0;

    for(int i=1;i<=n;i++){

        if (AT[i] <= time and AT[i]!=-1){
           V.push_back(i);
           Arrived_process += 1;
        }
    }

    if (Arrived_process == 0)return -1;

    else{
    return 1;
    }
}



void Add_to_queue(int AT[],int BT[])
{

 while(V.empty() == false){

    int x = V.back();
    AT[x] =-1;
    V.pop_back();
    P.push(make_pair(-1*BT[x],x));

    }

}




void show_process(int AT[],int BT[],int CT[],int TA[],int WT[],int n)
{


printf("\n ________________________SHORTEST JOB FIRST______________________________");

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
