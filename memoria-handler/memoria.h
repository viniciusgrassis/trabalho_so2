#ifndef MEMORIA_H
#define MEMORIA_H 

#include "./quadro-handler.h"
#include "./tabela-handler.h"
#include "./estrutura-de-dados/fila_addrs.h"

int acessoMemoria(Hash* tabelaPaginas, QuadrosPagina* quadrosPagina, NO* endereco, int shift);

#endif