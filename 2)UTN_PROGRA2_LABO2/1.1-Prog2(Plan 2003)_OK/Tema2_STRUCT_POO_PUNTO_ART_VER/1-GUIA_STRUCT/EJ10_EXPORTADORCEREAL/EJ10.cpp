#include <iostream>
#include <cstring>


using namespace std;

/*
10) La cámara de exportadores de cereales y oleaginosas dispone de un lote de registros con las exportaciones
realizadas durante el último mes. Los registros cuentan con los siguientes datos:

- Código de empresa (string(6))
- Día de exportación (1 a 31)
- Código de producto (1 a 15)
- Código de país de destino (string(20))
- Cantidad de toneladas
- Importe

Puede haber más de un registro para un mismo día y empresa. El fin del lote se indica con un código de empresa
igual a “fin”.

Dispone además de otro lote con los datos de las 100 empresas asociadas con el siguiente formato:

- Código de empresa (string(6))
- Nombre (string (30))
- Localidad (string (30))
- Provincia (1 a 24)
- Importe mensual de la cuota (float)

Se desea:
a. El monto total recaudado por cada producto. => son 15 productos(loteProceso), importe(loteProceso);
b. Para cada producto y provincia, la cantidad de toneladas exportadas.=> codigo empresa saco provincia, sacar toneladas
c. Generar un listado con las empresas que no hayan exportado nada el último mes, con el siguiente

formato:
- Código de empresa
– Localidad
- Provincia
*/

const int CANT_EMPRESAS = 4;

struct Empresa{ // son 100 => yo hago 4
  char codigo[6];
  char nombre[30];
  char localidad[30];
  int provincia; // 1 a 24
  float cuotaMensual;
};

int buscarIndex(Empresa *vEmpresas, char codigo[]); //PTOB y PTOC

void cargaEmpresa(Empresa *vEmpresas);
void loteProceso(Empresa *vEmpresas, float vProductosImporte[], int vProvinciasToneladas[], bool vEmpresasExportaron[]);

void mostrarPTOA(float vProductosImporte[]);

void cargaPTOB(Empresa *vEmpresas, int vProvinciasToneladas[], char codigo[], int toneladas);//PTOB
void mostrarPTOB(int vProvinciasToneladas[]);

void cargarPTOC(Empresa *vEmpresas, char codigo[], bool vEmpresasExportaron[]);
void mostrarPTOC(Empresa *vEmpresas, bool vEmpresasExportaron[]);

int main(){
  Empresa vEmpresas[CANT_EMPRESAS] = {
    {"abc12", "Argenchino", "Lanus", 1, 25.55},
    {"abc45", "COTO", "Banfield", 2, 10.20},
    {"abc78", "WALLMART", "Temperley", 1, 15.00},
    {"abc10", "PANADERIA", "3 FEBRERO", 3, 50.00}
  };

  float vProductosImporte[15] = {};//el indice es -1
  int vProvinciasToneladas[24] = {};//el indice lo busco con funcionIndex con el codigo empresa "abc12";
  bool vEmpresasExportaron[CANT_EMPRESAS] = {false};

  //cargaEmpresa(vEmpresas);

  loteProceso(vEmpresas, vProductosImporte, vProvinciasToneladas, vEmpresasExportaron);
  mostrarPTOA(vProductosImporte);
  mostrarPTOB(vProvinciasToneladas);
  mostrarPTOC(vEmpresas, vEmpresasExportaron);

  return 0;
}

void cargaEmpresa(Empresa *vEmpresas){
  for(int x = 0; x < CANT_EMPRESAS; x ++){
    cout << x+1 << ")Ingrese el codigo de empresa(6): ";
    cin.getline(vEmpresas[x].codigo, 6);
    cout << x+1 << ")Ingrese el nombre de la empresa: ";
    cin.getline(vEmpresas[x].nombre, 30);
    cout << x+1 << ")Ingrese la localidad: ";
    cin.getline(vEmpresas[x].localidad, 30);
    cout << x+1 << ")Ingrese la provincia (1 a 24): ";
    cin >> vEmpresas[x].provincia;
    cout << x+1 << ")Ingrese el valor de la cuota mensual: ";
    cin >> vEmpresas[x].cuotaMensual;
    cin.ignore();
  }
}

void loteProceso(Empresa *vEmpresas, float vProductosImporte[], int vProvinciasToneladas[], bool vEmpresasExportaron[]){
  char codigo[6], codPaisDestino[10];
  int diaExportacion, codProducto, cantToneladas;
  float importe;
  
  
  cout << "Ingrese el codigo EMPRESA (6)(CORTA CON 'fin'): ";
  cin.getline(codigo, 6);
  while (strcmp(codigo, "fin") != 0){
    cout << "Ingrese el dia de exportacion (1 a 31): ";
    cin >> diaExportacion;
    cout << "Codigo del producto(1 a 15): ";
    cin >> codProducto;
    cin.ignore();
    cout << "Codigo del pais destino(20): ";
    cin.getline(codPaisDestino, 10);
    cout << "Cantidad de Toneladas: ";
    cin  >> cantToneladas;
    cout << "Ingrese el importe: ";
    cin >> importe;

    vProductosImporte[codProducto-1] += importe; // PTOA
    cargaPTOB(vEmpresas, vProvinciasToneladas, codigo, cantToneladas);
    cargarPTOC(vEmpresas, codigo, vEmpresasExportaron);//PTOC





    cin.ignore();
    cout << "Ingrese el codigo EMPRESA (6)(CORTA CON 'fin'): ";
    cin.getline(codigo, 6);
  } 


}

void mostrarPTOA(float vProductosImporte[]){
  cout << "\nPTOA\n";
  for(int x = 0; x < 15; x ++){
    cout << "MONTO TOTAL RECAUDADO PARA EL PRODUCTO " << x + 1 << " $" << vProductosImporte[x] << endl;
  }
}

void cargaPTOB(Empresa *vEmpresas, int vProvinciasToneladas[], char codigo[], int toneladas){
  int index;
  index = buscarIndex(vEmpresas, codigo);
  vProvinciasToneladas[index] += toneladas;
}

int buscarIndex(Empresa *vEmpresas, char codigo[]){
  for(int x = 0; x < CANT_EMPRESAS; x ++){
    if(strcmp(vEmpresas[x].codigo, codigo) == 0){
      return x;
    }
  }
  return -1;
}

void mostrarPTOB(int vProvinciasToneladas[]){
  cout << "\nPUNTO B\n";
  for (int x = 0; x < 24; x ++){
    cout << "PROVINCIA " << x+1 << " => TONELADAS VENDIDAS: " << vProvinciasToneladas[x] << endl;
  }
}

void cargarPTOC(Empresa *vEmpresas, char codigo[], bool vEmpresasExportaron[]){
  int index;
  index = buscarIndex(vEmpresas, codigo);
  vEmpresasExportaron[index] = true;
}

void mostrarPTOC(Empresa *vEmpresas, bool vEmpresasExportaron[]){
  cout << "\nPUNTO C\n";
  cout << "***SIN EXPORTACION***\n";
  for(int x = 0; x < CANT_EMPRESAS; x ++){
    if(!vEmpresasExportaron[x]){
      cout << "EMPRESA: '" << vEmpresas[x].codigo << "' - LOCALIDAD: " << vEmpresas[x].localidad << " - PROVINCIA: " << vEmpresas[x].provincia << endl;
    }
  }
}

