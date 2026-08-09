#include<stdio.h>
#include<string.h>

void change(int * x){
    * x = 100;
}

int main(){
    printf("Code started\n");

    int y = 10;
    change(&y);
    printf("y : %d\n",y);


    int x = 10;
    int * p = & x;
    int * * pp = & p;

    printf("%d\n",*p);  //- value at the x
    printf("%p\n", p);  //- address of the x
    printf("%p\n", &p); //- address of the p

    printf("%d\n", **pp);  //- value at the x
    printf("%p\n", *pp);   //- address of the x
    printf("%p\n", pp);    //- address of the p
    printf("%p\n", &pp);    //- address of the pp

    printf("code ended");

}   
