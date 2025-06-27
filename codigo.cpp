#include <iostream>
#include "matrizes.h"
using namespace std;

void exibicao(Vetor v) { //função de exibição 

	cout << "Matriz = {";

	for (int i = 0 ,k = 0; i < TAM; i++) { //linhas
		for (int j = 0; j < TAM; j++) { //colunas

			int *p = (int*)v + i * TAM + j; //posição dos numeros na matriz
			cout << *p << " ";

		}
		k++;
		if (k == TAM) {

			cout << "}";

		}
		else {
			cout << "}" << endl << "	 {";
		}
	}
}

	int main() {

		int k = 0;

		Vetor m = { //matriz teste de TAM = 4
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
		};

		exibicao(m); cout << "\n\n";
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz Transposta"; cout << "\n\n";

		transposta(m);
		exibicao(m); cout << "\n\n";
		transposta(m);//fazendo ela voltar ao normal
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz x 10";

		multnum(m,10); cout << "\n\n";
		exibicao(m); cout << "\n\n";
		multnum(m, 0.1); //fazendo ela voltar ao normal
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz invertida na vertical";

		invertv(m); cout << "\n\n";
		exibicao(m); cout << "\n\n";
		invertv(m); //fazendo ela voltar ao normal
		cout << "-----------------------------------------------------------------------------\n";

		cout << "Matriz invertida na horizontal";

		inverth(m); cout << "\n\n";
		exibicao(m); cout << "\n\n";
		inverth(m);//fazendo ela voltar ao normal

	}
