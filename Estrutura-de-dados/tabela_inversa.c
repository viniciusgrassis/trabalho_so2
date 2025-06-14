#include "tabela_inversa.h"

TabelaInversa* criaTabela(int tamanho){
    TabelaInversa* tabela = (TabelaInversa*) malloc (sizeof(TabelaInversa));
    tabela->tamanho = tamanho;
    tabela->quadros = (QuadroFisico*) malloc (tamanho * sizeof(QuadroFisico));
    tabela->hash = (NoHash**) malloc (tamanho * sizeof(NoHash*));
    
    for (int i = 0; i < tamanho; i++){
        tabela->quadros[i].validade = 0;
        tabela->quadros[i].paginaVirtual = 0;
        tabela->quadros[i].referenciada = 0;
        tabela->quadros[i].ultimoAcesso = -1;
        tabela->quadros[i].modficada = 0;

        tabela->hash[i] = NULL;
    }
    return tabela;

}

int chave(int paginaVirtual, int tamanho){
    return paginaVirtual % tamanho;
}

int buscaTabelaInversa(TabelaInversa* tabela, int paginaVirtual) {
    int indice = hash(paginaVirtual, tabela->tamanho);
    
    NoHash* atual = tabela->hash[indice];
    while (atual != NULL) {
        if (atual->paginaVirtual == paginaVirtual) {
            return atual->paginaFisica; // Retorna o quadro físico
        }
        atual = atual->prox;
    }
    
    return -1; 
}

int inserePagina(TabelaInversa* tabela, int paginaVirtual, int quadroFisico) {    
    // Atualiza o quadro físico
    tabela->quadros[quadroFisico].paginaVirtual = paginaVirtual;
    tabela->quadros[quadroFisico].validade = 1;
    tabela->quadros[quadroFisico].ultimoAcesso = 0; //  mudaaaaaaaaaaaaaaaaaaar
    
    // Insere na hash table
    int indice = hash(paginaVirtual, tabela->tamanho);
    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->paginaVirtual = paginaVirtual;
    novo->paginaFisica = quadroFisico;
    novo->prox = tabela->hash[indice]; // Encadeamento
    tabela->hash[indice] = novo;
    
    return 1;
}

void destroiTabela(TabelaInversa* tabela) {
    // Libera nós da hash table
    for (int i = 0; i < tabela->tamanho; i++) {
        NoHash* atual = tabela->hash[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    
    free(tabela->quadros);
    free(tabela->hash);
    free(tabela);
}

