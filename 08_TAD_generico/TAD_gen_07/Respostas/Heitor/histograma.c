#include "histograma.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct tHistograma
{
    int *contagens;
    int intervalos;
    int tamanhoIntervalo;
};


Histograma *CalcularHistograma(Imagem *img, int nIntervalos){

    Histograma *histograma = (Histograma*) malloc(sizeof(struct tHistograma));

    histograma->intervalos = nIntervalos;

    // Calcula o tamanho de cada intervalo, arredondando para cima.
    histograma->tamanhoIntervalo = (256 + nIntervalos - 1) / nIntervalos;

    // Cria um vetor com uma posição para cada intervalo.
    histograma->contagens = (int*) calloc(nIntervalos, sizeof(int));

    // Obtém os dados da imagem.
    void *dados = ObterDadosImagem(img);

    int totalPixels = ObterAltura(img) * ObterLargura(img);

    int i;
    for(i = 0; i < totalPixels; i++){

        int pixel;

        // Se a imagem for FLOAT, converte o pixel para INT.
        if(ObterTipoImagem(img) == FLOAT){

            pixel = (int)(((float*)dados)[i] * 255);

        } else if(ObterTipoImagem(img) == INT){

            pixel = ((int*)dados)[i];

        }

        // Descobre em qual intervalo o pixel pertence.
        int indice = pixel / histograma->tamanhoIntervalo;

        // Incrementa a quantidade de pixels daquele intervalo.
        histograma->contagens[indice]++;
    }

    return histograma;
}

void MostrarHistograma(Histograma *histograma){

    int i;

    for(i = 0; i < histograma->intervalos; i++){

        int limiteInferior = i * histograma->tamanhoIntervalo;

        int limiteSuperior = (i + 1) * histograma->tamanhoIntervalo;

        printf("[%d, %d): %d\n",
            limiteInferior,
            limiteSuperior,
            histograma->contagens[i]);
    }
}

void DestruirHistograma(Histograma *histograma){

    free(histograma->contagens);
    free(histograma);
}