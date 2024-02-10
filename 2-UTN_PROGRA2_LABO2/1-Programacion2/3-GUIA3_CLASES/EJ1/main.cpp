#include <iostream>

using namespace std;

#include "clases.h"
#include "funciones.h"

const int TAM = 5;

void cargarCadena(char palabra[], int tam){
  int i = 0;
  fflush(stdin);
  for (i = 0; i < tam; i ++){ ///yo tengo un char de 30 (0-29)
    palabra[i] = cin.get(); //lee un solo caracter
    if(palabra[i] == '\n') //\n es el enter
      break;
  }
  palabra [i] = '\0'; //fin del arreglo
  fflush(stdin);
}

class Fecha{
private:
  int dia, mes, anio;
public:
  Fecha(int d = 0, int m = 0, int a = 0){
    dia = d;
    mes = m;
    anio = a;
  }

  void cargar(){
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

  void mostrar(){ ///POR QUE NO USAMOS GETDIA
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


class Empleado{
private:
  int dni;
  char nombre[30], apellido [30], domicilio[30], email[35];
  Fecha fechaNacimiento;
  int cargo;

public:
  Empleado(int dni = 0, const char *nombre = "nadie", const char *apellido = "ninguno", const char *domicilio = "Nada", const char* email = "", Fecha fechaNacimiento = Fecha(), int cargo = 0){
    this->dni = dni;
    strcpy(this->nombre, nombre);
    strcpy(this->apellido, apellido);
    strcpy(this->email, email);
    this->fechaNacimiento = fechaNacimiento;
    this->cargo = cargo;
  }

  void setDni (int d){
    dni = d;
  }

  void setNombre (char n[]){
    strcpy(nombre, n); //copia lo de n a nombre
  }

  void setApellido(char n[]){
    strcpy(apellido, n);
  }

  void setDomicilio(char n[]){
    strcpy(domicilio, n);
  }

  void setemail(char n[]){
    strcpy(email, n);
  }

  void setFechaNacimiento(Fecha f){
    fechaNacimiento = f;
  }
  void setCargo(int c){
    cargo = c;
  }

  int getDni(){return dni;}
  const char *getNombre(){return nombre;} // yo devuelvo direccion variable, por eso uso const
  const char *getApellido(){return apellido;}
  const char *getDomicilio(){return domicilio;}
  const char *getEmail(){return email;}
  Fecha getFechaNacimiento(){return fechaNacimiento;}
  int getCargo(){return cargo;}

  void cargar(){
    int dni;
    int cargo;
    cout << "NOMBRE: "; ///POR QUE ACCEDE A NOMBRE SIN EL SET NOMBRE
    cargarCadena(nombre, 29);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 29); //max caracteres es 29
    cout << "DOMICILIO: ";
    cargarCadena(domicilio, 29);
    cout << "EMAIL: ";
    cargarCadena(email, 34);
    cout << "FECHA NACIMIENTO: " << endl;
    fechaNacimiento.cargar();
    cout << "CARGO: ";
    cin >> cargo;
    setCargo(cargo);
    cout << "DNI: ";
    cin >> dni;
    setDni(dni);
  }
  void mostrar(){
    cout << "NOMBRE: ";
    cout << nombre << endl;
    cout << "APELLIDO: ";
    cout << apellido << endl;
    cout << "DOMICILIO: ";
    cout << domicilio << endl;
    cout << "EMAIL: ";
    cout << email << endl;
    cout << "FECHA NACIMIENTO: ";
    fechaNacimiento.mostrar();
    cout << endl;
    cout << "CARGO: ";
    cout << cargo << endl;
    cout << "DNI: ";
    cout << dni << endl;
  }
};


void cargarEmp(Empleado vEmp[]){
  for(int x = 0; x < TAM; x ++){
    cout << "INGRESE AL EMPLEADO: #" << x + 1 <<":\n";
    vEmp[x].cargar();
  }
}

void mostrarEmp(Empleado vEmp[]){
  for(int x = 0; x < TAM; x ++){
    cout << "MOSTRANDO EMPLEADOS #" << x + 1 <<":\n";
    vEmp[x].mostrar();
  }
}

int main()
{
  Empleado vEmpl[5];
  int opcion;

  do{
    cout << "\nMenu\n";
    cout << "1. Carga empleados\n";
    cout << "2. Mostrar empleados\n";
    cout << "3. SALIR\n";
    cout << "Ingrese la opcion: ";
    cin >> opcion;
    cin.ignore();  // Limpia el buffer


    switch(opcion)
    {
      case 1:
        cargarEmp(vEmpl);
        break;
      case 2:
        mostrarEmp(vEmpl);
        break;
      case 3:
        cout << "Saliendo del programa";
        break;
    }

  }while(opcion !=3);



    return 0;
}
