#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include <algorithm>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;




typedef void (*sighandler_t)(int);
char c = '\0';

void handle_signal(int signo)
{
	printf("\n>>> ");
	fflush(stdout);
}



void get_args(string inputs,string exec_inputs[]){
string var = "";
int index =0;

for(int i=0;i<inputs.length();i++){
    if (inputs[i]!=32)
        var+=inputs[i];

    else if (inputs[i]==32)
    {
    exec_inputs[index] = var;
    var = "";
    index++;
    }

}
exec_inputs[index]=var;

}


int great_out(string exec_inputs[],int args){

for(int i=0;i<args;i++){
string var = exec_inputs[i];

for(int j=0;j<var.length();j++){
if(var[j]==62){

//printf("\n%d",i);
return i;}


}


}
//printf("\nkjsdhkjSKDJ");
return -1;



}


int great_inp(string exec_inputs[],int args){

for(int i=0;i<args;i++){
string var = exec_inputs[i];

for(int j=0;j<var.length();j++){
if(var[j]==60){

//printf("\n%d",i);
return i;}


}


}
//printf("\nkjsdhkjSKDJ");
return -1;



}



int main(int argc, char *argv[], char *envp[])



{   int check =0;

    signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	string exec_inputs[10];
	string inputs = "";

    if (fork()==0){
	char *arg[]={"clear",NULL};

	execvp(arg[0],arg);


}

    else{
	waitpid(-1, NULL, 0);
	printf("\n>>> ");
	while(c != EOF) {
		c = getchar();
		if (c!=EOF and c!='\n')
		inputs += c;


		if(c == '\n')

		{

            get_args(inputs,exec_inputs);
            if (inputs == "")  printf(">>> ");

             else if (exec_inputs[0]=="cd"){

             chdir((char*)exec_inputs[1].c_str());
             inputs="";
             printf("\n>>> ");

             }

             else if (exec_inputs[0]=="exit"){
             exit(2);
             inputs="";
             printf("\n>>> ");


             }




            else if(fork()==0){
            //printf("child...");
            int n = std::count(inputs.begin(), inputs.end(), ' ');
            char *args[n+2];
            args[n+1]=NULL;
            FILE *fp;

            string help;
            get_args(inputs,exec_inputs);
            for (int i=0 ;i<n+1;i++){

            char *pw = (char*)exec_inputs[i].c_str();

            args[i]=pw;
            }


            int index_great_out = great_out(exec_inputs,n+1);


            if (index_great_out>0){
            args[index_great_out] = NULL;
            fp = fopen((char*)exec_inputs[index_great_out+1].c_str(), "w+");
            dup2(fileno(fp), 1);

            }

            int index_great_inp = great_inp(exec_inputs,n+1);

            if (index_great_inp>0){
            args[index_great_inp] = NULL;
            fp = fopen((char*)exec_inputs[index_great_inp+1].c_str(), "r");
            dup2(fileno(fp), 0);

            }




            execvp(args[0],args);

            printf("\nCMD NOT FOUND");
            exit(0);





            }

        else{
       waitpid(-1, NULL, 0);

        inputs ="";
        printf("\n>>> ");

        }


        }


	}
	printf("\n");

	return 0;
	}
}

