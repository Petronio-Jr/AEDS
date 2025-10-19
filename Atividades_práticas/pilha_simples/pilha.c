#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"

struct lista_items{ //transformei int* items numa lista
    int valor; //valor do item
    struct lista_items* next; //usado pra conectar os itens
};

struct pilha { 
	struct lista_items* topo; //topo da pilha
}; 

struct pilha* criar_pilha() { 
	
    struct pilha* pilha = (struct pilha*)malloc(sizeof(struct pilha)); // Aloca a estrutura de dados pilha

	(*pilha).topo = NULL; //quando não há nenhum elemento o topo aponta pra NULL

	return pilha; // Retorna a pilha
} 

bool ehVazia(struct pilha* pilha) { 

    if ((*pilha).topo == NULL) { //se o topo aponta pra NULL ta vazio
        return (true);
    } 
    return (false);
} 

struct lista_items* novo; //defini novo como global para que possa libertar a memória no final do código

void push(struct pilha* pilha, int item) { 

    novo = (struct lista_items*)malloc(sizeof(struct lista_items)); //criando o novo elemento 

    (*novo).valor = item; //colocando o valor desejado no item

    (*novo).next = (*pilha).topo; //o item aponta pra onde topo aponta. NULL no primeiro caso e depois pros items inseridos antes 
    (*pilha).topo = novo; //topo passa a apontar pro novo elemento. Novo topo da pilha

} 

int pop(struct pilha* pilha) { 
	
    if (ehVazia(pilha)) { // Se a pilha estiver vazia, não tem como remover nenhum elemento
		printf("\nPilha  vazia. Impossível remover elementos");
        return -1; 
    }

    int valor_retorno = (*(*pilha).topo).valor; //armazenando valor

    (*pilha).topo = (*(*pilha).topo).next; //removendo, o topo passa a pontar pra um alem do topo atual

	return valor_retorno; 
} 

int obtem_elemento(struct pilha* pilha) { 
	
    if (ehVazia(pilha)) { // Se a pilha estiver vazia, não tem como obter nenhum elemento
		printf("\nPilha  vazia. Impossível obter elementos");
        return -1; 
    }
    
    int valor_retorno = (*(*pilha).topo).valor; // Guarda o valor do elemento do topo

	return valor_retorno; // Retorna o elemento do topo da pilha
}


int main() { 
    int val, n;
    bool aux;  
    struct pilha* pilha = criar_pilha(); // Cria pilha com quantas posicoes posições desejar
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Pilha vazia?");
	    printf("\n0. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(pilha , val);
                break;
            case 2: 
               printf("\nElemento retirado : %d",pop(pilha));
                break;
            case 3: 
               printf("\nElemento do topo: %d",obtem_elemento(pilha));
                break;
            case 4: 
                aux = ehVazia(pilha);
                if (aux) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nPilha não está vazia");
                }                
                break;      
            case 0:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
        free(pilha); free(novo); //libertando a memória alocada
    return (0);
 }