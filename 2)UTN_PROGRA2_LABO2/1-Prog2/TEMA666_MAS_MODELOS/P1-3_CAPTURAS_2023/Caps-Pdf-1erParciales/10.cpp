#include <iostream>

using namespace std;

class Punto1{

    private:
      int _idDeporte;
      char _nombre[30];
      int _anioOrigen;
      int _cantidadAlimnos;

    public:

    //setters y getters+
    void setIdDeporte(int idDeporte){_idDeporte=idDeporte;}
    void setNombre( const char* nombre){strcpy(_nombre, nombre);}
    void setAnioOrigen(int anioOrigen){_anioOrigen=anioOrigen;}
    void setCantidadAlimnos(int cantidadAlimnos){_cantidadAlimnos=cantidadAlimnos;}
    void setearTodo(int idDeporte, const char* nombre, int anioOrigen, int cantidadAlimnos){
        setIdDeporte(idDeporte);
        setNombre(nombre);
        setAnioOrigen(anioOrigen);
        setCantidadAlimnos(cantidadAlimnos);
    }

    int getIdDeporte(){return _idDeporte;}
    const char* getNombre(){return _nombre;}
    int getAnioOrigen(){return _anioOrigen;}
    int getCantidadAlimnos(){return _cantidadAlimnos;}

    //metodos
    void mostrar(){
        cout<<_idDeporte<<" "<<_nombre<<" "<<_anioOrigen<<" "<<_cantidadAlimnos<<endl;
    }

    void cargar(){
        cout<<"Id deporte: "; cin>>_idDeporte;
        cout<<"Nombre: "; cin>>_nombre;
        cout<<"Anio de origen: "; cin>>_anioOrigen;
        cout<<"Cantidad de alimentos: "; cin>>_cantidadAlimnos;
    }
};

class ArchivoPunto1{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPunto1(const char* nombre){
            strcpy(this->nombre, nombre);
        }

//metodos
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



//Generar un archivo con los deportes de categoria 1 que tengan mas de 50 alumnos inscriptos. 
//Cada registro del archivo nuevo debe tener el siguiente formato
int main() {
  //Deporte objD; categoria1
  //Alumno objA; cantidadAlimnos + 50

  Punto1 objPunto1;
  ArchivoPunto1 ArobjPTO1("Punto1.dat");
  ArobjPTO1.BorrarArchivo;

  int tam1 = ARobjD.contarRegistros();
  int tam2 = ARobjA.contarRegistros();

  for (int i = 0; i < tam1; i++) {
    objD = ARobjD.leerRegistro(i);
    if (objD.getEstado()){
      for(int j = 0; j < tam2; j++){
        objA = ARobjA.leerRegistro(j);
        if(objA.getEstado()){
          if((objD.getIdDeporte() == objA.getIdDeporte()) && (objA.getCantidadAlimnos() > 50) && (objD.getCategoria() == 1)){     
            objPunto1.setearTodo(objD.getIdDeporte(), objD.getNombre(), objD.getAnioOrigen(), objA.getCantidadAlimnos());
            ARobjPTO1.guardarRegistro(objPunto1);
        
          }
          
              
        }

      
      }  

    }
  
  }

  ARobjPTO1.mostrarArchivo();  


  

return 0;
}