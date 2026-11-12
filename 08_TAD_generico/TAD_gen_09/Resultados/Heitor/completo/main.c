#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exame.h"
#include "receita.h"
#include "encaminhamento.h"
#include "documento.h"
#include "fila_imp.h"

int main(){

    float preco = 0;
    scanf("%f ", &preco);
    FilaImp *fila = criaFilaImp();
    
    char opcao[20];
    while(1){

        if(scanf("%[^\n]\n", opcao) != 1) break;

        if(!strcmp(opcao, "RECEITA")){

            Receita *r = leReceita();
            insereDocumentoFilaImp(fila, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);

        } else if(!strcmp(opcao, "ENCAMINHAMENTO")){

            Encaminhamento *enc = leEncaminhamento();
            insereDocumentoFilaImp(fila, enc, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);

        } else if(!strcmp(opcao, "EXAME")){

            Exame *ex = leExame();
            insereDocumentoFilaImp(fila, ex, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);

        } else if(!strcmp(opcao, "QUANTIDADE")){

            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(fila));

        } else if(!strcmp(opcao, "PRECO")){

            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(fila, preco));

        } else if(!strcmp(opcao, "IMPRIME")){

            imprimeFilaImp(fila);

        } else if(!strcmp(opcao, "FIM")){

            break;
        }
    }

    desalocaFilaImp(fila);

    return 0;
}