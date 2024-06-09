/*27 Una estación meteorológica registró una muestra climática de los últimos 15
días. Por cada día registró:
- Número de día (entero)
- Temperatura (float)
- Milímetros de lluvia (float)
- Visibilidad en km (float)
Hay un registro por cada día. La información se encuentra ordenada por día. Se
pide calcular e informar:
A) El número del día que se haya registrado la temperatura máxima.
B) La amplitud térmica de todo el período.
C) La cantidad de días con neblina.
D) Mostrar "Quincena lluviosa" si hubo más días de lluvia que días sin lluvia.
E) Mostrar "Quincena húmeda" si llovió en al menos un tercio de los días.
De lo contrario mostrar "Quincena seca".
NOTA: La amplitud térmica es la diferencia entre la temperatura máxima y la
temperatura mínima.
NOTA: Se considera neblina a una visibilidad menor a 2 km.*/

#include <iostream>
using namespace std;


int main(){
	int dia, diasNeblina=0, diasLluvia=0, diasSinLluvia=0;
	float temperatura, lluviaMl, visibilidadKM, temperaturaMax, temperaturaMin, amplitudTermica;

	for(int i=1;i<=15;i++){

		cout <<"		Dia " << i << endl;
		cout << "Ingrese la temperatura       : ";
		cin >> temperatura;
		cout << "Ingrese los ml de lluvia     : ";
		cin >> lluviaMl;
		cout << "Ingrese los km de visibilidad: ";
		cin >> visibilidadKM;
		cout << "----------------------------------" << endl;

	//Punto A día de temperatura máxima
		if(i==1 || temperatura>temperaturaMax ){
			temperaturaMax= temperatura;
			dia = i;

			}
	//Punto B amplitud termica
		if(i==1 || temperatura<temperaturaMin ){
			temperaturaMin= temperatura;

			}
	//Punto C cantidad de días con neblina
		if(visibilidadKM < 2 ){
			diasNeblina++;

			}
	//Punto D y E cantidad de días con lluvia
		if(lluviaMl > 0 ){
			diasLluvia++;

		}else{
			diasSinLluvia++;
			}
		}


	//Punto A día de temperatura máxima
		cout <<" La temperatura máxima fue de: " << temperaturaMax <<" C° y se registró el día " << dia << endl;

	//Punto B amplitud termica
		amplitudTermica = temperaturaMax - temperaturaMin;
		cout << " La amplitud térmica de todo el período fue: " << amplitudTermica << endl;

	//Punto C días con neblina

		cout << "Se registraron " << diasNeblina << " días con neblina. " << endl;

	//Punto D quincena LLuviosa
		if (diasLluvia > diasSinLluvia){
			cout<< "La quincena fue lluviosa" << endl;
		}

	//Punto E quincena seca/humeda
		if(diasLluvia >=5){
			cout<< "La quincena fue húmeda" << endl;

		}else{
			cout<<"La quincena fue seca" << endl;
		}

return 0;
}
