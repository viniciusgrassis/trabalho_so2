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
    int classe0 = -1;
    int classe1 = -1;
    int classe2 = -1;
    int classe3 = -1;

    for(int i = 0; i < tabela->tamanho; i++){
        if(tabela->quadros[i].validade == 0) continue;
        if(tabela->quadros[i].referenciada == 0 && tabela->quadros[i].modificada == 0){ // Classe 0
            if(classe0 == -1){
                classe0 = i;
            }            
        }
        else if(tabela->quadros[i].referenciada == 0 && tabela->quadros[i].modificada == 1){ // Classe 1
            if(classe1 == -1){
                classe1 = i;
            }            
        }
        else if(tabela->quadros[i].referenciada == 1 && tabela->quadros[i].modificada == 0){ // Classe 2
            if(classe2 == -1){
                classe2 = i;
            }            
        }
        else if(tabela->quadros[i].referenciada == 1 && tabela->quadros[i].modificada == 1){ // Classe 3
            if(classe3 == -1){
                classe3 = i;
            }            
        }
    }

    //Retorna a classe encontrada
    if(classe0 != -1) return classe0;
    if(classe1 != -1) return classe1;
    if(classe2 != -1) return classe2;
    if(classe3 != -1) return classe3;

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

