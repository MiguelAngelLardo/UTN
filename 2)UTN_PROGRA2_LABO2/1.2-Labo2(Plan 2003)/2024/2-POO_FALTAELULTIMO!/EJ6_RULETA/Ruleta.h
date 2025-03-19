#pragma once
#include <ctime>   //para la semilla
#include <cstdlib> // para rand

class Ruleta{
private:
  string *_vPremios;// Puntero a un arreglo de std::string
  int _cantidadPremios; // Para el ARRAY DINAMICO => Viene desde crearRuleta()
  int _numeroRand;

public:
  ///DUDA PARA BRIAN
  Ruleta(int cantPremio = 1); ///como hago para que funcione sin este numero "absurdo"???????
  ~Ruleta();

  ///GET TRADICIONAL
  int getCantidadPremios();
  int getNumeroRand();
  string getvPremios(int indice);

  ///MAGIA
  void girarRuleta();
  void agregarPremio(string premio, int indice);
};

///CONSTRUCTOR Y DESTRUCTOR
Ruleta::Ruleta(int cantPremios) : _vPremios(nullptr) {///inicializo  _vPremios
  srand(time(0)); // Inicializar la semilla del generador de números aleatorios
  if(cantPremios >= 1 && cantPremios <=50){
    _cantidadPremios = cantPremios;
    _vPremios = new string [_cantidadPremios];
    if(_vPremios == nullptr){
      cout << "NO HAY MEMORIA DINAMICA!!";
      exit(-200);
    }
  }else{
    cout << "CONSTRUCTOR => CANTIDAD INVALIDA, RECUERDE INGRESAR DESDE 1 HASTA 50. DISFRUTE DEL JUEGO!";
  }
}

Ruleta::~Ruleta(){
  delete [] _vPremios;
  cout << endl <<"ME ELIMINE =(";
}

///PUNTO A
void Ruleta::agregarPremio(string nuevoPremio, int indice){
  if(indice < _cantidadPremios){//si tengo 20 de cantidad tengo que ir desde indice 0 al 19
    _vPremios[indice] = nuevoPremio;
    //_indice ++;
  }
}

///PUNTO B
void Ruleta::girarRuleta(){
  _numeroRand = rand () % _cantidadPremios; //desde 0 hasta cant premios-1
}


///GETTER Y SETTER NORMALITOS (Nihil novum sub sole)
int Ruleta::getCantidadPremios(){return _cantidadPremios;}
int Ruleta::getNumeroRand(){return _numeroRand;}
string Ruleta::getvPremios(int indice) {
  if (indice >= 0 && indice < _cantidadPremios) {
    return _vPremios[indice];
  } else {
    return "Índice de premio fuera de rango";
  }
}
