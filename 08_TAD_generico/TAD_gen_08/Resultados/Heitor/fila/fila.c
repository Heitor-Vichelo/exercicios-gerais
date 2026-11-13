#include "vector.h"
#include "fila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct Fila Fila;

struct Fila
{
    Vector *posicao;
};


Fila *FilaConstruct(){
    Fila *f = (Fila*) calloc(1, sizeof(Fila));
    f->posicao = VectorConstruct();
    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)){
    VectorDestroy(f->posicao, destroy);
    free(f);
}

int FilaSize(Fila *f){
    return VectorSize(f->posicao);
}

DataType FilaPop(Fila *f){
    return VectorPopFront(f->posicao);
}

void FilaPush(Fila *f, DataType val){
    VectorPushBack(f->posicao, val);
}