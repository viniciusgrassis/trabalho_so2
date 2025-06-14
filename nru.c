#include "./estrutura-de-dados/tabela_inversa.h"
#include <stdio.h>
#include <stdlib.h>

/*
PaginaVirtual* encontrarVitimaNRU(Hash* tabelaPaginas){
    PaginaVirtual* vitima = NULL;
    for(int i = 0; i < tabelaPaginas->tamanho; i++){
        FilaPagVirtual* fila = tabelaPaginas->tabela[i];
        if(fila == NULL || fila->inicio == NULL) continue;
        PaginaVirtual* pagina = fila->inicio;
        while(pagina != NULL){
            if(pagina->referenciada == 0 && pagina->modficada == 0){ // classe 0
                vitima = pagina;
                break;
            }
            pagina = pagina->prox;
        }
        if(vitima != NULL) break;

    }
    if(vitima == NULL){
        for(int i = 0; i < tabelaPaginas->tamanho; i++){
            FilaPagVirtual* fila = tabelaPaginas->tabela[i];
            if(fila == NULL || fila->inicio == NULL) continue;
            PaginaVirtual* pagina = fila->inicio;
            while(pagina != NULL){
                if(pagina->referenciada == 0 && pagina->modficada == 1){ // classe 1
                    vitima = pagina;
                    break;
                }
                pagina = pagina->prox;
            }
            if(vitima != NULL) break;
        }
    }
    if(vitima == NULL){
        for(int i = 0; i < tabelaPaginas->tamanho; i++){
            FilaPagVirtual* fila = tabelaPaginas->tabela[i];
            if(fila == NULL || fila->inicio == NULL) continue;
            PaginaVirtual* pagina = fila->inicio;
            while(pagina != NULL){
                if(pagina->referenciada == 1 && pagina->modficada == 0){ // classe 2
                    vitima = pagina;
                    break;
                }
                pagina = pagina->prox;
            }
            if(vitima != NULL) break;
        }
    }

    if(vitima == NULL){
        for(int i = 0; i < tabelaPaginas->tamanho; i++){
            FilaPagVirtual* fila = tabelaPaginas->tabela[i];
            if(fila == NULL || fila->inicio == NULL) continue;
            PaginaVirtual* pagina = fila->inicio;
            while(pagina != NULL){
                if(pagina->referenciada == 1 && pagina->modficada == 1){  // classe 3
                    vitima = pagina;
                    break;
                }
                pagina = pagina->prox;
            }
            if(vitima != NULL) break;
        }
    }
    if(vitima == NULL){
        return NULL;
    }
}
    */

