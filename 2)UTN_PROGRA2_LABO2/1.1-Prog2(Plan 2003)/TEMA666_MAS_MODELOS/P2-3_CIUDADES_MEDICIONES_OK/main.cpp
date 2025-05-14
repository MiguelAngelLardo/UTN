#include <iostream>
#include <cstring>
#include <iomanip>

#include "parcial2.h"

using namespace std;

class PuntoA {
  private:
      int _codigoCiudad;
      char _nombre[30];
      float _promedioVisibilidad;
      bool _estado;
  
  public:
    void setCodigoCiudad(int codigo) {_codigoCiudad = codigo;}
    void setNombre(const char* nombre) {strcpy(_nombre, nombre);}
    void setPromedioVisibilidad(float promedio) {_promedioVisibilidad = promedio;}
    void setEstado(bool estado) {_estado = estado;}
    void setTodo(int codigo, const char* nombre, float promedio, bool estado) {
        setCodigoCiudad(codigo);
        setNombre(nombre);
        setPromedioVisibilidad(promedio);
        setEstado(estado);
    }

    void Mostrar() {
        cout << "Codigo Ciudad: " << _codigoCiudad << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Promedio de visibilidad: " << fixed << setprecision(2) << _promedioVisibilidad << endl;
        cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    }
      
  };
  
class ArchivoPuntoA {
  private:
    char nombre[30];
  
  public:
    ArchivoPuntoA() {
      strcpy(nombre, "PuntoA");
    }
  
  
      bool escribirRegistro(PuntoA reg) {
          FILE* p;
          p = fopen(nombre, "ab");
          if (p == NULL) return false;
          bool escribio = fwrite(&reg, sizeof reg, 1, p);
          fclose(p);
          return escribio;
      }
  
      void vaciar(){
          FILE *p = fopen(nombre, "wb");
          if (p == NULL){return ;}
          fclose(p);
      }
  
      bool listarArchivo() {
          PuntoA reg;
          FILE* p = NULL;
          p = fopen(nombre, "rb");
          if (p == NULL) {return false;}
          while (fread(&reg, sizeof reg, 1, p) == 1) {
              reg.Mostrar();
              cout << endl;
          }
          fclose(p);
          return true;
      }
  
};

void puntoA(){
  Ciudades objCiud;
  ArchivoCiudades objArcCiud;
  Mediciones objMed;
  ArchivoMediciones objArcMed;
  PuntoA objPuntoA;
  ArchivoPuntoA objArcPuntoA;

  objArcPuntoA.vaciar();

  int tamCiudades = objArcCiud.contarRegistros();
  int tamMediciones = objArcMed.contarRegistros();

  int cont;
  float acum;
  for(int i = 0; i < tamCiudades; i++) {
      objCiud = objArcCiud.leerRegistro(i);

      cont = 0;
      acum = 0.0;
      for(int j = 0; j < tamMediciones; j++) {
        objMed = objArcMed.leerRegistro(j);
        if(objCiud.getCodigoCiudad() == objMed.getCiudad()) {
            cont ++;
            acum += objMed.getVisibilidad();
        }
      }
      if(cont > 0){
        objPuntoA.setTodo(objCiud.getCodigoCiudad(), objCiud.getNombre(), (acum/cont), true);
        objArcPuntoA.escribirRegistro(objPuntoA);
      }
  } 

 objArcPuntoA.listarArchivo();

}

void puntoB(){
  Mediciones objMed;
  ArchivoMediciones objArcMed;

  int mVisibilidadDiasCont[6][31]={};

  int tam1 = objArcMed.contarRegistros();
  for(int i=0; i<tam1; i++){
      objMed = objArcMed.leerRegistro(i);
      if(objMed.getFecha().getMes() == 5)
      mVisibilidadDiasCont[objMed.getVisibilidad()][objMed.getFecha().getDia()-1]++;
  }

  cout << "mostrando cantidad de visibilidad por dia" << endl;

  for(int i=0; i<6; i++){
      cout << "Visibilidad: " << i << endl;
      for(int j=0; j<31; j++){
          cout << mVisibilidadDiasCont[i][j] << " ";
      }
      cout << endl;
  }



}

void mostrarArchivos(){
  ArchivoCiudades objArcCiud;
  ArchivoMediciones objArcMed;

  int tam1 = objArcCiud.contarRegistros();

  for(int i=0; i<tam1; i++){
      Ciudades regCiudades = objArcCiud.leerRegistro(i);
      cout<<regCiudades.getCodigoCiudad()<<" "<<regCiudades.getNombre()<<" "<<regCiudades.getCodigoProvincia()<<endl;
  }

  cout<<"----------------------------------------"<<endl;

  int tam2 = objArcMed.contarRegistros();
  for(int i=0; i<tam2; i++){
      Mediciones regMediciones = objArcMed.leerRegistro(i);
      cout<<regMediciones.getCiudad()<<" "<<regMediciones.getNombre()<<" "<<regMediciones.getTemperatura()<<" "<<regMediciones.getVisibilidad() << " ";
      regMediciones.getFecha().Mostrar();
  }

}


class PuntoA2 {
  private:
      int _codigoCiudad;
      char _nombre[30];
      int _cantModeradaBuena;
      bool _estado;
  
  public:
    void setCodigoCiudad(int codigo) {_codigoCiudad = codigo;}
    void setNombre(const char* nombre) {strcpy(_nombre, nombre);}
    void setCantModeradaBuena(int cant) {_cantModeradaBuena = cant;}
    void setEstado(bool estado) {_estado = estado;}
    void setTodo(int codigo, const char* nombre, int cant, bool estado) {
        setCodigoCiudad(codigo);
        setNombre(nombre);
        setCantModeradaBuena(cant);
        setEstado(estado);
    }

    void MostrarA2() {
        cout << "Codigo Ciudad: " << _codigoCiudad << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Cantidad de mediciones moderadas o buenas: " << _cantModeradaBuena << endl;
        cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    }
      
  };

  class ArchivoPuntoA2 {
    private:
      char nombre[30];
    
    public:
      ArchivoPuntoA2() {
        strcpy(nombre, "PuntoA2");
      }
    
    
        bool escribirRegistro(PuntoA2 reg) {
            FILE* p;
            p = fopen(nombre, "ab");
            if (p == NULL) return false;
            bool escribio = fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
            return escribio;
        }
    
        void vaciar(){
            FILE *p = fopen(nombre, "wb");
            if (p == NULL){return ;}
            fclose(p);
        }
    
        bool listarArchivo() {
            PuntoA2 reg;
            FILE* p = NULL;
            p = fopen(nombre, "rb");
            if (p == NULL) {return false;}
            while (fread(&reg, sizeof reg, 1, p) == 1) {
                reg.MostrarA2();
                cout << endl;
            }
            fclose(p);
            return true;
        }
    
  };
  
  void puntoA2(){
    Ciudades objCiud;
    ArchivoCiudades objArcCiud;
    Mediciones objMed;
    ArchivoMediciones objArcMed;
    PuntoA2 objPuntoA2;
    ArchivoPuntoA2 objArcPuntoA2;

    objArcPuntoA2.vaciar();

    int tamCiudades = objArcCiud.contarRegistros();
    int tamMediciones = objArcMed.contarRegistros();

    int cont;
    bool hayCoincidencia;
    for(int i = 0; i < tamCiudades; i++) {
        objCiud = objArcCiud.leerRegistro(i);

        cont = 0;
        hayCoincidencia = false;
        for(int j = 0; j < tamMediciones; j++) {
          objMed = objArcMed.leerRegistro(j);

          if(objCiud.getCodigoCiudad() == objMed.getCiudad()) {
              hayCoincidencia = true;
              if(objMed.getVisibilidad() == 4 || objMed.getVisibilidad() == 5) {
                  cont ++;
              }
          }
        }

        if(hayCoincidencia){
          objPuntoA2.setTodo(objCiud.getCodigoCiudad(), objCiud.getNombre(), cont, true);
          objArcPuntoA2.escribirRegistro(objPuntoA2);
        }
       
    }
    objArcPuntoA2.listarArchivo();
  }

  void puntoB2(){
    Ciudades objCiud;
    ArchivoCiudades objArcCiud;
    int tamCiudades = objArcCiud.contarRegistros();

    Mediciones objMed;
    ArchivoMediciones objArcMed;
    int tamMediciones = objArcMed.contarRegistros();

    bool bandera = false;
    int ciudadMenosNieblaNeblina;
    int contadorNieblaNeblina = 0;
    int menorCantidadTOTAL = 0;
    
    bool hayCoincidencia;
    for(int i = 0; i < tamCiudades; i++) {
        objCiud = objArcCiud.leerRegistro(i);

        contadorNieblaNeblina  = 0;
        hayCoincidencia = false;
        for(int j = 0; j < tamMediciones; j++) {
          objMed = objArcMed.leerRegistro(j);
          
          if(objCiud.getCodigoCiudad() == objMed.getCiudad()) {
            hayCoincidencia = true;
            if(objMed.getVisibilidad() == 0 || objMed.getVisibilidad() == 1 || objMed.getVisibilidad() == 2 || objMed.getVisibilidad() == 3) { 
              contadorNieblaNeblina ++;
            
            }
          }
        }

        if(hayCoincidencia && contadorNieblaNeblina > 0){
          if(!bandera){
            bandera = true;
            menorCantidadTOTAL = contadorNieblaNeblina;
            ciudadMenosNieblaNeblina = objCiud.getCodigoCiudad();  
          }else if(contadorNieblaNeblina < menorCantidadTOTAL){
            menorCantidadTOTAL = contadorNieblaNeblina;
            ciudadMenosNieblaNeblina = objCiud.getCodigoCiudad();
          }
        }
    }

    cout << "La ciudad con menor cantidad de niebla o neblina es: " << ciudadMenosNieblaNeblina << " - con una cantidad de " << menorCantidadTOTAL << endl;

  }

  void puntoC(){
    Ciudades objCiudad;
    ArchivoCiudades objArcCiudad;
    Ciudades *vDinCiudades = nullptr;

    int tamCiudades = objArcCiudad.contarRegistros();
    vDinCiudades = new Ciudades[tamCiudades];
    if(vDinCiudades == NULL){
        cout<<"Error al crear el vector dinamico"<<endl;
        return;
    }

    for(int i=0; i<tamCiudades; i++){
        objCiudad = objArcCiudad.leerRegistro(i);
        vDinCiudades[i].setCodigoCiudad(objCiudad.getCodigoCiudad());
        vDinCiudades[i].setNombre(objCiudad.getNombre());
        vDinCiudades[i].setCodigoProvincia(objCiudad.getCodigoProvincia());
    }

    int codigoProvincia;
    cout << "Ingrese la provincia para buscar las ciudades de la misma: ";
    cin >> codigoProvincia;

    for(int i=0; i<tamCiudades; i++){
        if(vDinCiudades[i].getCodigoProvincia() == codigoProvincia){
            cout << "Ciudad: " << vDinCiudades[i].getNombre() << endl;
        }
    }



  }
  

int main() {
  mostrarArchivos();
  puntoC();
  

    return 0;
}