#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("data.txt", "r");

    char str[500];
    
    while (fread(str,1,30,fp))
    {
        printf("%s",str);
    }

    fclose(fp);
    

    return 0;
}   