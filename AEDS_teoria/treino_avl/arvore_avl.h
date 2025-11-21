#ifndef _H_ARVORE
#define _H_ARVORE

typedef struct no_{
    int valor;
    struct no_* esq;
    struct no_* dir;
    int altura; 
} no;


int max_(int a, int b);
int fator_balanceamento(no* raiz);
no* rotacao_esq (no* x);
no* rotacao_dir (no* x);
no* busca_avl(no* raiz, int valor);
struct no* buscar(struct no* root, int valor);
struct no* remover(struct no** raiz, int valor_busca);

#endif // _H_ARVORE