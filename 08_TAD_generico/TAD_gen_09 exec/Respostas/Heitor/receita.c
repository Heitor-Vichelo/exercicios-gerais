#include "receita.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAM_NOME_MEDICO 101
#define MAX_TAM_NOME_PACIENTE 101
#define MAX_TAM_MEDICAMENTO 101
#define MAX_TAM_INSTRUCOES 201

struct _Receita
{
    char nomeMedicamento[MAX_TAM_MEDICAMENTO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    int qtdCaracteres;
};


Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes){
    Receita *r = (Receita*) calloc(1, sizeof(struct _Receita));

    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->instrucoes, instrucoes);

    r->qtdCaracteres = strlen(nomeMedicamento) + strlen(nomePaciente) + strlen(nomeMedico) + strlen(instrucoes);

    return r;
}

Receita *leReceita(){
    char nomeMedicamento[MAX_TAM_MEDICAMENTO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", nomeMedicamento);
    scanf(" %[^\n]\n", instrucoes);
    Receita *r = criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);
    return r;
}

float calculaPrecoImpressaoReceita(void *dado, float precoCaractere){
    Receita *r = (Receita*) dado;
    return r->qtdCaracteres * precoCaractere;
}

void imprimeReceita(void *dado){
    Receita *r = (Receita*) dado;
    printf("- - RECEITA - -\n");
    printf("MEDICAMENTO: %s\n", r->nomeMedicamento);
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("INSTRUCOES: %s\n", r->instrucoes);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - - -\n");
}

void desalocaReceita(void *dado){
    Receita *r = (Receita*) dado;
    free(r);
}