#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;// Usamos el espacio de nombres estándar

const int VUELOS = 50;

void fCarga(int [], int [], float [], float []);
void fProceso(float [], float [], int [], int [], float [], float [], int [], float [], float []);

void buscarMaxPTA(float []);//PTOA
void maximoVenta(int, int, int, int [], int []); //PTOB
void mostrarPTOB(int, int []); //PTOB
void calcularRecaudacion (int, int, int, float [], float []); //PTOC
void mostrarPTOC(float []);
void vendedorPuntoD(int, int, int, int, float, int [], float []);
void mostrarPuntoD(int []);
void calcularRecaBimestral (float, int, int, float [], float []);
void mostrarPuntoE(float []);

int main()
{
  int v_origen[VUELOS] , v_destino[VUELOS];
  float v_costo[VUELOS], v_distancia[VUELOS];

  float millasPTA[150] = {};//PTOA
  int v_max[12] = {}, vendedor_max[12]= {}; // PTB
  float recaudacionVendedor[8] = {}; // PTC
  int vendedorPuntoD[8] = {}; //PTD
  float ventaMaxPtoD[8] = {}; //PTD
  float v_bimestre[6] = {}; // PTE

  fCarga(v_origen, v_destino, v_costo,  v_distancia);
  fProceso(millasPTA, v_distancia, v_max, vendedor_max, v_costo, recaudacionVendedor, vendedorPuntoD, ventaMaxPtoD, v_bimestre);

  buscarMaxPTA(millasPTA);
  mostrarPTOB(12, vendedor_max);
  mostrarPTOC(recaudacionVendedor);
  mostrarPuntoD(vendedorPuntoD);
  mostrarPuntoE(v_bimestre);
}

void fCarga(int v_origen [], int v_distino[], float v_costo [], float v_distancia []){
  int ciudad_origen, ciudad_destino;
  float costo, distancia; 

  for(int x = VUELOS-1; x >= 0; x --){

    cout << x+1 << ") Ingrese la Ciudad de Origen(1 - 20): ";
    cin >> ciudad_origen;
    cout << x+1 << ") Ingrese el destino(1 - 20): ";
    cin >> ciudad_destino;
    cout << x+1 << ") Ingrese el costo del pasaje (por persona): ";
    cin >> costo;
    cout << x+1 << ") Ingrese la distancia(en millas): ";
    cin >> distancia;
    cout << endl;

    v_origen[x] = ciudad_origen;
    v_distancia[x] = ciudad_destino;
    v_costo[x] = costo;
    v_distancia[x] = distancia;
  }
}

void fProceso(float millasPTA[], float v_distancia[], int v_max[], int vendedor_max[], float v_costo[], float recaudacionVendedor[], int vendedorPuntoD [], float ventaMaxPtoD [], float v_bimestre []){

  int nroCliente, codVuelo, dia, mes, cantPasaje, nroVendedor;
  cout <<" Ingrese el numero de cliente (1 - 150): ";
  cin >> nroCliente;
  cout <<" Ingrese el codigo de vuelo (1 - 50): ";
  cin >> codVuelo;
  cout <<" Ingrese el dia de la venta (1 - 31)(CORTA CON CERO): ";
  cin >> dia;
  while(dia != 0)
  {

    cout <<" Ingrese el mes de la venta (1 - 12): ";
    cin >> mes;
    cout <<" Ingrese la cantidad de pasajes adquiridos: ";
    cin >> cantPasaje;
    cout <<" Ingrese el numero del vendedor (1 - 8): ";
    cin >> nroVendedor;
    cout << endl;

    //PTOA
    millasPTA[nroCliente-1] += v_distancia[codVuelo-1]*cantPasaje;

    //PTOB
    maximoVenta(cantPasaje, nroVendedor, mes, v_max, vendedor_max);

    //PTOC
    calcularRecaudacion (cantPasaje, nroVendedor, codVuelo, v_costo, recaudacionVendedor);

    //PTOD
    mostrarPuntoD(vendedorPuntoD);

    //PTOE
    float importe = v_costo[codVuelo -1] * cantPasaje; //PTE
    calcularRecaBimestral (importe, mes, codVuelo, v_distancia, v_bimestre);

    cout <<" Ingrese el numero de cliente (1 - 150): ";
    cin >> nroCliente;
    cout <<" Ingrese el codigo de vuelo (1 - 50): ";
    cin >> codVuelo;
    cout <<" Ingrese el dia de la venta (1 - 31)(CORTA CON CERO): ";
    cin >> dia;
  }
}

void buscarMaxPTA(float millasPTA[]){
  float max;
  int clienteMax;
  max = millasPTA[0];
  clienteMax = 1;
  
  for(int x = 1;x < 50; x++){
    if(millasPTA[x] > max){
      max = millasPTA[x];
      clienteMax = x + 1;
    }
  }

  cout << endl << "El cliente que mas millas recorrio es el Numero " << clienteMax << " y lo hizo con " << max << " millas" << endl;

}

void maximoVenta(int cantPasaje, int nroVendedor, int mes, int v_max[], int vendedor_max[]){
  if(cantPasaje > v_max[mes-1]){
    v_max[mes-1] = cantPasaje;
    vendedor_max[mes-1] = nroVendedor;
  }
}

void mostrarPTOB(int tam, int v[]){
  cout << endl; 
  for(int x = 0; x < tam; x++){
    cout << "MES " << x+1 << "-> el numero de vendedor que realizo la venta individual por mayor cantidad de pasajes es: " << v[x] << endl; 
  }
}

void calcularRecaudacion (int cantPasaje, int nroVendedor, int codVuelo, float v_costo[], float recaudacionVendedor []){
  recaudacionVendedor[nroVendedor-1] += (cantPasaje * v_costo [codVuelo-1]) * 0.05;
}

void mostrarPTOC(float v[]){
  cout << endl;
  for (int x = 7; x >= 0; x++){
    if(v[x] != 0){
      cout << "Vendedor: " << x + 1 << " -> comision: " << v[x];
    }
  }
}

void vendedorPuntoD(int nroCliente, int cantPasaje, int codVuelo, int nroVendedor, float v_costo [], int vendedorPuntoD [], float ventaMaxPtoD []){
  float totalCosto;
  totalCosto = cantPasaje * v_costo[codVuelo-1];

  if(totalCosto > ventaMaxPtoD [nroVendedor-1]){
    ventaMaxPtoD[nroVendedor-1] = totalCosto;
    vendedorPuntoD[nroVendedor-1] = nroCliente;
  }
}

void mostrarPuntoD(int vendedorPuntoD[]){
  cout << endl;
  for(int x = 0; x < 8; x++){
    if(vendedorPuntoD !=0){
      cout << "El vendedor " << x+1 << "tuvo la mayor venta en el cliente " << vendedorPuntoD[x] << endl;
    }else{
      cout << "El vendedor " << x+1 <<  "No registro ventas." << endl;
    }
  }
}

void calcularRecaBimestral (float importe, int mes, int codVuelo, float v_distancia[], float v_bimestre []){
  
  if(v_distancia[codVuelo - 1] > 500){
    if(mes % 2 !=0){
      mes = mes / 2;
    }else{
      mes = (mes/2) -1;
    }
  }

  v_bimestre[mes] += importe;
}

void mostrarPuntoE(float bimestre[]){
  cout << endl;
  for (int x = 0; x < 6; x++){
    cout << "Bimestre: " << x + 1 << endl;
    cout << "Recaudacion total: " << bimestre[x] << endl; 
  }
}
