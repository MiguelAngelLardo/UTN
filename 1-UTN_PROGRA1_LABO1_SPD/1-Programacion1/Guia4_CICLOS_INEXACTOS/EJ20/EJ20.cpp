#include <iostream>
using namespace std;

int main() {
	
	int numeroCliente, localidadCliente, consumoKiloVatios, tarifa, consumoMinimo, clienteMenorconsumoKV;
  int mayorConsumoVatios1 = 0, mayorConsumoVatios2 = 0, mayorConsumoVatios3 = 0;
	int ClienteMayorKVConsumidosLocalidad1, ClienteMayorKVConsumidosLocalidad2, ClienteMayorKVConsumidosLocalidad3 ;
  int totalRecaudacionLocalidad1 = 0, totalRecaudacionLocalidad2 = 0, totalRecaudacionLocalidad3 = 0;
  bool banderaConsumoMinimo = false;

	cout << endl << "Ingrese el numero de cliente (corta con cero): ";
	cin >> numeroCliente;
	cout << "Ingrese la localidad (1,2,3) del cliente " << numeroCliente << ": ";
	cin >> localidadCliente;
	cout << "Ingrese los kilovatios consumidos: ";
	cin >> consumoKiloVatios;
	
	while (numeroCliente != 0)
	{
		
    tarifa = 0;
    if (consumoKiloVatios <= 100)
      tarifa = consumoKiloVatios * 10 + 100;
    else if (consumoKiloVatios > 100 && consumoKiloVatios <= 200)
      tarifa = 100 * 10 + (consumoKiloVatios - 100) * 12 + 100;
    else
      tarifa = 100 * 10 + 100 * 12 + (consumoKiloVatios - 200) * 15 + 100;
    
    if(consumoKiloVatios > 0 && !banderaConsumoMinimo)
      {
        consumoMinimo = tarifa;
        clienteMenorconsumoKV = numeroCliente;
        banderaConsumoMinimo = true;
      }
    else
    {
      if(tarifa < consumoMinimo)
      {
        consumoMinimo = tarifa;
        clienteMenorconsumoKV = numeroCliente;
      }
    }

    switch (localidadCliente)
    {
      case 1:   
        if(tarifa > mayorConsumoVatios1)
        {
          mayorConsumoVatios1 = tarifa;
          ClienteMayorKVConsumidosLocalidad1 = numeroCliente;
        }  
        totalRecaudacionLocalidad1 += tarifa;
      break;

      case 2:        
        if(tarifa > mayorConsumoVatios2)
        {
          mayorConsumoVatios2 = tarifa;
          ClienteMayorKVConsumidosLocalidad2 = numeroCliente;
        } 
        totalRecaudacionLocalidad2 += tarifa;
      break;

      case 3:        
        if(tarifa > mayorConsumoVatios3)
        {
          mayorConsumoVatios3 = tarifa;
          ClienteMayorKVConsumidosLocalidad3 = numeroCliente;
        } 
        totalRecaudacionLocalidad3 += tarifa;
      break;
    
      default:
        cout << "No ingreso una localidad valida.";
      break;
    }
       
    cout << endl << "Ingrese el numero de cliente (corta con cero): ";
    cin >> numeroCliente;	
    if(numeroCliente != 0)
    {
     cout << "Ingrese la localidad (1,2,3) del cliente " << numeroCliente << ": ";
      cin >> localidadCliente;
      cout << "Ingrese los kilovatios consumidos: ";
      cin >> consumoKiloVatios;
    }	
	}

  cout << endl << "Localidad 1 => Recaudacion: $ " << totalRecaudacionLocalidad1 << "-. Cliente con mayor consumo: " << ClienteMayorKVConsumidosLocalidad1;
  cout << endl << "Localidad 2 => Recaudacion: $ " << totalRecaudacionLocalidad2 << "-. Cliente con mayor consumo: " << ClienteMayorKVConsumidosLocalidad2;
  cout << endl << "Localidad 3 => Recaudacion: $ " << totalRecaudacionLocalidad3 << "-. Cliente con mayor consumo: " << ClienteMayorKVConsumidosLocalidad3;
  cout << endl << "Cliente con menor consumo: " << clienteMenorconsumoKV;	

	return 0;
}