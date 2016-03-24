#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int square(int x);

int main(int argc,char *argv[])
{
    printf("PROCESS SQAURE RUNNING....\n");
    printf("PROCESS SQUARE PID = %d\n",getpid());


    if (argc == 2 ){
    int num = atoi(argv[1]);

    printf("RESULT = %d\n",square(num));

    }

    else if(argc > 2){

        char* args[argc];
        char buffer[100];


        for (int i=1; i <= argc ;i++){
                args[i-1] = argv[i];
            }



        int num  = atoi((argv[argc-1]));

        snprintf(buffer,sizeof(buffer),"%d",square(num));

        printf("SQAURE  = %d\n",square(num));

        args[argc-2] = buffer;

        args[argc-1]= NULL;

        execvp(args[0],args);

        }


}

int square(int n){

return n*n;

}
