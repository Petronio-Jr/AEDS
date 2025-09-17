#ifndef _H_FILA
#define _H_FILA
#include <stdbool.h>

struct fila_circular* criar_fila(int tamanho);
bool ehCheia(struct fila_circular* fila);
bool ehVazia(struct fila_circular* fila);
void push(struct fila_circular* fila, int item);
int pop(struct fila_circular* fila);
int obtem_elemento(struct fila_circular* fila);

#endif // _H_FILA