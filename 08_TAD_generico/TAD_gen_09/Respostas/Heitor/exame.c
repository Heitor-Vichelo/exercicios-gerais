#include "exame.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TAM_DESCRICAO 100
#define TAM_MEDICO 100
#define TAM_PACIENTE 100

//typedef struct _Exame Exame;
struct _Exame
{   
    char medico[TAM_MEDICO];
    char paciente[TAM_PACIENTE];
    char descricao[TAM_DESCRICAO];
    int qtdCaracteres;
};

Exame *criaExame(char *nomeMedico, char *nomePaciente, char *descricao){
    Exame *ex = (Exame*) calloc(1, sizeof(struct _Exame));
    if(!ex) exit(0);

    strcpy(ex->medico, nomeMedico);
    strcpy(ex->paciente, nomePaciente);
    strcpy(ex->descricao, descricao);
    ex->qtdCaracteres += strlen(nomeMedico) + strlen(nomePaciente) + strlen(descricao);

    return ex;
}
/* EXEMPLO DE ENTRADA: 
DR. MUNDO
JAYCE BARBOSA
SOLICITO EXAME DE RESSONANCIA MAGNETICA PARA AVALIACAO DA LOMBAR
*/
Exame *leExame(){
    char medico[TAM_MEDICO];
    char paciente[TAM_PACIENTE];
    char descricao[TAM_DESCRICAO];

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", descricao);

    Exame *ex = criaExame(medico, paciente, descricao);
    if(!ex) exit(0);

    return ex;
}

float calculaPrecoImpressaoExame(void *dado, float precoCaractere){
    Exame *ex = (Exame*) dado;
   return ex->qtdCaracteres*precoCaractere; 
}

/* FORMATO DE SAIDA
- - EXAME - -
PACIENTE: JAYCE BARBOSA
SOLICITACAO: SOLICITO EXAME DE RESSONANCIA MAGNETICA PARA AVALIACAO DA LOMBAR
MEDICO: DR. MUNDO
- - - - - - -
*/
void imprimeExame(void *dado){
    Exame *ex = (Exame*) dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", ex->paciente);
    printf("SOLICITACAO: %s\n", ex->descricao);
    printf("MEDICO: %s\n", ex->medico);
    printf("- - - - - - -\n");
}

void desalocaExame(void *dado){
    Exame *ex = (Exame*) dado;
    free(ex);
}
