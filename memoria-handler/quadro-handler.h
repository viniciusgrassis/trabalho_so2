#ifndef QUADRO_HANDLER_h
#define QUADRO_HANDLER_h

#include <stdlib.h>
#include <stdio.h>
// #include 

typedef struct{
    int *quadroPosicoes; // vetor dos quadros de paginas - bianry boy
    int posicoesPreenchidas; // 
    int tamanhoTotal; // total
} QuadrosPagina;

QuadrosPagina* criaQuadrosMemoria(int tamanho);

#endif