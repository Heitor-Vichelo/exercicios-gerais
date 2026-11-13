#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num;
    int prioridade;
    int i;
    float n1, n2;
    char opcao;
    printf("Digite o numero de tarefas: ");

    scanf("%d ", &num);
    tAgendaTarefas *agenda = CriaAgendaDeTarefas(num);

    for(i = 0; i < num; i++){
        scanf("%d %c ", &prioridade, &opcao);
        if(opcao == 'I'){
            char texto[200];
            scanf("%[^\n]", texto);
            tImpr *i = CriaTarefaImprimir(texto);
            CadastraTarefaNaAgenda(agenda, prioridade, i, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        } else if(opcao == 'S'){
            scanf("%f %f ", &n1, &n2);
            tSoma *s = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, s, ExecutaTarefaSoma, DestroiTarefaSoma);
        } else if(opcao == 'M'){
            scanf("%f %f ", &n1, &n2);
            tMult *m = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        } else {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf(" %[^\n]\n");
            i--;
            if(!i) break;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}
