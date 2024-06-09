/*
25 El festival Larapalooza, el mejor festival musical del mundo, brindará una serie
de conciertos distribuidos en tres jornadas distintas. Se desea un programa que
registre los artistas que participarán. Por cada artista se registró:
- Número de artista (entero)
- Integrantes (entero)
- Jornada (1, 2 o 3)
- Duración del show en minutos (entero)
La información no se encuentra ordenada bajo ningún criterio. La carga de
datos se finaliza con un número de artista igual a cero. Calcular e informar:
- El número de artista que realice el show más largo de la jornada 1.
- La cantidad de solistas (artistas de 1 integrante) que participaron en
cada una de las jornadas. (se muestran tres resultados).
- La jornada más extensa (en minutos totales).
- Duración promedio de show por artista (se muestra un resultado).
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int numeroArtista, integrantes, jornada, duracion;
    int maxDuracionJornada1 = 0, numArtistaMaxDuracionJornada1 = 0;
    int cantSolistasJornada1 = 0, cantSolistasJornada2 = 0, cantSolistasJornada3 = 0;
    int duracionTotalJornada1 = 0, duracionTotalJornada2 = 0, duracionTotalJornada3 = 0;
    int cantArtistas = 0, duracionTotal = 0;
    float duracionPromedio;

    cout << "Ingrese el número de artista (0 para finalizar): ";
    cin >> numeroArtista;

    while(numeroArtista != 0) {
        cout << "Ingrese la duración del show en minutos: ";
        cin >> duracion;
        cout << "Ingrese la cantidad de integrantes: ";
        cin >> integrantes;
        cout << "Ingrese la jornada (1, 2 o 3): ";
        cin >> jornada;


        // A- El número de artista que realice el show más largo de la jornada 1.
        if (jornada == 1 && duracion > maxDuracionJornada1) {
            maxDuracionJornada1 = duracion;
            numArtistaMaxDuracionJornada1 = numeroArtista;
        }

        // B- La cantidad de solistas por jornada
        if (integrantes == 1) {
            switch (jornada) {
                case 1:
                    cantSolistasJornada1++;
                    break;
                case 2:
                    cantSolistasJornada2++;
                    break;
                case 3:
                    cantSolistasJornada3++;
                    break;
            }
        }

        // C- La jornada más extensa (en minutos totales)
        switch (jornada) {
            case 1:
                duracionTotalJornada1 += duracion;
                break;
            case 2:
                duracionTotalJornada2 += duracion;
                break;
            case 3:
                duracionTotalJornada3 += duracion;
                break;
        }

        // D- Duración promedio de show por artista
        duracionTotal += duracion;
        cantArtistas++;

        cout << "Ingrese el número de artista (0 para finalizar): ";
        cin >> numeroArtista;
    }

    // A- El número de artista que realice el show más largo de la jornada 1.
    cout << "El número de artista con el show más largo de la jornada 1 es: " << numArtistaMaxDuracionJornada1 << endl;

    // B- La cantidad de solistas por jornada
    cout << "Cantidad de solistas en jornada 1: " << cantSolistasJornada1 << endl;
    cout << "Cantidad de solistas en jornada 2: " << cantSolistasJornada2 << endl;
    cout << "Cantidad de solistas en jornada 3: " << cantSolistasJornada3 << endl;

    // C- La jornada más extensa (en minutos totales)
    int duracionTotalMax = max(duracionTotalJornada1, max(duracionTotalJornada2, duracionTotalJornada3));
    if (duracionTotalMax == duracionTotalJornada1) {
        cout << "La jornada más extensa fue la 1 con una duración total de " << duracionTotalJornada1 << " minutos." << endl;
    } else if (duracionTotalMax == duracionTotalJornada2) {
        cout << "La jornada más extensa fue la 2 con una duración total de " << duracionTotalJornada2 << " minutos." << endl;
    } else {
        cout << "La jornada más extensa fue la 3 con una duración total de " << duracionTotalJornada3 << " minutos." << endl;
    }

    // D- Duración promedio de show por artista
    duracionPromedio = (float) duracionTotal / cantArtistas;
    cout << "Duración promedio de show por artista: " << duracionPromedio << " minutos." << endl;

    return 0;
}


