#ifndef lista_enc
#define lista_enc

typedef struct no_ {

	int chave; //valor buscado
	int valor; //conteúdo do nó
	struct no_* prox; //endereçamento
} no;

no* ptlista;

no* busca_enc(int valor_busc, no** ant, no** pont);
int insere_enc(no* novo_no);
no* remove_enc(int valor_buscado);
void impressao();


#endif
