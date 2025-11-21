#ifndef _H_ORDENACAO_SIMPLES_
#define _H_ORDENACAO_SIMPLES_

void imprimir(int *vetor);
void bubble(int *vetor, int tam);
int menor_valor(int *vetor, int tam, int inicio); //usado pra selection sort
void selection(int *vetor, int tam);
void insertion(int *vetor, int tam);

#endif // _H_ORDENACAO_SIMPLES_