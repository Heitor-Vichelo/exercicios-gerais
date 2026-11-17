#include "encaminhamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TAM_NOME_MEDICO 101
#define MAX_TAM_NOME_PACIENTE 101
#define MAX_TAM_ESPECIALIDADE 51
#define MAX_TAM_MOTIVO 201 

struct _Encaminhamento
{
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char especialidade[MAX_TAM_ESPECIALIDADE];
    char motivo[MAX_TAM_MOTIVO];
    int qtdCaracteres;
};

Encaminhamento *criaEncaminhamento(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo){
    Encaminhamento *enc = (Encaminhamento*) calloc(1, sizeof(struct _Encaminhamento));
    
    strcpy(enc->nomeMedico, nomeMedico);
    strcpy(enc->nomePaciente, nomePaciente);
    strcpy(enc->especialidade, especialidade);
    strcpy(enc->motivo, motivo);
    enc->qtdCaracteres = strlen(nomeMedico) + strlen (nomePaciente) + strlen(especialidade) + strlen(motivo);

    return enc;
}

/*
ENCAMINHAMENTO
DR. JOSE CARDOSO
ALDIN FERREIRA
CARDIOLOGIA
ANALISAR POSSIVEL INFARTO
*/

Encaminhamento *leEncaminhamento(){
    char nomeMedico[MAX_TAM_NOME_MEDICO];
    char nomePaciente[MAX_TAM_NOME_PACIENTE];
    char especialidade[MAX_TAM_ESPECIALIDADE];
    char motivo[MAX_TAM_MOTIVO];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", especialidade);
    scanf(" %[^\n]\n", motivo);
    Encaminhamento *enc = criaEncaminhamento(nomeMedico, nomePaciente, especialidade, motivo);
    return enc;
}

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere){
    Encaminhamento *enc = (Encaminhamento*) dado;
    return enc->qtdCaracteres * precoCaractere;
}

/*
- - ENCAMINHAMENTO - -
PACIENTE: CARLA SOUZA
ESPECIALIDADE: ORTOPEDIA
MOTIVO: AVALIAR DORES NO JOELHO
MEDICO: DR. PAULO MENDES
- - - - - - - - - - - -
*/
void imprimeEncaminhamento(void *dado){
    Encaminhamento *enc = (Encaminhamento*) dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", enc->nomePaciente);
    printf("ESPECIALIDADE: %s\n", enc->especialidade);
    printf("MOTIVO: %s\n", enc->motivo);
    printf("MEDICO: %s\n", enc->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

void desalocaEncaminhamento(void *dado){
    Encaminhamento *enc = (Encaminhamento*) dado;
    free(enc);
}