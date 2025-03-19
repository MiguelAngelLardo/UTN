#include <iostream>
using namespace std;
#include "Temporizador.h"

Temporizador::Temporizador(int hora, int minuto, int segundo){
   if (hora < 0 || (minuto > 59 || minuto < 0) || (segundo > 59 || segundo < 0)){
      _hora = 0;
      _minuto = 0;
      _segundo = 0;
   }
   else{
      _hora = hora;
      _minuto = minuto;
      _segundo = segundo;
   }
}

void Temporizador::mostrarHora(){
   if (_hora <= 9){
      cout << "0" << _hora;
   }
   else{
      cout << _hora;
   }
   cout << ":";
}
void Temporizador::mostrarMinuto(){
   if (_minuto <= 9){
      cout << "0" << _minuto;
   }
   else{
      cout << _minuto;
   }
   cout << ":";
}
void Temporizador::mostrarSegundo(){
   if (_segundo <= 9){
      cout << "0" << _segundo;
   }
   else{
      cout << _segundo;
   }
   cout << endl;
}

void Temporizador::mostrar(){

//   mostrarHora();
//   mostrarMinuto();
//   mostrarSegundo();

   cout << (_hora <= 9 ? "0" : "" ) << _hora << ":";
   cout << (_minuto <= 9 ? "0" : "" ) << _minuto << ":";
   cout << (_segundo <= 9 ? "0" : "" ) << _segundo << endl;
}

int Temporizador::comparar(Temporizador aux){

   int totalSegundos, totalSegundosAux;
   totalSegundos = _hora * 3600 + _minuto * 60 + _segundo;
   totalSegundosAux = aux._hora * 3600 + aux._minuto * 60 + aux._segundo;

   if (totalSegundos == totalSegundosAux){
      return 0;
   }

   if (totalSegundos > totalSegundosAux){
      return 1;
   }

   if (totalSegundos < totalSegundosAux){
      return -1;
   }
}

void Temporizador::tic(){
   _segundo++;

   if (_segundo == 60){
      _segundo = 0;
      _minuto++;
      if (_minuto == 60){
         _minuto = 0;
         _hora++;
      }
   }
}

void Temporizador::tac(){
   tic();
}