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
  
  const int TAM = 10; // Tamaño del vector
    int vector[TAM];    // Vector para almacenar los números
    int nuevoNumero;

    // Llenar los primeros 9 elementos del vector de manera ordenada
    cout << "Ingrese 9 numeros ordenados de menor a mayor:" << endl;
    for (int i = 0; i < 9; i++) {
        cin >> vector[i];
    }

    // Pedir al usuario ingresar el nuevo numero
    cout << "Ingrese el nuevo numero: ";
    cin >> nuevoNumero;

    // Encontrar la posición adecuada para insertar el nuevo número
    int posicion;
    for (posicion = 0; posicion < 9 && vector[posicion] < nuevoNumero; posicion++) {
        // No es necesario agregar código adicional aquí, el bucle for se encarga de la búsqueda.
        cout << "Posicion: " << posicion << " Vector[posicion]: " << vector[posicion] << endl;
    }
    cout << endl << "Valor de posicion: " << posicion << ". Vector[" << posicion <<"]" << " tiene un " << vector[posicion] << endl;

    // Desplazar los elementos a la derecha para hacer espacio
    for (int i = 9; i > posicion; i--) {
        vector[i] = vector[i - 1];
    }

    // Insertar el nuevo número en la posición correcta
    vector[posicion] = nuevoNumero;

    // Imprimir el vector actualizado
    cout << "Vector actualizado:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
    
  return 0;

}