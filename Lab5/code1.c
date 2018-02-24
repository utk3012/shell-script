#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t pid;
        pid = fork();
        if (pid == 0)
                printf("this is child process with pid %d and ppid %s\n",getpid(),getppid());
        else
                printf("this is parent process with pid %d and ppid %d\n",getpid(),getppid());
}
