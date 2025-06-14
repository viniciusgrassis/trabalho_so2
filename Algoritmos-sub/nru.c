#include "./nru.h"

int encontrarVitimaNRU(TabelaInversa* tabela){
    for(int i = 0; i < tabela->tamanho; i++){ // classe 0
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modficada == 0 && 
           tabela->quadros[i].referenciada == 0){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 1
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modficada == 1 && 
           tabela->quadros[i].referenciada == 0){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 2
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modficada == 0 && 
           tabela->quadros[i].referenciada == 1){ 
            return i;
        }
    }

    for(int i = 0; i < tabela->tamanho; i++){ // classe 3
        if(tabela->quadros[i].validade == 1 &&
           tabela->quadros[i].modficada == 1 && 
           tabela->quadros[i].referenciada == 1){ 
            return i;
        }
    }

    return -1; // página não encontrada
}
