#include <stdio.h>
#include <stdlib.h>
#include "ordenacao_linear.h"

void imprime(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
}

//retorna o meior valor do vetor
int maior_valor(int* vetor, int tam){
    int maior = vetor[0];
    for( int i = 1; i < tam; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}

//====================== Radix Sort ======================================
//========================================================================

// fiz um countsort para lidar com os digitos
void countSort_digitos(int* vetor, int tam, int exp) {

    //Alocar um array auxiliar para armazenar o resultado da ordenação por este dígito
    int *saida = (int *) malloc(tam * sizeof(int));

    //vetor de contagem para dígitos de 0 a 9
    int count[10];

    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    //Conta quantas vezes cada dígito (no lugar exp) aparece
    for (int i = 0; i < tam; i++) {
        //seleciona o valor a ser comparado
        int valor = vetor[i];
        //pega o digito a ser comparado
        int digito = (valor / exp) % 10;
        //adiciona a frequencia no vetor
        count[digito] = count[digito] + 1;
    }

    ///Modifica count[i] para que contenha a posição real desse dígito na saída
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    //Constroe o vetor de saída 
    for (int i = tam - 1; i >= 0; i--) {

        int valor = vetor[i];
        int digito = (valor / exp) % 10;
        // posição no vetor de saída
        int pos = count[digito] - 1;    
        saida[pos] = valor;
        count[digito] = count[digito] - 1;
    }

    //Passando o resultado de volta para o vetor original
    for (int i = 0; i < tam; i++) {
        vetor[i] = saida[i];
    }

    //Liberando memória auxiliar
    free(saida);
}


void RadixSort(int *vetor, int tam) {

    //Encontra o maior valor para saber o número de dígitos
    int maior = maior_valor(vetor, tam);

    //Faz o countSort para cada dígito, o exp representa o expoente do digito 
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countSort(vetor, tam, exp);
    }
}

//========================================================================


int main() {

    int vetor[15] = {1513, 5314 ,1216, 480, 952, 3201, 9883, 19159, 5293, 879, 1705, 9333, 6171, 4059, 2320};

    printf("\nVetor desordenado: ");
    imprime(vetor, 15);

    RadixSort(vetor, 15);

    printf("\n\n");

    printf("Vetor ordenado: ");
    imprime(vetor, 15);

    printf("\n\n");
}
