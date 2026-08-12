#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int id;
    char name[50];
    float makrs;
} Student ;

int main(){

    Student s1;
    
    printf("Enter ID: ");
    scanf("%d",&s1.id);

    printf("Enter name :");
    scanf("%49s", s1.name);

    printf("Enter marks :");
    scanf("%f",&s1.makrs);

    FILE * fp = fopen("student.dat","ab");

    if(fp == NULL){
        printf("File opening failed!");
        return 0;
    }

    size_t written = fwrite(&s1,sizeof(s1),1,fp);

    if(written != 1){
        printf("write failed!");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    printf("Student saved successfully\n");

    return 0;
}