/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes de TAM = 128 usando ponteiros
* Esse c�digo foi feito para testar o funcionamento das fun��es e da biblioteca criada
*/

#include <iostream>
#include "matrizes.h"
using namespace std;


void exibicao(Vetor v) { //fun��o de exibi��o 

	cout << "Matriz = {";

	int x = 0;
	int* j = &x;

	while (*j < TAM) {
		for (int* p = v[*j]; p < v[*j] + TAM; p++) {
			cout << *p << " ";
		}
		*j = *j + 1;
		if (*j == TAM) {
			cout << "}";
		}
		else {
			cout << "}" << endl << "	 {";
		}
	}
}

	int main() {

		Vetor matriz = { //matriz teste 
		{1, 2, 3, 4},
		{4, 5, 6, 7},
		{7, 8, 9, 10},
		{4, 8, 12, 16}
		};

		exibicao(matriz); cout << "\n\n";
		cout << "-----------------------------------------------------------------------------\n";

		transposta(matriz);
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz x 10";

		multnum(matriz,10); cout << "\n\n";
		exibicao(matriz); cout << "\n\n";
		multnum(matriz, 0.1); //fazendo ela voltar ao normal
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz invertida na vertical";

		invertv(matriz); cout << "\n\n";
		exibicao(matriz); cout << "\n\n";
		invertv(matriz); //fazendo ela voltar ao normal
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz invertida na horizontal";

		inverth(matriz); cout << "\n\n";
		exibicao(matriz); cout << "\n\n";
		inverth(matriz);//fazendo ela voltar ao normal

	}
