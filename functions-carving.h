#ifndef BIBFUNC_H
#define BIBFUNC_H

// -----------------------------------------------
// HEADER WITH THE PROTOTIPES TO MAKE SEAM CARVING
// -----------------------------------------------

void verificaEnergia(int matrixPixels[], int frstColumnList[], int qtdP, int lastColumnList[], int qtdU);
void calcEnergia(int matrixPixels[], int pixel, int rx, int bx, int gx, int ry, int gy, int by);
int primeiros(int pixel,int frstColumnList[], int tamanho);
int ultimos(int pixel, int lastColumnList[], int tamanho);
void seamCarvingVermelho(int matrixPixels[], int frstColumnList[], int tamanhoPrimeiros,int lastColumnList[], int tamanhoUltimos, int linhaEscolhida, int pixelsImportantes[],int count);
int identificaLinha(int pixelsImportantes[], int *count);
void seamCarvingNormal(int matrixPixels[], int frstColumnList[], int tamanhoPrimeiros,int lastColumnList[], int tamanhoUltimos, int larguraRetirada);
void puxaLinha(int pixel, int linha, int imagem);
void pintaVerde(int larguraReduzida);
int escolheCaminhoMenorValorAcumulado(unsigned long int matrizAlgoritmo[], int larguraRetirada);



#endif