#include <Exemplo.h>
#include <iostream>

using namespace std;

Exemplo::Exemplo(){};
Exemplo::~Exemplo(){};
Exemplo::void setId(int id)
{
  this->id = id
};
Exemplo::int getId()
{
  return id
};
Exemplo::void setDescricao(string descricao)
{
  this->descricao = descricao
};
Exemplo::string getDescricao()
{
  return descricao
};
Exemplo::void mostrar()
{
  cout << getId() << "" << getDescricao() << endl;
}