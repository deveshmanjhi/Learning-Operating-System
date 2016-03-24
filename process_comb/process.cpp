#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])

{

    printf("----------MAIN PROCESSES RUNNING-----------\n");
    printf(" MAIN PROCESS PID  = %d\n",getpid());

    if (argc  >= 2)

    {

        char* args[argc];


        for (int i=1; i <= argc ;i++){
            args[i-1] = argv[i];
            }


        printf("INPUT = %s\n",argv[argc-1]);
        execvp(args[0],args);



        return 0;




    }

    else{
    printf("\n TOO FEW ARGUMENTS...");
    }


}

