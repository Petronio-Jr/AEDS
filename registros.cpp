// Petrônio Dias de Carvalho Júnior      2025.1.08.021
// Hugo Soares Lopes                     2025.1.08.010
// 07/06/2025
// Código criado com o objetivo de ler e modificar um registro de imóveis e oferecer um menu de fácil interação com o usuário 
// A ideia do código é separar as informações do arquivo imposto em 100 linhas e 22 colunas e alterar o que for preciso especificando onde os dados estão nessa matriz

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream arquivo("entrada.txt"); //comando que abre o arquivo para leitura

struct dadoschar { 
	char inf[22][30]; // armazena 22 dados de até 30 caracteres
};

void valoreschar(int i, int tam, dadoschar linhas[]) { //função pra ler o arquivo

	for (int i = 0; i < tam; i++){
		for (int j = 0; j < 22; j++) {
			arquivo >> linhas[i].inf[j]; // leitura do conteudo do arquivo como char
		}
	}
	arquivo.close();
}

void reescrita(int tam, dadoschar linhas[]) { 

	ofstream arquivo("entrada.txt", ios::trunc); //comando ofstream usado para escrever no aquivo e ios::trunc usado para sobrescrever os dados do arquivo 

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < 22; j++) {
			arquivo << linhas[i].inf[j] << " "; //vai sobrescrever os dados colocando um espaço entre eles
		}
		arquivo << "\n"; //no fim de cada linha ele salta pra próxima
	}
	arquivo.close();
}

void detalhes(int i, dadoschar linhas[]) { //função de exibição do conteúdo das linhas

	cout << "\033[36mImóvel\033[0m " << i + 1 << "\n\n";
	cout << "\033[36mTipo:\033[0m " << linhas[i].inf[0] << endl;
	cout << "\033[36mFinalidade:\033[0m " << linhas[i].inf[1] << endl;
	cout << "\033[36mEndereço:\033[0m " << linhas[i].inf[2] << endl;
	cout << "\033[36mBairro:\033[0m " << linhas[i].inf[3] << endl;
	cout << "\033[36mCidade:\033[0m " << linhas[i].inf[4] << endl;
	cout << "\033[36mÁrea:\033[0m " << linhas[i].inf[5] << endl;
	cout << "\033[36mValor:\033[0m " << linhas[i].inf[6] << endl;
	cout << "\033[36mIPTU:\033[0m " << linhas[i].inf[7] << endl;
	cout << "\033[36mQuartos:\033[0m " << linhas[i].inf[8] << endl;
	cout << "\033[36mSuítes:\033[0m " << linhas[i].inf[9] << endl;
	cout << "\033[36mBanheiros:\033[0m " << linhas[i].inf[10] << endl;
	cout << "\033[36mVagas:\033[0m " << linhas[i].inf[11] << endl;
	cout << "\033[36mCozinha:\033[0m " << linhas[i].inf[12] << endl;
	cout << "\033[36mSala:\033[0m " << linhas[i].inf[13] << endl;
	cout << "\033[36mVaranda:\033[0m " << linhas[i].inf[14] << endl;
	cout << "\033[36mÁrea de serviço:\033[0m " << linhas[i].inf[15] << endl;
	cout << "\033[36mPiso:\033[0m " << linhas[i].inf[16] << endl;
	cout << "\033[36mConservação:\033[0m " << linhas[i].inf[17] << endl;
	cout << "\033[36mArmários:\033[0m " << linhas[i].inf[18] << endl;
	cout << "\033[36mAr condicionado:\033[0m " << linhas[i].inf[19] << endl;
	cout << "\033[36mAquecedor:\033[0m " << linhas[i].inf[20] << endl;
	cout << "\033[36mVentilador:\033[0m " << linhas[i].inf[21] << endl;
}

void novoimovel(int tam, dadoschar linhas[], dadoschar imovel[]) { //função que pede as informções de um novo imóvel a ser inserido

	cout << "\n------------------------------------------------------------------------------------------------------------\n";
	cout << "\nInsira as informações do novo imóvel abaixo:\n\n";

	cout << "\033[36mTipo:\033[0m ";
	cin >> imovel[1].inf[0];

	cout << "\033[36mFinalidade:\033[0m ";
	cin >> imovel[1].inf[1];

	cout << "\033[36mEndereço:\033[0m ";
	cin >> imovel[1].inf[2];

	cout << "\033[36mBairro:\033[0m ";
	cin >> imovel[1].inf[3];

	cout << "\033[36mCidade:\033[0m ";
	cin >> imovel[1].inf[4];

	cout << "\033[36mÁrea:\033[0m ";
	cin >> imovel[1].inf[5];

	cout << "\033[36mValor:\033[0m ";
	cin >> imovel[1].inf[6];

	cout << "\033[36mIPTU:\033[0m ";
	cin >> imovel[1].inf[7];

	cout << "\033[36mQuartos:\033[0m ";
	cin >> imovel[1].inf[8];

	cout << "\033[36mSuítes:\033[0m ";
	cin >> imovel[1].inf[9];

	cout << "\033[36mBanheiros:\033[0m ";
	cin >> imovel[1].inf[10];

	cout << "\033[36mVagas:\033[0m ";
	cin >> imovel[1].inf[11];

	cout << "\033[36mCozinha:\033[0m ";
	cin >> imovel[1].inf[12];

	cout << "\033[36mSala:\033[0m ";
	cin >> imovel[1].inf[13];

	cout << "\033[36mVaranda:\033[0m ";
	cin >> imovel[1].inf[14];

	cout << "\033[36mÁrea de serviço:\033[0m ";
	cin >> imovel[1].inf[15];

	cout << "\033[36mPiso:\033[0m ";
	cin >> imovel[1].inf[16];

	cout << "\033[36mConservação:\033[0m ";
	cin >> imovel[1].inf[17];

	cout << "\033[36mArmários:\033[0m ";
	cin >> imovel[1].inf[18];

	cout << "\033[36mAr condicionado:\033[0m ";
	cin >> imovel[1].inf[19];

	cout << "\033[36mAquecedor:\033[0m ";
	cin >> imovel[1].inf[20];

	cout << "\033[36mVentilador:\033[0m ";
	cin >> imovel[1].inf[21];

	linhas[tam] = imovel[1]; // a linha newTAM será substituída pela linha com os novos valores
}

int main() {
	
	setlocale(LC_ALL, "pt-BR"); //comando para exibir as palavras com acentuação correta no terminal

	const int TAM = 100; //variável constante do tamanho
	int newTAM = TAM; //variável que representa o tamanho real do registro

	if (!arquivo.is_open()) {
		cout << "Algo deu errado na abertura do arquivo!"; //checando se o arquivo foi aberto
		return 1;
	}

	dadoschar linhas[100]; //to fazendo uma matriz que separa por 100 linhas e 22 colunas
	dadoschar imovel[1]; 

	int i = 0;
	int j;

	valoreschar(i, TAM, linhas); //chamando a função que lê o arquivo em char

	int opcao = -1;

	cout << "\n\t\t\t\033[36mSeja bem vindo ao programa de registro de imóveis!\033[0m";
	cout << "\n\t\t\t--------------------------------------------------\n\n";

	while (opcao != 0) {

		reescrita(newTAM, linhas);

		cout << "\n\t\t\033[36mMenu de opções\033[0m";
		cout << "\n\t\t---------------";
		cout << "\n\t\033[36m1.\033[0mAdicionar um imóvel à base de dados";
		cout << "\n\t\033[36m2.\033[0mBuscar um imóvel pela rua";
		cout << "\n\t\033[36m3.\033[0mBuscar imóvel por faixa de valor para locação, aluguel ou temporada";
		cout << "\n\t\033[36m4.\033[0mBuscar imóvel pelas características";
		cout << "\n\t\033[36m5.\033[0mBuscar imóvel pelo número de quartos e suítes ";
		cout << "\n\t\033[36m6.\033[0mRelatório de estatísticas";
		cout << "\n\t\033[36m7.\033[0mListagem dos imóveis disponíveis";
		cout << "\n\t\033[36m0.\033[0mSair\n\n";
		cin >> opcao;

		int k = 1;
		string rua;
		float valor;

		int q1 = 0, q2 = 0;
		int v = 0, a = 0, t = 0;

		switch (opcao) {

		case 1:

			if (newTAM == TAM) { //checa se o arquivo está cheio
				cout << "\n\tNão é possível adicionar um novo imóvel pois o registro está lotado!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			else {
				novoimovel(newTAM, linhas, imovel);
				newTAM++;
				cout << "\n------------------------------------------------------------------------------------------------------------\n";

			}

			break;

		case 2:

			cout << "\n\tQual o nome da rua que será buscada? ";
			cin >> rua;
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0, k = 0; i < newTAM; i++) {
				if (rua == linhas[i].inf[2]) { //os nomes das rua tiveram sua acentuação retirada para que o comando pudesse funcionar
					k++;
					if (k == 1) {
						cout << "Rua encontrada! Aqui estão as informações referentes aos imóveis disponíveis:\n\n";

					}
					detalhes(i, linhas); //chamando a função detalhes que irá exibir todas as linhas em que rua é igual a linhas[i]inf[2]
					cout << "\n------------------------------------------------------------------------------------------------------------\n";

				}
			}

			if (k != 0) { //variável usada para conferir se alguma rua foi encontrada

				int escolha;
				int num;

				cout << "\nDeseja deletar algum desse imóveis? (Digite 1 para sim e 0 para não): ";
				cin >> escolha;

				if (escolha == 1) {

					cout << "\nQual o número do imóvel que será excluído?: ";
					cin >> num;
					num = num - 1; //o imovel 1 é o 0, o 100 é o 99
					cout << "\n------------------------------------------------------------------------------------------------------------\n";

					if (num < 0 || num > 99) { //os imóveis vão de 0 a 99

						cout << "\n\033[1;31mNão há esse imóvel na base de dados!\033[0m";
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
					}
					else {

						for (i = num; i < newTAM; i++) {
							linhas[i] = linhas[i + 1]; //toda a linha do imóvel será sobrescrevida pelo sucessor					
						}
						for (j = 0; j < 22; j++) {
							linhas[newTAM].inf[j][0] = '\0'; //a última linha terá seus dados apagados

						}
						newTAM--;
					}
				}
				else {
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			else{
				cout << "\tA rua não foi encontrada no banco de dados!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 3:

			k = 0;
			int resp;

			cout << "\nQual a faixa de valor procurada?: R$";
			cin >> valor;

			cout << "\nQual a finalidade do imóvel procurado?";
			cout << "\n1.locação";
			cout << "\n2.aluguel";
			cout << "\n3.temporada\n\n";
			cin >> resp;

			if (resp > 3 || resp < 1) {
				cout << "\nOpção inválida!";
			}

			for (int i = 0; i < newTAM; i++) {

				int valornum = stoi(linhas[i].inf[6]);// Comando stoi converte uma variável char para inteiro para então ser comparado ao valor inserido

				if (resp == 2 && valornum <= valor && strcmp(linhas[i].inf[1], "aluguel") == 0) {//Usei o comando strcmp que retorna 0 se as strings forem iguais)
					k++;
					if (k == 1) {
						cout << "\nEsses são os imóveis disponíveis dentro dessa faixa de preço!";
						cout << "\n-------------------------------------------------------------\n\n";
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
				else {
					if (resp == 3 && valornum <= valor && strcmp(linhas[i].inf[1], "temporada") == 0) {
						k++;
						if (k == 1) {
							cout << "\nEsses são os imóveis disponíveis dentro dessa faixa de preço!";
							cout << "\n-------------------------------------------------------------\n\n";
						}
						detalhes(i, linhas);
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
					}
					else {
						if (resp == 1 && valornum <= valor && strcmp(linhas[i].inf[1], "venda") == 0) {
							k++;
							if (k == 1) {
								cout << "\nEsses são os imóveis disponíveis dentro dessa faixa de preço!";
								cout << "\n-------------------------------------------------------------\n\n";
							}
							detalhes(i, linhas);
							cout << "\n------------------------------------------------------------------------------------------------------------\n";
						}
					}
				}
			}

			if (k == 0) { //k usado para conferir se o valor foi encontrado 
				cout << "\nNão há imóveis nessa faixa de preço para locação, aluguel ou temporada!" << endl;
				cout << "\n------------------------------------------------------------------------------------------------------------\n";

			}break;

		case 4:

			char resp1[3], resp2[3], resp3[3], resp4[3];

			cout << "\n\tInsira abaixo os requisitos buscados no imóvel: (responda usando sim ou nao)\n\n";
			cout << "Ármario: ";
			cin >> resp1;
			cout << "Ar condicionado: ";
			cin >> resp2;
			cout << "Aquecedor: ";
			cin >> resp3;
			cout << "Ventilador: ";
			cin >> resp4;
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0, k = 0; i < newTAM; i++) {
				if (strcmp(linhas[i].inf[18],resp1) == 0 && strcmp(linhas[i].inf[19], resp2) == 0 && strcmp(linhas[i].inf[20], resp3) == 0 && strcmp(linhas[i].inf[21], resp4) == 0) { //precisei tirar a acentução das palavras "não" no registro para funcionar
					if (k == 0) {
						cout << "\nEsses são os imóveis disponíveis que cumprem os requisitos!";
						cout << "\n-----------------------------------------------------------\n\n";
						k++;
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			if (k == 0) {
				cout << "\nNão há imóveis disponíveis com esses requisitos!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 5:

			int quant1, quant2;

			cout << "\n\tQual o número de quartos desejado?: ";
			cin >> quant1;
			cout << "\n\tQual o número de suítes desejado?: ";
			cin >> quant2;

			for (i = 0, k = 0; i < newTAM; i++) {

				int quarto = stoi(linhas[i].inf[8]); //stoi transforma a variável char em um inteiro para que ela possa ser comparada 
				int suite = stoi(linhas[i].inf[9]);

				if (quarto == quant1 && suite == quant2) {
					if (k == 0) {
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
						cout << "Esses são os imóveis disponíveis que cumprem os requisitos!\n\n";
						k++;
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			if (k == 0) {
				cout << "\nNão há imóveis disponíveis com esses requisitos!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 6:

			for (int i = 0; i < newTAM; i++) {
				if (strcmp(linhas[i].inf[1], "venda") == 0) { //strcmp foi usado para comparar as strings, se elas forem iguais ele irá retornar 0 e o valor v é acrescido em 1
					v++;
				}
				else {
					if (strcmp(linhas[i].inf[1], "aluguel") == 0) {
						a++;
					}
					else {
						if (strcmp(linhas[i].inf[1], "temporada") == 0) {
							t++;
						}
					}
				}
			}

			cout << "\n\tPorcentagem de imóveis por finalidade e características:\n";
			cout << "\n A porcentagem de imóveis a venda é " << (v * 100 / newTAM) << "%";
			cout << "\n A porcentagem de imóveis para alugar é " << (a * 100 / newTAM) << "%";
			cout << "\n A porcentagem de imóveis para temporada é " << (t * 100 / newTAM) << "%";
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0; i < newTAM; i++) {
				if (stoi(linhas[i].inf[9]) > 0) { //stoi converte char em int para que a comparação possa ser feita
					q1++;
				}
				else {
					if (strcmp(linhas[i].inf[16], "ceramica") == 0 && strcmp(linhas[i].inf[13], "sim") == 0) {
						q2++;
					}

				}
			}
			cout << "\n A porcentagem de imóveis com suítes é " << (q1 * 100 / newTAM) << "%";
			cout << "\n A porcentagem de imóveis com pisos de cerâmica nas salas é " << (q2 * 100 /newTAM) << "%";
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			break;

		case 7:

			cout << "\n----------------------------------------------------------------------------------------------------------------\n";

			for (i = 0; i < newTAM; i++) {

				int vagas = stoi(linhas[i].inf[11]);

				if (vagas != 0) {
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			break;

		default:
			if (opcao != 0) {
				cout << "\033[1;31m\nComando inválido!\033[0m";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
		}
	}
}
