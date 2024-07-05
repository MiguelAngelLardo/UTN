#pragma once

void dibujarTextoCentrado(string texto, int fila){
  int posX = rlutil::tcols() / 2 - texto.size() / 2;
  rlutil::locate(posX, fila);
  cout << texto;
}

int altoMaxFilas(string texto){ //me dice las filas (eje Y) maxima
  int cantidad = 0;
  for(char letra : texto){//for each -> me trae c/letra del texto
    if(letra == '\n'){//si hay enter es 1 fila
      cantidad ++;
    }
  }
  return cantidad; //me da la cantidad de lienas
}

int anchoMaxletras(string texto){//me dice el total de columnas (eje x) maximo
  int cont = 0;
  int cantidadMax = 0;
  for(char letra : texto){
    cont ++;
    if(letra == '\n'){
        cont --;//le quito el valor del \n que cuenta como 1
      if(cont > cantidadMax){
        cantidadMax = cont;
      }
      cont = 0;
    }
  }

  if(cont > cantidadMax){ //no hago cont -- por que no tendria \n
    cantidadMax = cont;
  }

  return cantidadMax; //me da la cantidad de lienas
}



// Función para mostrar un mensaje con fondo azul y centrado

void mostrarMensaje(string texto, int fila = -1, int columna = -1, int paddingIzq = 2, int paddingSup = 1, int paddingDer = 2, int paddingInf = 1){
    int filasMax = altoMaxFilas(texto) +1 ; // el +1 es por que si escribo 1 sola no habra enter
    cout << "filas max" << filasMax;
    int columnasMax = anchoMaxletras(texto);
    int posXCentrado = (rlutil::tcols() / 2) - (columnasMax / 2);
    int posYCentrado = (rlutil::trows() / 2) - (filasMax / 2);

    // Si se especifica una fila y columna, se ajusta la posición
    if (fila != -1) {
        posYCentrado = fila;
    }
    if (columna != -1) {
        posXCentrado = columna;
    }

    // Dibuja el rectángulo con fondo azul
    rlutil::setBackgroundColor(rlutil::BLUE);
    dibujarRectangulo(posXCentrado + (paddingIzq*-1), posYCentrado + (paddingSup*-1) , columnasMax + (paddingDer+2), filasMax + (paddingInf+1), ' ');

    // Dibuja el texto centrado
    int posInicial = 0;
    int posFinal = 0;
    for (int i = 1; i <= filasMax; i++) { // por cada linea busco donde esta el \n
      posFinal = texto.find('\n', posInicial); // empieza en cero y llega hasta la N(ej 13 char) cantidad de letras hasta el \n
      dibujarTextoCentrado(texto.substr(posInicial, posFinal - posInicial), posYCentrado + i -1);
      posInicial = posFinal + 1; // hace 13 char + 1
    }
    //find (buscame algo, desde TAL lado)
    //substr me da un string(donde quiero que empiece, hasta donde quiero que llegue)


    // Restablecer el color de fondo al valor predeterminado
    rlutil::setBackgroundColor(rlutil::GREEN);
}


