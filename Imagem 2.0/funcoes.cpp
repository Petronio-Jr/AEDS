#include <iostream>
#include <fstream>
#include "oprimg.h"
using namespace std; 

void tom(mtz v, int TAM1, int TAM2, int num, int maxcinza) {

    ofstream arq("alteracao_tonalidade.pgm"); //criando um novo arquivo

    if (!arq.is_open()) { //conferindo se foi aberto corretamente
        std::cerr << "Erro na criação do arquivo!\n";
    }

    arq << "P2\n" << TAM2 << " " << TAM1 << "\n" << maxcinza << "\n"; //cabeçalho

    int* base = (int*)v; //primeiro elemento da matriz
    
    int* primeiralinha = base; //primeira linha
    int* ultimalinha = base + (TAM1 * TAM2); //ultima linha + 1

    while (primeiralinha < ultimalinha){

        int* iniciolinha = primeiralinha; //inicio da linha
        int* fimlinha = primeiralinha + TAM2; //fim da linha

        while (iniciolinha < fimlinha) {

            int novovalor = *iniciolinha + num; //valor alterado

            if (novovalor >= maxcinza) { //caso ultrapasse o valor máximo
                novovalor = maxcinza;
            }
            else {
                if (novovalor < 0){ //caso ultrapasse o valor mínimo
                    novovalor = 0;
                }
            }
            arq << novovalor << " ";
            iniciolinha++; //avança a coluna
        }
        arq << endl;
        primeiralinha += TAM2; //avança a linha
    }
    arq.close();
}

void rotacaov(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_vertical.pgm"); //cria o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    int* base = (int*)v; //ponto inicial da matriz

    int* iniciolinha = base + TAM2 * (TAM1 - 1); //primeiro elemento da ultima linha matriz

    while(iniciolinha >= base){ //vai da ultima até a primeira linha

        int* p = iniciolinha; //p é um ponteiro usado para alterar as colunas da linha
        int* fimlinha = iniciolinha + TAM2; //ultimo elemento da ultima linha

        while (p < fimlinha) { //vai até o fim da linha

            arq << *p << " ";
            p++;
        }
        iniciolinha -= TAM2; //passa pra linha anterior
        arq << endl;
    }
    arq.close(); //fecha o arquivo
}

void rotacaoh(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_horizontal.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    int* base = (int*)v; //ponto inicial da matriz
    int* fim = base + TAM2 * TAM1; //fim da matriz

    while (base < fim) { //percorrendo as linhas até o fim da matriz

        int* iniciolinha = base; //primeiro elemento da linha
        int* fimlinha = base + (TAM2 - 1); //ultimo elemento da linha

        while (fimlinha >= iniciolinha) { //começa do fim até o inicio da linha

            arq << *fimlinha << " "; //recebe a linha invertida
            fimlinha--;

        }
        arq << endl;
        base += TAM2; //é acrescido uma linha
    }
    arq.close();
}

void rotacaod(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("rotacao_direita.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM1 << " " << TAM2 << endl << maxcinza << endl; //cabeçalho

    int* base = (int*)v; //ponto inicial da matriz

    int* iniciolinha = base; //inicio da linha
    int* fimlinha = base + TAM2; //fim da linha

    while(iniciolinha < fimlinha){ //desloca da primeira coluna até a ultima

        int* primeiralinha = iniciolinha; //apresenta o valor da primeira coluna e vai avançando
        int* ultimalinha = primeiralinha + TAM2 * (TAM1 - 1); // apresenta a mesma coluna mas na ultima linha 

        while (ultimalinha >= primeiralinha) { //a ultima linha é decrescida até chegar na primeira

            arq << *ultimalinha << " ";
            ultimalinha -= TAM2; //decresce a linha
        }
        arq << endl;
        iniciolinha++; //avanço da coluna
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
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM1 << " " << TAM2 << endl << maxcinza << endl; //cabeçalho, inverti o TAM1 e o TAM2 pra mudar o fomato da imagem

    int* base = (int*)v; //ponto inicial da matriz

    int* iniciolinha = base; //primeiro elemento da linha
    int* fimlinha = base + TAM2 - 1; //ultimo elemento da linha

    while (fimlinha >= iniciolinha) { //percorre a linha do fim ao inicio

        int* p = fimlinha; //ponteiro começa como o ultimo elemento da primeira linha
        int* fimmatriz = p + TAM2 * TAM1; //mesma coluna de p mas na ultima linha

        while (p < fimmatriz) { //enquanto as linhas forem diferentes

            arq << *p << " "; //exibe a ultima coluna como a primeira linha do arquivo e vai regredindo a coluna
            p += TAM2; //ponteiro salta uma linha

        }
        arq << endl;
        fimlinha--; //vai regredindo as colunas
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
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    int* base = (int*)v; //inicio da matriz

    int* primeiralinha = base; //primeira linha
    int* ultimalinha = base + TAM2 * TAM1; //ultima linha + 1

    while (primeiralinha < ultimalinha) {

        int* iniciolinha = primeiralinha; //primeiro elemento da linha
        int* fimlinha = iniciolinha + TAM2; //ultimo elemento da linha + 1

        while (iniciolinha < fimlinha) {

            if (*iniciolinha >= limiar) { //se for maior que o limiar ele vale o valor máximo (branco)
                arq << maxcinza << " ";
            }
            else { //se for menor ele vale 0 (preto)
                arq << 0 << " ";
            }
            iniciolinha++; //avança a coluna
        }
        arq << endl;
        primeiralinha += TAM2; //avança a linha
    }
    arq.close();
}

void negativo(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("imagem_negativa.pgm"); //criando arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << TAM2 << " " << TAM1 << endl << maxcinza << endl; //cabeçalho

    int* base = (int*)v;

    int* primeiralinha = base;
    int* ultimalinha = base + TAM1 * TAM2;

    while (primeiralinha < ultimalinha) {

        int* iniciolinha = primeiralinha; //inicio da linha
        int* fimlinha = iniciolinha + TAM2; //fim da linha + 1

        while (iniciolinha < fimlinha) {

            int valor = maxcinza - *iniciolinha; //negativando o valor

            arq << valor << " "; //enviando pro arquivo

            iniciolinha++;
        }
        arq << endl;
        primeiralinha += TAM2;
    }
    arq.close();
}

void icone(mtz v, int TAM1, int TAM2, int maxcinza) {

    ofstream arq("icone_imagem.pgm"); //criando o arquivo

    if (!arq.is_open()) { //confere se o arquivo foi aberto
        cerr << "Houve um erro da criação do arquivo!\n\n";
    }

    arq << "P2" << endl << 64 << " " << 64 << endl << maxcinza << endl; //cabeçalho

    int newTAM;

    if (TAM2 <= TAM1) { //transformando a imagem num quadrado
        newTAM = TAM1;
    }
    else {
        newTAM = TAM2;
    }

    int TAMpixel = newTAM / 64; //encontrando a nova dimensão dos pixels do icone no caso vai ser 16x16
    int media = 0;
    int valor;

    int* base = (int*)v;

    int* primeiralinha = base; //primeira linha da matriz
    int* ultimalinha = base + (newTAM * newTAM); //ultima linha da matriz + 1

    while (primeiralinha < ultimalinha) {

        int* primeiracoluna = primeiralinha; //primeira coluna da matriz
        int* ultimacoluna = primeiralinha + newTAM; //ultima coluna da matriz + 1

        while (primeiracoluna < ultimacoluna) {

            int* primeiralinhapixel = primeiracoluna; //primeira linha do pixel
            int* ultimalinhapixel = primeiralinhapixel + newTAM * TAMpixel; //ultima linha do pixel + 1

            while (primeiralinhapixel < ultimalinhapixel) {

                int* p = primeiralinhapixel; //inicio da linha no pixel
                int* fimlinhapixel = p + TAMpixel; //fim da linha no pixel

                while (p < fimlinhapixel) {

                    if (*p > maxcinza or *p < 0) { //os blocos sem valor recebem 0
                        valor = 0;
                    }
                    else {
                        valor = *p;
                    }
                    media += valor; //media recebe o valor do pixel todo
                    p++; //avança a coluna
                }
                primeiralinhapixel += newTAM; //salta a linha no bloco
            }
            arq << (media / (TAMpixel * TAMpixel)) << " "; //arquivo recebe média
            media = 0; //média reseta
            primeiracoluna += TAMpixel; //pula pro inicio do proximo bloco
        }
        arq << endl;
        primeiralinha += newTAM * TAMpixel; //avança pros blocos abaixo
    }
    arq.close();
}
