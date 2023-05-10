
#include <stdio.h>

#include "ponto.h"


//------------------------------- ex1


int main(int argc, char** argv) {

    ponto2D p1 = {1,3}, p2, p3={2,4};

    printf("p2: ");
    initPonto(&p2);

    printf("p1: ");
    printPonto(p1);

    printf("p2: ");
    printPonto(p2);

    printf("move p1: ");
    movePonto(&p1, 3, -2);

    printf("p1: ");
    printPonto(p1);

    printf("pertence a p1: %d", pertencePonto(p1,p2,p3) );

    return 0;
}


