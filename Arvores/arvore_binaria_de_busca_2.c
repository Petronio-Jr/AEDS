#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *esq, *dir;
}no;

// CRIA NOVO NO 

no* cria_no(int valor){

    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    return novo_no;
}

// INSERÇÃO

/*
no* insere_arvore(no* raiz, int valor){

    //se a raiz for nula, cria o primeiro no
    if(raiz == NULL) return cria_no(valor);

    if(raiz->valor > valor){
        raiz->esq = insere_arvore(raiz->esq, valor);
    }
    else if(raiz->valor < valor){
        raiz->dir = insere_arvore(raiz->dir, valor);
    }

    return raiz;
}
*/

no* insere_arvore(no* raiz, no* novo_no){

    if(raiz == NULL || raiz->valor == novo_no->valor) return novo_no;

    if(raiz->valor > novo_no->valor)
        raiz->esq = insere_arvore(raiz->esq, novo_no);
    else
        raiz->dir = insere_arvore(raiz->dir, novo_no);
    
    return raiz;
}

// IMPRESSÃO

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

// BUSCA

no* busca_arvore(no* raiz, int valor){

    if(raiz == NULL || raiz->valor == valor) return raiz;

    if(raiz->valor > valor)
        return busca_arvore(raiz->esq, valor);
    else
        return busca_arvore(raiz->dir, valor);
    
    return raiz;
}

// BUSCA DO NO PAI

/*
no* busca_pai(no* raiz, int valor){

    //se raiz é nula retorna nulo
    if(raiz == NULL) return NULL;

    //se o valor for menor
    if(raiz->valor > valor){
        //se o proximo valor nao for o buscado repete 
        if(raiz->esq->valor != valor)
            return busca_pai(raiz->esq, valor);
        else
            //se for o valor buscado para e retorna o pai
            return raiz;
    }
    else{
        //se o valor for menor 
        if(raiz->valor < valor){
            //se o proximo valor nao for o buscado repete 
            if(raiz->dir->valor != valor)
                return busca_pai(raiz->dir, valor);
            else
                //se for o valor buscado para e retorna o pai
                return raiz;
        }
    }
    return raiz;
}
*/
/*
no* busca_pai(no* raiz, no* no_busca){

    if(raiz == NULL) return NULL;

    if(raiz->valor > no_busca->valor && raiz->esq->valor != no_busca->valor){
        return raiz->esq = busca_pai(raiz, no_busca);
    }
    else if(raiz->valor < no_busca->valor && raiz->dir->valor != no_busca->valor){
        return raiz->dir = busca_pai(raiz, no_busca);
    }
    return raiz;
}
*/

no* busca_pai(no* raiz, no* no_busca){

    if(raiz == no_busca) return NULL;

    if((raiz->esq != NULL && raiz->esq->valor == no_busca->valor) || 
        (raiz->dir != NULL && raiz->dir->valor == no_busca->valor))
        return raiz;

    if(raiz->valor > no_busca->valor)
        return busca_pai(raiz->esq, no_busca);
    else
        return busca_pai(raiz->dir, no_busca);
}

// REMOVE ARVORE
/*
no* remove_arvore(no* raiz, int valor){

    if(raiz == NULL) return NULL;

    if(raiz->valor > valor){
        raiz->esq = remove_arvore(raiz->esq, valor);
    }
    else if(raiz->valor < valor){
        raiz->dir = remove_arvore(raiz->dir, valor);
    }
    else{

        if(raiz->esq == NULL || raiz->dir == NULL){

            if(raiz->esq != NULL){
                no* removido = raiz->esq;
                free(raiz);
                return removido;
            }
            else if(raiz->dir != NULL){
                no* removido = raiz->dir;
                free(raiz);
                return removido;
            }

            no* removido = NULL;
            free(raiz);
            return removido;
        }
        else{

            no* substituo = raiz->esq;
            while(substituo->dir != NULL){
                substituo = substituo->dir;
            }

            raiz->valor = substituo->valor;
            raiz->esq = remove_arvore(raiz->esq, substituo->valor);
        }
    }

    return raiz;
}
*/

no* remove_raiz(no* raiz){

    no* ant = raiz;
    no* substituto = raiz->esq != NULL ? raiz->esq : raiz; 

    // (raiz->esq != NULL) condição. (?) Se for verdade. (:) Se for falso

    if(substituto == raiz){
        //nao possui raiz->esq
        substituto = raiz->dir;
    }
    else{
        while(substituto->dir != NULL){
            ant = substituto;
            substituto = substituto->dir;
        }
        if(ant != raiz){
            ant->dir = substituto->esq;
            substituto->esq = raiz->esq;
        }
        substituto->dir = raiz->dir;
    }
    return substituto;
}

no* remove_no(no* raiz, int valor){

    no* n = busca_arvore(raiz,valor);
    if(n){

        no* pai = busca_pai(raiz,n);

        if(pai){
            if(pai->dir == n)
                pai->dir = remove_raiz(n);
            else
                pai->esq = remove_raiz(n);
        }
        else{
            raiz = remove_raiz(n);
        }
    }
    return raiz;
}

int main(){

    no* raiz = NULL;
    no* novo_no;

    novo_no = cria_no(5);
    raiz = insere_arvore(raiz,novo_no);

    novo_no = cria_no(3);
    raiz = insere_arvore(raiz,novo_no);
    novo_no = cria_no(8);
    raiz = insere_arvore(raiz,novo_no);
    novo_no = cria_no(4);
    raiz = insere_arvore(raiz,novo_no);
    novo_no = cria_no(1);
    raiz = insere_arvore(raiz,novo_no);
    novo_no = cria_no(6);
    raiz = insere_arvore(raiz,novo_no);
    novo_no = cria_no(10);
    raiz = insere_arvore(raiz,novo_no);

    novo_no = cria_no(3);
    no* pai = busca_pai(raiz, novo_no);
    printf("\n%d \n",pai->valor);

    while (raiz != NULL)
    {
        printf("\nremovendo %d\n", raiz->valor);
        raiz = remove_no(raiz, raiz->valor);
        printf("pre-ordem\n");
        imprime_pre_ordem(raiz);
        getchar();
        getchar();
    }

}