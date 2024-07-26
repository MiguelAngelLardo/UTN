#include <iostream>

using namespace std;

/*
8) Dada una lista de números compuesta por grupos donde cada grupo está separado del
siguiente por un cero, y la lista de números finaliza cuando se ingresan dos ceros
consecutivos, se pide determinar e informar:

a) La cantidad de grupos en los que se detecten un total de 4 o más números primos
consecutivos. Se informa 1 resultado al final.
b) Para cada uno de los grupos en los que se haya detectado números negativos, el mayor y
el segundo mayor de los mismos y en que posición estaban dentro del subgrupo. En los
grupos sin negativos, informar “Grupo sin negativos”. Se informan 4 resultados por cada
grupo.
c) El mayor número primo de todos los grupos, informando además en que grupo y en qué
posición del mismo fue detectado. Se informan 3 resultados al final.
Ejemplo de una posible lista: 5, 4, 3, 0, 18, -5, 20, 0, 7, 11, 25, 4, 0, 0
*/

int main(){
  int n, grupo = 0, aux; //Estructura

  cout << "Ingrese un numero (INICIO)(CORTA con CERO): ";
  cin >> n;

  while( n != 0){
    grupo++;
    cout << endl;
    printf("G%d) Ingrese un numero (CORTA CON CERO): ", grupo);
    cin >> n;

    
    aux = n;

    while (aux != 0){
      

      cout << "Ingrese un numero para el grupo " << grupo << ": ";
      cin >> aux;
    }


  }



}