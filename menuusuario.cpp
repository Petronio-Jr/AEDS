#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    const int TAM = 5;

    typedef struct {
        string nome;
        string sobrenome;
        string email;
        long long int celular;
        string cidade;

    } Tamigo;

    Tamigo amigo[TAM];

    ofstream agenda("entrada.txt");

    int i = 0;
    int TAMatual = 0;

    cout << "\n\t\tSeja bem vindo! Insira as informacoes abaixo:";
    cout << "\n\t\t----------------------------------------------";

    cout << "\n\nInformacoes de usuario: ";
    cout << "\n-----------------------";

    cout << "\n\nPrimeiro nome: ";
    cin >> amigo[i].nome;
    agenda << amigo[i].nome << " ";

    cout << "\nSobrenome: ";
    cin >> amigo[i].sobrenome;
    agenda << amigo[i].sobrenome << " ";

    cout << "\nEmail: ";
    cin >> amigo[i].email;
    agenda << amigo[i].email << " ";

    cout << "\nCelular: ";
    cin >> amigo[i].celular;
    agenda << amigo[i].celular << " ";

    cout << "\nCidade: ";
    cin >> amigo[i].cidade;
    agenda << amigo[i].cidade << " ";

    agenda << endl;

    cout << endl;

    int opcao = 100;
    string sobrenome;

    while (opcao != 0) {

        cout << "\n----------------------------------------------------------------------";
        cout << "\n\n\t\tMENU DE OPCOES";
        cout << "\n\t\t----------------";
        cout << "\n\t1.Mostrar usuarios no sistema";
        cout << "\n\t2.Mostrar informacoes do usuario";
        cout << "\n\t3.Adicionar usuario";
        cout << "\n\t4.Remover usuario";
        cout << "\n\t5.Alterar informacoes de usuario";
        cout << "\n\t0.Sair\n";

        cin >> opcao;

        ifstream("entrada.txt");

        string nome;

        switch (opcao) {

        case 1:

            cout << "\n----------------------------------------------------------------------";
            cout << "\n\t\tUsuarios salvos no sistema\n\n";
            for (i = 0; i <= TAMatual; i++) {
                cout << "\033[36m" << amigo[i].nome << "_" << amigo[i].sobrenome << "\033[0m" << endl;
            }
            break;

        case 2:

            int k, box;

            cout << "\nQual o primeiro nome do usuario procurado? : ";
            cin >> nome;

            for (i = 0, k = 0; i < TAM; i++) {
                if (nome == amigo[i].nome) {
                    k++;
                    box = i;
                }
            }
            if (nome != amigo[i].nome && k == 0) {
                cout << "\n\033[1;31mNao ha nenhum usuario com esse nome no sistema!\033[0m";
            }
            else {

                if (k == 1) {
                    cout << "\n\033[36mPrimeiro nome: \033[0m" << amigo[box].nome << endl;
                    cout << "\033[36mSobrenome: \033[0m" << amigo[box].sobrenome << endl;
                    cout << "\033[36mEmail: \033[0m" << amigo[box].email << endl;
                    cout << "\033[36mCelular: \033[0m" << amigo[box].celular << endl;
                    cout << "\033[36mCidade: \033[0m" << amigo[box].cidade << endl;
                }
                else {
                    if (k > 1) {
                        cout << "\nHa mais de um usuario resgistrado com esse nome. Por favor insira o sobrenome do usuario: ";
                        cin >> sobrenome;
                        for (i = 0, k = 2; i < TAM; i++) {
                            if (nome == amigo[i].nome && sobrenome != amigo[i].sobrenome && k == 2) {
                                cout << "\n\033[1;31mNao ha nenhum usuario com esse nome no sistema!\033[0m";
                                k++;
                            }
                            else {
                                if (nome == amigo[i].nome && sobrenome == amigo[i].sobrenome) {
                                    cout << "\n\033[36mPrimeiro nome: \033[0m" << amigo[i].nome << endl;
                                    cout << "\033[36mSobrenome: \033[0m" << amigo[i].sobrenome << endl;
                                    cout << "\033[36mEmail: \033[0m" << amigo[i].email << endl;
                                    cout << "\033[36mCelular: \033[0m" << amigo[i].celular << endl;
                                    cout << "\033[36mCidade: \033[0m" << amigo[i].cidade << "\033[0m" << endl;
                                    k++;
                                }
                            }
                        }
                    }
                }
            }break;

        case 3:

            TAMatual++;
            i = TAMatual;
            if (TAMatual >= TAM) {
                cout << "\n\033[1;31mO sistema esta lotado de usuarios!\033[0m";
            }
            else {

                cout << "\nInformacoes do novo usuario: ";
                cout << "\n----------------------------";

                cout << "\n\nPrimeiro nome: ";
                cin >> amigo[i].nome;
                agenda << amigo[i].nome << " ";

                cout << "\nSobrenome: ";
                cin >> amigo[i].sobrenome;
                agenda << amigo[i].sobrenome << " ";

                cout << "\nEmail: ";
                cin >> amigo[i].email;
                agenda << amigo[i].email << " ";

                cout << "\nCelular: ";
                cin >> amigo[i].celular;
                agenda << amigo[i].celular << " ";

                cout << "\nCidade: ";
                cin >> amigo[i].cidade;
                agenda << amigo[i].cidade << " ";
                agenda << endl;
                cout << endl;
            }
            break;

        case 4:

            cout << "\n\tQual o nome do usuario que sera removido? : ";
            cin >> nome;
            cout << "\n\tQual o sobrenome? : ";
            cin >> sobrenome;

            for (i = 0; i < TAM; i++) {
                if (nome == amigo[i].nome && sobrenome == amigo[i].sobrenome) {
                    amigo[i].nome = amigo[i + 1].nome;
                    amigo[i].email = amigo[i + 1].email;
                    amigo[i].celular = amigo[i + 1].celular;
                    amigo[i].cidade = amigo[i + 1].cidade;

                    TAMatual--;
                }
            }
            break;

        case 5:

            int opcao2 = 100;

            cout << "\nInsira o nome do usuario? : ";
            cin >> nome;
            cout << "Insira o sobrenome do usuario? : ";
            cin >> sobrenome;

            for (i = 0, k = 0; i < TAMatual; i++) {
                if (nome == amigo[i].nome && sobrenome == amigo[i].sobrenome) {

                    cout << "\nO que voce deseja alterar?";
                    cout << "\n---------------------------";

                    cout << "\n1.Primeiro nome";
                    cout << "\n2.Sobrenome";
                    cout << "\n3.Email";
                    cout << "\n4.Celular";
                    cout << "\n5.Cidade\n\n";
                    cin >> opcao2;

                    switch (opcao2) {

                    case 1:

                        cout << "\nPrimeiro nome: ";
                        cin >> amigo[i].nome;
                        agenda << amigo[i].nome << " ";
                        break;

                    case 2:

                        cout << "\nSobrenome: ";
                        cin >> amigo[i].sobrenome;
                        agenda << amigo[i].sobrenome << " ";
                        break;

                    case 3:

                        cout << "\nEmail: ";
                        cin >> amigo[i].email;
                        agenda << amigo[i].email << " ";
                        break;

                    case 4:

                        cout << "\nCelular: ";
                        cin >> amigo[i].celular;
                        agenda << amigo[i].celular << " ";
                        break;

                    case 5:

                        cout << "\nCidade: ";
                        cin >> amigo[i].cidade;
                        agenda << amigo[i].cidade << " ";
                        agenda << endl;
                        break;

                        k++;
                    }
                }
                else {
                    if (nome != amigo[i].nome && sobrenome != amigo[i].sobrenome && k == 0) {
                        cout << "\n\033[1;31mNao ha nenhum usuario com esse nome no sistema!\033[0m";
                        k++;
                    }
                }

            }break;
        }
    }
    agenda.close();
}