#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

  int n, duplaA, duplaB, contadorDupla = 0;
  bool bandera = false;

  for (int x = 0; x < 10; x ++){
    cout << x+1 << ") Ingrese un numero: ";
    cin >> n;

    if (!bandera && n%2 != 0){
      duplaA = n; //12-
      bandera = true;
    }else if (bandera = true && n%2 != 0 || n%2 == 0 ){
      duplaB = duplaA; 
      duplaA = n;      
    }

    if (duplaA % 2 != 0 && duplaB %2 != 0){
      contadorDupla ++;
    }   

  }

  cout << "hay " << contadorDupla << " duplas de numeros impares consecutivos";

}