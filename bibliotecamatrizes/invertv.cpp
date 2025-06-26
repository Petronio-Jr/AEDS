/* Petrônio Dias de Carvalho Júnior		2025.1.08.021
* 25/06/2025
* Código criado para realizar transformações em matrizes usando ponteiros
* Função que inverte verticalmente
*/

#include <iostream>
#include "matrizes.h"
using namespace std;

void invertv(Vetor v) {

	int x = 0, y = 0;
	int* coluna = &x;
	int* aux = &y; //ponteiro auxiliar 

	for (*coluna = 0; *coluna < TAM; (*coluna)++) { //começa na linha 0 e avança até chegar ao fim da matriz

		int* inicio = &v[0][*coluna]; //primeira coluna da primeira linha
		int* fim = &v[TAM - 1][*coluna]; //primeira coluna da ultima linha

		while (inicio < fim) { //garante que seja percorrido só até a metade do vetor, onde os endereços se encontram

			*aux = *inicio;
			*inicio = *fim;
			*fim = *aux;

			inicio++; //pula uma linha, modifica o enderaço
			fim--; //retrocede uma linha, modifica o endereço
		}
	}
}