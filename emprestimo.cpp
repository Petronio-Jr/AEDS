/* \User\VARIOUS\OneDrive\Área de Trabalho\Trabalhos Facul\Atividade1           22/03/2025         Petrônio Dias de Carvalho Júnior        AEDS 1 Prática
   Código criado para avaliar a solicitação de um empréstimo bancário.*/

#include <stdio.h>                                                                                         //biblioteca

int main() {

	int idade, //Idade do solicitante
		nome, //Histórico de crédito
		parcela, //Número de parcelas em atraso atualmente
		parcela2; //Número de parcelas em atraso nos últimos 2 anos                   
	float renda; //Renda mensal

	printf("\n\tSistema de Aprovação de Empréstimo. Insira as seguintes informações:\n");                  //frases que serão exibidas em ordem
	printf("\n\tIdade:");                                                                                 //printf usados para exibir uma mensagem
	scanf("%d", &idade);                                                                                //scanf usado para coletar a informação inserida pelo usuário
	printf("\n\tRenda mensal: R$");
	scanf("%f", &renda);
	printf("\n\tNome negativado.(1.Sim  0.Não): ");          
	scanf("%d", &nome);                                                                                //entrada do código
	printf("\n\tNúmero de parcelas em atraso atualmente:");
	scanf("%d", &parcela);
	printf("\n\tNúmero de parcelas em atraso nos últimos 2 anos:");
	scanf("%d", &parcela2);

	if (renda < 2000 || nome == 1 || idade < 18 || idade > 70) {                                        //condições usadas para determinar qual será a saída do código
		printf("\n\tClassificação: Empréstimo Negado\n");                                               //saída esperada caso a condição seja atendida
	}
	else {                                                                                              //else usado antes de cada novo if para otimizar o código
		if (renda >= 2000 && renda < 5000 && parcela <= 2) {                                            //condição 2
			printf("\n\tClassificação: Empréstimo de Baixo Valor (até R$ 5.000,00)\n");                 //saída 2
		}
		else {
			if (renda >= 5000 && renda < 10000 && parcela2 <= 4 && parcela == 0) {                      //condição 3
				printf("\n\tClassificação: Empréstimo de Medio Valor (até R$ 20.000,00)\n");            //saída 3
			}
			else {
				if (renda >= 10000 && parcela2 == 0) {                                                  //condição 4
					printf("\n\tClassificação: Empréstimo de Alto Valor (acima de R$ 20.000,00)\n");   //saída 4
				}
				else {
					printf("\n\tNão e possível realizar um empréstimo com esses dados.\n");             //caso nenhuma das condições sejam atendidas
				}
			}
		}
	}
	return 0;
}