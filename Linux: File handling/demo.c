#include<stdio.h>
#include<fcntl.h>
// #include<unistd.h>

int main(){

    int fd = open("share.txt",O_RDONLY | O_CREAT ,0400);

    if(fd == -1){
        perror("opened");
        return 0;
    }

    return 1;

}