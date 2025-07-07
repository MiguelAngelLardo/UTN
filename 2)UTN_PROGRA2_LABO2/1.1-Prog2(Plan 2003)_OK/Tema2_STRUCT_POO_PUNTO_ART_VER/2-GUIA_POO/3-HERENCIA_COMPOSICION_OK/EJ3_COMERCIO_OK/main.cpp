#include <iostream>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

/*
3) Un comercio guarda los siguientes datos de cada una de las compras que realiza:
Número de compra, fecha, nombre del producto comprado, tipo de producto (entero entre 1 y 15), 
forma de pago acordada (1 a 5) , cantidad e importe total.
A partir de los señalado desarrollar los siguientes puntos.
a)	Diseñar la clase correspondiente, con:
* sets() y gets() para todas las propiedades
* Un constructor con 0 como valor por omisión para las propiedades de tipo numérico.
*/

class Compra {
private:
  int _numCompra;
  Fecha _fechaCompra;
  char _nombreProducto[20];
  int _tipo;
  int _formaPago;
  int _cantidad;
  float _importe;

public:
  Compra (int numC, Fecha fechaC, const char *nombreP, int tipo, int formaP, int cant, float imp)
  : _numCompra(numC), _fechaCompra(fechaC), _nombreProducto(), _tipo(tipo), _formaPago(formaP), _cantidad(cant), _importe(imp)
  {strcpy(_nombreProducto, nombreP);}

  void setNumCompra(int numC){_numCompra=numC;}
  void setFechaCompra(Fecha fechaC){_fechaCompra=fechaC;}
  void setNombreProducto(const char *nombreP){strcpy(_nombreProducto, nombreP);}
  void setTipo(int tipo){_tipo=tipo;}
  void setFormaPago(int formaP){_formaPago=formaP;}
  void setCantidad(int cant){_cantidad=cant;}
  void setImporte(float imp){_importe=imp;}

  int getNumCompra(){return _numCompra;}
  Fecha getFechaCompra(){return _fechaCompra;}
  const char *getNombreProducto(){return _nombreProducto;}
  int getTipo(){return _tipo;}
  int getFormaPago(){return _formaPago;}
  int getCantidad(){return _cantidad;}
  float getImporte(){return _importe;}

  void cargar(){
    cout << "NUMERO DE COMPRA: ";cin >> _numCompra;
    cout << "FECHA DE COMPRA: \n";_fechaCompra.Cargar();
    cout << "NOMBRE del producto: ";cargarCadena(_nombreProducto, 20);
    cout << "TIPO: ";cin >> _tipo;
    cout << "FORMA DE PAGO: ";cin >> _formaPago;
    cout << "CANTIDAD: ";cin >> _cantidad;
    cout << "IMPORTE: ";cin >> _importe;
  }

  void mostrar(){
    cout << "NUMERO DE COMPRA: " << _numCompra << endl;
    cout << "FECHA DE COMPRA: ";_fechaCompra.Mostrar();
    cout << "NOMBRE del producto: " << _nombreProducto << endl;
    cout << "TIPO: " << _tipo << endl;
    cout << "FORMA DE PAGO: " << _formaPago << endl;
    cout << "CANTIDAD: " << _cantidad << endl;
    cout << "IMPORTE: " << _importe << endl;
  }
};




int main () {

  return 0;
}