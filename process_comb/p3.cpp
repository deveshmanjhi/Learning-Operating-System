#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int Twice(int x);

int main(int argc,char *argv[])
{
    printf("PROCESS TWICE RUNNING....\n");
    printf("PROCESS TWICE PID = %d\n",getpid());


    if (argc == 2 ){
    int num = atoi(argv[1]);

    printf("RESULT = %d\n",Twice(num));

    }

    else if(argc > 2){

        char* args[argc];
        char buffer[100];

        for (int i=1; i <= argc ;i++){
                args[i-1] = argv[i];
            }

        int num  = atoi((argv[argc-1]));
        snprintf(buffer,sizeof(buffer),"%d",Twice(num));

        printf("TWICE  = %d\n",Twice(num));

        args[argc-2] = buffer;

        args[argc-1]= NULL;


        execvp(args[0],args);

        }



        }

int Twice(int n){

return 2*n;

}
