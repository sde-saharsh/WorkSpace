#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("hello.txt", O_RDONLY | O_CREAT ,0644);

    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[100];

    int bytes = read(fd, buffer, 100);

    if(bytes == -1)
    {
        printf("Read failed!\n");
        close(fd);
        return 1;
    }

    printf("Bytes read: %d\n", bytes);

    close(fd);
    
    return 0;
}