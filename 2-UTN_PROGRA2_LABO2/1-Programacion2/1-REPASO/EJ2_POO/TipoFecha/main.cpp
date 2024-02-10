#include <iostream>

using namespace std;

class Fecha{
private:
  int dia, mes, anio;
public:

  Fecha(int d = 0, int m = 0, int a = 0){
    dia = d;
    mes = m;
    anio = a;
  }

  void cargar();
  void mostrar(){
    cout << "DIA: " << dia << endl;
    cout << "MES: " << mes << endl;
    cout << "ANIO: " << anio << endl;
  }

  void setDia(int d){
    if (d >= 1 && d <= 31){
      dia = d;
    }else{
      dia = -1;
    }
  }

  int getDia(){return dia;}

  void setMes(int m){
    if(m >= 1 && m <= 12){
      mes = m;
    }else{
      mes = -1;
    }
  }
  int getMes(){return mes;}

  void setAnio(int an){
    if(an > 1900){
      anio = an;
    }else{
      anio = -1;
    }
  }

  int getAnio(){return anio;}

  void mostrarDireccion(){
    cout << this << endl;
  }




};

void Fecha::cargar(){
  int d, m, a;
  cout << "DIA: ";
  cin >> d;
  setDia(d);
  cout << "MES: ";
  cin >> m;
  setMes(m);
  cout << "ANIO: ";
  cin >> a;
  setAnio(a);
 }

 void cargarFechas(Fecha *v, int tam){
  for(int i = 0; i < tam; i ++){
    v[i].cargar();
  }
 }

void mostrarFechas(Fecha *v, int tam){
  for(int i = 0; i < tam; i ++){
    v[i].mostrar();
  }
 }


class Alumno{
private:
public:
 };


int main()
{
  Fecha hoy(12, 19, 2023), ayer, otro (12), vDias[5];

  //cargarFechas(vDias, 3);
  //mostrarFechas(vDias, 3);
 /* cout << "HOY: " << endl;
  hoy.mostrar();
  cout << "AYER: " << endl;
  ayer.mostrar();
  cout << "OTRO: " << endl;
  otro.mostrar();*/

  vDias -> mostrar();
  cout << &hoy << endl;
  hoy.mostrarDireccion();


  return 0;
}

