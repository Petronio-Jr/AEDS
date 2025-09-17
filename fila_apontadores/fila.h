#ifndef _H_FILA
#define _H_FILA
#include <stdbool.h>

struct fila_apontada* criar_fila();
bool ehVazia(struct fila_apontada* fila);
void push(struct fila_apontada* fila, int item);
int pop(struct fila_apontada* fila);
int obtem_elemento(struct fila_apontada* fila);

#endif // _H_FILA