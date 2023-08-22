#include <iostream>

using namespace std;

class Pessoa
{
public:
  int id;
  string nome;

public:
  Pessoa(int id, string nome)
  {
    this->id = id;
    this->nome = nome;
  }
  ~Pessoa() {}

  int getId()
  {
    return id;
  }
  string getNome()
  {
    return nome;
  }
  void mostrar()
  {
    cout << "ID: " << getId() << "\nNome: " << getNome() << endl;
  }
};

class Motorista : public Pessoa
{
private:
  string cnh;

public:
  Motorista(int id, string nome, string cnh) : Pessoa(id, nome)
  {
    this->id = id;
    this->nome = nome;
    this->cnh = cnh;
  };
  ~Motorista() {}

  string getCnh()
  {
    return cnh;
  }
  void mostrar()
  {
    cout << "ID: " << getId() << "\nNome: " << getNome() << "\nCNH: " << getCnh() << endl;
  }
};

class Secretaria : public Pessoa
{
private:
  string departamento;

public:
  Secretaria(int id, string nome, string departamento) : Pessoa(id, nome)
  {
    this->id = id;
    this->nome = nome;
    this->departamento = departamento;
  }
  ~Secretaria() {}

  string getDepartamento()
  {
    return departamento;
  }
  void mostrar()
  {
    cout << "ID: " << getId() << "\nNome: " << getNome() << "\nDepartamento: " << getDepartamento() << endl;
  }
};

class Automovel
{
private:
  string placa, modelo, marca;
  int ano;

public:
  Automovel(string placa, string modelo, string marca, int ano)
  {
    this->placa = placa;
    this->ano = ano;
    this->modelo = modelo;
    this->marca = marca;
  }
  ~Automovel(){}

  void visualizar()
  {
    cout << "Modelo: " << modelo << "\nMarca: " << marca << "\nPlaca: " << placa << "\nAno: " << ano << endl;
  }
};

class Acessorios {
  private: 
    bool direcaoEletrica, arCondicionado, multimidia;

  public:
    Acessorios(bool direcaoEletrica, bool arCondicionado, bool multimidia){
      this->direcaoEletrica = direcaoEletrica;
      this->arCondicionado = arCondicionado;
      this->multimidia = multimidia;
    }
    ~Acessorios(){}

    void listar(Automovel *car){
      car->visualizar();
      printf("============= ACESSORIOS ============ \n");
      cout << "Direção eletrica? " << direcaoEletrica << "\nAr Condicionado?" << arCondicionado << "\nMultimidia? " << multimidia << endl;
    }
};

class Viagem
{
private:
  string dataIda, dataVolta;
  float kmInicial, kmFinal;
  Automovel *automovel;
  Motorista *motorista;

public:
  Viagem(Motorista *motorista, Automovel *automovel, string dataIda, string dataVolta, float kmInicial, float kmFinal)
  {
    this->dataIda = dataIda;
    this->dataVolta = dataVolta;
    this->kmInicial = kmInicial;
    this->kmFinal = kmFinal;
    this->automovel = automovel;
    this->motorista = motorista;
  }
  ~Viagem() {}

  void imprimir()
  {
    printf("=========== VIAGEM ================\n");
    printf("\n\n");
    printf("=========== MOTORISTA ================\n");
    motorista->mostrar();
    printf("=========== AUTOMOVEL ================\n");
    automovel->visualizar();
    printf("=========== DETALHES =================\n");
    cout << "Data de Ida: " << dataIda << "\nData de Volta: " << dataVolta << "\nKm Inicial: " << kmInicial << "\nKm Final: " << kmFinal << endl;
  }

  float kmViagem()
  {
    float kmTotal = kmFinal - kmInicial;
    cout << "Km Total da Viagem: " << kmTotal << "Km" << endl;
    return kmTotal;
  }
};

int main()
{
  Pessoa pes(1, "Gabriel");
  pes.mostrar();
  Motorista mot(2, "Rafael", "1234");
  mot.mostrar();
  Secretaria sec(3, "Leonarda", "RH");
  sec.mostrar();
  Automovel car("123ABC", "2013", "VOLVO", 2013);
  car.visualizar();
  Acessorios acessorios(1, 1 ,1);
  acessorios.listar(&car);
  Viagem viagem(&mot, &car, "20/06/2001", "30/06/2001", 13.05, 103.05);
  viagem.imprimir();
  viagem.kmViagem();
}