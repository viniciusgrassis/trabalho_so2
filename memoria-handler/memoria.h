#ifndef MEMORIA_H
#define MEMORIA_H 

#include "../estrutura-de-dados/tabela_inversa.h"
#include "./memoria.h"
#include "./algoritmos_sub.h"

int acessoMemoria(TabelaInversa* tabela, int paginaVirtual, char rw, char *algoritmoSubstituicao, unsigned int tempo, unsigned int *sujas);


#endif