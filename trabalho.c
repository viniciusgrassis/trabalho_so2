#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned int pagina_virtual;
    int validade;
    int modificada;
    int referenciada;
    unsigned int ultimo_acessos;
}QuadroMemoria;

QuadroMemoria* criarQuadro(unsigned int pagina_virtual){
    QuadroMemoria* quadro = (QuadroMemoria*)malloc(sizeof(QuadroMemoria));
    if (quadro == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o quadro.\n");
        exit(EXIT_FAILURE);
    }

    quadro->pagina_virtual = pagina_virtual;
    quadro->validade = 1; // Inicialmente válido
    quadro->modificada = 0; // Inicialmente não modificada
    quadro->referenciada = 0; // Inicialmente não referenciada
    quadro->ultimo_acessos = 0; // Inicialmente sem acessos

    return quadro;
}

void liberarQuadro(QuadroMemoria* quadro){
    if (quadro != NULL) {
        free(quadro);
    }
}