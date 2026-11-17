#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct tImagem Imagem;

struct tImagem
{
    Tipo tipo;
    int altura;
    int largura;
    void *dados;
};

int ObterAltura(Imagem *img){
    return img->altura;
}

int ObterLargura(Imagem *img){
    return img->largura;
}

Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

void *ObterDadosImagem(Imagem *img){
    return img->dados;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo){
    Imagem *img = (Imagem*) calloc(1, sizeof(struct tImagem));

    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;

    if(tipo == FLOAT){
        img->dados = calloc(1, altura*largura*sizeof(float));
    } else if(tipo == INT){
        img->dados = calloc(1, altura*largura*sizeof(int));
    }

    return img;
}

Imagem *LerImagem(){
    Tipo tipo;
    int altura;
    int largura;

    scanf("%d %d %d", &altura, &largura, &tipo);

    Imagem *img = CriarImagem(altura, largura, tipo);

    int l, a;
    for(a = 0; a < img->altura; a++){
        for(l = 0; l < img->largura; l++){

            int indice = a * img->largura + l;

            if(tipo == FLOAT){
                scanf("%f", &((float *) img->dados)[indice]);
            } else if(tipo == INT){
                scanf("%d", &((int *) img->dados)[indice]);
            }
        }
    }

    return img;
}

void DestruirImagem(Imagem *img){
    free(img->dados);
    free(img);
}

//void ImprimirImagem(Imagem *img){}