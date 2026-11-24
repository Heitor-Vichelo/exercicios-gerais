#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct aluno Aluno;

struct aluno
{
    char *nome;
    char *dtNasc; 
    char *cursoUfes;
    char *periodoIngresso;
    int percConclusao;
    float CRA;
};

char* leString(char *string);
void ImprimeAluno(Aluno* aluno, int indice);
void LiberaAluno(Aluno* aluno);

/**
 * @brief Cria um vetor de ponteiros para alunos, com espaço para numeroAlunos elementos.
 *
 * @param numeroAlunos - Quantidade de alunos que o vetor deve comportar
 *
 * @return Ponteiro para o vetor de alunos criado
 */
Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **vetorAlunos = (Aluno**) calloc(numeroAlunos, sizeof(struct aluno*));
    return vetorAlunos;
}

/**
 * @brief Cria um aluno com os dados passados como parâmetro.
 *
 * @param nome - Nome do aluno
 * @param dtNasc - Data de nascimento do aluno
 * @param cursoUfes - Curso do aluno na UFES
 * @param periodoIngresso - Período de ingresso do aluno
 * @param percConclusao - Porcentagem de conclusão do curso
 * @param CRA - Coeficiente de rendimento acadêmico
 *
 * @return Ponteiro para o aluno criado
 */
Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = (Aluno*) calloc(1,sizeof(struct aluno));
    a->nome = nome;
    a->dtNasc = dtNasc;
    a->cursoUfes = cursoUfes;
    a->periodoIngresso = periodoIngresso;
    a->percConclusao = percConclusao;
    a->CRA = CRA;
    return a;
}

/**
 * @brief Lê da entrada padrão os dados de numeroAlunos alunos, criando cada um deles e guardando-o no vetor.
 *
 * @param vetorAlunos - Vetor (já criado) onde os alunos serão guardados
 * @param numeroAlunos - Quantidade de alunos a serem lidos
 */
void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        char *nome = NULL;
        char *dtNasc = NULL;
        char *cursoUfes = NULL;
        char *periodoIngresso = NULL;
        int percConclusao;
        float CRA;
        nome = leString(nome);
        dtNasc = leString(dtNasc);
        cursoUfes = leString(cursoUfes);
        periodoIngresso = leString(periodoIngresso);
        scanf("%d %f", &percConclusao, &CRA);
        
        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

char *leString(char *string){
    char caracter;
    int i = 0;

    string = (char*) realloc(string, sizeof(char));
    scanf("\n");
    while(scanf("%c", &caracter) == 1 && caracter != '\n')
    {
        char *temp = (char*) realloc(string, (i + 2)*sizeof(char));

        if(temp == NULL){
            free(string);
            return NULL;
        }

        string = temp;
        string[i] = caracter;
        i++;
    }

    string[i] = '\0';

    return string;
}

/**
 * @brief Libera a memória de todos os alunos e do próprio vetor.
 *
 * @param alunos - Vetor de alunos a ser liberado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++)
    {
        LiberaAluno(alunos[i]);
    }
    free(alunos);
}

void LiberaAluno(Aluno* aluno){
    if(!aluno) return;

    free(aluno->nome);
    free(aluno->dtNasc);
    free(aluno->cursoUfes);
    free(aluno->periodoIngresso);
    free(aluno);
}

/**
 * @brief Salva o vetor de alunos em um arquivo binário e imprime a quantidade de bytes salvos
 * no formato "Numero de bytes salvos: X", seguido de uma quebra de linha.
 *
 *
 * @param alunos - Vetor de alunos a ser salvo
 * @param fileName - Nome do arquivo binário a ser criado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE *arquivo = fopen(fileName, "wb");

    if(arquivo == NULL) return;

    int bytesSalvos = 0;

    bytesSalvos += fwrite(&numeroAlunos, sizeof(int), 1, arquivo) * sizeof(int);

    for(int i = 0; i < numeroAlunos; i++){
        int tamanho;

        tamanho = strlen(alunos[i]->nome);
        bytesSalvos += fwrite(&tamanho, sizeof(int), 1, arquivo) * sizeof(int);
        bytesSalvos += fwrite(alunos[i]->nome, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->dtNasc);
        bytesSalvos += fwrite(&tamanho, sizeof(int), 1, arquivo) * sizeof(int);
        bytesSalvos += fwrite(alunos[i]->dtNasc, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->cursoUfes);
        bytesSalvos += fwrite(&tamanho, sizeof(int), 1, arquivo) * sizeof(int);
        bytesSalvos += fwrite(alunos[i]->cursoUfes, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->periodoIngresso);
        bytesSalvos += fwrite(&tamanho, sizeof(int), 1, arquivo) * sizeof(int);
        bytesSalvos += fwrite(alunos[i]->periodoIngresso, sizeof(char), tamanho, arquivo);

        bytesSalvos += fwrite(&alunos[i]->percConclusao, sizeof(int), 1, arquivo) * sizeof(int);
        bytesSalvos += fwrite(&alunos[i]->CRA, sizeof(float), 1, arquivo) * sizeof(float);
    }

    fclose(arquivo);

    printf("Numero de bytes salvos: %d\n", bytesSalvos);
}

/**
 * @brief Lê os alunos de um arquivo binário criando cada um deles e guardando no vetor.
 *
 * @param alunos - Vetor (já criado, com espaço para todos os alunos do arquivo) onde os alunos serão guardados
 * @param fileName - Nome do arquivo binário a ser lido
 */
void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *arquivo = fopen(fileName, "rb");

    if(arquivo == NULL) return;

    int tamanho;
    int numeroAlunos;
    int percConclusao;
    float CRA;

    if(fread(&numeroAlunos, sizeof(int), 1, arquivo) != 1){
        fclose(arquivo);
        return;
    }

    for(int i = 0; i < numeroAlunos; i++){

        fread(&tamanho, sizeof(int), 1, arquivo);
        char *nome = (char*) malloc((tamanho + 1) * sizeof(char));
        fread(nome, sizeof(char), tamanho, arquivo);
        nome[tamanho] = '\0';

        fread(&tamanho, sizeof(int), 1, arquivo);
        char *dtNasc = (char*) malloc((tamanho + 1) * sizeof(char));
        fread(dtNasc, sizeof(char), tamanho, arquivo);
        dtNasc[tamanho] = '\0';

        fread(&tamanho, sizeof(int), 1, arquivo);
        char *cursoUfes = (char*) malloc((tamanho + 1) * sizeof(char));
        fread(cursoUfes, sizeof(char), tamanho, arquivo);
        cursoUfes[tamanho] = '\0';

        fread(&tamanho, sizeof(int), 1, arquivo);
        char *periodoIngresso = (char*) malloc((tamanho + 1) * sizeof(char));
        fread(periodoIngresso, sizeof(char), tamanho, arquivo);
        periodoIngresso[tamanho] = '\0';

        fread(&percConclusao, sizeof(int), 1, arquivo);
        fread(&CRA, sizeof(float), 1, arquivo);

        alunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }

    fclose(arquivo);
}

/**
 * @brief Imprime os dados de todos os alunos do vetor.
 *
 * @param alunos - Vetor de alunos a ser impresso
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++)
    {  
        ImprimeAluno(alunos[i], i);
    }
}

void ImprimeAluno(Aluno* aluno, int indice){
    printf("Aluno %d:\n", indice);
    printf("Nome: %s\n", aluno->nome);
    printf("Data Nascimento: %s\n", aluno->dtNasc);
    printf("Curso: %s\n", aluno->cursoUfes);
    printf("Periodo Ingresso: %s\n", aluno->periodoIngresso);
    printf("%% Conclusao do Curso: %d\n", aluno->percConclusao);
    printf("CRA: %.2f\n", aluno->CRA);
}

/**
 * Aluno 0:
 * Nome: Seraphina Luminara
 * Data Nascimento: 12 de julho de 2995
 * Curso: Engenharia Quantica
 * Periodo Ingresso: 2023/1
 * % Conclusao do Curso: 85
 * CRA: 8.70
 */