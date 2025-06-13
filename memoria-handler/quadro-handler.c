#include "./quadro-handler.h"

QuadrosPagina* criaQuadrosMemoria(int tamanho){
    QuadrosPagina* memoria = (QuadrosPagina*) malloc (sizeof(QuadrosPagina));

    memoria->quadroPosicoes = (int*) malloc (sizeof(int) * tamanho);
    for(int i = 0; i < tamanho; i++){
        memoria->quadroPosicoes[i] = 0;
    }

    memoria->tamanhoTotal = 0;
    memoria->posicoesPreenchidas = 0;

    return memoria;
}

int inserirQuadro()