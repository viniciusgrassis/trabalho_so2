#ifndef TABELA_HANDLER_H
#define TABELA_HANDLER_H

#include "./estrutura-de-dados/hash.h"
#include "./estrutura-de-dados/fila_addrs.h"

int acessoTabela(Hash* tabelaPaginas, int addrsShift);

#endif