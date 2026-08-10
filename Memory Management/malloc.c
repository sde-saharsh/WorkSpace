#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = malloc(4 * sizeof(int));

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;

    int *temp = realloc(arr, 8 * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
    }

    arr = temp;
    arr[4] = 10;
    arr[5] = 20;
    arr[6] = 30;
    arr[7] = 400;

    for (int i = 0; i < 8; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;
    printf("\n");

    free(arr);
    arr = NULL;

    if (arr == NULL)
    {
        printf("Invalid can't print this !\n");
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            printf("arr[%d] : %d\n", i, arr[i]);
        }
    }
}