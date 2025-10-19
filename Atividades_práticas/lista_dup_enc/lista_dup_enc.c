#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

lista_dup* cria_lista(void){

    lista_dup* lista = (lista_dup*)malloc(sizeof(lista_dup));

    (*lista).frente = NULL;  
    (*lista).fundo = NULL;
    
    return lista;
}

void inserir_fim(lista_dup* lista, int elemento) {

    //alocando o novo no
    no* novo_no = (no*) malloc (sizeof(no));
    (*novo_no).data = elemento;
    (*novo_no).prox = NULL;
    (*novo_no).ant = NULL;

    //caso a lista esteja vazia 
    if ((*lista).frente == NULL) {
        (*lista).frente = (*lista).fundo = novo_no;
    }
    else{
        (*(*lista).fundo).prox = novo_no;
        (*novo_no).ant = (*lista).fundo;
        //definindo o novo ultimo elemento 
        (*lista).fundo = novo_no;
    }
}

void inserir_inicio(lista_dup* lista, int elemento) {

    //alocando um novo no 
	no* novo_no = (no*) malloc (sizeof(no));
	(*novo_no).data = elemento;
	(*novo_no).prox = NULL;
    (*novo_no).ant = NULL;

    if((*lista).frente != NULL){
       (*novo_no).prox = (*lista).frente;
       (*(*lista).frente).ant = novo_no;
       //definindo o novo primeiro elemento 
       (*lista).frente = novo_no;
    }
    else{
        (*lista).frente = (*lista).fundo = novo_no;
    }
}

void apagar(lista_dup* lista, int valor_busca) {

    no* tmp = (*lista).frente;

	while (tmp != NULL) {

		if ((*tmp).data == valor_busca) {
            
            //se for o primeiro elemento
            if (tmp == (*lista).frente) {
                (*lista).frente = (*(*lista).frente).prox;
			    free(tmp);
			    return;
			}
            else{
                //se for o ultimo
                if(tmp == (*lista).fundo){
                    (*lista).fundo = (*tmp).ant;
                    free(tmp);
			        return;
                }
                else {
                    (*(*tmp).ant).prox = (*tmp).prox;
                    (*(*tmp).prox).ant = (*tmp).ant;
			        free(tmp);
			        return;
			    }
		    }
        }
        else {
		    tmp = (*tmp).prox;
		}
	}
	printf("\n Valor nao encontrado! ");
}
 
void apagar_inicio(lista_dup* lista) {

    //lista vazia
	if ((*lista).frente == NULL) {
		printf("\n Nenhum elemento deletado ");
    } 
    else {
        //se so houver um elemento
        if((*lista).frente == (*lista).fundo){
            (*lista).frente = (*lista).fundo = NULL;
            return;
        }
		printf("\nElemento deletado - %d", (*(*lista).frente).data);
		(*lista).frente = (*(*lista).frente).prox;
        (*(*lista).frente).ant = NULL;
	}
}
 
void apagar_fim(lista_dup* lista) {	

    //lista vazia
	if((*lista).frente == NULL) {
		printf("\n Nenhum elemento deletado ");
    } 
    else{
        //um elemento
        if ((*lista).frente == (*lista).fundo) {
		    printf("\nElemento deletado - %d", (*(*lista).fundo).data);
		    (*lista).frente = (*lista).fundo = NULL;
            return;
	    } 
        int eliminado = (*(*lista).fundo).data;
        (*lista).fundo = (*(*lista).fundo).ant;
		printf("\nElemento deletado - %d", eliminado);
    }
}

bool ehVazia(lista_dup* lista) {
    if ((*lista).frente == NULL) {
        return true;
    } else {
        return false;
    }
}

void imprimir(lista_dup* lista) {

    no* tmp = (*lista).frente;

    if((*lista).frente != NULL){
        //o ponteiro tmp percorre a lista ate fundo
        while (tmp != (*lista).fundo) {
            printf("\n %d",(*tmp).data);
 	        tmp = (*tmp).prox;
	    }
        printf("\n %d",(*(*lista).fundo).data);
    }else{
        return;
    }
}

int obter_primeiro(lista_dup* lista) {

    //lista vazia
	if (ehVazia(lista)) {
		printf("\n Nenhum elemento encontrado ");
    }else {
        return (*(*lista).frente).data; 
	}
    return (0);
}

int obter_ultimo(lista_dup* lista) {

    //lista vazia
	if (ehVazia(lista)) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } 
    else{
        return (*(*lista).fundo).data;
    }
}

void inserirPosicao(lista_dup* lista, int valor, int posicao){

    //elemento a ser adicionado
    no* novo_no = (no*)malloc(sizeof(no)); 
    (*novo_no).data = valor;
    (*novo_no).prox = NULL;
    (*novo_no).ant = NULL;

    //como ja existe uma condicao pra posicao 1, i comeca sendo 2
    int i = 2; 

    //o primeiro elemento adicionado deve ser na posicao 1
    if(posicao <= 0 || (posicao > 1 && (*lista).frente == NULL)){
        printf("\nPosicao invalida!");
        return;
    }

    if(posicao == 1){
        //substitui o valor que tava em primero pelo novo_no
        (*novo_no).prox = (*lista).frente;
        (*novo_no).ant = NULL;
        (*lista).frente = novo_no;

        if((*lista).fundo == NULL){
            (*lista).fundo = novo_no;
        }
    }
    else{
        no* tmp = (*lista).frente;

        //avanca ate a posicao desejada
        while(i < posicao){

            //confere se tem um proximo elemento 
            if((*tmp).prox != NULL){
                tmp = (*tmp).prox;
            }
            else{
                printf("\nA lista nao possui essa posicao!");
                return;
            }
            i++;
        }
        //insere
        (*novo_no).prox = (*tmp).prox;
        (*novo_no).ant = tmp;
        (*tmp).prox = novo_no;

        //ajusta o fundo
        if((*lista).fundo == tmp){
            (*lista).fundo = novo_no;
        }
    }

}


void removerPosicao(lista_dup* lista, int posicao){

    int i = 2;
    no* tmp = (*lista).frente;
    
    if(posicao <= 0){
        printf("\nPosicao invalida!");
        return;
    }

    //confere se o vetor esta vazio
    if (tmp != NULL){
        
        if (posicao == 1){

            //se for o unico elemento ele zera a lista
            if((*lista).frente == (*lista).fundo){
                (*lista).frente = (*lista).fundo = NULL;
            }
            else{
            //tmp aponta pro elemento seguinte
            tmp = (*tmp).prox;
            (*tmp).ant = NULL;
            //a frente da lista agora é tmp 
            (*lista).frente = tmp;
            } 
        }
        else{
            // busca pela posicao
            while (i < posicao && i > 0){ 
                //confere se o valor buscado esta na lista
                if ((*tmp).prox != NULL){
                    tmp = (*tmp).prox; 
                }
                else{
                    printf("\nA lista nao possui essa posicao!");
                    return;
                }
                i++;
            }

            //confere se eh o ultimo elemento 
            if((*tmp).prox == (*lista).fundo ){
                (*tmp).prox = NULL;
                (*lista).fundo = tmp;
            }
            else{
                if((*tmp).prox != NULL){
                (*tmp).prox = (*(*tmp).prox).prox;
                (*(*tmp).prox).ant = tmp;
                }
            }
        }
    }
    else{
        printf("\nA lista esta vazia!");
    }
}

int obterPosicao(lista_dup* lista, int posicao){

    int i = 2;
    int val = 0;
    no* tmp = (*lista).frente;

    if(posicao <= 0){
        printf("\nPosicao invalida!");
        return (0);
    }

    if(tmp != NULL){
        if(posicao == 1){
            //valor do primeiro elemento
            val = (*(*lista).frente).data; 
        }
        else{
            while(i < posicao){
               //confere se o valor buscado esta na lista
               if((*tmp).prox != NULL){
                   tmp = (*tmp).prox; 
                }
                else{
                    printf("\nA lista nao possui essa posicao!");
                }
                i++;
            }

            if((*tmp).prox != NULL){ 
                val = (*(*tmp).prox).data;
            }
            else{
                printf("\nA lista nao possui essa posicao!");
            }
        }
    }
    else{
        printf("\nA lista esta vazia!");
    }
    return val; //valor retorno
}

void liberar_memoria(lista_dup* lista){

    //tmp recebe o inicio
    no* tmp = (*lista).frente;

    while(tmp != (*lista).fundo){
        //guarda o elemento seguinte
        no* prox = (*tmp).prox;
        //libera tmp atual e atualiza o ponteiro 
        free(tmp);
        tmp = prox;
    }

    //liberta a lista
    free(lista);
}

int main() { 

  int val, pos, n; //adicionei a variavel pos
  lista_dup* lista = cria_lista();

  do {
    printf("\n************************* MENU ************************");
	printf("\n1.Inserir no fim");
	 printf("\n2.Inserir no inicio");
	 printf("\n\n3.Apagar um valor na lista");
	 printf("\n4.Apagar do inicio");
	 printf("\n5.Apagar do fim");
	 printf("\n\n6.Imprimir lista");
	 printf("\n7.Eh vazia?");
     printf("\n\n8.Obter primeiro");
     printf("\n9.Obter ultimo");
     printf("\n\n10.Inserir novo elemento");
     printf("\n11.Remover elemento");
     printf("\n12.Obter valor numa posicao");
     printf("\n\n0.Sair");
	 printf("\n\nEntre sua opcao : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_fim(lista,val);
			    break;
		 case 2: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_inicio(lista,val);
			    break;
		 case 3: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    apagar(lista,val);
			    break;
		 case 4: 
			    apagar_inicio(lista);
			    break;
		 case 5: 
			    apagar_fim(lista);
			    break;
		 case 6: imprimir(lista);
		 	    break;
		 case 7: if (ehVazia(lista)) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista nao vazia");
                }
                break;
        case 8: val = obter_primeiro(lista);
                    printf("%d", val);
		 	    break;
        case 9: val = obter_ultimo(lista);
                    printf("%d", val);
		 	    break;
        case 10: printf("\n Insira o valor e a posicao: ");
                 scanf("%d %d",&val, &pos);
                 inserirPosicao(lista,val,pos);
                 break;
        case 11: printf("\n Insira a posicao: ");
                 scanf("%d",&pos);
                 removerPosicao(lista,pos);
                 break;
        case 12: printf("\n Insira a posicao: ");
                 scanf("%d",&pos);
                 val = obterPosicao(lista,pos);
                 if(val != 0){
                 printf("\n%d",val);
                 }
                 break;
        case 0: liberar_memoria(lista);
                exit(0);
		 	    break;
		default: printf("\n Opcao errada!");
		 	    break;
		}
	} while(1);
}