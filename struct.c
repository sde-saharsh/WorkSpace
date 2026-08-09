#include<stdio.h>
#include<string.h>

// data - actual array 
// size - kitne items 
// capacity - kitni spaces 

struct Student
{
    char name[50];
    int age;
    float marks;
};

typedef struct
{
    char name[50];
    int age;
    float salary;
} Teacher;


int main(){
    printf("Code started");

    struct Student s1;
    strcpy(s1.name,"saharsh");
    s1.age = 21;
    s1.marks = 94;

    printf("name :%s\n",s1.name);
    printf("age : %d\n",s1.age);
    printf("marks : %f\n",s1.marks);

    Teacher t1;
    strcpy(t1.name,"Hiren");
    t1.age = 40;
    t1.salary = 90000.14;

    printf("name :%s\n",t1.name);
    printf("age : %d\n",t1.age);
    printf("marks : %f\n",t1.salary);

    printf("code ended");

}   
