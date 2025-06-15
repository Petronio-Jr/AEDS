#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int newmain() {
	srand(time(NULL));             //gerando numero aleatório

	ofstream arquivo("entrada.txt");   // comando que permite enviar o numero pra um arquivo.txt
	int max = 1000;
	int min = 0;
	int i;

	for (i = 0; i < 100; i++) {
		int num = rand() % (max - min + 1) + min;    //definindo intervalo minimo e maximo
		arquivo << num << endl ;                     //mandando pro arquivo.txt
	}

	arquivo.close();
	return 0;
}
