#include "./memoria.h"

int acessoMemoria(TabelaInversa* tabela, NO* endereco, int shift){
    int paginaVirtual = (endereco->addrs >> shift);
    int indice = buscaTabelaInversa(tabela, paginaVirtual);

    if( indice != -1){
        // sucesso
        return 1;
    }

    int vazio = procuraVazio(tabela);    

    if(vazio != vazio){
        insereMapeamento(tabela, paginaVirtual, vazio);
    } else {
        // subs aqui
        int quadro = 0; // retorno do quadro achado pela função de troca ---------------------------------
        removePorQuadroFisico(tabela, quadro);
        insereMapeamento(tabela, paginaVirtual, quadro);
    }
    
}