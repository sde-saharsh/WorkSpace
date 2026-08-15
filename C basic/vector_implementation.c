#include<stdio.h>
#include<stdlib.h>

// data - actual array 
// size - kitne items 
// capacity - kitni spaces 

// data ──────────────┐
//                    ↓
//               ┌────┬────┬────┬────┐
//               │ 10 │ 20 │ 30 │    │
//               └────┴────┴────┴────┘
//                 ↑              ↑
//               size=3       capacity=4

typedef struct 
{
    int * data;
    int size;
    int capacity;
} vector;

void initVector(vector * v)
{
    v->size = 0;
    v->capacity = 2;
    v->data = malloc(v->capacity * sizeof(int));

    if(v->data == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void push_back(vector* v,int value)
{
    if(v->size == v->capacity){

        v->capacity = v->capacity*2;
        int * temp = realloc(v->data,v->capacity * sizeof(int));
        
        if(temp == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    v->data[v->size] = value;
    v->size++;
}

int get(vector * v, int index)
{
    if(index<0 || index >= v->size)
    {
        printf("Index out of bound\n");
        exit(1);
    }
    return v->data[index];
}

void freeVector(vector * v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}



int main(){
    printf("Code started");

    vector v;

    initVector(&v);
    push_back(&v,10);
    push_back(&v,20);
    push_back(&v,30);
    push_back(&v,40);
    push_back(&v,50);

    printf("Vector size : %d\n",v.size);
    printf("vector capacity : %d\n",v.capacity);

    for(int i=0;i<v.size;i++){
        printf("%d ",v.data[i]);
    }

    printf("\n");

    printf("Element at index 2 : %d\n",get(&v,2));
    

    printf("code ended");
}