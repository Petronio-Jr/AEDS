#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_* esq;
    struct no_* dir;
    int altura; 
}no;


no* cria_arvore (int valor){

    no* raiz = (no*)malloc(sizeof(no));

    raiz->valor = valor;
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->altura = 1;

    return raiz;
}

int altura_no (no* raiz){

    if(raiz == NULL)
        return 0;

    return raiz->altura;
}


int fator_balanceamento(no* raiz){

 return (altura_no(raiz->esq) - altura_no(raiz->dir));

}

no* rotacao_esq (){

    
}





int main(){


      
}