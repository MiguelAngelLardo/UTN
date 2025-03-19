#pragma once

void crearDat(int tam){
  ArchivoNasa objArcNasa;
  cout << "Ingresa los datos de la Nasa" << endl;
  objArcNasa.crearArchivo(tam);

  ArchivoMision objArcMision;
  cout << "Ingresa los datos de la Mision" << endl;
  objArcMision.crearArchivo(tam);
}

void mostrarDat(){
  ArchivoNasa objArcNasa;
  cout << "Ingresa los datos de la Nasa" << endl;
  objArcNasa.mostrarArchivo();

  ArchivoMision objArcMision;
  cout << "Ingresa los datos de la Mision" << endl;
  objArcMision.mostrarArchivo();
}