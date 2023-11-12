format long
IMAGE = imread("test/original.pgm");
IMAGEMULT = IMAGE.*0.33;
IMGNOSSA = imread("bri.pgm");

imwrite(IMAGE,"briMATLAB.pgm");

IMAGE2 = imread("test/bri.pgm");
comp = sum(sum(IMAGE2==IMAGEMULT))
compNOSSA = sum(sum(IMAGE2==IMGNOSSA))