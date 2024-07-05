#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{ 
     int asistentes;
    cout << "Ingrese la cantidad de asistentes: ";
    cin >> asistentes;

    int aulasNecesarias = 0;
    
    while (asistentes > 0) {
        asistentes -= 60;
        aulasNecesarias++;
    }

    cout << "Se necesitaran " << aulasNecesarias << " aulas." << endl;


 return 0;

}