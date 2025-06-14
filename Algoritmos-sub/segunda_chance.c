#include "./segunda_chance.h"

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