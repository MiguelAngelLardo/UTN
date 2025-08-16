#include <iostream>
#include <cstring>

using namespace std;


class Cadena{
private:
    char *_p;
    int _tam;
public:
Cadena(const char *texto="pode"){
  _tam=strlen(texto)+1;//4+1
  _p=new char[_tam];
  if(_p==nullptr)exit(1);
  strcpy(_p,texto);// p[0]='p', p[1]='o', p[2]='d', p[3]='e'
  _p[_tam-1]='\0';//p[4]='\0'
}
  
const char *getPunteroP(){return _p;} /*=>*/void Mostrar(){cout<<_p<<endl;}

int get_tamanio(){return _tam;}

~Cadena(){delete []_p;}	

void agregarCaracter(char c) {
  /*
  OPERACIÓN               VALOR DE _tam   CONTENIDO DEL ARRAY
  Inicio:                  5             p o d e \0
  new char[_tam+1] (6)     5             _ _ _ _ _ _
  strcpy                   5             p o d e \0 _
  aux[_tam-1] = c (aux[4]) 5             p o d e r _
  aux[_tam] = '\0' (aux[5])5             p o d e r \0
  _tam++                   6             (__tamaño ahora es 6)
  */
  
  char *aux = new char[_tam + 1];  // aux[0] a aux[5] (6 espacios)
  if (aux == nullptr) exit(1);
  strcpy(aux, _p); // Copia "pode\0" queda pode\0_
       //5-1                   01234   
  aux[_tam - 1] = c;  // queda poder_

  aux[_tam] = '\0';   //poder\0
  
  delete[] _p;//borro todo
  _p = aux;
   
  _tam++;// SOLO AQUÍ incrementamos _tam (5 → 6)
}

/*
b)	Agregar un método que se llame aMayusculas(), 
que ponga todas las letras de la cadena en mayúsculas 
(ver relación entre mayúsculas y minúsculas en ASCII)
*/

void aMayusculas() {
  for(int i = 0; i < _tam - 1; i++) {
    if((int)_p[i] >= 97 && (int)_p[i] <= 122) { // 'a' = 97, 'z' = 122
      _p[i] -= 32; // 'A' = 65, 'Z' = 90
    }

  }
} 


/*
d)	Agregar un método para saber si un caracter existe dentro de una cadena. 
El método debe recibir un caracter, y devolver la posición del primer encuentro 
de ese caracter en el vector. Si el caracter no está debe devolver -1.
*/

int existeCaracter(char c){
  for(int i = 0; i < _tam - 1; i++) {
    if(_p[i] == c) {
      cout << "El caracter " << c << " se encuentra en la posicion " << i+1 << endl;
      return i+1;
    }
  }
  cout << "El caracter " << c << " no se encuentra en la cadena" << endl;
  return -1;
}

/*
e)	Agregar un método que reciba una posición (valor entero) y devuelva el 
caracter que se encuentra en esa posición (ver qué y cómo se tiene que validar).
*/

char obtenerCaracterPorPosicion(int pos){
  if(pos < 0 || pos >=_tam){
    cout << "Posicion fuera de rango" << endl;
    return '\0'; // Retorna un caracter nulo si la posición es inválida
  }else{
    return _p[pos-1];
  }
}

/*
f)	Agregar un método de nombre primeraMayuscula() que ponga la
 primera letra de la cadena en mayúscula. Pista: ver la diferencia 
entre el valor ASCII de una letra mayúscula y la misma pero minúscula.
*/
void primerMayuscula(){
  if(_tam > 0){
    _p[0] -= 32; // Cambia la primera letra a mayúscula
  }
}

};





int main() {
  Cadena c("pode");
  c.agregarCaracter('r');

  c.primerMayuscula();
  c.Mostrar(); // Debería mostrar "Pode"
  
 
 

  return 0;
}