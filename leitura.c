#include <stdio.h>
#include <stdlib.h>

int contarLinhas(char *arquivo){
    FILE *arquivo = fopen(arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return -1;
    }

    int linhas = 0;
    int ch;

    while((ch = fgetc(arquivo)) != EOF){
        if (ch == '\n') {
            linhas++;
        }
    }

    fclose(arquivo);
    return linhas;
}

int hex_int(const char *hex){
    return (int)strtol(hex, NULL, 16);
}

int leituraArquivo(char *arquivo){
    int linhas = contarLinhas(arquivo);

    FILE *arquivo = fopen(arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return -1;
    }

    int *dados = (int*) malloc (sizeof(int) * linhas);

    // char *token = strtok(arquivo, " ");
    // for(int i = 0; i < linhas; i++){
    //     dados[0] = 

    // }


}