#include "./relatorio.h"

Relatorio* criaRelatorio(char *substituicao, char* arquivo, int tamanhoPagina, int totalMemoria){
    Relatorio* rl = (Relatorio*) malloc (sizeof(Relatorio));

    rl->acessos = rl->escritas = rl->faltasDePagina = rl->leituras = rl->pagSujas = 0;
    rl->substituicao = substituicao;
    rl->arquivo = arquivo;
    rl->tamanhoPagina = tamanhoPagina;
    rl->totalMemoria = totalMemoria;

    return rl;
}

void destroiRelatorio(Relatorio* rl){
    free(rl);
}

void imprimeRelatorio(Relatorio* rl){
        printf(
        "Arquivo de entrada: %s\n"
        "Tamanho da memoria: %d KB\n"
        "Tamanho das paginas: %d KB\n"
        "Tecnica de reposicao: %s\n"
        "Paginas lidas = %u\n" 
        "Paginas escritas = %u\n"
        "Total de acessos = %u\n"
        "Faltas de paginas = %u\n"
        "Paginas \"sujas\" atualizadas no disco = %u\n",
        rl->arquivo, rl->totalMemoria, rl->tamanhoPagina, rl->substituicao ,rl->leituras, 
        rl->escritas, rl->acessos, rl->faltasDePagina, rl->pagSujas);

}