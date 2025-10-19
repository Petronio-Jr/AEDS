#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Cria um novo nó na árvore
struct no* novo_no(int item) {
    struct no* temp = (struct no*)malloc(sizeof(struct no));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
 
// Inserir novo nó com determinado
// valor na árvore binária
struct no* inserir(struct no* raiz, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (raiz == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return raiz;
}
 
// Procura por um valor na árvore
struct no* buscar(struct no* raiz, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Valor é maior que a raiz
    if (raiz->valor < valor) {
        return buscar(raiz->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(raiz->esquerda, valor);
}

struct no* remover(struct no** raiz, int valor_busca){

    //se a árvore estiver vazia ou com 1 elemento  retorna NULL
    if(*raiz == NULL){
        return *raiz;
    }

    if((*raiz)->valor == valor_busca){
        
        struct no* ant = *raiz;
        struct no* pont = (*raiz)->esquerda;

        if(pont == NULL){
            //se nao houver filhos à equerda a raiz recebe a parte da direita
            *raiz = (*raiz)->direita;
            return ant;
        }
        else{
            //encontrando o no substituto (um pra esquerda e full direita)
            while(pont->direita != NULL){
                ant = pont;
                pont = pont->direita;
            }

            //reconectando os galhos da árvore
            if(ant == *raiz){
                //se o no substituido for pai e o filho nao tiver filhos esse é o novo pai
                ant->esquerda = pont->esquerda;
            }
            else{
                //se houver algum elemento à direita do que será substituto ele assume seu lugar
                if(pont->esquerda != NULL){
                    ant->direita = pont->esquerda;
                }
                else{
                //se nao houver nenhum elemento à direita esse espaço vira NULL e ele recebe a direita da raiz
                    pont->esquerda = (*raiz)->esquerda;
                    ant->direita = NULL;
                }
            }

            pont->direita = (*raiz)->direita;

            //mudando o ponteiro
           *raiz = pont;
        }
    }
    else{
        //se o valor nao for o buscado ele ve pra qual lado deve avançar e repete a função
        if(valor_busca < (*raiz)->valor)
            return remover(&(*raiz)->esquerda,valor_busca);
        else
            return remover(&(*raiz)->direita,valor_busca);
    }

    return *raiz;
}

// Funções de impressão
void imprime_em_ordem(struct no* raiz){

    if(raiz == NULL) return;

    imprime_em_ordem(raiz->esquerda);

    printf("\n%d",raiz->valor);

    imprime_em_ordem(raiz->direita);
}

void imprime_pre_ordem(struct no* raiz){

    if(raiz == NULL) return;

    printf("\n%d",raiz->valor);

    imprime_pre_ordem(raiz->esquerda);

    imprime_pre_ordem(raiz->direita);
}

void imprime_pos_ordem(struct no* raiz){
    
    if(raiz == NULL) return;

    imprime_pos_ordem(raiz->esquerda);

    imprime_pos_ordem(raiz->direita);

    printf("\n%d",raiz->valor);
}

void imprime_por_nivel(struct no* raiz){ 
    
    if(raiz == NULL) return;

    //criando uma fila de ponteiros pros nos da arvore
    struct no** fila = (struct no**)malloc(sizeof(struct no*) * tam_arvore(raiz));
    //inicio e fim começam em 0
    int inicio = 0, fim = 0;

    //fim recebe a raiz cabeça
    fila[fim++] = raiz;

    while(inicio < fim){
        
        //no que será exibido na tela
        struct no* atual = fila[inicio++];
        printf("\n%d",atual->valor);

        if(atual->esquerda != NULL)
            fila[fim++] = atual->esquerda;
        if(atual->direita != NULL)
            fila[fim++] = atual->direita;
    }

    //liberando a fila alocada
    free(fila);
}

// Função pra contar quantos elementos tem na árvore. 
int tam_arvore(struct no* raiz){ 
 
    if(raiz == NULL) return 0;

    // retorna 1 + tam_arvore(3) + tam_arvore(10) e assim por diante. Se houver valor ele retorna 1 se for nulo retorna 0
    return 1 + tam_arvore(raiz->esquerda) + tam_arvore(raiz->direita);
}

int tam_arvore_esq(struct no* raiz){ 
 
    //começa na raiz à esquerda da principal
    raiz = raiz->esquerda;

    if(raiz == NULL) return 0;

    // retorna 1 + tam_arvore(3) + tam_arvore(10) e assim por diante. Se houver valor ele retorna 1 se for nulo retorna 0
    return 1 + tam_arvore(raiz->esquerda) + tam_arvore(raiz->direita);
}

int tam_arvore_dir(struct no* raiz){ 
 
    //começa na raiz à direita da principal
    raiz = raiz->direita;

    if(raiz == NULL) return 0;

    // retorna 1 + tam_arvore(3) + tam_arvore(10) e assim por diante. Se houver valor ele retorna 1 se for nulo retorna 0
    return 1 + tam_arvore(raiz->esquerda) + tam_arvore(raiz->direita);
}

// Ordena os elementos num vetor
void ordenacao(struct no* raiz, int* vetor_ord, int* indice){

    if(raiz == NULL) return;

    ordenacao(raiz->esquerda,vetor_ord,indice);
    
    // o vetor recebe os elementos de acordo com o percurso em ordem
    vetor_ord[*indice] = raiz->valor;
    (*indice)++;
    
    ordenacao(raiz->direita,vetor_ord,indice);
}

// Constroi a arvore balanceada
struct no* construir_balanceada(int* vetor, int parte_esq, int parte_dir){

    if(parte_esq > parte_dir) return NULL;

    struct no* novo_no = (struct no*)malloc(sizeof(struct no));

    // o meio vai sendo inserido continuamente, como uma busca binaria
    int meio = (parte_esq + parte_dir)/2;

    //o no recebe o elemento do meio 
    novo_no->valor = vetor[meio];
    //o processo se repete para os filhos da esquerda e da direita com um novo valor de meio
    novo_no->esquerda = construir_balanceada(vetor, parte_esq, meio - 1);
    novo_no->direita = construir_balanceada(vetor, meio + 1, parte_dir);

    return novo_no;
}

int main() {

    // Define a árvore como uma estrutura vazia
    struct no* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 8);

    // Insere outros nós
    inserir(root, 7);
    inserir(root, 6);
    inserir(root, 4);
    inserir(root, 1);
    inserir(root, 14);
    inserir(root, 3);
    inserir(root, 2);
    inserir(root, 13);

    // criando vetor ordenado
    int* vetor_ord = (int*)malloc(sizeof(int) * tam_arvore(root));
    int indice = 0;

    ordenacao(root,vetor_ord,&indice);

    // impressão da matriz desbalanceada
    printf("\n\n###### Impressao por nivel da matriz desbalanceada #########\n");
    imprime_por_nivel(root);
    printf("\n\n#########################################################\n");

    printf("\nNumero de elementos na arvore: %d", tam_arvore(root));
    printf("\nNumero de elementos na esquerda da arvore: %d", tam_arvore_esq(root));
    printf("\nNumero de elementos na direita da arvore: %d", tam_arvore_dir(root));
    printf("\n\n-----------------------------------------------------------------------------");

    // nenhum elemento à esquerda e 8 a direita no vetor
    struct no* novo_no = construir_balanceada(vetor_ord,0,tam_arvore(root) - 1);

    // impressão da matriz balanceada
    printf("\n\n###### Impressao por nivel da matriz balanceada #########\n");
    imprime_por_nivel(novo_no);
    printf("\n\n#########################################################\n");

    // imprimindo valor do vetor ordenado
    printf("\nVetor ordenado: [");
    for(int i = 0; i < tam_arvore(root); i++){
        printf(" %d",vetor_ord[i]);
    }
    printf(" ]\n_________________________________________________________\n");

    printf("\nNumero de elementos na arvore balanceada: %d", tam_arvore(novo_no));
    printf("\nNumero de elementos na esquerda da arvore balanceada: %d", tam_arvore_esq(novo_no));
    printf("\nNumero de elementos na direita da arvore balanceada: %d", tam_arvore_dir(novo_no));

    printf("\n\n");

    free(vetor_ord);free(root);free(novo_no);

    return 0;
}