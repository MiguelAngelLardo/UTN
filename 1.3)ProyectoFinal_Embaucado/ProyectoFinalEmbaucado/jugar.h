#pragma once

void jugar();
void cargarNombre(Jugador &j1, Jugador &j2);




///.CPP
using namespace std;

void jugar(){
  Jugador jugador1, jugador2;

  cargarNombre(jugador1, jugador2);


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

    }while(confirmacion != 's' && confirmacion != 'S');

}
