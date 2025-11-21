#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

//retorna NULL se o valor tiver na arvore e se nao tiver retorna o pai da inserção
no* busca_avl(no* raiz, int valor){

    //checa se o valor buscado é maior que o da raiz
    if(valor > raiz->valor){
        //checa se há algum nó à direita da raiz
        if(raiz->dir != NULL){
            //retorna a função com o nó à direita
            return busca_avl(raiz->dir,valor);
        }
        else{
            //retorna o nó pai da inserção
            return raiz;
        }
    }
    else{
        //checa se o valor é menor que o da raiz
        if(valor < raiz->valor){
            //checa se há algum nó à esquerda
            if(raiz->esq != NULL){
                //retorna a função com esse nó
                return busca_avl(raiz->esq,valor);
            }
            else{
                //retorna o nó pai da inserção
                return raiz;
            }
        }
        else{
            //se o valor já estiver na árvore retona NULL
            //if(valor == raiz->valor)
            return NULL;
        }
    }
}
