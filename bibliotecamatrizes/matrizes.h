/* Petr�nio Dias de Carvalho J�nior		2025.1.08.021
* 25/06/2025
* C�digo criado para realizar transforma��es em matrizes usando ponteiros
* Arquico .h que armazena as fun��es criadas em uma biblioteca
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
