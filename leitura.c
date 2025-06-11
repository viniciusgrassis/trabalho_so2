#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_addr.h"


int hex_int(const char *hex){
    return (int)strtol(hex, NULL, 16);
}

Fila_addr* leituraArquivo(char *path){
    FILE *arquivo = fopen(path, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return -1;
    }

    Fila_addr *fila = criaFilaAddr();


    // char *tok1;
    // char *addrs = strtok_r(arquivo, "\n", &tok1);
    // while(addrs != NULL){
    //     char *tok2;
    //     char *aux = strtok_r(addrs, " ", &tok2);

    //     char *addrsFile = (char*) malloc (strlen(aux) + 1);

    //     strcpy(addrsFile, aux);
    //     aux = strtok_r(NULL, )


    // }

    char *addrs = strtok(arquivo, " \n");
    while(addrs != NULL){
        char *addrsFile = (char*) malloc (strlen(addrs) + 1);

        strcpy(addrsFile, addrs);

        addrs = strtok(NULL, " \n");
        
        char opFile = addrs[0];

        enfileirarAddr(fila, addrsFile, opFile);
    }

    return fila; 

}


    // char *tokPipe;

    // char *comando = strtok_r(entrada, "|", &tokPipe);
    // while(comando != NULL){
    //     int tam = 10;
    //     char **args_parcial = malloc(sizeof(char*) * tam);
    //     if(args_parcial == NULL) exit(EXIT_FAILURE);
    //     int i = 0;

    //     char *token;
    //     char *tokInterno;
    //     token = strtok_r(comando, " \t\n\r", &tokInterno);
    //     while(token != NULL){
    //         if(i >= tam){  // se a quantidade de argumentos superar a quantidade de linhas, realoca a matriz de argumentos
    //             tam *= 2;
    //             args_parcial = realloc(args_parcial, tam * sizeof(char*));
    //             if(args_parcial == NULL) exit(EXIT_FAILURE);
    //         }
    //         args_parcial[i++] = strdup(token);
    //         token = strtok_r(NULL, " \t\n\r", &tokInterno);
    //     }

    //     args_parcial[i] = NULL;
    //     enfileirarArgs(saida, args_parcial);

    //     comando = strtok_r(NULL, "|", &tokPipe);
    // }