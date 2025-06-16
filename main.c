#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "./estrutura-de-dados/tabela_inversa.h"
#include "./memoria-handler/memoria.h"
#include "./relatorio.h"


int main(int argc, char *argv[]){
    char *substituicao = argv[1];
    char *arquivo_endereco  = argv[2];
    int tamanhoPagina = atoi(argv[3]);
    int totalMemoria = atoi(argv[4]);
    char *d = argv[5];
    int debug = (argc > 5) ? 1 : 0;

    int temp = pow(2, log2(tamanhoPagina)) * pow(2, 10); // calcula o tamanho das páginas em KB
    int shift = log2(temp); // quantidade de bits que devem ser descartados para identificar a página

    int quantidadePaginas = totalMemoria / tamanhoPagina;
    TabelaInversa* tabela = criaTabela(quantidadePaginas);

    Relatorio* rl = criaRelatorio(substituicao, arquivo_endereco, tamanhoPagina, totalMemoria);
        
    unsigned int addr;
    char rw;
    FILE *f = fopen(arquivo_endereco, "r");

    while(fscanf(f, "%x %c", &addr, &rw) != EOF) {
        // printf("%u, %c\n", addr, rw); 
        if(rw == 'R') rl->leituras++;
        if(rw == 'W') rl->escritas++;
        if(rw == 'R' || rw == 'W') {
            rl->acessos++;
        } else {
            continue;
        }
        // paginaVirtual = addr >> shift;
        rl->faltasDePagina += acessoMemoria(tabela, addr, shift, rw, rl, debug);

    }

    imprimeRelatorio(rl);
    
}
