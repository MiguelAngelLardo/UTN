#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//pepa pig apunta a A - la guitarra de pepa es pepa misma
//buich/bulrric y al que/alke vendedora de aluminio 

using namespace std;// Usamos el espacio de nombres estándar

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
   const int TAM = 10;
    int vector[TAM] = {};

    // Ingresar los valores al vector
    for (int i = 0; i < TAM; i++)
    {
      cout << "Ingrese el numero #" << i+1 << ": ";
      cin >> vector[i]; //1 3 9 1 4 6 2 0 5 7 
    }

    //encontrar el valor maximo
    int maxValor = vector[0]; // cajita = 1
    int maxPosicion = 0; 

    for (int i = 1; i < TAM; i++){
      if(vector[i] > maxValor){ //3 > cajita(1) 
        maxValor = vector[i]; // cajita = 3  
        maxPosicion = i; // cajita2 = 1;
      }
    }

    //eliminar el valor maximo y desplazar todo a la derecha
    for (int i = maxPosicion; i < TAM -1; i++){ // maxPosicion es 2 (0,1,2){
      cout << endl << "int " << i << " = " << maxPosicion << "; " << i << " < " << TAM - 1 << " ; " << i << endl;
      vector[i] = vector[i + 1]; //vector[2] = vector[3]
    }

    // Mostrar el vector resultante sin el último elemento
    cout << "Vector resultante sin el valor maximo: ";
    for (int i = 0; i < TAM - 1; i++) {
        cout << vector[i] << " ";
    }
    
    
  return 0;

}