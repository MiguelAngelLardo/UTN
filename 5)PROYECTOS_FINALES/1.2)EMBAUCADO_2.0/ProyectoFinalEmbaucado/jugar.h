#pragma once

///JUGAR de toda la vida
void jugar();

///CARGO NOMBRE
void cargarNombre(Jugador &j1, Jugador &j2);

///FX para MazoFrancesa
void inicializarMazoFrancesa(Carta vMazoFrancesa[TAM_BARAJA_FRANCESA]);
void mostrarMazoFrancesaEnMesa(Carta vMazo[TAM_BARAJA_FRANCESA]); // NO SE USA!
void mezclarMazoFrancesa(Carta vMazo[TAM_BARAJA_FRANCESA]);

///FX para MazoFigura
void inicializarMazoFigura(Figura vMazoFigura[TAM_PALO]);
void mostrarMazoFigura(Figura vMazoFigura[TAM_PALO]); // NO SE USA!
void mezclarMazoFigura(Figura vMazoFigura[TAM_PALO]);

///HEADER
void crearHeader(int filaInicial, int ronda, Jugador &j1, Jugador &j2);

///DIBUJOCARTAS
void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo);
void dibujarNumero(string num, int puntaje, int posX, int posY);
void dibujarReversoCarta(int posX, int posY);//usa Rectangulo
void dibujarCarta(string num, int puntaje, char palo, int posX, int posY);//usa Rectangulo y el Numero
template <typename T>//funcion PLANTILLA para aceptar Carta y Figura
int obtenerPalo(T vMazo[], int index);//Transforma el STRING en un INT para el char

///TIRADA 1º y 2º PREPARATORIAS
void tiradaDeCartas(Carta vMazoFrancesa[], Figura vMazoFigura[]);

///PREPARATORIA => inicializa mazos, mezcla mazos, header, tiradaDeCartas
void mostrarCartasPreparatorias(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]);//

///REPARTIJA => 5 para cada uno, en Back (reparte y calcula puntos para cada J) y Front
void repartirCartasBack(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[]);
void repartirCartasFront(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]);

///JUEGO IN SITU
void ronda1(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[], int ronda);
void desarrolloPartida(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]);






///.CPP
#include <iomanip>
#include "textoResponsivo.h"

using namespace std;

void jugar(){
  Jugador jugador1, jugador2;//Declaro 2 jugadores
  Carta vMazoFrancesa[TAM_BARAJA_FRANCESA];//Declaro el mazo de TAM = 20 -> string _valor; string _palo;
  Figura vMazoFigura[TAM_PALO]; //vMazofigura de 4 cartas embaucadoras

  cargarNombre(jugador1, jugador2);//Cargo nombres con sus validaciones
  mostrarCartasPreparatorias(jugador1, jugador2, vMazoFrancesa, vMazoFigura);//inicializa mazos, mezcla mazos, header, tiradaDeCartas

  desarrolloPartida(jugador1, jugador2, vMazoFrancesa, vMazoFigura); //dentro tiene las 3 rondas y el header

}








void cargarNombre(Jugador &j1, Jugador &j2){
    char confirmacion;

    do{
      cout << "EMBAUCADO" << endl;
      cout << "-------------------------------------------------" << endl;
      cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

      cout << "Nombre del Jugadr 1? ";
      cin.ignore();//me limpia el enter que traigo de antes
      getline(cin, j1._nombre);
      while(j1._nombre.length() > 15){
        cout << "ERROR el nombre puede tener hasta 15 caracteres..." << endl;
        cout << "Nombre del Jugadr 1? ";
        getline(cin, j1._nombre);
      }
      //j1._turno = 1;

      cout << "Nombre del Jugadr 2? ";
      getline(cin, j2._nombre);
      while(j2._nombre.length() > 15){
        cout << "ERROR el nombre puede tener hasta 15 caracteres..." << endl;
        cout << "Nombre del Jugadr 2? ";
        getline(cin, j2._nombre);
      }
     // j2._turno = 2;

      cout << "\nConfirmar nombres? (S/N): ";
      cin >> confirmacion;

             //p => verdadero
      while(confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n'){
        cout << "ERROR solo se admite 'S' o 'N'" << endl;
        cout << "\nConfirmar nombres? (S/N): ";
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

//va en front.h
void crearHeader(int filaInicial, int ronda, Jugador &j1, Jugador &j2) {
  rlutil::setBackgroundColor(rlutil::BLUE);
  rlutil::setColor(rlutil::WHITE);
  int tamCol = rlutil::tcols(); // obtiene el número de columnas de la terminal

  // Bucles para pintar la fila especificada + dos filas siguientes
  for (int y = filaInicial; y < filaInicial + 4; y++) {
    for (int x = 1; x <= tamCol; x++) {
      rlutil::locate(x, y);
      cout << " ";
    }
  }

  // Crear el texto del encabezado
  string texto1 = "EMBAUCADO";
  string lineaGuiones(tamCol, '-');///utiliza constructor string(size n, char c);
  string texto2 = "RONDA# " + to_string(ronda);
  string texto3 = j1._nombre + " Vs " + j2._nombre;

  // Calcular las posiciones para centrar cada línea de texto
  int posXCentro1 = (tamCol / 2) - (texto1.size() / 2);
  int posXCentro2 = 1;
  int posXCentro3 = (tamCol / 2) - (texto2.size() / 2);
  int posXCentro4 = (tamCol / 2) - (texto3.size() / 2);

  // Dibujar el texto centrado
  rlutil::locate(posXCentro1, filaInicial);
  cout << texto1;
  rlutil::locate(posXCentro2, filaInicial + 1);
  cout << lineaGuiones;
  rlutil::locate(posXCentro3, filaInicial + 2);
  cout << texto2;
  rlutil::locate(posXCentro4, filaInicial + 3);
  cout << texto3;
  cout <<endl;

  // Restablecer el color de fondo al valor predeterminado después de pintar
  rlutil::setBackgroundColor(rlutil::GREEN);
  rlutil::setColor(rlutil::BLACK);
}

//va en front.h
void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo){
  for(int x = posX; x < posX+ancho; x++){
    for(int y = posY; y < posY+alto; y++){
      rlutil::locate(x, y);
      cout << fondo;
    }
  }
}

//va en front.h
void dibujarReversoCarta(int posX, int posY){
  //rlutil::setColor(rlutil::WHITE);
  rlutil::setBackgroundColor(rlutil::LIGHTRED);
  dibujarRectangulo(posX,posY,5,3, 176);
}

//va en front.h
void dibujarNumero(string num, int puntaje, int posX, int posY){
  rlutil::locate(posX, posY);//arriba izq
  cout << num;

  rlutil::locate(posX+5-num.size(), posY+2);//abajo der
  cout << num;

  rlutil::setBackgroundColor(rlutil::GREEN);
  rlutil::setColor(rlutil::BLACK);
  rlutil::locate(posX, posY+3);
  if(puntaje == -1){
    cout << "S/P";
  }else if (puntaje == -2){
    cout << "";
  }else{
    cout << puntaje << " pt";
  }

  //if(puntaje == -1) ? cout << "S/P" : cout << puntaje << " pt";
}


//va en front.h
void dibujarCarta(string num, int puntaje, char palo, int posX, int posY){///dibuja Rectangulo y el Numero
  rlutil::setColor(rlutil::WHITE);
  dibujarRectangulo(posX,posY,5,3, 219);//hace 5 de X y 3 de Y

  // Determinar color del palo (tamb se usa para el num) y fondo blanco
  rlutil::setBackgroundColor(rlutil::WHITE);
  rlutil::setColor((palo == 3 || palo == 4) ? rlutil::BLUE : rlutil::BLACK);
  rlutil::locate(posX+2, posY+1);
  cout << palo;

  //uso el color del palo para el num y pongo fondo blanco para el num
  rlutil::setBackgroundColor(rlutil::WHITE);
  dibujarNumero(num, puntaje, posX, posY);
}


//va en front.h
template <typename T>///funcion PLANTILLA
int obtenerPalo(T vMazo[], int index){//Transforma el STRING en un INT para el char
  if(vMazo[index]._palo == "Diamante"){
    return 4;
  }else if(vMazo[index]._palo == "Pica"){
    return 6;
  }else if(vMazo[index]._palo == "Corazon"){
    return 3;
  }else if(vMazo[index]._palo == "Trebol"){
    return 5;
  }
}

//va en front.h (js)
void tiradaDeCartas(Carta vMazoFrancesa[], Figura vMazoFigura[]){
  //int palos[] = {3,4,5,6}; //4 diamante, 6 pica, 3 corazon, 5 trebol
  int index = 0;
  bool banderaEmbaucadora = false;
   for(int k = 1; k <=2; k++){//dibuja la carta dada vuelta y la gira
     for(int i = 1; i <=4; i ++){ //i es la fila
      for(int j=1; j <= 5; j++){ //j es la col
        if(k == 1){
          dibujarReversoCarta(j*8,(i*6));//Reverso de Mazo Francesa
          if(i == 4 && j == 5)banderaEmbaucadora = true;
            if(banderaEmbaucadora){
              for(int z = 1; z <= 4; z++){//5*8 es la 5ta fila y el z es la col
                dibujarReversoCarta((z*8)+4, (5*6)-1);//Reverso de Mazo Embaucadora
              }
            }
        }else{
          banderaEmbaucadora = false;
          for(int m = 0; m <= 10; m++){ // para que gire antes de mostrar el valor
            int randomIndex = rand() % 20;
            dibujarCarta(vMazoFrancesa[randomIndex]._valor, vMazoFrancesa[randomIndex]._puntaje, obtenerPalo(vMazoFrancesa, randomIndex), j * 8, i * 6);
            rlutil::msleep(8);
          }
          dibujarCarta(vMazoFrancesa[index]._valor, vMazoFrancesa[index]._puntaje, obtenerPalo(vMazoFrancesa,index), j*8, i*6);
          index ++;
          rlutil::msleep(18);
          if(i == 4 && j == 5)banderaEmbaucadora = true;
            if(banderaEmbaucadora){
              index = 0;
              for(int z = 1; z <= 4; z++){//5*8 es la 5ta fila y el z es la col
                dibujarCarta("E", -1,obtenerPalo(vMazoFigura, index++), (z*8)+4, (5*6)-1);//-1 hard codeado para que diga S/P
              }
            }

        }
      }
    }
  }
  //rlutil::showcursor(); // Mostrar el cursor al final de la función
}





//va en el back.h
//Esta funcion arma inicializa el mazo de fabrica
void inicializarMazoFrancesa(Carta vMazoFrancesa[]){
  for (int i = 0; i < TAM_BARAJA_FRANCESA; i++)
  {
    vMazoFrancesa[i] = {VALORES[i%TAM_VALOR], PALOS[i/TAM_VALOR], PUNTAJE[i%TAM_VALOR]};
  }
               //vMazoFrancesa[2] = {"10", "Corazon", 10}, {"J", "Corazon", 11};
               //0%5 -> [0] = "10", 0/5 -> [0] = "Corazon"
               //1%5 -> [1] = "J",  1/5 -> [0] = "Corazon"
               //4%5 -> [4] = "A", 4/5 -> [0] = "Corazon"



}

void mostrarMazoFrancesaEnMesa(Carta vMazo[TAM_BARAJA_FRANCESA]){ // NO SE USA!
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

void mezclarMazoFrancesa(Carta vMazo[TAM_BARAJA_FRANCESA]){
  mostrarMensaje("+-----------------+\n|Mezclando el mazo|\n+-----------------+", 10, -1);

  /*cout << endl << "+-----------------+" << endl;
  cout << "|Mezclando el mazo|" << endl;
  cout << "+-----------------+" << endl;*/

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

  system("pause");
}

void inicializarMazoFigura(Figura vMazoFigura[TAM_PALO]){
  for(int i = 0; i < TAM_PALO; i ++){
    vMazoFigura[i] = {PALOS[i]};
  }
}

void mostrarMazoFigura(Figura vMazoFigura[TAM_PALO]){ // NO SE USA!
  for(int i = 0; i < TAM_PALO; i ++){
    cout << "EMBAUCADORA -> " << vMazoFigura[i]._palo << endl;
  }
}

void mezclarMazoFigura(Figura vMazoFigura[TAM_PALO]){
  cout << endl << "+---------------------------------------------+" << endl;
  cout << "|Mezclando las Figuras de la carta EMBAUCADORA|" << endl;
  cout << "+---------------------------------------------+" << endl;
  int numAleatorio1, numAleatorio2;
  Figura aux;

  for(int x = 0; x < 1000; x++){
    numAleatorio1 = rand() % TAM_PALO;//de 0 a 3
    numAleatorio2 = rand() % TAM_PALO;
    aux = vMazoFigura[numAleatorio1];
    vMazoFigura[numAleatorio1] = vMazoFigura[numAleatorio2];
    vMazoFigura[numAleatorio2] = aux;
  }
  system ("pause");
}


//inicializa mazos, mezcla mazos, header, tiradaDeCartas
void mostrarCartasPreparatorias(Jugador &jugador1, Jugador &jugador2, Carta vMazoFrancesa[], Figura vMazoFigura[]){
  //rlutil::setBackgroundColor(rlutil::GREEN);
 // rlutil::cls();//sin esto el fondo de las letras se pone verde y no todo el tablero

  crearHeader(1, 0, jugador1, jugador2);//paso filaInicial, ronda, j1, j2
  inicializarMazoFrancesa(vMazoFrancesa);//inicializo mazo
  inicializarMazoFigura(vMazoFigura);//inicializo mazo

  tiradaDeCartas(vMazoFrancesa, vMazoFigura);
  cout << endl << endl;
  cout << endl << "+--------------------------+" << endl;
  cout << "|PRIMER TIRADA PREPARATORIA|" << endl;
  cout << "+--------------------------+" << endl;
  system("pause");

  mezclarMazoFrancesa(vMazoFrancesa);
  mezclarMazoFigura(vMazoFigura);
  system("cls");

  crearHeader(1, 0, jugador1, jugador2);//paso filaInicial, ronda, j1, j2
  tiradaDeCartas(vMazoFrancesa, vMazoFigura);
  cout << endl << endl;
  cout << endl << "+---------------------------+" << endl;
  cout << "|SEGUNDA TIRADA PREPARATORIA|" << endl;
  cout << "+---------------------------+" << endl;
  system("pause");
  system("cls");
}


///BACK => reparte y suma puntaje back
void repartirCartasBack(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[]){
  for (int x = 0; x < CARTAS_POR_MANO+CARTAS_POR_MANO; x++) { // reparto las cartas de 0 al 9=> carta por mano es 5+5
    if (x % 2 == 0) { // Numero par es jugador 1
      j1._mano[x/2] = vMazoFrancesa[x];
    }else{ // Numero impar es jugador 2
      j2._mano[x/2] = vMazoFrancesa[x];
    }
  }
}


///FRONT => muestra la magia
void repartirCartasFront(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]){
  // Posiciona y muestra el nombre y puntaje del jugador 1
  rlutil::setBackgroundColor(rlutil::BLACK);
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(1, 6);
  cout << j1._nombre << " (" << j1._puntaje << " puntos)" << endl;


  // Dibuja las cartas del jugador 1
  for(int j = 1; j <= 5; j ++){
    dibujarCarta(j1._mano[j-1]._valor, j1._mano[j-1]._puntaje, obtenerPalo(j1._mano, j-1), j*6, 8);
  }

  // Posiciona y muestra el nombre y puntaje del jugador 2
  rlutil::setBackgroundColor(rlutil::BLACK);
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(1, 12);
  cout << j2._nombre << " (" << j2._puntaje << " puntos)" << endl;

  // Dibuja las cartas del jugador 2
  for (int j = 0; j < 5; j++) {
    dibujarCarta(j2._mano[j]._valor, j2._mano[j]._puntaje,obtenerPalo(j2._mano, j), (j + 1)*6, 14);
  }

  dibujarCarta("E", -1,obtenerPalo(vMazoFigura, 0), 37, 11);//Figura embaucadora = vMazoFigura[0];
}


//ronda 1 -> embaucadora para TODES
void ronda1(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[], int ronda){
  repartirCartasBack(j1, j2, vMazoFrancesa);//back y front
  for(int sumaPuntaje = 0; sumaPuntaje < TAM_VALOR; sumaPuntaje++){//suma puntaje pero por el back
    j1._puntaje += j1._mano[sumaPuntaje]._puntaje;
    j2._puntaje += j2._mano[sumaPuntaje]._puntaje;
  }
  repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura);//back y front

  rlutil::locate(1, 19);
  cout << "AHORA LA EMBAUCADORA INHIBE A LAS CARTAS CON PALO -> '" << vMazoFigura[0]._palo << "'" << endl;
  system("pause");
  system("cls");

  // Redibujar el header
  crearHeader(1, ronda, j1, j2);

  //Logica Ronda 1
  for(int i = 0; i < 5; i ++){
    if(vMazoFigura[0]._palo == j1._mano[i]._palo){
      int aux1 = j1._mano[i]._puntaje;//guarda el valor del puntaje del palo embaucado
      j1._mano[i]._puntaje -= j1._mano[i]._puntaje;
      j1._puntaje -= aux1;
    }
    if(vMazoFigura[0]._palo == j2._mano[i]._palo){
      int aux2 = j2._mano[i]._puntaje;
      j2._mano[i]._puntaje -= j2._mano[i]._puntaje;
      j2._puntaje -= aux2;
    }
  }

  //guardo el puntaje REAL de la ronda 1
  j1._puntajeRonda[0] = j1._puntaje;
  j2._puntajeRonda[0] = j2._puntaje;

  repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura);

  rlutil::locate(1, 20);
  system("pause");
}


///DIABOLICA!!!!!!!
//suma puntaje de las 5 cartas y luego resta la de los embaucados => se usa en ronda 2 y 3
void actualizarPuntajes(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[], bool calcularPuntaje, int jugadorCambioEmbaucadora){
  int puntajeParcialJ1, puntajeParcialJ2;
  bool banderaPuntajeRonda = false;

  if(calcularPuntaje){//calcula luego de prguntar por S o N.... antes muestra el puntage de la partida anterior
    banderaPuntajeRonda = true;//para hacer el calculo del puntaje REALRONDA
    puntajeParcialJ1 = j1._puntaje;//guardo el puntaje de la ronda anterior asi lo Resto a la suma de la ronda anterior y ronda actual = obtengo putaje REALRONDA
    puntajeParcialJ2 = j2._puntaje;
    for(int sumaPuntaje = 0; sumaPuntaje < TAM_VALOR; sumaPuntaje++){ //suma puntaje pero por el back
      repartirCartasBack(j1, j2, vMazoFrancesa); //vuelvo a darle todos los puntajes a las cartas para que no queden en cero las de la embaucada anterior
      j1._puntaje += j1._mano[sumaPuntaje]._puntaje;
      j2._puntaje += j2._mano[sumaPuntaje]._puntaje;

    }
  }

  for(int i = 0; i < TAM_VALOR; i++){
    if(vMazoFigura[0]._palo == j1._mano[i]._palo){
      int aux1 = j1._mano[i]._puntaje; //guarda el valor del puntaje del palo embaucado
      j1._mano[i]._puntaje -= j1._mano[i]._puntaje;//solo muestra en las cartas el ptaje
      if(calcularPuntaje){
        j1._puntaje -= aux1;
      }
    }
    if(vMazoFigura[0]._palo == j2._mano[i]._palo){
      int aux2 = j2._mano[i]._puntaje;
      j2._mano[i]._puntaje -= j2._mano[i]._puntaje;
      if(calcularPuntaje){
        j2._puntaje -= aux2;
      }
    }
  }

  if(banderaPuntajeRonda){//cuando se elige S o N significa que hay puntos ACTIVOS
    j1._puntajeRonda[1] = j1._puntaje - puntajeParcialJ1;
    j2._puntajeRonda[1] = j2._puntaje - puntajeParcialJ2;
  }

  // Aplicar penalización de 20 puntos si se cambió la embaucadora
  if (jugadorCambioEmbaucadora == 1) {
      j1._puntajeRonda[1] -= 20;
      j1._puntaje -= 20;
  } else if (jugadorCambioEmbaucadora == 2) {
      j2._puntajeRonda[1] -= 20;
      j2._puntaje -= 20;
  }

}


//j1.puntaje = 0
//se usa en ronda 2 y 3
bool decidirCambioEmbaucadora(Jugador &jugador, Figura vMazoFigura[]) {
  char cambioEmbaucadora;

  if(jugador._puntaje >= 20){
    cout << "Oye " << jugador._nombre << " quieres perder 20 PTOS y cambiar la Embaucadora? 'S' o 'N': ";
    cin >> cambioEmbaucadora;
    while(cambioEmbaucadora != 'S' && cambioEmbaucadora != 's' && cambioEmbaucadora != 'N' && cambioEmbaucadora != 'n'){
      cout << "Entrada invalida. Por favor ingresa 'S' o 'N': ";
      cin >> cambioEmbaucadora;
    }

    if (cambioEmbaucadora == 'S' || cambioEmbaucadora == 's'){
      //jugador._puntaje -= 20;
      mezclarMazoFigura(vMazoFigura); // mezclo mazo Figura
      return true; // Indica que el cambio se realizó
    }else{
      return false; // Indica que el cambio no se realizó
    }

  }else{
    cout << "Lo siento " << jugador._nombre << " tienes solamente " << jugador._puntaje << " ptos, no puedes decidir en este momento. SUERTE!" << endl;
    return false;
  }
}



//ronda 2 -> si tenes 20 ptos, jugador 1 elige primero si quiere cambiar embaucadora
void ronda2(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[], int ronda){
  char cambioEmbaucadora;//para el S o N del cambio
  system("cls");
  crearHeader(1, ronda, j1, j2);

  mezclarMazoFrancesa(vMazoFrancesa);//mezclo mazo Francesa
  mezclarMazoFigura(vMazoFigura);//mezclo mazo Figura
  system("cls");
  crearHeader(1, ronda, j1, j2);

  //reparto en el ETER y muestro en el Fisico con puntos de ronda 1
  repartirCartasBack(j1, j2, vMazoFrancesa);//back
  actualizarPuntajes(j1, j2, vMazoFrancesa, vMazoFigura, false, 0);//falso para que no modifique el puntaje del jugador
  repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura);//front

  rlutil::locate(1, 19);
  cout << "AHORA LA EMBAUCADORA ES -> '" << vMazoFigura[0]._palo << "'" << endl;

  // Jugador 1 decide si quiere cambiar la embaucadora
  if (decidirCambioEmbaucadora(j1, vMazoFigura)){//se fija si tiene 20 puntos o no y valida la S y N
    system("cls");
    actualizarPuntajes(j1, j2, vMazoFrancesa, vMazoFigura, true, 1);//suma puntaje de las 5 cartas y luego resta la de los embaucados => se usa en ronda 2 y 3
    crearHeader(1, ronda, j1, j2);
    repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura); // front
  } else {
    // Jugador 2 decide si quiere cambiar la embaucadora
    if (decidirCambioEmbaucadora(j2, vMazoFigura)) {
      system("cls");
      actualizarPuntajes(j1, j2, vMazoFrancesa, vMazoFigura, true, 2);//2 es que el jugador dos debe restarse 20 PTOS para el calculo RONDAREAL
      crearHeader(1, ronda, j1, j2);
      repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura); // front
    }else{
      cout << "SON FLOJITOS... nadie se animo..." << endl;
      system("pause");
      system("cls");//por si ambos ponen N, que no quede el texto molestando
      actualizarPuntajes(j1, j2, vMazoFrancesa, vMazoFigura, true, 0);
      crearHeader(1, ronda, j1, j2);
      repartirCartasFront(j1, j2, vMazoFrancesa, vMazoFigura); // front
    }
  }



   rlutil::locate(1, 19);

  cout << "EMBAUCADO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "RONDA" << setw(20) << j1._nombre << setw(20) << j2._nombre << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << setw(20) << j1._puntajeRonda[i] << setw(20) << j2._puntajeRonda[i] << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL" << setw(20) << j1._puntaje << setw(20) << j2._puntaje << endl;



  rlutil::locate(1, 40);
  system("pause");
  system("cls");

}


void desarrolloPartida(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]){

  for(int ronda = 1; ronda <=3; ronda++){
    crearHeader(1, ronda, j1, j2);//el header ahora es llamado en cada ronda dinamicamente
    switch(ronda)
    {
      case 1:
        ronda1(j1, j2, vMazoFrancesa, vMazoFigura, ronda);
        break;
      case 2:
        ronda2(j1, j2, vMazoFrancesa, vMazoFigura, ronda);
        break;
      case 3:
        //ronda3(j1, j2, vMazo, vMazoFigura);
        break;
    }
  }
}








