#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int const CLIENTES = 3; //va 200

struct cliente{
  int codCliente;
  int documento;
  int zona;
  int antiguead;
};

void carga(cliente []);
void proceso(cliente [], float [], int [], float [], bool []);

void ptoA(cliente [], float [], int, float);
void mostrarPTOA (cliente [], float []);
void ordenamientoMayorMenor (cliente [], float []);
void ptoB(cliente [], int [], int);
void mostrarPTOB(cliente [], int []);
void ptoC(cliente [], float [], int, float);
void mostrarPTOCyD(cliente [], float []);
void mostrarPTOE(bool []);

main()
{
  cliente clientes[CLIENTES];
  float vImporteTotal[CLIENTES]; //PTOA
  int vTresCompras [CLIENTES] = {}; //PTOB
  float vVentasPorZona[5] = {}; //PTOCyD
  bool vNumArtVendido[30] = {};//PTOE

  carga(clientes);
  proceso(clientes, vImporteTotal, vTresCompras, vVentasPorZona, vNumArtVendido);
  mostrarPTOA (clientes, vImporteTotal);
  mostrarPTOB(clientes, vTresCompras);
  mostrarPTOCyD(clientes, vVentasPorZona);
  mostrarPTOE(vNumArtVendido);
}

void carga(cliente clientes[]){
  cout << "CARGA" << endl;
  for(int x = 0; x < CLIENTES; x ++){
    cout << x+1 <<")Ingrese el codigo del cliente (1 a 200): ";
    cin >> clientes[x].codCliente;
    cout << x+1 <<")Ingrese el documento: ";
    cin >> clientes[x].documento;
    cout << x+1 <<")Ingrese la zona del cliente (1 a 5): ";
    cin >> clientes[x].zona;
    cout << x+1 << ")Ingrese la antiguedad: ";
    cin >> clientes[x].antiguead;
  }
}

void proceso(cliente clientes [], float vImporteTotal  [], int vTresCompras [], float vVentasPorZona [], bool vNumArtVendido []){
  int nroFactura, codCliente, numArticuloVendido;
  float importeVenta;
  cout << endl << "PROCESO" << endl;
  cout << "Ingrese el numero de factura (CORTA CONCERO): ";
  cin >> nroFactura;
  while (nroFactura !=0)
  {
    cout << "Ingrese el codigo del cliente (1 a 200): ";
    cin >> codCliente;
    cout << "Ingrese el numero de articulo vendido: ";
    cin >> numArticuloVendido;
    cout << "Ingrese el importe de la venta: ";
    cin >> importeVenta;

    ptoA(clientes, vImporteTotal, codCliente, importeVenta);
    ptoB(clientes, vTresCompras , codCliente);
    ptoC(clientes, vVentasPorZona, codCliente, importeVenta);
    vNumArtVendido[numArticuloVendido-1] = true;

    cout << "Ingrese el numero de factura (CORTA CON CERO): ";
    cin >> nroFactura;
  }
}

void ptoA(cliente clientes [], float vImporteTotal [], int codCliente, float importeVenta){
  for(int x = 0; x < CLIENTES; x ++){
    if(codCliente == clientes[x].codCliente){
      vImporteTotal[x] += importeVenta;
    }
  }
}

void mostrarPTOA (cliente clientes [], float vImporteTotal []){
  ordenamientoMayorMenor (clientes, vImporteTotal);
  cout << "PUNTO A" << endl;
  cout << "CLIENTE\t\t|\t\tImporte Total Vendido" << endl;
  for (int x = 0; x < CLIENTES; x ++){
    cout << clientes[x].codCliente << "\t\t|\t\t" << vImporteTotal[x] << endl;
  }
}

void ordenamientoMayorMenor (cliente clientes [], float vImporteTotal []){
  int aux;
  for (int x = 0; x < CLIENTES; x ++){
    for(int x = 0; x < CLIENTES-1; x ++){
      if(vImporteTotal[x] < vImporteTotal[x+1]){
        aux = vImporteTotal[x];
        vImporteTotal[x] = vImporteTotal[x+1];
        vImporteTotal[x+1] = aux;
        aux = clientes[x].codCliente;
        clientes[x].codCliente = clientes[x+1].codCliente;
        clientes[x+1].codCliente = aux;
      }
    }
  }
}

void ptoB(cliente clientes [], int vTresCompras [], int codCliente){
  for(int x = 0;  x < CLIENTES; x ++){
    if(clientes[x].codCliente == codCliente){
      vTresCompras[x] ++;
    }
  }
}

void mostrarPTOB(cliente clientes [], int vTresCompras []){
  cout << endl << "PUNTO B" << endl;
  for(int x = 0; x < CLIENTES; x ++){
    if(vTresCompras[x] > 3){
      cout << "NUMERO DOCUMENTO: " << clientes[x].documento << " | CODIGO: " << clientes[x].codCliente << endl;
    }
  }
}

void ptoC(cliente clientes [], float vVentasPorZona [], int codCliente, float importeVenta){
  vVentasPorZona[(clientes[codCliente-1].zona)-1] += importeVenta;
}

void mostrarPTOCyD(cliente clientes [], float vVentasPorZona []){
   float mayorVenta = vVentasPorZona[0];
   int mayorZona = 0;
   for (int x = 1; x < 5; x++){
    if(vVentasPorZona[x] > mayorVenta){
      mayorVenta = vVentasPorZona[x];
      mayorZona = x;   
    }
  }
  cout << endl << "PUNTO C" << endl;
  cout << "LA MAYOR VENTA FUE EN LA ZONA: " << mayorZona + 1 << " con el monto de $" << mayorVenta<< endl;  

  int contador = 0;
  int acumAntiguedad = 0;
  for(int x = 0; x < CLIENTES; x ++){
    if(mayorZona+1 == clientes[x].zona){
      contador ++;
      acumAntiguedad += clientes[x].antiguead;
    }
  }

  cout << endl << "PUNTO D" << endl;
  cout << "EL PROMEDIO DE ANTIGUEDAD  DE LA ZONA " << mayorZona + 1 << " es: " << fixed << setprecision(2) << (float)acumAntiguedad / contador << endl;
}

void mostrarPTOE( bool vNumArtVendido []){
  cout << endl << "PUNTO E" << endl;
  cout << "ARTICULOS SIN REGISTRO DE VENTA: " << endl;
  for(int x = 0; x < 30; x ++){
    if(!vNumArtVendido[x]){
      cout << x+1 << endl;
    }
  }
}