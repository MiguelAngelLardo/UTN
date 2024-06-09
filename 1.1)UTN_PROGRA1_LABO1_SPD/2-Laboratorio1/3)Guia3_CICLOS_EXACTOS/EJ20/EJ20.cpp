#include <iostream>
#include <iomanip> 
using namespace std;

int main() 
{
  const int PARTIDOS_FUTBOL = 5;

  int numeroPartido, minJugados, tarjetaAmarilla, tarjetaRoja, goles, contPartidoNoJugado = 0, contPartidoCompleto = 0, acumulaTarjetas = 0, mayorCantGoles, partidoMayorCantGoles, contPartidosRacha = 0;
  bool bandera = false, banderaRacha = false;
  
  for(int x = 0; x < PARTIDOS_FUTBOL; x ++)
  {
    cout << endl << "Ingrese el numero de partido: ";
    cin >> numeroPartido;
    cout << "Ingrese los minutos jugados: ";
    cin >> minJugados;
    cout << "Ingrese las tarjetas amarillas: ";
    cin >> tarjetaAmarilla;
    cout << "Ingrese las tarjetas rojas: ";
    cin >> tarjetaRoja;
    cout << "Ingrese los goles: ";
    cin >> goles;

    if(minJugados == 0)
      contPartidoNoJugado ++;
    else if (minJugados >= 90)
      contPartidoCompleto ++;  

    if (goles > 0)
    { 
      banderaRacha = true;
      if(banderaRacha)
      {
        contPartidosRacha ++;
      }
    }else if (goles == 0){
      banderaRacha = false;
      contPartidosRacha = 0;
    }

    if (tarjetaAmarilla > 0)
      acumulaTarjetas += tarjetaAmarilla;
    
    if (tarjetaRoja > 0)
      acumulaTarjetas += tarjetaRoja;
    
    if(!bandera){
      mayorCantGoles = goles;
      partidoMayorCantGoles = numeroPartido;
      bandera = true;
    }else if (goles > mayorCantGoles){
      mayorCantGoles = goles;
      partidoMayorCantGoles = numeroPartido;
    }
  }

  cout << endl <<  "La cantidad de partidos que no se jugaron: " << contPartidoNoJugado << endl;
  cout << "La cantidad de partidos que si se jugaron: " << contPartidoCompleto << endl;
  cout << "El promedio de tarjetas por partido es: " << fixed << setprecision(2) << static_cast<float>(acumulaTarjetas) / PARTIDOS_FUTBOL << endl;
  cout << "Mayor cantidad de goles: " << mayorCantGoles << ". Numero de partido: " << partidoMayorCantGoles << endl;
  cout << "Cantidad de partidos consecutivos con goles marcados: " << contPartidosRacha;

	return 0;
}