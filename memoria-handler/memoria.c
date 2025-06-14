#include "./memoria.h"
#include "../Algoritmos-sub/lru.h"
#include "../Algoritmos-sub/nru.h"

int acessoMemoria(TabelaInversa* tabela, int paginaVirtual, char *algoritmoSubstituicao, unsigned int tempo){
    int indice = buscaTabelaInversa(tabela, paginaVirtual);

    if( indice != -1){
        // sucesso
        return 0;
    }

    int vazio = procuraVazio(tabela);    
    if(vazio != -1){
        insereMapeamento(tabela, paginaVirtual, vazio, tempo);
    } else {
        int quadro = -1;
        if(strcmp(algoritmoSubstituicao, "lru") == 0){
            quadro = encontrarLRU(tabela);
        } else if(strcmp(algoritmoSubstituicao, "nru") == 0){
            quadro = encontrarVitimaNRU(tabela);
        } else if(strcmp(algoritmoSubstituicao, "segunda_chance") == 0) {
            //quadro = encontrarSegundaChance(tabela);
        }
        // subs aqui
        //int quadroVitima = encontrarVitimaNRU(tabela);
        //int quadro = 0; // retorno do quadro achado pela função de troca ---------------------------------
        if(quadro >= 0) {
            removePorQuadroFisico(tabela, quadro);
            insereMapeamento(tabela, paginaVirtual, quadro, tempo);
        }
    }
    return 1;
}