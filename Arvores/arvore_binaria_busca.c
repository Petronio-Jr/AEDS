#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *esq, *dir;
}no;

no* cria_arvore(int valor){

    no* raiz = (no*)malloc(sizeof(no));
    
    raiz->valor = valor;
    //valores menores que a raiz vao à esq e maiores à dir
    raiz->esq = NULL;
    raiz->dir = NULL;

    return raiz;
}

no* busca_arvore(no* raiz, int valor){

    if(raiz == NULL || raiz->valor == valor) return raiz;

    //se for maior vai pra direita, se for menor vai pra esquerda
    if(raiz->valor > valor){
        return busca_arvore(raiz->esq, valor);
    }
    else{
        return busca_arvore(raiz->dir, valor);
    }
}

no* insere_arvore(no* raiz, int valor){

    //raiz retorna quando chega a NULL
    if(raiz == NULL) return cria_arvore(valor);

    //deslocamento pela árvore
    if(raiz->valor > valor){
        raiz->esq = insere_arvore(raiz->esq, valor);
    }
    else if(raiz->valor < valor){
        raiz->dir = insere_arvore(raiz->dir, valor);
    }
    
    return raiz;
}


no* remove_arvore(no* raiz, int valor){

    //confere se a raiz nao é nula e se o valor esta na arvore
    if(raiz == NULL) return NULL;

    no *removido, *substituto;

    if(raiz->valor > valor){
        raiz->esq = remove_arvore(raiz->esq, valor);
    }
    else if(raiz->valor < valor){
        raiz->dir = remove_arvore(raiz->dir, valor);
    }
    else{

        removido = raiz;

        //se nao houver valores à esquerda o no é substituido pelo da direita e o antigo no é libertado
        if(removido->esq == NULL){
            removido = raiz->dir;
            free(raiz); return removido; 
        }
        //se nao houver valores à direita o no é substituido pelo da esquerda e o antigo no é libertado
        else if(removido->dir == NULL){
            removido = raiz->esq;
            free(raiz); return removido;
        }
        else{

            //encontrando o no substituto para o removido
            substituto = removido->esq;

            while(substituto->dir != NULL){
                substituto = substituto->dir;
            }

            raiz->valor = substituto->valor;

            raiz->esq = remove_arvore(raiz->esq, substituto->valor);

        }
    }
    return raiz;
}

void imprime_em_ordem(no* raiz){
    if(raiz == NULL) return;
    imprime_em_ordem(raiz->esq);
    printf("%d ",raiz->valor);
    imprime_em_ordem(raiz->dir);
}

void imprime_pre_ordem(no* raiz){
    if(raiz == NULL) return;
    printf("%d ",raiz->valor);
    imprime_pre_ordem(raiz->esq);
    imprime_pre_ordem(raiz->dir);
}

void imprime_pos_ordem(no* raiz){
    if(raiz == NULL) return;
    imprime_pos_ordem(raiz->esq);
    imprime_pos_ordem(raiz->dir);
    printf("%d ",raiz->valor);
}

int main(){

    no* raiz = NULL;

    raiz = insere_arvore(raiz,5);
    raiz = insere_arvore(raiz,3);
    raiz = insere_arvore(raiz,8);
    raiz = insere_arvore(raiz,4);
    raiz = insere_arvore(raiz,1);
    raiz = insere_arvore(raiz,6);
    raiz = insere_arvore(raiz,10);

     if(busca_arvore(raiz,10) != NULL)
        printf("\no valor 10 esta na arvore\n");
    else
        printf("\no valor 10 nao esta na arvore\n");

    raiz = remove_arvore(raiz,5);
    raiz = remove_arvore(raiz,10);
    raiz = remove_arvore(raiz,1);

    if(busca_arvore(raiz,10) != NULL)
        printf("\no valor 10 esta na arvore\n\n");
    else
        printf("\no valor 10 nao esta na arvore\n\n");


    printf("\n\tARVORE BINARIA DE BUSCA\n");

    printf("\nEM ORDEM: ");
    imprime_em_ordem(raiz);
    printf("\nPRE ORDEM: ");
    imprime_pre_ordem(raiz);
    printf("\nPOS ORDEM: ");
    imprime_pos_ordem(raiz);
    printf("\n\n");

}