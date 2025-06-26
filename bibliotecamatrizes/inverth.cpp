/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes usando ponteiros
* Fun��o que inverte horizontalmente
*/

#include <iostream>
#include "matrizes.h"
using namespace std; 

void inverth(Vetor v) {

	int x = 0, y = 0;
	int* linha = &x;
	int* aux = &y; //ponteiro auxiliar 

	for (*linha = 0; *linha < TAM; (*linha)++) { //come�a na linha 0 e avan�a at� chegar no fim da matriz

		int* inicio = &v[*linha][0]; //endere�o da primeira coluna
		int* fim = &v[*linha][TAM - 1]; //endere�o da �ltima coluna

		while (inicio < fim) {//s� vai ler a linha at� a metade (onde eles se encontram)

			*aux = *inicio;
			*inicio = *fim;
			*fim = *aux;

			inicio++; //avan�a pra pr�xima coluna
			fim--; //volta uma coluna
		}
	}
}