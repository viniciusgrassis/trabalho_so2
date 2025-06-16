# Compilação e Execução
## Para compilar o programa, utilize o comando:
```
make build
```

Isso gerará um executável chamado tp2virutal.

## Para executá-lo, são necessários cinco argumentos:

- 1. Tipo do método de substituição de página (lru, nru ou segunda_chance)
- 2. Caminho do arquivo contendo a sequência de endereços
- 3. Tamanho de página (em KB)
- 4. Tamanho da memória física (em KB)
- 5. Ativação do modo debug (qualquer caractere ativa)

Exemplo de execução:
```
./tp2virutal lru compilador.log 4 128 debug
```