#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int paginaFisica; 
    int validade;
    struct No *prox;
    struct No *ant;
} NO;

typedef struct {
    NO *inicio;
    NO *final;
    int tamanho;
} Fila_hash;

Fila_hash *criaFilahash();
void destroiFilahash(Fila_hash *fila);
int enfileirarhash(Fila_hash *fila, int paginaFisica);
int estaVaziaFilahash(Fila_hash *fila);
void imprimirFila_hash(Fila_hash *fila);

#endif