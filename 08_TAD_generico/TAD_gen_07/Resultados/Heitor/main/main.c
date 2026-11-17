#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "histograma.h"

int main(){

    int nIntervalos;

    // Lê o número de intervalos do histograma.
    scanf("%d", &nIntervalos);

    // Lê os dados da imagem.
    Imagem *img = LerImagem();

    // Calcula o histograma da imagem.
    Histograma *histograma = CalcularHistograma(img, nIntervalos);

    // Exibe o histograma.
    MostrarHistograma(histograma);

    // Libera a memória alocada.
    DestruirHistograma(histograma);
    DestruirImagem(img);

    return 0;
}