#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **tabela;
    int tamanho, quantidade;
}Hash;

Hash* criaHash(int tamanho);
void destroiHash(Hash* h);
int chave(unsigned int pagina_virtual, int total_quadros);

#endif