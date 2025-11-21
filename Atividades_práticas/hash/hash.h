#ifndef _H_HASH_
#define _H_HASH_

//cada item tem um campo pro valor e um pro endereço do proximo
struct Item {
    int valor;
    struct Item* prox;
};

//criei um vetor de ponteiros pra conseguir distinguir melhor quais espaços estavam ocupados e quais não (NULL)
// e montar as alocações com base em ponteiros provindos do indice que são avançados com ->prox 
struct Hash {
 struct Item** items;   /* vetor de items da hash */
}; 

/* Cria uma hash*/
struct Hash* criar_hash(int tamanho);

/* Cria um item*/
struct Item* cria_item(int valor);

/* Insere um novo elemento na hash */
int hash_insere(struct Hash* hash, struct Item* item);

/* Remove um elemento da hash de acordo com sua chave */
int hash_remove(struct Hash* hash, struct Item* item);

/* Obtém um item da hash */
int busca(struct Hash* hash, struct Item* item, int* cont);

/* Obtém o número de elementos no hash*/
int Num_elementos(struct Hash* hash);

/* Função de hashing */
int hashing(int chave);


#endif // _H_HASH_