#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat info;

    if(stat("hello.data", &info) == -1)
    {
        printf("stat failed\n");
        return 1;
    }

    printf("Device      : %lu\n", info.st_dev);
    printf("Inode       : %lu\n", info.st_ino);
    printf("Mode        : %o\n", info.st_mode);
    printf("Links       : %lu\n", info.st_nlink);
    printf("UID         : %u\n", info.st_uid);
    printf("GID         : %u\n", info.st_gid);
    printf("Size        : %ld bytes\n", info.st_size);
    printf("Block Size  : %ld\n", info.st_blksize);
    printf("Blocks      : %ld\n", info.st_blocks);
    printf("Access      : %s", ctime(&info.st_atime));
    printf("Modified    : %s", ctime(&info.st_mtime));
    printf("Changed     : %s", ctime(&info.st_ctime));

    return 0;
}