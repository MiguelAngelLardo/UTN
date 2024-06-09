#include<iostream>

using namespace std;

const int TAM_PROD = 1250;
const int TAM_MARCA = 30; 
const int TAM_CLIENTE = 1501;

struct Producto
{
  int nroProducto;
  int nroMarca;
  float precio;
};

void carga (Producto []);
void proceso(Producto [], int [], float [], int [], int []);

void fPTOA(int , int , Producto [], int []);
void fPTOB(int, int, int, Producto [], float []);
void fPTOC(int, int, int, int, int []);
void fPTOD(int, int , int []);

void mostrasVectorA(int , int []);
void mostrasVectorB(float []);
void mostrasVectorC(int []);
int mostrasVectorD(int []);

int main()
{

  Producto vProductos[TAM_PROD];
  int vCantidadProdVendPorMarca[TAM_MARCA] = {};
  float totalGastadoPorCliente[TAM_CLIENTE] = {};
  int mesJulio[31] = {};
  int productoMasVendido[TAM_PROD] = {};

  carga(vProductos);
  proceso(vProductos, vCantidadProdVendPorMarca, totalGastadoPorCliente, mesJulio, productoMasVendido);

  mostrasVectorA(TAM_MARCA, vCantidadProdVendPorMarca);
  mostrasVectorB(totalGastadoPorCliente);
  mostrasVectorC(mesJulio);
  int maxVendido = mostrasVectorD(productoMasVendido);
  cout << endl << "PUNTO D: PRODUCTO MAS VENDIDO." << endl;
  cout << "El producto mas vendido fue: " << maxVendido;

  return 0;
}  

void carga (Producto vProductos []){

  for(int x = 0; x < TAM_PROD; x ++){
    cout << x + 1 << ") Ingrese un nro de producto (1 a 1250): ";
    cin >> vProductos[x].nroProducto;
    cout << x + 1 << ") Ingrese un nro de marca (1 a 30): ";
    cin >> vProductos[x].nroMarca;
    cout << x + 1 << ") Ingrese el Precio: ";
    cin >> vProductos[x].precio;
  }
}

void proceso(Producto vProductos [], int vCantidadPRodVendPorMarca[], float totalGastadoPorCliente[], int mesJulio[], int productoMasVendido[]){
  int nroCliente, nroProducto, cantidad, dia, mes;

  cout << endl;
  cout << "Ingrese el nro de cliente(1000 a 2500): ";
  cin >> nroCliente;
  cout << "Ingrese el nro de producto(1 a 1250): ";
  cin >> nroProducto;
  cout << "Ingrese la cantidad: ";
  cin >> cantidad;
  cout << "Ingrese el dia: ";
  cin >> dia;
  cout << "Ingrese el mes: ";
  cin >> mes;
  while (dia !=0 )
  {
    fPTOA(nroProducto, cantidad, vProductos, vCantidadPRodVendPorMarca);
    fPTOB(nroProducto, cantidad, nroCliente, vProductos, totalGastadoPorCliente);
    fPTOC(nroProducto, dia, mes, cantidad, mesJulio);
    fPTOD(nroProducto, cantidad, productoMasVendido);

    cout << "Ingrese el nro de cliente(1000 a 2500): ";
    cin >> nroCliente;
    cout << "Ingrese el nro de producto(1 a 1250): ";
    cin >> nroProducto;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
  }
}

void fPTOA(int nroProducto, int cantidad, Producto vProductos[], int vCantidadPRodVendPorMarca[]){
  int marcaActual;
  for (int x = 0; x < TAM_PROD; x++){
    if(nroProducto == vProductos[x].nroProducto){
      marcaActual = vProductos[x].nroMarca;
      vCantidadPRodVendPorMarca[marcaActual-1] += cantidad;
    }
  }
}

void mostrasVectorA(int  tam, int v[]){
  cout << endl << "PUNTO A: Cantidad de productos vendidos de cada marca." << endl;
  for(int x = 0; x < tam; x++){
    cout << "Marca " << x + 1 << " cantidad vendia: " << v[x] << endl;
  }
}

void fPTOB(int nroProducto, int cantidad, int nroCliente, Producto vProductos [], float totalGastadoPorCliente[]){
  totalGastadoPorCliente[nroCliente-1000] += vProductos[nroProducto -1].precio * cantidad;
}

void mostrasVectorB(float v[]){
  cout << endl << "PUNTO B: Cuanto gasto cada cliente." << endl;
  for(int x = 0; x < TAM_CLIENTE; x++){
    cout << "Cliente nro " << x + 1000 << " gasto $ " << v[x]<< endl;
  }
}

void fPTOC(int nroProducto, int dia, int mes, int cantidad, int mesJulio[]){
  int productoObjetivo = 1003;
  if (nroProducto == productoObjetivo && mes == 7) {
    mesJulio[dia - 1] += cantidad;
  }
}

void mostrasVectorC(int v[]){
  cout << endl << "PUNTO C: Dias que no se registraron ventas con producto 1003 en julio." << endl;
  for(int x = 0; x < 31; x++){
    if(v[x] == 0){
      cout << "EL dia " << x+1 << " no se registro venta" << endl;
    }  
  } 
}

void fPTOD(int nroProducto, int cantidad, int productoMasVendido []){
  productoMasVendido[nroProducto-1] += cantidad;
}

int mostrasVectorD(int v[]){
  int maxVenta = v[0];
  int productoMaxVendido = 1;

  for (int x = 1; x < TAM_CLIENTE; x ++){
    if(v[x] > maxVenta){
      maxVenta = v[x];
      productoMaxVendido = x +1;
    }
  }
  return productoMaxVendido;
}
