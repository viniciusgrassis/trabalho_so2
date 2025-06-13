#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int addrs; // endereco em decimal
    char op; // r ou w  
    struct No *prox;
} NO;

typedef struct {
    NO *inicio;
    NO *final;
    int tamanho;
} Fila_addrs;

Fila_addrs *criaFilaAddrs();
void destroiFilaAddrs(Fila_addrs *fila);
int enfileirarAddrs(Fila_addrs *fila, int addrs, char op);
int desenfileirarAddrs(Fila_addrs *fila);
int estaVaziaFilaAddrs(Fila_addrs *fila);
void imprimirFila_addrs(Fila_addrs *fila);
int tamanhoFilaAddrs(Fila_addrs *fila);

#endif