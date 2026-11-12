#include "encaminhamento.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//typedef struct _Encaminhamento Encaminhamento;
#define TAM_ESPECIALIDADE 50
#define TAM_MOTIVO 200
#define TAM_MEDICO 100
#define TAM_PACIENTE 100

struct _Encaminhamento
{
    char medico[TAM_MEDICO];
    char paciente[TAM_PACIENTE];
    char especialidade[TAM_ESPECIALIDADE];
    char motivo[TAM_MOTIVO];
    int qtdCaracteres;
};

Encaminhamento *criaEncaminhamento(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo){
    Encaminhamento *enc = (Encaminhamento*) calloc(1,sizeof(struct _Encaminhamento));
    if(!enc) exit(0);

    strcpy(enc->medico, nomeMedico);
    strcpy(enc->paciente, nomePaciente);
    strcpy(enc->especialidade, especialidade);
    strcpy(enc->motivo, motivo);
    enc->qtdCaracteres += strlen(nomeMedico) + strlen(nomePaciente) + strlen(especialidade) + strlen(motivo);

    return enc;
}

/* EXEMPLO DE ENTRADA: 
DR. JOSE CARDOSO
ALDIN FERREIRA
CARDIOLOGIA
ENCAMINHO PACIENTE PARA EXAME CARDIOLOGICO PARA ANALISAR POSSIVEL INFARTO
*/
Encaminhamento *leEncaminhamento(){
    char medico[TAM_MEDICO];
    char paciente[TAM_PACIENTE];
    char especialidade[TAM_ESPECIALIDADE];
    char motivo[TAM_MOTIVO];

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", especialidade);
    scanf("%[^\n]\n", motivo);

    Encaminhamento *enc = criaEncaminhamento(medico, paciente, especialidade, motivo);
    return enc;
}

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere){
    Encaminhamento *enc = (Encaminhamento*) dado;
    return enc->qtdCaracteres*precoCaractere;
}

/* FORMATO DE SAIDA
- - ENCAMINHAMENTO - -
PACIENTE: ALDIN FERREIRA
ESPECIALIDADE: CARDIOLOGIA
MOTIVO: ENCAMINHO PACIENTE PARA EXAME CARDIOLOGICO PARA ANALISAR POSSIVEL INFARTO
MEDICO: DR. JOSE CARDOSO
- - - - - - - - - - - -
*/
void imprimeEncaminhamento(void *dado){
    Encaminhamento *enc = (Encaminhamento*) dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", enc->paciente);
    printf("ESPECIALIDADE: %s\n", enc->especialidade);
    printf("MOTIVO: %s\n", enc->motivo);
    printf("MEDICO: %s\n", enc->medico);
    printf("- - - - - - - - - - - -\n");
}

void desalocaEncaminhamento(void *dado){
    Encaminhamento *enc = (Encaminhamento*) dado;
    free(enc);
}
