#include <stdio.h>
#include "./lru.h"

int encontrarLRU(TabelaInversa * tabela) {
  int tempo = tabela->quadros[0].ultimoAcesso;
  int indice = 0;
  for(int i = 1; i < tabela->tamanho; i++) {
    if(tabela->quadros[i].ultimoAcesso < tempo) {
      tempo = tabela->quadros[i].ultimoAcesso;
      indice = i;
    }
  }
  return indice;
}