//Ordena somente os k primeiros valores do vetor

#include <iostream>
using namespace std;

int main() {

	int v[100] = {
	   57, 3, 89, 72, 14, 38, 91, 8,  44, 62,
	   19, 0,  33, 95, 28, 76, 41, 7,  60, 11,
	   23, 54, 82, 6,  31, 99, 1,  47, 65, 18,
	   13, 90, 5,  87, 32, 61, 77, 9,  37, 55,
	   16, 49, 93, 21, 68, 29, 4,  84, 25, 70,
	   52, 15, 39, 98, 20, 35, 94, 2,  81, 46,
	   26, 73, 58, 12, 40, 83, 17, 71, 34, 56,
	   24, 67, 88, 30, 66, 53, 79, 10, 36, 97,
	   22, 63, 51, 85, 27, 80, 42, 75, 43, 96,
	   45, 59, 64, 74, 69, 86, 48, 92, 78, 50
	};

	int k = 10;

	int i, j, menor, salva;
	for (i = 0; i < k; i++)
	{
		menor = i;
		for (j = i + 1; j < 100; j++)
			if (v[j] < v[menor])
				menor = j;
		salva = v[i];
		v[i] = v[menor];
		v[menor] = salva;
	}

	cout << "vetor = { ";
	for (int* i = v; i < v + 100; i++) {
		cout << *i << " ";
	}
	cout << "}";
}
_______
