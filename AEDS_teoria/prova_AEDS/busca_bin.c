#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    struct no_* prox;
}no;

int busca_bin_lista_sem_pont(no L[], int x, int M){

    int inicio = 0, fim = M;

    if(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(L[meio].chave < x){
            inicio = meio + 1;
        }
        else{
            if(L[meio].chave == x){
                return meio;
            }
            fim = meio - 1;
        }
    }
    return -1;
}

int busca_bin__lista_pont(no* L[], int x, int M){

    int inicio = 0, fim = M;

    if(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(L[meio]->chave < x){
            inicio = meio + 1;
        }
        else{
            if(L[meio]->chave == x){
                return meio;
            }
            fim = meio - 1;
        }
    }
    return -1;
}

int main(){

}