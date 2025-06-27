/*Petrônio Dias de Carvalho Júnior 
22/04
Código criado com o intuito de apresentar um menu para seleção de uma cena gráfica e enviar os dados obtidos para um arquivo de texto
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int newmain() {

	float x, y, z;
	int base;

	ofstream arquivo("figuras.txt");//ofstream usado para lançar informações no arquivo texto
	string nome;//string usado para permitir ao usuário inserir o nome das formas geométricas

	printf("\n\t\t\tInsira a descricao da cena grafica:");

	printf("\n\n*Insira o nome da figura e seus valores correspondentes.");//informações de funcionamento do programa
	printf("\n*Digite os nomes sem acentuacao e com primeira letra maiuscula.");
	
	printf("\n\nOpcoes de figuras 2D:");//menu de opções 2D
	printf("\n\n(Quadrado) (Triangulo) (Retangulo) (Losango) (Circulo) (Coroa_circular) (Trapezio)");
	
	printf("\n\nOpcoes de figuras 3D:");//menu de opções 3D
	printf("\n\n(Cubo) (Piramide) (Esfera) (Cone) (Cilindro) (Paralelepipedo) ");

	printf("\n\n*Digite 'Fim' para sair.");//comando para sair 
	printf("\n*Digite 'Ajuda' para ver as informacoes necessarias de cada figura");
	printf("\n\n------------------------------------------------------------------------------------------------");

	printf("\n\nEspecificacoes: (Insira caso houver)\nValor 1 = (raio, lado, diagonal maior, raio maior, base maior, largura)");//mostra o que cada variável representa nos diferentes casos
	printf("\nValor 2 = (base, diagonal menor, raio menor, base menor, geratriz, apotema, comprimento) ");
	printf("\nValor 3 = (altura)");
	printf("\n\nNome da figura: ");
	cin >> nome;
	arquivo << nome;//lança o nome da figura no arquivo texto

	while (nome != "Fim") {

		if (nome == "Ajuda") {//menu adicional que informa os valores nescessários para o calculo de cada figura
			printf("\nFiguras 2D");
			printf("\n\nQuadrado - necessario o valor do lado");
			printf("\nTriangulo - necessario o valor da base e da altura");
			printf("\nRetangulo - necessario o valor da base e da altura");
			printf("\nLosango - necessario o valor da diagonal maior e da diagonal menor");
			printf("\nCirculo - necessario o valor do raio");
			printf("\nCoroa_circular - necessario o valor do raio maior e do raio menor");
			printf("\nTrapezio - necessario o valor da base maior, base menor e altura");

			printf("\n\nFiguras 3D");
			printf("\n\nCubo - necessario o valor do lado");
			printf("\nEsfera - necessario o valor do raio");
			printf("\nCone - necessario o valor do raio, geratriz e altura");
			printf("\nCilindro - necessario o valor do raio e da altura");
			printf("\nPiramide Triangular - necessario o valor da base e da altura");
			printf("\nPiramide Quadrada - necessario o valor do lado, altura e apotema");
			printf("\nParalelepipedo - necessario o valor do comprimento, largura e altura");

			printf("\n\nNome da figura: ");//comando colocado dentro do while para iniciar a repetição
			cin >> nome;// o usuário deve inserir o nome da forma geométrica de acordo com as instruções apresentadas
			arquivo << endl << nome;
		}
		
		if (nome == "Piramide") {// condição adicional que permite ao usuário escolher entre pirâmides de duas bases distintas
			printf("\n1.Base Triangular");
			printf("\n2.Base Quadrada\n\n");
			scanf("%d", &base);
			arquivo << " " << base;
		}

		printf("\nValor 1: ");// valor que pode representar diferentes informações
		scanf("%f", &x);//variável que assumirá um valor no calculo das áreas e volumes
		arquivo << " " << x;// comando usado para enviar o dado recebido para o arquivo de texto
		printf("Valor 2: ");
		scanf("%f",&y);
		arquivo << " " << y;
		printf("Valor 3: ");
		scanf("%f", &z);
		arquivo << " " << z;

		printf("\n\nNome da figura: ");//comando colocado dentro do while para gerar uma repetição
		cin >> nome;
		arquivo << endl << nome;
	}

	printf("\n\tAcesse o outro codigo para conferir os resultados\n");// resposta final, indica como prosseguir 
		return 0;
}
