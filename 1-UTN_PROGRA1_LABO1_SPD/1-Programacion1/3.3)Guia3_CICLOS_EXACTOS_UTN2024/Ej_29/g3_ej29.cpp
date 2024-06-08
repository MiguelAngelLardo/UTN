/*29 Se dispone de la información de los últimos 19 partidos del futbolista Diego
Armando Laradona. Por cada partido se registró:
- Número de partido
- Minutos jugados
- Tarjetas amarillas
- Tarjetas rojas
- Goles
Existe un registro para cada partido. Los mismos se encuentran ordenados por
número de partido. Se pide calcular e informar:
A- La cantidad de partidos que no jugó (partidos con minutos igual a cero)
B- La cantidad de partidos que jugó por completo (minutos >= 90)
C- El promedio de tarjetas recibidas por partido.
D- El número de partido en el que haya convertido mayor cantidad de goles.
Indicar también los goles convertidos.
E- La mejor racha de partidos convirtiendo goles. Se debe mostrar la mayor
cantidad de partidos consecutivos en los que haya convertido.*/

#include <iostream>
using namespace std;


int main(){

	setlocale(LC_ALL, "Spanish");

	int nroPartido, tarjetaAmarilla, tarjetaRoja, minutos, goles;
	int partidosNoJugados=0, partidosCompletos=0, totalTarjetas=0, golesMax, partidoMax, racha=0, rachaMax;
	float promedioTarjeta;
	bool banderaGol=false;

	for(int i=1; i<=19; i++){
		cout <<"		Partido " << i << endl;
		cout << "Ingrese los minutos jugados     : ";
		cin >> minutos;
		cout << "Cantidad de tarjetas amarrillas : ";
		cin >> tarjetaAmarilla;
		cout << "Cantidad de tarjetas rojas      : ";
		cin >> tarjetaRoja;
		cout << "Cantidad de goles convertidos   : ";
		cin >> goles;
		cout << "----------------------------------" << endl;

	//Punto A y B
		if(minutos == 0){
			partidosNoJugados++;
		}else if (minutos >=90){
			partidosCompletos++;
		};
	//Punto C Promedio de tarjetas por partido
		totalTarjetas +=tarjetaAmarilla;
		totalTarjetas +=tarjetaRoja;

	//Punto D partido con mayor cantidad de goles
		 if( i == 1 || goles > golesMax ){
			golesMax = goles;
			partidoMax = i;

		 };
	// Punto E
		if (goles > 0){
				racha++;
			if(!banderaGol){
				rachaMax = racha;
				banderaGol = true;

			} else if (racha > rachaMax){
				rachaMax = racha;
			}
		} else{
			racha = 0;
			banderaGol = false;
		};



	};

	 // Calcula el promedio de tarjetas recibidas por partido
    promedioTarjeta = static_cast<float>(totalTarjetas) / 19;

    // Muestra los resultados
    cout << "Cantidad de partidos que no jugó: " << partidosNoJugados << endl;
    cout << "Cantidad de partidos completos: " << partidosCompletos << endl;
    cout << "Promedio de tarjetas recibidas por partido: " << promedioTarjeta << endl;
    cout << "Partido con mayor cantidad de goles: " << partidoMax << " con " << golesMax << " goles." << endl;
    cout << "Mejor racha de partidos convirtiendo goles: " << rachaMax << " partidos consecutivos." << endl;


return 0;
}
