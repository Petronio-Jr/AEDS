#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

struct lista {
    //valor de cada item
    int valor;
    //ponteiro que vai guardar o endereço do proximo no e do anterior
    struct lista* prox;
    struct lista* ant;
};

struct fila_apontada { 
    struct lista *frente, *fundo;
    struct lista *itens;
}; 

struct fila_apontada* criar_fila() { 
	// Aloca a estrutura de dados fila
    struct fila_apontada* fila = (struct fila_apontada*)malloc(sizeof(struct fila_apontada));  
    //aloca os ponteiros ambos para NULO
	(*fila).frente = NULL;
	(*fila).fundo = NULL;
    // Retorna a fila
	return fila; 
} 

bool ehVazia(struct fila_apontada* fila) { 
    //se frente é NULLO esta vazio
    if ((*fila).frente == NULL) {
        return (true);
    } 
    return (false);
} 

void push(struct fila_apontada* fila, int item) { 
    // Aloca um espaço para a alocacao de itens
	(*fila).itens = (struct lista*)malloc(sizeof(struct lista));   
    //conferindo se é o primeiro elemento inserido no vetor
    if((*fila).fundo == NULL){
        // Definindo a frente
        (*fila).frente = (*fila).itens;
        // Definindo o fundo
        (*fila).fundo = (*fila).itens;
        // Definindo itens
        (*(*fila).itens).prox = NULL;
        (*(*fila).itens).ant = NULL;
        (*(*fila).itens).valor = item; 
    }
    else{
        // Define o valor do novo item
        (*(*fila).itens).valor = item;
        // Insere o elemento no fim da fila
        (*(*fila).itens).ant = (*fila).fundo;
        (*(*(*fila).itens).ant).prox = (*fila).itens;
        (*(*fila).itens).prox = NULL;
        // Fundo aponta pro novo item
        (*fila).fundo = (*fila).itens; 
    }
} 


int pop(struct fila_apontada* fila) { 
	// Se a fila estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila  vazia. Impossivel remover elementos");
        return -1; 
    }
    // Valor retorno
    int valor_removido = (*(*fila).frente).valor; 
    
    if((*fila).frente == (*fila).fundo){
        // Se frente e fundo sao iguais fundo se torna NULL e frente aponta pra ele
        (*fila).fundo = (*(*fila).fundo).prox;
        (*fila).frente = (*fila).fundo;
    }else{
        // Avança o ponteiro frente
        (*fila).frente = (*(*fila).frente).prox;
        (*(*fila).frente).ant = NULL;
    }

    // Informa o valor removido
    return valor_removido;
} 

int obtem_elemento(struct fila_apontada* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossivel obter elementos!");
        return -1; 
    }
    // Valor do primeiro elemento da fila
	int valor = (*(*fila).frente).valor; 
    // Retorna o valor do primeiro elemento 
    return valor;
} 


int main() { 
    int val, n;
    bool aux;
    // Cria fila
    struct fila_apontada* fila = criar_fila(); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtem elemento");
	    printf("\n4. Pilha vazia?");
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