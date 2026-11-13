#include "agendatarefas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct agendatarefas tAgendaTarefas;

void OrdenaPrioridades(tAgendaTarefas *tar);

typedef struct tarefa tTarefa;

struct tarefa {
    int prioridade;
    void *tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
};

struct agendatarefas
{
    int numElem;
    tTarefa **tarefas;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas* agenda = (tAgendaTarefas*) malloc(sizeof(tAgendaTarefas));

    if (agenda == NULL) return NULL;

    agenda->tarefas = (tTarefa**) malloc(numElem * sizeof(tTarefa*));

    if (agenda->tarefas == NULL) {
        free(agenda);
        return NULL;
    }

    agenda->numElem = 0;

    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    int i;
    for (i = 0; i < tar->numElem; i++) {
        tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
        free(tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)){
    tar->tarefas[tar->numElem] = (tTarefa*) malloc(sizeof(tTarefa));

    if (tar->tarefas[tar->numElem] == NULL) return;

    tar->tarefas[tar->numElem]->prioridade = prioridade;
    tar->tarefas[tar->numElem]->tarefa = tarefa;
    tar->tarefas[tar->numElem]->executa = executa;
    tar->tarefas[tar->numElem]->destroi = destroi;

    tar->numElem++;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    OrdenaPrioridades(tar);

    int i;
    for (i = 0; i < tar->numElem; i++) {
        tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
    }
}


void OrdenaPrioridades(tAgendaTarefas *tar) {
    int i, j;
    tTarefa *aux;

    for (i = 1; i < tar->numElem; i++) {
        aux = tar->tarefas[i];
        j = i - 1;

        while (j >= 0 && tar->tarefas[j]->prioridade < aux->prioridade) {
            tar->tarefas[j + 1] = tar->tarefas[j];
            j--;
        }

        tar->tarefas[j + 1] = aux;
    }
}