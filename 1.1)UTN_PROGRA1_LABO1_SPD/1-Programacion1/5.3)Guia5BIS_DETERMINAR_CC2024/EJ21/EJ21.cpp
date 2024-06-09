#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{

  int numeroAvion, numeroItinerario, diaVuelo, asientoVendido, asientoNOVendido, minPuntualidad, numeroAvionActual, numeroAvionAnterior = -1;
  char marcaAvion;
  char marcaAvionMaxPasajeros, marcaAvionMaxPasajerosDETODOSLOSVIAJES; //A)
  float porcentajeVendidos, maxCantidadAsientosVendidos, maxCantidadAsientosVendidosDETODOSLOSVIAJES = 0; //A
  float menorPorcentajeAsientosOcupados, menorPorcentajeAsientosOcupadosDETODOSLOSVIANES = 0; //B)
  int numeroAvionMenorPorcentajeAsientosOcupados, numeroAvionMenorPorcentajeAsientosOcupadosDETODOSLOSVIAJES; //B)
  int menorAtrasoMarcaA, avionMenorAtrasoMarcaA, menorAtrasoMarcaB, avionMenorAtrasoMarcaB, menorAtrasoMarcaC, avionMenorAtrasoMarcaC; //C)
  int menorAtrasoMarcaATODOSLOSVIAJES = 0, menorAtrasoMarcaBTODOSLOSVIAJES = 0, menorAtrasoMarcaCTODOSLOSVIAJES = 0, avionMenorAtrasoMarcaATODOSLOSVIAJES = 0, avionMenorAtrasoMarcaBTODOSLOSVIAJES = 0, avionMenorAtrasoMarcaCTODOSLOSVIAJES = 0; //C
  int mayorAtrasoTOTAL, mayorAtrasoItinerario, mayorAtrasoNumeroAvion; // C) 
  char mayorAtrasoMarcaAvion; //C)

  cout << "Ingrese el numero de avion (1000 a 2000 no correlativos): ";
  cin >> numeroAvion;
  while (numeroAvion != 0)
  {
    marcaAvionMaxPasajeros = 0;
    maxCantidadAsientosVendidos = 0;
    menorPorcentajeAsientosOcupados = 0;
    numeroAvionMenorPorcentajeAsientosOcupados = 0;
    menorAtrasoMarcaA = 0, avionMenorAtrasoMarcaA = 0, menorAtrasoMarcaB = 0, avionMenorAtrasoMarcaB = 0, menorAtrasoMarcaC = 0, avionMenorAtrasoMarcaC = 0;
    mayorAtrasoTOTAL = 0;
    mayorAtrasoItinerario = 0, mayorAtrasoNumeroAvion = 0, mayorAtrasoMarcaAvion = 0;

    numeroAvionActual = numeroAvion;
    while (numeroAvion == numeroAvionActual)
    { 
      if(numeroAvion >= 1000 && numeroAvion <= 2000) //VALIDA QUE NO SE CORRELATIVO
      {
        if(numeroAvion == numeroAvionAnterior +1 || numeroAvion == numeroAvionAnterior - 1){
          cout << "El numero de avion ingresado no puede ser correlativo." << endl;
        }else{
          cout << "Numero de itinerario efectuado (1 al 250): ";
          cin >> numeroItinerario;
          cout << "Dia del vuelo (1 al 31): ";
          cin >> diaVuelo;
          cout << "Cantidad de asientos vendidos: ";
          cin >> asientoVendido;
          cout << "Cantidad de asientos NO vendidos: ";
          cin >> asientoNOVendido;
          cout << "Puntualidad (> 0 es atradado, 0 es a horario, < 0 adelantado): ";
          cin >> minPuntualidad;
          cout << "Marca de Avion que efectuo el vuelo (A=Airbus, B=Boeing, C=Carrier): ";
          cin >> marcaAvion;
        }
      }else{
        cout << "El numero de avion debe estar entre 1000 y 2000." << endl;
      }

      porcentajeVendidos = (float)asientoVendido*100/(asientoVendido+asientoNOVendido);    
      
      if(diaVuelo >= 1 && diaVuelo <= 7){
        if(maxCantidadAsientosVendidos == 0){
          maxCantidadAsientosVendidos = porcentajeVendidos;
          marcaAvionMaxPasajeros = marcaAvion;
        }else if(porcentajeVendidos > maxCantidadAsientosVendidos){
          maxCantidadAsientosVendidos = porcentajeVendidos;
          marcaAvionMaxPasajeros = numeroAvion;
        }        
      }

      if (menorPorcentajeAsientosOcupados == 0){
        menorPorcentajeAsientosOcupados = porcentajeVendidos;
        numeroAvionMenorPorcentajeAsientosOcupados = numeroAvion;
      }else if(porcentajeVendidos < menorPorcentajeAsientosOcupados){
        menorPorcentajeAsientosOcupados = porcentajeVendidos;
        numeroAvionMenorPorcentajeAsientosOcupados = numeroAvion;
      }
      
      
    if (marcaAvion == 'A' && minPuntualidad > 0){
      if (menorAtrasoMarcaA == 0 || minPuntualidad < menorAtrasoMarcaA) {
          menorAtrasoMarcaA = minPuntualidad;
          avionMenorAtrasoMarcaA = numeroAvion;
      }
    }else if(marcaAvion == 'B' && minPuntualidad > 0){
      if (menorAtrasoMarcaB == 0 || minPuntualidad < menorAtrasoMarcaB)
      menorAtrasoMarcaB = minPuntualidad;
      avionMenorAtrasoMarcaB = numeroAvion;
    }else if(marcaAvion == 'C' && minPuntualidad > 0){
      if(menorAtrasoMarcaC == 0 || minPuntualidad < menorAtrasoMarcaC){
        menorAtrasoMarcaC = minPuntualidad;
        avionMenorAtrasoMarcaC = numeroAvion;
      }
    }

    if(minPuntualidad > 0){
      if(mayorAtrasoTOTAL == 0 || minPuntualidad > mayorAtrasoTOTAL){
        mayorAtrasoTOTAL == minPuntualidad;
        mayorAtrasoItinerario = numeroItinerario;
        mayorAtrasoMarcaAvion = marcaAvion;
        mayorAtrasoNumeroAvion = numeroAvion;
      }
    }
      

      numeroAvionAnterior = numeroAvion;
      cout << "Ingrese el numero de avion (1000 a 2000 no correlativos): ";
      cin >> numeroAvion;
    }
   

    if(maxCantidadAsientosVendidosDETODOSLOSVIAJES == 0){
      maxCantidadAsientosVendidosDETODOSLOSVIAJES = maxCantidadAsientosVendidos;
      marcaAvionMaxPasajerosDETODOSLOSVIAJES = marcaAvionMaxPasajeros;      
    }else if (maxCantidadAsientosVendidos > maxCantidadAsientosVendidosDETODOSLOSVIAJES){
      maxCantidadAsientosVendidosDETODOSLOSVIAJES = maxCantidadAsientosVendidos;
      marcaAvionMaxPasajerosDETODOSLOSVIAJES = marcaAvionMaxPasajeros;  
    }

    if(menorPorcentajeAsientosOcupadosDETODOSLOSVIANES == 0){
      menorPorcentajeAsientosOcupadosDETODOSLOSVIANES = menorPorcentajeAsientosOcupados;
      numeroAvionMenorPorcentajeAsientosOcupadosDETODOSLOSVIAJES = numeroAvionMenorPorcentajeAsientosOcupados;
    }else if(menorPorcentajeAsientosOcupados < menorPorcentajeAsientosOcupadosDETODOSLOSVIANES){
      menorPorcentajeAsientosOcupadosDETODOSLOSVIANES = menorPorcentajeAsientosOcupados;
      numeroAvionMenorPorcentajeAsientosOcupadosDETODOSLOSVIAJES = numeroAvionMenorPorcentajeAsientosOcupados;
    }


    if (menorAtrasoMarcaA < menorAtrasoMarcaATODOSLOSVIAJES || menorAtrasoMarcaATODOSLOSVIAJES == 0){
      menorAtrasoMarcaATODOSLOSVIAJES = menorAtrasoMarcaA;
      avionMenorAtrasoMarcaATODOSLOSVIAJES = avionMenorAtrasoMarcaA;
    }

    if (menorAtrasoMarcaB < menorAtrasoMarcaBTODOSLOSVIAJES || menorAtrasoMarcaBTODOSLOSVIAJES == 0){
      menorAtrasoMarcaBTODOSLOSVIAJES = menorAtrasoMarcaB;
      avionMenorAtrasoMarcaBTODOSLOSVIAJES = avionMenorAtrasoMarcaB;
    }

    if (menorAtrasoMarcaC < menorAtrasoMarcaCTODOSLOSVIAJES || menorAtrasoMarcaCTODOSLOSVIAJES == 0){
      menorAtrasoMarcaCTODOSLOSVIAJES = menorAtrasoMarcaC;
      avionMenorAtrasoMarcaCTODOSLOSVIAJES = avionMenorAtrasoMarcaC;
    }


    cout << endl << "Avion con mayor cantidad de minutos de atraso: " << mayorAtrasoNumeroAvion << ". Itinerario: " << mayorAtrasoItinerario << ". Marca del avion: " << mayorAtrasoMarcaAvion << endl;
    

  }  
   
  cout << endl << "La marca de avion que transporto mas cantidad de pasajeros: " << marcaAvionMaxPasajerosDETODOSLOSVIAJES << endl;   
  cout << "Menor porcentaje de asientos ocupados %" << fixed << setprecision(2) << menorPorcentajeAsientosOcupadosDETODOSLOSVIANES << ". EL numero de avion es: " << numeroAvionMenorPorcentajeAsientosOcupadosDETODOSLOSVIAJES << endl;
  
  cout << "Marca A => El avion con menor cantidad de atraso: " << avionMenorAtrasoMarcaATODOSLOSVIAJES << ". Minutos de atraso: " << menorAtrasoMarcaATODOSLOSVIAJES << " min." << endl;
  cout << "Marca B => El avion con menor cantidad de atraso: " << avionMenorAtrasoMarcaBTODOSLOSVIAJES << ". Minutos de atraso: " << menorAtrasoMarcaBTODOSLOSVIAJES << " min." << endl;
  cout << "Marca C => El avion con menor cantidad de atraso: " << avionMenorAtrasoMarcaCTODOSLOSVIAJES << ". Minutos de atraso: " << menorAtrasoMarcaCTODOSLOSVIAJES << " min." << endl << endl;

  return 0;
}