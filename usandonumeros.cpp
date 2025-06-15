#include <iostream>
#include <fstream>
using namespace std;

int main() {

	const int n = 100;

	ifstream arquivo("entrada.txt");

	if (!arquivo.is_open()) {
		cout << "\n\tArquivo nao encontrado.";
		return 1;
	}
    
    int i, numeros[n], quant, opcao,procura; 
    float soma;

	
    cout << "\n\t\tSeja bem vindo ao meu projeto que analisa numeros:";
    cout << "\n\t\t--------------------------------------------------";
    opcao = -1;

    int max, min;

    if (opcao != 0) {

        cout << "\n\n\tEscolha o intervalo dos numeros: " << endl << "\tLimite inferior: ";
        cin >> min;
        cout << "\tLimite superior: ";
        cin >> max;
    }

    while (opcao != 0) {

        cout << "\n\n\t\tMENU DE OPCOES ";
        cout << "\n\n\tO que voce deseja saber?";
        cout << "\n\n\t1.Quantidade de numeros dentro do intervalo ";
        cout << "\n\t2.A media dos numeros";
        cout << "\n\t3.Encontrar a primeira posicao de um valor";
        cout << "\n\t4.Encontrar todas as posicoes de um valor";
        cout << "\n\t5.Alterar os limites do numero";
        cout << "\n\t6.Inverter valores do vetor";
        cout << "\n\t7.Adicionar um valor para todos os elementos do vetor";
        cout << "\n\t8.Adicionar um valor para todos os elementos nao divisiveis por 3";
        cout << "\n\t9.Remover um valor do vetor";
        cout << "\n\t10.Remover a primeira aparição de um valor do vetor";
        cout << "\n\t0.Sair\n";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
        case 1:

            for (i = 1, quant = 0; i <= 100; i++) {

                arquivo >> numeros[i];

                if (numeros[i] >= min && numeros[i] <= max) {
                    cout << " " << numeros[i];
                    quant++;
                }

            }
            cout << "\n\n\tExistem " << quant << " numeros nesse intervalo\n";
            cout << "\n------------------------------------------------------------------------------------------------------------------------------";
            break;

        case 2:

            for (i = 1, soma = 0, quant = 0; i <= 100; i++) {

                arquivo >> numeros[i];

                if (numeros[i] >= min && numeros[i] <= max) {
                    soma += numeros[i];
                    quant++;
                }
            }
            cout << "\n\tA media dos numeros eh " << soma / quant;
            cout << "\n----------------------------------------------------------------------------------------------------------------------------";
            break;

        case 3:

            int x, procura;

            cout << "\n\tQual numero voce quer ver? ";
            cin >> procura;

            for (i = 1, x = 101; i <= 100; i++) {

                arquivo >> numeros[i];

                if (numeros[i] == procura && numeros[i] >= min && numeros[i] <= max && i < x) {
                    x = i;
                }

            }

            if (x != 101) {

                cout << "\n\tAnalisei todos os numeros e descobri que a primeira vez que esse numero apareceu foi na posicao " << x;
                cout << "\n----------------------------------------------------------------------------------------------------------------------------";
            }
            else {


                cout << "\n\tAnalisei todos os numeros e descobri que esse numero nao aparece no intervalo";
                cout << "\n----------------------------------------------------------------------------------------------------------------------------";
            }
            break;

        case 4:

            cout << "\n\tQual numero voce quer ver? ";
            cin >> procura;

            int selecao[100], n, tam;

            for (i = 1, n = 1, tam = 0; i <= 100; i++) {

                arquivo >> numeros[i];

                if (numeros[i] == procura && numeros[i] >= min && numeros[i] <= max) {
                    selecao[n] = i;
                    tam++;
                    n++;
                }
            }
            cout << "\n\tAnalisei todos os numeros e descobri que esse numero apareceu nas posicoes: ";

            for (n = 1; n <= tam; n++) {

                cout << selecao[n] << " ";

            }
            cout << "\n----------------------------------------------------------------------------------------------------------------------------";

            break;

        case 5:

            cout << "\n\tNovo limite minimo: ";
            cin >> min;
            cout << "\tNovo limite maximo: ";
            cin >> max;

            break;

        case 6:

            int box;

            for (i = 1; i <= 100; i++) {

                arquivo >> numeros[i];

                if (i > 50) {
                    numeros[i] = numeros[i];
                }
                else {
                    box = numeros[i];
                    numeros[i] = numeros[101 - i];
                    numeros[101 - i] = box;
                }
                if (numeros[i] <= max && numeros[i] >= min) {
                    cout << " " << numeros[i];
                }
            }
            cout << "\n----------------------------------------------------------------------------------------------------------------------------";

            break;

        case 7:

            int valor;

            cout << "\n\tO valor sera:";
            cout << "\n\n\t1.Somado";
            cout << "\n\t2.Multiplicado\n";
            cin >> opcao;

            switch (opcao) {

            case 1:

                cout << "\n\tQual sera o valor somado? ";
                cin >> valor;
                cout << endl;

                for (i = 1; i <= 100; i++) {

                    arquivo >> numeros[i];

                    if (numeros[i] >= min && numeros[i] <= max) {
                        numeros[i] = numeros[i] + valor;
                        cout << " " << numeros[i];
                    }
                }

                cout << "\n----------------------------------------------------------------------------------------------------------------------------";
                break;
            case 2:

                cout << "\n\tQual sera o valor multiplicado? ";
                cin >> valor;
                cout << endl;

                for (i = 1; i <= 100; i++) {

                    arquivo >> numeros[i];

                    if (numeros[i] >= min && numeros[i] <= max) {
                        numeros[i] = numeros[i] * valor;
                        cout << " " << numeros[i];
                    }
                }
                cout << "\n----------------------------------------------------------------------------------------------------------------------------";

            }
            break;

        case 8:

            cout << "\n\tO valor sera:";
            cout << "\n\n\t1.Somado";
            cout << "\n\t2.Multiplicado\n";
            cin >> opcao;

            switch (opcao) {

            case 1:

                cout << "\n\tQual sera o valor somado? ";
                cin >> valor;
                cout << endl;

                for (i = 1; i <= 100; i++) {

                    arquivo >> numeros[i];

                    if (numeros[i] >= min && numeros[i] <= max && numeros[i] % 3 != 0) {
                        numeros[i] = numeros[i] + valor;
                        cout << " " << numeros[i];
                    }
                    else {
                        if (numeros[i] >= min && numeros[i] <= max && numeros[i]) {
                            numeros[i] = numeros[i];
                            cout << " " << numeros[i];
                        }
                    }
                }

                cout << "\n----------------------------------------------------------------------------------------------------------------------------";
                break;
            case 2:

                cout << "\n\tQual sera o valor multiplicado? ";
                cin >> valor;
                cout << endl;

                for (i = 1; i <= 100; i++) {

                    arquivo >> numeros[i];

                    if (numeros[i] >= min && numeros[i] <= max && numeros[i] % 3 != 0) {
                        numeros[i] = numeros[i] * valor;
                        cout << " " << numeros[i];
                    }
                    else {
                        if (numeros[i] >= min && numeros[i] <= max) {
                            numeros[i] = numeros[i];
                            cout << " " << numeros[i];
                        }
                    }
                }
                cout << "\n----------------------------------------------------------------------------------------------------------------------------";
            }break;

        case 9:
        

            cout << "\n\tQual valor voce deseja remover? ";
            cin >> valor;

                for (i = 1; i <= 100; i++) {

                    arquivo >> numeros[i];

                    if (numeros[i] <= max && numeros[i] >= min && numeros[i] != valor) {
                        numeros[i] = numeros[i];

                        cout << " " << numeros[i];
                    }
                    else {
                        if (numeros[i] > max && numeros[i] < min && numeros[i] == valor) {
                            numeros[i] = 0;
                            cout << " " << numeros[i];
                        }
                    }
                }
            break;

        case 10:

            int k;

            cout << "\n\tQual valor voce deseja remover? ";
            cin >> valor;

            for (i = 1; i <= 100; i++) {

                arquivo >> numeros[i];

                if (numeros[i] <= max && numeros[i] >= min && numeros[i] != valor) {
                    numeros[i] = numeros[i];

                    cout << " " << numeros[i];
                }
                if (numeros[i] > max && numeros[i] < min && numeros[i] == valor) {
                        numeros[i] = 0;
                        valor = 0;
                        cout << " " << numeros[i];
                 
                }
            }

        }
    }

	arquivo.close();
	return 0;
}









