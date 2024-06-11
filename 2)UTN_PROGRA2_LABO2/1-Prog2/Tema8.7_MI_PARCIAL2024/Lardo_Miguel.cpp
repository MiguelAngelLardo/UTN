#include<iostream>
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

class Pais{

private:
  char _codigoPais[5];
  char _nombrePais[30];
  int _codigoContinente;//1 a 5
  int _nivelDeIngreso;//1: alto; 2: mediano; 3: mediano alto; 4: mediano bajo; 5: bajo
  int _cantidadHabitantes;
  float _PBI;
  bool _estado;

public:
  
  const char* getCodigoPais(){return _codigoPais;}
  const char* getNombrePais(){return _nombrePais;}
  int getCodigoContinente(){return _codigoContinente;}
  int getNivelIngreso(){return _nivelDeIngreso;}
  int getCantidadHabitantes(){return _cantidadHabitantes;}
  float getPBI(){return _PBI;}
  bool getEstado(){return _estado;}

  void cargar(){
    cout << "CODIGO PAIS: "; cargarCadena(_codigoPais, 5);
    cout << "NOMBRE PAIS: "; cargarCadena(_nombrePais, 30);
    cout << "CODIGO CONTINENTE: "; cin >> _codigoContinente;
    cout << "NIVEL DE INGRESO: "; cin >> _nivelDeIngreso;
    cout << "CANTIDAD DE HABITANTES: "; cin >> _cantidadHabitantes;
    cout << "PBI: "; cin >> _PBI;
    _estado = true;
  }

  void cargar(){
    cout << "CODIGO PAIS: "; cargarCadena(_codigoPais, 5);
    cout << "NOMBRE PAIS: "; cargarCadena(_nombrePais, 30);
    cout << "CODIGO CONTINENTE: "; cin >> _codigoContinente;
    cout << "NIVEL DE INGRESO: "; cin >> _nivelDeIngreso;
    cout << "CANTIDAD DE HABITANTES: "; cin >> _cantidadHabitantes;
    cout << "PBI: "; cin >> _PBI;
    _estado = true;
  }

  void mostrar(){
    cout << "CODIGO PAIS: " << _codigoPais << endl;
    cout << "NOMBRE PAIS: " << _nombrePais << endl;
    cout << "CODIGO CONTINENTE: " << _codigoContinente << endl;
    cout << "NIVEL DE INGRESO: " << _nivelDeIngreso << endl;
    cout << "CANTIDAD DE HABITANTES: " << _cantidadHabitantes << endl;
    cout << "PBI: " << _PBI << endl;
  }

};

class ArchivoPais{
private:
  char _nombre[20];

public:
  ArchivoPais(const char *nombre = "paises.dat"){strcpy(_nombre, nombre);}  
  void borrarRegistrosPais(){
   FILE *p = fopen(_nombre,"wb");
   if(p == NULL){cout<<"No se pudo borrar el archivo";}
   fclose(p);
  }
  void GuardarRegistroPais(Pais& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Pais),1,p);
   fclose(p);
   return;
  }
  void listarRegistrosPais(){
  Pais obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}

  while (fread(&obj, sizeof(Pais), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }
  int contarRegistrosPais(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Pais); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }
  Pais leerPorIndicePais(int index){
   Pais reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Pais), SEEK_SET);   
   fread(&reg, sizeof(Pais), 1, pFile);
   fclose(pFile);
   return reg;   
  }

};


class Continente{
private:
    int _codigoContinente;
    char _nombreContinente[30];
  

  public:

    int getCodigoContinente(){return _codigoContinente;}
    const char* getNombreContinente(){return _nombreContinente;}

    void cargar(){
      cout << "CODIGO CONTINENTE: "; cin >> _codigoContinente;
      cout << "NOMBRE CONTINENTE: "; cargarCadena(_nombreContinente, 30);
    }

    void mostrar(){
      cout << "CODIGO CONTINENTE: " << _codigoContinente << endl;
      cout << "NOMBRE CONTINENTE: " << _nombreContinente << endl;
    }

    //sobrecarga operador
    bool operator==(Pais objP){
      return (_codigoContinente == objP.getCodigoContinente()) ? true : false;        
    }

  
};

class ArchivoContinente{
private:
  char _nombre[20];

public:
  ArchivoContinente(const char *nombre = "continentes.dat"){strcpy(_nombre, nombre);}  
  
  void borrarRegistrosContinente(){
   FILE *p = fopen(_nombre,"wb");
   if(p == NULL){cout<<"No se pudo borrar el archivo";}
   fclose(p);
  }

  void GuardarRegistroContinente(Continente& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Continente),1,p);
   fclose(p);
   return;
  }

  void listarRegistrosContinente(){
  Continente obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}

  while (fread(&obj, sizeof(Continente), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }

  int contarRegistrosContinente(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Continente); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Continente leerPorIndiceContinente(int index){
   Continente reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Continente), SEEK_SET);   
   fread(&reg, sizeof(Continente), 1, pFile);
   fclose(pFile);
   return reg;   
  }

};

//PUNTO2
class PaisesIngresoBajo{
private:
  char _codigoPais[5];
  char _nombrePais[30];
  int _codigoContinente;//1 a 5
  int _nivelDeIngreso;//1: alto; 2: mediano; 3: mediano alto; 4: mediano bajo; 5: bajo
  int _cantidadHabitantes;
  float _PBI;
  bool _estado;

public:

  void setearTodo(const char* codigoPais, const char* nombrePais, int codigoContinente, int nivelDeIngreso, int cantidadHabitantes, float PBI){
    strcpy(_codigoPais, codigoPais);
    strcpy(_nombrePais, nombrePais);
    _codigoContinente = codigoContinente;
    _nivelDeIngreso = nivelDeIngreso;
    _cantidadHabitantes = cantidadHabitantes;
    _PBI = PBI;
    _estado = true;
  }
  
  const char* getCodigoPais(){return _codigoPais;}
  const char* getNombrePais(){return _nombrePais;}
  int getCodigoContinente(){return _codigoContinente;}
  int getNivelIngreso(){return _nivelDeIngreso;}
  int getCantidadHabitantes(){return _cantidadHabitantes;}
  float getPBI(){return _PBI;}
  bool getEstado(){return _estado;}

  void cargar(){
    cout << "CODIGO PAIS: "; cargarCadena(_codigoPais, 5);
    cout << "NOMBRE PAIS: "; cargarCadena(_nombrePais, 30);
    cout << "CODIGO CONTINENTE: "; cin >> _codigoContinente;
    cout << "NIVEL DE INGRESO: "; cin >> _nivelDeIngreso;
    cout << "CANTIDAD DE HABITANTES: "; cin >> _cantidadHabitantes;
    cout << "PBI: "; cin >> _PBI;
    _estado = true;
  }

  void mostrar(){
    cout << "CODIGO PAIS: " << _codigoPais << endl;
    cout << "NOMBRE PAIS: " << _nombrePais << endl;
    cout << "CODIGO CONTINENTE: " << _codigoContinente << endl;
    cout << "NIVEL DE INGRESO: " << _nivelDeIngreso << endl;
    cout << "CANTIDAD DE HABITANTES: " << _cantidadHabitantes << endl;
    cout << "PBI: " << _PBI << endl;
  }

};

class ArchivoPaisesIngresoBajo{
private:
  char _nombre[20];

public:
  ArchivoPaisesIngresoBajo(const char *nombre = "paisesingresosbajos.dat"){strcpy(_nombre, nombre);}  
  void borrarRegistrosPais(){
   FILE *p = fopen(_nombre,"wb");
   if(p == NULL){cout<<"No se pudo borrar el archivo";}
   fclose(p);
  }

  void GuardarRegistroPais(PaisesIngresoBajo& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(PaisesIngresoBajo),1,p);
   fclose(p);
   return;
  }

  void listarRegistrosPais(){
  PaisesIngresoBajo obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}

  while (fread(&obj, sizeof(PaisesIngresoBajo), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }

  int contarRegistrosPais(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(PaisesIngresoBajo); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

 PaisesIngresoBajo leerPorIndicePais(int index){
   PaisesIngresoBajo reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (PaisesIngresoBajo), SEEK_SET);   
   fread(&reg, sizeof(PaisesIngresoBajo), 1, pFile);
   fclose(pFile);
   return reg;   
  }

};





//calcular e informar los continente con mas de 20 paises
void punto1(){
 Continente objC;//codigoCOntinente(PK)
  ArchivoContinente ARobjC("continentes.dat");

  Pais objP;//codigoContinente(FK)
  ArchivoPais ARobjP("paises.dat");

  int vAcumPaisesPorContinente5[5];

  int tam1 = ARobjC.contarRegistrosContinente();
  int tam2 = ARobjP.contarRegistrosPais();

  for(int i = 0; i < tam1; i++){
    objC = ARobjC.leerPorIndiceContinente(i);
    //no hago el if(objC.getEstado() ==true) por que no esta especificado
    for (int j = 0; j < tam2; j++){
      objP = ARobjP.leerPorIndicePais(j);
      if((objP.getEstado()) && (objC.getCodigoContinente() == objP.getCodigoContinente()) && (objC == objP)){//(objC == objP) es redundante para el pto 4
        vAcumPaisesPorContinente5[objC.getCodigoContinente()-1]++;
      }
    }
  }  

  cout << "Los continentes con mas de 20 paises son: " << endl;
  for(int i = 0; i < 5; i++){
    if(vAcumPaisesPorContinente5[i] > 20){
      cout << "El continente " << i+1 << " tiene " << vAcumPaisesPorContinente5[i] << " paises" << endl;
    }
  }
}


//generar un archivo con los paises de ingreso BAJO(5) que pertenezcan al continente de ASIA. EL formato es IDEM al archivo Pais
void punto2(){
  Continente objC;//codigoCOntinente(PK) , **nombre asia**
  ArchivoContinente ARobjC("continentes.dat");

  Pais objP;//codigoContinente(FK), **nivelIngreso 5**
  ArchivoPais ARobjP("paises.dat");

  PaisesIngresoBajo objPunto2; 
  ArchivoPaisesIngresoBajo ARobjPunto2;
  ARobjPunto2.borrarRegistrosPais();

  int tam1 = ARobjC.contarRegistrosContinente();
  int tam2 = ARobjP.contarRegistrosPais();

  for(int i = 0; i < tam1; i++){
    objC = ARobjC.leerPorIndiceContinente(i);

    for(int j = 0; j < tam2; j++){
      objP = ARobjP.leerPorIndicePais(j);
      if((objP.getEstado()) && (objC.getCodigoContinente() == objP.getCodigoContinente()) && (strcmp(objC.getNombreContinente(), "Asia")==0) && (objP.getNivelIngreso() == 5)){
        objPunto2.setearTodo(objP.getCodigoPais(), objP.getNombrePais(), objP.getCodigoContinente(), objP.getNivelIngreso(), objP.getCantidadHabitantes(), objP.getPBI());
        ARobjPunto2.GuardarRegistroPais(objPunto2);
      }
    }
  }


  ARobjPunto2.listarRegistrosPais();

}

void punto3(){ //con memoria dinamica listar
  Continente objC;//codigoCOntinente(PK) , **nombre asia**
  ArchivoContinente ARobjC("continentes.dat");

  Pais objP;//codigoContinente(FK), **nivelIngreso 5**
  ArchivoPais ARobjP("paises.dat");

  PaisesIngresoBajo objPunto2; 
  ArchivoPaisesIngresoBajo ARobjPunto2;
  ARobjPunto2.borrarRegistrosPais();
  
  int contIndex = 0;
  PaisesIngresoBajo *vPunto3;

  int tam1 = ARobjC.contarRegistrosContinente();
  int tam2 = ARobjP.contarRegistrosPais();

  for(int i = 0; i < tam1; i++){
    objC = ARobjC.leerPorIndiceContinente(i);

    for(int j = 0; j < tam2; j++){
      objP = ARobjP.leerPorIndicePais(j);
      if((objP.getEstado()) && (objC.getCodigoContinente() == objP.getCodigoContinente()) && (strcmp(objC.getNombreContinente(), "Asia")==0) && (objP.getNivelIngreso() == 5)){
        objPunto2.setearTodo(objP.getCodigoPais(), objP.getNombrePais(), objP.getCodigoContinente(), objP.getNivelIngreso(), objP.getCantidadHabitantes(), objP.getPBI());
        ARobjPunto2.GuardarRegistroPais(objPunto2);
        contIndex ++;
      }
    }
  }

  vPunto3 = new PaisesIngresoBajo[contIndex];
  if(vPunto3 == NULL){cout<<"No se pudo crear el vector";exit(1);}

  for(int i = 0; i < contIndex; i++){
    vPunto3[i] = ARobjPunto2.leerPorIndicePais(i);
  }

  
  cout << "paises de ingreso BAJO(5) que pertenezcan al continente de ASIA.";
  for(int i = 0; i < contIndex; i++){
    vPunto3[i].mostrar();
    cout << endl;
  }  




}



int main(){
  Continente objC;//codigoCOntinente(PK) , **nombre asia**
  ArchivoContinente ARobjC("continentes.dat");

  for(int i = 0; i < 5; i++){
    cout << "CONTINENTE " << i+1 << endl;
    objC.cargar();
    ARobjC.GuardarRegistroContinente(objC);
    cout << endl;
  }

  Pais objP;//codigoContinente(FK), **nivelIngreso 5**
  ArchivoPais ARobjP("paises.dat");

  for(int i = 0; i < 30; i++){
    cout << "PAIS " << i+1 << endl;
    objP.cargar();
    ARobjP.GuardarRegistroPais(objP);
    cout << endl;
  }

    punto1();
    punto2();//listar comun
    punto3();//listar mem dinamica


    return 0;
}