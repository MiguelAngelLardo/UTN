#include <iostream>
#include <iomanip> // Para formatear la salida

using namespace std;

/*
7) Una empresa que comercializa un total de 200 artículos, dispone de un lote de registros, ordenados
secuencialmente por nro. de artículo, donde cada registro contiene:
- Nro. de Artículo (8 cifras y no correlativo)
- Unidades en Stock (entero)
- Precio Unitario (real)

Se dispone de un segundo lote con las ventas realizadas en el año, con la siguiente información por registro:
- Nro. de Artículo (8 cifras)
- Nro. de Cliente (1 a 300)
- Mes de Venta (1 a 12)
- Cantidad de Unidades Vendidas (entero)

Estos registros están totalmente desordenados y puede haber más de un registro para el mismo artículo, cliente
y mes. El último registro se indica con nro. de artículo igual a cero.
Se pide determinar e informar:

a) Un listado con los importes adquiridos por los clientes que compraron durante el año en 8 o más meses,
ordenado por nro. de cliente con el siguiente formato:

Cliente   Ene   Feb     Mar    Abr     May .....
xxx      xxx    xxx    xxx     xxx     xxx......


b) Un listado, ordenado por nro. de artículo, con aquellos artículos que han quedado con stock cero luego de
procesar todas las ventas. Para calcular el nuevo stock se debe tomar el stock inicial e ir descontando según se
vayan ingresando las ventas.
*/

const int TAM_ARTICULOS = 5;
struct Articulo { //son 200 art;
  int numArticulo; //8 cifras
  int unidadesStock;
  float precio;
};

int buscarIndice(int cod, Articulo *vec);

void ordenarPorNumArt(Articulo *art);

void cargaArticulos(Articulo *art);
void proceso(Articulo *art, float (*mNumeroClienteMesImporteDeCompra)[12]);

void fxPTOA(Articulo *art, float (*mNumeroClienteMesImporteDeCompra)[12], int numArticulo,  int nroCliente, int mes, int cantidadVendida);
void mostrarPTOA(float (*mNumeroClienteMesImporteDeCompra)[12]);

void fxPTOB(Articulo *art, int nroArt, int cantVendida);
void mostrarPTOB(Articulo *art);

int main (){
 Articulo vArt[TAM_ARTICULOS];

 float mNumeroClienteMesImporteDeCompra[5][12] = {}; // [300][12]
 
 
 cargaArticulos(vArt); //cargo la BASE DE DATOS
 proceso(vArt, mNumeroClienteMesImporteDeCompra);

 mostrarPTOA(mNumeroClienteMesImporteDeCompra);
 mostrarPTOB(vArt);


  return 0;
}

int buscarIndice(int cod, Articulo *vec){
  for(int x = 0; x < TAM_ARTICULOS; x ++) if (cod == vec[x].numArticulo) return x;
}

void ordenarPorNumArt(Articulo *art){
  for(int x = 0; x < TAM_ARTICULOS; x ++){
    for(int y = 0; y < TAM_ARTICULOS -1; y ++)
    if(art[y].numArticulo < art[y+1].numArticulo){
      Articulo aux = art[y+1];
      art[y+1] = art[y];
      art[y] = aux;
    }
  }
}



void cargaArticulos(Articulo *art){
  for(int x = 0; x < TAM_ARTICULOS; x ++){
    cout << x+1 << ")Ingrese el numero de ARTICULO (8 digitos no correlativos): ";
    cin >> art[x].numArticulo;
    cout << x+1 << ")Ingrese el STOCK: ";
    cin >> art[x].unidadesStock;
    cout << x+1 << ")Ingrese el PRECIO: ";
    cin >> art[x].precio;
  }
}

void proceso(Articulo *art, float (*mNumeroClienteMesImporteDeCompra)[12]){
  int nroArt, nroCliente, mesVenta, cantidadVendida;
  
  cout << "\nVENTAS=> nroArt, nroCLIENTE, MES, CANTIDAD QUE DESEA\n";
  cout << "Ingrese el numero de articulo(8 digitos)(CORTA CON CERO): ";
  cin >> nroArt;
  while (nroArt != 0){
    cout << "Ingrese el numero de CLIENTE(1 a 300): ";
    cin >> nroCliente;
    cout << "Ingrese el MES: ";
    cin >> mesVenta;
    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidadVendida;

    fxPTOA(art, mNumeroClienteMesImporteDeCompra, nroArt,  nroCliente, mesVenta, cantidadVendida);
    fxPTOB(art, nroArt, cantidadVendida);

    cout << "Ingrese el numero de articulo(8 digitos)(CORTA CON CERO): ";
    cin >> nroArt;
  }
  


}

void fxPTOA(Articulo *art, float (*mNumeroClienteMesImporteDeCompra)[12], int numArticulo, int nroCliente, int mes, int cantidadVendida){
  int indice = buscarIndice(numArticulo, art);
  mNumeroClienteMesImporteDeCompra[nroCliente-1][mes-1] += cantidadVendida*art[indice].precio;
}

void mostrarPTOA(float (*mNumeroClienteMesImporteDeCompra)[12]){
  int contMeses;

  cout << "\nPUNTO A\n";
  cout << setw(1) << "Cliente";
  for (int mes = 1; mes <= 12; mes ++) {
    cout << setw(8) << "Me " << mes;
  }
  cout << endl;
  
  for(int cliente = 0; cliente < 5; cliente ++){
    contMeses = 0;
    for(int mes = 0; mes < 12; mes ++){
      (mNumeroClienteMesImporteDeCompra[cliente][mes] > 0) ? contMeses ++ : contMeses = contMeses + 0;

      if(contMeses >=8){
        cout << setw(7) << cliente + 1;
        for(int mes = 0; mes < 12; mes ++){
          if(mNumeroClienteMesImporteDeCompra[cliente][mes] < 100){}
          cout << setw(9.2) << fixed << setprecision(1) << mNumeroClienteMesImporteDeCompra[cliente][mes];
        }
        cout << endl;
        contMeses = 0;
      }
    }
  }
}

void fxPTOB(Articulo *art, int nroArt, int cantVendida){
  int indice = buscarIndice(nroArt, art);

  art[indice].unidadesStock -= cantVendida;
}

void mostrarPTOB(Articulo *art){
  ordenarPorNumArt(art);
  cout << "\nPTO B\n";
  for(int x = 0; x < TAM_ARTICULOS; x ++){
    if(art[x].unidadesStock == 0){
      cout << "NUMERO ARTICULO -> " << art[x].numArticulo << endl;
      cout << "UNIDADES STOCK -> " << art[x].unidadesStock << endl;
      cout << "PRECIO -> " << art[x].precio << endl << endl; 
    }
  }  
}

