#include <iostream>

using namespace std;

int main(){
  //string => getline(cin, variable);
  char vCaracter[50];

  cout << "Ingrese la palabra con cin.getline:";
  cin.getline(vCaracter, 50);

  char *p {nullptr}; // para que el puntero en stack este null asi no tiene basura

  p = &vCaracter[0]; // => *p = vCaracter

  int vec[5];
  cout << "VEC " << vec << endl;
  cout << "&vec " << &vec << endl;
  cout << "&vec[0] " << &vec[0] << endl;  

  cout << &vCaracter << endl;// direccion

    
  //3 sinonimos => muesta toda la cadena
  cout << &vCaracter[0] << endl;//1º
  cout << vCaracter << endl;//2º  // con int me da la direccion de memoria del primer elemento 
  cout << p << endl; //3º

  //casteo a direccion de memoria
  cout << (void*)vCaracter << endl;
  cout << (void*)&vCaracter[0] << endl;
  cout << (void*)&vCaracter[1] << endl;

  //otros casos
  cout << endl << endl << endl;
  cout << vCaracter[0] << endl;
  cout << vCaracter[1] << endl;
  cout << &vCaracter[1] << endl;


  //muestra 1 caracter
  cout << *vCaracter << endl;// h idem int
  cout << *p << endl; //h
  
  while(*p != 0){
    cout << *p;
    p++;
  }

  cout << endl << "Ingrese cadenas caracter con for:";
  int x;
  bool bandera = false;
  for (x = 0; x < 49 && !bandera; x++){
    vCaracter[x] = cin.get();//atrapa un caracter y el espacio
    bandera = (vCaracter[x] == '\n') ? true : false;
  }
  vCaracter[x-1] = '\0';//le resto uno para quitar el \n por el \0 o puedo usar cin.ignore();

  int len = 0;
  while(vCaracter[len] != '\0'){//si pongo "hola" habran un largo de 4 len => por que va del 0 al 4 (el 4to es '\0')
    len ++;
  }

  
  //TP REAL
  char vChain[50], l;
  int y = 0;
  cout << x + 1 << ")Enter the character string(FINISH WHIT '*'): ";
  cin >> l; // si o si me guarda 1 letra... si pongo "hola" guara 'h'
  while(l != '*'){
    vChain[y] = l;
    y ++;
    cout << x + 1 << ")Enter the character string(FINISH WHIT '*'): ";
    cin >> l;
    cin.ignore(); // Ignora el carácter de nueva línea osea que no queda '\n' despues de hola

  }
  vChain[y] = '\0';  // Asegúrate de que la cadena esté terminada con '\0'
  
  int K_esimo;
  cout << "Introduzca el K-esimo para rotar la cadena: ";
  cin >> K_esimo;

  int len2 = 0;
  while(vChain[len2] != '\0'){
    len2++;
  }

  cout << "Cantidad de caracteres: " << len2 << endl;
  
  for(int x = 0; x < len2; x ++){
    char aux = vChain[x];

    if(aux >= 'A' && aux <= 'Z'){
      char rotada = (aux - 'A' + K_esimo) % 26 + 'A';
      //A-A da 0
      //0 + k_esimo = 3
      //3 % 26 => como uso 0 de cociente bajo el 3 como modulo queda en 3
      //3 + A => 65 + 3 => 68 (lo que vale D)
      vChain[x] = rotada;
    }
    cout << "LETRA ORIGINAL: " << aux << ", LETRA ROTADA: " << vChain[x] << endl;
  }
  

 return 0;
}







