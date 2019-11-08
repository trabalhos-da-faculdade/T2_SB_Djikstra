#!/bin/bash

# -------------------------------
# THE COMPILER FROM THIS PROGRAM
# -------------------------------


# Starting the Makefile
make

# Selection from the images
echo ""
echo ""
echo "------------IMAGENS DISPONIVEIS-----------"
echo ""
ls *.png
echo ""
echo "------------------------------------------"
echo ""
echo ""

echo "Selecione a imagem original: [bird ou elephant] : ";
read image1;

echo "Selecione a imagem da mascara: [birdmask ou elephantmask] : ";
read image2;

./seamcarving ${image1}.png ${image2}.png

#./seamcarving bird.png birdmask.png
