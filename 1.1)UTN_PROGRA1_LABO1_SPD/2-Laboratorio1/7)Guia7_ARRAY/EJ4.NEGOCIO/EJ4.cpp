#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*****FUNCIONES*****/

const int MAX_DAYS = 31;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  //idVenta, dia[], importe, venta =0 cierra
  
  float salesPerDay[MAX_DAYS] = {};
  int saleID, day;
  float amount;

  cout << "Enter sale ID (finish with zero): ";
  cin >> saleID; 
  while(saleID != 0)
  {
  //PROCESS AND SIPLAY FOR EACH SALE (PROCESAR-LISTAR) 
    cout << "Enter day number: ";
    cin >> day;
    cout << "Enter the amount: ";
    cin >> amount;

    salesPerDay[day -1] += amount;
    cout << endl << " DIA: " << day << ". Day -1 : " << day-1 << " salesPerDar[day] " << salesPerDay[day] << " salesPerDay[day-1] " << salesPerDay[day-1] << endl;
    
    cout << "Enter sale ID (finish with zero): ";
     cin >> saleID;
  }

  //Calculo de recaudacion total por dia
  cout << "Revenue per day: " << endl;
  for (int x = 0; x < MAX_DAYS; x ++){
    if(salesPerDay[x] > 0){
      cout << "Day #" << x + 1 << " total revenue $" << salesPerDay[x] << endl;
    }
  }

  //Max revenue and its own day
  int maxDayRevenue = 1; // B) // el dia 1 para el usuario es el 
  float maxRevenue = salesPerDay[0]; //B)   indice cero del programador
 
  for (int x = 1; x < MAX_DAYS; x ++){ // como ya tengo indice cero asignado comienzo en 1 hasta 30 (30 vueltas + la cero que asigne son 31 valors)
    if(salesPerDay[x] > maxRevenue){
      maxRevenue = salesPerDay[x];
      maxDayRevenue = x + 1;
    }
  }

  cout << "Day max revenue: " << maxDayRevenue << ". Amount: $" << maxRevenue; 


/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */
    
  return 0;

}