#!/bin/bash

# -------------------------------
# THE COMPILER FROM THIS PROGRAM
# -------------------------------


# Starting the Makefile
make

# Selection from the images
ls *.png

echo "Selecione a imagem original: [bird ou elephantmask] : ";
read image1;

echo "Selecione a imagem da mascara: [birdmask ou elephantmask] : ";
read image2;

./seamcarving ${image1}.png ${image2}.png
