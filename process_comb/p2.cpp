#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int Half(int x);

int main(int argc,char *argv[])
{
    printf("PROCESS HALF RUNNING....\n");
    printf("PROCESS HALF PID = %d\n",getpid());


    if (argc == 2 ){
    int num = atoi(argv[1]);

    printf("RESULT = %d\n",Half(num));

    }

    else if(argc > 2){

        char* args[argc];
        char buffer[100];

        for (int i=1; i <= argc ;i++){
                args[i-1] = argv[i];
            }

        int num  = atoi((argv[argc-1]));
        snprintf(buffer,sizeof(buffer),"%d",Half(num));

        printf("HALF  = %d\n",Half(num));

        args[argc-2] = buffer;

        args[argc-1]= NULL;


        execvp(args[0],args);

        }



        }

int Half(int n){

return n/2;

}
