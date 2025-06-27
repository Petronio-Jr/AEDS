/*Petrônio Dias de Carvalho Júnior
22/04
Código criado com o intuito de calcular a área e o volume das figuras apresentadas no arquivo de texto através das medidas contidas nele
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

	ifstream arquivo("figuras.txt");//ifstream usado para ler informações no aquivo texto

	if (!arquivo.is_open()) {//caso o arquivo não abara essa mensagem será exibida
		cout << "\n\tERRO! Arquivo nao encontrado\n";
		return 1;
	}

	area = 0;
	volume = 0;

	string nome;

	while (nome != "Fim") { //condição para a repetição

		arquivo >> nome;// simbolo >> usado para puxar dados do arquivo de texto

		if (nome == "Quadrado") {//condição 1
			arquivo >> x;// variável puxada
			area += (x * x);//calculo da área total
			cout << "\n\tArea do Quadrado: " << x * x;//comando de saída
		}
		else {
			if (nome == "Retangulo") {//condição 2    repetição do mesmo padrão
				arquivo >> x;
				arquivo >> y;
				arquivo >> z;
				area += (y * z);
				cout << "\n\tArea do Retangulo: " << y * z;//saída 2
			}
			else {
				if (nome == "Losango") {//condição 3
					arquivo >> x;
					arquivo >> y;
					area += ((x * y) / 2);
					cout << "\n\tArea do Losango: " << (x * y) / 2;//saída 3
				}
				else {
					if (nome == "Circulo") {//condição 4
						arquivo >> x;
						area += (pi * (x * x));
						cout << "\n\tArea do Circulo: " << pi * (x * x);//saída 4
					}
					else {
						if (nome == "Coroa_circular") {//condição 5
							arquivo >> x;
							arquivo >> y;
							area += (pi * ((x * x) - (y * y)));
							cout << "\n\tArea da coroa circular: " << pi * ((x * x) - (y * y));//saída 5

						}
						else {
							if (nome == "Trapezio") {//condição 6
								arquivo >> x;
								arquivo >> y;
								arquivo >> z;
								area += ((x + y) * z / 2);
								cout << "\n\tArea do Trapezio: " << ((x + y) * z / 2);//saída 6

							}
							else {
								if (nome == "Triangulo") {//condição 7
									arquivo >> x;
									arquivo >> y;
									arquivo >> z;
									area += ((y * z) / 2);
									cout << "\n\tArea do Triangulo:" << (y * z) / 2;//saída 7

								}
								else {
									if (nome == "Cubo") {//condição 8
										arquivo >> x;
										area += 6 * (x * x);
										volume += (x * x * x);
										cout << "\n\tArea do Cubo: " << 6 * (x * x) << "\t\tVolume do Cubo: " << (x * x * x);//saída 8

									}
									else {
										if (nome == "Esfera") {//condição 9
											arquivo >> x;
											area += (4 * pi * x * x);
											volume += (4 / 3 * (pi * x * x * x));
											cout << "\n\tArea da Esfera: " << 4 * pi * x * x << "\t\tVolume da Esfera: " << (4 / 3) * (pi * x * x * x);//saída 9
										}
										else {
											if (nome == "Cone") {//condição 10
												arquivo >> x;
												arquivo >> y;
												arquivo >> z;
												area += (pi * x * (x + y));
												volume += ((1 / 3) * pi * x * x * z);
												cout << "\n\tArea do Cone: " << (pi * x) * (x + y) << "\t\tVolume do Cone: " << (((pi * x * x)*z)/3);//saída 10
											}
											else {
												if (nome == "Cilindro") {//condição 11
													arquivo >> x;
													arquivo >> y;
													arquivo >> z;
													area += ((2 * pi * x * x) + (2 * pi * x * z));
													volume += (pi * x * x * z);
													cout << "\n\tArea do Cilindro: " << (2 * pi * x * x) + (2 * pi * x * z) << "\t\tVolume do Cilindro: " << pi * x * x * z;//saída 11

												}
												else {
													if (nome == "Paralelepipedo") {//condição 12
														arquivo >> x;
														arquivo >> y;
														arquivo >> z;
														area += ((2 * x * y) + (2 * x * z) + (2 * y * z));
														volume += (x * y * z);
														cout << "\n\tArea do Paralelepipedo: " << ((2 * x * y) + (2 * x * z) + (2 * y * z)) << "\t\tVolume do Paralelepipedo: " << x * y * z;//saída 12
													}
													else {
														if (nome == "Piramide") {//condição 13
															arquivo >> base;
															arquivo >> x;
															arquivo >> y;
															arquivo >> z;

															if (base == 1) {//ifs adicionais acrescentados para que a piramide possa ser dividida entre triangular e quadrada
																area += (((y * z) / 2) + 3 * ((y * z) / 2));
																volume += ((((y * z) / 2) * z) / 3);
																cout << "\n\tArea da Piramide Triangular: " << ((y * z) / 2) + 3 * ((y * z) / 2) << "\t\tVolume da Piramide Triangular: " << ((((y * z) / 2) * z) / 3);//saída 13.1
															}
															if (base == 2) {
																area += ((x * x) + (2 * x * y));
																volume += (((x * x) * z) / 3);
																cout << "\n\tArea da Piramide Quadrada: " << (x * x) + (2 * x * y) << "\t\tVolume da Piramide Quadrada: " << (((x * x) * z) / 3);//saída 13.2
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
