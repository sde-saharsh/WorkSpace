#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("data.txt", "r");

    // Check whether the file was opened successfully
    if (fp == NULL) {
        printf("File does not exist or cannot be opened!\n");
        return 1;
    }

    printf("File opened successfully!\n");

    // fputs("Hello\n",fp);
    // fputs("Saharsh\n",fp);

    char str[100];

    while(fgets(str,100,fp)){
        printf("%s",str);
    }

    // printf("%s\n",str);

    fclose(fp);

    printf("File closed!\n");

    return 0;
}   