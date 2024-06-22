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

///REPARTIJA => 5 para cada uno
void repartirCartas(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]);


void ronda1(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]);



///.CPP
#include <iomanip>

using namespace std;

void jugar(){
  Jugador jugador1, jugador2;//Declaro 2 jugadores
  Carta vMazoFrancesa[TAM_BARAJA_FRANCESA];//Declaro el mazo de TAM = 20 -> string _valor; string _palo;
  Figura vMazoFigura[TAM_PALO]; //vMazofigura de 4 cartas embaucadoras

  cargarNombre(jugador1, jugador2);//Cargo nombres con sus validaciones
  rlutil::setBackgroundColor(rlutil::GREEN);
  rlutil::cls();//sin esto el fondo de las letras se pone verde y no todo el tablero

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

  crearHeader(1, 1, jugador1, jugador2);//paso filaInicial, ronda, j1, j2
 // ronda1(jugador1, jugador2, vMazoFrancesa, vMazoFigura);

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
      j1._turno = 1;

      cout << "Nombre del Jugadr 2? ";
      getline(cin, j2._nombre);
      while(j2._nombre.length() > 15){
        cout << "ERROR el nombre puede tener hasta 15 caracteres..." << endl;
        cout << "Nombre del Jugadr 2? ";
        getline(cin, j2._nombre);
      }
      j2._turno = 2;

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

void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo){
  for(int x = posX; x < posX+ancho; x++){
    for(int y = posY; y < posY+alto; y++){
      rlutil::locate(x, y);
      cout << fondo;
    }
  }
}

void dibujarReversoCarta(int posX, int posY){
  rlutil::setColor(rlutil::WHITE);
  rlutil::setBackgroundColor(rlutil::LIGHTRED);
  dibujarRectangulo(posX,posY,5,3, 176);
}

void dibujarNumero(string num, int puntaje, int posX, int posY){
  rlutil::locate(posX, posY);
  cout << num;

  rlutil::locate(posX+5-num.size(), posY+2);
  cout << num;

  rlutil::setBackgroundColor(rlutil::GREEN);
  rlutil::setColor(rlutil::BLACK);
  rlutil::locate(posX, posY+3);
  (puntaje == 0) ? cout << "S/P" : cout << puntaje << " pt";
}

void dibujarCarta(string num, int puntaje, char palo, int posX, int posY){///dibuja Rectangulo y el Numero
  rlutil::setColor(rlutil::WHITE);
  dibujarRectangulo(posX,posY,5,3, 219);

  // Determinar color del palo (tamb se usa para el num) y fondo blanco
  rlutil::setBackgroundColor(rlutil::WHITE);
  rlutil::setColor((palo == 3 || palo == 4) ? rlutil::BLUE : rlutil::BLACK);
  rlutil::locate(posX+2, posY+1);
  cout << palo;

  //uso el color del palo para el num y pongo fondo blanco para el num
  rlutil::setBackgroundColor(rlutil::WHITE);
  dibujarNumero(num, puntaje, posX, posY);
}

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

void tiradaDeCartas(Carta vMazoFrancesa[], Figura vMazoFigura[]){
  //int palos[] = {3,4,5,6}; //4 diamante, 6 pica, 3 corazon, 5 trebol
  int index = 0;
  bool banderaEmbaucadora = false;

  for(int k = 1; k <=2; k++){//dibuja la carta dada vuelta y la gira
     for(int i = 1; i <=4; i ++){ //i es la fila
      for(int j=1; j <= 5; j++){ //j es la col
        if(k == 1){
          dibujarReversoCarta(j*8, i*6);//Reverso de Mazo Francesa
          if(i == 4 && j == 5)banderaEmbaucadora = true;
            if(banderaEmbaucadora){
              for(int z = 1; z <= 4; z++){//5*8 es la 5ta fila y el z es la col
                dibujarReversoCarta((z*8)+4, (5*6)-1);//Reverso de Mazo Embaucadora
              }
            }
        }else{
          banderaEmbaucadora = false;
          dibujarCarta(vMazoFrancesa[index]._valor, vMazoFrancesa[index]._puntaje, obtenerPalo(vMazoFrancesa,index), j*8, i*6);
          index ++;
          rlutil::msleep(25);
          if(i == 4 && j == 5)banderaEmbaucadora = true;
            if(banderaEmbaucadora){
              index = 0;
              for(int z = 1; z <= 4; z++){//5*8 es la 5ta fila y el z es la col
                dibujarCarta("E", 0,obtenerPalo(vMazoFigura, index++), (z*8)+4, (5*6)-1);
              }
            }

        }
      }
    }
  }
}

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
  cout << endl << "+-----------------+" << endl;
  cout << "|Mezclando el mazo|" << endl;
  cout << "+-----------------+" << endl;

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
   //rlutil::setBackgroundColor(rlutil::BLACK);
}


void repartirCartas(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]){

  for (int x = 0; x < 10; x++) { // reparto las cartas de 0 al 9
    if (x % 2 == 0) { // Numero par es jugador 1
      j1._mano[x/2] = vMazoFrancesa[x];
    }else{ // Numero impar es jugador 2
      j2._mano[x/2] = vMazoFrancesa[x];
    }
  }
}

/*void ronda1(Jugador &j1, Jugador &j2, Carta vMazoFrancesa[], Figura vMazoFigura[]){
  repartirCartas(j1, j2, vMazoFrancesa, vMazoFigura);

  // Posiciona y muestra el nombre y puntaje del jugador 1
  rlutil::setBackgroundColor(rlutil::BLACK);
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(1, 6);
  cout << j1._nombre << " (" << j1._puntaje << " puntos)" << endl;

  // Dibuja las cartas del jugador 1
  for(int j = 1; j <= 5; j ++){
    dibujarCarta(j1._mano[j-1]._valor, obtenerPalo(j1._mano, j-1), j*6, 8);
  }

  // Posiciona y muestra el nombre y puntaje del jugador 2
  rlutil::setBackgroundColor(rlutil::BLACK);
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(1, 12);
  cout << j2._nombre << " (" << j2._puntaje << " puntos)" << endl;

  // Dibuja las cartas del jugador 2
  for (int j = 0; j < 5; j++) {
    dibujarCarta(j2._mano[j]._valor, obtenerPalo(j2._mano, j), (j + 1)*6, 14);
  }

  dibujarCarta("E", obtenerPalo(vMazoFigura, 0), 37, 11);//Figura embaucadora = vMazoFigura[0];



  rlutil::locate(1, 20);
  system("pause");

}*/





void desarrolloPartida(Jugador &j1, Jugador &j2, Carta vMazo[], Figura vMazoFigura[]){

  for(int ronda = 1; ronda <=3; ronda++){
    switch(ronda)
    {
      case 1:
        //ronda1(j1, j2, vMazo, vMazoFigura);
        break;
      case 2:
        //ronda2(j1, j2, vMazo, vMazoFigura);
        break;
      case 3:
        //ronda3(j1, j2, vMazo, vMazoFigura);
        break;


    }
  }
}








