#include <iostream>

using namespace std;

int main() {
  /***************************/
  int numArticulo, dia, cantArtVendidos; //1 a 10 y 1 a 31
  float precioCosto, precioVenta;
  /***************************/
  //corte control
  int numArticuloActual;
  /**************************/
  //PUNTO A -> numero articulo que mas ganacia haya recaudado
  float gananciaMax = 0,  gananciaSubLote;
  int numArtMaxGanancia;
  /**************************/
  //PUNTO B -> cantidad total de articulos vendidos en cada quincena sintener en cuenta los art que no registraron ventas
  int contadorVentaPrimerQuin = 0, contadorVentaSegundoQuin = 0;
  /**************************/
  //PUNTO C -> teniendo el total de ventas => el % de ventas para la primera semana del mes
  int contadorPrimerSemana = 0, totalVentaMes;
  float porcentajeVentaPrimerSemana = 0.0;
  /**************************/
  //PUNTO D -> cantidad de ventas del art 5 el dia 16 del mes;
  int cantidadArt5Dia16 = 0;

  cout << "Ingrese el numero de articulo: ";cin >> numArticulo;
  if(numArticulo !=0){
      cout << "Ingrese el dia (1 a 31): ";cin >> dia;
      cout << "Ingrese la cantidad vendida: ";cin >> cantArtVendidos;
      cout << "Ingrese el precio de costo: ";cin >> precioCosto;
      cout << "Ingrese el precio de venta: ";cin >> precioVenta;
  } 

  while(numArticulo != 0){ //corta el LOTE

    gananciaSubLote = 0;//PTOA
    numArticuloActual = numArticulo;//C.C
    while (numArticulo == numArticuloActual){//corta el subLote

      gananciaSubLote += (cantArtVendidos * (precioVenta - precioCosto)); //PTOA

      if(cantArtVendidos > 0){
        (dia <= 15) ? contadorVentaPrimerQuin += cantArtVendidos : contadorVentaSegundoQuin += cantArtVendidos; //PTOB
      }
      contadorPrimerSemana += (dia <=7) ? cantArtVendidos : 0; //PTOC
      cantidadArt5Dia16 += (dia == 16 && numArticulo == 5) ? cantArtVendidos : 0;//PTOD


      cout << "Ingrese el numero de articulo: ";cin >> numArticulo;
      if(numArticulo !=0){
        cout << "Ingrese el dia (1 a 31): ";cin >> dia;
        cout << "Ingrese la cantidad vendida: ";cin >> cantArtVendidos;
        cout << "Ingrese el precio de costo: ";cin >> precioCosto;
        cout << "Ingrese el precio de venta: ";cin >> precioVenta;
      } 

    }//1er while




    if(gananciaSubLote > gananciaMax){
      gananciaMax = gananciaSubLote;
      numArtMaxGanancia = numArticuloActual;      
    }




  }  //2do while

  totalVentaMes = contadorVentaPrimerQuin + contadorVentaSegundoQuin;//PTOC
  porcentajeVentaPrimerSemana = (contadorPrimerSemana * 100.0f) / totalVentaMes;//PTOC

  cout << "PTOA -> El articulo con mas ganancia es: " << numArtMaxGanancia << " con una ganancia de: " << gananciaMax << endl;
  cout << "PTOB -> La venta en primer quincena fue de: " << contadorVentaPrimerQuin << " y en la segunda de: " << contadorVentaSegundoQuin << endl;
  cout << "PTOC -> El porcentaje de ventas en la primer semana fue de: " << porcentajeVentaPrimerSemana << "%" << endl;
  (cantidadArt5Dia16 != 0) ? (cout << "PTOD -> La cantidad de ventas del art 5 el dia 16 del mes fue de: " << cantidadArt5Dia16 << endl) : (cout << "PTOD -> No se encontraron ventas del art 5 el dia 16 del mes" << endl);

  return 0;
}