#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int codigoProducto, tipoProducto;
  //int kgVendidos;
  float recaudado;
  int codigoMenorRecaudado; //A)
  float menorRecaudado = -1; //A)
  float totalRecaudadoFactura = 0,totalRecaudadoTorta = 0, totalRecaudadoPanificado = 0; //B)

  cout << endl << "Ingrese el codigo del producto (corta con -1): ";
  cin >> codigoProducto;
  if(codigoProducto > 0){
    cout << "Ingrese el tipo de producto (1-Factura, 2-Torta, 3-Panificado): ";
    cin >> tipoProducto;
    /*cout << "Ingrese los KG vendidos: ";
    cin >> kgVendidos;*/
    cout << "Ingrese el total recaudado: ";
    cin >> recaudado;
    cin.ignore(); 
  }
    
  while (codigoProducto > 0)
  {
    if(menorRecaudado == -1){
      menorRecaudado = recaudado;
      codigoMenorRecaudado = codigoProducto;
    }else if(recaudado < menorRecaudado){
      menorRecaudado = recaudado;
      codigoMenorRecaudado = codigoProducto;
    }

    switch (tipoProducto)
    {
      case 1:
        totalRecaudadoFactura += recaudado;
      break;
      case 2:
        totalRecaudadoTorta += recaudado;
      break;
      case 3:
        totalRecaudadoPanificado += recaudado;
      break;   
    }

    cout << endl << "Ingrese el codigo del producto (corta con -1): ";
    cin >> codigoProducto;
    if(codigoProducto > 0){
      cout << "Ingrese el tipo de producto (1-Factura, 2-Torta, 3-Panificado): ";
      cin >> tipoProducto;
      /*cout << "Ingrese los KG vendidos: ";
      cin >> kgVendidos;*/
      cout << "Ingrese el total recaudado: ";
      cin >> recaudado;
      cin.ignore(); 
    }  
  }

  cout << endl <<"El codigo de producto que recaudo menor dinero es: " << codigoMenorRecaudado << ". Recaudo $" << fixed <<setprecision(2) << menorRecaudado << endl;
  cout << "*****PORCENTAJES POR TIPO DE PRODUCTO*****" << endl;
  cout << "Factura %" << fixed << setprecision(2) << totalRecaudadoFactura * 100 /(totalRecaudadoFactura + totalRecaudadoTorta + totalRecaudadoPanificado) << endl; 
  cout << "Torta %" << fixed << setprecision(2) << totalRecaudadoTorta * 100 /(totalRecaudadoFactura + totalRecaudadoTorta + totalRecaudadoPanificado) << endl; 
  cout << "Panificados %" << fixed << setprecision(2) << totalRecaudadoPanificado * 100 /(totalRecaudadoFactura + totalRecaudadoTorta + totalRecaudadoPanificado) << endl; 

  return 0;
}