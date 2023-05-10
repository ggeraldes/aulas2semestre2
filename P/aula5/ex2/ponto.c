//
// Created by goncalo on 27/03/2023.
//


#include <stdio.h>
#include "ponto.h"

// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D* p){
    printf("\nEscreva x: ");
    scanf("%d", &p->x);
    printf("\nEscreva y: ");
    scanf("%d", &p->y);

}

// alinea d)
void movePonto(ponto2D* p, int dx, int dy){
    p->x+=dx;
    p->y+=dy;
}

// alinea e)

int pertencePonto(ponto2D p1, ponto2D p2, ponto2D p3){
    float m = (float) (p2.y-p1.y)/(p2.x-p1.x);

    float b= (float) p1.y - m*p1.x;

    printf("\nReta -> Y = %4.2f X + %4.2f \n", m, b);

    if((p3.y)==(m*p3.x+b)) return 1;
    else return 0;


}
