#include <iostream>
#include "matrizes.h"
using namespace std; 

void inverth(Vetor v) {

	for (int i = 0; i < TAM; i++) { //começa na linha 0 e avança até chegar no fim da matriz

		int* inicio = (int*)v + TAM * i; //endereço da primeira coluna da matriz
		int* fim = inicio + TAM - 1; //endereço da última coluna da linha

		while (inicio < fim) {//só vai ler a linha até a metade (onde eles se encontram)

			int aux = *inicio;
			*inicio = *fim;
			*fim = aux;

			inicio++; //avança pra próxima coluna
			fim--; //volta uma coluna
		}
	}
}
