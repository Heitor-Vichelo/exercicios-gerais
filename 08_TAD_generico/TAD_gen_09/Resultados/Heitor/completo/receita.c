#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "receita.h"


//typedef struct _Receita Receita;

#define MAX_NOME 100
#define MAX_INSTRUCOES 200

struct _Receita
{
    char *nomeMedicamento;
    char *nomePaciente;
    char *nomeMedico;
    char *instrucoes;
};

Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes){
    // verifica se algum dos campos passado eh invalido (NULL)
    if(!nomeMedicamento || ! nomePaciente || !nomeMedico || !instrucoes) exit(0);

    // aloca memoria para uma nova receita
    Receita *r = (Receita*) calloc(1,sizeof(struct _Receita));
    if(!r) exit(0);

    // aloca memoria para cada campo da receita
    r->nomeMedicamento = (char*) malloc(strlen(nomeMedicamento)+1);
    r->nomePaciente = (char*) malloc(strlen(nomePaciente)+1);
    r->nomeMedico = (char*) malloc(strlen(nomeMedico)+1);
    r->instrucoes = (char*) malloc(strlen(instrucoes)+1);

    // verifica se nao conseguiu alocar memoria para alguns dos campos, se nao exit(0)
    if(!r->instrucoes || !r->nomeMedicamento || !r->nomeMedico || !r->nomePaciente){
        free(r->nomeMedicamento);
        free(r->nomePaciente);
        free(r->nomeMedico);
        free(r->instrucoes);
        free(r);
        exit(0);
    }

    // copia os parametros para o campo e retorna o novo relatorio
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->instrucoes, instrucoes);

    return r;
}

/* EXEMPLO DE ENTRADA: 
DR. MUNDO (nome do médico)
JOAO MATIAS (nome do paciente) 
PARACETAMOL 500MG (nome do medicamento)
TOMAR EM CASO DE DOR A CADA 12H (instruções para uso do medicamento) 
*/

Receita *leReceita(){
    char nomeMedicamento[MAX_NOME];
    char nomePaciente[MAX_NOME];
    char nomeMedico[MAX_NOME];
    char instrucoes[MAX_INSTRUCOES];

    scanf(" %99[^\n]", nomeMedico);
    scanf(" %99[^\n]", nomePaciente);
    scanf(" %99[^\n]", nomeMedicamento);
    scanf(" %199[^\n]", instrucoes);

    Receita *novaReceita = criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);
    return novaReceita;
}

float calculaPrecoImpressaoReceita(void *dado, float precoCaractere){
    int tam = 0;
    Receita *r = (Receita*) dado;
    tam += strlen(r->instrucoes) + strlen(r->nomeMedicamento) + strlen(r->nomeMedico) + strlen(r->nomePaciente);
    
    return tam*precoCaractere;
}

/*
- - RECEITA - -
MEDICAMENTO: IBUPROFENO 400MG
PACIENTE: MARIA FERNANDA
INSTRUCOES: TOMAR A CADA 8 HORAS DURANTE UMA SEMANA
MEDICO: DR. ANA SILVA
- - - - - - - -
*/
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
    free(r->instrucoes);
    free(r->nomeMedicamento);
    free(r->nomeMedico);
    free(r->nomePaciente);
    free(r);
}