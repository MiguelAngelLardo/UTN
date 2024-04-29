#include <iostream>
#include "fecha.h"
#include "investigadores.h"
#include "funciones.h"

using namespace std;

int main(){
Investigador vInvest[3];

int opcion;
do
{
  cout << "\nMENU\n";
  cout << "1. Cargar Investigadores\n";
  cout << "2. Mostrar Investigadores\n";
  cout << "3. Salir\n";
  cout << "Ingrese la opcion: ",
  cin >> opcion;
  cin.ignore();  // Limpia el buffer


  switch (opcion)
  {
  case 1:
    cout << "Ingrese a los investigadores: " << endl;
    for (int x = 0; x < 3; x ++) // el cero es el uno
    {
      char nombre[30];
      cout << x+1 << ") NOMBRE: ";
      cargarCadena(nombre, 29);
      vInvest[x].setNombre(nombre);

      string apellido;
      cout << x+1 << ") APELLIDO: ";
      getline(cin, apellido);
      vInvest[x].setApellido(apellido);

      int dia, mes, anio;
      cout << x+1 << ") INGRESE LA FECHA: " << endl;
      cout << "DIA: ";
      cin >> dia;
      cout << "MES: ";
      cin >> mes;
      cout << "ANIO: ";
      cin >> anio;
      vInvest[x].setFechaNacimiento(Fecha(dia, mes, anio));     
      cin.ignore();  // Limpia el buffer

      int unidadAcademica;
      cout << x+1 << ") Ingrese la unidad academica (1 al 30): ";
      cin >> unidadAcademica;
      vInvest[x].setUnidadAcademica(unidadAcademica);
      cin.ignore();  // Limpia el buffer

      int categoria;
      cout << x+1 << ") Ingrese la Categoria (1 al 5): ";
      cin >> categoria;
      vInvest[x].setCategoria(categoria);
      cin.ignore();  // Limpia el buffer

      int especialidad;
      cout << x+1 << ") Ingrese la Especialidad (1 al 10): ";
      vInvest[x].setCategoria(especialidad);
      cin.ignore();  // Limpia el buffer

      int dni;
      cout << x+1 << ") Ingrese el DNI: ";
      cin >> dni;
      vInvest[x].setDNI(dni);
      cin.ignore();  // Limpia el buffer
    }
    break;

  case 2:
    for(int x = 0; x < 3; x ++)
    {
      cout << endl << "*****MOSTRANDO INVESTIGADORES: " << x + 1  << "*****" << endl;
      cout << "NOMBRE: ";
      cout << vInvest[x].getNombre() << endl;
      cout << "APELLIDO: ";
      cout << vInvest[x].getApellido() << endl;
      cout << "FECHA: ";
      cout << vInvest[x].getFechaNacimiento().toString() << endl; //getFechaNac devuelve objeto tipo FECHA, por eso accedo al metodo toString
      cout << "UNIDAD ACADEMICA: ";
      cout << vInvest[x].getUnidadAcademica() << endl;
      cout << "CATEGORIA: ";
      cout << vInvest[x].getCategoria() << endl;
      cout << "ESPECIALIDAD: ";
      cout << vInvest[x].getCategoria() << endl;
      cout << "DNI: ";
      cout << vInvest[x].getCategoria() << endl;
    }


  }

}while(opcion != 3);




/*Investigador defecto;
cout << "Constructor por defecto\n: ";
cout << defecto.toString() << endl;

const char nombre[] = "Jaun";
std::string apellido = "PErez";
Fecha fecha(1,1,2020);
int unidadAcademica = 1;
    int categoria = 2;
    int especialidad = 3;
    int dni = 12345678;
Investigador parametro(nombre, apellido, fecha, unidadAcademica, categoria, especialidad, dni);
cout << "Parametros: " << endl;
cout << parametro.toString();

/*Fecha f;
Fecha f2;
Fecha f3;
int dia, mes, anio;

cout << "Dia: ";
cin >> dia;
cout << "Mes: ";
cin >> mes;
cout << "Anio: ";
cin >> anio;

f2.setDia(dia);
f2.setMes(mes);
f2.setAnio(anio);

f3 = Fecha(dia, mes, anio);

cout << f.toString() << endl;
cout << f2.toString() << endl;
cout << f3.toString() << endl;

cout << f.getNombreDia() << endl;
cout << f2.getNombreDia() << endl;*/

  return 0;
}