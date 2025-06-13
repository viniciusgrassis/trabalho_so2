#include "./leitura.h"


Fila_addrs* leituraArquivo(char *path){
    FILE *arquivo = fopen(path, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    Fila_addrs *fila = criaFilaAddrs();
    char linha[20]; // 8 hexa, 1 espaço, um char e \n

    while(fgets(linha, sizeof(linha), arquivo) != NULL){

        char *token = strtok(linha, " ");
        while(token != NULL){

            char *addrssFile = (char*) malloc(strlen(token) + 1);
            if(addrssFile == NULL){
                fclose(arquivo);
                return NULL;
            }

            strcpy(addrssFile, token);

            token = strtok(NULL, " ");
            char opFile = token[0];

            enfileirarAddrs(fila, hex_int(addrssFile), opFile);

            token = strtok(NULL, " ");
        }
    }

    fclose(arquivo);
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