#include <stdio.h>
#include "./Estrutura-de-dados/fila_addr.h"
#include "./Estrutura-de-dados/leitura.h"

int main(int argc, char *argv[]){
    Fila_addr *addrs = leituraArquivo("teste.txt");
    imprimirFila_addr(addrs);
}

//  gcc fila_addr.c leitura.c main.c -o oi