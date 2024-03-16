#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int nroSerie, edad, sueldo;
  int nroSerieActual; //CORTECONTROL

  int contEdad = 0, acumEdad = 0; //PTOA
  int maxSueldo; //PTOB
  int contTotalPersonajes = 0; //PTOC
  int cantPersonajesSerie; //PTO D
  char vectorCaracter [50];//PTO E
  
  cout << "Ingrese numero de serie: ";
  cin >> nroSerie;  
  cout << "Ingrese el sueldo: ";
  cin >> sueldo;
  cout << "Ingrese la edad: ";
  cin >> edad;
  cin.ignore();
  cout << "Ingrese nombre del personaje: ";
  cin.getline(vectorCaracter, 50);

  while(nroSerie != 0)//CORTA
  {
    maxSueldo = -1;

    //CORTE CONTROL
    nroSerieActual = nroSerie;
    while (nroSerie == nroSerieActual) //cambia con numero de serie diferente entre si
    { 
      contEdad ++; // contEdad = contEdad + 1;  PTOA
      acumEdad += edad; // acumEdad = acumEdad + edad; PTOA
      
      //PTOC
      contTotalPersonajes ++; // contTotalPersonajes = contTotalPersonajes + 1; 
      
      //PTOD
      cantPersonajesSerie ++;

      //PTOB
      if(maxSueldo == -1){
        maxSueldo = sueldo;
      }else if(sueldo > maxSueldo){
        maxSueldo = sueldo;
      }

      //PTOE
      if(edad > 30){
        cout << endl << "***PUNTO E => NOMBRE***" << endl;
        cout << vectorCaracter << endl << endl;
      }

      cout << "Ingrese numero de serie: ";
      cin >> nroSerie;
      if(nroSerie != 0)
      {
        cout << "Ingrese el sueldo: ";
        cin >> sueldo;
        cout << "Ingrese la edad: ";
        cin >> edad;
        cin.ignore();
        cout << "Ingrese nombre del personaje: ";
        cin.getline(vectorCaracter, 50);
      }
    }

    printf("\nPTOB => EL maximo sueldo de la Serie Nro %d es %d\n", nroSerieActual, maxSueldo);
    cout << "PUNTO D => SERIE #" << nroSerieActual <<" => CANTIDAD PERSONAJES #" <<  cantPersonajesSerie << endl; 
  }
  
  cout << "PUNTO A: Promedio de TODAS las edades => " << fixed << setprecision(2) << (float)acumEdad/contEdad << endl; 
  printf("PUNTO C => TOTAL DE PERSONAJES #%d", contTotalPersonajes);

  return 0;
}