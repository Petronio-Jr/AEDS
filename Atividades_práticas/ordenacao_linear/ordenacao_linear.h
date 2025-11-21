#ifndef _ORDENACAO_LINEAR_
#define _H_ORDENACAO_SIMPLES_

typedef struct no_{
    int valor;
    struct no_* prox;
}no;

// Auxiliares
void imprime(int *vetor, int tam);
int maior_valor(int* vetor, int tam);
no* InsertionSort(no* no_cabeca);
int maior_num(int* vetor, int tam);
int menor_num(int* vetor, int tam);

// CountSort
void contagem_numeros(int* vetor, int tam, int* vetor_adicional);
void reconstrucao_vetor(int* vetor, int tam, int* vetor_adicional, int k);
void CountingSort(int* vetor, int tamanho);

// BucketSort
int escolhe_balde(int valor_vetor, int maior_num, int menor_num);
void BucketSort(int* vetor, int tam);

// RadixSort
void RadixSort(int *vetor, int tam);
void countSort_digitos(int* vetor, int tam, int exp);

#endif //_ORDENACAO_LINEAR_
