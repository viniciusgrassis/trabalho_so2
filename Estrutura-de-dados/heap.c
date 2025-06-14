#include <stdio.h>
#include <stdlib.h>
#include "./heap.h"

Heap *criaHeap(int quantidadeQuadros) {
  Heap *hp = (Heap*)malloc(sizeof(Heap));
  if(hp != NULL) {
    hp->quadros = (QuadroFisico*)malloc(quantidadeQuadros * sizeof(QuadroFisico));
    hp->maxQuadros = quantidadeQuadros;
    hp->tamanho = 0;
  }
  return hp;
}

void destroiHeap(Heap *hp) {
  free(hp);
}

QuadroFisico *verInicio(Heap *hp) {
  if(hp == NULL) return NULL;
  if(!estaVazia(hp)) {
    return &(hp->quadros[0]);
  }
}

void ajustaInsercaoHeap(Heap *hp, int indice_filho) {
  int indice_pai = (indice_filho - 1) / 2;
  while(indice_filho > 0 && hp->quadros[indice_pai].ultimoAcesso > hp->quadros[indice_filho].ultimoAcesso) {
    QuadroFisico aux = hp->quadros[indice_pai];
    hp->quadros[indice_pai] = hp->quadros[indice_filho];
    hp->quadros[indice_filho] = aux;
    indice_filho = indice_pai;
    indice_pai = (indice_filho - 1) / 2;
  }
}

int insereHeap(Heap *hp, QuadroFisico quadro) {
  if(hp == NULL) return 0;
  if(estaCheia(hp)) return 0;
  hp->quadros[hp->tamanho] = quadro;
  ajustaInsercaoHeap(hp, hp->tamanho);
  hp->tamanho++;
  return 1;
}

void ajustaRemocaoHeap(Heap *hp, int indice_pai) {
  int indice_filho = indice_pai * 2 + 1;
  while(indice_filho < hp->tamanho) {
    if(indice_filho < hp->tamanho-1){
      if(hp->quadros[indice_filho].ultimoAcesso > hp->quadros[indice_filho+1].ultimoAcesso) indice_filho++;
      if(hp->quadros[indice_pai].ultimoAcesso < hp->quadros[indice_filho].ultimoAcesso) break;
      QuadroFisico aux = hp->quadros[indice_pai];
      hp->quadros[indice_pai] = hp->quadros[indice_filho];
      hp->quadros[indice_filho] = aux;
      indice_pai = indice_filho;
      indice_filho = indice_pai * 2 + 1; 
    }
  }
}

int removeInicio(Heap *hp) {
  if(hp == NULL) return 0;
  if(estaVazia(hp)) return 0;
  hp->tamanho--;
  hp->quadros[0] = hp->quadros[hp->tamanho];
  ajustaRemocaoHeap(hp, 0);
  return 1;
}

int tamanhoHeap(Heap *hp) {
  if(hp == NULL) return -1;
  return hp->tamanho;
}

int estaVaziaHeap(Heap *hp) {
  if(hp == NULL) return -1;
  return hp-> tamanho == 0;
}

int estaCheia(Heap *hp) {
  if(hp == NULL) return -1;
  return hp->tamanho == hp->maxQuadros;
}