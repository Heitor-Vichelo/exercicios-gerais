#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    TAM_MAX_NOME_ALUNO = 101,
    TAM_MAX_DATA_NASC = 12,
    TAM_MAX_NOME_CURSO_ALUNO = 51,
};

struct Aluno
{
    char nome[TAM_MAX_NOME_ALUNO];
    char dataNascimento[TAM_MAX_DATA_NASC];
    char curso[TAM_MAX_NOME_CURSO_ALUNO];
    int periodo;
    float coeficienteRendimento;
};


/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno *a = (tAluno*) calloc(1, sizeof(struct Aluno));
    if(!a) exit(0);

    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->coeficienteRendimento = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    if(!aluno) return;
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    char nome[TAM_MAX_NOME_ALUNO];
    char dataNascimento[TAM_MAX_DATA_NASC];
    char curso[TAM_MAX_NOME_CURSO_ALUNO];
    int periodo;
    float coeficienteRendimento;
    
    fread(nome, sizeof(char), 100, arquivo_binario);
    nome[101] = '\0';
    
    fread(dataNascimento, sizeof(char), 11, arquivo_binario);
    dataNascimento[12] = '\0';

    fread(curso, sizeof(char), 50, arquivo_binario);
    curso[51] = '\0';

    fread(&periodo, sizeof(int), 1, arquivo_binario);

    fread(&coeficienteRendimento, sizeof(float), 1, arquivo_binario);

    return CriarAluno(nome, dataNascimento, curso, periodo, coeficienteRendimento);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->coeficienteRendimento;
}
