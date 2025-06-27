/* \User\VARIOUS\OneDrive\�rea de Trabalho\Trabalhos Facul\Atividade1           22/03/2025         Petr�nio Dias de Carvalho J�nior        AEDS 1 Pr�tica
   C�digo criado para avaliar a solicita��o de um empr�stimo banc�rio.*/

#include <stdio.h>                                                                                         //biblioteca

int main() {

	int idade, //Idade do solicitante
		nome, //Hist�rico de cr�dito
		parcela, //N�mero de parcelas em atraso atualmente
		parcela2; //N�mero de parcelas em atraso nos �ltimos 2 anos                   
	float renda; //Renda mensal

	printf("\n\tSistema de Aprova��o de Empr�stimo. Insira as seguintes informa��es:\n");                  //frases que ser�o exibidas em ordem
	printf("\n\tIdade:");                                                                                 //printf usados para exibir uma mensagem
	scanf("%d", &idade);                                                                                //scanf usado para coletar a informa��o inserida pelo usu�rio
	printf("\n\tRenda mensal: R$");
	scanf("%f", &renda);
	printf("\n\tNome negativado.(1.Sim  0.N�o): ");          
	scanf("%d", &nome);                                                                                //entrada do c�digo
	printf("\n\tN�mero de parcelas em atraso atualmente:");
	scanf("%d", &parcela);
	printf("\n\tN�mero de parcelas em atraso nos �ltimos 2 anos:");
	scanf("%d", &parcela2);

	if (renda < 2000 || nome == 1 || idade < 18 || idade > 70) {                                        //condi��es usadas para determinar qual ser� a sa�da do c�digo
		printf("\n\tClassifica��o: Empr�stimo Negado\n");                                               //sa�da esperada caso a condi��o seja atendida
	}
	else {                                                                                              //else usado antes de cada novo if para otimizar o c�digo
		if (renda >= 2000 && renda < 5000 && parcela <= 2) {                                            //condi��o 2
			printf("\n\tClassifica��o: Empr�stimo de Baixo Valor (at� R$ 5.000,00)\n");                 //sa�da 2
		}
		else {
			if (renda >= 5000 && renda < 10000 && parcela2 <= 4 && parcela == 0) {                      //condi��o 3
				printf("\n\tClassifica��o: Empr�stimo de Medio Valor (at� R$ 20.000,00)\n");            //sa�da 3
			}
			else {
				if (renda >= 10000 && parcela2 == 0) {                                                  //condi��o 4
					printf("\n\tClassifica��o: Empr�stimo de Alto Valor (acima de R$ 20.000,00)\n");   //sa�da 4
				}
				else {
					printf("\n\tN�o e poss�vel realizar um empr�stimo com esses dados.\n");             //caso nenhuma das condi��es sejam atendidas
				}
			}
		}
	}
	return 0;
}