#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "hash.h"

//variável do tamanho do vetor de itens no hash
int M;

//mesma ideia de uma fila circular 
int hashing(int chave) {
    return (chave % M);
}

struct Hash* criar_hash(int tamanho) {

    M = tamanho;

    //criando o hash
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    //criando a alocação de itens
    hash->items = (struct Item**) malloc(sizeof(struct Item*) * tamanho);

    //preenchendo o vetor com NULL
    for(int i = 0; i < M; i++){ 
        hash->items[i] = NULL;
    }
    return hash;
}

//função pra criar itens
struct Item* cria_item(int valor){
    struct Item *item = (struct Item*)malloc(sizeof(struct Item));  
    item->valor = valor;
    //todo item aponta pra NULL pra indicar onde é o fim da alocação
    item->prox = NULL;   
    return item;
}

/**
 * @param hash tabela hash onde o vetor de ponteiros esta
 * @param item ponteiro pro item  
 * @return inseriu: retorna 0 / não inseriu: retorna -1
 */
int hash_insere(struct Hash* hash, struct Item* item) {

    //se nao houver nada sai
    if(hash == NULL || item == NULL) return -1;

    //calculando o indice em que será inserido
    int indice = hashing(item->valor);
    //variavel que aponta pro primeiro elemento da encadeação 
    struct Item* inicio = hash->items[indice];

    //se o conteudo no indice for nulo a primeira opcao recebe o item
    if(inicio == NULL){
        hash->items[indice] = item;
        return 0;
    }
    //variavel para se deslocar na encadeação
    struct Item* temp = inicio;

    //se a primeira posicao nao for nula ele percorre a lista encadeada para inserir
    while(temp->prox != NULL){
        temp = temp->prox;
    }
    temp->prox = item; 

    return 0;
}

/**
 * @param hash tabela hash onde o vetor de ponteiros esta
 * @param item ponteiro pro item  
 * @return removeu: retorna 0 / não removeu: retorna -1
 */
int hash_remove(struct Hash* hash, struct Item* item) {
    
    //calculando o indice em que será retirado
    int indice = hashing(item->valor);

    if(hash == NULL || item == NULL || hash->items[indice] == NULL) return -1;

    struct Item* atual = hash->items[indice];
    struct Item* ant = NULL; //item anterior ao removido

    while(atual != NULL){
        if(atual->valor == item->valor){
            //se for o primeiro elemento ele recebe o proximo
            if(ant == NULL){
                hash->items[indice] = hash->items[indice]->prox;
            }
            else{
                ant->prox = atual->prox;
                free(atual);
            }
            return 0;
        }
        //ant e atual avançam
        ant = atual;
        atual = atual->prox;
    }
    return -1;
}

/**
 * @param hash tabela hash onde o vetor de ponteiros esta
 * @param item ponteiro pro item
 * @param cont contador pra ver em qual posição da encadeação o item está  
 * @return encontrou: retorna o indice / não encontrou: retorna -1
 */
int busca(struct Hash* hash, struct Item* item, int* cont) {

    int indice = hashing(item->valor);

    //se o hash ou o indice tiver vazio retorna -1
    if(hash == NULL || item == NULL || hash->items[indice] == NULL) return -1;

    struct Item* atual = hash->items[indice];

    //percorre a lista encadeada
    while(atual != NULL){
        if(atual->valor == item->valor){
            return indice;
        }
        atual = atual->prox;
        //soma o contador da lista
        (*cont)++;
    }
    return -1;
}

/**
 * @param hash tabela hash onde o vetor de ponteiros esta 
 * @return retorna o total de itens no hash
 */
int Num_elementos(struct Hash* hash){

    //se a hash for nula nao há nada nela
    if(hash == NULL) return 0;

    //numero total de itens
    int total = 0;

    for(int i = 0; i < M; i++){
        //inicializa busca com o primeiro elemento
        struct Item* busca = hash->items[i];
        //a cada item encontrado é acrescido + 1 e a cada NULL + 0
        if(busca == NULL)
            total += 0;
        else{
            while(busca != NULL){
                total++;
                busca = busca->prox;
            }
        }
    }
    return total;
}

void libera_alocacao(struct Hash* hash){  

    struct Item* removido;
    //percorre o vetor
    for(int i = 0; i < M; i++){
        //se tem algo, salva a posição atual, passa pra proxima e remove a anterior salva
        while(hash->items[i] != NULL){
            removido = hash->items[i];
            hash->items[i] = hash->items[i]->prox;
            free(removido); 
        }
    }
    //tendo liberado todos os items, libera o vetor e o hash
    free(hash->items);
    free(hash);
}

int main() { 
    int n,valor,num;
    /* Cria hash com 10 posições, [1,10] */ 
    struct Hash* hash = criar_hash(10);
    struct Item* item;
    do {
        printf("\n\n\n******************** Escolha a opcao *******************");
        printf("\n1.Inserir item");
        printf("\n2.Remover item");
        printf("\n3.Obter item");
        printf("\n4.Obter numero de itens");
        printf("\n0.Sair");
        printf("\n\nEntre sua opcao : ");
        scanf("%d",&n);
        switch(n) {
            case 1: 
                printf("\nDigite o valor do item ");
                scanf("%d",&valor);
                //criando o item
                item = cria_item(valor);
                //conferindo a inserção
                if(hash_insere(hash, item) == 0) 
                    printf("\nItem inserido com sucesso!");
                else 
                    printf("\nErro na insercao!");
                break;
            case 2: 
                //conferindo se a hash esta vazia
                if(Num_elementos(hash) == 0){
                    printf("\nHash vazia. Nao ha nada para ser removido!");
                    break;
                }
                printf("\nDigite o valor do item ");
                scanf("%d",&valor);
                //criando o item
                item = cria_item(valor);
                //conferindo a remoção
                if(hash_remove(hash, item) == 0) 
                    printf("\nItem removido com sucesso!");
                else 
                    printf("\nItem nao encontrado!");
                break;
            case 3: 
                //conferindo se a hash esta vazia
                if(Num_elementos(hash) == 0){
                    printf("\nHash vazia. Nao ha nada para ser buscado!");
                    break;
                }
                printf("\nDigite o valor do item ");
                scanf("%d",&valor);
                //criando o item
                item = cria_item(valor);
                int cont = 0;
                int indice = busca(hash, item,&cont);
                //conferindo a busca
                if(indice != -1) 
                    //somei +1 ao valor para ser uma ordenação de lista e nao de maquina (começa no 1 e não no 0)
                    printf("\nO item foi localizado na posicao %d do vetor, e na posicao %d da encadeacao",indice + 1,cont + 1);
                else
                    printf("\nO item nao foi localizado no vetor");
                break;
            case 4:
                num = Num_elementos(hash);
                printf("\nHa %d elementos no hash",num);
                break;
            case 0: 
                exit(0);
                break;
            default: 
                printf("\n Opcao errada!");
                break;
            }
    } while(1);

    libera_alocacao(hash);
}