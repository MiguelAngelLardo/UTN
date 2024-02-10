#include <iostream>

using namespace std;
/*8) Diseñar un procedimiento que elimine los espacios blancos sobrantes de una cadena de caracteres dada. Se considera espacio
sobrante cuando:
a) Existen espacios blancos al comenzar la cadena. En este caso deben ser eliminados.
b) Existen dentro de la cadena más de un espacio en blanco seguido. En este caso debe dejarse sólo un.
c) Existen espacios en blanco al final de la cadena. En este caso deben ser eliminados.*/
int main(){
  char vCadena[50];

  cout << "Ingrese cadena caracter con getline:";
  cin.getline(vCadena, 50);
  cout << vCadena << endl;
  cout << &vCadena << endl;
  cout << &vCadena + 0 << endl;
  cout << &vCadena + 1 << endl;
  cout << &vCadena[0] << endl;
  cout << &vCadena[1] << endl;

  char *p = vCadena;
  cout << *p << endl;
  while(*p != '\0'){
    cout << *p;
    p++;
  }

  cout << endl << "Ingrese cadenas caracter con for:";
  int x;
  bool bandera = false;
  for(x = 0; x < 49 && bandera == false; x ++){
    vCadena[x] = cin.get();// atrapa un caracter y el espacio
    bandera = (vCadena[x] == '\n') ? true : false;
  }
  vCadena[x-1] = '\0';//le resto uno para quitar el \n por el \0

  int len = 0;
  while(vCadena[len] != '\0'){//si pongo "hola" habran un largo de 4 len => por que va del 0 al 4 (el 4to es '\0')
    len ++;
  }

  //PUNTO A => ELIMINAR AL COMIENO DE LA CADENA
  int lenBlanco = 0;
  while(vCadena[lenBlanco] == ' ' && lenBlanco < len){
    lenBlanco ++;
  }

  cout << "PUNTO A: ELIMINAR ESPACIOS AL PPO: \n";
  cout << "ESPACIOS BLANCOS AL COMIENZO #" << lenBlanco << endl;
  cout << "CADENA CORREGIDA SIN ELIMINAR (SOLO MUESTRO):" << vCadena + lenBlanco << endl;

  for(int x = 0; x < len - lenBlanco; x ++){ // le agrego uno para que "___hola" = "holaola" y no "holhola"
    vCadena[x] = vCadena [x + lenBlanco];
  }
                                                                                       //7 - 3
  vCadena[len - lenBlanco] = '\0'; // si quedo "hola" va den 0 al 3 por ende en el espacio 4 pongo el '\0'

  cout << "CADENA CORREGIDA ELIMINADO ESPACIO:" << vCadena << endl;;

  //PUNTO B => Elimina DOBLES ESPACIOS EN EL MEDIO de la cadena
  for (int x = 0; x < len -lenBlanco; x ++){
    if(vCadena[x] == ' ' && vCadena[x + 1] == ' '){
      while(vCadena[x + 1] == ' '){
        for(int y = x; y < len - lenBlanco; y ++){
          vCadena[y] = vCadena[y+1];//"hola__como" => "hola__como" => "hola ccomo"
        }
      }
    }
  }
  cout << endl << endl << "PUNTO B: ELIMINAR ESPACIOS DEL MEDIO: \n";
  cout << "CADENA CORREGIDA:" << vCadena << endl;
  
  


  return 0;
}