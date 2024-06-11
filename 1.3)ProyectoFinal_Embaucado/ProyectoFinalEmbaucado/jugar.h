#pragma once

void jugar();
void cargarNombre(Jugador &j1, Jugador &j2);
void inicializarMazo(Carta vMazo[TAM_BARAJA_FRANCESA]);
void mostrarMazoEnMesa(Carta vMazo[TAM_BARAJA_FRANCESA]);
void mezclarMazo(Carta vMazo[TAM_BARAJA_FRANCESA]);





///.CPP
#include <iomanip>

using namespace std;

void jugar(){
  Jugador jugador1, jugador2;//Declaro 2 jugadores
  Carta vMazo[TAM_BARAJA_FRANCESA];//Declaro el mazo de TAM = 20 -> string _valor; string _palo;

  cargarNombre(jugador1, jugador2);//Cargo nombres con sus validaciones
  inicializarMazo(vMazo);//inicializo mazo
  mostrarMazoEnMesa(vMazo);
  mezclarMazo(vMazo);
  mostrarMazoEnMesa(vMazo);


}

void cargarNombre(Jugador &j1, Jugador &j2){
    char confirmacion;

    do{
      cout << "EMBAUCADO" << endl;
      cout << "------------------------------------------------------------------------" << endl;
      cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

      cout << "¿Nombre del Jugadr 1? ";
      cin.ignore();//me limpia el enter que traigo de antes
      getline(cin, j1._nombre);
      while(j1._nombre.length() > 15){
        cout << "ERROR el nombre puede tener hasta 15 caracteres..." << endl;
        cout << "¿Nombre del Jugadr 1? ";
        getline(cin, j1._nombre);
      }
      j1._turno = 1;

      cout << "¿Nombre del Jugadr 2? ";
      getline(cin, j2._nombre);
      while(j2._nombre.length() > 15){
        cout << "ERROR el nombre puede tener hasta 15 caracteres..." << endl;
        cout << "¿Nombre del Jugadr 1? ";
        getline(cin, j2._nombre);
      }
      j2._turno = 2;

      cout << "\n¿Confirmar nombres? (S/N): ";
      cin >> confirmacion;

             //p => verdadero
      while(confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n'){
        cout << "ERROR solo se admite 'S' o 'N'" << endl;
        cout << "\n¿Confirmar nombres? (S/N): ";
        cin >> confirmacion;
      }
       if(confirmacion == 'N' || confirmacion == 'n'){
        cout << "Ingrese los nombres nuevamente\n";
        system("pause");
        system("cls");
       }else{
        cout << "\n------------------------------------------------------------------------" << endl;
       }

       system("cls");

    }while(confirmacion != 's' && confirmacion != 'S');

}


//Esta funcion arma inicializa el mazo de fabrica
void inicializarMazo(Carta vMazo[TAM_BARAJA_FRANCESA]){
  for (int i = 0; i < TAM_BARAJA_FRANCESA; i++)
  {            //de palos toma el indice[i]
    vMazo[i] = {PALOS[i / TAM_VALOR], VALORES[i % TAM_VALOR]};
  }            //0/5 = [0] = "corazon", 0%5[0] = "10"
               //1/5 = [0] = "corazon", 1%5[1] = "J"
               //2/5 = [0] = "corazon", 2%5[2] = "Q"
               //3/5 = [0] = "corazon", 3%5[3] = "K"
               //4/5 = [0] = "corazon", 4%5[4] = "A"
               //5/5 = [1] = "diamante", 5%5 [0] = "10"
               //19/5 = [3] = "trebol", 19%5[4] = "A"
}

void mostrarMazoEnMesa(Carta vMazo[TAM_BARAJA_FRANCESA])
{
  cout << "+--------------------+" << endl;
  cout << "|                    |" << endl;

  for (int x = 0; x < TAM_BARAJA_FRANCESA; x++)
  {
    cout << "|     " << vMazo[x]._valor << " " << vMazo[x]._palo
         << setw(15 - vMazo[x]._valor.length() - vMazo[x]._palo.length()) << "|" << endl;
    /// 15 es el ancho total deseado.
    /// .length devuelve la longitud de la cadena. => estas son restadas al ancho de 15
  }

  cout << "|                    |" << endl;
  cout << "+--------------------+" << endl;

  system ("pause");

}



void mezclarMazo(Carta vMazo[TAM_BARAJA_FRANCESA]){
  cout << "Mezclando el mazo" << endl;
  system("pause");
  int numAleatorio1, numAleatorio2;
  Carta aux;

  for(int x = 0; x < 1000; x++){
      numAleatorio1 = rand() % TAM_BARAJA_FRANCESA;//resultado de 0 a 19
      numAleatorio2 = rand() % TAM_BARAJA_FRANCESA;//resultado de 0 a 19

        //aux tiene carta 8
      aux = vMazo[numAleatorio1];
       //<---donde estaba la 2 ahora tengo la carta 5
      vMazo[numAleatorio1] = vMazo[numAleatorio2];
      //donde estaba la 5 ahora pongola 2
      vMazo[numAleatorio2] = aux;
  }
}












