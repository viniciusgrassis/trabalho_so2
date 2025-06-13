#include "./quadro-handler.h"
#include "./tabela-handler.h"
#include "./estrutura-de-dados/fila_addrs.h"

int acessoMemoria(Hash* tabelaPaginas, QuadrosPagina* quadrosPagina, NO* endereco, int shift){
    int posicaoFisica = acessoTabela( tabelaPaginas, ((endereco->addrs) >> shift));

    if(posicaoFisica != -1){ // = -1 erro. tem que criar pagina virtual
        // deu certo e fazer o codigo que segue

        
        return 1;
    } 

    // deu errado. procurar quadro vazio. se estiver cheio, tem que esvaziar e apagar da tabela o mapeamento.
    // depois mapear para a tabela.
    
    int quadroVazio = procuraQuadroVazio(quadrosPagina);

    if(quadroVazio) {
        // mapear
    } else {
        // politica de subst
    }




}