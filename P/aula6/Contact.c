//
// Created by goncalo on 21/04/2023.
//

#include <malloc.h>
#include <stdio.h>
#include "Contact.h"

contacto obtem_info()
{
    contacto t;
    printf("Nome: ");
    scanf("%99[^\n]", t.nome);
    printf("Contacto: ");
    scanf(" %14s", t.numero);
    return t;
}
contacto* elimina_cliente(contacto *tab, int *n){
    contacto *aux;
    aux = realloc(tab, sizeof(contacto) * (*n-1));
    if(aux != NULL){
        tab = aux;
        tab[*n] = obtem_info();
        (*n)--;
    }
    return tab;
}

contacto *adiciona_cliente(contacto *tab, int* n){
    contacto *aux;
    aux = realloc(tab, sizeof(contacto) * (*n+1));
    if(aux != NULL){
        tab = aux;
        tab[*n] = obtem_info();
        (*n)++;
    }
    return tab;
}