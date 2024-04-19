#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

/*
9) Una librería especializada en libros de computación dispone de un lote de registros con los datos de los 1000
libros que vende con el siguiente formato:
• Código de libro (1 a 1000)
• Título (string de 40)
• Autor (string de 40)
• Precio (float)
• Unidades en stock (entero)

Posee además un lote con las ventas realizadas durante los 3 primeros meses del año en curso, con la siguiente
información:
• Código de libro (1 a 1000)
• Cantidad (entero)
• Vendedor (‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘f’, ‘g’)
• Tipo de venta (‘C’: contado, ‘T’: tarjeta)
• Dia de la venta (1 a 31)
• Mes de la venta (1 a 3)

El lote termina con un código de libro inexistente.

La librería aplica un 10% de recargo para las ventas por tarjeta de crédito.
Confeccionar un programa C que resuelva los siguientes puntos:

a. Generar un listado con los importes recaudados para cada uno de los libros durante todo el período con
el siguiente formato:
Código de libro     Título       Descripción del tema            Importe recaudado

b. Informar la cantidad vendida por mes de cada uno de los libros.
c. Informar el vendedor que más ventas realizó (en $) en cada uno de los 3 mes
*/

/*
      vendedor 1 vendedor 2   vendedor 3
mes 1   2           4             1
mes 2 
mes 3
*/

const int CANT_LIBROS = 3;

struct Libros{
  int codigo;//1 a 1000 => lo hago de 3 => ORDENADO (NO NECESITO FX INDEX)
  char titulo[40];
  char autor[40];
  float precio;
  int stock;
};


void cargaLibros(Libros *vLibros);
void loteProceso(Libros *vLibros, float *vImportes, int (*mLibrosMesCantidad)[3], float (*mMesVendedorCantidad)[7]);

void PTOA(float *vImportes, int codigoLibro, float totalPagar);
void mostrarPTOA(Libros *vLibros, float *vImportes);

void mostrarPTOB(int mLibrosMesCantidad[CANT_LIBROS][3]);

void PTOC(float (*mMesVendedorCantidad)[7], int mes, float totalPagar, char vendedor);
void mostrarPTOC(float mMesVendedorCantidad[3][7]);


int main (){
  Libros vLibros[CANT_LIBROS] = {
    {1, "Don quijote", "miguel Cervantes", 10.55, 10},
    {2, "Orgullo y Prejuicio", "Jane Austen", 23.00, 15},
    {3, "Frankestein", "Mary Shelley", 30.27, 20}
  };

  float vImportes[CANT_LIBROS] = {}; //el indice es el codigoLibro, guarda importe => uso la descripcion del STRUCT
  int mLibrosMesCantidad[CANT_LIBROS][3] = {};//PTOB
  float mMesVendedorCantidad[3][7] = {}; // PTOC

  //cargaLibros(vLibros);
  loteProceso(vLibros, vImportes, mLibrosMesCantidad, mMesVendedorCantidad);
  
  mostrarPTOA(vLibros, vImportes);
  mostrarPTOB(mLibrosMesCantidad);
  mostrarPTOC(mMesVendedorCantidad);





  return 0;
}


void cargaLibros(Libros *vLibros){
  for(int x = 0; x < CANT_LIBROS; x ++){
    cout << x+1 << ") Ingrese el codigo del libro: ";
    cin >> vLibros[x].codigo;
    cout << x+1 << ") Ingrese el titulo del libro: ";
    cin.ignore();
    cin.getline(vLibros[x].titulo, 40);
    cout << x+1 << ") Ingrese el autor: ";
    cin.getline(vLibros[x].autor, 40);
    cout << x+1 << ") Ingrese el precio: ";
    cin >> vLibros[x].precio;
    cout << x+1 << ") Ingrese el stock: ";
    cin >> vLibros[x].stock;
  }
}

void loteProceso(Libros *vLibros, float *vImportes, int (*mLibrosMesCantidad)[3], float (*mMesVendedorCantidad)[7]){
  int codLibro, cantidad, dia, mes; 
  char vendedor, tipoVenta;

  float totalPagar;

  printf("Ingrese el codigo del libro (CORTA CON <= 0 o MAYOR a %d) :", CANT_LIBROS);
  cin >> codLibro;
  while(codLibro > 0 && codLibro <= CANT_LIBROS){
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    cout << "Ingrese el vendedor(a, b, c, d, f, g): ";
    cin >> vendedor;
    cout << "Ingrese el tipo de veta (c-contado, t-tarjeta)(10% mas con tarjeta): ";
    cin >> tipoVenta;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes(1 al 3): ";
    cin >> mes;

    totalPagar = (tipoVenta == 't') ? (vLibros[codLibro-1].precio * cantidad) * 1.10 : vLibros[codLibro-1].precio * cantidad;

    PTOA(vImportes, codLibro, totalPagar);//PTOA
    mLibrosMesCantidad[codLibro-1][mes-1] += cantidad;//PTOB
    PTOC(mMesVendedorCantidad, mes, totalPagar, vendedor); //PTOC



    printf("Ingrese el codigo del libro (CORTA CON <= 0 o MAYOR a %d) :", CANT_LIBROS);
    cin >> codLibro;

  }
}

void PTOA(float *vImportes, int codigoLibro, float totalPagar){
  vImportes[codigoLibro-1] += totalPagar;
}

void mostrarPTOA(Libros *vLibros, float *vImportes){
  cout << "\nPTOA\n";
  cout << "CODIGO DE LIBRO\t TITULO(DESCRIPCION)\t IMPORTE\n"; 
  for(int x = 0; x < CANT_LIBROS; x ++){
    int anchoTitulo = strlen(vLibros[x].titulo);
    cout << setw(8) << vLibros[x].codigo << setw(10+anchoTitulo) << vLibros[x].titulo << setw(30 - anchoTitulo) << vImportes[x] << endl;
  }
}

void mostrarPTOB(int mLibrosMesCantidad[CANT_LIBROS][3]){
  cout << endl << setw(40) << "PTOB" << endl;
  cout << "| CODIGO LIBRO |" <<  " CANT VENDIDA MES 1 |" << " CANT VENDIDA MES 2 |" << " CANT VENDIDA MES 3 |" << endl;
  for(int i = 0; i < CANT_LIBROS; i ++){
    cout << "|" << setw(10) << "Libro " << i +1 << setw(4) << "|";
    for(int j = 0; j < 3; j ++){
      cout << setw(10) << mLibrosMesCantidad[i][j] << setw(11) << "|";  
    }
    cout << endl;
  }
}

void PTOC(float (*mMesVendedorCantidad)[7], int mes, float totalPagar, char vendedor){
  // a = 97. b = 98. g = 103 => vendedor - a => 98 - 97
  int index = vendedor - 'a';
  mMesVendedorCantidad[mes-1][index] += totalPagar; 
}

void mostrarPTOC(float mMesVendedorCantidad[3][7]){
  int maxVendedor;
  float maxCantidad;

  cout << "\nPTOC\n";
  for(int i = 0; i < 3; i ++){
    maxCantidad = -1;
    for(int j = 0; j < 7; j ++){
      if(mMesVendedorCantidad[i][j] > maxCantidad){
        maxCantidad = mMesVendedorCantidad[i][j];
        maxVendedor = j; // no se suma numero
      }
    }
    char maxVendedorChar = 'a' + maxVendedor;
    cout << "MES " << i + 1 << " => MAXIMO VENDEDOR '" << maxVendedorChar << "' => CANTIDAD VENDIDAS: " << maxCantidad << endl;
  }
}

