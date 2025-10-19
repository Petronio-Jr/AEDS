#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_* prox;
}no;

typedef struct fila_enc_{
    no* frente;
    no* fundo;
}fila_enc;

no* busca_fila_enc(int valor_busca, fila_enc* fila){
    
    if(fila->frente != NULL){

        no* tmp = fila->frente;
    
        while(tmp != fila->fundo->prox){    
            if(tmp->valor != valor_busca){
                tmp = tmp->prox;
            }
            else{
                if(tmp->valor == valor_busca)
                    return tmp;
            }
        }
    }
    return NULL;
}

int insere_fila(no* novo_no, fila_enc* fila){

    if(fila->fundo == NULL){
        fila->fundo = fila->frente = novo_no;
        return 0; 
    }
    else{
        fila->fundo->prox = novo_no;
        fila->fundo = novo_no;
        return 0; 
    }
    return -1;
}

int remove_fila(fila_enc* fila){

    if(fila->frente == NULL){
        return -1;
    }
    else{
        if(fila->frente == fila->fundo){
            fila->frente = fila->fundo = NULL;
        }
        else{
            fila->frente = fila->frente->prox;
        }
    }
    return 0;
}

void imprimir(fila_enc* fila){

    no* tmp = fila->frente;

    while(tmp != fila->fundo){
        printf("\n%d",tmp->valor);
        tmp = tmp->prox;
    }
    printf("\n%d",fila->fundo->valor);
}

int main(){

    fila_enc* fila = (fila_enc*)malloc(sizeof(fila_enc*));
    fila->frente = NULL;
    fila->fundo = NULL;

    // Buscando o valor 10

    if(busca_fila_enc(10,fila) != NULL)
        printf("\nValor 10 esta na fila!");
    else
        printf("\nValor 10 nao esta na fila");

    printf("\n");

    // Inserindo os valores 10, 4 e 20

    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->valor = 10; 
    novo_no->prox = NULL;

    if(insere_fila(novo_no,fila) == 0)
        printf("\nO valor 10 foi inserido com sucesso!");
    else    
        printf("\nO valor 10 nao foi inserido!");

    novo_no = (no*)malloc(sizeof(no));
    novo_no->valor = 4; 
    novo_no->prox = NULL;

    if(insere_fila(novo_no,fila) == 0)
        printf("\nO valor 4 foi inserido com sucesso!");
    else    
        printf("\nO valor 4 nao foi inserido!");

    novo_no = (no*)malloc(sizeof(no));
    novo_no->valor = 20; 
    novo_no->prox = NULL;

    if(insere_fila(novo_no,fila) == 0)
        printf("\nO valor 20 foi inserido com sucesso!");
    else    
        printf("\nO valor 20 nao foi inserido!");

    printf("\n");
    imprimir(fila);
    printf("\n");

    // Buscando novamente

    if(busca_fila_enc(10,fila) != NULL)
        printf("\nValor 10 esta na fila!");
    else
        printf("\nValor 10 nao esta na fila");

    if(busca_fila_enc(4,fila) != NULL)
        printf("\nValor 4 esta na fila!");
    else
        printf("\nValor 4 nao esta na fila");

    if(busca_fila_enc(20,fila) != NULL)
        printf("\nValor 20 esta na fila!");
    else
        printf("\nValor 20 nao esta na fila");

    printf("\n");
    imprimir(fila);
    printf("\n");

    // Retirando valores 

    if(remove_fila(fila) == 0)
        printf("\nO valor do inicio foi retirado com sucesso!");
    else
        printf("\nO valor do inicio nao foi retirado!");

    if(remove_fila(fila) == 0)
        printf("\nO valor do inicio foi retirado com sucesso!");
    else
        printf("\nO valor do inicio nao foi retirado!");

    printf("\n");
    imprimir(fila);
    printf("\n");

    // Buscando novamente

    if(busca_fila_enc(10,fila) != NULL)
        printf("\nValor 10 esta na fila!");
    else
        printf("\nValor 10 nao esta na fila");

    if(busca_fila_enc(4,fila) != NULL)
        printf("\nValor 4 esta na fila!");
    else
        printf("\nValor 4 nao esta na fila");

    if(busca_fila_enc(20,fila) != NULL)
        printf("\nValor 20 esta na fila!");
    else
        printf("\nValor 20 nao esta na fila");

    printf("\n");
    imprimir(fila);
    printf("\n");

    printf("\nExecutou certo!");
    printf("\n");

    free(novo_no);free(fila);
}