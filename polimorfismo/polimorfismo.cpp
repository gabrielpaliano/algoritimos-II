// NESSE CASO O POLIMORFISMO ENCONTRA-SE NA FUNÇÃO mostrar(). A FUNÇÃO TEM O MESMO NOME E SE ADAPTA CONFORME A CLASSE.
#include <iostream>
using namespace std;

class Pessoa
{
public:
  string nome;
  Pessoa()
  {
    this->nome = "Gabriel Paliano";
  };
  ~Pessoa(){};
  void mostrar()
  {
    cout << nome << endl;
  };
};

class Professor : public Pessoa
{
public:
  string profissao;
  Professor()
  {
    this->profissao = "Professor";
  };
  ~Professor(){};
  void mostrar()
  {
    cout << nome << " " << profissao << endl;
  }
};

int main()
{
  Professor *p = new Professor;
  p->mostrar();
}