#include <iostream>

using namespace std;

/*
Crea una clase llamada Usuario que represente a un usuario en un sistema. 
La clase debe tener los siguientes atributos:
●	Nombre (string)
●	Clave (string)
●	Rol (string): Puede ser "admin" o "user".
Implementa los siguientes métodos:
●	Usuario(string nombre, string clave, string rol): Constructor que inicializa los atributos.
●	getter y setter de cada atributo

Desarrolla un programa que realice lo siguiente:
1.	Cargar en el sistema una lista de 5 usuarios utilizando un array de objetos Usuario
 (esto debe estar hardcodeado en el programa).

2.	Solicitar al usuario que ingrese su nombre y contraseña al iniciar el programa.
3.	Verificar si las credenciales ingresadas coinciden con alguno de los usuarios cargados en 
el sistema utilizando una función que reciba el array de usuarios, la cantidad de usuarios, el nombre y la contraseña.
Esta función debe devolver el índice donde se encuentra el usuario en el array, o -1 si el usuario no existe.

4.	Si se encuentra un usuario con las credenciales correctas, permitir el acceso al sistema mostrando 
el rol al que pertenece con un saludo amigable. 
Utiliza una función que reciba un objeto Usuario y muestre el saludo con el rol específico.
5.	Si el usuario ingresa credenciales incorrectas, permitir un máximo de 3 intentos. 
Si se agotan los intentos, el programa debe finalizar indicando que se han agotado los intentos.
*/

class Usuario {
private:
  string _nombre, _clave, _rol; 

public:
  Usuario(string nombre, string clave, string rol) : _nombre(nombre), _clave(clave), _rol(rol){}
  
  void setNombre(string nombre) { _nombre = nombre; }
  void setClave(string clave) { _clave = clave; }
  void setRol(string rol) { _rol = rol; }

  string getNombre() { return _nombre; }
  string getClave() { return _clave; }
  string getRol() { return _rol; }
};

int verificarClaveUsuario(Usuario vUs[], int tam, string nombre, string clave) {
  bool pasoAlguno = false;
  for(int i = 0; i < tam; i++){
    if(vUs[i].getClave() == clave && vUs[i].getNombre() == nombre){
      pasoAlguno = true;
      return i;
    }
  }

  if(!pasoAlguno) return -1;
}

int main() {
  system("cls");
  Usuario usuarios[5] = {
    Usuario("user1", "clave1", "admin"),
    Usuario("user2", "clave2", "user"),
    Usuario("user3", "clave3", "admin"),
    Usuario("user4", "clave4", "user"),
    Usuario("user5", "clave5", "admin")
  };


  string nombre, clave;
  int intentos = 0;
  int i;
  do{ 
    cout << endl << "Ingrese su nombre: "; cin >> nombre;
    cout << "Ingrese su clave: "; cin >> clave;
    i = verificarClaveUsuario(usuarios, 5, nombre, clave);
    intentos ++;
  }while(intentos < 3 && i == -1);

  (i != -1) ? cout << "Hola " << usuarios[i].getNombre() << " tu rol es " << usuarios[i].getRol() << endl : cout << "se han agotado los intentos..." << endl;
  

  return 0;
} 