#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    const int TAM = 5; //Definindo o tamanho do vetor amigo

    typedef struct {  //Declarando a nova variável
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

    cout << "\n\t\t\033[36mSeja bem vindo! Insira as informacoes abaixo:\033[0m";
    cout << "\n\t\t----------------------------------------------";

    cout << "\n\n\033[36mInformacoes de usuario:\033[0m";
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
        cout << "\n\n\t\t\033[36mMENU DE OPCOES\033[0";
        cout << "\n\t\033[36m1\033[0m.Mostrar usuarios no sistema";
        cout << "\n\t\033[36m2\033[0m.Mostrar informacoes do usuario";
        cout << "\n\t\033[36m3\033[0m.Adicionar usuario";
        cout << "\n\t\033[36m4\033[0m.Remover usuario";
        cout << "\n\t\033[36m5\033[0m.Alterar informacoes de usuario";
        cout << "\n\t\033[36m0\033[0m.Sair\033[36m\n";

        cin >> opcao;
        cout << "\033[0m";

        ifstream("entrada.txt");

        string nome;

        int opcao2 = 100;

        switch (opcao) {

        case 1:

            cout << "\n----------------------------------------------------------------------";
            cout << "\n\t\t\033[36mUsuarios salvos no sistema\033[0m\n\n";
            for (i = 0; i <= TAMatual; i++) {
                cout << amigo[i].nome << "_" << amigo[i].sobrenome << endl;
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
            if (k == 0) {
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
                        for (i = 0, k = 10; i <= TAMatual; i++) {
                           if (nome == amigo[1].nome && sobrenome == amigo[i].sobrenome) {
                                    cout << "\n\033[36mPrimeiro nome: \033[0m" << amigo[i].nome << endl;
                                    cout << "\033[36mSobrenome: \033[0m" << amigo[i].sobrenome << endl;
                                    cout << "\033[36mEmail: \033[0m" << amigo[i].email << endl;
                                    cout << "\033[36mCelular: \033[0m" << amigo[i].celular << endl;
                                    cout << "\033[36mCidade: \033[0m" << amigo[i].cidade << "\033[0m" << endl;
                                    k++;
                           }
                        }                      
                        if (k == 10) {
                            cout << "\n\033[1;31mNao ha nenhum usuario com esse nome no sistema!\033[0m";          
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

                cout << "\n\033[36mInformacoes do novo usuario:\033[0m ";
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
                    amigo[i].nome = amigo[TAMatual].nome;
                    amigo[i].sobrenome = amigo[TAMatual].sobrenome;
                    amigo[i].email = amigo[TAMatual].email;
                    amigo[i].celular = amigo[TAMatual].celular;
                    amigo[i].cidade = amigo[TAMatual].cidade;

                    TAMatual--;
                }
            }
            break;

        case 5:

            cout << "\nInsira o nome do usuario? : ";
            cin >> nome;
            cout << "Insira o sobrenome do usuario? : ";
            cin >> sobrenome;

            for (i = 0, k = 0; i <= TAMatual; i++) {
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

                    }
                    k++;
                }
                else {
                    if (nome != amigo[i].nome && sobrenome != amigo[i].sobrenome && k == 0) {
                        cout << "\n\033[1;31mNao ha nenhum usuario com esse nome no sistema!\033[0m";
                        k++;
                    }
                }

            }break;
            
       default:

            if (opcao != 0) {
                cout << "\n\033[1;31mComando invalido\033[0m";
            }
            break;
        }
    }
    agenda.close();
}