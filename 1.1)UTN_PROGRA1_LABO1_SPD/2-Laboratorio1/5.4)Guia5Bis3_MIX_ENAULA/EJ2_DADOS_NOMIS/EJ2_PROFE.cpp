#include <iostream>
using namespace std;

int main(){
    int ronda, dado1, dado2, diferencia, puntajeRonda, puntajeTotal;
    puntajeTotal = 0;
    for(ronda=1; ronda<=3; ronda++){
        puntajeRonda = 0;
        cout << "RONDA # " << ronda << endl;
        // Tirar los dados (ingreso)
        cout << "Dado 1: ";
        cin >> dado1;
        cout << "Dado 2: ";
        cin >> dado2;
        diferencia = dado1 - dado2;
        if (diferencia < 0){
            diferencia = diferencia * (-1);
        }
        
        // Calcular el puntaje
        if (diferencia == 0 && (dado1 == 1 || dado1 == 6)){
            puntajeRonda = 10;
        }
        else if (diferencia == 1 || diferencia == 5){
            puntajeRonda = 0;
            puntajeTotal = 0;
        }
        else if (diferencia > 1 && diferencia < 5){
            puntajeRonda = diferencia;
        }
        puntajeTotal += puntajeRonda;

        // Mostrar puntaje parciales
        cout << "Puntaje ronda: " << puntajeRonda << endl;
        cout << "Puntaje total: " << puntajeTotal << endl << endl;
    }

    // Mostrar puntaje final
    cout << "----------------------------------------------" << endl;
    cout << "Puntaje final: " << puntajeTotal << endl;

    return 0;
}