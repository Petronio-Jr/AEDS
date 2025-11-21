#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 
#include "ordenacao_simples.h"
  
// Imprime um vetor de inteiros
void imprimir(int *vetor) {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubble(int *vetor, int tam) {
    
    //define a condição de execução
    bool continua = true;

    //so sai do loop quando não for encontrado um valor maior a frente
    while(continua){
        continua = false;
        //percorrendo o vetor
        for(int i = 0; i < tam - 1; i++){
            //compara os elementos consecutivos e os troca se necessário
            if(vetor[i] > vetor[i + 1]){
                int aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                continua = true;
            }
        }
        //ao fim do processo o maior valor será o ultimo logo ele não precisa
        //ser analizado novamente
        tam = tam - 1;
    }

    imprimir(vetor);
    return;
}

int menor_valor(int *vetor, int tam, int inicio){

    //definindo a posição inicial do menor valor
    int min = inicio;

    //comparando os valores do vetor pra identificar a posição do de menor valor
    for(int i = inicio + 1; i < tam; i++){
        if(vetor[min] > vetor[i]){
            min = i;
        }
    }

    return min;
}


void selection(int *vetor, int tam) {
    
    //percorre todo o vetor pegando o maior valor e trocando de posição com i
    for(int inicio = 0; inicio < tam; inicio++){
        int min = menor_valor(vetor, tam, inicio);

        int aux = vetor[inicio];
        vetor[inicio] = vetor[min];
        vetor[min] = aux; 
    }

    imprimir(vetor);
    return;
}

void insertion(int *vetor, int tam) {

    for(int i = 0; i < tam; i++){
        //valor atual usado como base pra comparação
        int valor = vetor[i];
        int j = i;
        //confere todos os elementos já ordenados antes de j e oacha onde o novo valor se encaixa
        while(j > 0 && valor < vetor[j - 1]){
            vetor[j] = vetor[j - 1];
            j--;
        }
        //insere o valor na posição
        vetor[j] = valor;
    }
    imprimir(vetor);
    return;
}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10, 22};
    printf("\n\n\n******************** Escolha seu algoritmo *******************");
	printf("\n1.Bubble sort");
	 printf("\n2.Selection sort");
	 printf("\n3.Insertion sort");
     printf("\n0.Sair");
	 printf("\nEntre sua opção : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: printf("\n"); bubble(vetor, 50);
			    break;
		 case 2: printf("\n"); selection(vetor, 50);
			    break;
		 case 3: printf("\n"); insertion(vetor, 50);
			    break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

  return 0; 
} 