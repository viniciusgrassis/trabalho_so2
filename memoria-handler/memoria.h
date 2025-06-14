#ifndef MEMORIA_H
#define MEMORIA_H 

#include "./estrutura-de-dados/fila_addrs.h"
#include "./estrutura-de-dados/tabela_inversa.h"

int acessoMemoria(TabelaInversa* tabela, NO* endereco, int shift);


#endif