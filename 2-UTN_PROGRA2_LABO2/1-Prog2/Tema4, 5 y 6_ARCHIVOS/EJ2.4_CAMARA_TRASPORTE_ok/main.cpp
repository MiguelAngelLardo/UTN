#include <iostream>
#include <cstring>

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

class Fecha{
private:
  int dia,mes, anio;
public:
  void Cargar(){cin>>dia;cin>>mes;cin>>anio;}
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


/*
3) La Cámara de Transporte necesita realizar un análisis del rendimiento de los autobuses utilizados por las
empresas de colectivos durante el año pasado. 
En su sistema dispone de un conjunto de archivos, entre losque se destacan:
*/

//Empresa.dat -> Código de empresa (char[5]), nombre, dirección, tipo de empresa (1: local.; 2: interurbano; 3: nacional; 4:internacional)
class Empresa {
private:
  char _codigoEmpresa[5];
  char _nombre[20];
  char _direccion[20];
  int _tipoEmpresa;// 1 a 4
  bool _estado;

public:
  Empresa(const char *codEmpresa = "X", const char *nom = "X", const char *dir = "X", int tipo = 0, bool estado = true) : _tipoEmpresa(tipo), _estado(estado)
  {strcpy(_codigoEmpresa, codEmpresa);strcpy(_nombre, nom); strcpy(_direccion, dir);}

  void setCodigo(const char *ce){strcpy(_codigoEmpresa, ce);}
  void setNombre(const char *n){strcpy(_nombre, n);}
  void setDireccion(const char *d){strcpy(_direccion, d);}
  void setTipo(int t){_tipoEmpresa = t;}

  const char *getCodigo(){return _codigoEmpresa;}
  const char *getNombre(){return _nombre;}
  const char *getDireccion(){return _direccion;}
  int getTipo(){return _tipoEmpresa;}
  bool getEstado(){return _estado;}

  void cargar(){
    cout << "CODIGO EMPRESA: "; cargarCadena(_codigoEmpresa, 5);
    cout << "NOMBRE: "; cargarCadena(_nombre, 20);
    cout << "DIRECCION: "; cargarCadena(_direccion, 20);
    cout << "TIPO (1: local.; 2: interurbano; 3: nacional; 4:internacional): "; cin >> _tipoEmpresa;
    _estado = true;
  }

  void mostrar(){
    cout << "CODIGO EMPRESA: " << _codigoEmpresa << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "DIRECCION: " << _direccion << endl;
    cout << "TIPO: " << _tipoEmpresa << endl;
  }
};

class ArchivoEmpresa{
private:
  char _nombre[20];

public:
  ArchivoEmpresa(const char *nombre = "Empresa.dat"){strcpy(_nombre, nombre);}  
  void borrarregistrosEmpresa(){
   FILE *p = fopen(_nombre,"wb");
   if(p == NULL){cout<<"No se pudo borrar el archivo";}
   fclose(p);
  }
  void GuardarRegistroEmpresa(Empresa& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Empresa),1,p);
   fclose(p);
   return;
  }
  void listarRegistrosEmpresa(){
  Empresa obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}

  while (fread(&obj, sizeof(Empresa), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }
  int contarRegistrosEmpresa(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Empresa); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }
  Empresa leerPorIndiceEmpresa(int index){
   Empresa reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Empresa), SEEK_SET);   
   fread(&reg, sizeof(Empresa), 1, pFile);
   fclose(pFile);
   return reg;   
  }

};

//Viajes.dat -> Número de viaje, código de empresa, marca del autobús (1 a 10), cantidad de km del viaje (float), cantidad de combustible consumido (float), fecha.
class Viaje {
private:
  int _numeroViaje;
  char _codigoEmpresa[5];
  int _marcaAutobus;// 1 a 10
  float _kmViaje;
  float _litrosCombustibleConsumido;
  Fecha _fechaViaje;
  bool _estado;

public:
  Viaje(int n = 0, const char *ce = "X", int g = 0, float km = 0, float l = 0, Fecha f = Fecha(), bool estado = true) 
  : _numeroViaje(n), _marcaAutobus(g), _kmViaje(km), _litrosCombustibleConsumido(l), _fechaViaje(f), _estado(estado)
  {strcpy(_codigoEmpresa, ce);}

  void setNumeroViaje(int n){_numeroViaje = n;}
  void setCodigo(const char *ce){strcpy(_codigoEmpresa, ce);}
  void setMarcaAutobus(int g){_marcaAutobus = g;}
  void setKmViaje(float km){_kmViaje = km;}
  void setLitrosCombustibleConsumido(float l){_litrosCombustibleConsumido = l;}
  void setFechaViaje(Fecha f){_fechaViaje = f;}

  int getNumeroViaje(){return _numeroViaje;}
  const char *getCodigo(){return _codigoEmpresa;}
  int getMarcaAutobus(){return _marcaAutobus;}
  float getKmViaje(){return _kmViaje;}
  float getLitrosCombustibleConsumido(){return _litrosCombustibleConsumido;}
  Fecha getFechaViaje(){return _fechaViaje;}
  bool getEstado(){return _estado;}

  void cargar(){
    cout << "NUMERO VIAJE: "; cin >> _numeroViaje;
    cout << "CODIGO EMPRESA: "; cargarCadena(_codigoEmpresa, 5);
    cout << "MARCA AUTOBUS: "; cin >> _marcaAutobus;
    cout << "KM VIAJE: "; cin >> _kmViaje;
    cout << "LITROS COMBUSTIBLE CONSUMIDO: "; cin >> _litrosCombustibleConsumido;
    cout << "FECHA VIAJE: "; _fechaViaje.Cargar();
    _estado = true;
  }

  void mostrar(){
    cout << "NUMERO VIAJE: " << _numeroViaje << endl;
    cout << "CODIGO EMPRESA: " << _codigoEmpresa << endl;
    cout << "MARCA AUTOBUS: " << _marcaAutobus << endl;
    cout << "KM VIAJE: " << _kmViaje << endl;
    cout << "LITROS COMBUSTIBLE CONSUMIDO: " << _litrosCombustibleConsumido << endl;
    cout << "FECHA VIAJE: "; _fechaViaje.Mostrar();
  }
};

class ArchivoViaje {
private:
  char _nombre[20];
public:
  ArchivoViaje(const char *nombre = "Viajes.dat"){strcpy(_nombre, nombre);}

  void borrarregistrosViaje(){
    FILE *p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }
  void GuardarRegistroViaje(Viaje& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Viaje),1,p);
   fclose(p);
   return;
  }
  void listarRegistrosViaje(){
  Viaje obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}
  while (fread(&obj, sizeof(Viaje), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }
  int contarRegistrosViaje(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Viaje); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }
  Viaje leerPorIndiceViaje(int index){
   Viaje reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Viaje), SEEK_SET);   
   fread(&reg, sizeof(Viaje), 1, pFile);
   fclose(pFile);
   return reg;   
  }
};

//a) Generar un archivo con el siguiente formato: Código de empresa, nombre, y promedio de consumo de combustible entre todos los viajes.
class Punto1{
private:
  char _codigoEmpresa[5];
  char _nombre[20];
  float _promedioCombustibleEntreTodosLosViajes;

public:
  Punto1(const char *cod = "X", const char *nom = "X", float prom = 0.0){
    strcpy(_codigoEmpresa, cod);
    strcpy(_nombre, nom); 
    _promedioCombustibleEntreTodosLosViajes = prom;
  }

  void setCodigo(const char *ce){strcpy(_codigoEmpresa, ce);}
  void setNombre(const char *n){strcpy(_nombre, n);}
  void setPromedioCombustibleEntreTodosLosViajes(float p){_promedioCombustibleEntreTodosLosViajes = p;}
  void setearTodo(const char *cod, const char *nom, float prom){
    setCodigo(cod);
    setNombre(nom);
    setPromedioCombustibleEntreTodosLosViajes(prom);
  }

  const char *getCodigo(){return _codigoEmpresa;}
  const char *getNombre(){return _nombre;}
  float getPromedioCombustibleEntreTodosLosViajes(){return _promedioCombustibleEntreTodosLosViajes;}

  void mostrar(){
    cout << "CODIGO EMPRESA: " << _codigoEmpresa << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "PROMEDIO COMBUSTIBLE ENTRE TODOS LOS VIAJES: " << _promedioCombustibleEntreTodosLosViajes << endl;
  }
};

class ArchivoPunto1{
private:
  char _nombre[20];
public:
  ArchivoPunto1(const char *nombre = "Punto1.dat"){strcpy(_nombre, nombre);}

  void borrarregistrosPunto1(){
    FILE *p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }
  void GuardarRegistroPunto1(Punto1& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
   return;
  }
  void listarRegistrosPunto1(){
  Punto1 obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}
  while (fread(&obj, sizeof(Punto1), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }
  int contarRegistrosPunto1(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Punto1); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }
  Punto1 leerPorIndiceViaje(int index){
   Punto1 reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Punto1), SEEK_SET);   
   fread(&reg, sizeof(Punto1), 1, pFile);
   fclose(pFile);
   return reg;   
  }
};

//a) Generar un archivo con el siguiente formato: Código de empresa, nombre, y promedio de consumo de combustible entre todos los viajes.
void punto1(){
  Empresa objE;//codigoEmpresa (char), nombre, direccion, tipo (1,2,3,4)
  ArchivoEmpresa ARobE;

  Viaje objV;//numeroviaje, codigoEmpresa(char), marcAutobus(1 a 10), kmViaje, litrosCombustibleConsumido, fechaViaje
  ArchivoViaje ARobjV;

  Punto1 objP1;
  ArchivoPunto1 ARobjP1;
  ARobjP1.borrarregistrosPunto1();

  int tam1 = ARobE.contarRegistrosEmpresa();
  int tam2 = ARobjV.contarRegistrosViaje();

  int contador;
  float acumuladorLitros;
  for (int i = 0; i < tam1; i++)
  {
    contador = 0;
    acumuladorLitros = 0.0;
    
    objE = ARobE.leerPorIndiceEmpresa(i);
    if(objE.getEstado())
    {
      for(int j = 0; j < tam2; j++)
      {
        objV = ARobjV.leerPorIndiceViaje(j);

        if((strcmp(objE.getCodigo(), objV.getCodigo())==0) && (objV.getEstado())){
          contador ++;
          acumuladorLitros += objV.getLitrosCombustibleConsumido();
        }   
      }

      if(contador != 0){
        float promedio = acumuladorLitros/contador;
        objP1.setearTodo(objE.getCodigo(), objE.getNombre(), promedio);
        ARobjP1.GuardarRegistroPunto1(objP1);
      }
    }
  }  

  cout << "LISTANDO PUNTO 1 -> presione ENTER" << endl;
  system("pause");
  ARobjP1.listarRegistrosPunto1();
}
   
  
//b) Por cada mes y marca la cantidad de combustible consumido.
void punto2(){
  Viaje objV;//numeroviaje, codigoEmpresa(char), marcAutobus(1 a 10), kmViaje, litrosCombustibleConsumido, fechaViaje
  ArchivoViaje ARobjV;

  float mMarcasMesesAcumLitros[10][12] = {};

  int tam = ARobjV.contarRegistrosViaje();

  for (int i = 0; i < tam; i++){
    objV = ARobjV.leerPorIndiceViaje(i);
    if(objV.getEstado()){
      mMarcasMesesAcumLitros[objV.getMarcaAutobus()-1][objV.getFechaViaje().getMes()-1] += objV.getLitrosCombustibleConsumido();
    }  
  }

  cout << "MOSTRANDO PUNTO 2 -> presione ENTER" << endl;
  system("pause");
  for(int i = 0; i < 10; i++){
    cout << "MARCA: " << i+1 << endl;
    for(int j = 0; j < 12; j++){
      cout << "\tMES: " << j+1 << " Ligros Consumidos = " << mMarcasMesesAcumLitros[i][j] << endl;
    }  
  }  
}


void menu(){
  Empresa objE;//codigoEmpresa (char), nombre, direccion, tipo (1,2,3,4)
  ArchivoEmpresa ARobE;

  Viaje objV;//numeroviaje, codigoEmpresa(char), marcAutobus(1 a 10), kmViaje, litrosCombustibleConsumido, fechaViaje
  ArchivoViaje ARobjV;

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar EMPRESAS" << endl;
    cout << "2-Mostrar EMPRESAS" << endl;
    cout << "3-Borrar EMPRESAS" << endl;
    cout << "4-cargar VIAJES" << endl;
    cout << "5-Mostrar VIAJES" << endl;
    cout << "6-Borrar VIAJES" << endl;
    cout << "---------------------" << endl;
    cout << "7-PUNTO 1-a) Generar un archivo con el siguiente formato: Código de empresa, nombre, y promedio de consumo de combustible entre todos los viajes." << endl;
    cout << "8-PUNTO 2-b) Por cada mes y marca la cantidad de combustible consumido." << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {

    /**********************/
    case 1:{
    int num;
    cout<<"ingrese cantidad de EMPRESAS a cargar: "; cin>>num;
      for(int i; i<num; i++){
        objE.cargar();
        cout << endl;
        ARobE.GuardarRegistroEmpresa(objE);        
      }
    }break;
    /**********************/
    case 2:
      ARobE.listarRegistrosEmpresa();
      break;
    /**********************/
     case 3:{
       ARobE.borrarregistrosEmpresa();
     }break;
    /**********************/
    case 4:{
      int num;
      cout << "Ingrese la cantidad de VIAJES a cargar: "; cin >> num;
      for (int i = 0; i < num; i++){
        objV.cargar();
        cout < endl;
        ARobjV.GuardarRegistroViaje(objV);
      }
      }break;
    /**********************/
    case 5:
      ARobjV.listarRegistrosViaje();
      break;
    /**********************/
    case 6:{
      ARobjV.borrarregistrosViaje();
    }break;
    /**********************/
    case 7:{
      punto1();
    }break;
    /*********************/
    case 8:{
      punto2();
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

int main() {
  menu();

  return 0;
}