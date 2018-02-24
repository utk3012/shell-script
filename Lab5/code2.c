#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc,char *argv[]){
        pid_t pid;
        pid=fork();
        int i,j;
        char *temp;
        int status;
        if(pid==0) {
                printf("Entered child process. Sorted : \n");
                char *temp;
                for( i=0;i<argc-1;i++){
                        for( j=1;j<argc-i-1;j++){
                                if(strcmp(argv[j],argv[j+1])>0){
                                        temp=argv[j];
                                        argv[j]=argv[j+1];
                                        argv[j+1]=temp;

                                }
                        }
                }
                for(i=1;i<argc;i++){
                        puts(argv[i]);
                }
        }
        else{
                wait(&status);
                printf("This is the parent process. Displaying with sort:\n");
                for(i=1;i<argc;i++)
                printf("%s\n",argv[i]);
        }
}
