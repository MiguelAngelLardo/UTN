#include <iostream>
#include <cstring>
#include <iomanip>//setw

using namespace std;

void cargarPuntos(int m[4][4], bool mVersus[4][4]);//firma, declaracion, prototipo
void mostrarTabla(int m[4][4], bool mVersus[4][4]);//firma, declaracion, prototipo
void reiniciarCampeonato(int m[4][4], bool mVersus[4][4]);

bool validarJugadores(int m[4][4], int &j1, int &j2, bool mVersus[4][4]);

void finDeJuego(int m[4][4], bool mVersus[4][4]);
void ganador(int m[4][4], bool mVersus[4][4]);
bool empatar(int vAcumPuntos[4], int maxPuntaje, bool vEmpate[4]);

int main(){
  int opcion;
  int mJugadoresPuntos[4][4] = {};
  bool mJugadoresGanadorPerdedor[4][4] = {};
  bool flagFinJuego;
  
  
  do{
    system("cls");
    cout << "1-Cargar Puntos" << endl;
    cout << "2-Mostrar Tabla" << endl;
    cout << "3-Reiniciar Campeonato" << endl;
    cout << "0-Cierra" << endl;
    cin >> opcion;
    system("cls");

    switch (opcion)
    {
      case 1:{    
        cargarPuntos(mJugadoresPuntos, mJugadoresGanadorPerdedor);
      }break;
      case 2:{
        mostrarTabla(mJugadoresPuntos, mJugadoresGanadorPerdedor);
        system("pause");
      }break;
      case 3:{
        reiniciarCampeonato(mJugadoresPuntos, mJugadoresGanadorPerdedor);
      }break;
      case 0:{
        cout << "Saliendo... Gracias por jugar al Torneo Relampago" << endl;
      }break;
      
      default:
        cout << "Opcion no valida" << endl;
        system("pause");
        break;
    }
    //determina quien gana
    if(opcion == 1 ) finDeJuego(mJugadoresPuntos, mJugadoresGanadorPerdedor);

  }while(opcion != 0);

  return 0;
}


void cargarPuntos(int m[4][4], bool mVersus[4][4]){
  int j1, j2, puntosJ1, puntosJ2;
  bool banderaJugRepe = false;//valida que no se repitan los jugadores
  cout << "1-Cargar Puntos" << endl;
  
  do{
    cout << "Ingrese el numero del primer jugador (1 al 4): ";
    cin >> j1;//1
    cout << "Ingrese el numero del segundo jugador (1 al 4): ";
    cin >> j2;
    

    if(j1 == j2){
      cout << endl << "ERROR! no pueden ser dos jugadores identicos...." << endl;
      system("pause");
      system("cls");
    }
  }while(j1 == j2);
  
  banderaJugRepe = validarJugadores(m, j1, j2, mVersus);
  
  if(!banderaJugRepe){
    do{
      cout << "Ingrese los puntos de j" << j1 << ": ";
      cin >> puntosJ1;//2
    
      cout << "Ingrese los puntos de j" << j2 << ": ";
      cin >> puntosJ2;//5
      if(puntosJ1 == puntosJ2) cout << endl << "No puede haber empate entre J" << j1 << " y J" << j2 << "..." << endl;

    }while(puntosJ1 == puntosJ2);
   

    m[j1-1][j2-1]+=puntosJ1;
    m[j2-1][j1-1]+=puntosJ2;

      //aca determino el ganador y el perdedor
    if(puntosJ1 > puntosJ2) {
      mVersus[j1-1][j2-1] = true;  // J1 ganó contra J2
      mVersus[j2-1][j1-1] = false; // J2 perdió contra J1
    }else{
      mVersus[j1-1][j2-1] = false; // J1 perdió contra J2
      mVersus[j2-1][j1-1] = true;  // J2 ganó contra J1
    }
  }
}


void mostrarTabla(int m[4][4], bool mVersus[4][4]) {
  cout << "Mostrar Tabla" << endl;
  // Encabezado de columnas
  for (int j = 0; j < 4; j++){//uso J por que solo me interesa esa FILA (pasa por columnas)
    cout << (j == 0 ? setw(5) : setw(3)) << "J" + to_string(j + 1);  
  }
  cout << endl;
  
  for (int i = 0; i < 4; i++) {
    cout << "J" << i+1; // Etiqueta de fila
    for (int j = 0; j < 4; j++) {
      (i == j) ? cout << setw(3) << "-" : cout << setw(3) << to_string(m[i][j]);
    }
    cout << endl;
  }
  cout << endl;

  // Encabezado de columnas
  cout << setw(5);  // Espacio para etiquetas de fila
  for (int j = 0; j < 4; j++) {
    cout << (j == 0 ? setw(5) : setw(3)) << "J" + to_string(j + 1);
  }

  cout << endl;

 // GANADORES Y PERDEDORES
 for (int i = 0; i < 4; i++) {
  cout << "J" << i + 1;  // Etiqueta de fila
  for (int j = 0; j < 4; j++) {
    if (i == j) {
      cout << setw(3) << "-";  // Diagonal
    } else {                 // si es TRUE muestra O, SINO SI ve si hay puntos
      cout << setw(3) << (mVersus[i][j] ? "O" : (m[i][j] > 0 ? "X" : " "));
    }
  }
  cout << endl;
 }  
 cout << endl;
}



void reiniciarCampeonato(int m[4][4], bool mVersus[4][4]){
  char opcion;
  cout << "Reiniciando Campeonato y la tabla de puntos" << endl;

  do{ 
    cout << "Aprete 'S' para resetar la tabla o 'N' para cancelar: ";
    cin >> opcion;
    if(opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n'){//0 * 1 * 1 * 1 = 0 
      cout << "Opcion no valida" << endl;
    }

  }while(opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');//0 * 1 * 1 * 1 = 0

  system("cls");
  if(opcion == 'S' || opcion == 's'){
    cout << "Tabla reiniciada" << endl;
    for(int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++)
      {
        m[i][j] = 0;
        mVersus[i][j] = false;
      }
    }
  }else{
    cout << "Tabla no reiniciada...volviendo al menu" << endl;
  } 
  system("pause");
}

                                      
bool validarJugadores(int m[4][4], int &j1, int &j2, bool mVersus[4][4]){
  int contador = 0;
  if(m[j1-1][j2-1] > 0){
    cout << endl << "El jugador J" << j1 << " ya jugo contra el jugador J" << j2 << "...Mire" << endl << endl;
    mostrarTabla(m, mVersus);

    for(int j = 0; j < 4; j++){
      if(m[j1-1][j] == 0 && j1 != j+1){// [j2-1][0] == 0 && j2 != j1 - J2 != j3 && j2 == j2
        contador++;
      }  
    }  
    
    if(contador == 0){
      cout << "Le digo mas !!! El jugador J" << j1 << " ya jugo contra todos los demas jugadores." << endl;
    }else if(contador > 0){
      cout << "El jugador J" << j1 << " aun no jugo contra el jugador ";
      for(int j = 0; j < 4; j++){
        if(m[j1-1][j] == 0 && j1 != j+1){// para que no cuente j1 y j1
          if(contador > 0){
            cout << "J" << j+1;
            contador --;
          }
          if(contador > 0){
            cout <<", ";
          }
        }//for
      }//if  
      cout << "." << endl;
    }
  
    cout << endl;
    system("pause");
    return true;
  }
}

void finDeJuego(int m[4][4], bool mVersus[4][4]){
  bool matrizCompleta = false;
  int contador = 0;
  for(int i = 0; i < 4; i ++){
    for(int j = 0; j < 4; j ++){
      if(m[i][j] == 0 && i != j){//para que no me cuente los 4 seros de j1 vs j1
        contador ++;
      }
    }
  }
  //si esta completa termina el juego
  if(contador == 0){
    matrizCompleta = true;
  }

  if(matrizCompleta){
    system("cls");
    cout <<endl << "La MATRIZ ESTA COMPLETA!" << endl;
    // system ("pause");
    // system("cls");
    ganador(m, mVersus); //LLAMA A FX GANADOR
  }   
}

void ganador(int m[4][4], bool mVersus[4][4]){
  int vAcumPuntos[4] = {};//acumula los puntos de J1, J2, J3 y J4
  int maximoPuntaje;
  bool hayEmpate[4] = {};
  bool emapte = false;

  //calcula los puntos de cada jugador
  for(int i = 0; i < 4; i ++){
    for(int j = 0; j < 4; j ++){
      if(i != j){//para que no me cuente los 4 ceros de j1 vs j1
        vAcumPuntos[i] += m[i][j];
      }
    }
  }

  //calcula el maximo
  int maxIndice = 0;
  for(int i = 1; i <4; i ++){
    if(vAcumPuntos[i] > vAcumPuntos[maxIndice]){
      maxIndice = i;
    }
  }
  maximoPuntaje = vAcumPuntos[maxIndice];
  
  mostrarTabla(m, mVersus);//muestra la tabla antes de mostrar si ganaron o empataron
  emapte = empatar(vAcumPuntos, maximoPuntaje, hayEmpate);//me dice si hay empate y entre quienes

  if(!emapte){
    cout << "TENEMOS UN GANADOR!!!" << endl;
    cout << "Jugador J" << maxIndice+1 << " con " << vAcumPuntos[maxIndice] << " puntos.";
  }else{
    cout << "TENEMOS UN EMPATE!!!" << endl;
    for(int i = 0; i < 4; i ++){
      if(hayEmpate[i]){
        cout << "Jugador J" << i+1 << " con " << vAcumPuntos[i] << " puntos." <<endl;
      }
    }

    cout << endl;
    system("pause");
    system("cls");

    for(int i = 0; i < 4; i ++){
      vAcumPuntos[i] = 0; //reinicia el acumulador asi lo uso para la cantidad de victorias
    }

    //calculo la cantidad de de victorias de los que empataron
    for (int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        if(mVersus[i][j] == true){
          vAcumPuntos[i] += mVersus[i][j];//reutilizo el acumulador de puntos, le guardo el TRUE/1 como 1
        }
      }  
    }
    //calcula el maximo
    maxIndice = 0;
    for(int i = 1; i <4; i ++){
      if(vAcumPuntos[i] > vAcumPuntos[maxIndice]) maxIndice = i;
    }
    
    maximoPuntaje = vAcumPuntos[maxIndice];

    cout << "VAMOS A DESEMPATAR!!!" << endl;
    mostrarTabla(m, mVersus);//muestra la tabla
    //muestro los que empataron y sus cantidades de victorias
    for(int i = 0; i < 4; i ++){
      if(hayEmpate[i]){
        cout << "Jugador J" << i+1 << " con " << vAcumPuntos[i] << " victorias." <<endl;
      }
    }  

   

    int contGanadores = 0;
    for (int i = 0; i < 4; i++){
      if(maximoPuntaje == vAcumPuntos[i]){
        contGanadores ++;
      }
    }

    cout << endl << "Tenemos " << contGanadores << (contGanadores == 1 ? " ganador " : " ganadores ") << "con " << maximoPuntaje << " victorias." << endl;
    cout << "Felicidades J";
    for(int i = 0; i < 4; i ++){
      if(maximoPuntaje == vAcumPuntos[i]){
        cout << i+1 << ".";
      }  
    }
  
  }//fin del else

  cout << endl << endl;
  system("pause"); 
  
}

bool empatar(int vAcumPuntos[4], int maxPuntaje, bool vEmpate[4]){//ver si asterisco va en east o west 
  int contadorEmpate = 0;
  for(int i = 0; i < 4; i ++){
    vEmpate[i] = (vAcumPuntos[i] == maxPuntaje);
    if(vEmpate[i] == true){
      contadorEmpate ++;
    }
  }

  return (contadorEmpate > 1); // Retorna true si hay empate, false si no
}



