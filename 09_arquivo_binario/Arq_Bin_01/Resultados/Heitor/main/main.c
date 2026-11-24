#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    
    printf("Digite o numero de alunos: ");
    
    int numeroAlunos;
    scanf("%d\n", &numeroAlunos);

    Aluno **alunos = CriaVetorAlunos(numeroAlunos);

    LeAlunos(alunos, numeroAlunos);
    SalvaAlunosBinario(alunos, "binario.txt", numeroAlunos);
    ImprimeAlunos(alunos, numeroAlunos);
    LiberaAlunos(alunos, numeroAlunos);

    return 0;
}