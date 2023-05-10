#include <stdio.h>
#include "retangulo.h"
int main() {
    retangulo rt1, rt2;
    rt1.cantoIE.x=0;
    rt1.cantoIE.y=0;
    rt1.lar=2;
    rt1.al=2;

    pontosRentangulo( rt1);

    inicializaRetangulo(&rt2, 1,1,2,2);
    pontosRentangulo( rt2);

    printf("\narea dw rt2: %d cm2",areaRetangulo(rt2));

    printf("\nesta? %d",verificaDentro(rt2, 3, 3));
}
