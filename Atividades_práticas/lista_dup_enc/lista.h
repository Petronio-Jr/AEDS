#ifndef LISTA_DUP
#define LISTA_DUP

typedef struct no_ {
    int data;
    struct no_ *prox;
    struct no_ *ant;
}no;

typedef struct lista_dup_{
    no *frente;
    no *fundo;
}lista_dup;

lista_dup* cria_lista(void);

void inserir_fim(lista_dup* lista, int elemento);
void inserir_inicio(lista_dup* lista, int elemento);

void apagar(lista_dup* lista, int valor_busca);
void apagar_inicio(lista_dup* lista);
void apagar_fim(lista_dup* lista);

bool ehVazia(lista_dup* lista);

int obter_primeiro(lista_dup* lista);
int obter_ultimo(lista_dup* lista);

void imprimir(lista_dup* lista);

void inserirPosicao(lista_dup* lista, int valor, int posicao);
void removerPosicao(lista_dup* lista, int posicao);
int obterPosicao(lista_dup* lista, int posicao);

void liberar_memoria(lista_dup* lista);

#endif // LISTA_DUP