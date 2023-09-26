#include <iostream>
#include <cstdio>
using namespace std;

class No
{
public:
  int id;
  int dado; // Dado dentro da lista
  No *prox; // É um ponteiro para armazenar o endereço do próximo nó

  No() // Método criador da classe
  {
    this->id = 0;
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

  No *listarNo(No *elemento, int id)
  {
    int aux = id;
    while (elemento)
    {
      if (elemento->id == aux)
      {
        system("clear");
        cout << "ID : " << elemento->id << " Endereço: " << elemento << " Valor: " << elemento->dado << " Prox. Endereço:  " << elemento->prox << endl;
        cout << "\nPressione qualquer tecla para continuar..." << endl;
        getchar();
        getchar();
        return elemento;
      }

      elemento = elemento->prox;
    }
    system("clear");
    cout << "Nenhum elemento encontrado com esse ID" << endl;
    cout << "\nPressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();
  }

  void inserirNo(No *elemento, int valor, int id) // Método para inserir um novo nó na lista
  {
    No *novo = new No;
    novo->id = id;
    novo->dado = valor;
    No *ultimoNo = elemento->listarUltimoNo(elemento);
    ultimoNo->prox = novo;
  }

  void mostrarLista(No *elemento) // Método para mostrar a lista
  {
    while (elemento)
    {
      cout << "ID : " << elemento->id << " Endereço: " << elemento << " Valor: " << elemento->dado << " Prox. Endereço:  " << elemento->prox << endl;
      cout << " " << endl;
      elemento = elemento->prox;
    }
    return;
  }

  void excluirUltimoNo(No *elemento)
  {
    No *ultimoNo = elemento->listarUltimoNo(elemento);
    while (elemento)
    {
      if (ultimoNo == elemento->prox)
      {
        elemento->prox = NULL;
        system("clear");
        cout << "Elemento excluído com sucesso" << endl;
        return;
      }
      elemento = elemento->prox;
    };
  }
};

int main()
{
  No *elemento = new No;
  int opcao;
  while (opcao == 0)
  {
    system("clear");
    cout << "Selecione o que deseja: \n 1 - Cadastrar No \n 2 - Mostrar Lista Completa \n 3 - Buscar No por ID \n 4 - Excluir o ultimo elemento da lista" << endl;
    cin >> opcao;

    if (opcao == 1)
    {
      int valor, quantidade;
      system("clear");
      cout << "Quantos nos deseja cadastrar? " << endl;
      cin >> quantidade;
      for (int i = 0; i < quantidade; i++)
      {
        system("clear");
        cout << "Digite o valor inteiro: " << endl;
        cin >> valor;
        elemento->inserirNo(elemento, valor, i + 1);
      }
      cout << "Elementos cadastrados com sucesso" << endl;
      opcao = 0;
    }
    if (opcao == 2)
    {
      system("clear");
      elemento->mostrarLista(elemento);
      cout << "\nPressione qualquer tecla para continuar..." << endl;
      getchar();
      getchar();
      opcao = 0;
    }

    if (opcao == 3)
    {
      int id;
      system("clear");
      cout << "Digite o ID que deseja buscar: " << endl;
      cin >> id;
      elemento->listarNo(elemento, id);
      opcao = 0;
    }

    if (opcao == 4)
    {
      elemento->excluirUltimoNo(elemento);
      cout << "\nPressione qualquer tecla para continuar..." << endl;
      getchar();
      getchar();
      opcao = 0;
    }
  }
}