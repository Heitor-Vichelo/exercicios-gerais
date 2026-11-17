#include "documento.h"
#include "encaminhamento.h"
#include "exame.h"
#include "fila_imp.h"
#include "receita.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FilaImp *fila = criaFilaImp();
    float preco;
    scanf(" %f\n", &preco);

    char opcao[20];
    while (1)
    {
        scanf(" %[^\n]\n", opcao);
        if(!strcmp(opcao, "RECEITA")){
            Receita *r = leReceita();
            insereDocumentoFilaImp(fila, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        } else if(!strcmp(opcao, "ENCAMINHAMENTO")){
            Encaminhamento *en = leEncaminhamento();
            insereDocumentoFilaImp(fila, en, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        } else if(!strcmp(opcao, "EXAME")){
            Exame *ex = leExame();
            insereDocumentoFilaImp(fila, ex, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        } else if(!strcmp(opcao, "QUANTIDADE")){
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(fila));
        } else if(!strcmp(opcao, "PRECO")){
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n",precoTotalImpressaoFilaImp(fila, preco));
        } else if(!strcmp(opcao, "IMPRIME")){
            imprimeFilaImp(fila);
        } else if(!strcmp(opcao, "FIM")){
            break;
        }
    }
    
    desalocaFilaImp(fila);

    return 0;
}