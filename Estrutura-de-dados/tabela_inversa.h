#ifndef TABELA_INVERSA_H
#define TABELA_INVERSA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int paginaVirtual;
    int validade;
    int modficada;
    int referenciada;
    int ultimoAcesso;   
} QuadroFisico;

typedef struct{
    int paginaFisica;
    int paginaVirtual;
    struct NoHash* prox;
} NoHash;

typedef struct {
    QuadroFisico* quadros;
    NoHash** hash;
    int tamanho;
} TabelaInversa;


int* criaTabela(int tamanho);
void destroiTabela(TabelaInversa* tabela);
int buscaTabelaInversa(TabelaInversa* tabela, int paginaVirtual);

#endif