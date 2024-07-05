#include <iostream>
using namespace std;

int main() {
  const int DIAS_REGISTRO = 15;
  int numeroDia, diaTemperaturaMaxima, diasNeblina = 0, lluviaSi = 0, lluviaNo = 0;
  float temperatura, lluviaMM, visibilidadKM, temperaturaMax, temperaturaMin;
  bool banderaTemperatura = false;


  for (int x = 0; x < DIAS_REGISTRO; x ++)
  {
    cout << endl << "Ingrese el numero de dia: ";
    cin >> numeroDia;
    cout << "Ingrese la temperatura: ";
    cin >> temperatura;
    cout << "Ingrese los mm de lluvia: ";
    cin >> lluviaMM;
    cout << "Ingrese la visibilidad KM: ";
    cin >> visibilidadKM;

    if (!banderaTemperatura){
      temperaturaMax = temperatura;
      diaTemperaturaMaxima = numeroDia;
      temperaturaMin = temperatura;
      banderaTemperatura = true;
    }else if (temperatura > temperaturaMax){
      temperaturaMax = temperatura;
      diaTemperaturaMaxima = numeroDia;
    }

    if ( temperatura < temperaturaMin)
      temperaturaMin = temperatura;

    if(visibilidadKM < 2)
      diasNeblina ++;
    
    (lluviaMM > 0) ? lluviaSi++ : lluviaNo++;

  }

  cout << endl << "Mayor temperatura: " << temperaturaMax << ". Dia con mayor temperatura: " << diaTemperaturaMaxima << endl;
  cout << "Amplitud termica: " << temperaturaMax - temperaturaMin << endl;
  cout << "Dias con neblina (menos 2 km): " << diasNeblina << endl;

  if (lluviaSi > lluviaNo)
    cout << "Quincena lluviosa";
  else if (lluviaSi > DIAS_REGISTRO/3)
    cout << "Quincena Humeda";
  else  
    cout << "Quincena seca";

	return 0;
}