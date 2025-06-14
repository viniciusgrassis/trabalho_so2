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


int encontrarVitimaNRU(TabelaInversa* tabela){
    for(int i = 0; i < tabela->tamanho; i++){ // classe 0
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modificada == 0 && 
           tabela->quadros[i].referenciada == 0){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 1
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modificada == 1 && 
           tabela->quadros[i].referenciada == 0){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 2
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modificada == 0 && 
           tabela->quadros[i].referenciada == 1){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 3
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modificada == 1 && 
           tabela->quadros[i].referenciada == 1){ 
            return i;
        }
    }

    return -1; // página não encontrada
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

