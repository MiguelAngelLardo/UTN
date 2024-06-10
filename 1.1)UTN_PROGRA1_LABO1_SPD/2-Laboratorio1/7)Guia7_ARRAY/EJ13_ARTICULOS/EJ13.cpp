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
const int TOTAL_STOCK = 20;
const int NO_ART = 15;
const int NO_OFFICE = 4;
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int vStockPerArt [NO_ART], mOfficexArt_AMOUNT[NO_OFFICE][NO_ART] = {};
  for(int x = 0; x < NO_ART; x ++) //LE pongo 20 de stock a cada articulo
    vStockPerArt[x] = TOTAL_STOCK;
  
  int noArt, quantSold, noSuc;

  cout << "Enter No Article (1 to 15) (FINISH WHIT ZERO): ";
  cin >> noArt;
  while (noArt != 0)
  {
    cout << "Enter Quantity sold: ";
    cin >> quantSold; 
    cout << "Enter No Office(1 to 5): ";
    cin >> noSuc;

    mOfficexArt_AMOUNT[noSuc-1][noArt-1] +=  quantSold;
    vStockPerArt[noArt-1] -= quantSold;


    cout << "Enter No Article (1 to 15) (FINISH WHIT ZERO): ";
    cin >> noArt;  
  }

  cout << "POINT A) Sold amount per article: " << endl;
  for (int j = 0; j < NO_ART; j++)
  {
    int Accum = 0;
    for(int i = 0; i < NO_OFFICE; i++)
    {
      if(mOfficexArt_AMOUNT[i][j] != 0)
      {
        Accum += mOfficexArt_AMOUNT[i][j];
      }
    }
    cout << "Article #" << j+1 << " sold quantity " << Accum << endl;
  }

  cout << endl  << "POINT B) More than 10 articles per office: " << endl;
  for(int i = 0; i < NO_OFFICE; i++){
    for(int j = 0; j < NO_ART; j++){
      if(mOfficexArt_AMOUNT[i][j] > 10){
        cout << "Office #" << i+1 << ": Article white more than 10 units sold: NO" << j+1 << ". Quantities: " << mOfficexArt_AMOUNT[i][j] << " UN" << endl; 
      }
    }
  }

  cout << endl << "POINT C) Quantity of most sold item per office: " << endl;
  for (int j = 0; j < NO_ART; j++) {
    int maxQuantity = 0, maxSoldPerOff = -1, maxArticleSold = -1;
    for (int i = 0; i < NO_OFFICE; i++) {
      if (mOfficexArt_AMOUNT[i][j] > maxQuantity) {
        maxQuantity = mOfficexArt_AMOUNT[i][j];
        maxSoldPerOff = i + 1;
        maxArticleSold = j + 1;
      }
    }
    if (maxSoldPerOff != -1) {
      cout << "Article #" << maxArticleSold << ": The Office #" << maxSoldPerOff << " had the highest sales quantity: " << maxQuantity << " units." << endl;
    }else{
      cout << "Article #" << j+1 << ": No articles sold." << endl;  // Corregir aquí
    }
  }

  cout << endl << "POINT D) STOCK IN ZERO: " << endl;
  for (int i = 0; i < NO_ART; i++){
    if(vStockPerArt[i] == 0){
      cout << "The article Number #" << i+1 << " is in zero!!!" << endl;
    }
  }

  cout << endl << "POINT E) STOCK IN HALF: " << endl;
  int halfStock = TOTAL_STOCK/2;
  for (int i = 0; i < NO_ART; i++){
    if(vStockPerArt[i] < halfStock){
      cout << "The article that decreased more than half #" << i+1 << " is in " << vStockPerArt[i] << "!!!" << endl;
    }
  }

  return 0;

}