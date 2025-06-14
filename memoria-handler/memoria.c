#include "./memoria.h"

int acessoMemoria(TabelaInversa* tabela, int paginaVirtual, char rw, char *algoritmoSubstituicao, unsigned int tempo, unsigned int *sujas){
    int quadroFisico = buscaTabelaInversa(tabela, paginaVirtual);

    if(tempo > 0 && tempo % (int)(tabela->tamanho * 0.2) == 0) {
        for(int i = 0; i < tabela->tamanho; i++) tabela->quadros[i].referenciada = 0;
    }

    if( quadroFisico != -1){
        if(rw == 'W') tabela->quadros[quadroFisico].modificada = 1;
        tabela->quadros[quadroFisico].ultimoAcesso = tempo;
        tabela->quadros[quadroFisico].referenciada = 1;
        // sucesso
        return 0;
    }

    int vazio = procuraVazio(tabela);    
    if(vazio != -1){
        insereMapeamento(tabela, paginaVirtual, vazio, tempo, (rw == 'W') ? 1 : 0);
    } else {
        // printf("\n\n\n\n\n\n\n\n");
        int quadro = -1;
        if(strcmp(algoritmoSubstituicao, "lru") == 0){
            quadro = encontrarLRU(tabela);

        } else if(strcmp(algoritmoSubstituicao, "nru") == 0){
            quadro = encontrarVitimaNRU(tabela);

        } else if(strcmp(algoritmoSubstituicao, "segunda_chance") == 0) {
            quadro = encontrarSegundaChance(tabela);
        }

        if(quadro >= 0) {
            if(tabela->quadros[quadro].modificada == 1) (*sujas)++;
            // printf("%d\n", tabela->quadros[quadro].modificada);
            removePorQuadroFisico(tabela, quadro);
            insereMapeamento(tabela, paginaVirtual, quadro, tempo, (rw == 'W')? 1 : 0);

        }
    }
    return 1;
}