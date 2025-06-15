#include <iostream>
using namespace std;

void exibicao(int v[], int TAM) {
	cout << "vetor = { ";
	for (int* p = v; p < v + TAM; p++) {
		cout << *p << " ";
	}
	cout << "}";
}
int main() {
	int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 };

int maior = 0, menor = 10000;
int media = 0;
int med[50], smed[50], i = 0, j = 0;

	for (int* p = v; p < v + 50; p++) {
		if (*p > maior) {
			maior = *p;
		}
		else {
			if (*p < menor) {
				menor = *p;
			}
		}
		media += *p;
	}

	media = media / 50;

	int* q = med;
	int* k = smed;

	for (int* p = v; p < v + 50; p++) {
		if (*p >= media) {
			*q = *p;
			q++;
			j++;
		}
		else {
			if (*p < media) {
				*k = *p;
				k++;
				i++;
			}
		}
	}
	

	cout << "Maior valor:" << maior;
	cout << "\nMenor valor:" << menor;
	cout << "\n\nMédia dos valores:" << media;
	cout << "\nValores acima da média:";
	exibicao(med, j);
	cout << "\nValores abaixo da média:";
	exibicao(smed, i);
	cout << "\n\n";
