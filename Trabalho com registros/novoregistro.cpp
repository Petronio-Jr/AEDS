#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream arquivo("entrada.txt"); //comando que abre o arquivo para leitura

struct imovel
{
	string tipo;
	string finalidade;
	string endereco;
	string bairro;
	string cidade;
	int area;
	string valor;
	string iptu;
	int quartos;
	int suites;
	int banheiros;
	int vagas;
	string cozinha;
	string sala;
	string varanda;
	string area_servico;
	string piso;
	string conservacao;
	string armarios;
	string ar_condicionado;
	string aquecedor;
	string ventilador;
};

void lervalores(int tam, imovel linha[]) { //fun��o pra ler o arquivo
	
	for (int i = 0; i < tam; i++) {
		arquivo >> linha[i].tipo;
		arquivo >> linha[i].finalidade;
		arquivo >> linha[i].endereco;
		arquivo >> linha[i].bairro;
		arquivo >> linha[i].cidade;
		arquivo >> linha[i].area;
		arquivo >> linha[i].valor;
		arquivo >> linha[i].iptu;
		arquivo >> linha[i].quartos;
		arquivo >> linha[i].suites;
		arquivo >> linha[i].banheiros;
		arquivo >> linha[i].vagas;
		arquivo >> linha[i].cozinha;
		arquivo >> linha[i].sala;
		arquivo >> linha[i].varanda;
		arquivo >> linha[i].area_servico;
		arquivo >> linha[i].piso;
		arquivo >> linha[i].conservacao;
		arquivo >> linha[i].armarios;
		arquivo >> linha[i].ar_condicionado;
		arquivo >> linha[i].aquecedor;
		arquivo >> linha[i].ventilador;
	}
	arquivo.close();
}

void reescrita(int tam, imovel linha[]) { //fun��o pra alterar o arquivo

	ofstream arquivo("entrada.txt"); //comando ofstream usado para escrever no aquivo 
	
	for (int i = 0; i < tam; i++) {
		arquivo << linha[i].tipo << " ";
		arquivo << linha[i].finalidade << " ";
		arquivo << linha[i].endereco << " ";
		arquivo << linha[i].bairro << " ";
		arquivo << linha[i].cidade << " ";
		arquivo << linha[i].area << " ";
		arquivo << linha[i].valor << " ";
		arquivo << linha[i].iptu << " ";
		arquivo << linha[i].quartos << " ";
		arquivo << linha[i].suites << " ";
		arquivo << linha[i].banheiros << " ";
		arquivo << linha[i].vagas << " ";
		arquivo << linha[i].cozinha << " ";
		arquivo << linha[i].sala << " ";
		arquivo << linha[i].varanda << " ";
		arquivo << linha[i].area_servico << " ";
		arquivo << linha[i].piso << " ";
		arquivo << linha[i].conservacao << " ";
		arquivo << linha[i].armarios << " ";
		arquivo << linha[i].ar_condicionado << " ";
		arquivo << linha[i].aquecedor << " ";
		arquivo << linha[i].ventilador << endl;
	}
	arquivo.close();
}

void detalhes(int i, imovel linha[]) { //fun��o de exibi��o do conte�do das linhas

	cout << "\033[36mIm�vel\033[0m " << i + 1 << "\n\n";
	cout << "\033[36mTipo:\033[0m " << linha[i].tipo << endl;
	cout << "\033[36mFinalidade:\033[0m " << linha[i].finalidade << endl;
	cout << "\033[36mEndere�o:\033[0m " << linha[i].endereco << endl;
	cout << "\033[36mBairro:\033[0m " << linha[i].bairro << endl;
	cout << "\033[36mCidade:\033[0m " << linha[i].cidade << endl;
	cout << "\033[36m�rea:\033[0m " << linha[i].area << endl;
	cout << "\033[36mValor:\033[0m " << linha[i].valor << endl;
	cout << "\033[36mIPTU:\033[0m " << linha[i].iptu << endl;
	cout << "\033[36mQuartos:\033[0m " << linha[i].quartos << endl;
	cout << "\033[36mSu�tes:\033[0m " << linha[i].suites << endl;
	cout << "\033[36mBanheiros:\033[0m " << linha[i].banheiros << endl;
	cout << "\033[36mVagas:\033[0m " << linha[i].vagas << endl;
	cout << "\033[36mCozinha:\033[0m " << linha[i].cozinha << endl;
	cout << "\033[36mSala:\033[0m " << linha[i].sala << endl;
	cout << "\033[36mVaranda:\033[0m " << linha[i].varanda << endl;
	cout << "\033[36m�rea de servi�o:\033[0m " << linha[i].area_servico << endl;
	cout << "\033[36mPiso:\033[0m " << linha[i].piso << endl;
	cout << "\033[36mConserva��o:\033[0m " << linha[i].conservacao << endl;
	cout << "\033[36mArm�rios:\033[0m " << linha[i].armarios << endl;
	cout << "\033[36mAr condicionado:\033[0m " << linha[i].ar_condicionado << endl;
	cout << "\033[36mAquecedor:\033[0m " << linha[i].aquecedor << endl;
	cout << "\033[36mVentilador:\033[0m " << linha[i].ventilador << endl;
}

void novoimovel(int tam, imovel linha[]) { //fun��o que pede as inform��es de um novo im�vel a ser inserido

	cout << "\n------------------------------------------------------------------------------------------------------------\n";
	cout << "\nInsira as informa��es do novo im�vel abaixo:\n\n";

	cout << "\033[36mTipo:\033[0m ";
	cin >> linha[tam].tipo;

	cout << "\033[36mFinalidade:\033[0m ";
	cin >> linha[tam].finalidade;

	cout << "\033[36mEndere�o:\033[0m ";
	cin >> linha[tam].endereco;

	cout << "\033[36mBairro:\033[0m ";
	cin >> linha[tam].bairro;

	cout << "\033[36mCidade:\033[0m ";
	cin >> linha[tam].cidade;

	cout << "\033[36m�rea:\033[0m ";
	cin >> linha[tam].area;

	cout << "\033[36mValor:\033[0m ";
	cin >> linha[tam].valor;

	cout << "\033[36mIPTU:\033[0m ";
	cin >> linha[tam].iptu;

	cout << "\033[36mQuartos:\033[0m ";
	cin >> linha[tam].quartos;

	cout << "\033[36mSu�tes:\033[0m ";
	cin >> linha[tam].suites;

	cout << "\033[36mBanheiros:\033[0m ";
	cin >> linha[tam].banheiros;

	cout << "\033[36mVagas:\033[0m ";
	cin >> linha[tam].vagas;

	cout << "\033[36mCozinha:\033[0m ";
	cin >> linha[tam].cozinha;

	cout << "\033[36mSala:\033[0m ";
	cin >> linha[tam].sala;

	cout << "\033[36mVaranda:\033[0m ";
	cin >> linha[tam].varanda;

	cout << "\033[36m�rea de servi�o:\033[0m ";
	cin >> linha[tam].area_servico;

	cout << "\033[36mPiso:\033[0m ";
	cin >> linha[tam].piso;

	cout << "\033[36mConserva��o:\033[0m ";
	cin >> linha[tam].conservacao;
	
	cout << "\033[36mArm�rios:\033[0m ";
	cin >> linha[tam].armarios;

	cout << "\033[36mAr condicionado:\033[0m ";
	cin >> linha[tam].ar_condicionado;

	cout << "\033[36mAquecedor:\033[0m ";
	cin >> linha[tam].aquecedor;

	cout << "\033[36mVentilador:\033[0m ";
	cin >> linha[tam].ventilador;
}

int main() {

	setlocale(LC_ALL, "pt-BR"); //comando para exibir as palavras com acentua��o correta no terminal

	const int TAM = 100; //vari�vel constante do tamanho
	int newTAM = TAM; //vari�vel que representa o tamanho real do registro

	imovel linha[100];

	if (!arquivo.is_open()) {
		cout << "Algo deu errado na abertura do arquivo!"; //checando se o arquivo foi aberto
		return 1;
	}
	int contador = 0;

	for (int i = 0; i < TAM; i++) {
		if (linha[i].tipo != "0") {
			contador++;
		}
	}

	newTAM = contador;

	lervalores(newTAM, linha); //chamando a fun��o que l� o arquivo 

	int opcao = -1; //op��o � iniciada com um valor diferente de 0
	int i = 0, k = 0;

	cout << "\n\t\t\t\033[36mSeja bem vindo ao programa de registro de im�veis!\033[0m";
	cout << "\n\t\t\t--------------------------------------------------\n\n";

	while (opcao != 0) {

		reescrita(newTAM, linha);

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

		string rua; //usada no case 2
		float valor; //usado no case 3
		int v = 0, a = 0, t = 0; //usado no case 6
		int q1 = 0, q2 = 0;

		switch (opcao) {

		case 1:

			if (newTAM == TAM) { //checa se o arquivo est� cheio
				cout << "\n\tN�o � poss�vel adicionar um novo im�vel pois o registro est� lotado!";
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
			else {
				novoimovel(newTAM, linha); //fun��o que preenche as informa��es do novo im�vel
				newTAM++; 
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}

			break;

		case 2:

			cout << "\n\tQual o nome da rua que ser� buscada? ";
			cin >> rua;
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			for (i = 0, k = 0; i < newTAM; i++) {
				if (rua == linha[i].endereco) { //compara o texto escrito com o nome da rua no arquivo
					k++;
					if (k == 1) {
						cout << "Rua encontrada! Aqui est�o as informa��es referentes aos im�veis dispon�veis:\n\n";

					}
					detalhes(i, linha); //chamando a fun��o detalhes que ir� exibir todas as linhas em que rua � igual a linha.endere�o
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

						for (i = num; i < newTAM - 1; i++) { //inicia apartir do n�mero do imovel escolhido
							linha[i] = linha[i + 1]; //toda a linha do im�vel ser� sobrescrevida pelo sucessor
							linha[newTAM].tipo = "0";
						}
						cout << endl;
						newTAM--; //diminui o tamanho em 1
					}
				}
				else {
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			else { 
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

			if (resp > 3 || resp < 1) { //caso digite uma op��o que n�o exista
				cout << "\nOp��o inv�lida!";
			}

			for (int i = 0; i < newTAM; i++) {

				int valornum = stoi(linha[i].valor); //stoi � uma fun��o que transforma variavel sting em inteiro

				if (resp == 2 && valornum <= valor && linha[i].finalidade == "aluguel") { //analisa a op��o, o valor e a finalidade do im�vel
					k++;
					if (k == 1) {
						cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
						cout << "\n-------------------------------------------------------------\n\n";
					}
					detalhes(i, linha);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
				else {
					if (resp == 3 && valornum <= valor && linha[i].finalidade == "temporada") { //analisa a op��o, o valor e a finalidade do im�vel
						k++;
						if (k == 1) {
							cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
							cout << "\n-------------------------------------------------------------\n\n";
						}
						detalhes(i, linha);
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
					}
					else {
						if (resp == 1 && valornum <= valor && linha[i].finalidade == "venda") { //analisa a op��o, o valor e a finalidade do im�vel
							k++;
							if (k == 1) {
								cout << "\nEsses s�o os im�veis dispon�veis dentro dessa faixa de pre�o!";
								cout << "\n-------------------------------------------------------------\n\n";
							}
							detalhes(i, linha);
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
				if (linha[i].armarios == resp1 && linha[i].ar_condicionado == resp2 && linha[i].aquecedor == resp3 && linha[i].ventilador == resp4) { //s� mostra os im�veis que apresentem especificamente essas caracter�sticas
					if (k == 0) {
						cout << "\nEsses s�o os im�veis dispon�veis que cumprem os requisitos!";
						cout << "\n-----------------------------------------------------------\n\n";
						k++;
					}
					detalhes(i, linha);
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

				if (linha[i].quartos == quant1 && linha[i].suites == quant2) { //analisa quais imoveis cumprem os requisitos
					if (k == 0) {
						cout << "\n------------------------------------------------------------------------------------------------------------\n";
						cout << "Esses s�o os im�veis dispon�veis que cumprem os requisitos!\n\n";
						k++;
					}
					detalhes(i, linha);
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
				if (linha[i].finalidade == "venda") { //busca os im�veis a venda
					v++; //vari�vel de contagem 
				}
				else {
					if (linha[i].finalidade == "aluguel") { //busca os im�veis para alugar
						a++; //vari�vel de contagem
					}
					else {
						if (linha[i].finalidade == "temporada") { //busca os im�veis para temporada
							t++; //vari�vel de contagem
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
				if (linha[i].suites > 0) { //busca os im�veis com pelo menos 1 su�te
					q1++;
				}
				else {
					if (linha[i].piso == "ceramica" && linha[i].sala == "sim") { //busca im�veis com piso de cer�mica e que tem sala
						q2++;
					}

				}
			}
			cout << "\n A porcentagem de im�veis com su�tes � " << (q1 * 100 / newTAM) << "%";
			cout << "\n A porcentagem de im�veis com pisos de cer�mica nas salas � " << (q2 * 100 / newTAM) << "%";
			cout << "\n------------------------------------------------------------------------------------------------------------\n";

			break;

		case 7:

			cout << "\n----------------------------------------------------------------------------------------------------------------\n";

			for (i = 0; i < newTAM; i++) {

				if (linha[i].vagas != 0) { //exibe os im�veis que apresentam vagas (dispon�veis)
					detalhes(i, linha);
					cout << "\n------------------------------------------------------------------------------------------------------------\n";
				}
			}
			break;

		default:
			if (opcao != 0) {
				cout << "\033[1;31m\nComando inv�lido!\033[0m"; //caso seja escolhida alguma op��o inv�lida
				cout << "\n------------------------------------------------------------------------------------------------------------\n";
			}
		}

	}
}