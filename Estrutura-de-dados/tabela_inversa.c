#include "tabela_inversa.h"

int* criaTabela(int tamanho){
    TabelaInversa* tabela = (TabelaInversa*) malloc (sizeof(TabelaInversa));
    tabela->tamanho = tamanho;
    tabela->quadros = (QuadroFisico*) malloc (tamanho * sizeof(TabelaInversa));
    
    for (int i = 0; i < tamanho; i++){
        tabela->quadros[i].validade = 0;
        tabela->quadros[i].paginaVirtual = 0;
        tabela->quadros[i].referenciada = 0;
        tabela->quadros[i].ultimoAcesso = -1;
        tabela->quadros[i].modficada = 0;

    }
    return tabela;

}

void destroiTabela(TabelaInversa* tabela){
    free(tabela->quadros);
    free(tabela);
}

