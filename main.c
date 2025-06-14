#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "./estrutura-de-dados/tabela_inversa.h"
#include "./memoria-handler/memoria.h"


int main(int argc, char *argv[]){
    char *substituicao = argv[1];
    char *arquivo_endereco  = argv[2];
    int tamanhoPagina = atoi(argv[3]);
    int totalMemoria = atoi(argv[4]);
    char *d = argv[5];
    int debug = (d == NULL) ? 0 : 1;

    int temp = pow(2, log2(tamanhoPagina)) * pow(2, 10); // Calcula o tamanho das páginas em KB
    int shift = log2(temp); // Quantidade de bits que devem ser descartados para identificar a página

    int quantidadePaginas = totalMemoria / tamanhoPagina;
    TabelaInversa* tabela = criaTabela(quantidadePaginas);
    unsigned int leituras = 0, escritas = 0, acessos = 0, faltasDePagina = 0, pagSujas = 0;
        
    unsigned int addr;
    char rw;
    FILE *f = fopen(arquivo_endereco, "r");

    while(fscanf(f, "%x %c", &addr, &rw) != EOF) {
        // printf("%u, %c\n", addr, rw); 
        if(rw == 'R') leituras++;
        if(rw == 'W') escritas++;
        if(rw == 'R' || rw == 'W') {
            acessos++;
        } else {
            continue;
        }
        int paginaVirtual = addr >> shift;
        faltasDePagina += acessoMemoria(tabela, paginaVirtual, rw, substituicao, acessos, &pagSujas, debug);

    }
    
    // for(int i = 0; i < tabela->tamanho; i++){
    //     printf("%d-", tabela->quadros[i].validade);
    // }

    printf(
        "Arquivo de entrada: %s\n"
        "Tamanho da memoria: %d KB\n"
        "Tamanho das paginas: %d KB\n"
        "Tecnica de reposicao: %s\n"
        "Paginas lidas = %u\n" 
        "Paginas escritas = %u\n"
        "Total de acessos = %u\n"
        "Faltas de paginas = %u\n"
        "Paginas \"sujas\" atualizadas no disco = %u\n",
        arquivo_endereco, totalMemoria, tamanhoPagina, substituicao,leituras, escritas, acessos, faltasDePagina, pagSujas);
    /*
    NO *aux = addrss->inicio;
    while(aux != NULL){
        

        
    
        
    
    aux = aux->prox;
}
    


*/
}

// gcc ./estrutura-de-dados/fila_addrs.c ./memoria-handler/bit-handler.c  leitura.c main.c -o oi