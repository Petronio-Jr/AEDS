/* Petrônio Dias de Carvalho Júnior		2025.1.08.021
* 25/06/2025
* Código criado para realizar transformações em matrizes usando ponteiros
* Função que inverte horizontalmente
*/

#include <iostream>
#include "matrizes.h"
using namespace std; 

void inverth(Vetor v) {

	int x = 0, y = 0;
	int* linha = &x;
	int* aux = &y; //ponteiro auxiliar 

	for (*linha = 0; *linha < TAM; (*linha)++) { //começa na linha 0 e avança até chegar no fim da matriz

		int* inicio = &v[*linha][0]; //endereço da primeira coluna
		int* fim = &v[*linha][TAM - 1]; //endereço da última coluna

		while (inicio < fim) {//só vai ler a linha até a metade (onde eles se encontram)

			*aux = *inicio;
			*inicio = *fim;
			*fim = *aux;

			inicio++; //avança pra próxima coluna
			fim--; //volta uma coluna
		}
	}
}