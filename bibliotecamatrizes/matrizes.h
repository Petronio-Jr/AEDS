/* Petrônio Dias de Carvalho Júnior		2025.1.08.021
* 25/06/2025
* Código criado para realizar transformações em matrizes usando ponteiros
* Arquico .h que armazena as funções criadas em uma biblioteca
*/

#ifndef matrizes
#define matrizes

const int TAM = 4;
typedef int Vetor[TAM][TAM];

void multnum(Vetor v, float num);
void transposta(Vetor v);
void invertv(Vetor v);
void inverth(Vetor v);

#endif 
