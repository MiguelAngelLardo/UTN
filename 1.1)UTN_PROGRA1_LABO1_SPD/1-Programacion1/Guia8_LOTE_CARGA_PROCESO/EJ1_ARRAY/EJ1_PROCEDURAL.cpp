#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****/
const int TAM = 3;

void setToZeroFX(int T, int vGeneric[]){//Recibe 1 vector con tamaño T. 1 FUNCION ATOMICA!
  for (int i = 0; i < T; i++){
    vGeneric[i] = 0;
  }  
} 
void setToFalseFX(bool (&vMes)[12]){
  for(int x = 0; x < 12; x ++){
    vMes[x] = false;
  }
}

void cargaLote1FX(int (&vectCod)[TAM], float (&vectPrec)[TAM]){
  int cod, pre;
  for (int i = 0; i < TAM; i++)
  {
    cout << "Ingrese el codigo: ";
    cin >> cod;
    cout << "Ingrese el Precio: ";
    cin >> pre;

    vectCod[i] = cod;
    vectPrec [i] = pre;
  }
}

///
int searchIndex_SUBFX(int cod, int (&vCod)[TAM]){
  for (int i = 0; i < TAM; i++)
  {
    if (cod == vCod[i]){
      return i;
    }
  }
}

void loteProcesoFX(int (&vectCod)[TAM], float (&vectPrec)[TAM], int (&vCounterPtoA)[TAM], bool (&vMes)[12]){
  int nroCustomer, codArticle, month, day, quantitySold;

  cout << "Enter customer number(1 to 300)(FINISH WHIT ZERO): ";
  cin >> nroCustomer;
  int index;
  while(nroCustomer != 0)
  { 
    cout << "Enter the article code(4 digit): ";
    cin >> codArticle; 
    cout << "Enter the month(1 to 12): ";
    cin >> month;
    cout << "Enter the day(1 to 31): ";
    cin >> day;
    cout << "Enter quantity sold: ";
    cin >> quantitySold; 

    index = searchIndex_SUBFX(codArticle, vectCod); //codigo articulo por valor y vectCod por referencia
    vCounterPtoA[index]  += quantitySold;

    vMes[month-1] = true;

    cout << "Enter customer number: ";
    cin >> nroCustomer;
  }
}

///

///
void burbujeo_SUBFX(int (&vCod)[TAM], int (&vPTOA)[TAM]){
  int aux;  
  for(int y = 0; y < TAM; y ++){
    for(int x = 0; x < TAM-1; x ++){
      if(vPTOA[x] < vPTOA [x+1]){
        aux = vPTOA[x+1];
        vPTOA[x+1] = vPTOA[x];
        vPTOA[x] = aux;
        aux = vCod[x+1];
        vCod[x+1] = vCod[x];
        vCod[x] = aux;
      }
    }
  }
}

void mostrarPUNTOA_SUBFX(int (&vCod)[TAM], int (&vPTOA)[TAM]){
   cout << endl;
  cout << "Article Code \t|\t Total Quantity Sold" << endl;
  cout << "----------------|---------------------" << endl;
    for (int x = 0; x < TAM; x++){
    cout << vCod[x] << "\t\t|\t\t" << vPTOA[x] << endl;
  }
}
void pointAFX(int (&vCod)[TAM], int (&vPtoA)[TAM]){
  burbujeo_SUBFX(vCod, vPtoA);

  mostrarPUNTOA_SUBFX(vCod, vPtoA);
}
///
void mostrarMes_SUBFX(int mes){
  switch (mes)
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
void pointBFX(bool (&vMes)[12]){
  for (int i = 0; i < 12; i++){
    if(!vMes[i])
      mostrarMes_SUBFX(i);
  }
}
///
void pointCFX(int (&vCod)[TAM], int (&vectPTOA)[TAM]){
  int acumulador; 
  float promedio;

  for(int x = 0; x < TAM; x ++){
    acumulador += vectPTOA[x];
  }

  promedio = (float) acumulador/TAM;

  for(int x = 0; x < TAM; x ++){
    if(vectPTOA[x] < promedio)
      cout << endl << "Article ID more than average is: " << vCod[x];
  }
}

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
   int vCod[TAM];
   float vPrecio[TAM];
   
   int vCounterQuantitySold[TAM];
   setToZeroFX(TAM, vCounterQuantitySold); 

   bool vMonth[12];
   setToFalseFX(vMonth);

   cargaLote1FX(vCod, vPrecio);

   loteProcesoFX(vCod, vPrecio, vCounterQuantitySold, vMonth);

   pointAFX(vCod, vCounterQuantitySold);

   pointBFX(vMonth);

   pointCFX(vCod, vCounterQuantitySold);
  
  return 0;
}