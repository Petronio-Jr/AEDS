#include <iostream>
#include <fstream>
#include "oprimg.h"
using namespace std;

void tom(mtz v, int TAM1, int TAM2, int num, int maxcinza) {

    ofstream arq("alteracao_tonalidade.pgm"); //criando o novo arquivo

    if (!arq.is_open()) { //conferindo se abriu
        cout << "Houve um erro na criação do arquivo!\n\n>";
    }
    else {
        cout << "\nO arquivo alteração_tonalidade.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    for (int i = 0; i < TAM1; i++) { //quantidade de linhas

        int* inicio = (int*)v + TAM2 * i; //inicio da linha
        int* fim = inicio + TAM2; //fim da linha

        while (inicio < fim) {

            int novovalor = *inicio + num; //atribuindo o valor numa outra variável pra não mexer na matriz original

            if (novovalor > maxcinza) { //se for maior que o valor de tom de cinza máximo ele se torna o valor máximo
                novovalor = maxcinza;
            }
            else {
                if (novovalor < 0) { //se for menor que 0 terá valor mínimo
                    novovalor = 0;
                }
            }

            arq << novovalor << " "; //separação dos números no arquivo

            inicio++; //avança pro próximo elemento da linha
        }
        arq << endl;
    }
    arq.close(); //fecha o arquivo
}

void rotacaov(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_vertical.pgm"); //cria o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo rotacao_vertical.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    for (int i = TAM1 - 1; i >= 0; i--) { //começa pela ultima linha

        int* inicio = (int*)v + TAM2 * i; //primeiro elemento da ultima linha
        int* fim = (int*)inicio + TAM2; //ultimo elemento da ultima linha + 1

        while (inicio < fim) {

            arq << *inicio << " "; //o arquivo recebe a ultima linha como sua primeira
            inicio++;
        }
        arq << endl;
    }
    arq.close(); //fecha o arquivo
}

void rotacaoh(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_horizontal.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo rotacao_horizontal.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    for (int i = 0; i < TAM1; i++) {

        int* iniciolinha = (int*)v + TAM2 * i; //primeiro elemento da linha
        int* fimlinha = (int*)v + (TAM2 - 1) + TAM2 * i; //ultimo elemento da linha

        while (fimlinha >= iniciolinha) { //começa do fim até o inicio da linha

            arq << *fimlinha << " "; //recebe a linha invertida
            fimlinha--;

        }
        arq << endl;
    }
    arq.close();
}

void rotacaod(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_direita.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo rotacao_direita.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM1 << " " << TAM2 << endl << maxcinza << endl; //cabeçalho, inverti o TAM1 e o TAM2 pra mudar o fomato da imagem

    for (int j = 0; j < TAM2; j++) { // j represnta os elementos da coluna
        
        for (int i = TAM1 - 1; i >= 0; i--) { // i representa as linhas
           
            int* p = (int*)v + TAM2 * i + j; // exibe o inverso das colunas consecutivamente  
            arq << *p << " "; // a primeira linha é o inverso da primeira coluna e assim por diante
        }
        arq << endl;
    }
    arq.close();
}

/* 

NORMAL                  R DIREITA  

 1  2  3  4 5             16 11  6  1   
 6  7  8  9 10            17 12  7  2  
 11 12 13 14 15           18 13  8  3  
 16 17 18 19 20           19 14  9  4   
                          20 15 10  5 
*/

void rotacaoe(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_esquerda.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo rotacao_esquerda.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM1 << " " << TAM2 << endl << maxcinza << endl; //cabeçalho, inverti o TAM1 e o TAM2 pra mudar o fomato da imagem

    for (int i = TAM2 - 1; i >= 0; i--) {

        int* inicio = (int*)v + i; //começa no ultimo elemento da primeira linha
        int* fim = (int*)v + (TAM2 - 1) + TAM2 * (TAM1 - 1); //ultimo elemento da ultima linha
        
        while (inicio <= fim) {

            arq << *inicio << " "; //exibe a ultima coluna como a primeira linha do arquivo e vai regredindo a coluna
            inicio+=TAM2;
        }
        arq << endl;
    }
    arq.close();
}

/*
 
NORMAL                R ESQUERDA

 1  2  3  4 5            5 10 15 20
 6  7  8  9 10           4  9 14 19
 11 12 13 14 15          3  8 13 18
 16 17 18 19 20          2  7 12 17
                         1  6 11 16     
*/

void binario(mtz v, int TAM1, int TAM2, int maxcinza, int limiar) {

    ofstream arq("imagem_binario.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo imagem_binario.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    for (int i = 0; i < TAM1; i++) { //i representa as linhas

        int* inicio = (int*)v + TAM2 * i; //primeiro elemento da linha
        int* fim = (int*)v + TAM2 * i + TAM2; //ultimo elemento + 1

        while (inicio < fim) {

            if (*inicio >= limiar) { // se for maior que o limiar ele vale o valor máximo (branco)
                arq << maxcinza << " ";
            }
            else { // se for menor ele vale 0 (preto)
                arq << 0 << " ";
            }
            inicio++;
        }
        arq << endl;
    }
    arq.close();
}

void icone(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("icone_imagem.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo icone_imagem.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << 64 << " " << 64 << endl << maxcinza << endl; //cabeçalho

    if (TAM2 < TAM1) { //transformando a imagem num quadrado
        TAM2 = TAM1;
    }
    else {
        if (TAM1 < TAM2) {
            TAM1 = TAM2;
        }
    }

    int quantfixa = TAM1 / 64; //encontrando a nova dimensão dos pixels do icone no caso vai ser 16x16

    int valor, media = 0;

    for (int j = 0; j < 64; j++) { //linhas

        int iniciobloco = 0; //coluna inicial do bloco

        for (int quantpixels = quantfixa; quantpixels <= TAM1; quantpixels += quantfixa) { //quantpixels começa sendo o fim do primeiro bloco e avança se tornando o fim dos próximos 

            media = 0; //resetar a média 

            for (int i = 0; i < quantfixa; i++) { //linha dentro do bloco

                int avanco = (j * quantfixa + i) * TAM1; //j * quantfixa decide qual o bloco que vai ser lido i e TAM1 determinam a linha correspondente

                int* inicio = (int*)v + avanco + iniciobloco; //v é a posição inicial, ele é multiplicada pelo endereço da linha do bloco e somada com o endereço da coluna do bloco
                int* fim = inicio + quantfixa; //fim do bloco

                while (inicio < fim) {

                    if (*inicio > maxcinza || *inicio < 0) { //filtrando os blocos sem valor adicionador da quadricularização do ícone
                        valor = 0; //os blocos de preenchimento serão pretos
                    }
                    else {
                        valor = *inicio;
                    }
                    media += valor; //média dos blocos de 16x16 pixels
                    inicio++;
                }
            }
            arq << (media / (quantfixa * quantfixa)) << " "; //o arquivo recebe a média do primeiro bloco

            iniciobloco += quantfixa; //mostra em qual coluna da linha o bloco inicia
        }
        arq << endl;
    }
    arq.close();
}

void negativo(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("imagem_negativa.pgm"); //criando arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cout << "Houve um erro da criação do arquivo!\n\n";
    }
    else {
        cout << "O arquivo imagem_negativa.pgm foi criado com sucesso!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    for (int i = 0; i < TAM1; i++) {

        int* inicio = (int*)v + TAM2 * i; //inicio da linha
        int* fim = inicio + TAM2; //fim da linha + 1

        while (inicio < fim) {

            int valor = maxcinza - *inicio; //negativando o valor
            arq << valor << " "; //enviando pro arquivo
            inicio++;
        }
        arq << endl;
    }
    arq.close();
}
    

