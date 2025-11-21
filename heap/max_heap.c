#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* vetor,int tam,int i){

    if(vetor == NULL) return;

    int maior = i;
    int esq = 2*i;
    int dir = (2*i) + 1;

    if(esq < tam && vetor[esq] > vetor[maior]){
        maior = esq;
    }
    if(dir < tam && vetor[dir] > vetor[maior]){
        maior = dir;
    }

    if(maior != i){
        troca(&vetor[i],&vetor[maior]);
        heapify(vetor,tam,maior);
    }
}

void cria_MaxHeap(int* vetor, int tam){

    if(vetor == NULL) return;

    for(int i = tam/2; i >= 1; i--){
        heapify(vetor,tam,i);
    }
}

// GENIAL

void HeapSort(int* vetor, int tam){

    if(vetor == NULL) return;

    cria_MaxHeap(vetor,tam);

    for(int i = tam; i > 1; i--){
        troca(&vetor[1],&vetor[i]);
        heapify(vetor,i,1);
    }

}

void imprime_vetor(int* vetor, int tam){

    if(vetor == NULL) return;

    for(int i = 1; i <= tam; i++){
        printf("%d ",vetor[i]);
    }
}


int main(){

    int vetor[16] = {0,5,78,2,34,55,1,21,8,30,11,20,43,86,99,15};
    int tam = 15;

    printf("\nVetor: ");
    imprime_vetor(vetor,tam);

    cria_MaxHeap(vetor,tam);
    printf("\nMaxHeap: ");
    imprime_vetor(vetor,tam);

    printf("\nMaxHeap odenada: ");
    HeapSort(vetor,tam);
    imprime_vetor(vetor,tam);

    printf("\n\n");

}