#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    int chave;
    struct no_ prox;
    struct no_ ant;
}no;

//Alocação sequencial lista desordenada
int busca1(no L[], int valor_busca, int tam){
    int retorno = 0;
    for(int i = 0; i <= tam;){
        if(L[i].chave == valor_busca){
            retorno = i;
            i = tam + 1;
        }
        else{
            i++;
        }
    }
    return retorno;
}

int busca(no L[], int valor_busca, int tam){
    L[tam + 1].chave = valor_busca;
    int i = 0;

    while(L[i].chave != valor_busca){
        i++;
    }
    if(i != tam + 1){
        return i;
    }
    return 0;
}

int insere(no L[], no novo_no, int tam_atual, int tam_max){
    if(tam_atual < tam_max){
        if(busca(L,novo_no.chave,tam_max) == 0){
            L[tam_atual + 1] = novo_no;
            tam_atual++;
            return tam_atual;
        }
        else{
            return 0;
        }
    }
    return -1;
}

no remove(no L[], int valor_busca, int tam_atual, int tam_max){
    no* remove = NULL;
    if(tam_atual != 0){
        int indice = busca(L,valor_busca,tam_max);
        if(indice != 0){
            *remove = L[indice];
            for(int i = indice; i < tam_max - 1;){
                L[i] = L[i + 1];
            }
            tam_atual--;
        }
    }
    return *remove;
}

int insere_pilha(no P[], no novo_no, int tam_max, int topo){
    if(topo != tam_max){
        topo++;
        P[topo] = novo_no;
        return topo;
    }
    return -1;
}

no remove_pilha(no P[], int topo, int tam_max){
    no *remove = NULL;
    if(topo != 0){
        *remove = P[topo];
        topo--;
    }
    return *remove;
}

int insere_lista(no L[], int *r, int *f, int M, no d){
    int prov = (*r + 1) % M;

    if(prov != *f){  
        *r = prov;
        L[*r] = d;
        return *r;
    }

    if(*f == -1){
        *f = 0;
    }
    return -1;
}

no remove_lista(no L[], int *r, int *f, int M){

    no* retorno = NULL;

    if(*f != -1){
        *retorno = L[*f];
        if(*f == *r){
            *f = *r = -1;
        }
        else{
            *f = (*f + 1) % M;
        }
    }

    return *retorno;
}

//Alocação sequencial em lista ordenada

int busca_ord(no L[], int valor_busca, int tam){
    L[tam + 1].chave = valor_busca;
    int i = 0;

    while(L[i].chave < valor_busca){
        i++;
    }

    if(i != tam + 1 || L[i].chave != valor_busca){
        return 0;
    }
    else{
        return i;
    }
}

int busca_bin(no L[], int valor_busca, int tam){
    int inf = 0, sup = tam;
    
    while(inf <= sup){
        int meio = (inf + sup)/2;
        if(L[meio].chave < valor_busca){
            inf = meio + 1;
        }
        else{
            if(L[meio].chave == valor_busca){
                return meio;
                inf = sup + 1;
            }
            sup = meio - 1;
        }
    }
    return 0;
}

//fatorial

int fatorial_recursivo(int n){
    
    if(n == 0 || n == 1){
        return 1;
    }

    return n * fatorial_recursivo(n - 1);
}

int fatorial_iterativo(int n){

    int resultado = 1;

    for(int i = 1; i <= n; i++){
        resultado *= i;
    }

    return resultado;
}

//Lista encadeada

no* ptlista;

no* busca_enc(int valor, no** ant, no** pont){

    *ant = ptlista;
    *pont = NULL;

    no* ptr = (*ptlista).prox;

    while(ptr != NULL){
        if((*ptr).chave < valor){
            *ant = ptr;
            ptr = (*ptr).prox;
        }
        else{
            if((*ptr).chave == valor){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
    return *pont;
}

int insere_enc(no* novo_no){

    no* ant;
    no* pont;

    busca_enc((*novo_no).chave,&ant,&pont);

    if(pont == NULL){
        (*novo_no).prox = (*ant).prox;
        (*ant).prox = novo_no;
        return 0;
    }

    return -1;
}

no* remove_enc(int valor){

    no*ant,*pont;
    busca_enc(valor,&ant,&pont);

    if(pont != NULL){
        (*ant).prox = (*pont).prox;
        return pont;
    }
    return NULL;
}

//pilha enc

void insere_pila_enc(no* topo, no* novo_no){
    (*novo_no).prox = topo;
    topo = novo_no;
}

no* remove_pilha_enc(no* topo){
    
    no* remove = NULL;

    if(topo != NULL){
        remove = topo; 
        topo = (*topo).prox;
    }

    return remove;
}

//fila enc

void insere_fila_enc(no* novo_no, no* frente, no* fundo){
    if(fundo != NULL){
        (*fundo).prox = novo_no;
    }else{
        frente = novo_no;
    }
    fundo = novo_no;
}

no* remove_fila_enc(no* fundo, no* frente){
    no* remove = NULL;
    if(frente != fundo){
        remove = frente;
        frente = (*frente).prox;
        if(frente == NULL){
            fundo == NULL;
        }
    }
    return remove;
}


