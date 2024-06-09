#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int nroComanda, nroMozo, tipoPlato;
  float importe;
  int platoEntrada, platoPrincipal, platoPostre; //A)
  int numeroMozoMenorImporte, numeroMozoMenorGENERAL; //B)
  float menorImportePlatoPPALDelMozo, menorImporteGENERAL = -1; //B)
  int contadorComanda = 0;
  float acumuladorImporte = 0;

  cout << "Ingrese el numero de comanda: ";
  cin >> nroComanda;
  cout << "Ingrese el numero de mozo (-1 para salir): ";
  cin >> nroMozo;
 
  while(nroMozo > 0)
  {
    platoEntrada = 0, platoPrincipal = 0, platoPostre = 0; //A)
    numeroMozoMenorImporte, menorImporteGENERAL = -1; //B)
    menorImportePlatoPPALDelMozo = -1; //B)

    for (int x = 0; x < 3; x ++) //10 comandas por mozo
    {
      cout << endl << "****Comanda " << x+1 << " del mozo: " << nroMozo << " (comanda " << nroComanda << ")****" << endl;
      cout << "Ingrese el tipo de plato (1-entrada, 2 - plato principal, 3 - postre): ";
      cin >> tipoPlato;
      cout << "Ingrese el importe: ";
      cin >> importe;
      cin.ignore(); // Limpiar el búfer de entrada

      contadorComanda ++; //C)
      acumuladorImporte += importe; //C)

      switch (tipoPlato)
      {
        case 1:
          platoEntrada ++;      
        break;
        case 2:
          platoPrincipal ++;      
        break;
        case 3:
          platoPostre ++;      
        break;
      }

      if(menorImportePlatoPPALDelMozo == -1){
        menorImportePlatoPPALDelMozo = importe;
        numeroMozoMenorImporte = nroMozo;
      }else if(importe < menorImportePlatoPPALDelMozo){
        menorImportePlatoPPALDelMozo = importe;
        numeroMozoMenorImporte = nroMozo;
      }
    }

    if(menorImporteGENERAL == -1){
      menorImporteGENERAL = menorImportePlatoPPALDelMozo;
      numeroMozoMenorGENERAL = numeroMozoMenorImporte;
    }else if(menorImportePlatoPPALDelMozo < menorImporteGENERAL){
      menorImporteGENERAL = menorImportePlatoPPALDelMozo;
      numeroMozoMenorGENERAL = numeroMozoMenorImporte;
    }

    cout << "El mozo " << nroMozo << ". Trabajo: " << platoEntrada << " platos de entrada, " << platoPrincipal << " platos principales, " << platoPostre << " plato de postres. " << endl;
    
    cout << "Ingrese el numero de comanda: ";
    cin >> nroComanda;
    cout << "Ingrese el numero de mozo (- 1 para salir): ";
    cin >> nroMozo;
  }

    cout << "El mozo que cobro el menor importe GENERAL " << numeroMozoMenorGENERAL<< ". IMPORTE COBRADO $: " << menorImporteGENERAL << endl;
    cout << "El promedio del importe GENERAL es: " << fixed << setprecision(2)<< acumuladorImporte / contadorComanda;

  return 0;
}