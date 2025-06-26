/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes usando ponteiros
* Fun��o que multiplica a matriz
*/

#include <iostream>
#include "matrizes.h"
using namespace std;

void multnum(Vetor v, float num) {

	int x = 0;

	for (int* i = &x; *i < TAM; (*i)++) { //i representa as linhas da matriz
		for (int* p = v[*i]; p < v[*i] + TAM; p++) {   //o ponteiro p aponta para os elementos da linha sucessivamente  
			*p = *p * num;
		}
	}
}