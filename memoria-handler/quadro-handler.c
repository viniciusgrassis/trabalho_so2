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

int procuraQuadroVazio(QuadrosPagina* quadrosPaginas){
    for(int i = 0; i < quadrosPaginas->tamanhoTotal; i++){
        if(quadrosPaginas->quadroPosicoes[i] == 0){ // 0 = vazio
            return i;
        }
    }
    return -1;
}