#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct impr tImpr;

struct impr
{
    char *msg;
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr *i = (tImpr*) calloc(1, sizeof(struct impr));
    i->msg = (char*) malloc((strlen(msg)+1)*sizeof(char));
    strcpy(i->msg, msg);

    return i;
}

void ExecutaTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    printf("\n%s", i->msg);
}

void DestroiTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    free(i->msg);
    free(i);
}