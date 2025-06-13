#include "./fila_hash.h"

NO *criaNO() {
    NO *no = (NO*)malloc(sizeof(NO));
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

void destroiNO(NO *no){
    free(no);
}

Fila_hash *criaFilahash(){
    Fila_hash *fila_hash = (Fila_hash*) malloc (sizeof(Fila_hash));
    if(fila_hash != NULL){
        fila_hash->inicio = fila_hash->final = NULL;
        fila_hash->tamanho = 0;
    }
    return fila_hash;
}

void destroiFilahash(Fila_hash *fila_hash) {
    if(fila_hash == NULL) return;
    while(fila_hash->inicio != NULL){
        NO *aux = fila_hash->inicio;
        fila_hash->inicio = fila_hash->inicio->prox;
        destroiNO(aux);
    }
    free(fila_hash);
}

int estaVaziaFilahash(Fila_hash *fila_hash) {
    if(fila_hash == NULL) return 0;
    return fila_hash->tamanho == 0;
}

int enfileirarhash(Fila_hash *fila_hash, int paginaFisica) {
    if(fila_hash == NULL) return 0;
    NO *novo = criaNO();

    novo->paginaFisica = paginaFisica;
    
    if(estaVaziaFilahash(fila_hash)){
        fila_hash->inicio = novo;
    } else {
        novo->ant = fila_hash->final;
        fila_hash->final->prox = novo;
    }   
    fila_hash->final = novo;
    fila_hash->tamanho++;
    return 1;
}

int removerNO(Fila_hash *fila_hash, NO *no) {
    if (fila_hash == NULL || no == NULL) return 0;

    // Se o nó for o primeiro
    if (no == fila_hash->inicio) {
        fila_hash->inicio = no->prox;
        if (fila_hash->inicio != NULL)
            fila_hash->inicio->ant = NULL;
        else
            fila_hash->final = NULL; // Fila ficou vazia
    }
    // Se o nó for o último
    else if (no == fila_hash->final) {
        fila_hash->final = no->ant;
        if (fila_hash->final != NULL)
            fila_hash->final->prox = NULL;
        else
            fila_hash->inicio = NULL; // Fila ficou vazia
    }
    // Se for um nó do meio
    else {
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
    }

    destroiNO(no);
    fila_hash->tamanho--;
    return 1;
}

                // DDDDDEIXAR
int removePaginaFisica(Fila_hash *Fila_hash, int endereço){

    NO *atual = fila_hash->inicio;
    while (atual != NULL) {
        if (atual->paginaVirtual == alvo) {
            removerNO(fila_hash, atual);
            break;
        }
        atual = atual->prox;
    }

}



// void imprimirFila_hash(Fila_hash *fila_hash){
//     if (fila_hash == NULL) return;
//     NO *aux = fila_hash->inicio;
//     int number = 1;
//     while (aux != NULL){
//         printf("%d = %X , %c\n", number, aux->hash, aux->op); number++;
//         aux = aux->prox;
//     }
//     printf("\n");
// }

