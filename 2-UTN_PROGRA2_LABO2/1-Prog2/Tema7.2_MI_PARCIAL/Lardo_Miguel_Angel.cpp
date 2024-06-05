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



void puntoA(){
  Deporte objD;
  ArchivoDeportes ARobjD("deportes.dat");

  Jugador objJ;
  ArchivoJugadores ARobjJ("jugadores.dat");

  Punto objP;
  ArchivoPunto ARobjP;
  ARobjP.BorrarArchivo();

  int tam1 = ARobjD.contarRegistros();
  int tam2 = ARobjJ.contarRegistros();

  int contNodocent = 0;

  for (int i = 0; i < tam1; i++){
    objD = ARobjD.leerRegistro(i);
    if(objD.getEstado() == true){
    
      for (int j = 0; j < tam2; j++){
        objJ = ARobjJ.leerRegistro(j);
        if(objJ.getEstado() == true){
          if( (objD.getIdDeporte() == objJ.getIdDeporte()) && (objD.getIdCtegoria() == 1) ){        
            if(objJ.getClaustro() == 3 ){
              contNodocent ++;
            }
          }  
        }  
      }

      if(contNodocent >=50){
        objP.setearTodos(objJ.getIdDeporte(), objJ.getNombre(), objJ.getFechaInscirpcion().getAnio(), contNodocent);
        ARobjP.GuardarArchivo(objP);
      }

      contNodocent = 0;
    }  
  }  

  ARobjP.listarArchivo();
}

class PuntoB{
  private:
  int _DNI;
  char _nombre[25], _apellido[30];
  Fecha _fechaInscripcion;
public:

  void setDNI(int dni){_DNI = dni;}
  void setNombre(const char *nombre){strcpy(_nombre, nombre);}
  void setApellido(const char *apellido){strcpy(_apellido, apellido);}
  void setFechaInscripcion(Fecha fecha){_fechaInscripcion = fecha;}
  void setearTodo(int dni, const char *nombre, const char *apellido, Fecha fecha){
    setDNI(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFechaInscripcion(fecha);
  }


  int getDNI(){return _DNI;}
  const char *getNombres(){return _nombre;}
  const char *getApellidos(){return _apellido;}
  Fecha getFechaInscripcion(){return _fechaInscripcion;}


  void mostrar(){
    cout << "DNI: " << _DNI<< endl;
    cout << "Nombres: " << _nombre << endl;
    cout << "Apellidos: " << _apellido << endl;
    cout << "Fecha de inscripcion: ";
    _fechaInscripcion.Mostrar();
  }  
    
};

class ArchivoPuntoB{
private:
  char nombre[30];

public:
  ArchivoPuntoB(const char* nombre="PuntoB.dat")  {
    strcpy(this->nombre, nombre);
  }

  void BorrarArchivo(){
  FILE *p;
  p = fopen(nombre,"wb");
  if(p == NULL){
    cout<<"No se pudo borrar el archivo";    
  }
  fclose(p);
  }


  int contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return -1;}
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(PuntoB);
  }

  PuntoB leerRegistro(int pos){
    PuntoB reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return reg;}
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
  }



  void GuardarArchivo(PuntoB& obj){
    FILE *p;
    p = fopen(nombre,"ab");
    if(p == NULL){
      cout<<"No se pudo abrir el archivo";  
    }
    fwrite(&obj,sizeof(PuntoB),1,p);
    fclose(p);
  }

  void listarArchivo(){
  PuntoB objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
    cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
    exit(1);
  }
  while (fread(&objE, sizeof(PuntoB), 1, p) == true){
    objE.mostrar();
    cout << endl;
  }
  fclose(p);
}



};

//generar un archivo con los alumnos que participan de equipos de nivel avanzado. Cada registro del archivo nuevo debe tener el siguiente formato:
//dni, nombre, apellidos, fecha de inscripcion


void puntoB(){
  Equipo objE;//NumeroEquipo(Id), nombre[char], nivel (1 inicial 2 intermedio 3 avanzado)
  ArchivoEquipos ARobjE("equipos.dat");
 
  Jugador objJ; //DNI(id), nombre[char], Apellido[char], FechaInscripcion, claustro (2 alumno)
  ArchivoJugadores ARobjJ("jugadores.dat");



  PuntoB objPuntoB;
  ArchivoPuntoB ARobjPuntoB;
  ARobjPuntoB.BorrarArchivo();

  int tam1 = ARobjE.contarRegistros();
  int tam2 = ARobjJ.contarRegistros();
  
  for (int i = 0; i < tam1; i++){ // PK => numero equipo
    objE = ARobjE.leerRegistro(i);
    if(objE.getEstado() == true && (objE.getNivel() == 3)){

      for (int j = 0; j < tam2; j++){ //FK numero equipo
        objJ = ARobjJ.leerRegistro(j);
        if((objJ.getEstado() == true)  &&  (objE.getIdEquipo() == objJ.getIdEquipo()) && (objJ.getClaustro() == 2)){
          objPuntoB.setearTodo(objJ.getDNI(), objJ.getNombre(), objJ.getApellido(), objJ.getFechaInscirpcion());
          ARobjPuntoB.GuardarArchivo(objPuntoB);
        }  
      }
    } 
  }
  

  ARobjPuntoB.listarArchivo();

}

class PuntoC{
  private:
  int _idDeporte;
  char _nombre[30];
  int _anioOrigen;
  int _cantidadAlumnosInscriptos;
public:

  void setIdDeporte(int idDeporte){_idDeporte=idDeporte;}
  void setNombre(const char *nombre){strcpy(_nombre, nombre);}
  void setAnioOrigen(int anioOrigen){_anioOrigen=anioOrigen;}
  void setCantidadAlumnosInscriptos(int cantidadAlumnosInscriptos){_cantidadAlumnosInscriptos=cantidadAlumnosInscriptos;}
  void setearTodo(int idDeporte, const char *nombre, int anioOrigen, int cantidadAlumnosInscriptos){
    setIdDeporte(idDeporte);
    setNombre(nombre);
    setAnioOrigen(anioOrigen);
    setCantidadAlumnosInscriptos(cantidadAlumnosInscriptos);
  }

  int getIdDeporte(){return _idDeporte;}
  const char *getNombre(){return _nombre;}
  int getAnioOrigen(){return _anioOrigen;}
  int getCantidadAlumnosInscriptos(){return _cantidadAlumnosInscriptos;}


  void mostrar(){
    cout<< "idDeporte: " << _idDeporte<<endl;
    cout<< "nombre: " << _nombre<<endl;
    cout<< "anioOrigen: " << _anioOrigen<<endl;
    cout<< "cantidadAlumnosInscriptos: " << _cantidadAlumnosInscriptos<<endl;
  }  
};

class ArchivoPuntoC{
private:
  char nombre[30];

public:
  ArchivoPuntoC(const char* nombre="PuntoC.dat")  {
    strcpy(this->nombre, nombre);
  }

  void BorrarArchivo(){
  FILE *p;
  p = fopen(nombre,"wb");
  if(p == NULL){
    cout<<"No se pudo borrar el archivo";    
  }
  fclose(p);
  }


  int contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return -1;}
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(PuntoC);
  }

  PuntoC leerRegistro(int pos){
    PuntoC reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){ return reg;}
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
  }



  void GuardarArchivo(PuntoC& obj){
    FILE *p;
    p = fopen(nombre,"ab");
    if(p == NULL){
      cout<<"No se pudo abrir el archivo";  
    }
    fwrite(&obj,sizeof(PuntoC),1,p);
    fclose(p);
  }

  void listarArchivo(){
  PuntoC objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
    cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
    exit(1);
  }
  while (fread(&objE, sizeof(PuntoC), 1, p) == true){
    objE.mostrar();
    cout << endl;
  }
  fclose(p);
}

};

//Archivo => Deportes de cat 5 que tengan mas de 50 ALUMNOS inscriptos => 
//(id Deporte, nombre Deporte, anio de origen Deporte, cantidad de alumnos inscriptos)
void puntoC(){
  Deporte objD; // idDeporte (PK), nombre, categoria de deporte (5), anio Oriten, estado
  ArchivoDeportes ARobjD("deportes.dat");

  Jugador objJ;//DNI(PK), idDeporte (fk), claustro (2 - alumno)
  ArchivoJugadores ARobjJ("jugadores.dat");

  PuntoC objPuntoC;
  ArchivoPuntoC ARobjPuntoC;
  ARobjPuntoC.BorrarArchivo();

  int tamDeporte = ARobjD.contarRegistros();
  int tamJugadores = ARobjJ.contarRegistros();

  int cantidadAlumnosInscriptos;

  for (int i = 0; i < tamDeporte; i++){
    objD = ARobjD.leerRegistro(i);
    if((objD.getEstado() == true) && objD.getIdCtegoria() == 5){ 
      
      cantidadAlumnosInscriptos = 0;
      for(int j = 0; j < tamJugadores; j++){
        objJ = ARobjJ.leerRegistro(j);
        if((objJ.getEstado() == true) && (objD.getIdDeporte() == objJ.getIdDeporte()) &&  (objJ.getClaustro() == 2)){
          cantidadAlumnosInscriptos ++;          
        }    
      } 

      if(cantidadAlumnosInscriptos > 2){
        objPuntoC.setearTodo(objD.getIdDeporte(), objD.getNombre(), objD.getAnioOrigen(), cantidadAlumnosInscriptos);
        ARobjPuntoC.GuardarArchivo(objPuntoC);
      }   
    
    
    }  
  
  }  

  ARobjPuntoC.listarArchivo();


}


int main(){
  // Jugador objJ; ArchivoJugadores ARobjJ("jugadores.dat");
  //  for (int i = 0; i < 5; i++){
  //   objJ.Cargar();
  //   ARobjJ.grabarRegistro(objJ);
  //  }

  // Deporte objD; ArchivoDeportes ARobjD("deportes.dat");
  // for (int i = 0; i < 5; i++){
  //   objD.Cargar();
  //   ARobjD.grabarRegistro(objD);
  // }

  //ARobjJ.listarRegistros();


  //puntoA();

  //puntoB();


  puntoC();

  return 0;
}