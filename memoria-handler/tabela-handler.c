#include "./tabela-handler.h"

int acessoTabela(Hash* tabelaPaginas, int addrsShift){
    int indice = chave(addrsShift , tabelaPaginas->tamanho);

    FilaPagVirtual *lista = tabelaPaginas->tabela[indice];

    int paginaFisica = buscarPaginaFisica(lista, addrsShift);

    return paginaFisica;
}