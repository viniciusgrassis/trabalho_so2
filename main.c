#include <stdio.h>
#include "./estrutura-de-dados/tabela_inversa.h"
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
    TabelaInversa* tabela = criaTabela(quantidadePaginas);
    unsigned int leituras = 0, escritas = 0, acessos = 0;


    printf("%d\n", temp);
    printf("%d\n", shift);
        
    unsigned int addr;
    char rw;
    FILE *f = fopen(arquivo_endereco, "r");

    while(fscanf(f, "%x %c", &addr, &rw) != EOF) {
        printf("%u, %c\n", addr, rw);
        if(rw == 'R') leituras++;
        if(rw == 'W') escritas++;
        if(rw == 'R' || rw == 'W') {
            acessos++;
        } else {
            continue;
        }
    }
    printf("Leituras = %u, escritas = %u\n", leituras, escritas);
    /*
    NO *aux = addrss->inicio;
    while(aux != NULL){
        

        
    
        
    
    aux = aux->prox;
}
    


*/
}

// gcc ./estrutura-de-dados/fila_addrs.c ./memoria-handler/bit-handler.c  leitura.c main.c -o oi