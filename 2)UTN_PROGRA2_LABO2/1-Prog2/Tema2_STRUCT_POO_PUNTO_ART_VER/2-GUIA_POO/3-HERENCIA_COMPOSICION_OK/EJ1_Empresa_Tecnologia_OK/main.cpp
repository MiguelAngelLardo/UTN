#include<iostream>
#include<cstring>

using namespace std;

const int TAM = 5;

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


// DNI, nombre,  apellido, domicilio, email, fecha de nacimiento y cargo (número entre 1 y 10).
//a)  Crear la clase correspondiente, con:* sets() y gets() para todas las propiedades
//    Un constructor con valores por omisión para todos los parámetros (o alguno de ellos)
class Empleado{
private:
  int _dni;
  char _nombre[20];
  char _apellido[20];
  char _domicilio[20];
  char _email[20];
  Fecha _fechaNacimiento;
  int _cargo;//1 al 10

public:
  Empleado (int dni = 0, const char *nom = "X", const char *ape = "X", const char *dom = "X", const char *email = "X", Fecha fecha = Fecha(), int car = 0)
    : _dni(dni), _fechaNacimiento(fecha), _cargo(car)
    {strcpy(_nombre, nom); strcpy(_apellido, ape); strcpy(_domicilio, dom); strcpy(_email, email);}

  void setDni(int dni){_dni = dni;}
  void setNombre(const char *nom){strcpy(_nombre, nom);}
  void setApellido(const char *ape){strcpy(_apellido, ape);}
  void setDomicilio(const char *dom){strcpy(_domicilio, dom);}
  void setEmail(const char *email){strcpy(_email, email);}
  void setFechaNacimiento(Fecha fecha){_fechaNacimiento = fecha;}
  void setCargo(int car){_cargo = car;}

  int getDni(){return _dni;}
  const char *getNombre(){return _nombre;}
  const char *getApellido(){return _apellido;}
  const char *getDomicilio(){return _domicilio;}
  const char *getEmail(){return _email;}
  Fecha getFechaNacimiento(){return _fechaNacimiento;}
  int getCargo(){return _cargo;}

  void cargar(){
    cout << "DNI: ";cin >> _dni;
    cout << "Nombre: "; cargarCadena(_nombre, 20);
    cout << "Apellido: "; cargarCadena(_apellido, 20);
    cout << "Domicilio: "; cargarCadena(_domicilio, 20);
    cout << "Email: "; cargarCadena(_email, 20);
    cout << "Fecha de nacimiento: \n"; _fechaNacimiento.Cargar();
    cout << "Cargo(1-10): "; cin >> _cargo; 
  }

  void mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Domicilio: " << _domicilio << endl;
    cout << "Email: " << _email << endl;
    cout << "Fecha de nacimiento: \n"; _fechaNacimiento.Mostrar();
    cout << "Cargo: " << _cargo << endl;
  }

};

/*
b)	Hacer un programa para cargar y mostrar un vector de 5 empleados. Hacer un menú y usar funciones.
*/

void cargaVecEmpleados(Empleado vec[], int tam = 5){
  for (int x = 0; x < tam; x ++){
    printf("Cargando el EMPLEADO numero %d\n", x+1);
    vec[x].cargar();
    cout << endl;
  }
}

void mostrarVecEmpleados(Empleado vec[], int tam = 5){
  for (int x = 0; x < tam; x ++){
    printf("Cargando el EMPLEADO numero %d ", x+1);
    cout << endl;
    vec[x].mostrar();
    cout << endl;
  }
}

void menu(){
  Empleado vObjE[TAM];//punto A => cargar y mostrar 

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar 5 EMPLEADOS (con array)" << endl;//numero, nombre, cantidadEmpleados, categoria(1 a 80), numeroMunicipio (1 a 153)
    cout << "2-Mostrar 5 EMPLEADOS (con array)" << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {

    /**********************/
      case 1:{
        cargaVecEmpleados(vObjE, TAM);     
        }break;

    /**********************/
      case 2:{
       mostrarVecEmpleados(vObjE, TAM);
        }break;
    /**********************/
    
    case 0:
      return;
    default:
      cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
      break;
    }
    system("pause");

  } 
}


int main(){

  menu();

  return 0;

}