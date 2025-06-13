#include "./fila_addrs.h"

NO *criaNO(){
    NO *no = (NO*)malloc(sizeof(NO));
    no->prox = NULL;
    return no;
}

void destroiNO(NO *no){
    free(no);
}

Fila_addrs *criaFilaAddrs(){
    Fila_addrs *fila_addrs = (Fila_addrs*)malloc(sizeof(Fila_addrs));
    if(fila_addrs != NULL){
        fila_addrs->inicio = fila_addrs->final = NULL;
        fila_addrs->tamanho = 0;
    }
    return fila_addrs;
}

void destroiFilaAddrs(Fila_addrs *fila_addrs){
    if(fila_addrs == NULL) return;
    while(fila_addrs->inicio != NULL){
        NO *aux = fila_addrs->inicio;
        fila_addrs->inicio = fila_addrs->inicio->prox;
        destroiNO(aux);
    }
    free(fila_addrs);
}

int estaVaziaFilaAddrs(Fila_addrs *fila_addrs){
    if(fila_addrs == NULL) return 0;
    return fila_addrs->tamanho == 0;
}

int enfileirarAddrs(Fila_addrs *fila_addrs, int addrs, char op){
    if(fila_addrs == NULL) return 0;
    NO *novo = criaNO();
    novo->addrs = addrs;
    novo->op = op;
    
    if(estaVaziaFilaAddrs(fila_addrs)){
        fila_addrs->inicio = novo;
    } else {
        fila_addrs->final->prox = novo;
    }   
    fila_addrs->final = novo;
    fila_addrs->tamanho++;
    return 1;
}

int desenfileirarAddrs(Fila_addrs *fila_addrs){
    if(fila_addrs == NULL) return 0;
    if(estaVaziaFilaAddrs(fila_addrs)) return 0;
    NO *aux = fila_addrs->inicio;
    fila_addrs->inicio = aux->prox;
    if(fila_addrs->final == aux) fila_addrs->final = aux->prox;
    destroiNO(aux);
    fila_addrs->tamanho--;
    return 1;
}

void imprimirFila_addrs(Fila_addrs *fila_addrs){
    if (fila_addrs == NULL) return;
    NO *aux = fila_addrs->inicio;
    int number = 1;
    while (aux != NULL){
        printf("%d = %d , %c\n", number, aux->addrs, aux->op); number++;
        aux = aux->prox;
    }
    printf("\n");
}

