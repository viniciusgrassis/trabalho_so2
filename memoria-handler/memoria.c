#include "./memoria.h"
#include "../Algoritmos-sub/lru.h"
#include "../Algoritmos-sub/nru.h"

int acessoMemoria(TabelaInversa* tabela, int paginaVirtual, char rw, char *algoritmoSubstituicao, unsigned int tempo, unsigned int *sujas){
    int quadroFisico = buscaTabelaInversa(tabela, paginaVirtual);

    if( quadroFisico != -1){
        if(rw == 'W') tabela->quadros[quadroFisico].modificada = 1;
        tabela->quadros[quadroFisico].ultimoAcesso = tempo;
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
            if(tabela->quadros[quadro].modificada == 1) *(sujas)++;
            removePorQuadroFisico(tabela, quadro);
            insereMapeamento(tabela, paginaVirtual, quadro, tempo);
        }
    }
    return 1;
}