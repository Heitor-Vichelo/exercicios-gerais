#include "exame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM_NOME_MEDICO 101
#define MAX_TAM_NOME_PACIENTE 101
#define MAX_TAM_DESCRICAO 101

//typedef struct _Exame Exame;
struct _Exame
{
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char descricao[MAX_TAM_DESCRICAO];
    int qtdCaracteres;
};

Exame *criaExame(char *nomeMedico, char *nomePaciente, char *descricao){
    Exame *ex = (Exame*) calloc(1, sizeof(struct _Exame));

    strcpy(ex->nomePaciente, nomePaciente);
    strcpy(ex->nomeMedico, nomeMedico);
    strcpy(ex->descricao, descricao);

    ex->qtdCaracteres = strlen(nomeMedico) + strlen(nomePaciente) + strlen(descricao);

    return ex;
}

Exame *leExame(){
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char descricao[MAX_TAM_DESCRICAO];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", descricao);
    Exame *ex = criaExame(nomeMedico, nomePaciente, descricao);
    return ex;
}

float calculaPrecoImpressaoExame(void *dado, float precoCaractere){
    Exame *ex = (Exame*) dado;
    return ex->qtdCaracteres * precoCaractere;
}

void imprimeExame(void *dado){
    Exame *ex = (Exame*) dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", ex->nomePaciente);
    printf("SOLICITACAO: %s\n", ex->descricao);
    printf("MEDICO: %s\n", ex->nomeMedico);
    printf("- - - - - - -\n");
}

void desalocaExame(void *dado){
    Exame *ex = (Exame*) dado; 
    free(ex);
}