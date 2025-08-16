#pragma once

#include <iostream>
#include <cstdlib>
#include<cstring>

using namespace std; 

void cargarCadena(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

/*

Goles.dat
Código de partido
Minutos
Tiempo (1: 1º tiempo; 2: 2º tiempo)
Código de jugador, Tipo de gol (1: penal; 2: en contra; 3: juego)
Partidos.dat
Código de partido (char [5])
Código de equipo 1
Código de equipo 2
Fecha, Hora, Código de sede
Sedes.dat
Código de sede
Nombre ciudad, Nombre estadio
*/

class Pais{ //Clase pais
private:
  int codigoPais; //1 a 32  
  char nombrePais[30];
  char grupo[3];

public:
  int getCodigoPais(){return codigoPais;}
  const char *getNombrePais(){return nombrePais;}
  const char *getGrupo(){return grupo;}
  bool leerDeDisco(int);
  int contarRegistros();


  void cargar(){
    cout << "Ingrese el codigo del pais: "; cin >> codigoPais;
    cout << "Ingrese el nombre del pais: "; cargarCadena(nombrePais, 30);
    cout << "Ingrese el nombre del grupo: "; cargarCadena(grupo, 3);
  }

  void mostrar(){
    cout << "Codigo del pais: " << codigoPais << endl;
    cout << "Nombre del pais: " << nombrePais << endl;
    cout << "Nombre del grupo: " << grupo << endl;
  }

};

bool Pais::leerDeDisco(int pos){ //leer archivo
  FILE *p;
  p=fopen("paises.dat","rb");
  if(p==NULL)exit(1);
  fseek(p, sizeof *this*pos,0);
  bool leyo=fread(this, sizeof *this, 1, p);
  fclose(p);
  return leyo;
}

int Pais::contarRegistros(){   //cuantos registros tengo
  FILE *p = fopen("paises.dat", "rb");
  if(p==NULL) return -1;
  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  
  fclose(p);
  return tam/sizeof(Pais); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
}

//***********************************************************//
class ArchivoPais{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPais(const char* nombre="Pais.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Pais& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Pais),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pais);
    }

Pais leerRegistro(int pos){
        Pais reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Pais& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Pais), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Pais), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Pais objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Pais), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Pais objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Pais), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Pais objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Pais), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}



};

//***********************************************************//

class Jugador{
private:
  char _codigoJugador[5];
  char _nombreJugador[30];/*string trabaja con memoria heap por eos usamos char ya que puedo saber lo que pesa*/
  int _codigoPais;//1 a 32  
  int _edad;

public:
  void setCodigoJugador(const char *codJug){strcpy(_codigoJugador, codJug);}
  /*
    Jugador objJ;
    objJ.setNombreJugador("PEPE"); al ser const permite escribir constante como "PEPE"
  */
  void setNombreJugador(const char *nom){strcpy(_nombreJugador,nom);}//strcpy permite que solo pase el valor del parametro/nom a mi atributo/_nombreJugador
  void setCodigoPais(const int codP){_codigoPais=codP;}
  int getCodigoPais(){return _codigoPais;}
  const char *getCodigoJugador(){return _codigoJugador;}
  const char *getNombreJugador(){return _nombreJugador;}
  void setEdad(int ed){_edad=ed;}
  int getEdad(){return _edad;}

  void cargar(){
    cout << "Ingrese el codigo del jugador: "; cargarCadena(_codigoJugador, 5);
    cout << "Ingrese el nombre del jugador: "; cargarCadena(_nombreJugador, 30);
    cout << "Ingrese el codigo del pais: "; cin >> _codigoPais;
    cout << "Ingrese la edad: "; cin >> _edad;
  }

  void mostrar()
  {
    cout << "Codigo del jugador: " << _codigoJugador << endl;
    cout << "Nombre del jugador: " << _nombreJugador << endl;
    cout << "Codigo del pais: " << _codigoPais << endl;
    cout << "Edad: " << _edad << endl;
  }

  int contarRegistros();
};




Jugador leerRegistro(int pos){
  Jugador reg;
  FILE *p;
  p=fopen("jugadores.dat", "rb");
  if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg,1, p);
  fclose(p);
  return reg;
}

int Jugador::contarRegistros(){   //cuantos registros tengo
  FILE *p = fopen("jugadores.dat", "rb");
  if(p==NULL) return -1;
  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  
  fclose(p);
  return tam/sizeof(Jugador); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
}


//***********************************************************//


class Gol{ 
private:
  int codigoPartido;
  int minutos;
  int tiempo;// tiempo1 o 2 de primer o segundo tiempo
  int tipo;//1: penal; 2: en contra; 3: juego)
  char codigoJugador[5]; //PK de jugador
public:
  const char *getCodigoJugador(){return codigoJugador;}
  int getTipo(){return tipo;}
  bool leerDeDisco(int);
  void cargar(){
    cout<<"codigo Partido: "; cin>>codigoPartido;
    cout<<"minutos: "; cin>>minutos;
    cout<<"tiempo: "; cin>>tiempo;
    cout<<"codigo Jugador: "; cargarCadena(codigoJugador,5);
    cout<<"tipo: "; cin>>tipo;
  }

  void mostrar(){
    cout<<"codigo Partido: "<<codigoPartido<<endl;
    cout<<"minutos: "<<minutos<<endl;
    cout<<"tiempo: "<<tiempo<<endl;
    cout<<"tipo: "<<tipo<<endl;
    cout<<"codigo Jugador: "<<codigoJugador<<endl;
  }

};
bool Gol::leerDeDisco(int pos){//leer archivo
  FILE *p;
  p=fopen("goles.dat","rb");
  if(p==NULL)exit(1);
  fseek(p, sizeof *this*pos,0);
  bool leyo=fread(this, sizeof *this, 1, p);
  fclose(p);
  return leyo;
}


//***********************************************************//
class ArchivoGol{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoGol(const char* nombre="Gol.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Gol& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Gol),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Gol);
    }

Gol leerRegistro(int pos){
        Gol reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Gol& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Gol), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Gol), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Gol objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Gol), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Gol objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Gol), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Gol objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Gol), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

// bool ExisteDNI(int dni){
//    Gol obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Gol),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

//***********************************************************//










class ArchivoJugador{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoJugador(const char* nombre="Jugador.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos



void crearArchivo(int tam=1){
    Jugador objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Jugador), 1, p);
    }

    fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pais);
    }

void mostrarArchivo(){
    Jugador objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }
while (fread(&objE, sizeof(Jugador), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

Jugador leerRegistro(int pos){
        Jugador reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


};


