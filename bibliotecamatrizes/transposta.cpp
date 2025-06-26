/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes usando ponteiros
* Fun��o que exibe a matriz transposta
*/

#include <iostream>
#include "matrizes.h"
using namespace std; 

void transposta(Vetor v) {

	int x = 0;
	int* linha = &x;

	cout << "Matriz transposta = {";

	for (int* coluna = v[0]; coluna < v[0] + TAM;) { //come�a na linha 0 (v[0]) e coluna 0

		for (*linha = 0; *linha < TAM;) { //a coluna mant�m como 0 mas as linhas variam
			cout << *(v[*linha] + (coluna - v[0])) << " "; //� exibido o VALOR da linha 0 e coluna 0, depois linha 1 coluna 0. O + � usado pra mostrar o deslocamento do ponteiro e o * exibe o valor
			*linha = *linha + 1; //muda de linha
		}

		if (*coluna == TAM) { // exibi��o
			cout << "}";
		}
		else {
			cout << "}" << endl << "		    {";
		}

		coluna++;//muda a coluna
	}
	cout << "\n\n";
}