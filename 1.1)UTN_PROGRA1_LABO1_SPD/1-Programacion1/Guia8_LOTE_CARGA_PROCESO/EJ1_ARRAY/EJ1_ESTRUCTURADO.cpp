#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****/
void seeMonthFX(int month){
  switch (month)
  {
    case 0:
      cout << "No sales for January." << endl;
    break;
    case 1:
      cout << "No sales for February." << endl;
    break;
    case 2:
      cout << "No sales for March." << endl;
    break;
    case 3:
      cout << "No sales for April." << endl;
    break;
    case 4:
      cout << "No sales for May." << endl;
    break;
    case 5:
      cout << "No sales for June." << endl;
    break;
    case 6:
      cout << "No sales for July." << endl;
    break;
    case 7:
      cout << "No sales for August." << endl;
    break;
    case 8:
      cout << "No sales for September." << endl;
    break;
    case 9:
      cout << "No sales for October." << endl;
    break;
    case 10:
      cout << "No sales for November." << endl;
    break;
    case 11:
      cout << "No sales for December." << endl;
    break;
  }
}

/*****ARRAY*****/
const int TAM = 3;
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  int vCod[TAM], vPrice[TAM], cod, price;
  int nroCustomer, codArticle, month, day, quantitySold;

  cout << "CARGO LOT!!!" << endl;
  for (int x = 0; x < TAM; x++){
    cout << x+1 << ") Enter a code(4 digit): ";
    cin >> cod;
    cout << x+1 << ") Enter a price: ";
    cin >> price;
    vCod[x] = cod;
    vPrice[x] = price;
  }

  int vCounterQuantitySold[TAM] = {};
  bool vMonth[12] = {};

  cout << "Enter customer number (1 to 300)(FINISH WHIT ZERO): ";
  cin >> nroCustomer;
  while (nroCustomer != 0)
  {
    cout << "Enter the article code(4 digit): ";
    cin >> codArticle; 
    cout << "Enter the month(1 to 12): ";
    cin >> month;
    cout << "Enter the day(1 to 31): ";
    cin >> day;
    cout << "Enter quantity sold: ";
    cin >> quantitySold; 

    int index;
    for(int x = 0; x < TAM; x ++)
      if(vCod[x] == codArticle)
        index = x;
    
    vCounterQuantitySold[index] += quantitySold;
    vMonth[month-1] = true;

    cout << "Enter customer number: ";
    cin >> nroCustomer;
  }

  int aux;
  for(int y = 0; y < TAM; y ++){
    for(int x = 0; x < TAM -1; x ++){
      if(vCounterQuantitySold[x] < vCounterQuantitySold[x+1]){
        aux = vCounterQuantitySold[x+1];
        vCounterQuantitySold[x+1] = vCounterQuantitySold[x];
        vCounterQuantitySold[x] = aux;
        aux = vCod[x+1];
        vCod[x+1] = vCod[x];
        vCod[x] = aux;
      }
    }
  }

  cout << endl;
  cout << "Article Code \t|\t Total Quantity Sold" << endl;
  cout << "----------------|---------------------" << endl;
    for (int x = 0; x < TAM; x++){
    cout << vCod[x] << "\t\t|\t\t" << vCounterQuantitySold[x] << endl;
  }

  cout << endl;
  cout << "Month with no sales:" << endl;
  for(int x = 0; x < 12; x++)
    if(!vMonth[x])
      seeMonthFX(x);
  
  int accum = 0;
  float average;
  for(int x = 0; x < TAM; x ++){
    accum += vCounterQuantitySold[x];
  }
  average = (float)accum / TAM;

  for(int x = 0; x < TAM; x ++){
    if(vCounterQuantitySold[x] > average)
      cout << endl << "Article ID more than average is: " << vCod[x];
  }

  return 0;
}