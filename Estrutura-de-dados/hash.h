#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#include "./fila_virtual.h"

typedef struct{
    FilaPagVirtual **tabela;
    int tamanho;
} Hash;

Hash* criaHash(int tamanho);

void destroiHash(Hash* h);

int chave(unsigned int pagina_virtual, int total_quadros);

#endif