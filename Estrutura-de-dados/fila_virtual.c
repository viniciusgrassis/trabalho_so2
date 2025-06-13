#include "./fila_virtual.h"

PaginaVirtual *criaPaginaVirtual() {
    PaginaVirtual *pv = (PaginaVirtual*)malloc(sizeof(PaginaVirtual));
    pv->prox = NULL;
    pv->ant = NULL;
    return pv;
}

void destroiPaginaVirtual(PaginaVirtual *pv){
    free(pv);
}

FilaPagVirtual *criaFilaPagVirtual(){
    FilaPagVirtual *fpv = (FilaPagVirtual*) malloc (sizeof(FilaPagVirtual));
    if(fpv != NULL){
        fpv->inicio = fpv->final = NULL;
        fpv->tamanho = 0;
    }
    return fpv;
}

void destroiFilaPagVirtual(FilaPagVirtual *fpv) {
    if(fpv == NULL) return;
    while(fpv->inicio != NULL){
        PaginaVirtual *aux = fpv->inicio;
        fpv->inicio = fpv->inicio->prox;
        destroiPaginaVirtual(aux);
    }
    free(fpv);
}

int estaVaziaFilaPagVirtual(FilaPagVirtual *fpv) {
    if(fpv == NULL) return 0;
    return fpv->tamanho == 0;
}

int enfileirarFilaPagVirtual(FilaPagVirtual *fpv, int paginaFisica, int paginaVirtual) {
    if(fpv == NULL) return 0;
    PaginaVirtual *novaPV = criaPaginaVirtual();

    novaPV->modficada = 0;
    novaPV->paginaFisica = paginaFisica;
    novaPV->paginaVirtual = paginaVirtual;
    novaPV->referenciada = 1;


        novaPV->ultimoAcesso = 0;  // <------------------------------------------  mudar ultimo acesso com um tempo depois






        
    novaPV->validade = 1;
    
    
    if(estaVaziaFilaPagVirtual(fpv)){
        fpv->inicio = novaPV;
    } else {
        novaPV->ant = fpv->final;
        fpv->final->prox = novaPV;
    }   
    fpv->final = novaPV;
    fpv->tamanho++;
    return 1;
}

int buscarPaginaFisica(FilaPagVirtual *fila, int paginaVirtual) {
    if (fila == NULL) return -1;

    PaginaVirtual *atual = fila->inicio;

    while (atual != NULL) {
        if (atual->paginaVirtual == paginaVirtual) {  // ta joia
            if(atual->validade == 1){
                return atual->paginaFisica;
            }
        }
        atual = atual->prox;
    }

    return -1; 
}


int removerPaginaVirtual(FilaPagVirtual *fpv, PaginaVirtual *pagVirtual) {
    if (fpv == NULL || pagVirtual == NULL) return 0;

    // Se o nó for o primeiro
    if (pagVirtual == fpv->inicio) {
        fpv->inicio = pagVirtual->prox;
        if (fpv->inicio != NULL)
            fpv->inicio->ant = NULL;
        else
            fpv->final = NULL; // Fila ficou vazia
    }
    // Se o nó for o último
    else if (pagVirtual == fpv->final) {
        fpv->final = pagVirtual->ant;
        if (fpv->final != NULL)
            fpv->final->prox = NULL;
        else
            fpv->inicio = NULL; // Fila ficou vazia
    }
    // Se for um nó do meio
    else {
        pagVirtual->ant->prox = pagVirtual->prox;
        pagVirtual->prox->ant = pagVirtual->ant;
    }

    destroiPaginaVirtual(pagVirtual);
    fpv->tamanho--;
    return 1;
}
/*
                // DDDDDEIXAR
int removePaginaFisica(FilaPagVirtual *FilaPagVirtual, int endereço){

    PaginaVirtual *atual = FilaPagVirtual->inicio;
    while (atual != NULL) {
        if (atual->paginaVirtual == alvo) {
            removerPaginaVirtual(FilaPagVirtual, atual);
            break;
        }
        atual = atual->prox;
    }

}
*/



// void imprimirFilaPagVirtual(FilaPagVirtual *fpv){
//     if (fpv == NULL) return;
//     PaginaVirtual *aux = fpv->inicio;
//     int number = 1;
//     while (aux != NULL){
//         printf("%d = %X , %c\n", number, aux->hash, aux->op); number++;
//         aux = aux->prox;
//     }
//     printf("\n");
// }

