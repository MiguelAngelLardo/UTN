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



void body() {
    //texto que sale y calculo de la mitad responsiva y del texto responsivo
    string menuTexto = "INGRESE UNA OPCION\n\nJUGAR\nREGLAS\nESTADISTICAS\nCREDITOS\nCONTACTO\nSALIR";

/*
       int anchoMax = anchoMaxletras(menuTexto) + 20; // Asegurarse de que el ancho sea suficiente
    int altoMax = altoMaxFilas(menuTexto); // Ajustar la altura para incluir todas las filas
    int posX = rlutil::tcols() / 2 - anchoMax / 2;
    int posY = rlutil::trows() / 2 - altoMax / 2;
    cout << "ancho consol: " << rlutil::tcols() << " - alto consol: " << rlutil::trows()
         << " - Ancho Texto: " << anchoMax << " - alto Texto: " << altoMax << endl;
    cout <<"pos X " << posX << " pos Y " << posY << endl;//55 13
    cout << "123456789112345678921234567893123456789412345678951234567896123456789"
         << "712345678981234567899123456789C12345678911";*/

    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    mostrarMensaje(menuTexto,-1,-1,10,3,18,4);//padding der es((paddingIzq*2)-2), paddingInf es + 1 del sup

}

void footer(){
  string menuTexto1 = "Programar compulsivamente es perjudicial para la salud";
  string menuTexto2 = "TODOS LOS DERECHOS RESERVADOS";

  rlutil::setBackgroundColor(rlutil::BLUE);
  mostrarMensaje(menuTexto1, 25, -1, 0, 0, -2, -1, false);
  mostrarMensaje(menuTexto2, 27, -1, 0, 0, -3, -1, false);
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

void dibujarCorazon2(int posX = 10, int posY = 10){
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

void dibujarCorazon(int posX = 10, int posY = 10){
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

void dibujarDiamante(int posX = 40, int posY = 9) {
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

void dibujarJoker(int posX = 20, int posY = 20) {
    // CENTRO
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 0, posY + 0); cout << (char)219;

    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 0, posY + 1); cout << (char)220;
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 0, posY + 4); cout << (char)223;

    // DERECHA
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 1, posY + 0); cout << (char)219;

    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 1, posY + 1); cout << (char)220;
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 1, posY + 2); cout << (char)223;
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(posX + 1, posY + 4); cout << (char)223;



}


void mostrarMenu(){
/*
    dibujarCorazon(10, 10);
    dibujarCorazon(111, 10);
    dibujarPica(29, 9);
    dibujarPica(91, 9);
    dibujarTrebol(10, 16);
    dibujarTrebol(111, 16);
    dibujarDiamante(29, 17);
    dibujarDiamante(91, 17);*/
dibujarJoker();


    //dibujarCorazon1();
    dibujarCartasResponsivasHeader();
    body();
    footer();

  rlutil::locate(1, 28);
}













