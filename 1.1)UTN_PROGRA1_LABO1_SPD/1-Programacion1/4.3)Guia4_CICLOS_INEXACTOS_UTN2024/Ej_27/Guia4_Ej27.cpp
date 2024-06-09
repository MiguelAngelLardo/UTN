/*
27 Una Universidad dispone de diez aulas para acomodar a una cantidad de
asistentes a una charla. Cada aula tiene una capacidad total de 60 personas. Se
necesita un programa que solicite la cantidad de asistentes a la charla y
determine la cantidad total de aulas necesarias para acomodarlos a todos.
Por ejemplo:
Si los asistentes son 120 se necesitarán 2 aulas.
Si los asistentes son 123 se necesitarán 3 aulas.
Si los asistentes son 40 se necesitará 1 aula.
DESAFÍO: No utilizar el operador de división ni el de resto en el algoritmo.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int asistentes, cantAulas = 0, personasAcomodar ;

    int capacidadAula = 60;
    cout << "Ingrese la cantidad de asistentes a la charla: ";
    cin >> asistentes;
    personasAcomodar = asistentes;


    // Mientras haya asistentes por acomodar
    while (personasAcomodar > 0) {
        // Restamos la capacidad total de un aula a la cantidad de asistentes
        personasAcomodar -= capacidadAula;
        // Incrementamos el contador de aulas necesarias
        cantAulas++;
    }

    cout << "Para acomodar a " << asistentes << " personas, se necesitan " << cantAulas << " aulas." << endl;

return 0;
}
