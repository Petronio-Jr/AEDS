#include <stdlib.h>
#include <stdio.h>

typedef struct no_{
    int valor;
    struct no_ *esq, *dir;
    int altura;
}no;

int max_(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura_no(no* raiz){
    if(raiz == NULL) return 0;
    return raiz->altura;
}

int fator_balanceamento(no* raiz){
    if(raiz == NULL) return 0;
    return altura_no(raiz->esq) - altura_no(raiz->dir);
}

no* cria_no(int valor){

    no* novo_no = (no*)malloc(sizeof(no));

    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->altura = 1;

    return novo_no;
}


no* rotacao_esq(no* x){

    no* y = x->dir;
    no* z = y->esq;

    y->esq = x;
    x->dir = z;

    //atualizando as alturas
    x->altura = max_(altura_no(x->dir),altura_no(x->esq)) + 1;
    y->altura = max_(altura_no(y->dir),altura_no(y->esq)) + 1;

    //retorna a nova raiz
    return y;
}

no* rotacao_dir(no* x){

    no* y = x->esq;
    no* z = y->dir;

    y->dir = x;
    x->esq = z;

    //atualizando as alturas
    x->altura = max_(altura_no(x->dir),altura_no(x->esq)) + 1;
    y->altura = max_(altura_no(y->dir),altura_no(y->esq)) + 1;

    //retorna a nova raiz
    return y;
}

no* inserir_avl(no* raiz, int valor){

    //se a raiz for nula ou se o numero ja estiver na árvore
    if(raiz == NULL) return cria_no(valor);

    //buscando onde o valor será inserido
    if(raiz->valor > valor)
       raiz->esq = inserir_avl(raiz->esq, valor);
    else 
        if(raiz->valor < valor)
            raiz->dir = inserir_avl(raiz->dir, valor);
    else
        return raiz;
        
    //atualizando a altura da raiz
    raiz->altura = max_(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
    //calculando o fator de balanceamento 
    int fb = fator_balanceamento(raiz);

    //caso esquerda esquerda
    if(fb > 1 && valor < raiz->esq->valor){
        return rotacao_dir(raiz);
    }
    //caso esquerda direita
    if(fb > 1 && valor > raiz->esq->valor){
        raiz->esq = rotacao_esq(raiz->esq);
        return rotacao_dir(raiz);
    }
    //caso direita direita
    if(fb < -1 && valor > raiz->dir->valor){
        return rotacao_esq(raiz);
    }
    //caso direita esquerda
    if(fb < -1 && valor < raiz->dir->valor){
        raiz->dir = rotacao_dir(raiz->dir);
        return rotacao_esq(raiz);
    }
    return raiz;
}

no* busca_avl(no* raiz, int valor){

    if(raiz == NULL || raiz->valor == valor) return raiz;

    if(raiz->valor > valor)
        return busca_avl(raiz->esq, valor);
    else
        return busca_avl(raiz->dir, valor);

    return raiz;
}

no* remove_avl(no* raiz, int valor){

    if(raiz == NULL) return raiz;

    if (raiz->valor > valor) {
        raiz->esq = remove_avl(raiz->esq, valor);
    }
    else if (raiz->valor < valor) {
        raiz->dir = remove_avl(raiz->dir, valor);
    }
    else {
        if (raiz->esq == NULL || raiz->dir == NULL) {

            no* removido;

            if (raiz->esq == NULL)
                removido = raiz->dir;
            else
                removido = raiz->esq;

            free(raiz);
            return removido;   
        } 
        else {

            no* substituto = raiz->esq;

            while (substituto->dir != NULL)
                substituto = substituto->dir;

            raiz->valor = substituto->valor;
            
            raiz->esq = remove_avl(raiz->esq, substituto->valor);
        }
    }

    if(raiz == NULL) return NULL;

    //atualizando altura da raiz
    raiz->altura = max_(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
    //definindo o fator de balanceamento
    int fb = fator_balanceamento(raiz);

    //caso esquerda esquerda
    if(fb > 1 && fator_balanceamento(raiz->esq) >= 0){
        return rotacao_dir(raiz);
    }
    //caso esquerda direita
    if(fb > 1 && fator_balanceamento(raiz->esq) < 0){
        raiz->esq = rotacao_esq(raiz->esq);
        return rotacao_dir(raiz);
    }
    //caso direita direita
    if(fb < -1 && fator_balanceamento(raiz->dir) >= 0){
        return rotacao_esq(raiz);
    }
    //caso direita esquerda
    if(fb < -1 && fator_balanceamento(raiz->dir) < 0){
        raiz->dir = rotacao_dir(raiz->dir);
        return rotacao_esq(raiz);
    }

    return raiz;
}

void imprime_em_ordem(no* raiz){
    if(raiz == NULL) return;
    imprime_em_ordem(raiz->esq);
    printf("%d ", raiz->valor);
    imprime_em_ordem(raiz->dir);
}

void imprime_pre_ordem(no* raiz){
    if(raiz == NULL) return;
    printf("%d ", raiz->valor);
    imprime_pre_ordem(raiz->esq);
    imprime_pre_ordem(raiz->dir);
}

void imprime_pos_ordem(no* raiz){
    if(raiz == NULL) return;
    imprime_pos_ordem(raiz->esq);
    imprime_pos_ordem(raiz->dir);
    printf("%d ", raiz->valor);
}

int main(){

    no* raiz = NULL;

    raiz = inserir_avl(raiz,5);
    raiz = inserir_avl(raiz,3);
    raiz = inserir_avl(raiz,8);
    raiz = inserir_avl(raiz,1);
    raiz = inserir_avl(raiz,4);
    raiz = inserir_avl(raiz,6);
    raiz = inserir_avl(raiz,10);

    if(busca_avl(raiz,10) != NULL)
        printf("\no valor 10 esta na arvore\n");
    else
        printf("\no valor 10 nao esta na arvore\n");

    raiz = remove_avl(raiz,5);
    raiz = remove_avl(raiz,10);
    raiz = remove_avl(raiz,1);

    if(busca_avl(raiz,10) != NULL)
        printf("\no valor 10 esta na arvore\n\n");
    else
        printf("\no valor 10 nao esta na arvore\n\n");

    printf("\n\tARVORE AVL\n");

    printf("\nEM ORDEM: ");
    imprime_em_ordem(raiz);
    printf("\nPRE ORDEM: ");
    imprime_pre_ordem(raiz);
    printf("\nPOS ORDEM: ");
    imprime_pos_ordem(raiz);
    printf("\n\n");
}