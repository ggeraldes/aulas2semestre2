#include <stdio.h>
#include <malloc.h>
#include "Pessoa.h"
int main() {
    pno lista=NULL;

    int i;
    //lista= adicionar_pessoa("aaaaa", 1, 20.5, 16.2);
    //printf("nome: %s, id: %d, peso:%f, altura: %f ", a->nome, a->id, a->peso, a->altura);
    do {
        i = menu();
        switch(i){
            case 1: mostra_info(lista); break;
            case 2: lista=insere_inicio(lista); break;
            case 3: lista=insere_final(lista); break;
            case 4: lista=elimina(lista); break;
        }
    } while(i != 5);

    if (lista != NULL)
        free(lista);
}
