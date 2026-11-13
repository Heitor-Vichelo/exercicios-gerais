#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct soma tSoma;

struct soma
{
    float n1;
    float n2;
    float soma;
};


tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma *s = (tSoma*) calloc(1, sizeof(struct soma));
    
    s->n1 = n1;
    s->n2 = n2;
    s->soma = n1+ n2;
    
    return s; 
}

//O resultado da soma de 1.00 com 1.00 eh: 2.00
void ExecutaTarefaSoma(void *sum){
    tSoma *s = (tSoma *) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", s->n1, s->n2, s->soma);
}

void DestroiTarefaSoma(void *sum){
    tSoma *s = (tSoma *) sum;
    free(s);
}