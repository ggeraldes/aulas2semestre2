//
// Created by goncalo on 27/03/2023.
//
#include <stdio.h>
#include "retangulo.h"

void pontosRentangulo(retangulo r){
    printf("\nantoSE: {%d, %d}, cantoIE: {%d, %d}, cantoSD: {%d,%d} cantoED: {%d,%d}", r.cantoIE.x, r.cantoIE.y+r.al, r.cantoIE.x, r.cantoIE.y,  r.cantoIE.x+r.lar, r.cantoIE.y+r.al, r.cantoIE.x+r.lar, r.cantoIE.y);
}

void inicializaRetangulo(retangulo *r, int x,int y,int al,int lar){

    r->cantoIE.x=x;
    r->cantoIE.y=y;
    r->al=al;
    r->lar=lar;
}

int areaRetangulo(retangulo r){
    return r.lar*r.al;
}

int verificaDentro(retangulo r, int x, int y){

    if(r.cantoIE.x<=x && x<=r.cantoIE.x+r.lar && r.cantoIE.y<=y && y<=r.cantoIE.y+r.al)
        return 1;
    return 0;
}