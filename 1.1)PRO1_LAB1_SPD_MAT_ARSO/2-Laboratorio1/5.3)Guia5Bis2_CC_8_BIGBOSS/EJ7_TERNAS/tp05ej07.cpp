//TP         : 05
//EJERCICIO  : 07
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

int main(void){
  int n, error, ctmen8, ct, suma, cdiv, cpri, cp;
  float prom;
  cp = ct = ctmen8 = error = suma = cdiv = cpri = 0;

  cout << "Ingresar numero: ";
  cin >> n;
  while(n!=0){
    cdiv=0;
    if(n > 0){
      //INICIO PUNTO A
      cp++; //contador positivo
      suma += n;
      if(cp==3){
        ct++; //contador terna
        prom = (float) suma / 3;
        cout << endl << "TERNA: " << prom << endl;
        cp = suma = 0;
        if (ct <= 3 && prom < 8){
          ctmen8++;
          cout << "PROM < 8: " << ctmen8 << endl;
          if (ctmen8 == 3){
            error = 1;
          }
        }
      }
      //FIN PUNTO A
      //INICIO PUNTO B
      for(int i=1; i<=n; i++){
        if(n%i == 0){
          cdiv++;
        }
      }
      if(cdiv==2){
        cpri++;
        if(cpri == 4){
          error = 2;
        }
      }
      else{
        cpri=0;
      }
      //FIN PUNTO B
    }
    else{
      cp = 0;
      cpri = 0;
    }

    if(error == 1 || error == 2){
      n = 0;
    }
    else{
      cout << "Ingresar numero: ";
      cin >> n;
    }
  }
  
  if(error == 1){
    cout << endl << "FALLAS EN EL SUMINISTRO ELECTRICO";
  }
  else if(error == 2){
    cout << endl << "REPONER INSUMOS";
  }
  else{
    cout << endl << "EXITOSO";
  }
  return 0;
}
