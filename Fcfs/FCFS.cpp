#include<stdio.h>
#include<iostream>
using namespace std;

int main(){

//CREATE ARRAY FOR ARRIVAL-TIME,BURST-TIME,TURN-AROUND-TIME,COMPLETION-TIME,WEIGHTING-TIME FOR DIFFERENT PROCESS


int n,AT[100],BT[100],TAT[100],CT[100],WT[100];
int ct =0;

cout << "Enter no of processes  ";              //GET NO OF PROCESSES
cin >> n;

//GET ARRIVAL TIME AND EXECUTION TIME
for (int i=1 ; i<= n;i++){

cout << "\nEnter Arrival At time and Burst time for process " << i <<" ";
cin >> AT[i];
cin >> BT[i];
ct  += BT[i];
CT[i] = ct;                         //CALCULATE COMPLETION TIME
TAT[i] = CT[i] - AT[i];             //CALCULATE TURN AROUND TIME
WT[i]  = TAT[i] - BT[i];            //CALCULATING WEIGHTING TIME



}
cout << "\n";

cout << "PID\t";
cout << "AT\t";
cout << "BT\t";
cout << "CT\t";
cout << "TAT\t";
cout << "WT\t";

for (int i=1 ; i<= n;i++){
cout << "\n";
cout << i <<"\t";
cout << AT[i] <<"\t";
cout << BT[i] <<"\t";
cout << CT[i] <<"\t";
cout << TAT[i] <<"\t";
cout << WT[i] <<"\t";


}
int avgtat=0,avgwt=0;


for(int i= 1 ;i<=n ; i++){

avgtat += TAT[i];           //CALCULATE AVERAGE TURN-AROUND-TIME
avgwt  += WT[i];            //CALCULATE AVERAGE WEIGHTING-TIME

}
double f,g;
f= avgtat/n;
g= avgwt/n;
cout <<"\nAVERAGE TURN AROUND TIME" << f;
cout << "\nAVERAGE WEIGHTing TIME " << g;






}
