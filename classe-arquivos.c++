// CLASSE DE EXEMPLO PARA SALVAR DADOS EM ARQUIVOS DE TEXTO LOCALMENTE.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string nome, linha;
  int idade;
  fstream dados;
  char opcao;

  // ### INSERÇÃO DE DADOS EM UM ARQUIVO DE TEXTO
  dados.open("dados.txt", fstream::out | fstream::app);
  dados << "Nome"
        << "\t"
        << "Idade"
        << "\n";
  do
  {
    cout << "Digite o nome do usuário: " << endl;
    getline(cin, nome); // PARA QUE CONSIGA INSERIR NOMES COM ESPAÇO, TRATAMOS O BUFFER, E NO FINAL DO CÓDIGO LIMPAMOS ELE
    cout << "Digite a idade da pessoa" << endl;
    cin >> idade;
    dados << nome << "\t" << idade << "\n";
    cout << "Quer continuar inserindo dados? s para SIM | n para NÃO" << endl;
    cin >> opcao;
    cin.ignore();
  } while (opcao == 's');
  dados.close();
  cout << "Dados salvos com sucesso" << endl;

  // ### LENDO OS DADOS INSERIDOS ANTERIORMENTE NO ARQUIVO
  dados.open("dados.txt", fstream::in);
  while (dados.good())
  {
    getline(dados, linha);
    cout << linha << endl;
  }
  dados.close();
  cout << "Dados lidos com sucesos" << endl;
}
