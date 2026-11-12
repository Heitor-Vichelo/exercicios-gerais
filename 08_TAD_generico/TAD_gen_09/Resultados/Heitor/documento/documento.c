#include "documento.h"
#include <stdlib.h>

struct _Documento
{
    void* dado;
    func_ptr_imprime imprime;
    func_ptr_desaloca desaloca;
    func_ptr_calculaPreco calculaPreco;
};


Documento *criaDocumento(void *dado,func_ptr_imprime imprimeDado, func_ptr_desaloca desalocaDado, func_ptr_calculaPreco calculaPrecoDado){
    Documento *doc = (Documento*) calloc(1, sizeof(struct _Documento));
    if(doc == NULL) return NULL;

    doc->dado = dado;
    doc->imprime = imprimeDado;
    doc->desaloca = desalocaDado;
    doc->calculaPreco = calculaPrecoDado;

    return doc;
}

void imprimeDocumento(Documento *doc){
    doc->imprime(doc->dado);
}

float calculaPrecoImpressaoDocumento(Documento *doc, float precoCaractere){
    return doc->calculaPreco(doc->dado, precoCaractere);
}

void desalocaDocumento(Documento *doc){
    doc->desaloca(doc->dado);
    free(doc);
}