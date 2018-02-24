#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
int main(){
        int n,i,j,status;
        pid_t pid1,pid2;
        printf("Enter the number of string N:");
        scanf("%d",&n);
        char array[n][100];
        for(i=0;i<n;i++)
                scanf("%s",&array[i]);
        pid1=fork();
        if(pid1>0)
                pid2=fork();
        if(pid1==0) {
                printf("This is first child process\n");
                printf("Performing bubble sort\n");
                char temp[20];
                for(i=0;i<n-1;i++){
                        for(j=0;j<n-i-1;j++){
                                if(strcmp(array[j],array[j+1])>0){
                                        strcpy(temp,array[j]);
                                        strcpy(array[j],array[j+1]);
                                        strcpy(array[j+1],temp);
                                }
                        }
                }
                printf("Sorted order: \n");
                for(i=0;i<n;i++)
                        printf("%s\n",array[i]);
        }
        else if(pid2==0){
                printf("This is second child process .\n");
		printf("Performing selection sort\n");
                char min[20];
                int key;
                for(i=0;i<n-1;i++){
                        strcpy(min,array[i]);
                        key=i;
                        for(j=i;j<n;j++){
                                if(strcmp(array[j],min)<0){
                                        strcpy(min,array[j]);
                                        key=j;
                                }
                        }
                       strcpy(array[key],array[i]);
                       strcpy(array[i],min);
                }
		printf("Sorted order: \n");
                for(i=0;i<n;i++)
                        printf("%s\n",array[i]);
        }
        else{
                waitpid(pid1,&status,0);
                waitpid(pid2,&status,0);
                printf("\nThis is parent process.\nBoth child processes complete. Sorting performed.\n");
        }
}

