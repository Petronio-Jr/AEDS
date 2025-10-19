#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

struct fila_circular { 
    int frente, fundo, tamanho_maximo;
    int tamanho_atual;
    int* itens;
}; 

struct fila_circular* criar_fila(int tamanho) { 
	// Aloca a estrutura de dados fila
    struct fila_circular* fila = (struct fila_circular*)malloc(sizeof(struct fila_circular)); 
	// Armazena o tamanho que ela foi criada
    (*fila).tamanho_maximo = tamanho; 
    (*fila).tamanho_atual = 0; 
    //aloca os indices
	(*fila).frente = 0;
	(*fila).fundo = 0;
    // Aloca o vetor de items utilizando o tamanho passado para a função
	(*fila).itens = (int*)malloc(tamanho * sizeof(int)); 
    // Retorna a fila
	return fila; 
} 

bool ehCheia(struct fila_circular* fila) { 
    // Se o tamanho atual for igual ao maximo a fila esta cheia
	if ((*fila).tamanho_atual == (*fila).tamanho_maximo) {
        return (true);
    }
    // Caso contrário, ela não está cheia
    return (false);
} 

bool ehVazia(struct fila_circular* fila) { 
    // Se o tamanho atual não for alterado a fila permanece vazia
    if ((*fila).tamanho_atual == 0) {
        return (true);
    } 
    return (false);
} 

void push(struct fila_circular* fila, int item) { 
	// Se a fila estiver cheia, não tem como inserir nenhum novo elemento
    if (ehCheia(fila)) {
		printf("\nFila cheia. Impossivel inserir elementos");
        return; 
    }
    //conferindo se o fundo é o ultimo elemento e fazendo ele voltar ao inicio
    if((*fila).fundo == (*fila).tamanho_maximo){
        (*fila).fundo = 0;
    }
    //Insere o elemento no fim da fila
	(*fila).itens[(*fila).fundo] = item; 
    (*fila).fundo++;
    //aumentando o tamanho atual da fila
    (*fila).tamanho_atual++;
} 


int pop(struct fila_circular* fila) { 
	// Se a fila estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossivel remover elementos");
        return -1; 
    }
    //se frente chegar ao fim da fila ele volta ao inicio
    if((*fila).frente == (*fila).tamanho_maximo){
        (*fila).frente = 0;
    }
    int valor_removido = ((*fila).itens[(*fila).frente]);
    // Remove o elemento no inicio da lista e diminui o tamanho atual
    (*fila).frente++; 
    (*fila).tamanho_atual--;

    return valor_removido;
} 

int obtem_elemento(struct fila_circular* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossivel obter elementos!");
        return -1; 
    }
    // Valor do primeiro elemento da fila
	int valor;
    
    if((*fila).frente == (*fila).tamanho_maximo){
        valor = (*fila).itens[0];   
    }else{
        valor = (*fila).itens[(*fila).frente]; 
    }
    return valor;
} 


int main() { 
    int val, n;
    bool aux;
    // Cria filaa com 5 posições
    struct fila_circular* fila = criar_fila(5); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtem elemento");
	    printf("\n4. Pilha vazia?");
        printf("\n5. Pilha cheia?");
	    printf("\n0. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(fila , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(fila));
                break;
            case 3: 
                printf("\nElemento do inicio: %d",obtem_elemento(fila));
                break;
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nFila vazia");
                } else {
                    printf("\nFila nao esta vazia");
                }
                break;
            case 5: 
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nFila cheia");
                } else {
                    printf("\nFila nao esta cheia");
                }
                break;         
            case 0:
                return (1);
                break;
            default: printf("\nOpçao errada!");
                break;
        }
	} while(1);
    // Liberando memória alocada
    free(fila);
    return (0);
 }