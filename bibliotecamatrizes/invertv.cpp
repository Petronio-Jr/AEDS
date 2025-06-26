/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes usando ponteiros
* Fun��o que inverte verticalmente
*/

#include <iostream>
#include "matrizes.h"
using namespace std;

void invertv(Vetor v) {

	int x = 0, y = 0;
	int* coluna = &x;
	int* aux = &y; //ponteiro auxiliar 

	for (*coluna = 0; *coluna < TAM; (*coluna)++) { //come�a na linha 0 e avan�a at� chegar ao fim da matriz

		int* inicio = &v[0][*coluna]; //primeira coluna da primeira linha
		int* fim = &v[TAM - 1][*coluna]; //primeira coluna da ultima linha

		while (inicio < fim) { //garante que seja percorrido s� at� a metade do vetor, onde os endere�os se encontram

			*aux = *inicio;
			*inicio = *fim;
			*fim = *aux;

			inicio++; //pula uma linha, modifica o endera�o
			fim--; //retrocede uma linha, modifica o endere�o
		}
	}
}