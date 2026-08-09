#include<stdio.h>

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

typedef struct {
    int * data;
    int size;
    int capacity;
} vector;

void initVector(vector *v){
    v->size = 0;
    v->capacity = 2;
    v->data = malloc(v->capacity * sizeof(int));
}

void push_back()

int main(){
    printf("Code started");



    printf("code ended");
}

