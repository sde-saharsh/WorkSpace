#include <stdio.h>

int sizeOf(int arr[]){
    return sizeof(arr)/sizeof(arr[0]);
}

int main()
{
    int age = 20;
    float height = 5.71;
    char grade = 'a';

    printf("Age : %d\n",age);
    printf("Height : %.10f\n",height);
    printf("Grade : %c\n",grade);

    unsigned int x = 10;

    printf("Number : %u\n",x);

    // string name = "saharsh"; -- not valid
    char name[] = "saharsh";
    printf("name: %s\n",name);

    int arr[5] = {10,20,30,40,50};
    int size =  sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }

    int n = sizeOf(arr);
    printf("Number: %d\n",n);

    // char buffer[1024]
}