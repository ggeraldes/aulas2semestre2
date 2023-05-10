
#include <stdio.h>
#include <string.h>

#define L1	3
#define C1	2

#define L2	4
#define C2	3

#define M 8

#define N 5

typedef struct {
    char nomePt[20];
    char nomeIn[20];
}Meses;

void escreve(int n_lin, int n_col, int mat[n_lin][n_col])
{
    for(int i=0; i<n_lin; i++){
        for(int j=0; j<n_col; j++)
            printf("%d  ", mat[i][j]);
        printf("\n");
    }

}

float calculaMin(int n_lin, int n_col, float mat[n_lin][n_col]){

    float min=0, soma=0;
    for(int i=0; i<n_lin; i++){
        for(int j=0; j<n_col; j++)
            soma+=mat[i][j];
        if(soma/n_col<min || i==0)
            min=soma/n_col;
        soma=0;
    }
    return min;

}
float calculaMax(int n_lin, int n_col, float mat[n_lin][n_col]){

    float max=0, soma=0;
    for(int i=0; i<n_lin; i++){
        for(int j=0; j<n_col; j++)
            soma+=mat[i][j];
        if(soma/n_col>max)
            max=soma/n_col;
        soma=0;
    }
    return max;
}

void escreveIngles(Meses mes[12]){
    char m[20];

    printf("Escreva o mes mes: ");
    scanf("%s", &m);

    for(int i=0;i<12;i++)
        if(strcmp(m, mes[i].nomePt)==0){
            printf("\n%s", mes[i].nomeIn);
            return;
        }

    printf("Mal escrito!");
}

void escreve_sin(char *sin[][2], int tot_lin)
{
    for(int i=0;i<tot_lin;i++)
        printf("%s e sinonimo de %s\n",sin[i][0], sin[i][1]);

}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{
    for(int i=0;i<tot_lin;i++)
        if(strcmp(p, sin[i][0])==0)
            return sin[i][1];
        else if(strcmp(p, sin[i][1])==0)
            return sin[i][0];
    return NULL;

}

char *pesquisa_frase(char *sin[][2], int tot_lin, char *p)
{
    char palavra[20];
    int space=0;
    for(int i=0;i<tot_lin;i++) {
        for (int y = 0, j = space; p[j] != '\0'; j++, y++) {
            if (p[j] == ' ')
                break;
            palavra[y] = p[j];
        }
        printf("palavra: %s\n", palavra);
        if (strcmp(palavra, sin[i][0]) == 0)
            return sin[i][1];
        else if (strcmp(palavra, sin[i][1]) == 0)
            return sin[i][0];
        palavra[0]='\0';
        space+=1;
    }
    return NULL;

}



int main14()
{

    int mat1[L1][C1] = {{1,2}, {3,4}, {5,6}};

    int mat2[L2][C2] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};


    printf("Matriz 1:\n");
    escreve(L1, C1, &mat1[0][0]);

    printf("Matriz 2:\n");
    escreve(L2, C2,&mat2[0][0]);

    return 0;
}

int main18() {
    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};
    float min1=0, max1=0, min2=0, max2=0;

    min1= calculaMin(3,2,&m1[0][0]);
    min2= calculaMin(2,6,&m2[0][0]);
    max1= calculaMax(3,2,&m1[0][0]);
    max2= calculaMax(2,6,&m2[0][0]);

    printf("Matriz m1: (%.2f, %.2f)\n", min1, max1);
    printf("Matriz m2: (%.2f, %.2f)\n", min2, max2);
    return 0;
}

int main20(){
    Meses meses[12]={"Janeiro", "January",
                     "Fevereiro","February",
                     "Marco", "March",
                     "Abril","April",
                     "Maio", "May",
                     "Junho", "June",
                     "Julho","July",
                     "Agosto","August",
                     "Setembro", "September",
                     "Outubro", "October",
                     "Novembro", "November",
                     "Dezembro", "December"};

    escreveIngles(&meses[0]);

    return 0;

}

int main()
{
    char palavra[50], *p;

    char *s[N][2] = {{"estranho", "bizarro"},
                     {"desconfiar", "suspeitar"},
                     {"vermelho", "encarnado"},
                     {"duvidar", "desconfiar"},
                     {"carro", "automovel"}};


    escreve_sin(s, N);		// alinea 22.1

    printf("Palavra a pesquisar: ");
    fgets (palavra, 50, stdin);
    palavra[strlen(palavra)-1]='\0';

    p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2

    if(p == NULL)
        printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
    else
        printf("A palavra %s e sinonimo de %s\n", p, palavra);

    palavra[0]='\0';
    printf("Frase a pesquisar: ");
    fgets (palavra, 50, stdin);
    p = pesquisa_frase(s, N, palavra);

    if(p == NULL)
        printf("Frase nao tem palavras que constem, %s\n", palavra);
    else
        printf("Na frase %s ha um sinonimo de %s\n", palavra, p);


    return 0;
}


