#include <iostream>
using namespace std;

int main() 
{
  int dado1, dado2, puntajeRonda, diferenciaAbosluta, acumuladorPuntajeTotal = 0;
 
  for (int x = 0; x < 3; x ++)
  {
    puntajeRonda = 0, diferenciaAbosluta = 0;
    cout << "Ingrese el valor del dado 1 (1 al 6): ";
    cin >> dado1;
    cout << "Ingrese el valor del dado 2 (1 al 6): ";
    cin >> dado2;

    if(dado1 == 1 && dado2 == 1 || dado1 == 6 && dado2 == 6)
      puntajeRonda = 10;  
      
    diferenciaAbosluta = dado1 - dado2;
    if(diferenciaAbosluta < 0)
      diferenciaAbosluta *= -1;
    
    if (diferenciaAbosluta > 1)
      puntajeRonda = diferenciaAbosluta;

    if (diferenciaAbosluta == 1 || diferenciaAbosluta == 5){
      acumuladorPuntajeTotal = 0;
      puntajeRonda = 0;
    }  
    
    acumuladorPuntajeTotal += puntajeRonda;

    cout << "El puntaje de la ronda es: " << puntajeRonda << endl;  
  }
    cout << "El puntaje total de las 3 rondas es: " << acumuladorPuntajeTotal << endl;  
}