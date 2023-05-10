//
// Created by goncalo on 24/04/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Pessoa.h"

int lista_vazia(pno p)
{
    if(p == NULL)
        return 1;
    else
        return 0;
}

void mostra_info(pno p)
{
    while(p != NULL)
    {
        printf("%s\t%d\t%f\t%f\n",
               p->nome, p->id, p->peso, p->altura);
        p = p->prox;
    }
}

pno insere_inicio(pno p){
    pno novo;
    novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }

    if((novo = malloc(sizeof(no))) == NULL)
        printf("Erro na alocacao de memoria\n");
    else
    {
        preenche(novo);
        novo->prox = p;
        p = novo;
    }
    return p;
}

void preenche(pno p)
{
    printf("Nome: ");
    scanf(" %99[^\n]", p->nome);
    printf("Id: ");
    scanf(" %d", &p->id);
    printf("Peso: ");
    scanf(" %f", &p->peso);
    printf("Altura: ");
    scanf(" %f", &p->altura);
    p->prox = NULL;
}

pno insere_final(pno p){
    pno novo, aux;
    novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenche(novo);
    if(p == NULL)
        p = novo;
    else
    {
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

pno elimina(pno p)
{
    int id;
    printf("\nID: ");
    scanf("%d", id);
    pno atual, anterior = NULL;
    atual = p;
    while(atual != NULL && atual->id != id)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return p;
    if(anterior == NULL)
        p = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
    return p;
}

void liberta_lista(pno p)
{
    pno aux;
    while(p != NULL)
    {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

int menu(){
    int i;
    puts("\n1 - Mostrar Lista");
    puts("2 - Inserir Inicio");
    puts("3 - Inserir Final");
    puts("4 - Eliminar");
    puts("5 - Terminar");
    printf("\nEscolha uma opcao: ");
    do{
        scanf(" %d", &i);
    }while(i<1 || i>5);
    return i;
}

