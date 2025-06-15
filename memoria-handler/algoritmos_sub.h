#ifndef ALGORITMOS_SUB_H
#define ALGORITMOS_SUB_H

#include "../estrutura-de-dados/tabela_inversa.h"
#include <stdio.h>
#include <stdlib.h>

int encontrarLRU(TabelaInversa * tabela);
int encontrarNRU(TabelaInversa* tabela);
int encontrarSegundaChance(TabelaInversa * tabela);

#endif