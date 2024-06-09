#include <iostream>

using namespace std;

class Rectangulo{ 
private:
  float _largo, _ancho; //atributos o miembros

public://metodos
  Rectangulo(float, float); //constructor
  void perimetro();
  void area();

};

Rectangulo::Rectangulo(float largo, float ancho){
  _largo = largo;
  _ancho = ancho;
}

void Rectangulo::perimetro(){ //void solo muestra
  float peri;

  peri = (2*_largo) + ( 2*_ancho); // se suman los dos largos y los dos anchos del rectangulo 

  cout << "El perimetro es: " <<peri;
}

void Rectangulo::area(){ 
  float area;

  area = _largo * _ancho; // el area es largo por ancho
  cout << "EL area es: " << area;
}

int main(){
  //CREAR OBJETOS se le dice INSTANCIAR LA CLASE!

  Rectangulo r1(11, 7); //11 de largo y 7 de ancho
  //se pueden poner las variables tambien que ingreso con CIN el usuario

  r1.perimetro();
  r1.area();


  return 0;
}