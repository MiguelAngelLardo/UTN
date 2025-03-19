#pragma once
#include "Alumno.h"
#include "Fecha.h"
#include "Materia.h"

class Examen{
private:
  Fecha _fechaExamen;
  Alumno _alumnoExamen;
  int _nota;


public:
  Examen(int n=-1, Fecha f = Fecha(), Alumno alum = Alumno());//Fecha f = Fecha(11, 11, 2011);

  void setFechaExamen(Fecha f){ _fechaExamen = f;};
  void setDiaExamen(int d){_fechaExamen.setDia(d);}
  void setMesExamen(int m){_fechaExamen.setMes(m);}
  void setAnioExamen(int a){_fechaExamen.setAnio(a);}
  
  Fecha getFechaExamen(){return _fechaExamen;}
  int getDiaExamen(){return _fechaExamen.getDia();}
  int getMesExamen(){return _fechaExamen.getMes();}
  int getAnioExamen(){return _fechaExamen.getAnio();}

  void setAlumnoExamen(Alumno a){_alumnoExamen = a;}
  void setLegajoAlumno(int a){_alumnoExamen.setLegajo(a);}
  void setNombreAlumno(const char *n){_alumnoExamen.setNombre(n);}
  void setApellidoAlumno(const char *a){_alumnoExamen.setApellido(a);}

  Alumno getAlumnoExamen(){return _alumnoExamen;}
  int getLegajoAlumno(){return _alumnoExamen.getLegajo();}
  const char *getNombreAlumno(){return _alumnoExamen.getNombre();}
  const char *getApellidoAlumno(){return _alumnoExamen.getApellido();}
  

  void setNota(int nota){_nota = nota;}
  int getNota(){return _nota;}

  void cargar();
  void mostrar();

};

Examen::Examen(int n, Fecha f, Alumno alum){
  _nota = n;
  _fechaExamen = f;
  _alumnoExamen = alum;
}


void Examen::cargar(){
  cout << "FECHA EXAMEN: " << endl;
  _fechaExamen.cargar();
  
  cout << "ALUMNO EXAMEN: " << endl;
  _alumnoExamen.cargar();
  
  cout << "NOTA: ";
  cin >> _nota;
}

void Examen::mostrar(){
  cout << "\nPROPIO DE LA FECHA\n";
  _fechaExamen.mostrar();

  cout << "\nPROPIO ALUMNO\n";
  _alumnoExamen.mostrar();
  cout << endl;

  cout << "\nPROPIO EXAMEN\n";
  cout << "NOTA: " << _nota << endl;  
}


