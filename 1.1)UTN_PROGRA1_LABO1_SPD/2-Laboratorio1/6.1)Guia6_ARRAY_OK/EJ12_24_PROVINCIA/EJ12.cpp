#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/


/*****ARRAY*****/
const int NO_PROVINCE = 24;
const int NO_ZONE = 9;
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int nroProvince, nroZone;  
  bool mProvincexZone[NO_ZONE][NO_PROVINCE] = {};
 

  cout << "Enter the number of the province (1 to 24)(FINISH WHIT ZERO): ";
  cin >> nroProvince;
  while(nroProvince != 0)
  {
    cout << "Enter number of GEOGRAFIC ZONE in province No" << nroProvince << ": ";
    cin >>  nroZone; 

    mProvincexZone[nroZone-1][nroProvince-1] = true;

    cout << "Enter the number of the province (1 to 24)(FINISH WHIT ZERO): ";
    cin >> nroProvince;  
  }
  
  for(int i = 0; i < NO_ZONE; i++){
    int counterProv = 0;
    for(int j = 0; j < NO_PROVINCE; j ++){
      if(mProvincexZone[i][j] == true){ // VEO SI TENGO 3 ZONAS EN TRUE
        counterProv++;     
      }
    }
    if(counterProv >= 3){
      cout << endl << "Tengo por lo menos 3 provincias cubiertas POR LA ZONA " << i+1 << ". Son #" << counterProv << " provincias cubiertas: " << endl;
      for(int z = 0; z < NO_PROVINCE; z++){
        if(mProvincexZone[i][z] == true){
          cout << "PROVINCIA # " << z + 1 << endl;
        }  
      }
    }
  }

  return 0;

}