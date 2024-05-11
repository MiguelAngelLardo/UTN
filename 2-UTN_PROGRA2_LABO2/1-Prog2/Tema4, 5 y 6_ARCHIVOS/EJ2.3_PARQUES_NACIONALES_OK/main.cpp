#include <iostream>
#include <cstring>

using namespace std;

/*
3) Parques Nacionales tiene, entre otros, los siguientes archivos en su sistema:
*/

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

class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

//Animales.dat: Código de animal (int), nombre (char[30]), clasificación (char[5]), zona de habitat (entero entre 1 y 10), y estado (1= registro activo; 0: registro inactivado o borrado)
class Animal{
private:
  int _codigoAnimal;
  char _nombre[30];
  char _clasificacion[5];
  int _zonaHabitat;//1 a 10
  bool _estado;//1= registro activo; 0: registro inactivado o borrado

public:
  Animal (int codigoAnimal = 0, const char *nombre = "X", const char *clasificacion = "X", int zonaHabitat = 0, bool estado = true) 
    : _codigoAnimal(codigoAnimal), _zonaHabitat(zonaHabitat), _estado(estado)
    {strcpy(_clasificacion, clasificacion); strcpy(_nombre, nombre);}

  void setCodigoAnimal(int c){_codigoAnimal = c;}
  void setNombre(const char *n){strcpy(_nombre, n);}
  void setClasificacion(const char *c){strcpy(_clasificacion, c);}
  void setZonaHabitat(int z){_zonaHabitat = z;}

  int getCodigoAnimal(){return _codigoAnimal;}
  const char *getNombre(){return _nombre;}
  const char *getClasificacion(){return _clasificacion;}
  int getZonaHabitat(){return _zonaHabitat;}
  bool getEstado(){return _estado;}

  void cargar(){
    cout << "CODIGO DE ANIMAL: "; cin >> _codigoAnimal;
    cout << "NOMBRE: "; cargarCadena(_nombre, 30);
    cout << "CLASIFICACION: "; cargarCadena(_clasificacion, 5);
    cout << "ZONA DE HABITAT: "; cin >> _zonaHabitat;
    _estado = true;
  }

  void mostrar(){
    cout << "CODIGO DE ANIMAL: " << _codigoAnimal << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "CLASIFICACION: " << _clasificacion << endl;
    cout << "ZONA DE HABITAT: " << _zonaHabitat << endl;
  }
};

class ArchivoAnimal{
private:
  char _nombre[30];
public:
  ArchivoAnimal(const char *nombre = "Animales.dar"){
    strcpy(_nombre, nombre);
  }

  void grabarRgistroAnimal(Animal obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){cout << "No se pudo abrir el archivo";return;}
    fwrite(&obj, sizeof(Animal), 1, p);
    fclose(p);
  }

  void listarRegistros(){
    Animal obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL){cout << "Error de apertura";return;}

    while (fread(&obj, sizeof(Animal), 1, p) == 1){
      obj.mostrar();
      cout << endl;
    }
    fclose(p);
  }

  int contarRegistros(){//cuantos registros tengo
    FILE *p = fopen(_nombre, "rb");
    if(p==NULL) return -1;  
    fseek(p, 0,2); //cursor al final del codigo
    int tam=ftell(p); //del principio hasta donde esta el cursor
    fclose(p);
    return tam/sizeof(Animal); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Animal leerPorIndice(int index){
    Animal reg;
    FILE *pFile = fopen(_nombre, "rb");   
    if(pFile == nullptr){return reg;}
    fseek(pFile, index * sizeof (Animal), SEEK_SET);   
    fread(&reg, sizeof(Animal), 1, pFile);
    fclose(pFile);
    return reg;   
  }

  void borrarRegistros(){
    FILE *p;
    p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }
};

//Avistajes.dat: Código de animal (int), fecha (día, mes y año), zona de avistaje (entero entre 1 y 10) 
//El archivo tiene registros con los animales vistos desde el año 2000 a la fecha.
class Avistajes{
private:
  int _codigoAnimal;
  Fecha _fechaAvistamiento;
  int _zonaAvistaje; //1 a 10
public:
  Avistajes(int codigoAnimal = 0, Fecha fechaAvistamiento = Fecha(), int zonaViaje = 0) : _codigoAnimal(codigoAnimal), _fechaAvistamiento(fechaAvistamiento), _zonaAvistaje(zonaViaje){}

  void setCodigoAnimal(int c){_codigoAnimal = c;}
  void setFechaAvistamiento(Fecha f){_fechaAvistamiento = f;}
  void setZonaAvistaje(int z){_zonaAvistaje = z;}

  int getCodigoAnimal(){return _codigoAnimal;}
  Fecha getFechaAvistamiento(){return _fechaAvistamiento;}
  int getZonaAvistaje(){return _zonaAvistaje;}

  void cargar(){
    cout << "CODIGO DE ANIMAL: "; cin >> _codigoAnimal;
    cout << "FECHA DE AVISTAMIENTO: ";
    _fechaAvistamiento.Cargar();
    cout << "ZONA DE AVISTAJE: "; cin >> _zonaAvistaje;
  }

  void mostrar(){
    cout << "CODIGO DE ANIMAL: " << _codigoAnimal << endl;
    cout << "FECHA DE AVISTAMIENTO: ";
    _fechaAvistamiento.Mostrar();
    cout << "ZONA DE AVISTAJE: " << _zonaAvistaje << endl;
  }
};

class ArchivoAvistajes{
private:
  char _nombre[30];
public:
  ArchivoAvistajes(const char *nombre = "Avistajes.dat"){
    strcpy(_nombre, nombre);
  }

  void grabarRgistroAvistajes(Avistajes obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){cout << "No se pudo abrir el archivo";return;}
    fwrite(&obj, sizeof(Avistajes), 1, p);
    fclose(p);
  }

  void listarRegistrosAvistajes(){
    Avistajes obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL){cout << "Error de apertura";return;}

    while (fread(&obj, sizeof(Avistajes), 1, p) == 1){
      obj.mostrar();
      cout << endl;
    }
    fclose(p);
  }

  int contarRegistros(){//cuantos registros tengo
    FILE *p = fopen(_nombre, "rb");
    if(p==NULL) return -1;  
    fseek(p, 0,2); //cursor al final del codigo
    int tam=ftell(p); //del principio hasta donde esta el cursor
    fclose(p);
    return tam/sizeof(Avistajes); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Avistajes leerPorIndice(int index){
    Avistajes reg;
    FILE *pFile = fopen(_nombre, "rb");   
    if(pFile == nullptr){return reg;}
    fseek(pFile, index * sizeof (Avistajes), SEEK_SET);   
    fread(&reg, sizeof(Avistajes), 1, pFile);
    fclose(pFile);
    return reg;   
  }

  void borrarRegistros(){
    FILE *p;
    p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }
};

//Se pide hacer una función para generar un archivo nuevo (peligro.dat) con aquellos animales que no se hayan avistado desde enero de 2016. 
//Nota: se pueden desarrollar todas las funciones que se consideren necesarias.

class ArchivoPeligro{
private:
  char _nombre[30];
public:
  ArchivoPeligro(const char *nombre = "peligro.dat"){strcpy(_nombre, nombre);}  

  void grabarRgistroPeligro(Animal obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){cout << "No se pudo abrir el archivo";return;}
    fwrite(&obj, sizeof(Animal), 1, p);
    fclose(p);
  }

  void listarRegistrosPeligro(){
    Animal obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL){cout << "Error de apertura";return;}

    while (fread(&obj, sizeof(Animal), 1, p) == 1){
      obj.mostrar();
      cout << endl;
    }
    fclose(p);
  }

  int contarRegistros(){//cuantos registros tengo
    FILE *p = fopen(_nombre, "rb");
    if(p==NULL) return -1;  
    fseek(p, 0,2); //cursor al final del codigo
    int tam=ftell(p); //del principio hasta donde esta el cursor
    fclose(p);
    return tam/sizeof(Animal); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Animal leerPorIndicePeligro(int index){
    Animal reg;
    FILE *pFile = fopen(_nombre, "rb");   
    if(pFile == nullptr){return reg;}
    fseek(pFile, index * sizeof (Animal), SEEK_SET);   
    fread(&reg, sizeof(Animal), 1, pFile);
    fclose(pFile);
    return reg;   
  }

  void borrarRegistrosPeligro(){
    FILE *p;
    p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }
};

// PUNTO 1 Se pide hacer una función para generar un archivo nuevo (peligro.dat) con aquellos animales que no se hayan avistado desde enero de 2016" << endl;
void punto1(){
  Animal objA;// Código de animal (int), nombre (char[30]), clasificación (char[5]), zona de habitat (entero entre 1 y 10)
  ArchivoAnimal ARobjA; 

  Avistajes objAV;//Código de animal (int), fecha (día, mes y año)(2000 en adel), zona de avistaje (entero entre 1 y 10) 
  ArchivoAvistajes ARobjAV;

  ArchivoPeligro ARobjPeligro;
  ARobjPeligro.borrarRegistrosPeligro();

  int tam1 = ARobjA.contarRegistros();
  int tam2 = ARobjAV.contarRegistros();

  bool estaEnRegistro = true;
  for (int i = 0; i < tam1; i++){
    objA = ARobjA.leerPorIndice(i);

    estaEnRegistro = true;
    if(objA.getEstado()){
      for (int j = 0; j < tam2; j++){
        objAV = ARobjAV.leerPorIndice(j);


        if((objA.getCodigoAnimal() == objAV.getCodigoAnimal()) && (objAV.getFechaAvistamiento().getAnio() >= 2016)){
          estaEnRegistro = true;
          break;
        }else {   
          estaEnRegistro = false;
        }  
      }

      if(!estaEnRegistro){
        ARobjPeligro.grabarRgistroPeligro(objA);               
      }

    }
  }

  cout << "LISTAR peligro.dat -> aprete enter para continuar" << endl;
  system("pause");
  ARobjPeligro.listarRegistrosPeligro();

}


void menu(){
  Animal objA;// Código de animal (int), nombre (char[30]), clasificación (char[5]), zona de habitat (entero entre 1 y 10)
  ArchivoAnimal ARobjA; 

  Avistajes objAV;//Código de animal (int), fecha (día, mes y año), zona de avistaje (entero entre 1 y 10) 
  ArchivoAvistajes ARobjAV;

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar Animales: " << endl;
    cout << "2-Mostrar Animales: " << endl;
    cout << "3-Borrar Registros Animales" << endl;
    cout << "4-cargar Avistajes: " << endl;
    cout << "5-Mostrar Avistajes: " << endl;
    cout << "6-Borrar Registros Avistados: " << endl;
    cout << "---------------------" << endl;
    cout << "7-PUNTO 1 Se pide hacer una función para generar un archivo nuevo (peligro.dat) con aquellos animales que no se hayan avistado desde enero de 2016" << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {

    /**********************/
    case 1:{
    int num;
    cout<<"ingrese cantidad de animal a cargar: "; cin>>num;
      for(int i; i< num; i++){
        objA.cargar(); 
        ARobjA.grabarRgistroAnimal(objA);
      }
    }break;

    /**********************/
    case 2:
      ARobjA.listarRegistros();
      break;
    /**********************/
    case 3:{
      ARobjA.borrarRegistros();
    }break;
    
    case 4:{
      int num;
      cout << "Ingrese la cantidad de avistaje a cargar: "; cin >> num;
      for (int i = 0; i < num; i++){
        objAV.cargar();
        ARobjAV.grabarRgistroAvistajes(objAV);
      }
      }break;
    /**********************/
    case 5:
      ARobjAV.listarRegistrosAvistajes();
      break;
    /**********************/
    case 6:{
      ARobjAV.borrarRegistros();
    }break;
    case 7:{
      punto1();      
    }break;
    case 0:
      return;
    default:
      cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
      break;
    }
    system("pause");

  } 
}



int main(){

  menu();


  return 0;
}


