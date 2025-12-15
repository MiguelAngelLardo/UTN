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
/*
a)	Operadores relacionales ==, !=, > y <. 
En todos los casos cada operador debe permitir la comparación entre 
un objeto Cadena y los siguientes tipos de datos:
	- otro objeto Cadena
	- un objeto string
	- un vector de caracteres
*/

bool operator ==(Cadena aux){
  if(_tam != aux.get_tamanio()) {  // Primero verificar tamaños diferentes
    return false;
  }
  for(int i = 0; i < _tam; i++) {
    if(_p[i] != aux.getPunteroP()[i]) {
      return false;
    } 
  }
  return true;
}

bool operator !=(Cadena aux){
  if(_tam != aux.get_tamanio()) {  // Primero verificar tamaños diferentes
    return true;
  }
  for(int i = 0; i < _tam; i++) {
    if(_p[i] != aux.getPunteroP()[i]) {
      return true;
    } 
  }
  return false;
}

bool operator <(Cadena aux){
  if(_tam != aux.get_tamanio()) {  // Primero verificar tamaños diferentes
    return _tam < aux.get_tamanio();
  }

  for(int i = 0; i < _tam; i++) {
    if(_p[i] < aux.getPunteroP()[i]) {
      return true;
    } else if(_p[i] > aux.getPunteroP()[i]) {
      return false;
    }
  }
  return false; // Son iguales
}

bool operator >(Cadena aux){
  if(_tam != aux.get_tamanio()) {  // Primero verificar tamaños diferentes
    return _tam > aux.get_tamanio();
  }

  for(int i = 0; i < _tam; i++) {
    if(_p[i] > aux.getPunteroP()[i]) {
      return true;
    } else if(_p[i] < aux.getPunteroP()[i]) {
      return false;
    }
  }
  return false; // Son iguales
}

bool operator ==(const string& aux) const {  // Mejor pasar por referencia constante
  // std::string no incluye el \0 en length()
  if(_tam != aux.length() + 1)  // Solo si tu Cadena guarda el \0 en _tam
    return false;
  
  // Compara hasta _tam-1 porque aux[_tam-1] sería el \0 en tu Cadena
  for(int i = 0; i < _tam - 1; i++) {
    if(_p[i] != aux[i]) {
      return false;
    } 
  }
  return true;
}

bool operator !=(const string& aux) const {  // Mejor pasar por referencia constante
  // std::string no incluye el \0 en length()
  if(_tam != aux.length() + 1)  // Solo si tu Cadena guarda el \0 en _tam
    return true;
  
  // Compara hasta _tam-1 porque aux[_tam-1] sería el \0 en tu Cadena
  for(int i = 0; i < _tam - 1; i++) {
    if(_p[i] != aux[i]) {
      return true;
    } 
  }
  return false;
}

bool operator <(const string& aux) const {  // Mejor pasar por referencia constante
  // std::string no incluye el \0 en length()
  if(_tam != aux.length() + 1)  // Solo si tu Cadena guarda el \0 en _tam
    return _tam < aux.length() + 1;
  
  // Compara hasta _tam-1 porque aux[_tam-1] sería el \0 en tu Cadena
  for(int i = 0; i < _tam - 1; i++) {
    if(_p[i] < aux[i]) {
      return true;
    } else if(_p[i] > aux[i]) {
      return false;
    }
  }
  return false; // Son iguales
}

bool operator >(const string& aux) const{
  if(_tam != aux.length() +1){
    return _tam > aux.length() +1;
  }
  for(int i = 0; i < _tam -1; i++){
    if(_p[i] > aux[i]){
      return true;
    } else if(_p[i] < aux[i]){
      return false;
    }
  }
  return false; 
}

bool operator == (const char* aux){
  if(_tam != strlen(aux) +1 ){// Solo si tu Cadena guarda el \0 en _tam
    return false;
  }

  for (int i = 0; i < _tam-1; i++){
    if(_p[i] != aux[i]){
      return false;
    }
  }
  return true;

}

bool operator != (const char* aux){
  if(_tam != strlen(aux) +1 ){// Solo si tu Cadena guarda el \0 en _tam
    return true;
  }

  for (int i = 0; i < _tam-1; i++){
    if(_p[i] != aux[i]){
      return true;
    }
  }
  return false;

};

bool operator < (const char* aux){
  if(_tam != strlen(aux) +1 ){// Solo si tu Cadena guarda el \0 en _tam
    return _tam < strlen(aux) +1;
  }

  for (int i = 0; i < _tam-1; i++){
    if(_p[i] < aux[i]){
      return true;
    } else if(_p[i] > aux[i]){
      return false;
    }
  }
  return false;
}

bool operator > (const char* aux){
  if(_tam != strlen(aux) +1 ){// Solo si tu Cadena guarda el \0 en _tam
    return _tam > strlen(aux) +1;
  }

  for (int i = 0; i < _tam-1; i++){
    if(_p[i] > aux[i]){
      return true;
    } else if(_p[i] < aux[i]){
      return false;
    }
  }
  return false;
}

};


int main() {
  Cadena c("podec");
  Cadena c2("pode");

  if(c != c2) {
    cout << "Cadena c es diferente de Cadena c2" << endl;
  } else {
    cout << "Cadena c es igual a Cadena c2" << endl;
  }

  return 0;
}