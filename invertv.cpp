#include <iostream>
#include "matrizes.h"
using namespace std;

void invertv(Vetor v) {

	for (int i = 0; i < TAM; i++) { //começa na linha 0 e avança até chegar ao fim da matriz	

		int* inicio = (int*)v + i; //o ponteiro inicio aponta para o primeiro elemento da primeira linha e avança sucessivamente
		int* fim = (int*)v + ((TAM - 1) * TAM) + i; //ponto inicial + quant linhas + coluna buscada

		while (inicio < fim) {

			int aux = *inicio;
			*inicio = *fim;
			*fim = aux;

			inicio += TAM; //avança uma linha
			fim -= TAM; //volta uma linha
		}
	}
}