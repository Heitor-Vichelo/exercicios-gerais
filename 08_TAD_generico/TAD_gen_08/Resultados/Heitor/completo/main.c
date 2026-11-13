#include "movel.h"
#include "vector.h"
#include "fila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_ENTRADA 10

void DestroiMovelGenerico(DataType dado);

int main(){
    Fila *fila = FilaConstruct();

    int qtd;
    scanf("%d\n", &qtd);

    int i;
    char opcao[TAM_ENTRADA];

    for(i = 0; i < qtd; i++){
        
        scanf("%s", opcao);
        
        if(!strcmp(opcao, "ENTRADA")){
        
            tMovel *m = LeMovel();
            FilaPush(fila, m);
        
        } else if(!strcmp(opcao, "PRODUZIR")){
        
            tMovel *m = (tMovel*) FilaPop(fila);
            ImprimeMovel(m);
            DestroiMovel(m);
        
        }
    }

    FilaDestroy(fila, DestroiMovelGenerico);

    return 0;
}

void DestroiMovelGenerico(DataType dado){
    DestroiMovel((tMovel*) dado);
}