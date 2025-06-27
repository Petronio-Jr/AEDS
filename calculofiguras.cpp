/*Petr�nio Dias de Carvalho J�nior
22/04
C�digo criado com o intuito de calcular a �rea e o volume das figuras apresentadas no arquivo de texto atrav�s das medidas contidas nele
Obs: o aplicativo de programa��o usado n�o exibe corretamente palavras acentuadas e n�o consegui obter acesso ao netbeans na faculdade devido
a uma atualiza��o do sistema, portanto realizei o c�digo sem acentua��o para evitar alguma desaven�a na hora de testar seu funcionamento em outro aplicativo.
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {

	float area, volume;//area e volume totais 
	float x, y, z, pi;
	int base;

	pi = 3;//valor de pi usado nas contas

	ifstream arquivo("figuras.txt");//ifstream usado para ler informa��es no aquivo texto

	if (!arquivo.is_open()) {//caso o arquivo n�o abara essa mensagem ser� exibida
		cout << "\n\tERRO! Arquivo nao encontrado\n";
		return 1;
	}

	area = 0;
	volume = 0;

	string nome;

	while (nome != "Fim") { //condi��o para a repeti��o

		arquivo >> nome;// simbolo >> usado para puxar dados do arquivo de texto

		if (nome == "Quadrado") {//condi��o 1
			arquivo >> x;// vari�vel puxada
			area += (x * x);//calculo da �rea total
			cout << "\n\tArea do Quadrado: " << x * x;//comando de sa�da
		}
		else {
			if (nome == "Retangulo") {//condi��o 2    repeti��o do mesmo padr�o
				arquivo >> x;
				arquivo >> y;
				arquivo >> z;
				area += (y * z);
				cout << "\n\tArea do Retangulo: " << y * z;//sa�da 2
			}
			else {
				if (nome == "Losango") {//condi��o 3
					arquivo >> x;
					arquivo >> y;
					area += ((x * y) / 2);
					cout << "\n\tArea do Losango: " << (x * y) / 2;//sa�da 3
				}
				else {
					if (nome == "Circulo") {//condi��o 4
						arquivo >> x;
						area += (pi * (x * x));
						cout << "\n\tArea do Circulo: " << pi * (x * x);//sa�da 4
					}
					else {
						if (nome == "Coroa_circular") {//condi��o 5
							arquivo >> x;
							arquivo >> y;
							area += (pi * ((x * x) - (y * y)));
							cout << "\n\tArea da coroa circular: " << pi * ((x * x) - (y * y));//sa�da 5

						}
						else {
							if (nome == "Trapezio") {//condi��o 6
								arquivo >> x;
								arquivo >> y;
								arquivo >> z;
								area += ((x + y) * z / 2);
								cout << "\n\tArea do Trapezio: " << ((x + y) * z / 2);//sa�da 6

							}
							else {
								if (nome == "Triangulo") {//condi��o 7
									arquivo >> x;
									arquivo >> y;
									arquivo >> z;
									area += ((y * z) / 2);
									cout << "\n\tArea do Triangulo:" << (y * z) / 2;//sa�da 7

								}
								else {
									if (nome == "Cubo") {//condi��o 8
										arquivo >> x;
										area += 6 * (x * x);
										volume += (x * x * x);
										cout << "\n\tArea do Cubo: " << 6 * (x * x) << "\t\tVolume do Cubo: " << (x * x * x);//sa�da 8

									}
									else {
										if (nome == "Esfera") {//condi��o 9
											arquivo >> x;
											area += (4 * pi * x * x);
											volume += (4 / 3 * (pi * x * x * x));
											cout << "\n\tArea da Esfera: " << 4 * pi * x * x << "\t\tVolume da Esfera: " << (4 / 3) * (pi * x * x * x);//sa�da 9
										}
										else {
											if (nome == "Cone") {//condi��o 10
												arquivo >> x;
												arquivo >> y;
												arquivo >> z;
												area += (pi * x * (x + y));
												volume += ((1 / 3) * pi * x * x * z);
												cout << "\n\tArea do Cone: " << (pi * x) * (x + y) << "\t\tVolume do Cone: " << (((pi * x * x)*z)/3);//sa�da 10
											}
											else {
												if (nome == "Cilindro") {//condi��o 11
													arquivo >> x;
													arquivo >> y;
													arquivo >> z;
													area += ((2 * pi * x * x) + (2 * pi * x * z));
													volume += (pi * x * x * z);
													cout << "\n\tArea do Cilindro: " << (2 * pi * x * x) + (2 * pi * x * z) << "\t\tVolume do Cilindro: " << pi * x * x * z;//sa�da 11

												}
												else {
													if (nome == "Paralelepipedo") {//condi��o 12
														arquivo >> x;
														arquivo >> y;
														arquivo >> z;
														area += ((2 * x * y) + (2 * x * z) + (2 * y * z));
														volume += (x * y * z);
														cout << "\n\tArea do Paralelepipedo: " << ((2 * x * y) + (2 * x * z) + (2 * y * z)) << "\t\tVolume do Paralelepipedo: " << x * y * z;//sa�da 12
													}
													else {
														if (nome == "Piramide") {//condi��o 13
															arquivo >> base;
															arquivo >> x;
															arquivo >> y;
															arquivo >> z;

															if (base == 1) {//ifs adicionais acrescentados para que a piramide possa ser dividida entre triangular e quadrada
																area += (((y * z) / 2) + 3 * ((y * z) / 2));
																volume += ((((y * z) / 2) * z) / 3);
																cout << "\n\tArea da Piramide Triangular: " << ((y * z) / 2) + 3 * ((y * z) / 2) << "\t\tVolume da Piramide Triangular: " << ((((y * z) / 2) * z) / 3);//sa�da 13.1
															}
															if (base == 2) {
																area += ((x * x) + (2 * x * y));
																volume += (((x * x) * z) / 3);
																cout << "\n\tArea da Piramide Quadrada: " << (x * x) + (2 * x * y) << "\t\tVolume da Piramide Quadrada: " << (((x * x) * z) / 3);//sa�da 13.2
															}
														}
													}
												}
											}
										}
									}
								}

							}
						}
					}
				}
			}


		}
	}
	cout << "\n\t___________________________________________________________________";
	cout << "\n\n\tArea total: " << area << "\t\tVolume total: " << volume;
	cout << "\n";
	arquivo.close();
	return 0;
			
}