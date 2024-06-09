#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int numeroAvion, numeroAvionActual, diaDeVuelo, asientosVendidos, asientosNoVendidos, minutosDePuntualidad;
  int acumuladorMinutosAtrasoDelVuelo, mayorCantidadMinutosAtrasados = 0, numeroAvionMayorCantidadMinutosAtrasado; // B)
  int mayorAtrasoIndividualDeTodosLosGrupos = 0, diaMayorAtrasoindividual, avionMayorAtrasoIndivual;  //C)
  int avionMenorPorcentaje;//A)
  float porcentajeAsientosOcupadosDelVueloActual, menorPorcentajeAsientosOcupados; //A)

  cout << "Ingrese el numero de avion (1 a 50): ";
  cin >> numeroAvion;
  cout << "dia de vuelo (1 a 31): ";
  cin >> diaDeVuelo;
  cout << "Cantidad de asientos vendidos: ";
  cin >> asientosVendidos;
  cout << "Cantidad de asientos NO vendidos: ";
  cin >> asientosNoVendidos;  
  cout << "Puntualidad (> 0 es atradado, 0 es a horario, < 0 adelantado): ";
  cin >> minutosDePuntualidad;

  while(numeroAvion != 0)
  {
    porcentajeAsientosOcupadosDelVueloActual = 0; //A)
    menorPorcentajeAsientosOcupados = 0;//A)
    acumuladorMinutosAtrasoDelVuelo = 0;//C)

    numeroAvionActual = numeroAvion;
    while(numeroAvionActual == numeroAvion)
    {
      porcentajeAsientosOcupadosDelVueloActual = (float)asientosVendidos*100/(asientosVendidos+asientosNoVendidos); //A)
      
      if (menorPorcentajeAsientosOcupados == 0){
        menorPorcentajeAsientosOcupados = porcentajeAsientosOcupadosDelVueloActual;
        avionMenorPorcentaje = numeroAvion;
      }else if (porcentajeAsientosOcupadosDelVueloActual < menorPorcentajeAsientosOcupados){
        menorPorcentajeAsientosOcupados = porcentajeAsientosOcupadosDelVueloActual;
        avionMenorPorcentaje = numeroAvion;
      }

      cout << fixed << setprecision(2) << "Porcentaje de acientos ocupados actuales: " << porcentajeAsientosOcupadosDelVueloActual << endl;

      if(minutosDePuntualidad > 0){ //B)
        acumuladorMinutosAtrasoDelVuelo = minutosDePuntualidad;
      }

      if (minutosDePuntualidad > 0){ //C)
        if(mayorAtrasoIndividualDeTodosLosGrupos == 0){
          mayorAtrasoIndividualDeTodosLosGrupos = minutosDePuntualidad;
          diaMayorAtrasoindividual = diaDeVuelo;
          avionMayorAtrasoIndivual = numeroAvion;
        }else if(minutosDePuntualidad > mayorAtrasoIndividualDeTodosLosGrupos){
          mayorAtrasoIndividualDeTodosLosGrupos = minutosDePuntualidad;
          diaMayorAtrasoindividual = diaDeVuelo;
          avionMayorAtrasoIndivual = numeroAvion;
        }
      }

      cout << "Ingrese el numero de avion (1 a 50): ";
      cin >> numeroAvion;
      if (numeroAvion != 0){
        cout << "dia de vuelo (1 a 31): ";
        cin >> diaDeVuelo;
        cout << "Cantidad de asientos vendidos: ";
        cin >> asientosVendidos;
        cout << "Cantidad de asientos NO vendidos: ";
        cin >> asientosNoVendidos;  
        cout << "Puntualidad (> 0 es atradado, 0 es a horario, < 0 adelantado): ";
        cin >> minutosDePuntualidad;
      }  

    }

      if (mayorCantidadMinutosAtrasados == 0){ //B)
        mayorCantidadMinutosAtrasados = acumuladorMinutosAtrasoDelVuelo;
        numeroAvionMayorCantidadMinutosAtrasado = numeroAvionActual;
      }else if(acumuladorMinutosAtrasoDelVuelo > mayorCantidadMinutosAtrasados){
        mayorCantidadMinutosAtrasados = acumuladorMinutosAtrasoDelVuelo;
        numeroAvionMayorCantidadMinutosAtrasado = numeroAvionActual;
      }

  }

  cout << endl << "Avion con mayor cantidad de minutos de atraso: " << numeroAvionMayorCantidadMinutosAtrasado << ". Minutos de atras: " << mayorCantidadMinutosAtrasados << endl;
  cout << "El Avion con mayor atraso individual: " << avionMayorAtrasoIndivual << ". Fue el dia: " << diaMayorAtrasoindividual << ". Los minutos fueron: "<< mayorAtrasoIndividualDeTodosLosGrupos << endl;
  cout << "Numero de avion con menor porcentaje de asientos ocupados: " << avionMenorPorcentaje << " El porcentaje fue %" << menorPorcentajeAsientosOcupados << "." << endl;

  return 0;
}