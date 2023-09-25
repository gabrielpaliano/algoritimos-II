#include <iostream>
using namespace std;

class No
{
public:
  int dado; // Dado dentro da lista
  No *prox; // É um ponteiro para armazenar o endereço do próximo nó

  No() // Método criador da classe
  {
    this->dado = -1;
    this->prox = NULL;
  }
  No *listarUltimoNo(No *elemento) // Método para listar o último nó da lista;
  { 
    while (elemento)
    {
      if (elemento->prox == NULL)
      {
        return elemento;
      }
      elemento = elemento->prox;
    }
  }

  void inserirNo(No *elemento, int valor) // Método para inserir um novo nó na lista
  {
    No *novo = new No;
    novo->dado = valor;
    No *ultimoNo = elemento->listarUltimoNo(elemento);
    ultimoNo->prox = novo;
  }
};

int main()
{
  No *elemento = new No;
  int valor;
  for(int i=0; i<5; i++){
    cout << "Digite o valor inteiro: " << endl;
    cin >> valor;
    elemento->inserirNo(elemento, valor);
  }

  while (elemento)
  {
    cout << elemento << " " << elemento->dado << " " << elemento->prox << endl;
    elemento = elemento->prox;
  }
}