#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"


no* busca_enc(int valor_busc, no** ant, no** pont) {

	*ant = ptlista; // ant guarda o endereço do endereço de ptlista (endereço do ponteiro ptlista)
	*pont = NULL; // pont guarda ebdereço nulo

	no* ptr = (*ptlista).prox; //ptr vai ter o endereço que leva ao primeiro elemento

	while (ptr != NULL) {

		if ((*ptr).chave < valor_busc) {

			*ant = ptr; //ant guarda o endereço de ptr 
			ptr = (*ptr).prox; //ptr passa pro proximo endereço
		}
		else {
			if ((*ptr).chave == valor_busc) {
				*pont = ptr; //pont recebe o endereço de onde o número esta
			}
			ptr = NULL; //se o valor adiante for maior não precisa continuar
		}
	}
	return *pont;
}

int insere_enc(no* novo_no) {

	int valor_retorno = -1;

	no* ant, * pont;

	busca_enc((*novo_no).chave, &ant, &pont);

	if (pont == NULL) {
		(*novo_no).prox = (*ant).prox; //ant = &ptr  *ant = conteudo do endereço  (*ant).prox = endereço do no
		(*ant).prox = novo_no; //novo endereço do no é o do novo no
		valor_retorno = 0;
	}
	return valor_retorno;
}

no* remove_enc(int valor_buscado) {

	no* ant, * pont;
	no* valor_retorno = NULL;

	busca_enc(valor_buscado, &ant, &pont);

	if (pont != NULL) {
		(*ant).prox = (*pont).prox; //(*ant).prox = endereço do no anterior ao eliminado  (*pont).prox = endereço de um no a frente do removido
		valor_retorno = pont;
	}

	return valor_retorno;
}

void impressao() {

	no* ptr = (*ptlista).prox;

	printf("\n\n\tExibicao");
	printf("\n____________________________________\n");

	while (ptr != NULL) {
		printf("\n\tChave: %d", (*ptr).chave);
		printf("\n\tValor: %d", (*ptr).valor);
		ptr = (*ptr).prox;
		printf("\n\n");
	}

}