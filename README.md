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