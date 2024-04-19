#pragma once

class Proveedor:public Persona{
private:
  int _cuil;
  int _tipoProducto;//1 a 10
  char _condicionPago;//a-b-c

public:
  Proveedor(int dni = 0, const char *nom = "S/N", const char *ape = "S/A", Fecha f = Fecha(), const char *dir = "S/D", int codPos = 0, int cuil = -1, int tipoProd = -1, char condPag = 'z');

///SET
void setCuil(int cuil);
void setTipoProducto(int tipoProd);
void setCondicionPago(char condPago);

///GET
int getCuil();
int getTipoProducto();
char getCodicionPago();

///CARGAR-LISTAR
void cargar();
void mostrar();

};

Proveedor::Proveedor(int dni, const char *nom, const char *ape, Fecha f, const char *dir, int codPos, int cuil, int tipoProd, char condPag) : Persona(dni, nom, ape, f, dir, codPos), _cuil(cuil), _tipoProducto(tipoProd), _condicionPago(condPag) {}

///SET
void Proveedor::setCuil(int cuil){_cuil = cuil;}
void Proveedor::setTipoProducto(int tipoProd){_tipoProducto = (tipoProd >= 1 && tipoProd <= 10) ? tipoProd : -1;}
void Proveedor::setCondicionPago(char condPago){_condicionPago = (condPago == 'a' || condPago == 'b' || condPago == 'c') ? condPago : 'x';}

///GET
int Proveedor::getCuil(){return _cuil;}
int Proveedor::getTipoProducto(){return _tipoProducto;}
char Proveedor::getCodicionPago(){return _condicionPago;}

///CARGAR-LISTAR
void Proveedor::cargar(){
  int tipoProd;
  char condPago;
  Persona::cargar();
  cout << "CUIL: ";
  cin >> _cuil;
  cout << "TIPO PRODUCTO(1 a 10): ";
  cin >> tipoProd;
  setTipoProducto(tipoProd);
  cout << "CONDICION PAGO(a, b, c): ";
  cin >> condPago;
  setCondicionPago(condPago);
}

void Proveedor::mostrar(){
  Persona::mostrar();
  cout << "CUIL: " << _cuil << endl;
  cout << "TIPO PRODUCTO: " << _tipoProducto << endl;
  cout << "CONDICION PAGO: " << _condicionPago << endl;
}
