#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    __pid_t pid = fork();

    // printf("PID = %d\n", getpid());
    // printf("PPID = %d\n", getppid());

    if(pid < 0){
        printf("failed to fork!\n");
    }
    else if(pid ==0 ){
        printf("In child process!\n");
        exit(23);
    } else{
        int status;
        wait(&status);
        printf("%d\n",status);
        printf("parent process!\n");
    }

    return 3;
}   