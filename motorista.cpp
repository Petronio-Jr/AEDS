#include <stdio.h>
int main() {

	int idade, anos, infr, infrg;

	printf("\n\tPara consultar sua classificacao de motorista, favor preencher os seguintes criterios:\n");
	printf("\n\tIdade:");
	scanf_s("%d", &idade);
	printf("\n\tAnos de habilitacao:");
	scanf_s("%d", &anos);
	printf("\n\tNumero de infracoes nos ultimos 5 anos:");
	scanf_s("%d", &infr);
	printf("\n\tNumero de infracoes graves nos ultimos 2 anos:");
	scanf_s("%d", &infrg);

	if (idade < 18 || idade >= 18 && idade < 22 && anos < 2) {
		printf("\n\tVoce eh um Motorista Inexperiente!\n");
	}
	else {
		if (idade >= 22 && idade <= 65 && anos >= 2 && infrg == 0) {
			printf("\n\tVoce eh um Motorista Regular!\n");
		}
		else {
			if (idade > 21 && infrg > 0 || idade > 65) {
				printf("\n\tVoce eh um Motorista de Risco!\n");
			}
			else {
				if (idade >= 30 && idade <= 60 && anos > 5 && infr == 0 && infrg == 0) {
					printf("\n\tVoce eh um Motorista Seguro!\n");
				}
			}
		}
	}
	return 0;
}