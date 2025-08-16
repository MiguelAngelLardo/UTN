#pragma once

#include<iostream>
#include<cstring>//para strcpy


using namespace std;


void cargarCadena1(char *pal, int tam){
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
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}
  
      void Cargar(){
          cout << "Dia: "; cin>>dia;
          cout << "Mes: "; cin>>mes;
          cout << "Anio: "; cin>>anio;
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

class Tecnicos{
private:
  int _DNI;
  char _nombreApellido[50];
  int _provincia; //1 al 10
  int _puesto;//1 al 10
  float _saldo;
  Fecha _fechaIngreso;

public:
  void setDni(int dni){_DNI=dni;}
  void setNombreApellido(const char* na){strcpy(_nombreApellido,na);}
  void setProvincia(int prov){_provincia=prov;}
  void setPuesto(int p){_puesto=p;}
  void setSaldo(float s){_saldo=s;}
  void setFechaIngreso(Fecha fi){_fechaIngreso=fi;}
  
  int getDni(){return _DNI;}
  const char* getNombreApellido(){return _nombreApellido;}
  int getProvincia(){return _provincia;}
  int getPuesto(){return _puesto;}
  float getSaldo(){return _saldo;}
  Fecha getFechaIngreso(){return _fechaIngreso;}

  //metodos
  void cargar(){
    cout << "DNI: "; cin>>_DNI;
    cout<<"Nombre y apellido: "; cargarCadena1(_nombreApellido,50);
    cout << "Provincia: "; cin>>_provincia;
    cout << "Puesto: "; cin>>_puesto;
    cout << "Saldo: "; cin>>_saldo;
    _fechaIngreso.Cargar();
  }

  void mostrar(){
    cout << "DNI: " << _DNI << endl;
    cout << "Nombre y Apellido: " << _nombreApellido << endl;
    cout << "Provincia: " << _provincia << endl;
    cout << "Puesto: " << _puesto << endl;
    cout << "Saldo: " << _saldo << endl;
    cout << "Fecha de Ingreso: "; _fechaIngreso.Mostrar();
  }


    //constructor
    Tecnicos(){}
    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Tecnicos(){}

};

class ArchivoTecnicos{
public:
void GuardarArchivo(Tecnicos& obj,const char* nombre = "Tecnicos.dat"){
 FILE *p;
 p = fopen(nombre,"ab");
 if(p == NULL){
    cout<<"No se pudo abrir el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fwrite(&obj,sizeof(Tecnicos),1,p);
 fclose(p);
}

int contarRegistros(const char* nombre="Tecnicos.dat"){
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
      fseek(p, 0,2);
      int tam=ftell(p);
      fclose(p);
      return tam/sizeof(Tecnicos);
  }

Tecnicos leerRegistro(int pos,const char* nombre="Tecnicos.dat"){
      Tecnicos reg;
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
      fseek(p, sizeof reg*pos,0);
      fread(&reg, sizeof reg,1, p);
      fclose(p);
      return reg;
  }

bool reemplazarRegistro(Tecnicos& reg, int posicionAReemplazar,const char* nombre="Tecnicos.dat"){
  FILE *p = fopen(nombre, "rb+");
  if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
  fseek(p, posicionAReemplazar * sizeof(Tecnicos), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Tecnicos), 1, p);
  fclose(p);
  return pudoEscribir;
}

void cargarArchivo(int tam=1,const char* nombre="Tecnicos.dat"){
  Tecnicos objE;
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
  fwrite(&objE, sizeof(Tecnicos), 1, p);
  }

  fclose(p);
}

void crearArchivo(int tam=1,const char* nombre="Tecnicos.dat"){
  Tecnicos objE;
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
  fwrite(&objE, sizeof(Tecnicos), 1, p);
  }

  fclose(p);
}

void mostrarArchivo(const char* nombre="Tecnicos.dat"){
  Tecnicos objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
      cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
      //cout<<"En la Linea: "<<__LINE__<<endl;
      exit(1);
  }
while (fread(&objE, sizeof(Tecnicos), 1, p) == true){
  objE.mostrar();
  cout << endl;
}
  fclose(p);
}

void BorrarArchivo(const char* nombre="Tecnicos.dat"){
 FILE *p;
 p = fopen(nombre,"wb");
 if(p == NULL){
    cout<<"No se pudo borrar el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fclose(p);
}

// bool ExisteDNI(int dni,const char* nombre="Tecnicos.dat"){
//  Tecnicos obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Tecnicos),1,p)){
//     if((obj.getDNI()==dni)){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

// bool ExisteCHAR(const char* dni,const char* nombre="Tecnicos.dat"){
//  Tecnicos obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Tecnicos),1,p)){
//     if((strcmp(obj.getCodigoJugador(),dni)==0)){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

};

class Tecnicos_Obras{
private:
  int _numeroObra;
  int _DNITecnico;
  Fecha _fechaInicio;
  int _tipo; // 1 al 5

public:
  void setNumeroObra(int no){_numeroObra=no;}
  void setDNITecnico(int dni){_DNITecnico=dni;}
  void setFechaInicio(Fecha fi){_fechaInicio=fi;}
  void setTipo(int t){_tipo=t;}

  int getNumeroObra(){return _numeroObra;}
  int getDNITecnico(){return _DNITecnico;}
  Fecha getFechaInicio(){return _fechaInicio;}
  int getTipo(){return _tipo;}

  //metodos
  void cargar(){
    cout << "Numero de Obra: "; cin>>_numeroObra;
    cout << "DNI: "; cin>>_DNITecnico;
    _fechaInicio.Cargar();
    cout << "Tipo: "; cin>>_tipo;
  }
  void mostrar(){
    cout << "Numero de Obra: " << _numeroObra << endl;
    cout << "DNI: " << _DNITecnico << endl;
    cout << "Fecha de Inicio: "; _fechaInicio.Mostrar();
    cout << "Tipo: " << _tipo << endl;
  }

  //constructor
  Tecnicos_Obras(){}

  //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
 // ~Tecnicos_Obras(){}

};

class ArchivoTecnicos_Obras{

  public:

//metodos

void GuardarArchivo(Tecnicos_Obras& obj,const char* nombre = "Tecnicos_Obras.dat"){
 FILE *p;
 p = fopen(nombre,"ab");
 if(p == NULL){
    cout<<"No se pudo abrir el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fwrite(&obj,sizeof(Tecnicos_Obras),1,p);
 fclose(p);
}

int contarRegistros(const char* nombre="Tecnicos_Obras.dat"){
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
      fseek(p, 0,2);
      int tam=ftell(p);
      fclose(p);
      return tam/sizeof(Tecnicos_Obras);
  }

Tecnicos_Obras leerRegistro(int pos,const char* nombre="Tecnicos_Obras.dat"){
      Tecnicos_Obras reg;
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
      fseek(p, sizeof reg*pos,0);
      fread(&reg, sizeof reg,1, p);
      fclose(p);
      return reg;
  }

bool reemplazarRegistro(Tecnicos_Obras& reg, int posicionAReemplazar,const char* nombre="Tecnicos_Obras.dat"){
  FILE *p = fopen(nombre, "rb+");
  if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
  fseek(p, posicionAReemplazar * sizeof(Tecnicos_Obras), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Tecnicos_Obras), 1, p);
  fclose(p);
  return pudoEscribir;
}

void cargarArchivo(int tam=1,const char* nombre="Tecnicos_Obras.dat"){
  Tecnicos_Obras objE;
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
  fwrite(&objE, sizeof(Tecnicos_Obras), 1, p);
  }

  fclose(p);
}

void crearArchivo(int tam=1,const char* nombre="Tecnicos_Obras.dat"){
  Tecnicos_Obras objE;
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
  fwrite(&objE, sizeof(Tecnicos_Obras), 1, p);
  }

  fclose(p);
}

void mostrarArchivo(const char* nombre="Tecnicos_Obras.dat"){
  Tecnicos_Obras objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
      cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
      //cout<<"En la Linea: "<<__LINE__<<endl;
      exit(1);
  }
while (fread(&objE, sizeof(Tecnicos_Obras), 1, p) == true){
  objE.mostrar();
  cout << endl;
}
  fclose(p);
}

void BorrarArchivo(const char* nombre="Tecnicos_Obras.dat"){
 FILE *p;
 p = fopen(nombre,"wb");
 if(p == NULL){
    cout<<"No se pudo borrar el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fclose(p);
}

// bool ExisteDNI(int dni,const char* nombre="Tecnicos_Obras.dat"){
//  Tecnicos_Obras obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Tecnicos_Obras),1,p)){
//     if((obj.getDNI()==dni)&&(obj.getEstado())){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

// bool ExisteCHAR(const char* dni,const char* nombre="Tecnicos_Obras.dat"){
//  Tecnicos_Obras obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Tecnicos_Obras),1,p)){
//     if((strcmp(obj.getCodigoJugador(),dni)==0)&&(obj.getEstado()){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

};