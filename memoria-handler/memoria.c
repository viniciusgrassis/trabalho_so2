#include "./memoria.h"

int acessoMemoria(TabelaInversa* tabela, unsigned int addr, int shift, char rw, Relatorio* rl, int debug){
    int paginaVirtual = addr >> shift; // numero da pagina virtual
    int quadroFisico = buscaTabelaInversa(tabela, paginaVirtual); // numero do quadro fisico que contem a pagina virtual
    int frequenciaDeLimpeza = (tabela->tamanho * 0.2 < 10) ? 10 : tabela->tamanho * 0.2; // limpador do bit R baseado no tamanho da tabela

    if(rl->acessos > 0 && rl->acessos % frequenciaDeLimpeza == 0) { // seta os bits R de toda a tabela pra R a cada intervalo de acesso
        if(debug) {
            printf("Bit de referência limpo em todos os quadros.\n");
        }
        for(int i = 0; i < tabela->tamanho; i++) tabela->quadros[i].referenciada = 0;
    }
    if(debug) printf("Acesso %d - ", rl->acessos);

    if( quadroFisico != -1){ // já existe um quadro mapeado com o endereço virtual. Page hit
        if(debug) printf("Page hit, o endereço %08x está no quadro %d.\n", addr, quadroFisico);

        if(rw == 'W') tabela->quadros[quadroFisico].modificada = 1;
        tabela->quadros[quadroFisico].ultimoAcesso = rl->acessos;
        tabela->quadros[quadroFisico].referenciada = 1;
        // sucesso
        return 0;
    }
    
    // sequência para tratar a Page miss
    int vazio = procuraVazio(tabela); // procura uma posição da tabela vazia(invalida ou sem mapeamento)

    if(vazio != -1){ // achou posição vazia. Somente inserir e mapear na hash
        if(debug) printf("Page miss, inseriu o endereço %08x no quadro vazio %d. \n", addr, vazio);

        insereMapeamento(tabela, paginaVirtual, vazio, rl->acessos, (rw == 'W') ? 1 : 0);
        
    } else { // sem pagina vazia. Deve procurar uma pagina para substituir pelo algoritmo definido no argumento passado na execução
        int quadro = -1;
        if(strcmp(rl->substituicao, "lru") == 0){
            quadro = encontrarLRU(tabela);

        } else if(strcmp(rl->substituicao, "nru") == 0){
            quadro = encontrarNRU(tabela);

        } else if(strcmp(rl->substituicao, "segunda_chance") == 0) {
            quadro = encontrarSegundaChance(tabela);
        }

        if(quadro >= 0) {
            unsigned int offset = addr & ((1 << shift) - 1);
            unsigned novoAddrs = ((unsigned)quadro << shift) | offset;

            if(debug) printf("Page miss, quadro %d substituiu o endereço %08x pelo %08x.\n", quadro, addr, novoAddrs);

            if(tabela->quadros[quadro].modificada == 1) rl->pagSujas++;
            // printf("%d\n", tabela->quadros[quadro].modificada);
            removePorQuadroFisico(tabela, quadro); // tira o mapeamento da hash(destroi nó)
            insereMapeamento(tabela, paginaVirtual, quadro, rl->acessos, (rw == 'W')? 1 : 0); // insere nova pagina valida e faz um novo mapeamento para a hash

        }
    }
    return 1;
}