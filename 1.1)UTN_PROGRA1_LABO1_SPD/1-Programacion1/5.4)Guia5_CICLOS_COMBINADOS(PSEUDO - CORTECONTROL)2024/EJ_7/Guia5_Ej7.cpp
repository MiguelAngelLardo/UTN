/*
7 Se dispone de una lista de 10 grupos de números enteros separados entre ellos
por ceros. Se pide determinar e informar:
a) Informar el promedio de cada grupo. Se informa 1 resultado por cada grupo.
b) Determinar e informar el valor mínimo de todos los grupos, indicando en qué
grupo se encontró y su posición relativa en el mismo. Se informan 3 resultados
al final.
c) El mayor de los promedios y a que grupo pertenecía. Se informan 2
resultados al final.

*/

#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int numero;
    // Variables para el punto a)
    float promedioGrupo;
    int grupoMayorImpares = 0;
    int total,cantidadNumeros;


    // Variables para el punto b)
    int nroMinimo,posicion,grupoMinimo;
    bool minimo;


    // Variable para el punto c)
    float mayorPormedio;
    int grupoMayor;
    bool promedio=false;

    // Bucle para los 10 grupos
    for (int grupo = 1; grupo <= 10; grupo++) {
        cout << endl << "----------------------" << endl;
        cout << "         GRUPO " << grupo << endl << endl;

        // Reniciar Variables para cada grupo
        total=cantidadNumeros=0;
        minimo=false;

        // Entrada de números para el grupo actual
        cout << "Ingresa un número: ";
        cin >> numero;


        int numeroAnterior = numero;
        while (numero != 0) {

            // Punto a)
            cantidadNumeros++;
            total+=numero;

            //punto b)
            if(!minimo ||numero < nroMinimo){
                nroMinimo=numero;
                grupoMinimo=grupo;
                posicion=cantidadNumeros;
                minimo=true;

            }

            cout << "Ingresa un número: ";
            cin >> numero;
        }

        // Calcular promedio de grupos para el punto a) y mostrar
        float promedioGrupo = (float) total / cantidadNumeros;
       cout << "El promedio del grupo " <<grupo << " es " << promedioGrupo << endl;


        //  punto c)
        if (!promedio || promedioGrupo>mayorPormedio) {
           mayorPormedio=promedioGrupo;
           grupoMayor=grupo;
           promedio= true;
    }
    }
    cout << endl << "----------------------" << endl;
    // Mostrar resultados finales
    cout << "El numero mas chico ingresado es: " << nroMinimo <<endl;
    cout << "Pertenece al grupo "<< grupoMinimo << endl;
    cout << "Se ingresó en la posición " << posicion << endl;
    cout << "El mayor promedio es:"<< mayorPormedio<< " y corresponde al grupo" << grupoMayor<<endl;


return 0;
}
