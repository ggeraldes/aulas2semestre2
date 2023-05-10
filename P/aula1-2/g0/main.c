#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <string.h>
#define TAM 12

int maior(int v[], int t){
    int maior=0;
    for(int i =0; i< t; i++){
        if(v[i]>maior)
            maior=v[i];
    }
    return maior;
}
void maior2(int v[], int t){
    int maior=0, pos=0;
    for(int i =0; i< t; i++){
        if(v[i]>maior) {
            maior = v[i];
            pos = i;
        }
    }
    printf("MAX: %d, POS: %d", maior, pos);
}
void maior3(int v[], int t){
    int maior=0, contador;
    for(int i =0; i< t; i++){
        if(v[i]==maior)
            contador++;
        else{
            if(v[i]>maior) {
                maior = v[i];
                contador = 1;
            }
        }

    }
    printf("MAX: %d, POS: %d", maior, contador);
}
int maior4(int v[], int t){
    int maior=0, contador=0, contadorM=0;
    for(int i =0; i< t; i++){
        for(int y =0; y< t; y++) {
            if(v[i]==v[y])
                contador++;
        }
        if (contador>contadorM){
            maior=v[i];
            contadorM=contador;
        }
        else if(contador==contadorM && maior<v[i])
            maior=v[i];

        contador=0;

    }
    return maior;
}
int encontra(int v[], int t, int valor){
    int a=0;
    for(int i =0; i< t; i++){
        if(v[i]==valor) {
            a = 1;
            break;
        }
    }
    return a;
}
void soma(int v[], int t, int valor){
    for(int i =0; i< t; i++) {
        for (int y = i; y < t; y++) {
            for (int j = y; j < t; j++) {
                if(j!=i && i!=y && y!=j){
                    if(v[j]+v[y]+v[i]==valor)
                        printf("[%d %d %d]  ", v[i], v[j], v[y]);
                }
            }
        }
    }
}
double CalcularDesvioPadrao(double array[], int tam)
{
    // Calcular a média
    double media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += array[i];
    }
    media = media / tam;

    // Calcular o somatorio
    double somatorio = 0;

    for (int i = 0; i < tam; i++)
    {
        somatorio += pow(media - array[i], 2);
    }

    // Calcular e devolver o valor do desvio padrão à função main
    double desvioP = sqrt((1/((double)tam)) * somatorio);

    return desvioP;
}

void ler_matriz(int mat[][3], int m){
    for(int i=0;i<m;i++) {
        int sim=0;
        int valor=0;
        do{
            sim=0;
            valor=0;
            printf("valor[%d %d] ->", i + 1, 1);
            scanf("%d", &valor);

            for(int j=i;j>=0;j--){
                if(mat[j][1]==valor)
                    sim=1;
            }
        }while(sim!=0);

        mat[i][0]=valor;
        mat[i][1]=valor*valor;
        mat[i][2]=valor*valor*valor;
    }

    printf("\n");
}
void mostrar_matriz(int mat[][3], int m){
    for(int i=0;i<m;i++){
        for(int j=0;j < 3; j++){

            printf("[%d] ", mat[i][j]);
        }
        printf("\n");
    }

}

void quebra(char str[50]){
    int i=0;
    while(str[i]!='\0'){

        if (str[i] == ' '){
            printf("\n");
            while(str[i+1]==' '){
                i++;
            }
        }else
            printf("%c", str[i]);

        i++;
    }

}

void comparaStr(char str1[50], char str2[50], char str3[50]){
    if(strcmp(str1,str2)==0)
        strcpy(str3, "FRASES IGUAIS!!");
    else if(strlen(str1)==strlen(str2))
        strcpy(str3, "MESMO TAMANHO!!");
    else
        sprintf(str3, "%s %s", str1, str2);

    printf("\n%s", str3);
}

void main1() {
    int vect[] = {4,2,7,7,3,4,14,8,12,14,7,5};
    for (int i=0;i<TAM; i++) printf("%d ", vect[i]);
    printf("\n MAX = %d\n", maior(vect, TAM));
}

void main2() {
    int vect[] = {4,2,7,7,3,4,14,8,12,14,7,5};
    maior2(vect, TAM);
}

void main3() {
    int vect[] = {4,2,7,7,3,4,14,8,12,14,7,5};
    maior3(vect, TAM);
}

void main4() {
    int vect[] = {4,2,7,7,3,4,14,8,12,14,7,5};
    printf("\n MAX = %d\n", maior4(vect, TAM));
}

void main5() {
    int v;
    int vect[] = {1,2,3,4,5,6,7,8,8,10,11,12};
    printf("Digite o valor: ");
    scanf("%d", &v);
    printf("\n encontrou = %d\n", encontra(vect, TAM, v));
}

void main6() {
    int v;
    int vect[] = {1,2,3,4,5,6,7,8,8,10,11,12};
    printf("Digite o valor: ");
    scanf("%d", &v);
    soma(vect, TAM, v);
}

void main7() {
    double array[] = {1.1, 2.5, 3.7};

    double desvioPadrao = CalcularDesvioPadrao(array, TAM);

    printf("Desvio padrao: %f", desvioPadrao);
}

void main8_9() {
    int array[3][3];

    ler_matriz(array,3);
    mostrar_matriz(array,3);
}

void main12() {
    char str[50];

    printf("Escreva a frase:");
    fgets(str, sizeof(str), stdin);
    quebra(str);
}

void main() {
    char str1[50], str2[50], str3[50];

    printf("Escreva a frase1:");
    fgets(str1, sizeof(str1), stdin);
    printf("Escreva a frase2:");
    fgets(str2, sizeof(str2), stdin);
    comparaStr(str1, str2, str3);

}
