#include <stdio.h>
#include "aluno.h"
#include "base_alunos.h"

int main(){
    char caminho[1000];

    tBaseAlunos *base = CriarBaseAlunos();
    scanf("%[^\n]\n", caminho);

    LerBaseAlunos(base, caminho);

    float coeficiente = GetCoeficienteRendimentoMedioBaseAlunos(base);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", coeficiente);

    DestruirBaseAlunos(base);

    return 0;
}
