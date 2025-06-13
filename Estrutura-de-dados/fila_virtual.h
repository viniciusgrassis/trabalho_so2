#ifndef FILA_VIRTUAL_H
#define FILA_VIRTUAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PaginaVirtual {
    int paginaFisica; 
    int validade;
    int modficada;
    int referenciada;
    int ultimoAcesso;   
    
    struct PaginaVirtual *prox;
    struct PaginaVirtual *ant;
} PaginaVirtual;

typedef struct {
    PaginaVirtual *inicio;
    PaginaVirtual *final;
    int tamanho;
} FilaPagVirtual;

FilaPagVirtual *criaFilaPagVirtual();
void destroiFilaPagVirtual(FilaPagVirtual *fila);
int enfileirarFilaPagVirtual(FilaPagVirtual *fila, int paginaFisica);
int estaVaziaFilaPagVirtual(FilaPagVirtual *fila);
void imprimirFilaPagVirtual(FilaPagVirtual *fila);

#endif