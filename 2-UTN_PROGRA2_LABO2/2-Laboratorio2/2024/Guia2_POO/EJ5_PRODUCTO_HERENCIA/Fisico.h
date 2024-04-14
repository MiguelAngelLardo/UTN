#pragma once
#include "Producto.h"

class Fisico:public Producto{
private:
  int _stockActual;
  int _stockMin;

public:
 // Fisico(int stockAct = 0, int stockMin = 0);
  Fisico(int stockAct = 0, int stockMin = 0, std::string nom = "S/N", const char* id = "0000", float precio = 0.0);


  void setStockActual(int stockAct);
  void setStockMin(int stockMin);

  int getStockActual();
  int getStockMin();

  void cargarFisico();
  void mostrarFisico();
} ;

//CONSTRUCTOR
Fisico::Fisico(int stockAct, int stockMin, std::string nom, const char* id, float precio)
       : Producto(nom, id, precio), _stockActual(stockAct), _stockMin(stockMin) {
  if(stockAct < 0 || stockMin < 0) {
    std::cout << " CONST => NO PUEDEN EXISTIR PRODUCTOS CON STROCK NEGATIVO" << std::endl;
  }else if(stockAct <= stockMin){
    std::cout << "CONST => DEBE REPONER STOCK (CANTIDAD IGUAL O MENOR INVALIDA!!" << std::endl; 
  }else{
    _stockActual = stockAct;
    _stockMin = stockMin;
  }
} 

//SET
void Fisico::setStockActual(int stockAct){
  if(stockAct < 0 ) {
    std::cout << "SET => NO PUEDEN EXISTIR PRODUCTOS CON STOCK NEGATIVO" << std::endl;
  }else if(stockAct <= _stockMin){
    std::cout << "SET => DEBE REPONER STOCK!!" << std::endl; 
  }else{
    _stockActual = stockAct;
  }
}

void Fisico::setStockMin(int stockMin){
  if(stockMin < 0){
    std::cout << "SET => NO PUEDEN EXISTIR PRODUCTOS CON STOCKMINIMO NEGATIVO" << std::endl;
  }else{
    _stockMin = stockMin;
  }
}

//GET
int Fisico::getStockActual(){return _stockActual;}
int Fisico::getStockMin(){return _stockMin;}


//CARGAR-LISTAR
void Fisico::cargarFisico(){
  Producto::cargar();
  std::cout << "\nCARGA FISICO\n";
  std::cout << "STOCK ACTUAL: ";
  std::cin >> _stockActual;
  std::cout << "STOCK MINIMO: ";
  std::cin >> _stockMin;

}
void Fisico::mostrarFisico(){
  Producto::mostrar();
  std::cout << "\nMOSTRAR FISICO\n";
  std::cout << "STOCK ACTUAL: " << _stockActual << std::endl;
  std::cout << "STOCK MINIMO: " << _stockMin << std::endl;
}
