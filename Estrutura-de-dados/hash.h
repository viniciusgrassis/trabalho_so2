#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#include "./fila_hash.h"

typedef struct{
    Fila_hash **tabela;
    int tamanho;
} Hash;

Hash* criaHash(int tamanho);

void destroiHash(Hash* h);

int chave(unsigned int pagina_virtual, int total_quadros);

#endif