// Petr�nio Dias de Carvalho J�nior      2025.1.08.021
// Hugo Soares Lopes                     2025.1.08.010
// 07/06/2025
// C�digo criado com o objetivo de ler e modificar um registro de im�veis e oferecer um menu de f�cil intera��o com o usu�rio 
// A ideia do c�digo � separar as informa��es do arquivo imposto em 100 linhas e 22 colunas e alterar o que for preciso especificando onde os dados est�o nessa matriz

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream arquivo("entrada.txt"); //comando que abre o arquivo para leitura

struct dadoschar { 
	char inf[22][30]; // armazena 22 dados de at� 30 caracteres
};

void valoreschar(int i, int tam, dadoschar linhas[]) { //fun��o pra ler o arquivo

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
			arquivo << linhas[i].inf[j] << " "; //vai sobrescrever os dados colocando um espa�o entre eles
		}
		arquivo << "\n"; //no fim de cada linha ele salta pra pr�xima
	}
	arquivo.close();
}

void detalhes(int i, dadoschar linhas[]) { //fun��o de exibi��o do conte�do das linhas

	cout << "\033[36mIm�vel\033[0m " << i + 1 << "\n\n";
	cout << "\033[36mTipo:\033[0m " << linhas[i].inf[0] << endl;
	cout << "\033[36mFinalidade:\033[0m " << linhas[i].inf[1] << endl;
	cout << "\033[36mEndere�o:\033[0m " << linhas[i].inf[2] << endl;
	cout << "\033[36mBairro:\033[0m " << linhas[i].inf[3] << endl;
	cout << "\033[36mCidade:\033[0m " << linhas[i].inf[4] << endl;
	cout << "\033[36m�rea:\033[0m " << linhas[i].inf[5] << endl;
	cout << "\033[36mValor:\033[0m " << linhas[i].inf[6] << endl;
	cout << "\033[36mIPTU:\033[0m " << linhas[i].inf[7] << endl;
	cout << "\033[36mQuartos:\033[0m " << linhas[i].inf[8] << endl;
	cout << "\033[36mSu�tes:\033[0m " << linhas[i].inf[9] << endl;
	cout << "\033[36mBanheiros:\033[0m " << linhas[i].inf[10] << endl;
	cout << "\033[36mVagas:\033[0m " << linhas[i].inf[11] << endl;
	cout << "\033[36mCozinha:\033[0m " << linhas[i].inf[12] << endl;
	cout << "\033[36mSala:\033[0m " << linhas[i].inf[13] << endl;
	cout << "\033[36mVaranda:\033[0m " << linhas[i].inf[14] << endl;
	cout << "\033[36m�rea de servi�o:\033[0m " << linhas[i].inf[15] << endl;
	cout << "\033[36mPiso:\033[0m " << linhas[i].inf[16] << endl;
	cout << "\033[36mConserva��o:\033[0m " << linhas[i].inf[17] << endl;
	cout << "\033[36mArm�rios:\033[0m " << linhas[i].inf[18] << endl;
	cout << "\033[36mAr condicionado:\033[0m " << linhas[i].inf[19] << endl;
	cout << "\033[36mAquecedor:\033[0m " << linhas[i].inf[20] << endl;
	cout << "\033[36mVentilador:\033[0m " << linhas[i].inf[21] << endl;
}

void novoimovel(int tam, dadoschar linhas[], dadoschar imovel[]) { //fun��o que pede as inform��es de um novo im�vel a ser inserido

	cout << "\n------------------------------------------------------------------------------------------------------------\n";
	cout << "\nInsira as informa��es do novo im�vel abaixo:\n\n";

	cout << "\033[36mTipo:\033[0m ";
	cin >> imovel[1].inf[0];

	cout << "\033[36mFinalidade:\033[0m ";
	cin >> imovel[1].inf[1];

	cout << "\033[36mEndere�o:\033[0m ";
	cin >> imovel[1].inf[2];

	cout << "\033[36mBairro:\033[0m ";
	cin >> imovel[1].inf[3];

	cout << "\033[36mCidade:\033[0m ";
	cin >> imovel[1].inf[4];

	cout << "\033[36m�rea:\033[0m ";
	cin >> imovel[1].inf[5];

	cout << "\033[36mValor:\033[0m ";
	cin >> imovel[1].inf[6];

	cout << "\033[36mIPTU:\033[0m ";
	cin >> imovel[1].inf[7];

	cout << "\033[36mQuartos:\033[0m ";
	cin >> imovel[1].inf[8];

	cout << "\033[36mSu�tes:\033[0m ";
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

	cout << "\033[36m�rea de servi�o:\033[0m ";
	cin >> imovel[1].inf[15];

	cout << "\033[36mPiso:\033[0m ";
	cin >> imovel[1].inf[16];

	cout << "\033[36mConserva��o:\033[0m ";
	cin >> imovel[1].inf[17];

	cout << "\033[36mArm�rios:\033[0m ";
	cin >> imovel[1].inf[18];

	cout << "\033[36mAr condicionado:\033[0m ";
	cin >> imovel[1].inf[19];

	cout << "\033[36mAquecedor:\033[0m ";
	cin >> imovel[1].inf[20];

	cout << "\033[36mVentilador:\033[0m ";
	cin >> imovel[1].inf[21];

	linhas[tam] = imovel[1]; // a linha newTAM ser� substitu�da pela linha com os novos valores
}

int main() {
	
	setlocale(LC_ALL, "pt-BR"); //comando para exibir as palavras com acentua��o correta no terminal

	const int TAM = 100; //vari�vel constante do tamanho
	int newTAM = TAM; //vari�vel que representa o tamanho real do registro

	if (!arquivo.is_open()) {
		cout << "Algo deu errado na abertura do arquivo!"; //checando se o arquivo foi aberto
		return 1;
	}

	dadoschar linhas[100]; //to fazendo uma matriz que separa por 100 linhas e 22 colunas
	dadoschar imovel[1]; 

	int i = 0;
	int j;

	valoreschar(i, TAM, linhas); //chamando a fun��o que l� o arquivo em char

	int opcao = -1;

	cout << "\n\t\t\t\033[36mSeja bem vindo ao programa de registro de im�veis!\033[0m";
	cout << "\n\t\t\t--------------------------------------------------\n\n";

	while (opcao != 0) {

		reescrita(newTAM, linhas);

		cout << "\n\t\t\033[36mMenu de op��es\033[0m";
		cout << "\n\t\t---------------";
		cout << "\n\t\033[36m1.\033[0mAdicionar um im�vel � base de dados";
		cout << "\n\t\033[36m2.\033[0mBuscar um im�vel pela rua";
		cout << "\n\t\033[36m3.\033[0mBuscar im�vel por faixa de valor para loca��o, aluguel ou temporada";
		cout << "\n\t\033[36m4.\033[0mBuscar im�vel pelas caracter�sticas";
		cout << "\n\t\033[36m5.\033[0mBuscar im�vel pelo n�mero de quartos e su�tes ";
		cout << "\n\t\033[36m6.\033[0mRelat�rio de estat�sticas";
		cout << "\n\t\033[36m7.\033[0mListagem dos im�veis dispon�veis";
		cout << "\n\t\033[36m0.\033[0mSair\n\n";
		cin >> opcao;

		int k = 1;
		string rua;
		float valor;

		int q1 = 0, q2 = 0;
		int v = 0, a = 0, t = 0;

		switch (opcao) {

		case 1:

			if (newTAM == TAM) { //checa se o arquivo est� cheio
				cout << "\n\tN�o � poss�vel adicionar um novo im�vel pois o registro est� lotado!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			else {
				novoimovel(newTAM, linhas, imovel);
				newTAM++;
				cout << "\n------------------------------------------------------------------------------------------------------------\n";

			}

			break;

		case 2:

			cout << "\n\tQual o nome da rua que ser� buscada? ";
			cin >> rua;
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0, k = 0; i < newTAM; i++) {
				if (rua == linhas[i].inf[2]) { //os nomes das rua tiveram sua acentua��o retirada para que o comando pudesse funcionar
					k++;
					if (k == 1) {
						cout << "Rua encontrada! Aqui est�o as informa��es referentes aos im�veis dispon�veis:\n\n";

					}
					detalhes(i, linhas); //chamando a fun��o detalhes que ir� exibir todas as linhas em que rua � igual a linhas[i]inf[2]
					cout << "\n------------------------------------------------------------------------------------------------------------\n";

				}
			}

			if (k != 0) { //vari�vel usada para conferir se alguma rua foi encontrada

				int escolha;
				int num;

				cout << "\nDeseja deletar algum desse im�veis? (Digite 1 para sim e 0 para n�o): ";
				cin >> escolha;

				if (escolha == 1) {

					cout << "\nQual o n�mero do im�vel que ser� exclu�do?: ";
					cin >> num;
					num = num - 1; //o imovel 1 � o 0, o 100 � o 99
					cout << "\n------------------------------------------------------------------------------------------------------------\n";

					if (num < 0 || num > 99) { //os im�veis v�o de 0 a 99

						cout << "\n\033[1;31mN�o h� esse im�vel na base de dados!\033[0m";
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
					}
					else {

						for (i = num; i < newTAM; i++) {
							linhas[i] = linhas[i + 1]; //toda a linha do im�vel ser� sobrescrevida pelo sucessor					
						}
						for (j = 0; j < 22; j++) {
							linhas[newTAM].inf[j][0] = '\0'; //a �ltima linha ter� seus dados apagados

						}
						newTAM--;
					}
				}
				else {
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			else{
				cout << "\tA rua n�o foi encontrada no banco de dados!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 3:

			k = 0;
			int resp;

			cout << "\nQual a faixa de valor procurada?: R$";
			cin >> valor;

			cout << "\nQual a finalidade do im�vel procurado?";
			cout << "\n1.loca��o";
			cout << "\n2.aluguel";
			cout << "\n3.temporada\n\n";
			cin >> resp;

			if (resp > 3 || resp < 1) {
				cout << "\nOp��o inv�lida!";
			}

			for (int i = 0; i < newTAM; i++) {

				int valornum = stoi(linhas[i].inf[6]);// Comando stoi converte uma vari�vel char para inteiro para ent�o ser comparado ao valor inserido

				if (resp == 2 && valornum <= valor && strcmp(linhas[i].inf[1], "aluguel") == 0) {//Usei o comando strcmp que retorna 0 se as strings forem iguais)
					k++;
					if (k == 1) {
						cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
						cout << "\n-------------------------------------------------------------\n\n";
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
				else {
					if (resp == 3 && valornum <= valor && strcmp(linhas[i].inf[1], "temporada") == 0) {
						k++;
						if (k == 1) {
							cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
							cout << "\n-------------------------------------------------------------\n\n";
						}
						detalhes(i, linhas);
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
					}
					else {
						if (resp == 1 && valornum <= valor && strcmp(linhas[i].inf[1], "venda") == 0) {
							k++;
							if (k == 1) {
								cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
								cout << "\n-------------------------------------------------------------\n\n";
							}
							detalhes(i, linhas);
							cout << "\n------------------------------------------------------------------------------------------------------------\n";
						}
					}
				}
			}

			if (k == 0) { //k usado para conferir se o valor foi encontrado 
				cout << "\nN�o h� im�veis nessa faixa de pre�o para loca��o, aluguel ou temporada!" << endl;
				cout << "\n------------------------------------------------------------------------------------------------------------\n";

			}break;

		case 4:

			char resp1[3], resp2[3], resp3[3], resp4[3];

			cout << "\n\tInsira abaixo os requisitos buscados no im�vel: (responda usando sim ou nao)\n\n";
			cout << "�rmario: ";
			cin >> resp1;
			cout << "Ar condicionado: ";
			cin >> resp2;
			cout << "Aquecedor: ";
			cin >> resp3;
			cout << "Ventilador: ";
			cin >> resp4;
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0, k = 0; i < newTAM; i++) {
				if (strcmp(linhas[i].inf[18],resp1) == 0 && strcmp(linhas[i].inf[19], resp2) == 0 && strcmp(linhas[i].inf[20], resp3) == 0 && strcmp(linhas[i].inf[21], resp4) == 0) { //precisei tirar a acentu��o das palavras "n�o" no registro para funcionar
					if (k == 0) {
						cout << "\nEsses s�o os im�veis dispon�veis que cumprem os requisitos!";
						cout << "\n-----------------------------------------------------------\n\n";
						k++;
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			if (k == 0) {
				cout << "\nN�o h� im�veis dispon�veis com esses requisitos!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 5:

			int quant1, quant2;

			cout << "\n\tQual o n�mero de quartos desejado?: ";
			cin >> quant1;
			cout << "\n\tQual o n�mero de su�tes desejado?: ";
			cin >> quant2;

			for (i = 0, k = 0; i < newTAM; i++) {

				int quarto = stoi(linhas[i].inf[8]); //stoi transforma a vari�vel char em um inteiro para que ela possa ser comparada 
				int suite = stoi(linhas[i].inf[9]);

				if (quarto == quant1 && suite == quant2) {
					if (k == 0) {
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
						cout << "Esses s�o os im�veis dispon�veis que cumprem os requisitos!\n\n";
						k++;
					}
					detalhes(i, linhas);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			if (k == 0) {
				cout << "\nN�o h� im�veis dispon�veis com esses requisitos!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			break;

		case 6:

			for (int i = 0; i < newTAM; i++) {
				if (strcmp(linhas[i].inf[1], "venda") == 0) { //strcmp foi usado para comparar as strings, se elas forem iguais ele ir� retornar 0 e o valor v � acrescido em 1
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

			cout << "\n\tPorcentagem de im�veis por finalidade e caracter�sticas:\n";
			cout << "\n A porcentagem de im�veis a venda � " << (v * 100 / newTAM) << "%";
			cout << "\n A porcentagem de im�veis para alugar � " << (a * 100 / newTAM) << "%";
			cout << "\n A porcentagem de im�veis para temporada � " << (t * 100 / newTAM) << "%";
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0; i < newTAM; i++) {
				if (stoi(linhas[i].inf[9]) > 0) { //stoi converte char em int para que a compara��o possa ser feita
					q1++;
				}
				else {
					if (strcmp(linhas[i].inf[16], "ceramica") == 0 && strcmp(linhas[i].inf[13], "sim") == 0) {
						q2++;
					}

				}
			}
			cout << "\n A porcentagem de im�veis com su�tes � " << (q1 * 100 / newTAM) << "%";
			cout << "\n A porcentagem de im�veis com pisos de cer�mica nas salas � " << (q2 * 100 /newTAM) << "%";
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
				cout << "\033[1;31m\nComando inv�lido!\033[0m";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
		}
	}
}
