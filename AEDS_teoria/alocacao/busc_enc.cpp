#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {

	int chave; //valor buscado
	int valor; //conteúdo do nó
	struct no_* prox; //endereçamento
} no;

no* ptlista;

no* busca_enc(int valor_busc, no** ant, no** pont) {

	*ant = ptlista; // ant guarda o endereço do endereço de ptlista (endereço do ponteiro ptlista)
	* pont = NULL; // pont guarda ebdereço nulo

	no* ptr = (*ptlista).prox; //ptr vai ter o endereço que leva ao primeiro elemento

	while (ptr != NULL) {
		
		if((*ptr).chave < valor_busc){
		
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

	no* ant, *pont;

	busca_enc((*novo_no).chave, &ant, &pont);

	if (pont == NULL) {
		(*novo_no).prox = (*ant).prox; //ant = &ptr  *ant = conteudo do endereço  (*ant).prox = endereço do no
		(*ant).prox = novo_no; //novo endereço do no é o do novo no
		valor_retorno = 0;
	}
	return valor_retorno;
}

no* remove_enc(int valor_buscado) {

	no* ant, *pont;
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
		printf("\n\tChave: %d",(*ptr).chave);
		printf("\n\tValor: %d", (*ptr).valor);
		ptr = (*ptr).prox;
		printf("\n\n");
	}

}


int main() {

	no* no_lista;
	no* ant, *pont;


	//INSERINDO CONTEÚDO NOS NÓS

	//no 0
	ptlista = (no*)malloc(sizeof(no)); //alocando memória para um nó (do tamanho de no)
	(*ptlista).prox = NULL; //enderçamento

	//no 1
	no_lista = (no*)malloc(sizeof(no));
	(*no_lista).chave = 2;
	(*no_lista).valor = 2;
	(*no_lista).prox = NULL;

	(*ptlista).prox = no_lista; //ptlista->prox do primeiro no recebe o endereço do segundo no

	//no 2
	no_lista = (no*)malloc(sizeof(no));
	(*no_lista).chave = 5;
	(*no_lista).valor = 5;
	(*no_lista).prox = NULL;

	(*(*ptlista).prox).prox = no_lista; //ptlista->prox do primeiro no recebe o endereço do segundo no

	//no 3
	no_lista = (no*)malloc(sizeof(no));
	(*no_lista).chave = 7;
	(*no_lista).valor = 7;
	(*no_lista).prox = NULL;

	(*(*(*ptlista).prox).prox).prox = no_lista;

	printf("\n\tVALORES ARMAZENADOS: 2,5,7\n");
	printf("\n----------------------------------------------------------------------\n");



	//TESTANDO A FUNCAO 

	//busca do numero 2
	printf("\nBusca do numero 2");

	if (busca_enc(2,&ant,&pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	//busca do numero 5
	printf("\nBusca do numero 5");

	if (busca_enc(5, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n", pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	//busca do numero 7
	printf("\nBusca do numero 7");

	if (busca_enc(7, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	//busca do numero 9
	printf("\nBusca do numero 9");

	if (busca_enc(9, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	//busca do numero 1
	printf("\nBusca do numero 1");

	if (busca_enc(1, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	//busca do numero 3
	printf("\nBusca do numero 3");

	if (busca_enc(3, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}



	//TESTANDO INSERCAO DE NOVOS NOS 

	no* novo_no = (no*)malloc(sizeof(no));
	(*novo_no).chave = 3;
	(*novo_no).valor = 3;
	(*novo_no).prox = NULL;

	insere_enc(novo_no);

	printf("\n----------------------------------------------------------------------\n");
	printf("\n\tVALORES ADICIONADOS: 3\n");
	printf("\n----------------------------------------------------------------------\n");

	//busca do numero 3
	printf("\nBusca do numero 3");

	if (busca_enc(3, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n",pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}


	impressao();



	//TESTANDO REMOCAO

	remove_enc(7);

	printf("\n----------------------------------------------------------------------\n");
	printf("\n\tVALORES REMOVIDOS: 7\n");
	printf("\n----------------------------------------------------------------------\n");

	//busca do numero 7
	printf("\nBusca do numero 7");

	if (busca_enc(7, &ant, &pont) != NULL) {
		printf("\nO valor buscado esta no endereco %p!\n", pont);
	}
	else {
		printf("\nO valor nao esta armazenado!\n");
	}

	printf("\n____________________________________\n");


	impressao();

	//LIBERANDO MEMORIA ALOCADA

	free(no_lista); free(novo_no); free(ptlista);
	printf("\n\n");
}

