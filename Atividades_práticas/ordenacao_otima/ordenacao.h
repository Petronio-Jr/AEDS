#ifndef _H_ORDENACAO_
#define _H_ORDENACAO_

void imprimir(int *vetor);

void bubble(int *vetor, int tam);

int menor_valor(int *vetor, int tam, int inicio);
void selection(int *vetor,int tam);

void insertion(int *vetor,int tam);

void merge(int *vetor, int inicio, int meio, int fim);
void mergeSort(int* vetor, int inicio, int fim);

int particiona(int* vetor, int inicio, int fim);
void quickSort(int *vetor, int inicio, int fim);

#endif // _H_ORDENACAO_