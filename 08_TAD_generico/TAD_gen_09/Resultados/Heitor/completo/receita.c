#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "receita.h"


//typedef struct _Receita Receita;

#define MAX_MEDICO 100
#define MAX_MEDICAMENTO 100
#define MAX_PACIENTE 100
#define MAX_INSTRUCOES 200

struct _Receita
{
    char nomeMedicamento[MAX_MEDICAMENTO];
    char nomePaciente[MAX_PACIENTE];
    char nomeMedico[MAX_MEDICO];
    char instrucoes[MAX_INSTRUCOES];
    int qtdCaracteres;
};

Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes){
    // verifica se algum dos campos passado eh invalido (NULL)
    if(!nomeMedicamento || ! nomePaciente || !nomeMedico || !instrucoes) exit(0);

    // aloca memoria para uma nova receita
    Receita *r = (Receita*) calloc(1,sizeof(struct _Receita));
    if(!r) exit(0);

    // copia os parametros para o campo e retorna o novo relatorio
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->instrucoes, instrucoes);

    // Ja disponibilizo a quantidade de caracteres para a struct
    r->qtdCaracteres = strlen(r->nomeMedicamento) + strlen(r->nomePaciente) + strlen(r->nomeMedico) + strlen(r->instrucoes);

    return r;
}

/* EXEMPLO DE ENTRADA: 
DR. MUNDO (nome do médico)
JOAO MATIAS (nome do paciente) 
PARACETAMOL 500MG (nome do medicamento)
TOMAR EM CASO DE DOR A CADA 12H (instruções para uso do medicamento) 
*/

Receita *leReceita(){
    char nomeMedicamento[MAX_MEDICAMENTO];
    char nomePaciente[MAX_PACIENTE];
    char nomeMedico[MAX_MEDICO];
    char instrucoes[MAX_INSTRUCOES];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", nomeMedicamento);
    scanf(" %[^\n]\n", instrucoes);

    Receita *novaReceita = criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);
    return novaReceita;
}

float calculaPrecoImpressaoReceita(void *dado, float precoCaractere){
    Receita *r = (Receita*) dado;
    if(!r) return 0;
    return r->qtdCaracteres*precoCaractere;
}

/* FORMATO DE SAIDA
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
    free(r);
}