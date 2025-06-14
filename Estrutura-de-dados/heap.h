#ifndef HEAP_H
#define HEAP_H

#include "./tabela_inversa.h"

typedef struct Heap {
  int tamanho;
  int maxQuadros;
  QuadroFisico *quadros;
} Heap;

Heap *criaHeap();
void destroiHeap(Heap *hp);
int insereHeap(Heap *hp, int valor);
int removeInicio(Heap *hp);
int verInicio(Heap *hp);
int tamanhoHeap(Heap *hp);
void imprimeHeap(Heap *hp);
int estaVazia(Heap *hp);
int estaCheia(Heap *hp);

#endif