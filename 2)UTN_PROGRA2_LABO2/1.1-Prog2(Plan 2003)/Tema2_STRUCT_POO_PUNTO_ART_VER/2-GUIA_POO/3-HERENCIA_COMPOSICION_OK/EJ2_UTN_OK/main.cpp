#include <iostream>
#include <cstring>

using namespace std;

/*
2) El área de investigación de la UTN tiene registrados a sus investigadores con los siguientes datos:
DNI, nombre, apellido, fecha de nacimiento, unidad académica a la que pertenece (entero entre 1 y 30), categoría (1 a 5) y especialidad(1 a 10).
A partir de los señalado desarrollar los siguientes puntos.
a)	Diseñar la clase correspondiente, con:
* sets() y gets() para todas las propiedades
* Un constructor con valores por omisión para los parámetros (o alguno de ellos)
*/

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

class Investigador {
private:
 int _dni;
 char _nombre[20];
 char _apellido[20];
 Fecha _fechaNacimiento;
 int _unidadAcademica;
 int _categoria;
 int _especialidad;

public:
  Investigador(int dni = 0, const char* nombre = "", const char* apellido = "", Fecha fechaNac = Fecha(), int ua = 0, int c = 0, int e = 0)
  : _dni(dni), _fechaNacimiento(fechaNac), _unidadAcademica(ua), _categoria(c), _especialidad(e){
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
  }

  void setDni(int d){_dni=d;}
  void setNombre(const char* n){strcpy(_nombre,n);}
  void setApellido(const char* a){strcpy(_apellido,a);}
  void setFechanacimiento(Fecha fechanacimiento){_fechaNacimiento=fechanacimiento;}
  void setUnidadAcademica(int ua){_unidadAcademica=ua;}
  void setCategoria(int c){_categoria=c;}
  void setEspecialidad(int e){_especialidad=e;}

  int getDni(){return _dni;}
  const char* getNombre(){return _nombre;}
  const char* getApellido(){return _apellido;}
  Fecha getFechaNacimiento(){return _fechaNacimiento;}
  int getUnidadAcademica(){return _unidadAcademica;}
  int getCategoria(){return _categoria;}
  int getEspecialidad(){return _especialidad;}




};

int main () {
  


  return 0;
}

