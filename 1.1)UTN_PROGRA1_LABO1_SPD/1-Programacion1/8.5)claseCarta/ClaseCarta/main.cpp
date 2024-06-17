#include <iostream>
#include "rlutil.h"

using namespace std;

///CARTAS
void tiradaDeCartas();
void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo = 219);
void dibujarReversoCarta(int posX, int posY);
std::string obtenerNumeroCarta(int numero);
void dibujarCarta(std::string num, char palo, int posX, int posY);  // Cambié el tipo de palo a int para el ejemplo

///TEXTO
void dibujarTextoCentrado(std::string texto, int fila = 2);
void pintarFila(int fila);
int contarEnters(std::string texto);
int filaMaxima(std::string texto);

void mostrarMensaje(std::string texto);



int main()
{
    ///3 funciones basicas del main
    //srand(time(0));
    rlutil::hidecursor();
    rlutil::saveDefaultColor();;

    ///fondo verde
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::cls();
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
    pintarFila(1); pintarFila(2); pintarFila(3);
    dibujarTextoCentrado("Jugar compulsivamente y C++ pueden ser perjudicial para la salud");



    tiradaDeCartas();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    mostrarMensaje("-- GANASTE --\n"
                   "\n"
                   "Espero que disfrutes del juego.\n"
                   "Nos vemos en la proxima jugada :)\n"
                   "\n"
                   "[S]salir [C]ontinuar");
    char opcion = rlutil::getkey();
    if(opcion == 'S' || opcion == 's'){
       mostrarMensaje("SALISTE!");
    }else{
      mostrarMensaje("CONTINUASTE!");
    }

    rlutil::anykey();
    rlutil::locate(1,25);
    return 0;
}

void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo){
  for(int x = posX; x < posX+ancho; x++){
    for(int y = posY; y < posY+alto; y++){
      rlutil::locate(x, y);
      cout << fondo;
    }
  }
}

void dibujarNumero(string num, int posX, int posY){
  rlutil::locate(posX, posY);
  cout << num;

  rlutil::locate(posX+5-num.size(), posY+2);
  cout << num;
}

void dibujarReversoCarta(int posX, int posY){
  rlutil::setColor(rlutil::WHITE);
  rlutil::setBackgroundColor(rlutil::LIGHTRED);
  dibujarRectangulo(posX,posY,5,3, 176);
}

///usar el rectangulo y el numero
void dibujarCarta(string num, char palo, int posX, int posY){
  rlutil::setColor(rlutil::WHITE);
  dibujarRectangulo(posX,posY,5,3);

  rlutil::setColor((palo == 3 || palo == 4) ? rlutil::BLUE : rlutil::BLACK);

  rlutil::setBackgroundColor(rlutil::WHITE); // Establecer color de fondo blanco
  dibujarNumero(num, posX, posY);
  rlutil::locate(posX+2, posY+1);
  cout << palo;

}

string obtenerNumeroCarta(int numero){

   string cartas[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };

  return cartas[numero-1];

  // switch(numero)
  // {
  //   case 1:
  //     return "A";
  //     break;
  //   case 11:
  //     return "J";
  //     break;
  //   case 12:
  //     return "Q";
  //     break;
  //   case 13:
  //     return "K";
  //     break;

  //   default:
  //     return to_string(numero);
  // }
}

void tiradaDeCartas(){//4 diamante, 6 pica, 3 corazon, 5 trebol
  int palos[] = {3,4,5,6};

  for(int k = 1; k <=2; k++){//dibuja la carta dada vuelta y la gira
     for(int i = 5; i <=20; i +=5){ //i es la fila
      for(int j=1; j <=13; j++){ //j es la col
        if(k == 1){
          dibujarReversoCarta(j*8, i);
        }else{
          dibujarCarta(obtenerNumeroCarta(j), (char)palos[(i/5)-1], j*8,i);
            rlutil::msleep(25);
        }
      }
    }
  }

}


void dibujarTextoCentrado(string texto, int fila){
  int posX = (rlutil::tcols()/2) - (texto.size()/2);
  rlutil::locate(posX,fila);
  cout << texto;
}

void pintarFila(int fila){
  int tamCol = rlutil::tcols();
  for(int x = 1; x <= tamCol; x++){
    rlutil::locate(x, fila);
    cout << " ";
  }
}

int contarEnters(string texto){
  int cantidad = 0;
  for(char letra : texto){
    if(letra == '\n'){
      cantidad ++;
    }
  }
  return cantidad; //me da la cantidad de lienas
}

int filaMaxima(string texto){
  int cantidad = 0;
  int cantidadMaxima = 0;
  for(char letra : texto){
    cantidad ++;
    if(letra == '\n'){
      if(cantidad > cantidadMaxima){
        cantidadMaxima = cantidad;
      }
      cantidad = 0;
    }
  }

  if(cantidad > cantidadMaxima){
    cantidadMaxima = cantidad;
  }

  return cantidadMaxima; //me da la cantidad de lienas
}


void mostrarMensaje(string texto){
  int lineas = contarEnters(texto)+1;
  int columnas = filaMaxima(texto);
  int posXCentrado = (rlutil::tcols()/2) - (columnas/2);
  int posYCentrado =  rlutil::trows()/2 - (lineas/2);


  //3 por que es 1 arriba, el texto y el de abajo
  dibujarRectangulo(posXCentrado-2, posYCentrado-1, columnas+4, lineas+2, ' ');
  rlutil::locate(posXCentrado,posYCentrado);

  int posInicial = 0;
  int posFinal = 0;
  for(int i = 1; i <= lineas; i ++){
    posFinal = texto.find('\n', posInicial);
    dibujarTextoCentrado(texto.substr(posInicial, posFinal-posInicial), posYCentrado +i -1);
    posInicial = posFinal +1;
  }
}








