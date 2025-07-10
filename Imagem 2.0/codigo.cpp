/*Petrônio Dias de Carvalho Júnior   2025.1.08.021

 06/07/2025

Objetivo: adquirir conhecimentos de manipulação de  matrizes (imagens) com ponteiros implementando funcionalidades que
geram novas matrizes (imagens) a partir de valores carregados de arquivos-texto em formato PGM de representação de imagens.

O aplicativo tem um menu de opções que permita ler a imagem de entrada em formato PGM e,
para cada operação implementada gera um novo arquivo-texto de mesmo formato PGM com um outro nome.

*/

#include <iostream>
#include "oprimg.h"
#include <fstream>
using namespace std;

mtz imagem; // coloquei fora do main pq era uma variável muito grande para a função

void leitura(mtz v, int maxlinhas, int maxcolunas, int maxcinza, ifstream& arq) { //função pra ler os dados do arquivo numa matriz

    int* inicio = (int*)v; //(int*)v assume o mesmo papel de &v[0][0]

    int TAMmatriz = maxlinhas * maxcolunas; //tamanho da matriz

    int* fim = inicio + TAMmatriz; //fim da matriz

    while (inicio < fim) { //percorre a matriz toda

        arq >> *inicio;

        if (*inicio > maxcinza) {
            cerr << "O arquivo possui pixels de valores inválidos!";
            exit(0); //fecha o programa
        }

        inicio++;
    }
    arq.close();
}

int main() {

    setlocale(LC_ALL, "pt-BR"); //comando para exibir as palavras com acentuação correta no terminal

    string nomearquivo, tipo;
    int MAXcolunas, MAXlinhas, MAXcinza;
    int opimg;

    cout << "\nQual das imagens será usada?"; //define qual das imagens será utilizada
    cout << "\n----------------------------";
    cout << "\n\n1.Imagem 1.  1024 x 569";
    cout << "\n2.Imagem 2.  1024 x 1024\n\n";
    cin >> opimg;

    switch (opimg) {
    case 1:
        nomearquivo = "img.pgm"; //primeira imagem
        break;
    case 2:
        nomearquivo = "img2.pgm"; //segunda imagem
        break;
    default:
        cout << "\033[1;31m\nComando inválido!\033[0m\t";
        return 1; //fecha o programa
        break;
    }

    cout << "\nCarregando dados...";
    cout << "\n----------------------------------------------------------------------------------------------------";

    ifstream arquivo(nomearquivo); //abre o arquivo escolhido para leitura

    if (opimg == 1 || opimg == 2) {
        if (!arquivo.is_open()) {
            cout << "\n\nAlgo deu errado na abertura do arquivo!\n"; //checando se o arquivo foi aberto
            return 1;
        }
    }

    arquivo >> tipo; //P2

    if (tipo != "P2") { //verificando se o arquivo tem o formato correto
        cout << "\n\nO arquivo não é compatível";
        return 1;
    }

    arquivo >> MAXcolunas;
    arquivo >> MAXlinhas;
    arquivo >> MAXcinza;

    leitura(imagem, MAXlinhas, MAXcolunas, MAXcinza, arquivo); //chamando a função

    int opcao = -1;

    cout << "\n\n\t\tSeja bem vindo ao programa de alteração de imagens";
    cout << "\n\t\t---------------------------------------------------";

    while (opcao != 0) {

        cout << "\n\n\tMenu de opções";
        cout << "\n\t--------------";
        cout << "\n\n1.Escurecer ou clarear imagem por um fator informado";
        cout << "\n2.Rotacionar a imagem";
        cout << "\n3.Negativar a imagem";
        cout << "\n4.Binarizar a imagem por um limiar informado";
        cout << "\n5.Transformar a imagem num ícone";
        cout << "\n0.Sair\n\n";

        cin >> opcao;

        int fator, opcao2, limiar;

        switch (opcao) {

        case 1:

            cout << "\nQual será o fator de escurecimento ou clareamento? ";
            cin >> fator;

            tom(imagem, MAXlinhas, MAXcolunas, fator, MAXcinza); //função que altera a tonalidade
            cout << "\nO arquivo alteracao_tonalidade.pgm foi criado com sucesso!";
            cout << "\n----------------------------------------------------------------------------------------------------\n";

            break;

        case 2:

            cout << "\nA imagem será rotacionada para qual direção?";
            cout << "\n\n1.Vertical";
            cout << "\n2.Horizontal";
            cout << "\n3.Esquerda";
            cout << "\n4.Direita\n\n";
            cin >> opcao2;
            cout << "\n";

            switch (opcao2) { //novo switch para escolher a direção 

            case 1:
                rotacaov(imagem, MAXlinhas, MAXcolunas, MAXcinza);
                cout << "\nO arquivo rotacao_vertical.pgm foi criado com sucesso!";
                cout << "\n----------------------------------------------------------------------------------------------------\n";
                break;
            case 2:
                rotacaoh(imagem, MAXlinhas, MAXcolunas, MAXcinza);
                cout << "\nO arquivo rotacao_horizontal.pgm foi criado com sucesso!";
                cout << "\n----------------------------------------------------------------------------------------------------\n";
                break;
            case 3:
                rotacaoe(imagem, MAXlinhas, MAXcolunas, MAXcinza);
                cout << "\nO arquivo rotacao_esquerda.pgm foi criado com sucesso!";
                cout << "\n----------------------------------------------------------------------------------------------------\n";
                break;
            case 4:
                rotacaod(imagem, MAXlinhas, MAXcolunas, MAXcinza);
                cout << "\nO arquivo alteracao_direita.pgm foi criado com sucesso!";
                cout << "\n----------------------------------------------------------------------------------------------------\n";
                break;
            }
            break;

        case 3:

            cout << endl;
            negativo(imagem, MAXlinhas, MAXcolunas, MAXcinza);
            cout << "\nO arquivo imagem_negativa.pgm foi criado com sucesso!";
            cout << "\n----------------------------------------------------------------------------------------------------\n";
            break;

        case 4:

            cout << "\nQual será o valor do limiar? ";
            cin >> limiar;

            cout << endl;
            binario(imagem, MAXlinhas, MAXcolunas, MAXcinza, limiar);
            cout << "\nO arquivo imagem_binario.pgm foi criado com sucesso!";
            cout << "\n----------------------------------------------------------------------------------------------------\n";
            break;

        case 5:

            cout << endl;
            icone(imagem, MAXlinhas, MAXcolunas, MAXcinza);
            cout << "\nO arquivo icone_imagem.pgm foi criado com sucesso!";
            cout << "\n----------------------------------------------------------------------------------------------------\n";
            break;

        case 0:

            cout << "\nConfira as novas imagens criadas no seu dispositivo. A imagem original não sofreu alterações!\n";

        default: //caso escolha um número fora do exibido no menu

            if (opcao != 0) {
                cout << "\033[1;31m\nComando inválido!\033[0m";
                cout << "\n----------------------------------------------------------------------------------------------------\n";
            }
            break;

        }

    }
}