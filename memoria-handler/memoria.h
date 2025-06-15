#ifndef MEMORIA_H
#define MEMORIA_H 

#include "../estrutura-de-dados/tabela_inversa.h"
#include "./memoria.h"
#include "./algoritmos_sub.h"
#include "../relatorio.h"

int acessoMemoria(TabelaInversa* tabela, unsigned int addr, int shift, char rw, Relatorio* rl, int debug);


#endif