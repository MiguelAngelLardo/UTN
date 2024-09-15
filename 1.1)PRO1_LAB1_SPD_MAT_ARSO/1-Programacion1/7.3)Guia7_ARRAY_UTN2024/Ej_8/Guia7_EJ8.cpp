/*
8 Dada una lista de n�meros compuesta por 10 subgrupos y cada grupo
separado del siguiente por un cero, se pide generar un vector de 10 elementos
con el m�ximo de cada uno de los subgrupos. Luego mostrar los elementos del
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

        cout << "Ingrese un numero ";
        cin >> numero;
        maximo = numero;// para cada grupo de numeros el primer ingreso es el maximo

        while (numero !=0){
        //comparacion de maximos
        if (numero >= maximo){
            maximo = numero;
        }

        cout << "Ingrese un numero ";
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
