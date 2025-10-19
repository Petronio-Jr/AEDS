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

void imprime_pre_ordem(struct no* raiz){

    if(raiz == NULL) return;

    printf("\n%d",raiz->valor);

    imprime_pre_ordem(raiz->esquerda);

    imprime_pre_ordem(raiz->direita);
}

void imprime_pos_ordem(struct no* raiz){
    
    if(raiz == NULL) return;

    imprime_pos_ordem(raiz->esquerda);

    imprime_pos_ordem(raiz->direita);

    printf("\n%d",raiz->valor);
}

//função pra contar quantos elementos tem na árvore
int tam_arvore(struct no* raiz){

    if(raiz == NULL) return 0;

    // retorna 1 + tam_arvore(3) + tam_arvore(10) e assim por diante. Se houver valor ele retorna 1 se for nulo retorna 0
    return 1 + tam_arvore(raiz->esquerda) + tam_arvore(raiz->direita);
}


void imprime_por_nivel(struct no* raiz){
    
    if(raiz == NULL) return;

    //criando uma fila de ponteiros pros nos da arvore
    struct no** fila = (struct no**)malloc(sizeof(struct no*) * tam_arvore(raiz));
    //inicio e fim começam em 0
    int inicio = 0, fim = 0;

    //fim recebe a raiz cabeça
    fila[fim++] = raiz;

    while(inicio < fim){
        
        //no que será exibido na tela
        struct no* atual = fila[inicio++];
        printf("\n%d",atual->valor);

        if(atual->esquerda != NULL)
            fila[fim++] = atual->esquerda;
        if(atual->direita != NULL)
            fila[fim++] = atual->direita;
    }

    //liberando a fila alocada
    free(fila);
}

int main() {

    // Define a árvore como uma estrutura vazia
    struct no* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 8);

    // Insere outros nós
    inserir(root, 3);
    inserir(root, 10);
    inserir(root, 1);
    inserir(root, 6);
    inserir(root, 14);
    inserir(root, 4);
    inserir(root, 7);
    inserir(root, 13);

    // Imprimindo valores
    printf("\n###### Imprimindo valores em ordem ###########\n");
    imprime_em_ordem(root);

    printf("\n\n###### Imprimindo valores pre ordem ###########\n");
    imprime_pre_ordem(root);

    printf("\n\n###### Imprimindo valores pos ordem ###########\n");
    imprime_pos_ordem(root);

    printf("\n\n###### Imprimindo valores por nivel ###########\n");
    imprime_por_nivel(root);

    printf("\n\n");

    return 0;
}