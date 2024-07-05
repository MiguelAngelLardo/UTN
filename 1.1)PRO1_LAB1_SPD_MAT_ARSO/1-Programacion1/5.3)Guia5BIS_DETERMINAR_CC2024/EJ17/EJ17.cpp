#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{ 
  
  int zona, numeroCliente, zonaActual;
  int usuariosPorZona ;
  float medidorKVMesAnterior, medidorKVMesActual, TotalFacturadoPorZonaMesAnterior, TotalFacturadoPorZonaMesActual;

  cout << "Ingrese la zona (1-10): ";
  cin >> zona;
 
  while(zona != 0)
  {
    usuariosPorZona  = 0;
    TotalFacturadoPorZonaMesAnterior = 0;
    TotalFacturadoPorZonaMesActual = 0;

    zonaActual = zona;
    while(zona == zonaActual)
    {
      usuariosPorZona  ++;
      cout << "Numero de cliente (4 numeros no correlativos): ";
      cin >> numeroCliente;
      cout << "Lectura medidor para mes anterior (KV): ";
      cin >> medidorKVMesAnterior;
      cout << "Lectura medidor para mes actual (KV): ";
      cin >> medidorKVMesActual;

      if(medidorKVMesAnterior <= 100){
        TotalFacturadoPorZonaMesAnterior += 0.10 * medidorKVMesAnterior; 
      } else if (medidorKVMesAnterior <= 200){
        TotalFacturadoPorZonaMesAnterior += 0.10 * 100 + (medidorKVMesAnterior - 100) * 0.12;
      }else{
        TotalFacturadoPorZonaMesAnterior += (0.10 * 100) + (0.12 * 100) + (medidorKVMesAnterior - 200) * 0.15;
      }
      
      if(medidorKVMesActual <= 100){
        TotalFacturadoPorZonaMesActual += 0.10 * medidorKVMesActual;
      } else if (medidorKVMesActual <= 200){
        TotalFacturadoPorZonaMesActual += 0.10 * 100 + (medidorKVMesActual - 100) * 0.12;
      }else{
        TotalFacturadoPorZonaMesActual += (0.10 * 100) + (0.12 * 100) + (medidorKVMesActual - 200) * 0.15;
      }
   
    cout << endl << "Ingrese la zona (1-10): ";
    cin >> zona;    
 
    }

    cout << endl << "Zona: " << zonaActual << endl;
    cout << "Cantidad de usuarios de la zona: " << usuariosPorZona << endl;
    cout << "Total Facturado en la zona (Mes Anterior): " << TotalFacturadoPorZonaMesAnterior << endl;
    cout << "Total Facturado en la zona (Mes Actual): " << TotalFacturadoPorZonaMesActual << endl;
  }

 return 0;
}