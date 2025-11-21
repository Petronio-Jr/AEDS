#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include "heap.h"

#define TAM 16 //15 elementos mais o 0 (começa a partir do indice 1)

struct Heap* heap_inicializa(int tam) {

    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));

    heap->tam = tam;
    heap->indice = 0;
    heap->prioridade = (int*)malloc(sizeof(int) * tam);

    return heap;
}

//Função pra imprimir o vetor 
void imprime(struct Heap* heap, int tam){
    for(int i = 1; i < tam; i++){
        printf("%d ",heap->prioridade[i]);
    }
}

//se só tem o 0 então ta vazia
bool EhVazia(struct Heap* heap){
    if(heap->indice == 0) return true;
    else return false;
}

//se tem TAM elementos então ta cheia
bool EhCheia(struct Heap* heap){
    if(heap->indice == TAM) return true;
    else return false;
}

//Modifiquei a função troca
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void corrige_acima(struct Heap* heap, int indice) {
    int pai;
    while (indice > 0) {

        //essa conta funciona pra base 1 tanto pra numeros impares quanto pares
        pai = indice/2;

        if (heap->prioridade[pai] < heap->prioridade[indice]) {
            troca(&heap->prioridade[indice],&heap->prioridade[pai]);
        }else{ 
            break;
        }
        indice = pai;
    }
}

void heap_insere(struct Heap* heap, int prioridade) {

    //se estiver cheia sai da função
    if(EhCheia(heap)){
        printf("\nHeap CHEIO!\n"); 
        return;
    }

    //a posicao 0 nao sera usada
    if(heap->indice == 0){
        heap->indice = 1;
    }

    if (heap->indice < heap->tam) {

        heap->prioridade[heap->indice] = prioridade;

        corrige_acima(heap, heap->indice);

        heap->indice++;
    }
}

void corrige_abaixo(int *valor, int atual, int tam) {

    int pai = atual;

    int filho_esq, filho_dir, filho;

    while ((2 * pai) + 1 < tam){

        //adaptei pra heap de base 1
        filho_esq = 2*pai;
        filho_dir = (2*pai) + 1;

        if (filho_dir >= tam) {
            filho_dir = filho_esq;
        }

        if (valor[filho_esq] > valor[filho_dir]) {
                filho = filho_esq;
        }else {
            filho = filho_dir;
        }

        if (valor[pai] < valor[filho]) {
            troca(&valor[pai],&valor[filho]);
        }else {
            break;
        }

        pai = filho;
    }
}

int heap_remove(struct Heap* heap) {

    //se o vetor esta vazio sai da função
    if(EhVazia(heap)){
        printf("\nHeap CHEIO!\n"); 
        return -1;
    }

    //o topo foi alterado para 1 ao inves de 0
    int topo = heap->prioridade[1];

    heap->prioridade[1] = heap->prioridade[heap->indice - 1];
    heap->indice--;

    corrige_abaixo(heap->prioridade, 1, heap->indice);
    return topo;  
}

int main() { 

    struct Heap *heap = heap_inicializa(TAM);

    int opcao = -1, valor;

    while(opcao != 0){

        printf("\n===============================================================");
        printf("\n\t\tMENU DE OPCOES:\n\nO que deseja?\n");

        printf("\n1.Exibir lista de prioridade");
        printf("\n2.Inserir um valor");
        printf("\n3.Remover um valor");
        printf("\n4.Esta vazio?");
        printf("\n5.Esta cheio?");
        printf("\n\n0.Sair\n\n");
        scanf("%d",&opcao);
        printf("\n");

        switch(opcao){

        case 1:

            if(EhVazia(heap)) {
                printf("Nao ha nada para exibir!\n");
            }else{
                imprime(heap,heap->indice);
            }
            break;

        case 2:

            if(EhCheia(heap)){
                printf("Nao ha mais espaco para inserir\n");
            }
            else{
                printf("\nInsira o valor de prioridade: ");
                scanf("%d",&valor);

                heap_insere(heap,valor);
                printf("O valor foi inserido com sucesso na heap!\n");
            }
            break;
        
        case 3:

            if(EhVazia(heap)){
                printf("Nao ha nada para ser removido!\n");
            }
            else{
                heap_remove(heap);
                if(heap->indice != 0)
                    printf("O valor de maior prioridade foi removido com sucesso!\n");
                else
                    printf("O valor de indice 0 foi removido com sucesso!\n");
            }
            break;

        case 4:
            
            if(EhVazia(heap)){
                printf("\nHeap vazia!\n");
            }
            else{
                valor = heap->indice;

                if(valor != 1)
                    printf("Ainda tem %d espacos ocupados!\n",valor - 1);
                else
                    printf("\nHeap vazia!\n");
            }
            break;

        case 5:
            
            if(EhCheia(heap)){
                printf("\nHeap cheia!\n");
            }
            else{
                valor = TAM - heap->indice;

                if(valor != 16)
                    printf("Ainda tem %d espacos livres!\n",valor);
                else
                    printf("Ainda tem %d espacos livres!\n",valor - 1);
            }
            break;

        case 0:
            return 0; break;

        default:
            printf("\nComando errado!\n"); break;
        }
    }

}