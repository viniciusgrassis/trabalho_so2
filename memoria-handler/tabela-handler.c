#include "./tabela-handler.h"

int acessoTabela(Hash* tabelaPaginas, int addrsShift){
    int indice = chave(addrsShift , tabelaPaginas->tamanho);

    FilaPagVirtual *lista = tabelaPaginas->tabela[indice];

    int paginaFisica = buscarPaginaFisica(lista, addrsShift);

    return paginaFisica;
}


int mapearFisicoTabela(Hash* tabelaPaginas, int addrsShift ){
    int indice = chave(addrsShift , tabelaPaginas->tamanho);

    FilaPagVirtual *lista = tabelaPaginas->tabela[indice];

   if( enfileirarFilaPagVirtual(lista, addrsShift)) return 1;
    return 0;


}
