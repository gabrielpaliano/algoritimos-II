#ifndef EXEMPLO_H
#define EXEMPLO_H
#include <iostream>
using namespace std;

class Exemplo
{
public:
  Exemplo();
  ~Exemplo();
  void setId(int id);
  int getId();
  void setDescricao(string descricao);
  string getDescricao();
  void mostrar();

private:
  int id;
  string descricao;
};

#endif