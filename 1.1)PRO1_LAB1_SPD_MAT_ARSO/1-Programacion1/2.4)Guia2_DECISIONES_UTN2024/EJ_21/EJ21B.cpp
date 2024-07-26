#include <iostream>
using namespace std;
/*Una marroquinería dispone de 45 carteras blancas, 50 carteras negras, 40
 marrones y 49 grises. 
 
 Se pide hacer un programa donde se ingresen tres  ventas. 
 
Cada venta está compuesta por:
1-Cantidad de carteras
2-Tipo de cartera (1- Blanco, 2- Negro, 3- Marrón, 4- Gris)

Calcular e informar:--
Cantidad total de carteras vendidas en total.
 Cuántas carteras quedaron de cada tipo.
 Los colores de carteras que no se vendieron.
 NOTA: Ninguna venta superará las 10 carteras.*/

const int TAM_CARTERA_BLANCAS = 45;
const int TAM_CARTERA_NEGRA = 50;
const int TAM_CARTERA_MARRON = 40;
const int TAM_CARTERA_GRIS = 49;

int main (){
int carteraBlanca = TAM_CARTERA_BLANCAS, carteraNegra =  TAM_CARTERA_NEGRA, carteraGris = TAM_CARTERA_GRIS, carteraMarron = TAM_CARTERA_MARRON; //ESTRUCTURA
 
int tipoCarteraVenta1, cantidadCarteraVenta1;
int tipoCarteraVenta2, cantidadCarteraVenta2;
int tipoCarteraVenta3, cantidadCarteraVenta3;
bool ventaMenora10 = true; // validacion ejemplo 

int cantidadTotalVendida = 0; //PUNTO A
bool noseVendioBlanco = true, noseVendioNegro = true, noseVendioMarron = true, noseVendioGris = true, noseVendieronTodas = true;

 //ventas
  cout << "****MENU****\n";
  cout << "1-Ingrese el TIPO de cartera que quiere comprar (1- Blanco, 2- Negro, 3- Marron, 4- Gris): ";
  cin >> tipoCarteraVenta1;
  cout << "1-Ingrese la CANTIDAD de carteras que quiere comprar: ";
  cin >> cantidadCarteraVenta1;
  if(cantidadCarteraVenta1 > 10){
    ventaMenora10 = false;
  }

  if(!ventaMenora10){
    cout << "NO PUEDES COMPRAR MAS DE 10 CARTERAS -> Ingresa nuevamente la cantidad de la cartera " << tipoCarteraVenta1 << ": ";
    cin >> cantidadCarteraVenta1;
  }

  cout << "\n2-Ingrese el TIPO de cartera que quiere comprar (1- Blanco, 2- Negro, 3- Marron, 4- Gris): ";
  cin >> tipoCarteraVenta2;
  cout << "2-Ingrese la CANTIDAD de carteras que quiere comprar: ";
  cin >> cantidadCarteraVenta2;

  cout << "\n3-Ingrese el TIPO de cartera que quiere comprar (1- Blanco, 2- Negro, 3- Marron, 4- Gris): ";
  cin >> tipoCarteraVenta3;
  cout << "3-Ingrese la CANTIDAD de carteras que quiere comprar: ";
  cin >> cantidadCarteraVenta3;

  cout << "\nPROCESANDO LAS VENTAS...\n";
  system("pause");
  
  //punto A
  cantidadTotalVendida  += (cantidadCarteraVenta1 + cantidadCarteraVenta2 + cantidadCarteraVenta3);

  //PTO B
  switch(tipoCarteraVenta1)
  {
    case 1:
      carteraBlanca -= cantidadCarteraVenta1;
      break;
    case 2:
      carteraNegra -= cantidadCarteraVenta1;
      break;
    case 3:
      carteraMarron -= cantidadCarteraVenta1;
      break;
    case 4:
      carteraGris -= cantidadCarteraVenta1;
      break;
  }

  switch(tipoCarteraVenta2)
  {
    case 1:
      carteraBlanca -= cantidadCarteraVenta2;
      break;
    case 2:
      carteraNegra -= cantidadCarteraVenta2;
      break;
    case 3:
      carteraMarron -= cantidadCarteraVenta2;
      break;
    case 4:
      carteraGris -= cantidadCarteraVenta2;
      break;
  }


  switch(tipoCarteraVenta3)
  {
    case 1:
      carteraBlanca -= cantidadCarteraVenta3;
      break;
    case 2:
      carteraNegra -= cantidadCarteraVenta3;
      break;
    case 3:
      carteraMarron -= cantidadCarteraVenta3;
      break;
    case 4:
      carteraGris -= cantidadCarteraVenta3;
      break;
  }

  


  cout << "\nPto A -> La cantidad total de carteras vendidas es: " << cantidadTotalVendida << endl;
  cout << "Pto B -> STOCK ACTUAL DE CARTERAS: " << endl;
  cout << "Carteras Blancas: " << carteraBlanca << endl;
  cout << "Carteras Negras: " << carteraNegra << endl;
  cout << "Carteras Marrones: " << carteraMarron << endl;
  cout << "Carteras Grises: " << carteraGris << endl;

  //PUNTO C
  cout << "\nCARTERAS QUE NO SE VENDIERON(STOCK ESTA COMPLETO): " << endl;
  if(carteraBlanca == TAM_CARTERA_BLANCAS){ //45 == 45
    cout << "BLANCOS" << endl;
  } else{
    noseVendioBlanco = false; //por que si se vendio
  }  

  
  if(carteraNegra == TAM_CARTERA_NEGRA){//50 == 50
    cout << "NEGRAS" << endl;
  }else{
    noseVendioNegro = false;//por que si se vendio
  }

  if(carteraMarron == TAM_CARTERA_MARRON){//40 == 40
    cout << "MARRON" << endl;
  }else{
    noseVendioMarron = false;//por que si se vendio
  }

  if(carteraGris == TAM_CARTERA_GRIS){ //40 == 49
    cout << "GRIS" << endl;
  }else{
    noseVendioGris = false;//por que si se vendio
  }

  if(!noseVendioBlanco && !noseVendioNegro && !noseVendioMarron && !noseVendioGris){
    cout << "QUE SUERTE! SE VENDIERON TODAS :)" << endl;
  }

  

  return 0;
 }