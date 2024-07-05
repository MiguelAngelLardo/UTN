#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int nroParticipante, minutos, finaliza;
  char genero;
  int contadorFemenino = 0, contadorMasculino = 0, contadorNoBin = 0; //A)
  int contadorFinaliza = 0, acumuladorTiempoFinalizado = 0; //B)
  int menorTiempoMaraton, personaMenorTiempo; //C)

  for(int nroMaraton = 0; nroMaraton < 5; nroMaraton ++)
  {
    menorTiempoMaraton = -1;
    cout << endl << "****MARATON NUMERO #" << nroMaraton+1 << "****" << endl;

    cout << "Ingrese el numero de participante (corta con -1): ";
    cin >> nroParticipante;
    if(nroParticipante > 0){
      cout << "Ingrese el genero (F-M-X): ";
      cin >> genero;
      cout << "Ingrese el tiempo (Minutos): ";
      cin >> minutos;
      cout << "Finaliza (1 si, 0 no): ";
      cin >> finaliza;
    }  

    while(nroParticipante > 0)
    {
      cout << endl << "****MARATON NUMERO #" << nroMaraton+1 << "****" << endl;

      switch (genero)
      {
        case 'F':
        case 'f':
          contadorFemenino ++;
        break;
        case 'M':
        case 'm':
          contadorMasculino ++;
        break;
        case 'X':
        case 'x':
          contadorNoBin ++;
        break;
      }

      if(finaliza == 1)
      {
        contadorFinaliza ++;
        acumuladorTiempoFinalizado += minutos;
      }

      if(menorTiempoMaraton == -1 && finaliza == 1){
        menorTiempoMaraton = minutos;
        personaMenorTiempo = nroParticipante;
      }else if(minutos < menorTiempoMaraton && finaliza == 1){
        menorTiempoMaraton = minutos;
        personaMenorTiempo = nroParticipante;
      }

      cout << "Ingrese el numero de participante (corta con -1): ";
      cin >> nroParticipante;
      if(nroParticipante > 0){
        cout << "Ingrese el genero (F-M-X): ";
        cin >> genero;
        cout << "Ingrese el tiempo (Minutos): ";
        cin >> minutos;
        cout << "Finaliza (1 si, 0 no): ";
        cin >> finaliza;
      }  
    }
    
    cout << endl << "En la maraton #" << nroMaraton + 1 << " el menor tiempo fue " << menorTiempoMaraton << " min. El corredor numero: " << personaMenorTiempo << endl;

  }

  cout << endl << "Porcentaje participante femenino: %" << fixed << setprecision(2) << (float)contadorFemenino*100 /(contadorFemenino + contadorMasculino + contadorNoBin) << endl;
  cout << "Porcentaje participante masculino: %" << fixed << setprecision(2) << (float)contadorMasculino*100 /(contadorFemenino + contadorMasculino + contadorNoBin) << endl;
  cout << "Porcentaje participante No binario: %" << fixed << setprecision(2) << (float)contadorNoBin*100 /(contadorFemenino + contadorMasculino + contadorNoBin) << endl;
  cout << "El promedio entre los participantes que finalizaron es: " << (float)acumuladorTiempoFinalizado / contadorFinaliza << endl;
  return 0;
  
}