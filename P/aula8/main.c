#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4
//ex11g3
typedef struct concorrente no, *pno;

struct concorrente{
    char nome[200];		/* nome do concorrente */
    int id;				/* n.� de aluno: identificador �nico */
    float analise;		/* n�vel de �lcool no sangue */
    pno prox;
};


// Funcao para criar a estrutura dinamica com base na informacao do ficheiro de texto
void cria_listas(pno tab[], char *n1)
{
    FILE *f;
    pno novo;
    int i, x, y;

    f = fopen(n1, "r");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
    while(fscanf(f, " %d %d", &x, &y) == 2)
    {
        for(i=0; i<y; i++)
        {
            novo = malloc(sizeof(no));
            if(novo == NULL)
            {
                printf("Erro na alocacao de memoria\n");
                fclose(f);
                return;
            }
            fscanf(f, " %d %f %[^\n]", &novo->id, &novo->analise, novo->nome);
            novo->prox = tab[x];
            tab[x] = novo;
        }
    }
    fclose(f);
}

void classificacao(pno tab[]){
    pno temp;

    for(int i=0; i<N;i++) {
        temp = tab[i];
        while (temp != NULL){
            printf("nome: %s, id:%d, analise: %f\n", temp->nome, temp->id, temp->analise);
            temp=temp->prox;
        }
        printf("\n");
    }
}
bool procura(int id, pno lista){
    pno p=lista;

    while(p!=NULL){
        if(p->id==id) return true;
        p=p->prox;
    }
    return false;

}
pno insere_fim(pno lista, pno novo){
    pno tmp=lista;
    novo->prox=NULL;
    if(tmp==NULL) return novo;
    while(tmp->prox != NULL) tmp=tmp->prox;

    tmp->prox=novo;
    return lista;
}
void participouTodas(pno tab[]){
   pno Lista = NULL;
   pno base = tab[0];

   while(base != NULL){
       bool encontrou=true;

       for(int i=1; i<N && encontrou; i++)
        encontrou=procura(base->id,tab[i]);
       if(encontrou){
           pno novo=(pno)malloc(sizeof(no));
           *novo = *base; //copia todo o conteudo

           //altera o valor da analise
           novo->analise=0.0;
           Lista = insere_fim(Lista, novo);
       }
       base= base->prox;
   }
    while(Lista !=NULL){
        printf("nome: %s, id:%d, analise: %f\n", Lista->nome, Lista->id, Lista->analise);
        Lista=Lista->prox;
    }

}

int main()
{
    // Declaracao do array de ponteiros
    pno tab[N] = {NULL};


    // Criar ED
    cria_listas(tab, "dados_11.txt");

   //a
    printf("\na:\n");
   classificacao(tab);

   //b
    printf("\nb:\n");
   participouTodas(tab);

    return 0;
}
