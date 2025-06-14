#include "tabela_inversa.h"

TabelaInversa* criaTabela(int tamanho){
    TabelaInversa* tabela = (TabelaInversa*) malloc (sizeof(TabelaInversa));
    tabela->tamanho = tamanho;
    tabela->quadros = (QuadroFisico*) malloc (tamanho * sizeof(QuadroFisico));
    tabela->hash = (NoHash**) malloc (tamanho * sizeof(NoHash*));
    
    for (int i = 0; i < tamanho; i++){
        tabela->quadros[i].validade = 0;
        tabela->quadros[i].paginaVirtual = -1;
        tabela->quadros[i].referenciada = 0;
        tabela->quadros[i].ultimoAcesso = -1;
        tabela->quadros[i].modificada = 0;

        tabela->hash[i] = NULL;
    }
    return tabela;

}

int chave(int paginaVirtual, int tamanho){
    return paginaVirtual % tamanho;
}

int buscaTabelaInversa(TabelaInversa* tabela, int paginaVirtual) {
    int indice = chave(paginaVirtual, tabela->tamanho);
    
    NoHash* atual = tabela->hash[indice];
    while (atual != NULL) {
        if (atual->paginaVirtual == paginaVirtual) {
            return atual->quadroFisico; // Retorna o quadro físico
        }
        atual = atual->prox;
    }
    
    return -1; 
}


int procuraVazio(TabelaInversa* tabela){
    for(int i = 0; i < tabela->tamanho; i++){
        if(tabela->quadros[i].validade == 0 ||
                tabela->quadros->paginaVirtual < 0){
                    return i;
                }
    }
    return -1;
}

int insereMapeamento(TabelaInversa* tabela, int paginaVirtual, int quadroFisico, unsigned int tempo) {    
    // Atualiza o quadro físico
    tabela->quadros[quadroFisico].paginaVirtual = paginaVirtual;
    tabela->quadros[quadroFisico].validade = 1;
    tabela->quadros[quadroFisico].ultimoAcesso = tempo; //  mudaaaaaaaaaaaaaaaaaaar
    
    // Insere na hash table
    int indice = chave(paginaVirtual, tabela->tamanho);
    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->paginaVirtual = paginaVirtual;
    novo->quadroFisico = quadroFisico;
    novo->prox = tabela->hash[indice]; // Encadeamento
    tabela->hash[indice] = novo;
    
    return 1;
}

int removePagina(TabelaInversa* tabela, int paginaVirtual) {
    int indice = chave(paginaVirtual, tabela->tamanho);
    NoHash* atual = tabela->hash[indice];
    NoHash* anterior = NULL;
    
    // Procura a página na hash table
    while (atual != NULL) {
        if (atual->paginaVirtual == paginaVirtual) {
            // Marca o quadro físico como inválido
            tabela->quadros[atual->quadroFisico].validade = 0;
            tabela->quadros[atual->quadroFisico].paginaVirtual = -1;
            
            // Remove o nó da hash table
            if (anterior == NULL) {
                tabela->hash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            
            // Libera a memória
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    return 0; // Página não encontrada
}


int removePorQuadroFisico(TabelaInversa* tabela, int quadroFisico){

    int paginaVirtual = tabela->quadros[quadroFisico].paginaVirtual;
    
    // Remove da hash table
    int indice = chave(paginaVirtual, tabela->tamanho);
    NoHash* atual = tabela->hash[indice];
    NoHash* anterior = NULL;

    while (atual != NULL) {
        if (atual->quadroFisico == quadroFisico) {
            // Remove o nó da lista encadeada
            if (anterior == NULL) {
                tabela->hash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            // Libera o nó
            free(atual);
            
            // Marca o quadro como inválido
            tabela->quadros[quadroFisico].validade = 0;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0; // Não deveria acontecer se a tabela estiver consistente
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

