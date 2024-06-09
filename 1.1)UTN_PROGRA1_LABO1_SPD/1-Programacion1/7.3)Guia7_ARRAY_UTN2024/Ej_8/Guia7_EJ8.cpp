/*
8 Dada una lista de números compuesta por 10 subgrupos y cada grupo
separado del siguiente por un cero, se pide generar un vector de 10 elementos
con el máximo de cada uno de los subgrupos. Luego mostrar los elementos del
vector por pantalla.
*/


#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");

    int numero;
    int vecMaximos [10];
    int maximo;


    for(int i=0;i<10;i++){

        cout << "Ingrese un número ";
        cin >> numero;
        maximo =numero;// para cada grupo de números el primer ingreso es el maximo

        while (numero !=0){
        //comparación de maximos
        if (numero >=maximo){
            maximo=numero;
        }

        cout << "Ingrese un número ";
        cin >> numero;
        }
        /// lleno el vector
        vecMaximos[i]=maximo;

    }

    for (int i=0;i<10;i++){
        if(i<9){
           cout << vecMaximos[i] << ", ";
        }
          else{
          cout << vecMaximos[i] << ".";
        }

    }
return 0;
}
