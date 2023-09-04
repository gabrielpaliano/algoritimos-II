#include <iostream>

using namespace std;

class Pessoa {
  private:
    int id;
    string nome;
  public:
    // Método construtor e destruto
    Pessoa() {}
    ~Pessoa() {}
    // Método para atribuir valores a cada atributo
    void setId(int id){
      this->id = id;
    }
    void setNome(string nome){
      this->nome = nome;
    }
    // Método para retornar os valores com métodos do tipo igual ao tipo do atributo, String = String, Int = Int.
    int getId(){
      return id;
    }
    string getNome(){
      return nome;
    }
      void mostrarDados(){
        cout << this->getId() << " - " << this->getNome() << endl;
    }
};

// Paciente : Pessoa - Significa que a classe paciente é herança da classe Pessoa. Ele herda os métodos e atributos da classe pai
class Paciente : public Pessoa {
  private:
    float peso, altura;

  public:
    Paciente() {}
    ~Paciente() {}

    void setPeso(float peso){
      this->peso = peso;
    }
    void setAltura(float altura){
      this->altura = altura;
    }
    float getPeso(){
      return peso;
    }
    float getAltura(){
      return altura;
    }
    void mostrarDados(){
      cout << this->getId() << " - " << this->getNome() << "\nAltura: " << this->getAltura() << "\nPeso: " << this->getPeso() << endl;
    }
};

// MAIN
int main(){
  Pessoa pes;
  Paciente pac;

  pes.setId(1);
  pes.setNome("Gabriel");
  pes.mostrarDados();

  pac.setId(2);
  pac.setNome("Leonarda");
  pac.setPeso(68.5);
  pac.setAltura(1.71);
  pac.mostrarDados();
}