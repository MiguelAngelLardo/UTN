#include <iostream>

using namespace std;

int main()
{
  int numero = 10;
  int *pNumero = nullptr; //por buena practica se inicializa con nullptr
  int &rNumero = numero;// creamos una referencia (es como si crearamos un alias) - si o si va inicializado
  
  if(pNumero == nullptr){
     pNumero = &numero; // == pNumero = &rNumero;
  }


  cout << "Numero: " << numero << endl;
  cout << "Referencia numero: " << &numero << endl << endl;

  cout << "rNumero: " << rNumero << endl;
  cout << "Referencia rNumero: " << &rNumero << endl << endl;

  cout << "pNumero : " << pNumero << endl;
  cout << "&pNumero: " << &pNumero << endl;
  cout << "*pNumero: " << *pNumero << endl << endl;

  cout << "rNumero = 120" << endl;
  rNumero = 120;

  cout << "Numero: " << numero << endl;
  cout << "Referencia numero: " << &numero << endl << endl;

  cout << "rNumero: " << rNumero << endl;
  cout << "Referencia rNumero: " << &rNumero << endl << endl;

  cout << "pNumero : " << pNumero << endl;
  cout << "&pNumero: " << &pNumero << endl;
  cout << "*pNumero: " << *pNumero << endl << endl;

  cout << "*pNumero = 500" << endl;
  *pNumero = 500;

  cout << "Numero: " << numero << endl;
  cout << "Referencia numero: " << &numero << endl << endl;

  cout << "rNumero: " << rNumero << endl;
  cout << "Referencia rNumero: " << &rNumero << endl << endl;

  cout << "pNumero : " << pNumero << endl;
  cout << "&pNumero: " << &pNumero << endl;
  cout << "*pNumero: " << *pNumero << endl << endl;


  cout << "rNumero = 700" << endl;
  cout << "pNumero = &rNumero" << endl;

  rNumero = 700;
  pNumero = &rNumero;
  cout << "Numero: " << numero << endl;
  cout << "Referencia numero: " << &numero << endl << endl;

  cout << "rNumero: " << rNumero << endl;
  cout << "Referencia rNumero: " << &rNumero << endl << endl;

  cout << "pNumero : " << pNumero << endl;
  cout << "&pNumero: " << &pNumero << endl;
  cout << "*pNumero: " << *pNumero << endl << endl;




    return 0;
}