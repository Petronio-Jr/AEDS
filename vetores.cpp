// Petrônio Dias de Carvalho Júnior  2025.1.08.021
// 18/05/2025
// Projeto criado com o objetivo de gerar um vetor com 100 números inteiros e criar um menu de opções que apresente operações que podem ser realizadas
// quantas vezes o usuário desejar.


#include <iostream>
#include <time.h>
using namespace std;

int main() {

	const int TAM = 100; //tamanho do vetor
	int newTAM = TAM;

	srand(time(NULL)); // comando usado para gerar numeros aleatórios no vetor.

	int vetor[TAM];
	int max, min, opcao;
	int i;

	cout << "\n\t\tSeja bem vindo ao meu projeto de análise de vetores inteiros:"; //apresentação inicial
	cout << "\n\t\t-------------------------------------------------------------";
	cout << "\n\n\tInsira 1 para continuar ou 0 para sair.\n"; //condição de saída do codigo
	cin >> opcao;
	cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n"; //linha de separação



	if (opcao != 0) {

		cout << "\nInsira o limite mínimo dos números do vetor: "; //limite minimo dos numeros que serão gerados
		cin >> min;
		cout << "Insira o limite máximo dos números do vetor: ";  //limite máximo dos numeros que serão gerados
		cin >> max;

		for (i = 0; i < TAM; i++) {
			vetor[i] = rand() % (max - min + 1) + min; // comando que gera os numeros para cada casa do vetor
		}
	}
	cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n"; //linha de separação


	while (opcao != 0) {

		cout << "\n\t\tMENU DE OPÇÕES"; // menu
		cout << "\n\n\tO que voce deseja?\n";
		cout << "\n\t1.Exibir vetor";
		cout << "\n\t2.Contar a quantidade de ocorrências que um valor aparece";
		cout << "\n\t3.Contar a quantidade de ocorrências de valores num intervalo";
		cout << "\n\t4.Buscar pela primeira ocorrência de um valor e informar a posição";
		cout << "\n\t5.Excluir a primeira ocorrência de um valor";
		cout << "\n\t6.Inserir um valor numa posição desejada";
		cout << "\n\t7.retirar todos os valores repetidos";
		cout << "\n\t0.Sair\n";
		cin >> opcao;

		switch (opcao) {

			int valor, quant;

		case 1:

			cout << "\nvetor = [";                                                                 
			               
			for (i = 0; i < TAM; i++) {    //exibição do vetor 
				if (vetor[i] >= min && vetor[i] <= max) {
					cout << vetor[i] << ",";
				}
			}

			cout << "]\n";

			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
			break;


		case 2:

			cout << "\n\tQual valor você deseja procurar? ";
			cin >> valor;

			for (i = 0, quant = 0; i < TAM; i++) {   // quando o valor inserido é igual ao valor i do vetor é adicionado +1 à quantidade
				if (valor == vetor[i]) {
					quant++;
				}
			}

			printf("\n\tO valor %d", valor);
			printf(" aparece %d", quant); // exibição de quantas vezes o valor aparece
			printf(" vezes no vetor\n");

			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";

			break;


		case 3:

			int minbusca, maxbusca;

			cout << "\n\tQual o intervalo de busca? ";
			cout << "\n\nLimite mínimo: ";  // limite minimo para a busca
			cin >> minbusca;
			cout << "Limite máximo: ";  // limite máximo para a busca
			cin >> maxbusca;

			for (i = 0, quant = 0; i < TAM; i++) {
				if (vetor[i] >= minbusca && vetor[i] <= maxbusca) {  //quando um valor do vetor é identificado como dentro do intervalo pedido quant aumenta em 1
					quant++;
				}
			}

			printf("\n\tExistem %d", quant); // exibição
			printf(" valores nesse intervalo\n");

			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";

			break;

		case 4:

			int posicao, k;

			cout << "\n\tQual valor você procura? ";
			cin >> valor;

			for (i = 0, k = 0; i < TAM; i++) {      // comparação do valor pedido com os valores no vetor
				if (vetor[i] == valor && k == 0) {  // k usado para garantir que o comando só ocorra uma vez
					posicao = i;
					k++;
				}
			}

			if (k == 0) {
				printf("\n\tEsse valor não aparece nenhuma vez no vetor!\n"); // condição caso o valor não esteja no vetor
			}
			else {

				posicao += 1; // posição 0 = 1º posição, posição 1 = 2° posição...

				printf("\n\tA primeira aparição do número %d", valor);
				printf(" foi na %d", posicao); // exibição
				printf("º posição\n");
			}

			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
			break;

		case 5:
			
			cout << "\n\tQual valor será excluído? ";
			cin >> valor;

			if (valor > max || valor < min) {
				newTAM = newTAM + 1; 
				cout << "\n\tEsse valor não está presente no vetor!\n";
			}

			cout << "\nvetor = [ ";

			for (i = 0, k = 0; i < TAM; i++) {
				if (valor == vetor[i] && k == 0) { // k usado para que o comando só ocorra na primeira vez
					vetor[i] = vetor[i + 1];
					k++;
				}

				if (k != 0) {
					vetor[i] = vetor[i + 1]; //comando que puxa o resto dos elementos para a esquerda
				}

				if (vetor[i] >= min && vetor[i] <= max) { //apenas serão exibidos numeros dentro do intervalo para que o lixo não seja exibido junto
					cout << vetor[i] << ",";
				}
			}
			
			newTAM = newTAM - 1; // o vetor agora possui um elemento a menos

			cout << " ]\n";
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
			break;

		case 6:

			int box, box2;

			if (newTAM == TAM) { // compara o tamanho do vetor com sua quantidade atual de elementos
				cout << "\n\tEssa operação não pode ser realizada pois o vetor está cheio!";

			}
			else {

				cout << "\n\tQual o valor que será inserido? "; // valor que será inserido
				cin >> valor;

				while (valor > max || valor < min) { // condição que checa se ele se encaixa no intervalo de valores do vetor e repete se necessário
					cout << "\nEsse valor não está dentro do limite do vetor! Escolha outro:";
					cout << "\n\n\tQual o valor que será inserido? ";
					cin >> valor;
				}

				cout << "\n\tQual posição ele ocupará? "; // posição que ocupará
				cin >> posicao;

				while (posicao > TAM || posicao < 1) { // condição que confere se a posição existe no vetor e repete se necessário
					cout << "\nO vetor não apresenta essa posição! Escolha outra:";
					cout << "\n\n\tQual posição ele ocupará? ";
					cin >> posicao;
				}

				posicao = posicao - 1; // posição 0 = 1° posição, posição 1 = 2° posição...

				for (i = 0, k = 0; i < TAM; i++) {
					if (posicao == i) {

						box = vetor[i + 1]; // box usado com o propósito de armazenar um valor
						vetor[i + 1] = vetor[i]; // troca de valores
						vetor[i] = valor;
						k++;
						i++;
					}

					if (k != 0) {
						box2 = vetor[i + 1]; // box2 criado para armazenar mais valores
						vetor[i + 1] = box; // troca de valores
						box = box2;
					}
				}

				newTAM = newTAM + 1; // um valor foi adicionado ao vetor

				cout << "\nvetor = [";

				for (i = 0; i < TAM; i++) { // exibição do vetor
					cout << vetor[i] << ",";
				}

				cout << "]\n";
			}
				cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
				break;

		case 7:

			int j;

			box = max + 1; // box representa um numero que será atribuido aos numeros que sairão do vetor

			for (i = 0, k = 0; i < TAM; i++)
			{
				for (j = i + 1; j < TAM; j++) 
				{
					if (vetor[i] == vetor[j] && k == 0) // preservação da primeira aparição de um valor
					{
						vetor[i] = vetor[i + 1];
						k++;
					}
					else 
					{
						if (vetor[i] == vetor[j] && k != 0) // atribuição do valor fora do intervalo nas repetições
						{
							vetor[i] = box;
						}
						else 
						{
							vetor[i] = vetor[i];
						}
					}
				}
			}

			cout << "\nvetor = [";

			for (i = 0; i < TAM; i++) {
				if (vetor[i] <= max && vetor[i] >= min) { // apenas serão exibidos valores dentro dos limites
					cout << vetor[i] << ",";
				}
			}

			cout << "]\n";

			for (i = 0,quant = 0; i < TAM; i++) { 
				if (vetor[i] == box) {           // substituição dos valores com valor box para que o vetor seja preenchido com lixos que poderão ser substituídos
					for (j = i; j < TAM; j++) {
						vetor[j] = vetor[j + 1];
					}
					i--;
					quant++;
				}

			}
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";

			newTAM = newTAM - quant;
			break;

		default:
		    if (opcao != 0) {
			cout << "\n\tComando inválido!\n";
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
               }
		}
	}

	return 0;
}
