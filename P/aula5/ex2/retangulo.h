//
// Created by goncalo on 27/03/2023.
//






#ifndef EX2_RETANGULO_H
#define EX2_RETANGULO_H
#include "ponto.h"

typedef struct rectangle retangulo;

struct rectangle{
    ponto2D cantoIE;
    int al, lar;
};

void pontosRentangulo(retangulo r);

void inicializaRetangulo(retangulo *r, int x,int y,int al,int lar);

int areaRetangulo(retangulo r);

int verificaDentro(retangulo r, int x, int y);

#endif //EX2_RETANGULO_H
