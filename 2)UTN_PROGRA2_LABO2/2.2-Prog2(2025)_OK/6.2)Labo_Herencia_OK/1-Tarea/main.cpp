#include <iostream>

using namespace std;
/*Vas a crear un programa que trabaje con distintos tipos de triángulos, permitiendo mostrar su tipo de triángulo y calcular su perímetro.
Los triángulos que debés representar son:
1.	🔺 Equilátero
○	Todos sus lados miden lo mismo.
○	Solo necesitás un lado.
○	Su perímetro se calcula como: lado * 3
2.	🔺 Isósceles
○	Tiene dos lados iguales y uno diferente.
○	Necesitás dos lados.
○	Su perímetro es: lado1 + lado2 * 2
3.	🔺 Escaleno
○	Todos los lados son diferentes.
○	También necesitás tres lados.
○	Su perímetro es: lado1 + lado2 * lado3
 
🛠️ Tu tarea
1.	Analizá cómo podrías estructurar tu código para evitar repetir atributos o métodos innecesarios.
2.	Cada triángulo debe poder:
○	Mostrar su tipo
○	Establecer los valores de los lados
○	Calcular su perímetro
3.	Creá estos tres triángulos con los siguientes datos:
○	Triki → equilátero de lados 5, 5, 5
○	Tito → isósceles de lados 5 , 5 y 7
○	Tobi → escaleno de lados 3, 4 y 5
4.	Hacé que cada uno muestre:
○	El tipo de triángulo
○	Su perímetro calculado correctamente
⏱️ Tiempo estimado: 10–15 minutos
💡 Pista: Si hay comportamientos o atributos en común, ¡capaz podés generalizarlos!

*/

class TrianguloBase{
protected:
  int _lado[3];
  string _tipo;

public:
  TrianguloBase():_lado{0, 0, 0}{}

  TrianguloBase(int a, int b, int c){
    _lado[0] = a;
    _lado[1] = b;
    _lado[2] = c;
  }

  virtual void mostrarTipo() = 0;
  virtual void calcularPerimetro() = 0;

};

class Equilatero: public TrianguloBase{
public:
  Equilatero(int lado):TrianguloBase(lado, lado, lado){
    _tipo = "Equilatero";
  }

  void mostrarTipo() override{
    cout << "Tipo de triangulo: " << _tipo << endl;
  }

  void calcularPerimetro() override{
    cout << "Perimetro: " << _lado[0] * 3 << endl;
  }

};

class Isosceles: public TrianguloBase{
public:
  Isosceles(int lado1, int lado2repetido)
  : TrianguloBase(lado1, lado2repetido, lado2repetido){
    _tipo = "Isosceles";
  }

  void mostrarTipo() override{
    cout << "Tipo de triangulo: " << _tipo << endl;
  }

  void calcularPerimetro() override{
    cout << "Perimetro: " << _lado[0] + _lado[1] * 2 << endl;
  }

};

class Escalenos : public TrianguloBase{
public:
  Escalenos(int lado1, int lado2, int lado3): TrianguloBase(lado1, lado2, lado3){
    _tipo = "Escaleno";
  }

  void mostrarTipo() override{
    cout << "Tipo de triangulo: " << _tipo << endl;
  }

  void calcularPerimetro() override{
    cout << "Perimetro: " << _lado[0] + _lado[1] + _lado[2] << endl;
  }

};


int main() {
  Equilatero triki(5);
  triki.mostrarTipo();
  triki.calcularPerimetro();

  TrianguloBase *Tito = new Isosceles(5, 7);
  Tito->mostrarTipo();
  Tito->calcularPerimetro();

  delete Tito;
  TrianguloBase *Tobi = new Escalenos(3, 4, 5);
  Tobi->mostrarTipo();
  Tobi->calcularPerimetro();
  delete Tobi;

    
    return 0;
}
