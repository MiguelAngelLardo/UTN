#include <iostream>
#include <cstdlib>
#include<cstring> //<----

using namespace std; 

#include"clases.h"
#include"crearymostrar.h"

//***********************************************************//
//***********************************************************//

class Punto1{
private:
  char _nombrePais[30]; //paises.dat => uso el codigo pais de paises.dat para ir a jugadores.dat
  char _codigoJugador[5];//jugadores.dat
  char _nombreJugador[30];//jugadores.dat
  int _cont;//cantidad de goles convertidos, solo deben aparecer los goles que hicieron, no se tiene en cuenta los goles en cotra

public:
  void setNommbrePais(const char *nom){strcpy(_nombrePais,nom);}//strcpy permite que solo pase el valor del parametro/nom a mi atributo/_nombrePais
  void setCodigoJugador(const char *codJug){strcpy(_codigoJugador, codJug);}
  void setNombreJugador(const char *nom){strcpy(_nombreJugador,nom);}
  void setCont(int cont){_cont=cont;}

  const char *getNommbrePais(){return _nombrePais;}
  const char *getCodigoJugador(){return _codigoJugador;}
  const char *getNombreJugador(){return _nombreJugador;}
  int getCont(){return _cont;}
  
  void setearTodo(const char *nom, const char *codJug, const char *nomJug, int cont){
    strcpy(_nombrePais,nom);
    strcpy(_codigoJugador, codJug);
    strcpy(_nombreJugador,nomJug);
    _cont=cont;
  }
  
  void cargar(){
    cout << "Ingrese el nombre del pais(30 caracteres): "; cargarCadena(_nombrePais, 30);
    cout << "Ingrese el codigo del jugador(5 caracteres): "; cargarCadena(_codigoJugador, 5);
    cout << "Ingrese el nombre del jugador(30 caracteres): "; cargarCadena(_nombreJugador, 30);
    cout << "Ingrese la cantidad de goles convertidos: "; cin >> _cont;
  }
  
    void mostrar(){
      cout << "\t" << _nombrePais << "\t" << _codigoJugador << "\t" << _nombreJugador << "\t" << _cont << endl;
    }

};

class ArchivoPunto1{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPunto1(const char* nombre="Punto1.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Punto1& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

int contarRegistros(){
  FILE *p;
  p=fopen(nombre, "rb");
  if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
  fseek(p, 0,2); 
  int tam=ftell(p);
  fclose(p);
  return tam/sizeof(Punto1);
}

Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Punto1 objE;
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
    fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){cout << "No se pudo abrir el archivo crearArchivo" << endl;exit(1);}

    for(int i=0; i<tam; i++){
      objE.cargar();
      cout<<endl;
      fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
}


void mostrarArchivo(){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Punto1), 1, p) == true){
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
//    Punto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Punto1),1,p)){
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
//***********************************************************//

void punto1(){
    Punto1 objP;
    ArchivoPunto1 objARP;
    objARP.BorrarArchivo();

    Pais objPais;
    ArchivoPais objARPais;

    Jugador objJugador;
    ArchivoJugador objARJugador;

    Gol objGoles;
    ArchivoGol objARGoles;

    int tam1 = objARPais.contarRegistros();
    int tam2 = objARJugador.contarRegistros();
    int tam3 = objARGoles.contarRegistros();

int cont=0;
bool band=false;




  for(int i=0; i<tam1; i++){
    objPais = objARPais.leerRegistro(i);

    for(int j=0; j<tam2; j++){
      objJugador = objARJugador.leerRegistro(j);

      if(objPais.getCodigoPais() == objJugador.getCodigoPais()){
      //nombre jugador == objJugador.getNombreJugador();
      //nombre pais  == objPais.getNombrePais();
      
      cout<<"objPais.getCodigoPais(): "<<objPais.getCodigoPais()<<endl;

        for(int k=0; k<tam3; k++){
          objGoles = objARGoles.leerRegistro(k);

          if(strcmp(objJugador.getCodigoJugador(), objGoles.getCodigoJugador())==0){
            //codigo de jugador == objJugador.getCodigoJugador();
            //cantidad de goles == cont
            band = true;
            
            if(objGoles.getTipo() == 1 || objGoles.getTipo() == 3){
              cont++;
            }
          }
        } /// cerrar for n°3
          if(band==true){
          objP.setearTodo(objPais.getNombrePais(), objJugador.getCodigoJugador(), objJugador.getNombreJugador(), cont);
          objARP.GuardarArchivo(objP);
          }

          band=false;
          cont = 0;
      } /// cerrar el if

    } /// cerrar for n°2
  } /// cerrar for n°1


  //objARP.mostrarArchivo();
} ///cerrar funcion

void borrar(){
      Punto1 objP;
    ArchivoPunto1 objARP;
    objARP.BorrarArchivo();

    Pais objPais;
    ArchivoPais objARPais;

    Jugador objJugador;
    ArchivoJugador objARJugador;

    Gol objGoles;
    ArchivoGol objARGoles;

    int  tam1 = objARPais.contarRegistros();
    int  tam2 = objARJugador.contarRegistros();
    int  tam3 = objARGoles.contarRegistros();




    for(int i=0; i<tam1; i++){
      objPais = objARPais.leerRegistro(i);

      for(int j=0; j<tam2; j++){
        objJugador = objARJugador.leerRegistro(j);

        if(objPais.getCodigoPais() == objJugador.getCodigoPais()){
          cout<<"objPais.getCodigoPais(): "<<objPais.getCodigoPais()<<endl;
        }

      }
    }
}


int main(){
  
    Pais objPais; // PK codigo pais - uso el nombre del pais para el nuevo archivo
    ArchivoPais objARPais;
    Jugador objJugador; // FK codigo pais - uso Codigo de Jugador y Nombre de jugador para el nuevo archivo
    Gol objGoles; // uso PK codigo Jugador de jugadores.dat para validad la FK codigo de jugador de goles.dat => debe ser 1-penal o 3 en juego


    Punto1 objPunto1;
    ArchivoPunto1 objArchpunto1;
    
    borrar();

    // crearyMostrarPais(10);
    // crearyMostrarGoles(10);
    // crearyMostrarJugador(10);

  return 0;
}

/*
1) Generar un archivo con el código y el nombre del jugador, el nombre del país al
que pertenece, y la cantidad de goles convertidos. En el archivo sólo deben
aparecer los jugadores que hicieron goles, sin tener en cuenta los goles en
contra.
*/

//strcmp(objJugador.getCodigoJugador(), objGoles.getCodigoJugador());