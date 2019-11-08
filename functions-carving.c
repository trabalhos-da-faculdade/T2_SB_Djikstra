
// -------------------------
// HEADERS COM OS PROTOTIPOS
// -------------------------

#include "functions-carving.h"

// -------------------
// IMPORTS NECESSARIOS
// -------------------

#include <string.h>  // Para usar strings
#include <limits.h> // colocar limites nos ponteiros de inteiro
#include <math.h>   // para usar calculos Matematicos


// --------------------------------
// DEFININDO AS STRUCTS UTILIZADAS
// -------------------------------

// Um pixel RGB (24 bits)
typedef struct {
    unsigned char r, g, b;
} RGB;

// Uma imagem RGB
typedef struct {
    int width, height;
    RGB* img;
} Img;

// Vetor de Imagens
Img pic[3];


// --------------------------------------------
// VERIFICANDO ENERGIA DE CADA PIXEL NA MATRIZ
// --------------------------------------------

void verificaEnergia(int matrixPixels[], int frstColumnList[], int qtPixels, int lastColumnList[], int qtUnits){
   // qtPixels = Quantidade de Pixels em Inteiros
   // qtdUnits = Quantidade de Unidades para verificar em Inteiros


    int i;
    for(i = 0; i < pic[0].height*pic[0].width; i++){
        
        int comecoPrimeiraLinha = 0;
        int comecoUltimaLinha = pic[0].width*(pic[0].height - 1);
        int rx, gx, bx = 0;
        int ry, gy, by = 0;

        // vermelho(230,200,200), se for Energia = 0
        if((pic[1].img[i].r >= 230) && (pic[1].img[i].g < 200) && (pic[1].img[i].b < 200)){
            calcEnergia(matrixPixels, i, 0, 0, 0, 0, 0, 0);
        }
        // verde(240,200,200), se for Energia = Mais Alta
        else if ((pic[1].img[i].g >= 240) && (pic[1].img[i].b < 200) && (pic[1].img[i].r < 200)){
            calcEnergia(matrixPixels, i, 255, 0, 255, 0, 255, 0);
        }
        else{
        

        if((i >= comecoPrimeiraLinha) & (i < pic[0].width)){

            if(i == 0){ // Primeiro Pixel da Matriz
            
            // Calculo dos valores RGB dos pixels da area X da matriz

            rx = pic[0].img[pic[0].width-1].r - pic[0].img[i+1].r;
            gx = pic[0].img[pic[0].width-1].g - pic[0].img[i+1].g;
            bx = pic[0].img[pic[0].width-1].b - pic[0].img[i+1].b;

            // Calculo dos valores RGB dos pixels da area X da matriz

            ry = pic[0].img[pic[0].width].r - pic[0].img[comecoUltimaLinha].r;
            gy = pic[0].img[pic[0].width].g - pic[0].img[comecoUltimaLinha].g;
            by = pic[0].img[pic[0].width].b - pic[0].img[comecoUltimaLinha].b;

            calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
            }

            // Primeira Linha ultimo pixel
            else if(i == (pic[0].width-1)){

                rx = pic[0].img[i-1].r - pic[0].img[comecoPrimeiraLinha].r;
                gx = pic[0].img[i-1].g - pic[0].img[comecoPrimeiraLinha].g;
                bx = pic[0].img[i-1].b - pic[0].img[comecoPrimeiraLinha].b;

                ry = pic[0].img[pic[0].width+i].r - pic[0].img[comecoUltimaLinha+i].r;
                gy = pic[0].img[pic[0].width+i].g - pic[0].img[comecoUltimaLinha+i].g;
                by = pic[0].img[pic[0].width+i].b - pic[0].img[comecoUltimaLinha+i].b;

                calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
            }
            else{ // Qualquer outro caso

                rx = pic[0].img[i-1].r - pic[0].img[i+1].r;
                gx = pic[0].img[i-1].g - pic[0].img[i+1].g;
                bx = pic[0].img[i-1].b - pic[0].img[i+1].b;

                ry = pic[0].img[pic[0].width+i].r - pic[0].img[comecoUltimaLinha+i].r;
                gy = pic[0].img[pic[0].width+i].g - pic[0].img[comecoUltimaLinha+i].g;
                by = pic[0].img[pic[0].width+i].b - pic[0].img[comecoUltimaLinha+i].b;

                calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
                }
            }

        // If da ultima linha pq varia o pixel de baixo
        else if((i >= comecoUltimaLinha) & (i < (pic[0].width * pic[0].height))){
                // Ultima linha primeiro pixel
                if(i == comecoUltimaLinha){

                    // pixel da esquerda menos direita
                    rx = pic[0].img[pic[0].width * pic[0].height -1].r - pic[0].img[i+1].r;
                    gx = pic[0].img[pic[0].width * pic[0].height -1].g - pic[0].img[i+1].g;
                    bx = pic[0].img[pic[0].width * pic[0].height -1].b - pic[0].img[i+1].b;

                    //// pixel de baixo menos de cima
                    ry = pic[0].img[comecoPrimeiraLinha].r - pic[0].img[i - pic[0].width].r;
                    gy = pic[0].img[comecoPrimeiraLinha].g - pic[0].img[i - pic[0].width].g;
                    by = pic[0].img[comecoPrimeiraLinha].b - pic[0].img[i - pic[0].width].b;

                    calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
                }
                // Ultima linha ultimo pixel
                else if(i == (pic[0].width * pic[0].height -1)){

                    // esquerda menos da direita
                    rx = pic[0].img[i-1].r - pic[0].img[comecoUltimaLinha].r;
                    gx = pic[0].img[i-1].g - pic[0].img[comecoUltimaLinha].g;
                    bx = pic[0].img[i-1].b - pic[0].img[comecoUltimaLinha].b;

                    // baixo menos de cima
                    ry = pic[0].img[pic[0].width -1].r - pic[0].img[i-pic[0].width].r;
                    gy = pic[0].img[pic[0].width -1].g - pic[0].img[i-pic[0].width].g;
                    by = pic[0].img[pic[0].width -1].b - pic[0].img[i-pic[0].width].b;

                    calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
                }
                // Pixels do meio ultima linha
                else{
                    // esquerda menos o da direita
                    rx = pic[0].img[i-1].r - pic[0].img[i+1].r;
                    gx = pic[0].img[i-1].g - pic[0].img[i+1].g;
                    bx = pic[0].img[i-1].b - pic[0].img[i+1].b;

                    // baixo menos o de cima
                    ry = pic[0].img[i - comecoUltimaLinha].r - pic[0].img[i-pic[0].width].r;
                    gy = pic[0].img[i - comecoUltimaLinha].g - pic[0].img[i-pic[0].width].g;
                    by = pic[0].img[i - comecoUltimaLinha].b - pic[0].img[i-pic[0].width].b;

                    calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
                }
        }
        
        else if(primeiros(i, frstColumnList, qtPixels) == 1){
            // se n tiver o pixel embaixo pega o de cima
            if(i == pic[0].width){

                // esquerda menos o da direita
                rx = pic[0].img[i + pic[0].width - 1].r - pic[0].img[i+1].r;
                gx = pic[0].img[i + pic[0].width - 1].g - pic[0].img[i+1].g;
                bx = pic[0].img[i + pic[0].width - 1].b - pic[0].img[i+1].b;

                // baixo menos o de cima
                ry = pic[0].img[i+pic[0].width].r - pic[0].img[i-pic[0].width].r;
                gy = pic[0].img[i+pic[0].width].g - pic[0].img[i-pic[0].width].g;
                by = pic[0].img[i+pic[0].width].b - pic[0].img[i-pic[0].width].b;

                calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
            }
            else{
                // esquerda menos o da direita
                rx = pic[0].img[i + pic[0].width - 1].r - pic[0].img[i+1].r;
                gx = pic[0].img[i + pic[0].width - 1].g - pic[0].img[i+1].g;
                bx = pic[0].img[i + pic[0].width - 1].b - pic[0].img[i+1].b;

                // baixo menos o de cima
                ry = pic[0].img[i+pic[0].width].r - pic[0].img[i-pic[0].width].r;
                gy = pic[0].img[i+pic[0].width].g - pic[0].img[i-pic[0].width].g;
                by = pic[0].img[i+pic[0].width].b - pic[0].img[i-pic[0].width].b;

                calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
            }
        }
        // Pixels da ultima coluna a direita
        else if((ultimos(i, lastColumnList, qtUnits) == 1)){

            // esquerda menos o da direita
            rx = pic[0].img[i-1].r - pic[0].img[i- pic[0].width +1].r;
            gx = pic[0].img[i-1].g - pic[0].img[i- pic[0].width +1].g;
            bx = pic[0].img[i-1].b - pic[0].img[i- pic[0].width +1].b;

            // baixo menos o de cima
            ry = pic[0].img[i+pic[0].width].r - pic[0].img[i-pic[0].width].r;
            gy = pic[0].img[i+pic[0].width].g - pic[0].img[i-pic[0].width].g;
            by = pic[0].img[i+pic[0].width].b - pic[0].img[i-pic[0].width].b;

            calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
        }
        // Pixels do meio da imagem
        else{
            // esquerda menos o da direita
            rx = pic[0].img[i+1].r - pic[0].img[i-1].r;
            gx = pic[0].img[i+1].g - pic[0].img[i-1].g;
            bx = pic[0].img[i+1].b - pic[0].img[i-1].b;

            // baixo menos de cima
            ry = pic[0].img[i+pic[0].width].r - pic[0].img[i-pic[0].width].r;
            gy = pic[0].img[i+pic[0].width].g - pic[0].img[i-pic[0].width].g;
            by = pic[0].img[i+pic[0].width].b - pic[0].img[i-pic[0].width].b;

            calcEnergia(matrixPixels, i, rx, gx, bx, ry, gy, by);
            }
        }
    }
}

// ---------------------------------------------------------
// VERIFICA SE O PIXEL PERTENCE AOS PIXELS DO CANTO ESQUERDO
// ---------------------------------------------------------

int primeiros(int pixel, int frstColumnList[], int tamanho){
    int i = 0;
    for(i = 0; i < tamanho; i++){
        if(frstColumnList[i] == pixel){
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------
// VERIFICA SE O PIXEL PERTENCE AOS PIXELS DO CANTO DIREITO
// ---------------------------------------------------------

int ultimos(int pixel, int lastColumnList[], int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        if(lastColumnList[i] == pixel){
            return 1;
        }
    }
    return 0;
}

// ----------------------------
// CALCULO DA ENERGIA DO PIXEL
// ----------------------------

void calcEnergia(int matrixPixels[], int pixel, int rx, int bx, int gx, int ry, int gy, int by){

    int energia;
    // int posicaoY;

    energia = (pow(rx,2) + pow(gx,2) + pow(bx,2)) + (pow(ry,2) + pow(gy,2) + pow(by,2));
    matrixPixels[pixel] = energia;
}

// ----------------------------------------------------
// VERIFICA E ELIMINA O OBJETO QUE ESTIVER EM VERMELHO
// ----------------------------------------------------

void verificaVermelho(int matrixPixels[], int frstColumnList[], int tamanhoPrimeiros,int lastColumnList[], int tamanhoUltimos, int linhaEscolhida, int pixelsImportantes[],int count){
    int i, j, auxiliar;
    int proximaLinha = pic[0].width;
    int pixelLinhaEscolhida = linhaEscolhida * pic[0].width;

    for(i =0; i<1; i++){
            auxiliar = pixelsImportantes[0] + proximaLinha;
            // Caminho Baixo
            for(j = 0; j < 384-linhaEscolhida; j++){
                if(matrixPixels[auxiliar] < matrixPixels[auxiliar-1] &&
                   matrixPixels[auxiliar] < matrixPixels[auxiliar+1]){
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 0);
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 1);
                    auxiliar = auxiliar + proximaLinha;
                }
                else if(matrixPixels[auxiliar-1] < matrixPixels[auxiliar] &&
                   matrixPixels[auxiliar-1] < matrixPixels[auxiliar+1]){
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 0);
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 1);
                    auxiliar = auxiliar-1 + proximaLinha;
                }
                else{
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 0);
                    puxaLinha(auxiliar, linhaEscolhida+(j+1), 1);
                    auxiliar = auxiliar+1 + proximaLinha;
                }
            }

            puxaLinha(pixelsImportantes[0], linhaEscolhida, 0);
            puxaLinha(pixelsImportantes[0], linhaEscolhida, 1);
            auxiliar = pixelsImportantes[0] - proximaLinha;
            // Caminho Cima
            for(j = linhaEscolhida-1; j > 0; j--){
                if(matrixPixels[auxiliar] < matrixPixels[auxiliar-1] &&
                   matrixPixels[auxiliar] < matrixPixels[auxiliar+1]){
                    puxaLinha(auxiliar, j, 0);
                    puxaLinha(auxiliar, j, 1);
                    auxiliar = auxiliar - proximaLinha;
                }
                else if(matrixPixels[auxiliar-1] < matrixPixels[auxiliar] &&
                   matrixPixels[auxiliar-1] < matrixPixels[auxiliar+1]){
                    puxaLinha(auxiliar, j, 0);
                    puxaLinha(auxiliar, j, 1);
                    auxiliar = auxiliar-1 - proximaLinha;
                }
                else{
                    puxaLinha(auxiliar, j, 0);
                    puxaLinha(auxiliar, j, 1);
                    auxiliar = auxiliar+1 - proximaLinha;
                }
            }
        verificaEnergia(matrixPixels, frstColumnList, tamanhoPrimeiros, lastColumnList, tamanhoUltimos);
    }
}

// -----------------------------------------------------------
// VERIFICA E APRESENTA AS LINHAS QUE CONTEM PIXELS VERMELHOS
// -----------------------------------------------------------

int identificaLinha(int pixelsImportantes[], int *count){
    int linhaEscolhida, countLinha = 0;
    int i, j;
    int contadorVerm = 0;
    int menorQtd = INT_MAX;

    for(i =0; i < pic[0].height*pic[0].width; i = (i+pic[0].width)){

        for(j = i; j < i+pic[0].width; j++){
            if(pic[1].img[j].r >= 230 && pic[1].img[j].g <= 50 && pic[1].img[j].b <= 50){
                contadorVerm++;

                pic[0].img[j].r = 255;
                pic[0].img[j].g = 0;
                pic[0].img[j].b = 0;
            }
        }

        if(contadorVerm > menorQtd){
            menorQtd = contadorVerm;
            linhaEscolhida = countLinha;
            contadorVerm = 0;
        }
        else{
            contadorVerm = 0;
        }
        countLinha++;
    }

    int inicioLinha = linhaEscolhida*pic[0].width;
    *count = 0;
    for(i = inicioLinha; i< inicioLinha+512; i++){
        if(pic[1].img[i].r >= 230 && pic[1].img[i].g <= 50 && pic[1].img[i].b <= 50){
            pixelsImportantes[*count] = i;
            *count = *count+1;
        }
    }
    return linhaEscolhida;
}

// ---------------------------------------------------------
// FUNCAO PRINCIPAL DE SEAM CARMING PARA VERIFICAR A IMAGEM
// ---------------------------------------------------------

void seamCarming(int matrixPixels[], int frstColumnList[], int tamanhoPrimeiros,
                             int lastColumnList[], int tamanhoUltimos, int larguraRetirada){
    int i, j, auxiliar;
    unsigned long int matrizAlgoritmo[pic[0].width-larguraRetirada]; 
    unsigned long int valorAcumulado; 
    unsigned int caminhoSeam[pic[0].width][pic[0].height]; 
    int proximaLinha = pic[0].width;
    

    verificaEnergia(matrixPixels, frstColumnList, tamanhoPrimeiros, lastColumnList, tamanhoUltimos);

    for(i = 0; i < (pic[0].width - larguraRetirada); i++){
        valorAcumulado = 0;
        auxiliar = i; // para verificar o pixel
        for(j = 0; j < pic[0].height; j++){
            if(primeiros(auxiliar, frstColumnList, tamanhoPrimeiros) == 1 || auxiliar == 0){
                // Pega o primeiro valor e e proximo
                if(auxiliar == i){
                    valorAcumulado = matrixPixels[auxiliar];
                    caminhoSeam[i][j] = auxiliar;
                    j++;
                    if(matrixPixels[auxiliar + proximaLinha] < matrixPixels[auxiliar + proximaLinha+1]){
                        valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha];
                        auxiliar = auxiliar + proximaLinha;
                        caminhoSeam[i][j]= auxiliar;
                    }
                    else{
                        valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha+1];
                        auxiliar = auxiliar + proximaLinha +1;
                        caminhoSeam[i][j]= auxiliar;
                        }
                    }

                    // O restante dos pixels do canto esquerdo.
                    else{
                        if(matrixPixels[auxiliar+proximaLinha] < matrixPixels[auxiliar+proximaLinha+1]){
                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar+proximaLinha];
                            auxiliar = auxiliar + proximaLinha;
                            caminhoSeam[i][j] = auxiliar;
                        }
                        else{
                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha+1];
                            auxiliar = auxiliar + proximaLinha +1;
                            caminhoSeam[i][j]= auxiliar;
                        }
                    }
                }
                

                else if(ultimos(auxiliar, lastColumnList, tamanhoUltimos) == 1){

                    // Pega o primeiro e o seguinte pixel
                    if(auxiliar == i){
                            valorAcumulado = matrixPixels[auxiliar];
                            caminhoSeam[i][j] = auxiliar;
                            j++;
                            if(matrixPixels[auxiliar + proximaLinha] < matrixPixels[auxiliar + proximaLinha-1]){
                                valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha];
                                auxiliar = auxiliar + proximaLinha;
                                caminhoSeam[i][j]= auxiliar;
                            }
                            else{
                                valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha-1];
                                auxiliar = auxiliar + proximaLinha -1;
                                caminhoSeam[i][j]= auxiliar;
                            }
                        }

                        // O restante dos pixels do canto direito
                        else{
                           if(matrixPixels[auxiliar + proximaLinha] < matrixPixels[auxiliar + proximaLinha-1]){
                                valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha];
                                auxiliar = auxiliar + proximaLinha;
                                caminhoSeam[i][j]= auxiliar;
                            }
                            else{
                                valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha-1];
                                auxiliar = auxiliar + proximaLinha -1;
                                caminhoSeam[i][j]= auxiliar;
                            }
                        }
                }
                
                else{

                    // Pega o primeiro pixel e o seguinte
                    if(auxiliar == i){
                        valorAcumulado = matrixPixels[auxiliar];
                        caminhoSeam[i][j] = auxiliar;
                         j++;
                        if(matrixPixels[auxiliar + proximaLinha] < matrixPixels[auxiliar + proximaLinha+1]){
                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha];
                            auxiliar = auxiliar + proximaLinha;
                            caminhoSeam[i][j]= auxiliar;
                        }
                        else{
                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha+1];
                            auxiliar = auxiliar + proximaLinha +1;
                            caminhoSeam[i][j]= auxiliar;
                           }
                    }
                    
                    else{
                        if(matrixPixels[auxiliar+proximaLinha] < matrixPixels[auxiliar+proximaLinha+1] &&
                            matrixPixels[auxiliar+proximaLinha] < matrixPixels[auxiliar+proximaLinha-1]){

                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha];
                            auxiliar = auxiliar + proximaLinha;
                            caminhoSeam[i][j]= auxiliar;
                        }
                        else if(matrixPixels[auxiliar+proximaLinha+1] < matrixPixels[auxiliar+proximaLinha] &&
                            matrixPixels[auxiliar+proximaLinha+1] < matrixPixels[auxiliar+proximaLinha-1]){

                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha+1];
                            auxiliar = auxiliar + proximaLinha +1;
                            caminhoSeam[i][j]= auxiliar;
                        }
                        else{
                            valorAcumulado = valorAcumulado + matrixPixels[auxiliar + proximaLinha-1];
                            auxiliar = auxiliar + proximaLinha -1;
                            caminhoSeam[i][j]= auxiliar;
                        }
                    }
                }
            matrizAlgoritmo[i] = valorAcumulado;
        }
    }
    int pixelEscolhido = escolheCaminhoMenorValorAcumulado(matrizAlgoritmo, larguraRetirada);

    for(i = 0; i < pic[0].height; i++){
        puxaLinha(caminhoSeam[pixelEscolhido][i], i, 0);
    }
}

// -------------------------------------------------------------
// PINTA A IMAGEM COM AS CORES DO PIXEL DO LADO POR TODA A LINHA
// -------------------------------------------------------------

void puxaLinha(int pixel, int linha, int imagem){
    int i;

    if(linha == 0){
        for(i = pixel; i< pic[imagem].width-1; i++){
            pic[imagem].img[i].r = pic[imagem].img[i+1].r;
            pic[imagem].img[i].g = pic[imagem].img[i+1].g;
            pic[imagem].img[i].b = pic[imagem].img[i+1].b;

        }
    }
    else{
        for(i = pixel; i< pic[imagem].width*(linha+1)-1; i++){
            pic[imagem].img[i].r = pic[imagem].img[i+1].r;
            pic[imagem].img[i].g = pic[imagem].img[i+1].g;
            pic[imagem].img[i].b = pic[imagem].img[i+1].b;
        }
    }
}

// -----------------------------------------------------
// PINTANDO DE VERDE AS COLUNAS QUE POSSUEM A MESMA COR
// -----------------------------------------------------

void pintaVerde(int larguraReduzida){
    int i,j;
    for(j = (pic[0].width - larguraReduzida); j < pic[0].width*pic[0].height; j = j+pic[0].width){
        for(i = 0; i<larguraReduzida; i++){
            pic[0].img[j+i].r = 0;
            pic[0].img[j+i].g = 255;
            pic[0].img[j+i].b = 0;
        }
    }
}

// ------------------------------------
// CAMINHO COM O MENOR VALOR ACUMULADO
// ------------------------------------

int escolheCaminhoMenorValorAcumulado(unsigned long int matrizAlgoritmo[], int larguraRetirada){
    int i;
    int posicao;
    unsigned long int menorValor = -INT_MAX;

    for(i = 0; i < pic[0].width-larguraRetirada;i++){
        if(matrizAlgoritmo[i] < menorValor){
            menorValor = matrizAlgoritmo[i];
            posicao = i;
        }
    }
    return posicao;
}