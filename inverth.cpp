#include <iostream>
#include "matrizes.h"
using namespace std; 

void inverth(Vetor v) {

	for (int i = 0; i < TAM; i++) { //come�a na linha 0 e avan�a at� chegar no fim da matriz

		int* inicio = (int*)v + TAM * i; //endere�o da primeira coluna da matriz
		int* fim = inicio + TAM - 1; //endere�o da �ltima coluna da linha

		while (inicio < fim) {//s� vai ler a linha at� a metade (onde eles se encontram)

			int aux = *inicio;
			*inicio = *fim;
			*fim = aux;

			inicio++; //avan�a pra pr�xima coluna
			fim--; //volta uma coluna
		}
	}
}