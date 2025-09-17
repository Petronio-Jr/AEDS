#ifndef _H_PILHA
#define _H_PILHA
#include <stdbool.h> //nao tava aceitando o bool então coloquei a biblioteca

struct pilha* criar_pilha();
bool ehVazia(struct pilha* pilha);
void push(struct pilha* pilha, int item);
int pop(struct pilha* pilha);
int obtem_elemento(struct pilha* pilha);

#endif // _H_PILHA