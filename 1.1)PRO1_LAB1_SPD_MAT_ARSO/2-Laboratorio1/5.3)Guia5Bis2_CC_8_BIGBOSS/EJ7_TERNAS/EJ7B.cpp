#include <iostream>

using namespace std;
//PUNTO A

//una terna es una seguidilla de 3 numeros
//tiene que ser positivo, si es cero o neg se resetea la terna
// el promedio debe ser de 7 o menos
//cuando tres ternas dan el promedio de 7 o menos se corta el programa
//si ingreso 2 ternas de promedio 7 y una de promedio 9, se resetea el contador?

bool primo(int);

int main() {
  int n;
  int contadorPrimo = 0;
  bool ingreso = true;
  int contTernas = 0, acumTernas = 0, grupoTerna = 1, promedioPtoA = 0;

  while (ingreso)
  {
    cout << "Ingrese un numero positivo (CORTA CON CERO): ";
    cin >> n;

    if (n == 0){
      cout << "EXITOSO" << endl;
      ingreso = false;
    } 
    else if (n < 0){
      cout << "El numero ingresado es incorrecto" << endl;
      contTernas = 0;
      acumTernas = 0;
      grupoTerna = 1;
      promedioPtoA = 0;
    }else{
      contTernas++;
      acumTernas += n; 
      contadorPrimo += (primo(n)) ? 1 : contadorPrimo = 0; //primo
    
      cout << "contador ternas " << contTernas << endl;     
      if (contTernas == 3){
        promedioPtoA = acumTernas / contTernas;
        contTernas = 0;       
        if (promedioPtoA < 8){
          grupoTerna++;
          if (grupoTerna == 3){
            cout << "FALLAS EN EL SUMINISTRO ELECTRICO\n";
            cout << "Ingrese un cero: ";
            cin >> n;
            while(n != 0)
            {
            cout << "NUMERO INCORRECTO => Ingrese un cero: " << endl;
            cin >> n;
            }
            cout << "SALIENDO DEL SISTEMA!" << endl;
            ingreso = false;
          }
        }else{
          grupoTerna = 0;
        }
          acumTernas = 0;
          promedioPtoA = 0;         
      }
        cout << "grupo terna " << grupoTerna << endl;
    }

    if(contadorPrimo == 4){
      cout << "REPONER INSUMOS" << endl;
      cout << "Ingrese un cero para finalizar: ";
      cin >> n;
      while(n != 0)
      {
        cout << endl << "NUMERO INCORRECTO => Ingrese un cero para finalizar: ";
        cin >> n;
      }
      ingreso = false;
      cout << "SALIENDO DEL PROGRAMA";
    } 
  }

 return 0;
}

bool primo(int n){
  int contPrimo = 0; 
  for(int x = 1; x <= n; x++){
    if(n % x == 0){
      contPrimo ++;
    }
  }
  return (contPrimo == 2) ? true : false;
}