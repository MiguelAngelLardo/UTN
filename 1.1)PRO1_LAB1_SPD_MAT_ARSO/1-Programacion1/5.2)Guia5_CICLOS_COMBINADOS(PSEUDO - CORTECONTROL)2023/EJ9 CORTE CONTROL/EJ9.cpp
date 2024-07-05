#include <iostream>
using namespace std;

int main() 
{
  int numeroArticulo, dia, cantidadArticulosVendidos, numeroArticuloActual, totalArticulosVendidosDelgrupo;
  int CantidadMasVendidosEntreTodosLosGrupos, numeroArticuloMasVendidoEntreTodosLosGrupos;
  int cantidadArticulosVendidosSemana1, cantidadArticulosVendidosSemana2, cantidadArticulosVendidosSemana3,cantidadArticulosVendidosSemana4;
  int contadorMayorVentaSemana1 = 0, contadorMayorVentaSemana2 = 0, contadorMayorVentaSemana3 = 0, contadorMayorVentaSemana4 = 0;
  float importesRecaudadoVentasEnElDia, recuadacionTotalDelGrupo;
  bool banderaMasVendidos = false;
  
  cout << "Ingrese el numero de articulo (1 a 30): ";
  cin >> numeroArticulo;
  cout << "Ingrese el dia (1 a 31): ";
  cin >> dia;
  cout << "Ingrese la cantidad de articulos vendidos: ";
  cin >> cantidadArticulosVendidos;
  cout << "Ingrese el importe recaudado por las ventas en ese dia: ";
  cin >> importesRecaudadoVentasEnElDia;

  while(numeroArticulo != 0)
  { 
    totalArticulosVendidosDelgrupo = 0;
    recuadacionTotalDelGrupo = 0;
    cantidadArticulosVendidosSemana1 = 0, cantidadArticulosVendidosSemana2 = 0, cantidadArticulosVendidosSemana3 = 0, cantidadArticulosVendidosSemana4 = 0;
    
    numeroArticuloActual = numeroArticulo;
    while (numeroArticulo == numeroArticuloActual)
    {
      if(dia >= 1 && dia <=15){
        totalArticulosVendidosDelgrupo += cantidadArticulosVendidos;
      }   

      recuadacionTotalDelGrupo += importesRecaudadoVentasEnElDia;

      if(dia >= 1 && dia <= 7){
        cantidadArticulosVendidosSemana1 += cantidadArticulosVendidos;
      }else if(dia >= 8 && dia <= 15){
        cantidadArticulosVendidosSemana2 += cantidadArticulosVendidos;
      }else if(dia >= 16 && dia <= 23){
        cantidadArticulosVendidosSemana3 += cantidadArticulosVendidos;
      }else if(dia >= 24 && dia <= 31){
        cantidadArticulosVendidosSemana4 += cantidadArticulosVendidos;
      }

      cout << "Ingrese el numero de articulo (1 a 30): ";
      cin >> numeroArticulo;
      if(numeroArticulo != 0){
        cout << "Ingrese el dia (1 a 31): ";
        cin >> dia;
        cout << "Ingrese la cantidad de articulos vendidos: ";
        cin >> cantidadArticulosVendidos;
        cout << "Ingrese el importe recaudado por las ventas en ese dia: ";
        cin >> importesRecaudadoVentasEnElDia;
      }  
    }

    if(cantidadArticulosVendidosSemana1 > cantidadArticulosVendidosSemana2 && cantidadArticulosVendidosSemana1 > cantidadArticulosVendidosSemana3 && cantidadArticulosVendidosSemana1 > cantidadArticulosVendidosSemana4){
      contadorMayorVentaSemana1 += cantidadArticulosVendidosSemana1;
    } else if (cantidadArticulosVendidosSemana2 > cantidadArticulosVendidosSemana1 && cantidadArticulosVendidosSemana2 > cantidadArticulosVendidosSemana3 && cantidadArticulosVendidosSemana2 > cantidadArticulosVendidosSemana4) {
      contadorMayorVentaSemana2 += cantidadArticulosVendidosSemana2;
    } else if (cantidadArticulosVendidosSemana3 > cantidadArticulosVendidosSemana1 && cantidadArticulosVendidosSemana3 > cantidadArticulosVendidosSemana2 && cantidadArticulosVendidosSemana3 > cantidadArticulosVendidosSemana4) {
      contadorMayorVentaSemana3 += cantidadArticulosVendidosSemana3;
    } else if (cantidadArticulosVendidosSemana4 > cantidadArticulosVendidosSemana1 && cantidadArticulosVendidosSemana4 > cantidadArticulosVendidosSemana2 && cantidadArticulosVendidosSemana4 > cantidadArticulosVendidosSemana3) {
      contadorMayorVentaSemana4 += cantidadArticulosVendidosSemana4;
    }

     if(!banderaMasVendidos)
     {
       CantidadMasVendidosEntreTodosLosGrupos = totalArticulosVendidosDelgrupo;
       numeroArticuloMasVendidoEntreTodosLosGrupos = numeroArticuloActual;
       banderaMasVendidos = true;
     }
     else
     {
       if(totalArticulosVendidosDelgrupo > CantidadMasVendidosEntreTodosLosGrupos)
       {
         CantidadMasVendidosEntreTodosLosGrupos = totalArticulosVendidosDelgrupo;
         numeroArticuloMasVendidoEntreTodosLosGrupos = numeroArticuloActual;
       }
     }

     cout << endl << "Articulo " << numeroArticuloActual <<": posee " << recuadacionTotalDelGrupo << " ventas. " << endl;
  }
  
   cout << "El numero de articulo mas vendidos en la primer quincena es el " << numeroArticuloMasVendidoEntreTodosLosGrupos << ". Posee " << CantidadMasVendidosEntreTodosLosGrupos << " ventas." << endl;

  if(contadorMayorVentaSemana1  > contadorMayorVentaSemana2 && contadorMayorVentaSemana1 > contadorMayorVentaSemana3 && contadorMayorVentaSemana1 > contadorMayorVentaSemana4)
    cout << "La semana 1 fue la que mayor ventas tuvo." << endl;
  else if(contadorMayorVentaSemana2 > contadorMayorVentaSemana1 && contadorMayorVentaSemana2 > contadorMayorVentaSemana3 && contadorMayorVentaSemana2 > contadorMayorVentaSemana4)
    cout << "La semana 2 fue la que mayor ventas tuvo." << endl;
  else if(contadorMayorVentaSemana3  > contadorMayorVentaSemana1 && contadorMayorVentaSemana3 > contadorMayorVentaSemana2 && contadorMayorVentaSemana3 > contadorMayorVentaSemana4)
    cout << "La semana 3 fue la que mayor ventas tuvo." << endl;
  else if(contadorMayorVentaSemana4  > contadorMayorVentaSemana1 && contadorMayorVentaSemana4 > contadorMayorVentaSemana2 && contadorMayorVentaSemana4 > contadorMayorVentaSemana3)
    cout << "La semana 4 fue la que mayor ventas tuvo." << endl;

}