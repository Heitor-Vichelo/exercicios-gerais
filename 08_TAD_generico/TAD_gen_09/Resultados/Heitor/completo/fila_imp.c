#include "fila_imp.h"
#include "documento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct _FilaImp FilaImp;

struct _FilaImp
{
    int size;
    Documento **fila;
};

FilaImp *criaFilaImp(){
    FilaImp *fila = calloc(1, sizeof(struct _FilaImp));
    return fila;
}

void desalocaFilaImp(FilaImp *f){
    int i;
    for(i = 0; i < f->size; i++){
        desalocaDocumento(f->fila[i]);
    }
    free(f->fila);
    free(f);
}

void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime, func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco){
    Documento **temp = (Documento**) realloc(f->fila,(f->size+1)*sizeof(Documento*));
    if(!temp) return;

    f->fila = temp;
    f->fila[f->size] = criaDocumento(dado, imprime, desaloca, calculaPreco);
    if(!f->fila[f->size]) return;
    f->size++;
}

int quantidadeDocumentosNaFilaImp(FilaImp *f){
    return f->size;
}

float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere){
    int i;
    float total = 0;
    for(i = 0; i < f->size; i++){
        total += calculaPrecoImpressaoDocumento(f->fila[i], precoCaractere);
    }
    return total;
}

void imprimeFilaImp(FilaImp *f){
    int i;
    for(i = 0; i < f->size; i++){
        imprimeDocumento(f->fila[i]);
    }
}