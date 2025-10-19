#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * O objetivo do programa é manipular uma lista crescente com alocação encadeada.
 *
 * Importante: ao executar o programa compilado você deve utilizar-se do script executar.sh.
 * Exemplo: supondo que você tenha compilado o código fonte da seguinte forma:
 * gcc Q3.c -o Q3
 *
 * Você deve chamar o script da seguinte forma:
 * ./executar.sh Q3
 *
 * Ou seja, o nome do executável gerado deve ser passado como argumento para o script.
 * Neste caso, Q3.
 *
 * Dentro do diretório você encontrará diversos casos de teste, nomeados como:
 *  - entrada_1.txt
 *  - entrada_2.txt
 *  ...
 *
 * Para cada arquivo de entrada existirá um gabarito correspondente. ou Seja:
 *  - gabarito_1.txt
 *  - gabarito_2.txt
 *  ...
 *
 *  Você NÃO deve alterar estes arquivos.
 *
 * Ao executar o script executar.sh ele comparará a saída produzida pelo seu programa com os gabaritos.
 * Você terá o resultado do teste para cada entrada.
 */

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

/**
 * Implemente a função buscar a seguir, de modo que o código execute corretamente.
 * Utilize no máximo 7;
*/

void buscar(no *ptlista, int x, no **ant, no **pont)
{
    *ant = ptlista;
    *pont = NULL;
    
    no* ptr = (*ptlista).prox;

    while(ptr != NULL){
        if((*ptr).chave < x){
            *ant = ptr;
            ptr = (*ptr).prox;
        }
        else{
            if((*ptr).chave == x){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
    return pont;
}

no *inserir(no *ptlista, no *novo_no)
{
    no *ant;
    no *pont;
    buscar(ptlista, novo_no->chave, &ant, &pont);
    no *retorno = pont;
    if (pont == NULL)
    {
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
    }
    return retorno;
}

no *remover(no *ptlista, int x)
{
    no *ant;
    no *pont;

    buscar(ptlista, x, &ant, &pont);
    no *retorno = pont;
    if (pont != NULL)
    {
        ant->prox = pont->prox;
    }

    return retorno;
}

void imprimir(no *ptlista, char *arq_saida)
{
    FILE *saida = fopen(arq_saida, "a");
    if (ptlista->prox == NULL)
    {
        fprintf(saida, "<lista vazia!>");
        return;
    }

    ptlista = ptlista->prox;
    while (ptlista != NULL)
    {
        fprintf(saida, "%d", ptlista->valor);
        ptlista = ptlista->prox;
        fprintf(saida, " -> ");
        if (ptlista == NULL)
            fprintf(saida, "NULL");
    }
    fprintf(saida, "\n");
    fclose(saida);
}

void desalocar_lista(no *ptlista)
{
    no *no_prox = ptlista->prox;
    while (no_prox != NULL)
    {
        no *no_temp = no_prox->prox;
        free(no_prox);
        no_prox = no_temp;
    }
    free(ptlista);
}

void gera_nomes_arquivos(char *arq_entrada, char *arq_saida, char *comp)
{
    strcpy(arq_entrada, "entrada_");
    strcat(arq_entrada, comp);
    strcat(arq_entrada, ".txt");

    strcpy(arq_saida, "saida_");
    strcat(arq_saida, comp);
    strcat(arq_saida, ".txt");
}

int ler_valor(FILE *entrada)
{
    int valor;
    fscanf(entrada, "%d", &valor);
    return valor;
}

no *alocar_no()
{
    no *novo_no = malloc(sizeof(no));
    novo_no->prox = NULL;
    return novo_no;
}

void main(int argc, char **argv)
{
    char arq_entrada[14];
    char arq_saida[12];
    gera_nomes_arquivos(arq_entrada, arq_saida, argv[1]);
    FILE *entrada = fopen(arq_entrada, "r");

    no *ptlista;
    ptlista = malloc(sizeof(no));
    ptlista->prox = NULL;

    int resposta = 1;

    while (resposta != 0)
    {
        resposta = ler_valor(entrada);

        if (resposta == 0)
        {
            // sair
            fclose(entrada);
            desalocar_lista(ptlista);
            return;
        }
        else if (resposta == 1)
        {
            // inserir
            no *novo_no = alocar_no();
            novo_no->chave = ler_valor(entrada);
            novo_no->valor = ler_valor(entrada);

            if (inserir(ptlista, novo_no) != NULL)
            {
                free(novo_no);
            }
        }
        else if (resposta == 2)
        {
            // remover
            int chave = ler_valor(entrada);

            no *no_removido = remover(ptlista, chave);
            if (no_removido != NULL)
            {
                free(no_removido);
            }
        }
        else if (resposta == 3)
        {
            // imprimir
            imprimir(ptlista, arq_saida);
        }
    }
}