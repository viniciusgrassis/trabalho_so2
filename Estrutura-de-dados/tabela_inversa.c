#include "tabela_inversa.h"

TabelaInversa* criaTabela(int tamanho){
    TabelaInversa* tabela = (TabelaInversa*) malloc (sizeof(TabelaInversa));
    tabela->tamanho = tamanho;
    tabela->quadros = (QuadroFisico*) malloc (tamanho * sizeof(QuadroFisico));
    tabela->hash = (NoHash**) malloc (tamanho * sizeof(NoHash*));

    if(tabela->quadros == NULL || tabela->hash ==NULL) EXIT_FAILURE;
    
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

// chave da tabela hash
int chave(int paginaVirtual, int tamanho){
    return paginaVirtual % tamanho;
}

// busca otimizada pela hash
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

// procura de maneira sequencial uma posição vazia
int procuraVazio(TabelaInversa* tabela){
    for(int i = 0; i < tabela->tamanho; i++){
        if(tabela->quadros[i].validade == 0 ||
                tabela->quadros[i].paginaVirtual < 0){
                    return i;
                }
    }
    return -1;
}

int insereMapeamento(TabelaInversa* tabela, int paginaVirtual, int quadroFisico, unsigned int tempo, int modificada) {    
    
    if(tabela->quadros[quadroFisico].validade == 1){
        printf("Mapeamento em endereço ocupado!");
        exit(EXIT_FAILURE);
    } 
    
    // atualiza o quadro físico
    tabela->quadros[quadroFisico].paginaVirtual = paginaVirtual;
    tabela->quadros[quadroFisico].validade = 1;
    tabela->quadros[quadroFisico].ultimoAcesso = tempo; 
    tabela->quadros[quadroFisico].referenciada = 1;
    tabela->quadros[quadroFisico].modificada = modificada;
    
    // insere no início do índice da hash 
    int indice = chave(paginaVirtual, tabela->tamanho);
    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->paginaVirtual = paginaVirtual;
    novo->quadroFisico = quadroFisico;
    novo->prox = tabela->hash[indice]; 
    tabela->hash[indice] = novo;
    
    return 1;
}

// remoção do mapeamento da pagina virtual na hash e invalidez do quadro
int removePorQuadroFisico(TabelaInversa* tabela, int quadroFisico){

    int paginaVirtual = tabela->quadros[quadroFisico].paginaVirtual;
    
    int indice = chave(paginaVirtual, tabela->tamanho);
    NoHash* atual = tabela->hash[indice];
    NoHash* anterior = NULL;

    while (atual != NULL) {
        if (atual->quadroFisico == quadroFisico) {
            if (anterior == NULL) {
                tabela->hash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            
            // marca o quadro como inválido
            tabela->quadros[quadroFisico].validade = 0;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0; 
}

// desaloca toda a estrutura da tabela inversa
void destroiTabela(TabelaInversa* tabela) {
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

