#include "./memoria.h"

int acessoMemoria(Hash* tabelaPaginas, QuadrosPagina* quadrosPagina, NO* endereco, int shift){
    int posicaoFisica = acessoTabela( tabelaPaginas, ((endereco->addrs) >> shift));

    if(posicaoFisica != -1){ // = -1 erro. tem que criar pagina virtual
        // deu certo e fazer o codigo que segue
    // 8========================================================================================>> - - - 
        
        return 1;
    } 

    // deu errado. procurar quadro vazio. se estiver cheio, tem que esvaziar e apagar da tabela o mapeamento.
    // depois mapear para a tabela.
    
    int quadroVazio = procuraQuadroVazio(quadrosPagina);

    if(quadroVazio){
        mapearFisicoTabela(tabelaPaginas, ((endereco->addrs) >> shift));
        // mapear
        
         // 8========================================================================================>> - - - 

    } else {
         // 8========================================================================================>> - - - 
        
        // politica de subst
    }




}