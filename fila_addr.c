#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./fila_addr.h"

NO *criaNO() {
    NO *no = (NO*)malloc(sizeof(NO));
    no->prox = NULL;
    return no;
}

void destroiNO(NO *no){
    free(no);
}

Fila_addr *criaFilaAddr(){
    Fila_addr *fila_addr = (Fila_addr*)malloc(sizeof(Fila_addr));
    if(fila_addr != NULL){
        fila_addr->inicio = fila_addr->final = NULL;
        fila_addr->tamanho = 0;
    }
    return fila_addr;
}

void destroiFilaAddr(Fila_addr *fila_addr) {
    if(fila_addr == NULL) return;
    while(fila_addr->inicio != NULL){
        NO *aux = fila_addr->inicio;
        fila_addr->inicio = fila_addr->inicio->prox;
        destroiNO(aux);
    }
    free(fila_addr);
}

int estaVaziaFilaAddr(Fila_addr *fila_addr) {
    if(fila_addr == NULL) return 0;
    return fila_addr->tamanho == 0;
}

int enfileirarAddr(Fila_addr *fila_addr, int addr, char op) {
    if(fila_addr == NULL) return 0;
    NO *novo = criaNO();
    novo->addr = addr;
    novo->op = op;
    
    if(estaVaziaFila_addr(fila_addr)){
        fila_addr->inicio = novo;
    } else {
        fila_addr->final->prox = novo;
    }   
    fila_addr->final = novo;
    fila_addr->tamanho++;
    return 1;
}

int desenfileirarAddr(Fila_addr *fila_addr) {
    if(fila_addr == NULL) return 0;
    if(estaVaziaFila_addr(fila_addr)) return 0;
    NO *aux = fila_addr->inicio;
    fila_addr->inicio = aux->prox;
    if(fila_addr->final == aux) fila_addr->final = aux->prox;
    destroiNO(aux);
    fila_addr->tamanho--;
    return 1;
}

void imprimirFila_addr(Fila_addr *fila_addr){
    if (fila_addr == NULL) return;
    NO *aux = fila_addr->inicio;
    int number = 1;
    while (aux != NULL){
        printf("%d = %X , %c\n", number, aux->addr, aux->op); number++;
        aux = aux->prox;
    }
    printf("\n");
}

int tamanhoFilaAddr(Fila_addr *fila_addr){
    if(fila_addr == NULL) return -1;
    return fila_addr->tamanho;
}
