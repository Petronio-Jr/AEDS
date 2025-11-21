#ifndef _H_HEAP_
#define _H_HEAP_

struct Heap {
 int tam;           /* tamanho maximo do heap */
 int indice;           /* proxima posicao disponivel no vetor */
 int* prioridade;   /* vetor das prioridades */
}; 

/* Cria uma heap de prioridades*/
struct Heap* heap_inicializa(int max);

/* Insere um novo elemento na heap */
void heap_insere(struct Heap* heap, int prioridade);

/* Troca os elementos a e b de posição*/
void troca(int* a, int* b);

/* Função auxiliar ao método de inserção */
void corrige_acima(struct Heap* heap, int pos);

/* Remove o elemento de maior prioridade */
int heap_remove(struct Heap* heap);

/* Função auxiliar ao método de remoção */
void corrige_abaixo(int *prios, int atual, int tam);

bool EhCheia(struct Heap* heap);
bool EhVazia(struct Heap* heap);
void imprime(struct Heap* heap, int tam);

#endif // _H_HEAP_