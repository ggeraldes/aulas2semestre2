//
// Created by goncalo on 24/04/2023.
//

#ifndef AULA7_PESSOA_H
#define AULA7_PESSOA_H

#endif //AULA7_PESSOA_H

typedef struct pessoa no, *pno;
struct pessoa{
    char nome[100];
    int id;
    float peso, altura;
    pno prox;
};

int lista_vazia(pno p);

void mostra_info(pno p);

pno insere_inicio(pno p);

pno insere_final(pno p);

pno elimina(pno p);

void liberta_lista(pno p);

void preenche(pno p);

int menu();