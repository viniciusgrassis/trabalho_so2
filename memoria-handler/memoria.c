#include "./memoria.h"

int acessoMemoria(TabelaInversa* tabela, NO* endereco, int shift){
    int indice = buscaTabelaInversa(tabela, (endereco->addrs >> shift));

    if( indice != -1){
        // sucesso
        return 1;
    }

    int vazio = procuraVazio(tabela);    

    if(vazio != vazio){
        insereMapeamento(tabela, (endereco->addrs >> shift), vazio);
    } else {
        // subs aqui
    }
    
}