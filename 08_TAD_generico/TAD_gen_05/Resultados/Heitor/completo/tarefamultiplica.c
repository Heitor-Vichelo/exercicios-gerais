#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct mult tMult;

struct mult
{
    float n1;
    float n2;
    float mult;
};


tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult *m = (tMult*) calloc(1, sizeof(struct mult));
    
    m->n1 = n1;
    m->n2 = n2;
    m->mult = n1*n2;

    return m;
}

//O resultado da multiplicacao de 3.14 com 2.00 eh: 6.28
void ExecutaTarefaMultiplicar(void *mult){
    tMult *m = (tMult*) mult;
    printf("\n O resultado da multiplicacao de %.2f com %.2f eh: %.2f", m->n1, m->n2, m->mult);
}

void DestroiTarefaMultiplicar(void *mult){
    tMult *m = (tMult*) mult;
    free(m);
}