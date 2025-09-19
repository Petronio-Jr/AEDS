//Trabalho 1 AEDS II Prática

//Petrônio Dias de Carvalho Júnior 2025.1.08.021
//Otávio Augusto Miguel 2025.1.08.041
//Alisson Guilherme F. Silva Soares 2025.1.08.002

//Código criado para identificar palíndromos

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_{
    //valores da lista
    int *itens;
    //frente e fundo da alocação
    int frente;
    int fundo;
}lista;

void retira_acento(unsigned char c1, FILE* arq, FILE* new_arq){

    //foram usados dois unsigned char c1 e c2 para ler os dois bytes das letras acentuadas
    //c1 guarda o primeiro byte e c2 guarda o segundo 
    unsigned char c2 = fgetc(arq);
    
    if (c1 == 195) { //todos os acentos começam com o primeiro byte de valor 195

        //compara os valores de c2
        switch (c2) {

            // Letras minúsculas com acento
            case 160: case 161: case 162: case 163:  // à á â ã
                fputc('a', new_arq); 
            break;

            case 168: case 169: case 170:            // è é ê
                fputc('e', new_arq); 
            break;

            case 173:                                // í
                fputc('i', new_arq); 
            break;

            case 179: case 180: case 181:            // ó ô õ
                fputc('o', new_arq); 
            break;

            case 186:                                // ú
                fputc('u', new_arq); 
            break;

            case 167:                                // ç
                fputc('c', new_arq); 
            break;

            // Letras maiúsculas com acento (convertidas pra minúsculo)
            
            case 128: case 129: case 130: case 131:  // À Á Â Ã
                fputc('a', new_arq); 
            break;

            case 137: case 138:                      // É Ê
                fputc('e', new_arq); 
            break;

            case 141:                                // Í
                fputc('i', new_arq); 
            break;

            case 147: case 148: case 149:            // Ó Ô Õ
                fputc('o', new_arq); 
            break;

            case 154:                                // Ú
                fputc('u', new_arq); 
            break;

            case 135:                                // Ç
                fputc('c', new_arq); 
            break;

            default:
                // Caracteres não tratados
                break;
        }
    }
}

void analise_arq(FILE* arq, FILE* new_arq){

    int c;

    while((c = fgetc(arq)) != EOF){
        //identificando quantas linhas o arquivo tem
        if(c == '\n'){
            fputc(c,new_arq);
        }
        else{
            //o novo arquivo nao tera espaços e não terá pontuação
            if((c != ' ') && ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)|| (c == 195))){
                //cofere se tem letra maiuscula
                if(c >= 65 && c <= 90){
                    //passa pra minuscula
                    c += 32;
                }
                //compara o primeiro byte de c
                if ((unsigned char)c == 195) {
                    retira_acento((unsigned char)c, arq, new_arq);
                }
                else {
                    //altera no novo arquivo
                    fputc(c,new_arq);
                }
            }
        }
    }
    //retorna pro inicio
    fseek(new_arq,0,SEEK_SET);
}

lista* leitura_arq(FILE* new_arq){
    
    //defininfo uma alocacao dados
    lista* dados = (lista*)malloc(sizeof(lista));

    //definindo um contador e um valor que receberá os elementos do arquivo
    int cont = 0, c;

    //guarda tem a posição atual do cursor em new_arq
    int guarda = ftell(new_arq);

    //enquanto o caracter pego no arq for diferente de quebra de linha e do fim do arquivo 
    while((c = fgetc(new_arq)) != '\n' && c != EOF){
        //descobrindo o tamanho do palindromo
        cont++;
    }

    //conferindo se chegou no fim
    if(cont == 0 && c == EOF){
        free(dados);
        return NULL;
    }

    //criando uma lista de itens do tamanho do palindromo
    (*dados).itens = (int*)malloc(sizeof(int) * cont);

    //defininfo frente e fundo da lista
    dados->frente = 0;
    dados->fundo = cont - 1;

    //voltando o cursor pro inicio do arquivo
    // SEEK_SET -> do começo do arquivo
    // SEEK_CUR -> posição atual
    // SEEK_END -> do final do arquivo

    fseek(new_arq,guarda,SEEK_SET);

    for(int i = 0; i < cont; i++){
        //atribuindo os caracteres à fila
       dados->itens[i] = fgetc(new_arq);
    }

    //o for preenche a lista até antes do /n ou do EOF, entao
    //fazendo fgetc ele assume o valor do /n
    fgetc(new_arq); 

    //retorna a lista dados
    return dados;
}

int identifica_palindromo(lista* dados){

    while(dados->frente <= dados->fundo){
        //se o valor do primeiro e do ultimo forem iguais
        if(dados->itens[dados->frente] == dados->itens[dados->fundo]){
            dados->frente++;
            dados->fundo--;
        }
        else{
            //se nao forem iguais da pra entender que nao é palindromo
            return 0;
        }
    }
    return 1;

    // 1 se palindromo
    // 0 se nao é
}

int main () {
    
    FILE* arq; //arq original
    FILE* new_arq; //arq alterado para leitura do palindromo

    //abrindo o arquivo existente pra leitura e escrita
    arq = fopen("dados.txt", "r");

    if(!arq){
        printf("\nErro na abertura do arquivo!");
    }

    //cria um arquivo pta leitura e escrita
    new_arq = fopen("dados_pra_leitura.txt", "w+");

    //analise_arq() é usada pra ler o arquivo original e modificar um segundo arquivo que será o usado nas demais funções
    //leitura_arq() le os dados no novo arquivo e aloca eles em uma lista de inteiros
    //identifica_palindrimo() confere se é palindromo ou não

    analise_arq(arq,new_arq);

    lista* dados;

    while((dados = leitura_arq(new_arq)) != NULL){

        int resultado = identifica_palindromo(dados);
        printf("%d\n",resultado);
        free((*dados).itens);free(dados);
    }
    fclose(arq);
    fclose(new_arq);
}