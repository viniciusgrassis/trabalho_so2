#include <stdio.h>
#include "./Estrutura-de-dados/fila_addrs.h"
#include "./Estrutura-de-dados/leitura.h"

int main(int argc, char *argv[]){
    Fila_addrs *addrss = leituraArquivo("teste.txt");
    imprimirFila_addrs(addrss);
}

//  gcc fila_addrs.c leitura.c main.c -o oi