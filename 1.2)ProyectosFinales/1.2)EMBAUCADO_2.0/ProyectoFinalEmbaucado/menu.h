#pragma once
#include <cstring> //para strlen
#include "jugar.h"
#include "textoResponsivo.h"


//calculo de cartas responsivas
void dibujarCartasResponsivasHeader(){
  // Letras de "EMBAUCADO"
  char vLetras[] = {'E', 'M', 'B', 'A', 'U', 'C', 'A', 'D', 'O', 'S'};
  int contCartas = strlen(vLetras);
  int anchoPantalla = rlutil::tcols();
  int altoPantalla = rlutil::trows();
  int anchoCarta = 5;
  int altoCarta = 3;
  int margenIzquierdo = 5;
  int margenDerecho = 5;
   // Calculamos el espacio entre las cartas
    int espacioEntreCartas = (anchoPantalla - margenIzquierdo - margenDerecho - (contCartas * anchoCarta)) / (contCartas - 1);

    // Si hay algún espacio sobrante, lo distribuimos en los márgenes
    int espacioSobrante = (anchoPantalla - margenIzquierdo - margenDerecho - (contCartas * anchoCarta)) % (contCartas - 1);
    margenIzquierdo += (espacioSobrante / 2) + 1; // Añadimos 1 espacio extra al margen izquierdo
    margenDerecho += (espacioSobrante / 2) - 1;  // Quitamos 1 espacio al margen derecho

    int posY = 3; // Posición Y fija

    // Dibujar cartas con letras
    for (int i = 0; i < contCartas; i++) {
        int posX = margenIzquierdo + i * (anchoCarta + espacioEntreCartas);
        string letraStr(1, vLetras[i]); // el 1 lo que hace es decirle que repite 1 vez el segundo parámetro
        dibujarCarta(letraStr, -2, 169, posX, posY); // le paso -2 así no hace nada con el número
    }
}
/*
void dibujarRectanguloMenu(int posX, int posY, int ancho, int alto, char relleno) {
  for(int i = 0; i < alto;i ++){
    rlutil::locate(posX, posY+i);
    for(int j = 0; j < ancho; j++){
      cout << relleno;
    }
  }
}
*/



void body() {
    //texto que sale y calculo de la mitad responsiva y del texto responsivo
    string menuTexto = "Ganaste!\nHola";
    int anchoMax = anchoMaxletras(menuTexto) + 20; // Asegurarse de que el ancho sea suficiente
    int altoMax = altoMaxFilas(menuTexto); // Ajustar la altura para incluir todas las filas
    int posX = rlutil::tcols() / 2 - anchoMax / 2;
    int posY = rlutil::trows() / 2 - altoMax / 2;

    cout << "ancho consol: " << rlutil::tcols() << " - alto consol: " << rlutil::trows()
         << " - Ancho Texto: " << anchoMax << " - alto Texto: " << altoMax << endl;
    cout <<"pos X " << posX << " pos Y " << posY << endl;//55 13
    cout << "123456789112345678921234567893123456789412345678951234567896123456789"
         << "712345678981234567899123456789C12345678911";

    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(posX, posY);
    cout << (char)201;//angulo supero izquierdo ╔ , a partir de aca inicia el for
    for (int i = 0; i < anchoMax; ++i) cout << (char)205; //═══════════ el 1er 205 se inicia posX+1 despues del 201
    cout << (char)187; //╗

    mostrarMensaje(menuTexto);
   /*
    cout << "h";
    istringstream lineaEditada(menuTexto); //istringstream me lee como si fuera getline(cin, linea) pero hardcodeado
    string linea;
    while (getline(lineaEditada, linea)){ //devuelve false cuando no hay mas lineas
      posY++;//uno mas abajo del techo
      rlutil::locate(posX, posY);//posX idem al cout << (char)201 ║ con un Y+1
      cout << (char)186;
      cout << linea;*/
      //rlutil::locate(posX/*55*/ + anchoMax/*11*/ +1, posY);//sumo 1 para que sea al terminar el texto
      //cout << (char)186;  // Línea vertical derecha ║
    //}
  /*
    posY ++;
    rlutil::locate(posX, posY);
    cout << (char)200;  // Esquina inferior izquierda ╚
    for (int i = 0; i < anchoMax; ++i) cout << (char)205; // Línea horizontal inferior ═
    cout << (char)188;  // Esquina inferior derecha ╝
    cout << "hola; ";*/
}





void dibujarDiamante1(int posX = 10, int posY = 10, int altura = 9) {
    rlutil::setColor(rlutil::RED); // Establecer color rojo para el diamante

    int mitad = altura / 2;

    // Dibujar el diamante completo
    for (int i = 0; i < altura; ++i) {                                                     //0 1 2 3 4 5 6 7 8
      int espacios = abs(mitad - i); // abs asegura que el resultado sea siempre positivo => 4 3 2 1 0 1 2 3 4
      int caracteres = altura - 2 * espacios; // 9(-2*4)=1   9(-2*3)= 3  9(-2*2)=5 9(-2*1)=7  9(-2*0)=9

      rlutil::locate(posX + espacios, posY + i);
      //vuelta 0 => rlutil::locate(10 + 4, 10 + 0); => rlutil::locate(14, 10)
      //vuelta 1 => rlutil::locate(10 + 3, 10 + 1); => rlutil::locate(13, 11)
      //vuelta 2 => rlutil::locate(10 + 2, 10 + 2); => rlutil::locate(12, 12)
      // rlutil::locate(11, 13) - rlutil::locate(10, 14) - rlutil::locate(11, 15) - rlutil::locate(12, 16) - rlutil::locate(13, 17)- rlutil::locate(14, 18)

      // Imprimir caracteres (█)
      for (int j = 0; j < caracteres; j++){//i=0 es j<1   i=1 es j<3     i=2 es j<5
        cout << (char)219;
      }
    }

    rlutil::setColor(rlutil::WHITE); // Restaurar color blanco al finalizar
}


void dibujarPica(int posX = 30, int posY = 9) {
  rlutil::setColor(rlutil::BLACK); // Establecer color negro para el trébol

  //centro del tallo
   rlutil::locate(posX + 0, posY + 0); cout << (char)219; rlutil::locate(posX + 0, posY + 1); cout << (char)219; rlutil::locate(posX + 0, posY + 2); cout << (char)219; rlutil::locate(posX + 0, posY + 3); cout << (char)219; rlutil::locate(posX + 0, posY + 4); cout << (char)219;

  // Parte derecha del trébol (ya proporcionada)
  rlutil::locate(posX + 1, posY + 0); cout << (char)220; rlutil::locate(posX + 1, posY + 1); cout << (char)219; rlutil::locate(posX + 1, posY + 2); cout << (char)219; rlutil::locate(posX + 1, posY + 3); cout << (char)223;
  rlutil::locate(posX + 2, posY + 1); cout << (char)219; rlutil::locate(posX + 2, posY + 2); cout << (char)219; rlutil::locate(posX + 2, posY + 3); cout << (char)219;
  rlutil::locate(posX + 3, posY + 1); cout << (char)220; rlutil::locate(posX + 3, posY + 2); cout << (char)219; rlutil::locate(posX + 3, posY + 3); cout << (char)219;
  rlutil::locate(posX + 4, posY + 2); cout << (char)219; rlutil::locate(posX + 4, posY + 3); cout << (char)219;
  rlutil::locate(posX + 5, posY + 2); cout << (char)220; rlutil::locate(posX + 5, posY + 3); cout << (char)223;

  // Parte izquierda del trébol (simétrica)
  rlutil::locate(posX - 0, posY + 0); cout << (char)219; rlutil::locate(posX - 0, posY + 1); cout << (char)219; rlutil::locate(posX - 0, posY + 2); cout << (char)219; rlutil::locate(posX - 0, posY + 3); cout << (char)219; rlutil::locate(posX - 0, posY + 4); cout << (char)219;
  rlutil::locate(posX - 1, posY + 0); cout << (char)220; rlutil::locate(posX - 1, posY + 1); cout << (char)219; rlutil::locate(posX - 1, posY + 2); cout << (char)219; rlutil::locate(posX - 1, posY + 3); cout << (char)223;
  rlutil::locate(posX - 2, posY + 1); cout << (char)219; rlutil::locate(posX - 2, posY + 2); cout << (char)219; rlutil::locate(posX - 2, posY + 3); cout << (char)219;
  rlutil::locate(posX - 3, posY + 1); cout << (char)220; rlutil::locate(posX - 3, posY + 2); cout << (char)219; rlutil::locate(posX - 3, posY + 3); cout << (char)219;
  rlutil::locate(posX - 4, posY + 2); cout << (char)219; rlutil::locate(posX - 4, posY + 3); cout << (char)219;
  rlutil::locate(posX - 5, posY + 2); cout << (char)220; rlutil::locate(posX - 5, posY + 3); cout << (char)223;

  //base del tallo
  rlutil::locate(posX + 1, posY + 4); cout << (char)220;
  rlutil::locate(posX - 1, posY + 4); cout << (char)220;
  rlutil::locate(posX + 1, posY + 5); cout << (char)223;
  rlutil::locate(posX - 1, posY + 5); cout << (char)223;
  rlutil::locate(posX + 2, posY + 5); cout << (char)223;
  rlutil::locate(posX - 2, posY + 5); cout << (char)223;

  rlutil::setColor(rlutil::WHITE); // Restaurar color blanco al finalizar
}

void dibujarTrebol(int posX = 20, int posY = 9) {
  rlutil::setColor(rlutil::BLACK); // Establecer color negro para el trébol

  //centro del tallo
  rlutil::locate(posX + 0, posY + 0); cout << (char)219; rlutil::locate(posX + 0, posY + 1);cout << (char)219;rlutil::locate(posX + 0, posY + 2); cout << (char)219;rlutil::locate(posX + 0, posY + 3); cout << (char)219;rlutil::locate(posX + 0, posY + 4); cout << (char)219;

  //mitad derecha flor del centro
  rlutil::locate(posX + 1, posY + 0); cout << (char)219;rlutil::locate(posX + 1, posY + 1); cout << (char)219;
  rlutil::locate(posX + 2, posY + 0); cout << (char)220;rlutil::locate(posX + 2, posY + 1); cout << (char)223;
  //mitad izquierda flor del centro
  rlutil::locate(posX - 1, posY + 0); cout << (char)219;rlutil::locate(posX - 1, posY + 1); cout << (char)219;
  rlutil::locate(posX - 2, posY + 0); cout << (char)220;rlutil::locate(posX - 2, posY + 1); cout << (char)223;

  //centro tallo
  rlutil::locate(posX + 1, posY + 2); cout << (char)220;//der
  rlutil::locate(posX - 1, posY + 2); cout << (char)220;//izq

  //flor derecha
  rlutil::locate(posX + 2, posY + 2); cout << (char)219;rlutil::locate(posX + 2, posY + 3); cout << (char)223;
  rlutil::locate(posX + 3, posY + 1); cout << (char)220;rlutil::locate(posX + 3, posY + 2); cout << (char)219;rlutil::locate(posX + 3, posY + 3); cout << (char)219;
  rlutil::locate(posX + 4, posY + 1); cout << (char)220;rlutil::locate(posX + 4, posY + 2); cout << (char)219;rlutil::locate(posX + 4, posY + 3); cout << (char)219;
  rlutil::locate(posX + 5, posY + 2); cout << (char)219;rlutil::locate(posX + 5, posY + 3); cout << (char)223;

  //flor izquierda
  rlutil::locate(posX - 2, posY + 2); cout << (char)219;rlutil::locate(posX - 2, posY + 3); cout << (char)223;
  rlutil::locate(posX - 3, posY + 1); cout << (char)220;rlutil::locate(posX - 3, posY + 2); cout << (char)219;rlutil::locate(posX - 3, posY + 3); cout << (char)219;
  rlutil::locate(posX - 4, posY + 1); cout << (char)220;rlutil::locate(posX - 4, posY + 2); cout << (char)219;rlutil::locate(posX - 4, posY + 3); cout << (char)219;
  rlutil::locate(posX - 5, posY + 2); cout << (char)219;rlutil::locate(posX - 5, posY + 3); cout << (char)223;

  //base del tallo
  rlutil::locate(posX + 1, posY + 4); cout << (char)220;//der
  rlutil::locate(posX + 1, posY + 5); cout << (char)223;//der
  rlutil::locate(posX + 2, posY + 5); cout << (char)223;//der
  rlutil::locate(posX - 1, posY + 4); cout << (char)220;//izq
  rlutil::locate(posX - 1, posY + 5); cout << (char)223;//der
  rlutil::locate(posX - 2, posY + 5); cout << (char)223;//der


}

void dibujarCorazon1(int posX = 10, int posY = 10){
  rlutil::setColor(rlutil::RED); // Establecer color negro para el trébol

  //centro del corazon
  rlutil::locate(posX + 0, posY + 0); cout << (char)219; rlutil::locate(posX + 0, posY + 1); cout << (char)219;rlutil::locate(posX + 0, posY + 2); cout << (char)219;rlutil::locate(posX + 0, posY + 3); cout << (char)219;rlutil::locate(posX + 0, posY + 4); cout << (char)223;
  rlutil::locate(posX + 1, posY + 0); cout << (char)219; rlutil::locate(posX + 1, posY + 1); cout << (char)219;rlutil::locate(posX + 1, posY + 2); cout << (char)219;rlutil::locate(posX + 1, posY + 3); cout << (char)219;rlutil::locate(posX + 1, posY + 4); cout << (char)223;

  //Ala derecha
  rlutil::locate(posX + 2, posY  -1); cout << (char)220; rlutil::locate(posX + 2, posY + 0); cout << (char)219;rlutil::locate(posX + 2, posY + 1); cout << (char)219;rlutil::locate(posX + 2, posY + 2); cout << (char)219;rlutil::locate(posX + 2, posY + 3); cout << (char)219;
  rlutil::locate(posX + 3, posY  -1); cout << (char)219; rlutil::locate(posX + 3, posY + 0); cout << (char)219;rlutil::locate(posX + 3, posY + 1); cout << (char)219;rlutil::locate(posX + 3, posY + 2); cout << (char)219;rlutil::locate(posX + 3, posY + 3); cout << (char)223;
  rlutil::locate(posX + 4, posY  -1); cout << (char)219; rlutil::locate(posX + 4, posY + 0); cout << (char)219;rlutil::locate(posX + 4, posY + 1); cout << (char)219;rlutil::locate(posX + 4, posY + 2); cout << (char)219;
  rlutil::locate(posX + 5, posY  -1); cout << (char)219; rlutil::locate(posX + 5, posY + 0); cout << (char)219;rlutil::locate(posX + 5, posY + 1); cout << (char)219;rlutil::locate(posX + 5, posY + 2); cout << (char)223;
  rlutil::locate(posX + 6, posY  -1); cout << (char)220; rlutil::locate(posX + 6, posY + 0); cout << (char)219;rlutil::locate(posX + 6, posY + 1); cout << (char)219;

  //Ala izq
  rlutil::locate(posX - 1, posY  -1); cout << (char)220; rlutil::locate(posX - 1, posY + 0); cout << (char)219; rlutil::locate(posX - 1, posY + 1); cout << (char)219; rlutil::locate(posX - 1, posY + 2); cout << (char)219;rlutil::locate(posX - 1, posY + 3); cout << (char)219;
  rlutil::locate(posX - 2, posY  -1); cout << (char)219; rlutil::locate(posX - 2, posY + 0); cout << (char)219; rlutil::locate(posX - 2, posY + 1); cout << (char)219; rlutil::locate(posX - 2, posY + 2); cout << (char)219; rlutil::locate(posX - 2, posY + 3); cout << (char)223;
  rlutil::locate(posX - 3, posY  -1); cout << (char)219; rlutil::locate(posX - 3, posY + 0); cout << (char)219; rlutil::locate(posX - 3, posY + 1); cout << (char)219; rlutil::locate(posX - 3, posY + 2); cout << (char)219;
  rlutil::locate(posX - 4, posY  -1); cout << (char)219; rlutil::locate(posX - 4, posY + 0); cout << (char)219; rlutil::locate(posX - 4, posY + 1); cout << (char)219; rlutil::locate(posX - 4, posY + 2); cout << (char)223;
  rlutil::locate(posX - 5, posY  -1); cout << (char)220; rlutil::locate(posX - 5, posY + 0); cout << (char)219; rlutil::locate(posX - 5, posY + 1); cout << (char)219;

  rlutil::setColor(rlutil::WHITE); // Restaurar color blanco al finalizar

}

void dibujarCorazon2(int posX = 10, int posY = 10){
  rlutil::setColor(rlutil::RED); // Establecer color negro para el trébol

  //centro del corazon
  rlutil::locate(posX + 0, posY + 0); cout << (char)219; rlutil::locate(posX + 0, posY + 1); cout << (char)219; rlutil::locate(posX + 0, posY + 2); cout << (char)219; rlutil::locate(posX + 0, posY + 3); cout << (char)219;

  //Ala derecha
  rlutil::locate(posX + 1, posY - 1); cout << (char)220; rlutil::locate(posX + 1, posY + 0); cout << (char)219; rlutil::locate(posX + 1, posY + 1); cout << (char)219; rlutil::locate(posX + 1, posY + 2); cout << (char)219; rlutil::locate(posX + 1, posY + 3); cout << (char)223;
  rlutil::locate(posX + 2, posY - 1); cout << (char)219; rlutil::locate(posX + 2, posY + 0); cout << (char)219; rlutil::locate(posX + 2, posY + 1); cout << (char)219; rlutil::locate(posX + 2, posY + 2); cout << (char)219;
  rlutil::locate(posX + 3, posY - 1); cout << (char)219; rlutil::locate(posX + 3, posY + 0); cout << (char)219; rlutil::locate(posX + 3, posY + 1); cout << (char)219; rlutil::locate(posX + 3, posY + 2); cout << (char)223;
  rlutil::locate(posX + 4, posY - 1); cout << (char)220; rlutil::locate(posX + 4, posY + 0); cout << (char)219; rlutil::locate(posX + 4, posY + 1); cout << (char)219;
  rlutil::locate(posX + 5, posY + 0); cout << (char)219; rlutil::locate(posX + 5, posY + 1); cout << (char)223;


  //Ala izq
  rlutil::locate(posX - 1, posY - 1); cout << (char)220; rlutil::locate(posX - 1, posY + 0); cout << (char)219; rlutil::locate(posX - 1, posY + 1); cout << (char)219; rlutil::locate(posX - 1, posY + 2); cout << (char)219; rlutil::locate(posX - 1, posY + 3); cout << (char)223;
  rlutil::locate(posX - 2, posY - 1); cout << (char)219; rlutil::locate(posX - 2, posY + 0); cout << (char)219; rlutil::locate(posX - 2, posY + 1); cout << (char)219; rlutil::locate(posX - 2, posY + 2); cout << (char)219;
  rlutil::locate(posX - 3, posY - 1); cout << (char)219; rlutil::locate(posX - 3, posY + 0); cout << (char)219; rlutil::locate(posX - 3, posY + 1); cout << (char)219; rlutil::locate(posX - 3, posY + 2); cout << (char)223;
  rlutil::locate(posX - 4, posY - 1); cout << (char)220; rlutil::locate(posX - 4, posY + 0); cout << (char)219; rlutil::locate(posX - 4, posY + 1); cout << (char)219;
  rlutil::locate(posX - 5, posY + 0); cout << (char)219; rlutil::locate(posX - 5, posY + 1); cout << (char)223;


  rlutil::setColor(rlutil::WHITE); // Restaurar color blanco al finalizar

}

void dibujarDiamante2(int posX = 40, int posY = 9) {
  rlutil::setColor(rlutil::RED); // Establecer color negro para el trébol

  //centro de diamante
  rlutil::locate(posX + 0, posY - 1); cout << (char)220; rlutil::locate(posX + 0, posY + 0); cout << (char)219; rlutil::locate(posX + 0, posY + 1); cout << (char)219; rlutil::locate(posX + 0, posY + 2); cout << (char)219; rlutil::locate(posX + 0, posY + 3); cout << (char)219; rlutil::locate(posX + 0, posY + 4); cout << (char)219;

  //mitad derecha
  rlutil::locate(posX + 1, posY + 0); cout << (char)219; rlutil::locate(posX + 1, posY + 1); cout << (char)219; rlutil::locate(posX + 1, posY + 2); cout << (char)219; rlutil::locate(posX + 1, posY + 3); cout << (char)219; rlutil::locate(posX + 1, posY + 4); cout << (char)223;
  rlutil::locate(posX + 2, posY + 1); cout << (char)219; rlutil::locate(posX + 2, posY + 2); cout << (char)219; rlutil::locate(posX + 2, posY + 3); cout << (char)223;
  rlutil::locate(posX + 3, posY + 1); cout << (char)220; rlutil::locate(posX + 3, posY + 2); cout << (char)219;
  rlutil::locate(posX + 4, posY + 2); cout << (char)223;

  //mitad izquierda
  rlutil::locate(posX - 1, posY + 0); cout << (char)219; rlutil::locate(posX - 1, posY + 1); cout << (char)219; rlutil::locate(posX - 1, posY + 2); cout << (char)219; rlutil::locate(posX - 1, posY + 3); cout << (char)219; rlutil::locate(posX - 1, posY + 4); cout << (char)223;
  rlutil::locate(posX - 2, posY + 1); cout << (char)219; rlutil::locate(posX - 2, posY + 2); cout << (char)219; rlutil::locate(posX - 2, posY + 3); cout << (char)223;
  rlutil::locate(posX - 3, posY + 1); cout << (char)220; rlutil::locate(posX - 3, posY + 2); cout << (char)219;
  rlutil::locate(posX - 4, posY + 2); cout << (char)223;

}


void mostrarMenu(){

    dibujarDiamante2();
    dibujarPica();
    dibujarTrebol();
    dibujarCorazon2();
    //dibujarCorazon1();
    dibujarCartasResponsivasHeader();
    body();

  rlutil::locate(1, 28);
}













