#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lista_enc.h"
using namespace std;

int main() {

    int opcao = -1;
    no* ant;
    no* pont;
    no* novo_no;

    while (opcao != 0) {

        cout << "\n\t\tPROGRAMA DE INSERCAO ALOCADA:";
        cout << "\nO que voce deseja?";

        cout << "\n\n1.Buscar um no pela chave de acesso";
        cout << "\n2.Inserir um novo no";
        cout << "\n3.Remover um no";
        cout << "\n4.Exibir os nos armazenados e seus dados";
        cout << "\n0.Sair";
        cin >> opcao;

        switch (opcao) {
            
            int chave, valor;

        case 1:

            cout << "\nInsira a chave de acesso:";
            cin >> chave;

            busca_enc(chave, &ant, &pont);

            if (pont != NULL) {
                cout << "\nO no esta presente na alocacao. Ele esta no endereco" << pont << "!";
            }
            else {
                cout << "\nNao ha nenhum no com essa chave contido na alocacao!";
            }

        case 2:

            cout << "\nInsira o valor da chave de acesso: ";
            cin >> chave;
            cout << "Insira o valor do no: ";
            cin >> valor;

            novo_no = (no*)malloc(sizeof(no));
            (*novo_no).chave = chave;
            (*novo_no).valor = valor;
            (*novo_no).prox = NULL;

            insere_enc(novo_no);

            if (insere_enc(novo_no) == 0) {
                cout << "\nO no foi inserido com sucesso!";
            }
            else {
                cout << "\nA alocacao ja possui esse valor de chave de acesso!";
            }

        case 3:

            cout << "\nInsira o valor da chave de acesso: ";
            cin >> chave;

            remove_enc(chave);

            if (remove_enc(chave) == NULL) {
                cout << "\nA chave de acesso nao foi encontrada na alocacao!";
            }
            else {
                cout << "\nO no foi removido com sucesso!";
            }

        case 4:

            impressao();
        }
    }

    //Liberacao de memoria alocada
     free(novo_no); free(ptlista);
}