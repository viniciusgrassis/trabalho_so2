#include "./fila_hash.h"

NO *criaNO() {
    NO *no = (NO*)malloc(sizeof(NO));
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

void destroiNO(NO *no){
    free(no);
}

Fila_hash *criaFilahash(){
    Fila_hash *fila_hash = (Fila_hash*) malloc (sizeof(Fila_hash));
    if(fila_hash != NULL){
        fila_hash->inicio = fila_hash->final = NULL;
        fila_hash->tamanho = 0;
    }
    return fila_hash;
}

void destroiFilahash(Fila_hash *fila_hash) {
    if(fila_hash == NULL) return;
    while(fila_hash->inicio != NULL){
        NO *aux = fila_hash->inicio;
        fila_hash->inicio = fila_hash->inicio->prox;
        destroiNO(aux);
    }
    free(fila_hash);
}

int estaVaziaFilahash(Fila_hash *fila_hash) {
    if(fila_hash == NULL) return 0;
    return fila_hash->tamanho == 0;
}

int enfileirarhash(Fila_hash *fila_hash, int paginaVirutal, int paginaFisica) {
    if(fila_hash == NULL) return 0;
    NO *novo = criaNO();

    novo->paginaVirtual = paginaVirutal;
    novo->paginaFisica = paginaFisica;
    
    if(estaVaziaFilahash(fila_hash)){
        fila_hash->inicio = novo;
    } else {
        novo->ant = fila_hash->final;
        fila_hash->final->prox = novo;
    }   
    fila_hash->final = novo;
    fila_hash->tamanho++;
    return 1;
}

int desenfileirarhash(Fila_hash *fila_hash) {
    if(fila_hash == NULL) return 0;
    if(estaVaziaFilahash(fila_hash)) return 0;
    
    NO *aux = fila_hash->inicio;
    fila_hash->inicio = aux->prox;
    if(fila_hash->final == aux) fila_hash->final = aux->prox;
    destroiNO(aux);
    fila_hash->tamanho--;
    return 1;
}

void imprimirFila_hash(Fila_hash *fila_hash){
    if (fila_hash == NULL) return;
    NO *aux = fila_hash->inicio;
    int number = 1;
    while (aux != NULL){
        printf("%d = %X , %c\n", number, aux->hash, aux->op); number++;
        aux = aux->prox;
    }
    printf("\n");
}

