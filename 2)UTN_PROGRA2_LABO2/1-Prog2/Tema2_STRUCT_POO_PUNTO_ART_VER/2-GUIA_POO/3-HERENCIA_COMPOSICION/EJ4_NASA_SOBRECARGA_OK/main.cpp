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
  Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

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
4) La NASA guarda los siguientes datos de las misiones espaciales que realiza: 
Número de misión, nombre de la misión, nombre del astronauta  a cargo, 
fecha de inicio, fecha de fin, presupuesto disponible. 
A partir de los señalado desarrollar los siguientes puntos.
a)	Diseñar la clase correspondiente, con:
* sets() y gets() para todas las propiedades
* Un constructor que asigne la palabra “nada” como valor por omisión
 para las propiedades de tipo cadena

*/

class Mision{
private:
  int _numMision;
  char _nomMision[20];
  char _nombreAstronauta[20];
  Fecha _fechIni;
  Fecha _fechFin;
  int _presupuesto;

public:

Mision (int numMis, const char* nomMis, const char* nombreAstr, Fecha fechaIni, Fecha fechaFin, int presupu)
: _numMision(numMis), _fechIni(fechaIni), _fechFin(fechaFin), _presupuesto(presupu)
{strcpy (_nomMision, nomMis); strcpy (_nombreAstronauta, nombreAstr);}

Mision(Fecha fechaIni, Fecha fechaFin, int presupu)
 : Mision(0, "nada", "nada", fechaIni, fechaFin, presupu){}


  void setNumMision(int n){_numMision=n;}
  void setNomMision(const char* n){strcpy(_nomMision,n);}
  void setNomAstronauta(const char* n){strcpy(_nombreAstronauta,n);}
  void setFechIni(Fecha fechaIni){_fechIni=fechaIni;}
  void setFechFin(Fecha fechaFin){_fechFin=fechaFin;}
  void setPresupuesto(int p){_presupuesto=p;}

  int getNumMision(){return _numMision;}
  const char* getNomMision(){return _nomMision;}
  const char* getNomAstronauta(){return _nombreAstronauta;}
  Fecha getFechIni(){return _fechIni;}
  Fecha getFechFin(){return _fechFin;}
  int getPresupuesto(){return _presupuesto;}

  void cargar(){
    cout << "Numero de Mision: ";cin >> _numMision;
    cout << "Nombre de la Mision: "; cargarCadena(_nomMision,20);
    cout << "Nombre del astronauta: "; cargarCadena(_nombreAstronauta,20);
    cout << "Fecha de Inicio: \n";_fechIni.Cargar();
    cout << "Fecha de Fin: \n";_fechFin.Cargar();
    cout << "Presupuesto disponible: "; cin >> _presupuesto;
  }


  void mostrar(){
    cout << "Numero de Mision: " << _numMision << endl;
    cout << "Nombre de la Mision: " << _nomMision << endl;
    cout << "Nombre del astronauta: " << _nombreAstronauta << endl;
    cout << "Fecha de Inicio: ";_fechIni.Mostrar();
    cout << "Fecha de Fin: ";_fechFin.Mostrar();
    cout << "Presupuesto disponible: " << _presupuesto << endl;
  }

};

int main() {
  Fecha fechaInicio(1, 2, 3);
  Fecha fechaFin(4, 5, 6);
  Mision objM(fechaInicio, fechaFin, 1000000); 

  objM.mostrar();
  

  return 0;
}