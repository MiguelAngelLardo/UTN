#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

/*
/*
2) Una peluquería tiene un archivo (color.dat) con la información de las coloraciones (tinturas) realizadas a
los/las clientes en lo que va del año. 

Cada registro contiene los siguientes campos:
Código de tintura (número entero entre el 100 y el 135), fecha (día, mes y año), género (‘H’: hombre; ‘M’:
mujer; ‘O’: otro), tipo de pelo.
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
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int dia = 0, int mes = 0, int anio = 0){this->dia = dia; this->mes = mes; this->anio = anio;}

        //setters y getters
        void setDia(const int dia){this->dia = dia;}
        void setMes(const int mes){this->mes = mes;}
        void setAnio(const int anio){this->anio = anio;}
        void setearTodo(const int dia, const int mes, const int anio){this->dia = dia; this->mes = mes; this->anio = anio;}

        int getDia()const{return dia;}
        int getMes()const{return mes;}
        int getAnio()const{return anio;}

        void cargar(){
            cout<<"Dia: "; cin >> dia;
            cout<<"Mes: "; cin >> mes;
            cout<<"Anio: "; cin >> anio;
        }

        void mostrarFecha(){cout << dia << "/" << mes << "/" << anio << endl;}
        
        int getDiaActual()
        {
            time_t t = time(NULL); //time_t es un alias para un entero de 32 y 64 bits - time(NULL) nos da el el tiempo en formato 'timestamp' -> "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
            struct tm *f = localtime(&t);// el struct tm convierte el timestamp a un formato entendible
            dia = (*f).tm_mday; ////(*f).tm_mday => indirecciona f y accede a tm_day
            return dia;                     
        }

        int getMesActual()
        {
            time_t t = time(NULL);
            struct tm *f = localtime(&t);

            mes = f->tm_mon + 1;
            return mes;
        }

        int getAnioActual()
        {
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
        
            anio = f->tm_year + 1900;
            return anio;
        }
        int getHoraActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_hour;
        }

        int getMinutoActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_min;
        }

        int getSegundoActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_sec;
        }
};



class Peluqueria{
private:
  int _codigoTintura;//100 al 135
  Fecha _fechaAplicacion;
  char _genero;//'H' hombre, 'M' mujer, 'O' otro
  char _tipoPelo[30];//rubio, morocho, rojizo, castaño
  bool estado;

public: 
  Peluqueria(int codigoTintura = 0, Fecha fechaAplicacion = Fecha(), char genero = 'X', const char *tipoPelo = "X"){
    _codigoTintura = codigoTintura;
    _fechaAplicacion = fechaAplicacion;
    _genero = genero;
    strcpy(_tipoPelo, tipoPelo);
  }

  void setCodigoTintura(int codigoTintura){_codigoTintura = codigoTintura;}
  void setFechaAplicacion(Fecha fechaAplicacion){_fechaAplicacion = fechaAplicacion;}
  void setGenero(char genero){_genero = genero;}
  void setTipoPelo(const char *tipoPelo){strcpy(_tipoPelo, tipoPelo);}

  int getCodigoTintura(){return _codigoTintura;}
  Fecha getFechaAplicacion(){return _fechaAplicacion;}
  char getGenero(){return _genero;}
  char *getTipoPelo(){return _tipoPelo;}
  bool getEstado(){return estado;}

  void cargar(){
    cout << "CODIGO DE TINTURA: "; cin >> _codigoTintura;
    cout << "FEHCA APLICACION: ";
    _fechaAplicacion.cargar();
    cout << "GENERO (H/M/O): "; cin >> _genero;
    cout << "TIPO DE PELO(rubio, morocho, etc): ";
    cargarCadena(_tipoPelo, 30);
    estado = true;
  }

  void mostrar(){
    cout << "CODIGO DE TINTURA: " << _codigoTintura << endl;
    cout << "FECHA APLICACION: ";
    _fechaAplicacion.mostrarFecha();
    cout << "GENERO: " << _genero << endl;
    cout << "TIPO DE PELO: " << _tipoPelo << endl;
  }
};

class ArchivoPeluqueria{
private:
  char _nombre[30];
public:
  ArchivoPeluqueria(const char *nombre = "peluquerias.dat"){
    strcpy(_nombre, nombre);
  }

  void borrarArchivo(){
    FILE *p = fopen(_nombre,"wb");
    if(p == NULL){cout<<"No se pudo borrar el archivo";}
    fclose(p);
  }

  void GuardarRegistro(Peluqueria& obj){
    FILE *p =fopen(_nombre,"ab");
    if(p == NULL){return;}
    fwrite(&obj,sizeof(Peluqueria),1,p);
    fclose(p);
    return;
  }

  void listarRegistros(){
    Peluqueria obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL){cout << "Error de apertura";return;}

    while (fread(&obj, sizeof(Peluqueria), 1, p) == 1){
      obj.mostrar();
      cout << endl;
    }
  }
  

  int contarRegistros(){
    FILE *p = fopen(_nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2); //cursor al final del codigo
    int tam=ftell(p); //del principio hasta donde esta el cursor
    fclose(p);
    return tam/sizeof(Peluqueria); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Peluqueria leerPorIndice(int index){
    Peluqueria reg;
    FILE *pFile = fopen(_nombre, "rb");
    if(pFile == nullptr){return reg;}
    fseek(pFile, index * sizeof (Peluqueria), SEEK_SET);   
    fread(&reg, sizeof(Peluqueria), 1, pFile);
    fclose(pFile);
    return reg;   
  }

};


//Hacer un programa para informar el/los códigos de tintura que hayan registrado al menos 10 coloraciones en el mes de marzo.

void punto1(){
  Peluqueria objP; //codigoTintura 100 al 135, fechaAplicacion, genero, tipoPelo
  ArchivoPeluqueria ARobjP;
  //ARobjP.borrarArchivo();

  int tam = ARobjP.contarRegistros();

  int vCodTintura[36] = {};  //0 a 35 = 36

  cout << "***for***" << endl;
  for (int i = 0; i < tam; i++){

    objP = ARobjP.leerPorIndice(i);

    if((objP.getEstado() == true) && (objP.getFechaAplicacion().getMes() == 3)){
      vCodTintura[objP.getCodigoTintura()-100] ++;  
    }  
  }

   cout << "CODIGOS DE TINTURA QUE HAN SIDO APLICADAS EN MARZO CON MAS DE 10 COLORACIONES: " << endl;  
  for (int i = 0; i < 36; i++){
    if(vCodTintura[i] >= 10){
      cout << "CODIGO TINTURA (100-135)" <<  i + 100 << " -> CANTIDAD TODAL " << vCodTintura[i] << endl;
    }
  }  
}


void menu(){
Peluqueria objP; //codigoTintura, fechaAplicacion, genero, tipoPelo
ArchivoPeluqueria ARobjP;

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar Peluquerias" << endl;
    cout << "2-Mostrar Peluqierias" << endl;
    cout << "---------------------" << endl;
    cout << "3-PUNTO 1 - informar el/los códigos de tintura que hayan registrado al menos 10 coloraciones en el mes de marzo." << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {
    /**********************/
    case 1:{
      int num;
      cout<<"ingrese cantidad de PELUQUERIAS a cargar: "; cin>>num;
      for(int i; i<num; i++){
        objP.cargar();
        cout << endl;
        ARobjP.GuardarRegistro(objP);
      }
      }break;
    /**********************/
    case 2:
      ARobjP.listarRegistros();
      break;
    /**********************/
    case 3:{
      punto1();      
      }break;
    /**********************/
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