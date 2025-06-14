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

typedef struct {
    QuadroFisico* quadros;
    int tamanho;
} TabelaInversa;


int* criaTabela(int tamanho);
void destroiTabela(TabelaInversa* tabela);




#endif