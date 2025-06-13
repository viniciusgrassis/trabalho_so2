#include <stdio.h>
#include "./estrutura-de-dados/fila_addrs.h"
#include "./io-handler/leitura.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]){
    char *substituicao = argv[1];
    char *arquivo_endereco  = argv[2];

    int tamanhoPagina = atoi(argv[3]);
    int totalMemoria = atoi(argv[4]);

    
    int temp = pow(2, log2(tamanhoPagina)) * pow(2, 10);
    printf("%d\n", temp);
    int s = 0;
    while(temp > 1) {
        temp = temp >> 1;
        s++;
    }
    printf("%d\n", s);
        
    Fila_addrs *addrss = leituraArquivo(arquivo_endereco);
    
    NO *aux = addrss->inicio;
    while(aux != NULL){

        

        aux = aux->prox;
    }
    


    imprimirFila_addrs(addrss);
}

// gcc ./estrutura-de-dados/fila_addrs.c ./memoria-handler/bit-handler.c  leitura.c main.c -o oi