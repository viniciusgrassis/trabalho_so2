#include <stdio.h>
#include "./estrutura-de-dados/fila_addrs.h"
#include "./leitura.h"
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    char *arquivo_endereco  = argv[1];

    char *substituicao = argv[2];

    int tamanhoPagina = atoi(argv[3]);      // mais simples
    int totalMemoria = atoi(argv[4]);

        
    Fila_addrs *addrss = leituraArquivo(arquivo_endereco);
    
    NO *aux = addrss->inicio;
    while(aux != NULL){

        

        aux = aux->prox;
    }
    


    imprimirFila_addrs(addrss);
}

// gcc ./estrutura-de-dados/fila_addrs.c ./memoria-handler/bit-handler.c  leitura.c main.c -o oi