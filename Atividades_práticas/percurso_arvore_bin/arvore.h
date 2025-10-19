#ifndef _H_ARVORE
#define _H_ARVORE

struct no {
    int valor;
    struct no *esquerda, *direita;
};

struct no* novo_no(int item);
struct no* inserir(struct no* no, int valor);
struct no* buscar(struct no* root, int valor);
struct no* remover(struct no** raiz, int valor_busca);

void imprime_em_ordem(struct no* raiz);
void imprime_pre_ordem(struct no* raiz);
void imprime_pos_ordem(struct no* raiz);
int tam_arvore(struct no* raiz);
void imprime_por_nivel(struct no* raiz);

#endif // _H_ARVORE