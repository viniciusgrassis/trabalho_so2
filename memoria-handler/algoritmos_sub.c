#include "./algoritmos_sub.h"

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


int encontrarNRU(TabelaInversa* tabela){
    int classe = 5;
    int indice = -1;

    for(int i = 0; i < tabela->tamanho; i++){ 
        if(tabela->quadros[i].validade != 1) continue;

        int aux = tabela->quadros[i].referenciada * 2 + tabela->quadros[i].modificada; // conversao de bit

        if(aux < classe){
            indice = i;
            classe = aux;

            if(!aux) return indice;
        }
    }
    return indice; 
}


int encontrarSegundaChance(TabelaInversa * tabela) {
    int tempo = tabela->quadros[0].primeiroAcesso;
    int indice = 0;
    
    for(int i = 0; i <= 1; i++){
        for(int i = 1; i < tabela->tamanho; i++) {
            if(tabela->quadros[i].primeiroAcesso < tempo) {

                if(tabela->quadros[i].referenciada == 1){
                    tabela->quadros[i].referenciada = 0;
                    continue;
                }

                tempo = tabela->quadros[i].ultimoAcesso;
                indice = i;
            }
        }
    }

    return indice;
}

