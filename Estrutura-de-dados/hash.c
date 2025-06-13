#include "hash.h"

Hash* criaHash(int tamanho){
    Hash* h = (Hash*)malloc(sizeof(Hash));

    if(h == NULL) return NULL;

    h->tabela = (Fila_hash**)malloc(tamanho * sizeof(Fila_hash*));

    if(h->tabela == NULL) return NULL;

    for(int i = 0; i < tamanho; i++){
        h->tabela[i] = NULL;
    }
    
    h->tamanho = tamanho;

    return h;
}

void destroiHash(Hash* h){
    if(h == NULL) return;

    for(int i = 0; i < h->tamanho; i++){
        if(h->tabela[i] != NULL){
            destroiFilahash(h->tabela[i]);
        }
    }
    free(h->tabela);
    free(h);
}



int chave(unsigned int paginaVirtual, int totalQuadros){
    return paginaVirtual % totalQuadros; 
}
