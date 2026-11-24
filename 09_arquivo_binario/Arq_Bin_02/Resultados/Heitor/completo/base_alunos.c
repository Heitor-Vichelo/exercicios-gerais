#include "base_alunos.h"
#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct BaseAlunos
{
    tAluno **alunos;
    int qtdAlunos;
    float coeficienteRendimento;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *b = (tBaseAlunos*) calloc(1, sizeof(struct BaseAlunos));
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for(int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE * arquivo = fopen(nomeArquivo, "rb");
    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, arquivo);

    baseAlunos->alunos = (tAluno**) calloc(baseAlunos->qtdAlunos, sizeof(tAluno*));
    for(int i = 0; i < baseAlunos->qtdAlunos; i++){
        baseAlunos->alunos[i] = LeAluno(arquivo);
    }
    fclose(arquivo);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma = 0;
    for(int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        soma+= GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return soma/baseAlunos->qtdAlunos;
}
