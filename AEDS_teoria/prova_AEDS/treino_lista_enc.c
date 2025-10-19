#include <stdlib.h>
#include <stdio.h>

typedef struct no_ {
    int chave;
    int valor;
    struct no_* prox;
}no;

// Lista simplesmente encadeada

no* ptlista;

no* busca_enc(int valor, no** ant, no** pont){

    *ant = ptlista;
    *pont = NULL;

    no* ptr = ptlista->prox;

    while(ptr != NULL){
        if(ptr->chave < valor){
            *ant = ptr;
            ptr = ptr->prox;
        }
        else{
            if(ptr->chave == valor)
                *pont = ptr;
            ptr = NULL;
        }
    }
    return *pont;
}

int inserir(no* novo_no){

    no* ant, *pont;

    busca_enc(novo_no->chave,&ant,&pont);

    if(pont == NULL){
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
        return 0;
    }

    return -1;
}

no* remover(int valor){

    no* ant, *pont;

    busca_enc(valor,&ant,&pont);

    if(pont != NULL){
        ant->prox = pont->prox;
        return pont;
    }

    return NULL;
}

int main(){

// Definindo no cabeça
ptlista = (no*)malloc(sizeof(no));
ptlista->prox = NULL;

no* ant, *pont;

// Buscando o valor 5

if(busca_enc(5,&ant,&pont) == NULL)
    printf("\nO valor 5 nao esta na lista!");
else
    printf("\nO valor 5 esta na lista!");

printf("\n");

// inserindo o valor 5, 1 e 10

no* novo_no = (no*)malloc(sizeof(no));
novo_no->chave = 5;
novo_no->valor = 50;
novo_no->prox = NULL;

if(inserir(novo_no) == 0)
    printf("\nNo inserido com sucesso!");
else
    printf("\nO no nao foi inserido!");

novo_no = (no*)malloc(sizeof(no));
novo_no->chave = 1;
novo_no->valor = 10;
novo_no->prox = NULL;

if(inserir(novo_no) == 0)
    printf("\nNo inserido com sucesso!");
else
    printf("\nO no nao foi inserido!");

novo_no = (no*)malloc(sizeof(no));
novo_no->chave = 10;
novo_no->valor = 100;
novo_no->prox = NULL;

if(inserir(novo_no) == 0)
    printf("\nNo inserido com sucesso!");
else
    printf("\nO no nao foi inserido!");

printf("\n");

//Buscando os valores 

if(busca_enc(5,&ant,&pont) == NULL)
    printf("\nO valor 5 nao esta na lista!");
else
    printf("\nO valor 5 esta na lista!");

if(busca_enc(1,&ant,&pont) == NULL)
    printf("\nO valor 1 nao esta na lista!");
else
    printf("\nO valor 1 esta na lista!");

if(busca_enc(10,&ant,&pont) == NULL)
    printf("\nO valor 10 nao esta na lista!");
else
    printf("\nO valor 10 esta na lista!");

printf("\n");

// Removendo valores

if(remover(5) != NULL)
    printf("\nValor 5 removido com sucesso!");
else
    printf("\nValor 5 nao foi removido!");

if(remover(1) != NULL)
    printf("\nValor 1 removido com sucesso!");
else
    printf("\nValor 1 nao foi removido!");

if(remover(10) != NULL)
    printf("\nValor 10 removido com sucesso!");
else
    printf("\nValor 10 nao foi removido!");

if(remover(15) != NULL)
    printf("\nValor 15 removido com sucesso!");
else
    printf("\nValor 15 nao foi removido!");

printf("\n");

// buscando denovo

if(busca_enc(5,&ant,&pont) == NULL)
    printf("\nO valor 5 nao esta na lista!");
else
    printf("\nO valor 5 esta na lista!");

if(busca_enc(1,&ant,&pont) == NULL)
    printf("\nO valor 1 nao esta na lista!");
else
    printf("\nO valor 1 esta na lista!");

if(busca_enc(10,&ant,&pont) == NULL)
    printf("\nO valor 10 nao esta na lista!");
else
    printf("\nO valor 10 esta na lista!");

printf("\n\nExecucao perfeita!\n");

free(ptlista);free(novo_no);

}