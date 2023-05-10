#include <stdio.h>
//guião 1


void rotacao_direta(float *a, float *b, float *c){
    float temp=*a;
    *a=*b;
    *b=*c;
    *c=temp;
}

void rotacao_esquerda(float *a, float *b, float *c){
    float temp=*c;
    *c=*b;
    *b=*a;
    *a=temp;
}

void f4(int *t, int tam, int *np, int *ni, int *maior, int *pos){

   for(int i=0;i<tam;i++){
        if(*(t+i)>*maior){
         *maior=*(t+i);
         *pos=i;
        }
        if (*(t+i) % 2 == 0)
            *np+=1;
        else
            *ni+=1;
    }

}

void procura_dupla(int *tab, int tam, int *prim, int *seg){

    *prim = 0;
    *seg = 0;
    for(int i=0;i<tam;i++){
        if(*(tab+i)>*prim){
            *seg=*prim;
            *prim=*(tab+i);
        }
        else if(*(tab+i)>*seg)
            *seg=*(tab+i);
    }
}

int maior_subida(int *tab, int dim){

    int maior=0, pos;
    for(int i=1;i<dim;i++)
        if(*(tab+i)-*(tab+i-1)>maior){
            maior=*(tab+i)-*(tab+i-1);
            pos=i;
        }

    return  pos;

}

int main1(){
    int a, b, total, *p = &a, *q = &b, *r = &total;

    printf("\nIndique a");
    scanf("%d", p);

    printf("\nIndique b");
    scanf("%d", q);
    *r=*p+*q;

    printf("a= %d \t b= %d \t total= %d\n", a, b, total);
    return 0;
}

int main2(){
    float a, b, c;

    printf("\nIndique a: ");
    scanf("%f", &a);

    printf("\nIndique b: ");
    scanf("%f", &b);

    printf("\nIndique c: ");
    scanf("%f", &c);

    rotacao_direta(&a, &b, &c);
    printf("\nrotacao a direta: %f, %f, %f",a,b,c);

    rotacao_esquerda(&a, &b, &c);
    printf("\nrotacao a esquerda: %f, %f, %f",a,b,c);
    return 0;
}

int main4(){
    int a[]={1,3,7,5,2,10,9,7,7,1};
    int impares=0, pares=0, m=0, posM=0;

    f4(&a[0], 9, &pares, &impares, &m, &posM);
    printf("Existem %d numeros pares, %d numeros impares. O maior numero e o %d e esta na posicao %d.",pares,impares,m,posM);
    return 0;
}

int main7(){
    int a[]={-1,23,7,5,2,11,9,27,10,19};
    int maior, maior2;

    procura_dupla(&a[0], 9, &maior, &maior2);
    printf("Maior: %d, Maior2: %d",maior, maior2);
    return 0;
}

int main8(){
    int a[]={-1,23,7,5,2,11,9,27,10,19};
    int maior;

    printf("Maior subida posicao: %d -> %d",maior_subida(&a[0], 9)-1, maior_subida(&a[0], 9));
    return 0;
}
