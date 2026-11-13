#include "movel.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME_MOVEL 31

//typedef struct Movel tMovel;

struct Movel
{
    char nome[TAM_NOME_MOVEL];
};



tMovel *CriaMovel(char *nome){
    tMovel *m = (tMovel*) calloc(1, sizeof(struct Movel));
    strcpy(m->nome, nome);
    return m;
}

void DestroiMovel(tMovel *m){
    free(m);
}

tMovel *LeMovel(){
    char nome[TAM_NOME_MOVEL];
    scanf(" %[^\n]\n", nome);
    tMovel *m = CriaMovel(nome);

    return m;
}

void ImprimeMovel(tMovel *m){
    printf("%s\n", m->nome);
}