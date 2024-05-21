#include <iostream>
#include <cstring>
using namespace std;

#include "Fecha.h"

/*
basedato

123
1
1
1
pepe
albarez
pepe@albarez
+54126
456
2
2
2
pedro
perez
pedro@perez
+54126
789
3
3
3
juan
gonzalez
juan@gonzalez
+54126
111
4
4
4
maria
lopez
maria@lopez
+54126
222
5
5
5
pedro
sanchez
pedro@sanchez
+54126
333
6
6
6
pedro
sanchez
pedro@sanchez
+54126
444
7
7
7
amalia
sanchez
amalia@sanchez
+54126
555
8
8
8
natalia
lopez
natalia@lopez
+54126
666
9
9
9
pedro
lopez
pedro@lopez
+54126
777
10
10
10
pedro
lopez
pedro@lopez
+54126
*/

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

class Cliente{
private: 
  int _dni;
  Fecha _fechaNacimiento;
  char _nombre[20];
  char _apellido[20];
  char _email[20];
  char _telefono[20];

public:
  Cliente (int dni= 000, Fecha fechaNac = Fecha(), const char *nombre ="S/N", const char *apellido = "S/N", const char *email = "S/N", const char *telefono = "S/N")
  : _dni(dni), _fechaNacimiento(fechaNac){
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_email, email);
    strcpy(_telefono, telefono);
  }

  Cliente(const char *nom){
    strcpy(_nombre, nom);
  }

  void setDni(int dni){_dni = dni;}
  void setFechaNac(Fecha fechaNac){_fechaNacimiento = fechaNac;}
  void setNombre(const char *nombre){strcpy(_nombre, nombre);}
  void setApellido(const char *apellido){strcpy(_apellido, apellido);}
  void setEmail(const char *email){strcpy(_email, email);}
  void setTelefono(const char *telefono){strcpy(_telefono, telefono);}

  int getDni(){return _dni;}
  Fecha getFechaNac(){return _fechaNacimiento;}
  char *getNombre(){return _nombre;}
  char *getApellido(){return _apellido;}
  char *getEmail(){return _email;}
  char *getTelefono(){return _telefono;}

  void cargar(){
    cout << "DNI: "; cin >> _dni;
    cout << "FECHA NACIMIENTO: ";
    _fechaNacimiento.cargar();
    cout << "NOMBRE: "; 
    cargarCadena(_nombre, 20);
    cout << "APELLIDO: ";
    cargarCadena(_apellido, 20);
    cout << "EMAIL: ";
    cargarCadena(_email, 20);
    cout << "TELEFONO: ";
    cargarCadena(_telefono, 20);
  }

  void mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "FECHA NACIMIENTO:\n";
    _fechaNacimiento.mostrar();
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "EMAIL: " << _email << endl;
    cout << "TELEFONO: " << _telefono << endl;
  }

};

void cargarVec10Clientes(Cliente vec[], int tam);
void listarVec10Clientes(Cliente vec[], int tam);
void listarDNIMayorA(Cliente vec[], int tam);
int posicionObjetoPorDNI(Cliente vec[], int tam, int dni);
Cliente objetoPorDNI(Cliente vec[], int tam, int dni);
int cantidadClientesNacimientoAnteriorAFecha(Cliente vec[], int tam, Fecha fecha);




void menu(){
  Cliente vObjC[10];// nombre, apellido, dni, fechaNacimiento, email, telefono

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar vector de 10 clientes" << endl;
    cout << "2-Listar todos los clientes del vector" << endl;
    cout << "3-Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado." << endl;
    cout << "4-A partir de un valor de DNI recibido como parámetro, devolver la posicion del objeto que contiene ese DNI. De no encontrarlo devolver -1" << endl;
    cout << "5-IDEM 4, pero debe devolver el objeto completo que contiene el DNI. De lo contrarop debe devolver un objeto Cliente con un valor de -1 en el DNI." << endl;
    cout << "6-Dado una fecha que se recibe como parámetro devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido." << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {
    /**********************/
    case 1:{
      cargarVec10Clientes(vObjC, 10);      
    }break;
    /**********************/
    case 2:
      listarVec10Clientes(vObjC, 10);
      break;
    /**********************/
    case 3:{
      listarDNIMayorA(vObjC, 10);     
    }break;
    /**********************/
    case 4:
      int posicion;
      posicion =  posicionObjetoPorDNI(vObjC, 10, 777);
      cout << "POSICION: " << posicion << endl;
      break;
    /**********************/
    case 5:{
      Cliente aux;
      aux = objetoPorDNI(vObjC, 10, 7777);
      aux.mostrar();      
    }break;
    /**********************/
    case 6:{
      int cantidadAnteriorFecha;
      cantidadAnteriorFecha =  cantidadClientesNacimientoAnteriorAFecha(vObjC, 10, Fecha(6,6,6));
      cout << "CANTIDAD: " << cantidadAnteriorFecha << endl;  
    }break;

    case 0:
      return;
    default:
      cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
      break;
    }
    system("pause");

  } 
}

void cargarVec10Clientes(Cliente vec[], int tam){
  for(int i = 0; i < tam; i++){
    vec[i].cargar(); 
    cout << endl; 
  }  
}

void listarVec10Clientes(Cliente vec[], int tam){
  for(int i = 0; i < tam; i++){
    vec[i].mostrar();  
    cout << endl;
  }
}

void listarDNIMayorA(Cliente vec[], int tam){
  int dni;
  cout << "Ingrese DNI para mostrar a los mayores respecto de su ingreso: ";
  cin >> dni;
  for(int i = 0; i < tam; i++){
    if(vec[i].getDni() > dni){
      vec[i].mostrar();
      cout << endl;
    }
  }  
  cout << "FIN PTO 3" << endl;
}

int posicionObjetoPorDNI(Cliente vec[], int tam, int dni){
  for(int i = 0; i < tam; i++){
    if(vec[i].getDni() == dni){
      return i;
    }
  }
  return -1;
}

Cliente objetoPorDNI(Cliente vec[], int tam, int dni){
  for(int i = 0; i < tam; i++){
    if(vec[i].getDni() == dni){
      return vec[i];
    }  
  }

  vec[0].setDni(-1);
  return vec[0];  
}

int cantidadClientesNacimientoAnteriorAFecha(Cliente vec[], int tam, Fecha fecha){
  int contador = 0;
  for(int i = 0; i < tam; i++){
    if(vec[i].getFechaNac().getAnio() < fecha.getAnio() && vec[i].getFechaNac().getMes() < fecha.getMes() && vec[i].getFechaNac().getDia() < fecha.getDia()){
      contador++;
    }  

  }
  return contador;
}  


int main() {
  menu();


  return 0;}