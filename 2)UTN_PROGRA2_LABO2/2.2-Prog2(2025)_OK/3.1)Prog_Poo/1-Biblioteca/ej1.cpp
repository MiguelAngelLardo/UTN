#include <iostream>

using namespace std;

/*
a cada socio se le asigna un numero unico q lo identifica como socio

Enunciado base para determinar objetos/clases
Una biblioteca lleva el registro de los 
socios, los libros que tiene y los préstamos de libros que realiza a los socios.

Por cada uno de los socios registra el DNI, el nombre, el apellido,
un número de teléfono, un email y la fecha de nacimiento. 
número único que lo identifica como socio.

Para cada libro se registra el número ISBN, el nombre del libro, el nombre del autor, la fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca. 
El número ISBN (International Standard Book Number) es un código numérico que identifica de forma única a cada libro publicado.

En cuanto a cada uno de los préstamos, a la Biblioteca le interesa saber cuál es el libro que se prestó, a qué socio se lo prestó, cuál fue el día del préstamo y cuál fue la fecha de devolución.

A partir de la descripción se pide:
●	Definir cuáles son los objetos que se necesitan para registrar la información de la biblioteca.
●	Para cada uno de los objetos, definir cuáles son las propiedades necesarias.
●	Definir el tipo de dato que corresponda para representar cada propiedad.

*/

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

class Socio{
private:
  int _dni;
  char _nombre[20];
  char _apellido[20];
  char _telefono[10];
  char _email[10];
  Fecha _fechaNacimiento;
  int _numeroUnicoSocio;
};

class Libro{
  int _ISBN;
  char _nombreLibro[20];
  char _nombreAutor[20];
  Fecha _fechaPublicacion;
  int _cantEjemplares;
};

class Prestamo {
private:
  Libro _libroPrestado;       
  Socio _socioPrestamo;     
  Fecha _fechaPrestamo;       
  Fecha _fechaDevolucion;    
}; 

class Biblioteca{
private:
  Socio _socio;
  Prestamo _prestamo;
  Libro _libro;
 
};

int main(){

  return 0;
}