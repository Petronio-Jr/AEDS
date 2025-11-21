#include <stdio.h>
#include <stdlib.h>
#include "ordenacao_linear.h"

void imprime(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
}

//====================== Counting Sort ===================================
//========================================================================

int maior_num(int* vetor, int tam){

    //se o vetor tiver vazio ou so tiver um elemento 
    if(vetor == NULL || tam == 1){
        return 0;
    }

    //o primeiro elemento do vetor é a base pro maior
    int maior = vetor[0];

    //os demais sao comparados com o primeiro e o maior é atualizado
    for(int i = 1; i < tam; i++){
        if(vetor[i] > maior ){
            maior = vetor[i];
        }
    }

    //retorna o maior valor do vetor
    return maior;
}

void contagem_numeros(int* vetor, int tam, int* vetor_adicional){

    //percorre o vetor comparando os elementos
    for(int i = 0; i < tam; i++){
        //valor é o que será comparado
        int valor = vetor[i];
        //vetor adicional inicialmente é 0 
        vetor_adicional[valor] = vetor_adicional[valor] + 1;
    }
}

void reconstrucao_vetor(int* vetor, int tam, int* vetor_adicional, int k){

    //indica a partir de onde os valores serão adicionados
    int cont = 0;

    //percorre o tamaho do vetor adicional
    for(int i = 0; i <= k; i++){

        //se o valor na posição for 0 ele passa pra proxima
        if(vetor_adicional[i] != 0){

            //numero de vezes que o numero repete
            int repeticoes = vetor_adicional[i];

            //percorre o vetor original mantendo a posicao onde parou (cont)
            for(int j = cont; j < tam; j++){

                //adiciona o numero repetidas vezes nas casas em sequencia
                if(repeticoes > 0){

                    //a posicao do vetor recebe o valor
                    vetor[j] = i;

                    //cont avança e diminui o numero de repetições
                    cont++;
                    repeticoes--;
                }

            }
        }
    }
}

void CountingSort(int* vetor, int tamanho){

    //maior numero do vetor
    int k = maior_num(vetor,tamanho);

    //criando um vetor adicional todo com 0

    int *vetor_adicional = (int*)malloc(sizeof(int) * (k + 1));

    for(int i = 0; i <= k; i++){
        vetor_adicional[i] = 0;
    }

    //calculando a frequencia e alterando os valores no vetor adicional
    contagem_numeros(vetor,tamanho,vetor_adicional);

    //organiza o vetor original
    reconstrucao_vetor(vetor,tamanho,vetor_adicional,k);

    free(vetor_adicional);
}

//========================================================================


int main(){

    //vetor teste
    int vetor[7] = {9,2,3,4,3,2,2};

    printf("\nVetor desordenado: ");

    imprime(vetor,7);  
    printf("\n");

    CountingSort(vetor,7);

    printf("\nVetor ordenado: ");

    imprime(vetor,7);
    printf("\n\n");

}