#include "vector.h"
#include <stdlib.h>

//typedef void *DataType; // void pointer
//typedef struct Vector Vector;

struct Vector
{
    int size;
    DataType *posicao;
};

Vector *VectorConstruct(){
    Vector* v = (Vector*) calloc(1, sizeof(struct Vector));
    return v;
}

void VectorPushBack(Vector *v, DataType val){
    DataType *temp = realloc(v->posicao, (v->size+1)*sizeof(DataType));
    if(!temp) return;

    v->posicao = temp;
    v->posicao[v->size] = val;
    v->size++;
}

DataType VectorPopFront(Vector *v){
    int i;
    DataType removido = v->posicao[0];
    for(i = 0; i < v->size-1; i++){
        v->posicao[i] = v->posicao[i+1];
    }
    v->size--;
    return removido;
}

DataType VectorGet(Vector *v, int i){
    return v->posicao[i];
}

int VectorSize(Vector *v){
    return v->size;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    int i;
    for(i = 0; i < v->size; i++){
        destroy(v->posicao[i]);
    }
    free(v->posicao);
    free(v);
}