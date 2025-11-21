#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "ordenacao.h"
  
// Imprime um vetor de inteiros
void imprimir(int *vetor) {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

//================================= BubleSort ================================================
//============================================================================================

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

//================================= SelectionSort ============================================
//============================================================================================

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

//================================= InsertionSort ============================================
//============================================================================================

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

//================================= MergeSort ================================================
//============================================================================================

void merge(int *vetor, int inicio, int meio, int fim) {

    // tam = 49 - 0 + 1 = 50
    int tamanho = fim - inicio + 1;

    int p1 = inicio;
    int p2 = meio + 1;

    int x = 0;

    //vetor temporario que vai guardar a ordenação
    int *temp = (int*)malloc(sizeof(int) * tamanho);

    //tanto a parte antes do meio quanto a depois dele vao avançar e ser comparadas
    while(p1 <= meio && p2 <= fim){
        
        //se o valor de p1 for menor ou igual ele vai pro vetor temporário
        if(vetor[p1] <= vetor[p2]){
            temp[x] = vetor[p1];
            p1++;
        }
        else{
            //se o valor de p2 for menor, p2 vai
            temp[x] = vetor[p2];
            p2++;
        }
        x++;
    }

    //conferindo a sobra do vetor antes do meio
    while(p1 <= meio){
        temp[x] = vetor[p1];
        x++; p1++;
    }

    //conferindo a sobra depois do meio
    while(p2 <= fim){
        temp[x] = vetor[p2];
        x++; p2++;
    }

    //tranferindo os valores do vetor temp pro vetor
    for(x = inicio; x <= fim; x++){
        vetor[x] = temp[x - inicio];
    }
    
    //liberando o vetor temporário
    free(temp);
    return;
}

void mergeSort(int* vetor, int inicio, int fim){
    if(inicio < fim){
        //define o meio
        int meio = (inicio + fim)/2;
        //confere, respectivamente, a parte antes e depois do meio
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio + 1,fim);
        //junta tudo
        merge(vetor,inicio,meio,fim);
    }
}

//================================= QuickSort ================================================
//============================================================================================

int particiona(int* vetor, int inicio, int fim){
    
    //esquerda começa no primeiro elemento e fim no ultimo
    int esq = inicio;
    int dir = fim;

    //o pivo inicialmente será o primeiro elemento
    int pivo = vetor[inicio];

    while(esq < dir){
        
        //esquerda avança até achar um valor menor ou igual ao pivo
        while(esq <= fim && vetor[esq] <= pivo){
            esq++;
        }
        //direita retrai até achar um valor maior que o pivo
        while(dir >= 0 && vetor[dir] > pivo){
            dir--;
        }

        //substituindo os valores
        if(esq < dir){
            int aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }

    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;

    return dir;
}

void quickSort(int *vetor, int inicio, int fim) {
    
    if(fim > inicio){
        //o pivo separa o vetor em 2
        int pivo = particiona(vetor,inicio,fim);
        //ordena as partes
        quickSort(vetor,inicio,pivo - 1);
        quickSort(vetor,pivo + 1, fim);
    }
    
    return;
}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10, 22};
    printf("\n\n******************** Escolha seu algoritmo *******************");  
	 printf("\n1.Bubble sort");
	 printf("\n2.Selection sort");
	 printf("\n3.Insertion sort");
     printf("\n4.Merge sort");
     printf("\n5.Quick sort");
     printf("\n0.Sair");
	 printf("\nEntre sua opcao : ");
	 scanf("%d",&n);
	
	 switch(n) {
        case 1: printf("\n");bubble(vetor,50);
			    break;
		case 2: printf("\n");selection(vetor,50);
			    break;
		case 3: printf("\n");insertion(vetor,50);
			    break;
        case 4: printf("\n");mergeSort(vetor,0,49);
                imprimir(vetor);
			    break;
        case 5: printf("\n");quickSort(vetor,0,49);
                imprimir(vetor);
			    break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opcao errada!");
		 	    break;
		}
	} while(1);

  return 0; 
} 