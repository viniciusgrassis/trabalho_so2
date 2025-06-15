#ifndef DEBUG_H
#define DEBUG_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    unsigned int leituras;
    unsigned int escritas; 
    unsigned int acessos;
    unsigned int faltasDePagina; 
    unsigned int pagSujas;
    char *substituicao;
    char* arquivo;
    int tamanhoPagina;
    int totalMemoria;
} Relatorio;

Relatorio* criaRelatorio(char *substituicao, char* arquivo, int tamanhoPagina, int totalMemoria);
void destroiRelatorio(Relatorio* rl);
void imprimeRelatorio(Relatorio* rl);

#endif