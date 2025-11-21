#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void imprime_vetor(int* vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

void BubbleSort(int* vetor,int tam){

    bool trocou = true;

    while(trocou){

        trocou = false;

        for(int i = 0; i < tam - 1; i++){
            if(vetor[i] > vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                trocou = true;
            }
            getchar();
            imprime_vetor(vetor,tam);
        }
        tam--;
    }
}

int main(){

    int vetor2[20] = {1, 2, 3, 4, 5, 6, 77, 32, 55, 34, 65, 88, 98, 87, 11, 50, 49, 12, 96, 100};

    printf("\nVetor desordenado: ");
    imprime_vetor(vetor2,20);

    BubbleSort(vetor2,20);

    printf("\n\nVetor ordenado: ");
    imprime_vetor(vetor2,20);
    printf("\n\n");

}