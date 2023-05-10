//
// Created by goncalo on 27/03/2023.
//

#ifndef G2_PONTO_H
#define G2_PONTO_H

// alinea a)
typedef struct ponto ponto2D;
struct ponto{
    int x, y;
};

void printPonto(ponto2D a);

void initPonto(ponto2D* p);

void movePonto(ponto2D* p, int dx, int dy);

int pertencePonto(ponto2D p1, ponto2D p2, ponto2D p3);

#endif //G2_PONTO_H
