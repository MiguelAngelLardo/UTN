#include <iostream>
using namespace std;

const int FRASCO = 75, BRIANCETAMOL = 45, PINTOXICILINA = 2000, ACSIMONITICO = 7;
 
int main(){
 
  int cantidadFrascos, pastillasPorFrasco, cantidadBrian, cantidadPinto, cantidadSimon;

  cout << "Ingrese la cantidad de frascos que necesita pedir: ";
  cin >> cantidadFrascos;

  pastillasPorFrasco = cantidadFrascos * FRASCO;
  cantidadBrian = pastillasPorFrasco * BRIANCETAMOL;
  cantidadPinto = pastillasPorFrasco * PINTOXICILINA;
  cantidadSimon = pastillasPorFrasco * ACSIMONITICO;

  cout << "Necesitas " << cantidadBrian << " mg de Briancetamol, " << cantidadPinto << " mg de Pintoxicilina, " << cantidadSimon << " mg de Acido Simonitico.";

  return 0;
}