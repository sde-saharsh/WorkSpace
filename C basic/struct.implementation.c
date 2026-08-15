#include<stdio.h>
#include<string.h>

// data - actual array 
// size - kitne items 
// capacity - kitni spaces 

typedef struct{
    char name[50];
    int age;
    int marks;
} Student;

int main(){

    Student s1;
    strcpy(s1.name,"saharsh");
    s1.age = 30;
    s1.marks = 90;

    Student * ptr = &s1;
    printf("%s\n",(*ptr).name);
    printf("%d\n",(*ptr).age);
    printf("%d\n",(*ptr).marks);

    printf("%s\n",ptr->name);
    printf("%d\n",ptr->age);
    printf("%d\n",ptr->marks);
    
}   
