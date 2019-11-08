# Trabalho 2 de Software Basico

* Este trabalho envolve pegar uma imagem e passar nela o algoritmo do Seam-Carving, que serve para poder retirar os espacos desnecessarios de uma Imagem

## Como compilar pelo terminal

* Usamos o comando `make` para compilar o arquivo **Makefile** dentro deste Repositorio
* Depois rodamos o script `seamcarving` que e o executavel com as duas imagens desejadas
* Exemplo:

```shell
# run Makefile
make

# Run test (one of the examples)
./seamcarving bird.png birdmask.png
```

* Pode usar o Script `compile.sh` que faz esses comandos

## Como zerar para outros testes

* Para reiniciar os testes depois de modificacoes, precisa apagar os arquivos criados pelo Makefile

```shell
# Erase all changes
make clean
```

* Pode usar o Script `clear.sh` para fazer esse comando

## Como foi feito neste trabalho

1. Utilizei o Code:Blocks para compilar todas as partes, devido as novas headers e functions
2. Criei um Header chamado `functions-carving.h` que possui os prototipos das funcoes do seam carming
3. Criei um Arquivo C para colocar todas as Structs e Funcoes necessarios que criei para a Main
4. Main continuar sendo o principal arquivo C do projeto
