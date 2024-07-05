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
//para composicion
class Fecha{
private:
    int dia,mes, anio;
public:
  Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

    void Cargar(){
        cout << "Dia: "; cin>>dia;
        cout << "Mes: "; cin>>mes;
        cout << "Anio: "; cin>>anio;
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

//para composicion
class Direccion{
private:
  char _calle[20];
  int _numero;
  int _cp;
  char _localidad[20];
  int _piso;
public:

  Direccion(const char *calle = "", int numero = 0, int cp = 0000, const char *localidad = "", int piso = 0) 
  : _numero(numero), _cp(cp), _piso(piso) 
  {strcpy(_calle, calle);strcpy(_localidad, localidad);}

  void getCalle(const char *calle){strcpy(_calle, calle);}
  void getNumero(int numero){_numero=numero;}
  void getCp(int cp){_cp=cp;}
  void getLocalidad(const char *localidad){strcpy(_localidad, localidad);}
  void getPiso(int piso){_piso=piso;}

  const char *getCalle(){return _calle;}
  int getNumero(){return _numero;}
  int getCp(){return _cp;}
  const char *getLocalidad(){return _localidad;}
  int getPiso(){return _piso;}

  void cargar(){
    cout << "Calle: ";cargarCadena(_calle, 20);
    cout << "Numero: ";cin>>_numero;
    cout << "Cp: ";cin>>_cp;
    cout << "Localidad: ";cargarCadena(_localidad, 20);
    cout << "Piso: ";cin>>_piso;
  }

  void mostrar(){
    cout << "Calle: " << _calle << endl;
    cout << "Numero: " << _numero << endl;
    cout << "Cp: " << _cp << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << "Piso: " << _piso << endl;
  }
};


/*
5)Una inmobiliaria opera con distintos tipos de inmuebles. Para todos ellos registra los siguientes datos:
 
Dirección (calle, número, código postal, localidad, piso, etc.)
Fecha de ingreso
Fecha de operación
Superficie total
Tipo de operación (1: venta; 2: alquiler)
 
Para las casas registra además la cantidad de ambientes, y la superficie construída; 
para los departamentos registra la cantidad de ambientes, y si dispone o no de instalaciones complementarias (pileta, quincho, etc); 
para los locales comerciales indica la zona (1: comercial; 2 mixta; 3 industrial), 
para los terrenos registra si posee o no mejoras (‘A’: sin mejoras; ‘B’: asfalto; ‘C’: todos los servicios)
 
Diseñar las clases que se consideren convenientes. Utilizar si corresponde herencia, composición o ambas.
*/

class Inmobiliaria{ // clase base => usa composicion de Direccion y Fecha
protected: 
  Direccion _direccion;
  Fecha _fechaIngreso;
  Fecha _fechaOperacion;
  int _superficieTotal;
  int _tipoOperacion;//1 venta 2 alquiler

public:
  Inmobiliaria(Direccion dire = Direccion(), Fecha fIngreso = Fecha(), Fecha fOperacion = Fecha(), int superficieTotal = 0, int tipoOperacion = 0)
  : _direccion(dire), _fechaIngreso(fIngreso), _fechaOperacion(fOperacion), _superficieTotal(superficieTotal), _tipoOperacion(tipoOperacion) {}

  void setDireccion(Direccion dire){_direccion=dire;}//espera un objeto direccion
  void setDireccion(const char* calle, int numero, int cp, const char* localidad, int piso) { //para q reciba parametros indivioduales
    _direccion = Direccion(calle, numero, cp, localidad, piso);
  }
  void setFechaIngreso(Fecha fIngreso){_fechaIngreso=fIngreso;}
  void setFechaIngreso(int dia, int mes, int anio){
    _fechaIngreso = Fecha(dia, mes, anio);
  }
  void setFechaOperacion(Fecha fOperacion){_fechaOperacion=fOperacion;}
  void setFechaOperacion(int dia, int mes, int anio){
    _fechaOperacion = Fecha(dia, mes, anio);
  }
  void setSuperficieTotal(int superficieTotal){_superficieTotal=superficieTotal;}
  void setTipoOperacion(int tipoOperacion){_tipoOperacion=tipoOperacion;}

  Direccion getDireccion(){return _direccion;}
  Fecha getFechaIngreso(){return _fechaIngreso;}
  Fecha getFechaOperacion(){return _fechaOperacion;}
  int getSuperficieTotal(){return _superficieTotal;}
  int getTipoOperacion(){return _tipoOperacion;}

  void cargar(){
    cout << "DIRECCION: \n"; _direccion.cargar();
    cout << "FECHA DE INGRESO: \n"; _fechaIngreso.Cargar();
    cout << "FECHA DE OPERACION: \n"; _fechaOperacion.Cargar();
    cout << "SUPERFICIE TOTAL: "; cin>>_superficieTotal;
    cout << "TIPO DE OPERACION: "; cin>>_tipoOperacion;
  }

  void mostrar(){
    cout << "**DIRECCION**\n"; _direccion.mostrar();
    cout << "FECHA DE INGRESO: "; _fechaIngreso.Mostrar();
    cout << "FECHA DE OPERACION:"; _fechaOperacion.Mostrar();
    cout << "SUPERFICIE TOTAL: " << _superficieTotal << endl;
    cout << "TIPO DE OPERACION: " << _tipoOperacion << endl;
  }
};

class Casa : public Inmobiliaria{
private:
  int _cantAmbientes;
  int _superficieConstruida;
public:
  Casa(int canAmb = 0, int supCon = 0) : _cantAmbientes(canAmb), _superficieConstruida(supCon) {}

  void setCantAmbientes(int canAmb){_cantAmbientes=canAmb;}
  void setSuperficieConstruida(int supCon){_superficieConstruida=supCon;}

  int getCantAmbientes(){return _cantAmbientes;}
  int getSuperficieConstruida(){return _superficieConstruida;}

  void cargar(){
    Inmobiliaria::cargar();
    cout << "CANT. AMBIENTES: "; cin>>_cantAmbientes;
    cout << "SUPERFICIE CONSTRUIDA: "; cin>>_superficieConstruida;
  }

  void mostrar(){
    Inmobiliaria::mostrar();
    cout << "CANT. AMBIENTES: " << _cantAmbientes << endl;
    cout << "SUPERFICIE CONSTRUIDA: " << _superficieConstruida << endl;
  }  

}; 

class Departamento : public Inmobiliaria{
  
private: 
  int _cantAmbientes;
  char _instalacionComplementaria[20];

public:
  Departamento(int canAmb = 0, const char* instCom = "") : _cantAmbientes(canAmb) {strcpy(_instalacionComplementaria, instCom);}
  void setCantAmbientes(int canAmb){_cantAmbientes=canAmb;}
  void setInstalacionComplementaria(const char* instCom){strcpy(_instalacionComplementaria, instCom);}

  int getCantAmbientes(){return _cantAmbientes;}
  const char* getInstalacionComplementaria(){return _instalacionComplementaria;}

  void cargar(){
    Inmobiliaria::cargar();
    cout << "CANT. AMBIENTES: "; cin>>_cantAmbientes;
    cout << "INSTALACION COMPLEMENTARIA: "; cargarCadena(_instalacionComplementaria, 20);
  }

  void mostrar(){
    Inmobiliaria::mostrar();
    cout << "CANT. AMBIENTES: " << _cantAmbientes << endl;
    cout << "INSTALACION COMPLEMENTARIA: " << _instalacionComplementaria << endl;
  }
};


class Local : public Inmobiliaria{
private:
  int _zona;

public:
  Local (int zona = 0) : _zona(zona) {}

  void setZona(int zona){_zona=zona;}
  int getZona(){return _zona;}

  void cargar(){
    Inmobiliaria::cargar();
    cout << "ZONA: "; cin>>_zona;
  }

  void mostrar(){
    Inmobiliaria::mostrar();
    cout << "ZONA: " << _zona << endl;
  }

};


class Terreno : public Inmobiliaria{

private:
  char _mejoras;

public:
  Terreno (char mej = 'x') : _mejoras(mej) {}

  void setMejoras(char mej){_mejoras=mej;}
  char getMejoras(){return _mejoras;}

  void cargar(){
    Inmobiliaria::cargar();
    cout << "MEJORAS: "; cin>>_mejoras;
  }

  void mostrar(){
    Inmobiliaria::mostrar();
    cout << "MEJORAS: " << _mejoras << endl;
  }

};

int main() {


  return 0;
}