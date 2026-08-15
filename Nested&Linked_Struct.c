#include<stdio.h>
#include<string.h>

typedef struct 
{
    char city[50];
    int pincode;
} Address;

typedef struct 
{
    char name[50];
    int age;
    Address address;
} Student;


int main(){

    Student s1;
    strcpy(s1.name,"saharsh");
    s1.age = 20;
    s1.address.pincode = 444808;
      
    
}