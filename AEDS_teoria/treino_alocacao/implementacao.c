#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_* prox;
}no;

no *ptlista;

no* busca_enc(int valor_busca, no** ant, no** pont){

    *ant = ptlista;
    *pont = NULL;

    no* ptr = (*ptlista).prox;

    while(ptr != NULL){
        if((*ptr).chave < valor_busca){
        *ant = ptr;
        ptr = (*ptr).prox;
        }else{
            if((*ptr).chave == valor_busca){
                *pont = ptr;
                return *pont;
            }
            ptr = NULL;
        }
    }
    return *pont;
}

int insere_enc(no* novo_no){

    no* ant;
    no* pont;

    busca_enc((*novo_no).chave,&ant,&pont);

    if(pont == NULL){
        (*novo_no).prox = (*ant).prox;
        (*ant).prox = novo_no;
        return 0;
    }else{
        return -1;
    }
}

no* remove_enc(int valor_busca){

    no* ant;
    no* pont;

    busca_enc(valor_busca,&ant,&pont);

    if(pont != NULL){
        (*ant).prox = (*pont).prox;
        return pont;
    }
    else{
        return NULL;
    }
}

int main(){

    no* ant; no* pont;

    ptlista = (no*)malloc(sizeof(no));
    (*ptlista).prox = NULL;

    no* novo_no = (no*)malloc(sizeof(no));

    (*novo_no).valor = 10;
    (*novo_no).chave = 1;
    (*novo_no).prox = NULL;

    insere_enc(novo_no);

    novo_no = (no*)malloc(sizeof(no));
    (*novo_no).valor = 20;
    (*novo_no).chave = 2;
    (*novo_no).prox = NULL;
    insere_enc(novo_no);

    novo_no = (no*)malloc(sizeof(no));
    (*novo_no).valor = 30;
    (*novo_no).chave = 3;
    (*novo_no).prox = NULL;
    insere_enc(novo_no);

    if(busca_enc(1,&ant,&pont) != NULL){
        printf("\nO valor esta na lista");
    }else{
        printf("\nO valor nao esta na lista");
    }

    if(busca_enc(2,&ant,&pont) != NULL){
        printf("\nO valor esta na lista");
    }else{
        printf("\nO valor nao esta na lista");
    }
        
    if(busca_enc(3,&ant,&pont) != NULL){
        printf("\nO valor esta na lista");
    }else{
        printf("\nO valor nao esta na lista");
    }

    if(busca_enc(4,&ant,&pont) != NULL){
        printf("\nO valor esta na lista");
    }else{
        printf("\nO valor nao esta na lista");
    }

    remove_enc(3);

    if(busca_enc(3,&ant,&pont) != NULL){
        printf("\nO valor esta na lista");
    }else{
        printf("\nO valor nao esta na lista");
    }


    free(ptlista);free(novo_no);

}