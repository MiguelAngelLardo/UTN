/*
10 Dada una lista de números compuesta por grupos donde cada grupo está
separado del siguiente por un cero, y la lista de números finaliza cuando se
ingresan dos ceros consecutivos, se pide determinar e informar:
a) La cantidad de grupos en los que se detecten un total de 4 o más números
primos consecutivos. Se informa 1 resultado al final.
b) Para cada uno de los grupos en los que se haya detectado números
negativos, el mayor y el segundo mayor de los mismos y en qué posición
estaban dentro del subgrupo. En los grupos sin negativos, informar “Grupo sin
negativos”. Se informan 4 resultados por cada grupo.
c) El mayor número primo de todos los grupos, informando además en cual
grupo y en qué posición del mismo fue detectado. Se informan 3 resultados al
final.
Ejemplo de una posible lista: 5 4 3 0 18 -5 20 0 7 11 25 4 0 0.
*/




#include <iostream>
using namespace std;


int main()
{
 int n=1, aux, contPrimo, cont4PrimoConsecutivo, contPrePrimo, negativoMayor1, negativoMayor2, contSubGrupo, posicionNegativoMayor1, posicionNegativoMayor2;
 int contGrupo = 0, grupoCon4oMasPrimosConsecutivos = 0, numeroPrimoActual, maximoPrimoDelGrupo, posicionDelPrimoEnElGrupo, posicionDelPrimoEnTodosLosGrupos;
 int maximoPrimoDeTodosLosGrupos, mostrarPosicionDelPrimoEnElGrupo ;
 bool banderaMas4Primo, banderaMayorNegativo, banderaNoNegativo, banderaPrimo, banderaMaximoPrimoDeTodosLosGrupos = false;

 while (n != 0)
 {
  contPrimo = 0, cont4PrimoConsecutivo = 0, contSubGrupo = 0, negativoMayor1 = 0, negativoMayor2 = 0, numeroPrimoActual = 0, maximoPrimoDelGrupo = 0 ;
  posicionDelPrimoEnElGrupo = 0;
  banderaMas4Primo = true, banderaMayorNegativo = false, banderaNoNegativo = false, banderaPrimo = false;

  cout << "Ingrese un numero: ";
  cin >> n;

  contGrupo ++; //me dice si es el grupo 1 o 2 o 3 o 4....
  aux = n;
  while (aux != 0)
  {
    contPrePrimo = 0, contSubGrupo ++, contPrePrimo = 0;
    //A) Inicio del punto B
    for(int x = 1; x <= aux; x++)
      if(aux % x == 0)
        contPrePrimo ++;

    if (contPrePrimo == 2){
      contPrimo ++;
      numeroPrimoActual = aux;
    }

    if(banderaMas4Primo && contPrePrimo == 2){
      cont4PrimoConsecutivo ++;
      banderaMas4Primo = true;
    }else{
      banderaMas4Primo = false;
      cont4PrimoConsecutivo = 0;
    }

    if(cont4PrimoConsecutivo == 0)
      banderaMas4Primo = true;
    //A) Fin del punto A

    //B) Fin del punto B
    if(aux < 0){
      if(!banderaMayorNegativo){
        negativoMayor1 = aux;
        negativoMayor2 = negativoMayor1;
        posicionNegativoMayor1 = contSubGrupo;
        posicionNegativoMayor2 = contSubGrupo;
        banderaMayorNegativo = true;
      }else if(aux > negativoMayor1){
        negativoMayor2 = negativoMayor1;
        negativoMayor1 = aux;
        posicionNegativoMayor2 = posicionNegativoMayor1;
        posicionNegativoMayor1 = contSubGrupo;
      }
    }

    if(negativoMayor1 == 0){
      banderaNoNegativo = true;
    }

    //B) Fin del punto B
    //C) Inicio del punto C
    if(!banderaPrimo){
      maximoPrimoDelGrupo = numeroPrimoActual;
      posicionDelPrimoEnElGrupo = contSubGrupo;
      banderaPrimo = true;
    }else if (numeroPrimoActual > maximoPrimoDelGrupo){
      maximoPrimoDelGrupo = numeroPrimoActual;
      posicionDelPrimoEnElGrupo = contSubGrupo;
    }

    //cout << endl << "PRIMER WHILE maximo primo del grupo " << maximoPrimoDelGrupo << " Su posicion relatia es: " << posicionDelPrimoEnElGrupo << endl;

    cout << "Ingrese un numero (auxiliar) ";
    cin >> aux;
  }

  if(cont4PrimoConsecutivo >= 4)
    grupoCon4oMasPrimosConsecutivos ++;

   if(n != 0 && banderaNoNegativo == false)
     cout << endl << "Grupo " << contGrupo <<") El mayor negativo y segundo mayor negativo: " << negativoMayor1 << " en posicion " << posicionNegativoMayor1 << " y " << negativoMayor2 << " en posicion " << posicionNegativoMayor2 << endl;

  if(banderaNoNegativo)
    cout << endl << "Grupo " << contGrupo <<") Sin Numeros Negativos" << endl;

  if (maximoPrimoDelGrupo > 0 && !banderaMaximoPrimoDeTodosLosGrupos){ //guarda el maximo primo de todos los grupos
    maximoPrimoDeTodosLosGrupos = maximoPrimoDelGrupo;
    posicionDelPrimoEnTodosLosGrupos = contGrupo;
    mostrarPosicionDelPrimoEnElGrupo = posicionDelPrimoEnElGrupo;
    banderaMaximoPrimoDeTodosLosGrupos = true;
  }else if (maximoPrimoDelGrupo > maximoPrimoDeTodosLosGrupos){
    maximoPrimoDeTodosLosGrupos = maximoPrimoDelGrupo;
    posicionDelPrimoEnTodosLosGrupos = contGrupo;
    mostrarPosicionDelPrimoEnElGrupo = posicionDelPrimoEnElGrupo;
  }

  // cout << "Grupo Actual " << contGrupo << endl;
  // cout << "El mayor primo de todos los grupos es " << maximoPrimoDeTodosLosGrupos << ". Es del grupo numero " << posicionDelPrimoEnTodosLosGrupos << ". Su posicion relatia es: " << mostrarPosicionDelPrimoEnElGrupo << endl;
 }

  cout << endl << " Cantidad de Grupos con 4 o mas primos consecutivos: " << grupoCon4oMasPrimosConsecutivos << endl;
  cout << "El mayor primo de todos los grupos es " << maximoPrimoDeTodosLosGrupos << ". Es del grupo numero " << posicionDelPrimoEnTodosLosGrupos << ". Su posicion relatia es: " << mostrarPosicionDelPrimoEnElGrupo << endl;

  return 0;
}
