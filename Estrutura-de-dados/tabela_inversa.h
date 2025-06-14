#ifndef TABELA_INVERSA_H
#define TABELA_INVERSA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned int paginaVirtual;
    short int validade;
    short int modificada;
    short int referenciada;
    unsigned int ultimoAcesso;   
    unsigned int primeiroAcesso;   
} QuadroFisico;

typedef struct NoHash{
    int quadroFisico;
    int paginaVirtual;
    struct NoHash* prox;
} NoHash;

typedef struct {
    QuadroFisico* quadros;
    NoHash** hash;
    int tamanho;
} TabelaInversa;


TabelaInversa* criaTabela(int tamanho);
void destroiTabela(TabelaInversa* tabela);
int buscaTabelaInversa(TabelaInversa* tabela, int paginaVirtual);
int insereMapeamento(TabelaInversa* tabela, int paginaVirtual, int quadroFisico, unsigned int tempo, int modificada);
int procuraVazio(TabelaInversa* tabela);
int removePagina(TabelaInversa* tabela, int paginaVirtual);
int removePorQuadroFisico(TabelaInversa* tabela, int quadroFisico);

#endif