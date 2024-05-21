#include<iostream>
#include<cstring>

using namespace std;

#include "parcial1l.h"

class Punto{

private:
  int _idDeporte;
  char _nombre[25];
  int _anioOrigen;
  int _cantidadAlumnosInscriptos;


public:

  //setters y getters
  void setIdDeporte(int idDeporte){_idDeporte=idDeporte;}
  void setNombre(const char *nombre){strcpy(_nombre, nombre);}
  void setAnioOrigen(int anioOrigen){_anioOrigen=anioOrigen;}
  void setCantidadAlumnosInscriptos(int cantidadAlumnosInscriptos){_cantidadAlumnosInscriptos=cantidadAlumnosInscriptos;}
  
  void setearTodos(int idDeporte, const char *nombre, int anioOrigen, int cantidadAlumnosInscriptos){
    setIdDeporte(idDeporte);
    setNombre(nombre);
    setAnioOrigen(anioOrigen);
    setCantidadAlumnosInscriptos(cantidadAlumnosInscriptos);
  }


  int getIdDeporte(){return _idDeporte;}
  const char *getNombres(){return _nombre;}
  int getAnioOrigen(){return _anioOrigen;}
  int getCantidadAlumnosInscriptos(){return _cantidadAlumnosInscriptos;}


  void cargar(){
    cout << "ID deporte: "; cin >> _idDeporte;
    cout << "Nombres: "; cargarCadena(_nombre, 24);
    cout << "Anio de origen: "; cin >> _anioOrigen;
    cout << "Cantidad de alumnos inscriptos: "; cin >> _cantidadAlumnosInscriptos;
  }


  void mostrar(){
    cout << "ID deporte: " << _idDeporte << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "año origen: " << _anioOrigen << endl;
    cout << "Cantidad de alumnos inscriptos: " << _cantidadAlumnosInscriptos << endl;
  }

  
    

};

class ArchivoPunto{
private:
  char nombre[30];

public:
  ArchivoPunto(const char* nombre="Punto.dat"){
    strcpy(this->nombre, nombre);
  }


  int contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return -1;}
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Punto);
  }

  Punto leerRegistro(int pos){
    Punto reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return reg;}
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
  }

  void GuardarArchivo(Punto& obj){
    FILE *p;
    p = fopen(nombre,"ab");
    if(p == NULL){
      cout<<"No se pudo abrir el archivo";  
    }
    fwrite(&obj,sizeof(Punto),1,p);
    fclose(p);
  }

bool reemplazarRegistro(Punto& reg, int posicionAReemplazar){
  FILE *p = fopen(nombre, "rb+");
  if (p == NULL){ return false;}
  fseek(p, posicionAReemplazar * sizeof(Punto), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Punto), 1, p);
  fclose(p);
  return pudoEscribir;
  }

void cargarRegistro(int tam=1){
  Punto objE;
  FILE *p;
  p = fopen(nombre,"ab");
  if(p==NULL){
    cout << "No se pudo abrir el archivo crearArchivo" << endl;  
    exit(1);
  }

  for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto), 1, p);
  }

  fclose(p);
}

void crearArchivo(int tam=1){
  Punto objE;
  FILE *p;
  p = fopen(nombre,"wb");
  if(p==NULL){
    cout << "No se pudo abrir el archivo crearArchivo" << endl;  
    exit(1);
  }

  for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto), 1, p);
  }

  fclose(p);
}

void listarArchivo(){
  Punto objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
    cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
    exit(1);
  }
  while (fread(&objE, sizeof(Punto), 1, p) == true){
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
  }
  fclose(p);
}

};



void punto(){

Jugador objJ;//dni(PK), nombre, apellido, email,telefono, claustro (1 docente, 2 alumno 3 no docente; 4 graduado), idDeporte(FK) , numEquipo, FechaInscripcion, Matricula, estado
ArchivoJugadores ARobjJ("jugadores.dat");

Deporte objD; //idDeporte(PK), nombre, CategoriaDeporte, anioOrigen, Estado
ArchivoDeportes ARobjD("deportes.dat");

int tam1 = ARobjJ.contarRegistros();
int tam2 = ARobjD.contarRegistros();

Punto objP;
ArchivoPunto ARobjP;
ARobjP.BorrarArchivo();

int contNodocent = 0;  
int contAlumInscript = 0;

for(int i = 0; i < tam2; i++){ //deporte con ID primary key
  objJ = ARobjJ.leerRegistro(i);

  if(objJ.getEstado() == true){
     contNodocent = 0;
     contAlumInscript = 0;
 
    for(int j = 0; j < tam1; j++){//jugador
        objD = ARobjD.leerRegistro(j);

        if(objD.getEstado() == true){
          if((objJ.getIdDeporte() == objD.getIdDeporte()) && (objD.getIdCtegoria() == 1) ) {           
            
            if(objJ.getClaustro() == 2 ){contAlumInscript ++;}
            
            if(objJ.getClaustro() == 3 ){contNodocent ++;}

            cout << "DEPORTE MOSTRAR:" << endl;
            objD.Mostrar();
            cout << endl;
            cout << "JUGADOR MOSTRAR:" << endl;
            objJ.Mostrar();
            cout << endl;
            cout << "contador de alumnos inscriptos: " << contAlumInscript << endl;
            cout << "contador de no docentes: " << contNodocent << endl;
            system("pause");

        }
      }
    
    }

    if(contNodocent >=2){
      objP.setearTodos(objJ.getIdDeporte()/*es lo mismo que objD.getIdDeporte()*/, objJ.getNombre()/*nombre del jugador o del deporte?*/, objJ.getFechaInscirpcion().getAnio(), contAlumInscript);
      ARobjP.GuardarArchivo(objP);
    }

  }


}

ARobjP.listarArchivo();


}


void puntoAux(){
  Deporte objD;
  ArchivoDeportes ARobjD("deportes.dat");

  Jugador objJ;
  ArchivoJugadores ARobjJ("jugadores.dat");

  Punto objP;
  ArchivoPunto ARobjP;
  ARobjP.BorrarArchivo();

  int tam1 = ARobjD.contarRegistros();
  int tam2 = ARobjJ.contarRegistros();

  int contAlumInscript = 0;
  int contNodocent = 0;

  for (int i = 0; i < tam1; i++){
    objD = ARobjD.leerRegistro(i);
    if(objD.getEstado() == true){
    
      for (int j = 0; j < tam2; j++){
        objJ = ARobjJ.leerRegistro(j);
        if(objJ.getEstado() == true){
          if( (objD.getIdDeporte() == objJ.getIdDeporte()) && (objD.getIdCtegoria() == 1) ){
            
            if(objJ.getClaustro() == 2 ){contAlumInscript ++;}            
            if(objJ.getClaustro() == 3 ){contNodocent ++;}

          }  
        
        }  
      }

      if(contNodocent >=2){
        objP.setearTodos(objJ.getIdDeporte(), objJ.getNombre(), objJ.getFechaInscirpcion().getAnio(), contAlumInscript);
        ARobjP.GuardarArchivo(objP);
      }

      contAlumInscript = 0;
      contNodocent = 0;

    
    }  
  
  
  
  }  

  ARobjP.listarArchivo();


}

int main(){
  Jugador objJ; ArchivoJugadores ARobjJ("jugadores.dat");
  //  for (int i = 0; i < 30; i++){
  //   objJ.Cargar();
  //   ARobjJ.grabarRegistro(objJ);
  //  }

  Deporte objD; ArchivoDeportes ARobjD("deportes.dat");
  // for (int i = 0; i < 30; i++){
  //   objD.Cargar();
  //   ARobjD.grabarRegistro(objD);
  // }

//ARobjJ.listarRegistros();

 //punto();

  puntoAux();

  return 0;
}