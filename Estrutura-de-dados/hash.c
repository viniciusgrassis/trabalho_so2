#include "hash.h"

Hash* criaHash(int tamanho){
    Hash* h;
    h = (Hash*)malloc(sizeof(Hash));
    if(h != NULL){
        h->tamanho = tamanho;
        h->quantidade = 0;
        h->tabela = (int**)malloc(tamanho * sizeof(int*));
        if(h->tabela == NULL) return NULL;
        for(int i = 0; i < tamanho; i++){
            h->tabela[i] = NULL;
        }
    }
    return h;
}

void destroiHash(Hash* h){
    if(h != NULL){
        for(int i = 0; i < h->tamanho; i++){
            if(h->tabela[i] != NULL){
                free(h->tabela[i]);
            }
        }
        free(h->tabela);
        free(h);
    }
}

int chave(unsigned int pagina_virtual, int total_quadros){
    return pagina_virtual % total_quadros; 
}