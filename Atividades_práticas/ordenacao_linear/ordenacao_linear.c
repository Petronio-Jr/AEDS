#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao_linear.h"

#define NUM_BALDES 10

//====================== Funções Auxiliares =====================================================
//===============================================================================================

void imprime(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
}

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

//Função usada pra ordenar dentro dos baldes
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

//====================== Counting Sort ==========================================================
//===============================================================================================

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

//====================== Bucket Sort ============================================================
//===============================================================================================

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

//====================== RadixSort ==============================================================
//===============================================================================================

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
        countSort_digitos(vetor, tam, exp);
    }
}

//===============================================================================================


int main(){

    //vetor teste pra CountingSort (usei os numeros do slide)

    int vetor1[7] = {9,2,3,4,3,2,2};

    printf("\n======================= CountingSort ===================================");
    printf("\n========================================================================\n");

    printf("\nVetor desordenado: ");

    imprime(vetor1,7);  
    printf("\n");

    CountingSort(vetor1,7);

    printf("\nVetor ordenado: ");

    imprime(vetor1,7);
    printf("\n\n");

//===============================================================================================
    
    //vetor teste pra BucketSort (usei os numeros do slide)
    
    int vetor2[20] = {61,42,67,27,17,75,56,93,76,46,63,55,70,59,98,9,7,67,95,90};

    printf("\n======================= BucketSort =====================================");
    printf("\n========================================================================\n");

    printf("\nVetor desordenado: ");
    imprime(vetor2, 20);

    BucketSort(vetor2,20);

    printf("\n");

    printf("\nVetor ordenado: ");
    imprime(vetor2, 20);
        
    printf("\n\n");

//===============================================================================================

    //vetor teste pra RadixSort (usei os numeros do slide + numeros que nao tem 4 digitos pra testar)

    int vetor3[15] = {1513, 5314 ,1216, 480, 952, 3201, 9883, 19159, 5293, 879, 17, 9333, 6, 4059, 2320};

    printf("\n======================= RadixSort ======================================");
    printf("\n========================================================================\n");

    printf("\nVetor desordenado: ");
    imprime(vetor3, 15);

    RadixSort(vetor3, 15);

    printf("\n\n");

    printf("Vetor ordenado: ");
    imprime(vetor3, 15);

    printf("\n\n");

}
