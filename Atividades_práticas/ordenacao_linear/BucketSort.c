#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao_linear.h"

#define NUM_BALDES 10

typedef struct no_{
    int valor;
    struct no_* prox;
}no;

void imprime(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
}

//====================== Insertion Sort ==================================
//========================================================================

//Função usada pra ordenar dentro dos baldes, nesse vetor nem precisa

no* InsertionSort(no* no_cabeca) {

    if (no_cabeca == NULL || no_cabeca->prox == NULL) {
        return no_cabeca;
    }

    no* ordenado = NULL;
    no* atual = no_cabeca;

    while (atual != NULL) {

        no* proximo = atual->prox;

        // desconecta o atual
        atual->prox = NULL;

        // insere atual em ordenado
        if (ordenado == NULL || ordenado->valor >= atual->valor) {

            atual->prox = ordenado;
            ordenado = atual;
        } else {

            no* temp = ordenado;

            while (temp->prox != NULL && temp->prox->valor < atual->valor) {
                temp = temp->prox;
            }

            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = proximo;
    }
    return ordenado;
}

//====================== Bucket Sort =====================================
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

int menor_num(int* vetor, int tam){

    //se o vetor tiver vazio ou so tiver um elemento 
    if(vetor == NULL || tam == 1){
        return 0;
    }

    //o primeiro elemento do vetor é a base pro menor
    int menor = vetor[0];

    //os demais sao comparados com o primeiro e o menor é atualizado
    for(int i = 1; i < tam; i++){
        if(vetor[i] < menor ){
            menor = vetor[i];
        }
    }

    //retorna o menor valor do vetor
    return menor;
}

int escolhe_balde(int valor_vetor, int maior_num, int menor_num){

    if(maior_num == menor_num)
        return 0;

    //usa a formula pra decidir em qual balde o numero esta
    int balde_destino = floor(NUM_BALDES * (valor_vetor - menor_num) / 
                                            (maior_num - menor_num));

    //conferindo se os indices estão de acordo 

    if(balde_destino >= NUM_BALDES){
        balde_destino = NUM_BALDES - 1;
    }else{
        if(balde_destino < 0){
            balde_destino = 0;
        }
    }

    return balde_destino;
}


void BucketSort(int* vetor, int tam){

    int k = maior_num(vetor,tam);
    int n = menor_num(vetor,tam);

    //criando o vetor de baldes
    no** vetor_baldes = (no**)malloc(sizeof(no*) * NUM_BALDES);

    //preenchendo os ponteiros com NULL
    for(int i = 0; i < NUM_BALDES; i++){
        vetor_baldes[i] = NULL;
    }

    for(int i = 0; i < tam; i++){

        //função que diz pra qual balde o valor vai
        int balde_destino = escolhe_balde(vetor[i], k, n);

        //criando os nos que guardarão os valores encadeados
        no* novo_no = (no*)malloc(sizeof(no));

        //o no recebe o valor
        novo_no->valor = vetor[i];
        // o no->prox aponta pro balde em que ele esta
        novo_no->prox = vetor_baldes[balde_destino];

        //o valor do vetor balde é sempre atualizado com o ultimo valor colocado
        vetor_baldes[balde_destino] = novo_no;
    }

    //realizando ordenação com InsertionSort dentro de cada balde
    for(int i = 0; i < NUM_BALDES; i++){
        vetor_baldes[i] = InsertionSort(vetor_baldes[i]);
    }

    for(int j = 0, i = 0; i < NUM_BALDES; i++){

        no* no_balde = vetor_baldes[i];

        //enquanto o no_balde for diferente de NULL
        while(no_balde){

            //o vetor ordenado recebe os valores dos nos em cada balde
            vetor[j] = no_balde->valor;
            no_balde = no_balde->prox;
            j++; 
        }
    }

}

//====================== Counting Sort ===================================
//========================================================================

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


int main(){

    
    int vetor[20] = {61,42,67,27,17,75,56,93,76,46,63,55,70,59,98,9,7,67,95,90};

    printf("\nVetor desordenado: ");
    imprime(vetor, 20);

    BucketSort(vetor,20);

    printf("\n");

    printf("\nVetor ordenado: ");
    imprime(vetor, 20);
        
    printf("\n\n");

}

