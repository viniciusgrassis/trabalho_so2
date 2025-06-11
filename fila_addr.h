#ifndef FILA_H
#define FILA_H

typedef struct No {
    int addr; // endereco em decimal
    char op; // r ou w  
    struct No *prox;
} NO;

typedef struct {
    NO *inicio;
    NO *final;
    int tamanho;
} Fila_addr;

Fila_addr *criaFilaAddr();
void destroiFilaAddr(Fila_addr *fila);
int enfileirarAddr(Fila_addr *fila, int addr, char op);
int desenfileirarAddr(Fila_addr *fila);
int estaVaziaFilaAddr(Fila_addr *fila);
void imprimirFila_addr(Fila_addr *fila);
int tamanhoFilaAddr(Fila_addr *fila);

#endif