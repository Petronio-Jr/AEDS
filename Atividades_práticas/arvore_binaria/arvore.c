#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Cria um novo nó na árvore
struct no* novo_no(int item) {
    struct no* temp = (struct no*)malloc(sizeof(struct no));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
 
// Inserir novo nó com determinado
// valor na árvore binária
struct no* inserir(struct no* raiz, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (raiz == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return raiz;
}
 
// Procura por um valor na árvore
struct no* buscar(struct no* raiz, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Valor é maior que a raiz
    if (raiz->valor < valor) {
        return buscar(raiz->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(raiz->esquerda, valor);
}

struct no* remover(struct no** raiz, int valor_busca){

    //se a árvore estiver vazia ou com 1 elemento  retorna NULL
    if(*raiz == NULL){
        return *raiz;
    }

    if((*raiz)->valor == valor_busca){
        
        struct no* ant = *raiz;
        struct no* pont = (*raiz)->esquerda;

        if(pont == NULL){
            //se nao houver filhos à equerda a raiz recebe a parte da direita
            *raiz = (*raiz)->direita;
            return ant;
        }
        else{
            //encontrando o no substituto (um pra esquerda e full direita)
            while(pont->direita != NULL){
                ant = pont;
                pont = pont->direita;
            }

            //reconectando os galhos da árvore
            if(ant == *raiz){
                //se o no substituido for pai e o filho nao tiver filhos esse é o novo pai
                ant->esquerda = pont->esquerda;
            }
            else{
                //se houver algum elemento à direita do que será substituto ele assume seu lugar
                if(pont->esquerda != NULL){
                    ant->direita = pont->esquerda;
                }
                else{
                //se nao houver nenhum elemento à direita esse espaço vira NULL e ele recebe a direita da raiz
                    pont->esquerda = (*raiz)->esquerda;
                    ant->direita = NULL;
                }
            }

            pont->direita = (*raiz)->direita;

            //mudando o ponteiro
           *raiz = pont;
        }
    }
    else{
        //se o valor nao for o buscado ele ve pra qual lado deve avançar e repete a função
        if(valor_busca < (*raiz)->valor)
            return remover(&(*raiz)->esquerda,valor_busca);
        else
            return remover(&(*raiz)->direita,valor_busca);
    }

    return *raiz;
}
 
void imprime_em_ordem(struct no* raiz){

    if(raiz == NULL) return;

    imprime_em_ordem(raiz->esquerda);

    printf("\n%d",raiz->valor);

    imprime_em_ordem(raiz->direita);
}

int main() {

    // Define a árvore como uma estrutura vazia
    struct no* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós
    inserir(root, 30);
    inserir(root, 20);
    inserir(root, 40);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 80);
    inserir(root, 10);

    // Buscando valores
    printf("\n###### Busca na arvore ###########\n");

    int valor = 100;

    if (buscar(root, valor) == NULL) {
        printf("\nValor %d nao encontrado\n", valor);
    } else {
        printf("\nValor %d encontrado\n", valor);
    }

    valor = 60;
 
    if (buscar(root, valor) == NULL) {
        printf("\nValor %d não encontrado\n", valor);
    } else {
        printf("\nValor %d encontrado\n", valor);
    }

    //----------------------------------------------------------------------------------------------------------------
    
    // Imprimindo valores
    printf("\n###### Imprimindo valores ###########\n");
    imprime_em_ordem(root);

    //----------------------------------------------------------------------------------------------------------------

    // Removendo valores 10 30 80 e 100
    printf("\n\n###### Removendo valores ###########\n");

    valor = 10;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    valor = 30;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    valor = 80;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    valor = 100;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    //----------------------------------------------------------------------------------------------------------------
    
    // Imprimindo valores
    printf("\n###### Imprimindo valores ###########\n");
    imprime_em_ordem(root);

    //----------------------------------------------------------------------------------------------------------------

    // Removendo a raiz principal 50
    printf("\n\n###### Removendo valores ###########\n");

    valor = 50;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    //----------------------------------------------------------------------------------------------------------------

    // Imprimindo valores
    printf("\n###### Imprimindo valores ###########\n");
    imprime_em_ordem(root);

    //----------------------------------------------------------------------------------------------------------------

    // Removendo os valores 20 60 e 70
    printf("\n\n###### Removendo valores ###########\n");

    valor = 20;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    valor = 60;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    valor = 70;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);

    //----------------------------------------------------------------------------------------------------------------

    // Imprimindo valores
    printf("\n###### Imprimindo valores ###########\n");
    imprime_em_ordem(root);

    //----------------------------------------------------------------------------------------------------------------

    // Removendo o ultimo valor 40
    printf("\n\n###### Removendo valores ###########\n");

    valor = 40;

    if (remover(&root, valor) == NULL)
        printf("\nValor %d nao foi removido!\n",valor);
    else
        printf("\nValor %d foi removido com sucesso!\n",valor);
    //----------------------------------------------------------------------------------------------------------------

    // Imprimindo valores
    printf("\n###### Imprimindo valores ###########\n");
    imprime_em_ordem(root);

    printf("\n\n");

    return 0;
}
