#include <stdlib.h>
#include <stdio.h>

typedef struct no_ {
    int chave;
    int valor;
    struct no_* prox;
}no;

int busca_bin(no F[], int valor_busca, int M){
    int inf = 0, sup = M;
    while(inf != sup){
        int meio = (inf + sup)/2;
        if(F[meio].chave < valor_busca){
            inf = meio + 1;
        }else{
            if(F[meio].chave == valor_busca){
                return meio;
            }
            sup = meio - 1;
        }
    }
    return -1;
}

int fatorial(int num){
    int resultado = 1;
    for(int i = 1; i <= num; i++){
        resultado *= i;
    }
    return resultado;
}

int r = -1;
int f = -1;

int insere_no(no F[], int* r, int* f, int M, no d){
    int prov = (*r + 1) % M;
    if(prov != *f){
        *r = prov;
        F[*r] = d;
        return *r;
    }
    return -1;
}

no remove(no F[], int* r, int* f, int M){

    no* remove = NULL;
    if(*f != -1){
        *remove = F[*f];
        if(*f == *r){
            *f = *r = 0;
        }else{
            *f = (*f + 1) % M;
        }
    }
    return *remove;
}