#include <iostream>
#include "matrizes.h"
using namespace std; 

void transposta(Vetor v) {

	for (int i = 0; i < TAM; i++) { //começa na linha 0 
		for (int j = i + 1; j < TAM; j++) { //começa a partir da segunda linha

			int* p = (int*)v + i * TAM + j; //pega o elemento j da linha i
			int* q = (int*)v + j * TAM + i; //pega o elemento i da linha j
			
			int aux = *p;
			*p = *q;
			*q = aux;

		}
	}
}
