#include <stdio.h>
#include <string.h>

void change(int *x)
{
    *x = 100;
}

int main()
{
    printf("Code started\n");

    int y = 10;
    change(&y);
    printf("y : %d\n", y);

    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("%d\n", *p); //- value at the x
    printf("%p\n", p);  //- address of the x
    printf("%p\n", &p); //- address of the p

    printf("%d\n", **pp); //- value at the x
    printf("%p\n", *pp);  //- address of the x
    printf("%p\n", pp);   //- address of the p
    printf("%p\n", &pp);  //- address of the pp

    char name[50] = "saharsh khalokar";

    printf("name : %s\n", name);
    printf("name 0 : %c\n", name[10]);

    char *ptr = name;

    int i = 0;

    while (*(ptr + i) != '\0')
    {
        printf("i : %c\n", *(ptr + i));
        i++;
    }



    printf("code ended");
}
