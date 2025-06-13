#include <stdio.h>
#include "./estrutura-de-dados/fila_addrs.h"
#include "./estrutura-de-dados/hash.h"
#include "./memoria-handler/quadro-handler.h"
#include "./memoria-handler/memoria.h"
#include "./io-handler/leitura.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]){
    char *substituicao = argv[1];
    char *arquivo_endereco  = argv[2];

    int tamanhoPagina = atoi(argv[3]);
    int totalMemoria = atoi(argv[4]);

    
    int temp = pow(2, log2(tamanhoPagina)) * pow(2, 10); // Calcula o tamanho das páginas em KB
    int shift = log2(temp); // Quantidade de bits que devem ser descartados para identificar a página

    //page = addr >> shift, pelo pdf do saquetto

    int quantidadePaginas = totalMemoria / tamanhoPagina;

    printf("%d\n", temp);
    printf("%d\n", shift);
        
    Fila_addrs *addrss = leituraArquivo(arquivo_endereco);
    
    Hash* tabelaPag = criaHash(quantidadePaginas);

    QuadrosPagina* quadrosPagina = criaQuadrosMemoria(quantidadePaginas);  

    
    NO *aux = addrss->inicio;
    while(aux != NULL){
        

        acessoMemoria(tabelaPag, quadrosPagina, aux, shift);
        
        

        aux = aux->prox;
    }
    


    imprimirFila_addrs(addrss);
}

// gcc ./estrutura-de-dados/fila_addrs.c ./memoria-handler/bit-handler.c  leitura.c main.c -o oi