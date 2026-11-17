#include "fila_imp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct _FilaImp FilaImp;

struct _FilaImp
{
    int size;
    Documento **documento;
};


FilaImp *criaFilaImp(){
    FilaImp *f = (FilaImp*) calloc(1, sizeof(struct _FilaImp));
    return f;
}

void desalocaFilaImp(FilaImp *f){
    int i;
    for(i = 0; i < f->size; i++){
        desalocaDocumento(f->documento[i]);
    }
    free(f->documento);
    free(f);
}

void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime, func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco){
    f->documento = (Documento**) realloc(f->documento,(f->size+1)*sizeof(Documento*));
    f->documento[f->size] = criaDocumento(dado, imprime, desaloca, calculaPreco);
    f->size++;
}

int quantidadeDocumentosNaFilaImp(FilaImp *f){
    return f->size;
}

float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere){
    float preco = 0;
    int i;
    for(i = 0; i < f->size; i++){
        preco += calculaPrecoImpressaoDocumento(f->documento[i], precoCaractere);
    }
    return preco;
}

void imprimeFilaImp(FilaImp *f){
    int i;
    for(i = 0; i < f->size; i++){
        imprimeDocumento(f->documento[i]);
    }
}