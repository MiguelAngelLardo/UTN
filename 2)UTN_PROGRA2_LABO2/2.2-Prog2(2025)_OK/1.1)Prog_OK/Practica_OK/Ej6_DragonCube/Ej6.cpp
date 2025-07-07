#include <iostream>

using namespace std;
//album de 50 figuritas
//cada paqueta tiene 5 figus
int main() {
  int numeroPaquete;//indistinco
  int numerofigu;//1 a 50
  char tipoFigu;//c o h
  char pegar;//s o n|

  //Punta A
  int vComRepetidas[50] = {0};//vector de comunes repetidas
  int contComunesRepetidas = 0;

  //puntoB
  int vfigusCont[50] = {0};//vector de figus contadas
  int contFaltantes = 0;

  //Punto C
  int vHoloNoRepe[50] = {0};//vector de holo no repetidas
  int cantHologramasNoRepe = 0;

  //Punto D
  bool vEstadoAlbum[50][2] = {}; // [numFigu][C=0, H=1]

  //Punto E
  const int PAQUETE = 500, COMUN = 20, HOLOGRAMA = 50;
  int acumColeccion = 0;

  int vContComunNoPegada[50] = {0};
  int vContHoloNoPegada[50] = {0};

  cout << "Ingrese el numero de paquete" << endl;
  cin >> numeroPaquete;

  while (numeroPaquete != 0){
    acumColeccion += PAQUETE;
    for(int i = 0; i < 5; i++){
      cout << "Ingrese la figura #" << i + 1 << ": ";
      cin >> numerofigu;
      cout << "Ingrese el tipo de figura: ";
      cin >> tipoFigu;
      cout << "Pegar en el album? (s/n): ";
      cin >> pegar;
      
      //punto A
      if(tipoFigu == 'C'){
        vComRepetidas[numerofigu - 1]++;
      }

      //punto B
      vfigusCont[numerofigu - 1]++;

      //Punto C
      if(tipoFigu == 'H'){
        vHoloNoRepe[numerofigu - 1]++;
      }

      //Punto D
      (tipoFigu == 'C') ? vEstadoAlbum[numerofigu - 1][0] = true : vEstadoAlbum[numerofigu - 1][1] = true;

      //Punto E
      acumColeccion += (tipoFigu == 'C') ? COMUN : HOLOGRAMA;

      //Punto F
      if(tipoFigu == 'C' && pegar == 'N'){
        vContComunNoPegada[numerofigu - 1]++;
      }

      if(tipoFigu == 'H' && pegar == 'N'){
        vContHoloNoPegada[numerofigu - 1]++;
      }

    }  

    cout << "Ingrese el numero de paquete" << endl;
    cin >> numeroPaquete;
  }

  system("cls");
  //Punto A  
  for(int i = 0; i < 50; i++){
    if(vComRepetidas[i] >= 2){
      contComunesRepetidas += (vComRepetidas[i]-1);
    }  
  }  

  cout << "La cantidad de figuritas comunes repetidas es: " << contComunesRepetidas << endl;
  
  //Punto B
  for(int i = 0; i < 50; i++){
    if(vfigusCont[i] == 0){
      contFaltantes++;
    }  
  }  

  cout << "La cantidad de figuritas faltantes es: " << contFaltantes << endl;

  //Punto C
  for(int i = 0; i < 50; i++){
    if(vHoloNoRepe[i] > 0){
      cantHologramasNoRepe++;
    }  
  }

  cout << "La cantidad de figuritas hologramas no repetidas es: " << cantHologramasNoRepe << endl;

  //Punto D
  bool completo = true;
  bool todasComunes = true;
  bool todasHologramas = true;

  for(int i = 0; i < 50; i++){                         //1     +   0    = 1
    if(!vEstadoAlbum[i][0] && !vEstadoAlbum[i][1]){// fig 1 C + fig 1 H
      completo = false;
    } 

    //!vEstadoAlbum[1][0] = false (porque no estaba pegada como comú)
    //!vEstadoAlbum[1][1] = false (porque no estaba pegada como holo)
    //false || false = 0+0 → false → El if se activa, marcando completo = false. ya que falto la carta 1

    //!vEstadoAlbum[1][0] = true (porque estaba pegada como comú)
    //!vEstadoAlbum[1][1] = false (porque no estaba pegada como holo)
    //true || false= 1+0 → true → El if no se activa con lo que queda en true por que hay carta

    if(!vEstadoAlbum[i][0]){
      todasComunes = false;
    }

    if(!vEstadoAlbum[i][1]){
      todasHologramas = false;
    }
  }

  if(!completo) {
    cout << "Incompleto" << endl;
  }else if (todasComunes) {
    cout << "Completo común" << endl;
  }else if (todasHologramas) {
    cout << "Completo holográfico" << endl;
  }else {
  cout << "Completo" << endl;
  }

  //Punto E
  cout << "El costo total de la coleccion es: " << acumColeccion << endl;

  //Punto F
  int acumComunHoloNoPegada = 0;
  for(int i = 0; i < 50; i++){
    if (vContComunNoPegada[i] > 0) acumComunHoloNoPegada += (COMUN*vContComunNoPegada[i]);
    if (vContHoloNoPegada[i] > 0) acumComunHoloNoPegada += (HOLOGRAMA*vContHoloNoPegada[i]);
  }  

  cout << "El costo total de una potencial venta de figuritas no pegadas de la coleccion es: " << acumComunHoloNoPegada << endl;


  return 0;
}