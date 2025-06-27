#include <iostream>
#include "matrizes.h"
using namespace std;

void multnum(Vetor v, float num) {

	for (int i = 0; i < TAM; i++) { //i representa as linhas da matriz
		for (int j = 0; j < TAM; j++) { // j representa as colunas
			int* p = (int*)v + i * TAM + j; // o ponteiro aponta para os elementos consecutivos da linha

			*p = *p * num;
		}
	}
}
