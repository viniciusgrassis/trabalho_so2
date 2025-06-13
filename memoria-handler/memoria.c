#include "./quadro-handler.h"
#include "./tabela-handler.h"
#include "./estrutura-de-dados/fila_addrs.h"

int acessoMemoria(Hash* tabelaPaginas, QuadrosPagina* quadrosPagina, NO* endereco, int shift){
    int posicaoFisica = acessoTabela( tabelaPaginas, ((endereco->addrs) >> shift));

    if(posicaoFisica != -1){ // = -1 erro. tem que criar pagina virtual
        

    } 
    
}