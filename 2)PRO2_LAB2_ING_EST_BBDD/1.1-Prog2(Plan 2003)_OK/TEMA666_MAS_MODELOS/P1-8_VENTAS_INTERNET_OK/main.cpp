

#include<iostream>
#include<cstring>//strcpy

using namespace std;

#include"clases.h"

class Punto1{
private:
    char _codigoVendedor[5];
    char _nombreVendedor[30];
    public:

    void setCodigoVendedor(const char* codigoVendedor){strcpy(_codigoVendedor, codigoVendedor);}
    void setNombreVendedor(const char* nombreVendedor){strcpy(_nombreVendedor, nombreVendedor);}

    const char* getCodigoVendedor(){return _codigoVendedor;}
    const char* getNombreVendedor(){return _nombreVendedor;}

    void setearTodo(const char* codigoVendedor, const char* nombreVendedor){
        setCodigoVendedor(codigoVendedor);
        setNombreVendedor(nombreVendedor);
    }
    
    //metodos
    void cargar(){
        cout << "Codigo Vendedor: ";cargarCadena(_codigoVendedor, 5);
        cout << "Nombre Vendedor: ";cargarCadena(_nombreVendedor, 30);
        
    }
    void mostrar(){
        cout << "Codigo Vendedor: " << _codigoVendedor << endl;
        cout << "Nombre Vendedor: " << _nombreVendedor << endl;
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
bool ExisteDNIchar(const char* dni){
   Punto1 obj;
   FILE *p;
   p = fopen(nombre,"rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   while(fread(&obj,sizeof(Punto1),1,p)){
      if(strcmp(obj.getCodigoVendedor(),dni)==0){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}
};

void punto1a(){ //usando banderas
    Vendedores objVendedor; //PK codigo Vendedor
    ArchivoVendedores objArcVendedor;

    Ventas objVta; //FK codigo Venta
    ArchivoVentas objArcVta;

    Punto1 objPunto1;
    ArchivoPunto1 objArcPunto1;

    objArcPunto1.BorrarArchivo();

    int tamVendedor = objArcVendedor.contarRegistros();
    int tamVta = objArcVta.contarRegistros();
    bool tieneVenta2024;
    bool estaEnLaFK;

    for(int x = 0; x < tamVendedor; x++){
      objVendedor = objArcVendedor.leerRegistro(x);

       bool tieneVenta2024 = false; // Bandera para ventas en 2024
      bool tieneVentas = false;   // Bandera para verificar si el vendedor tiene alguna venta


      for(int y = 0; y < tamVta; y++){
        objVta = objArcVta.leerRegistro(y);

         // Verifico si el código de vendedor coincide
        if (strcmp(objVendedor.getCodigoVendedor(), objVta.getCodigoVendedor()) == 0) {
          tieneVentas = true; // Tiene al menos una venta

          // Verifico si la venta corresponde al año 2024
          if (objVta.getFechaVenta().getAnio() == 2024) {
            tieneVenta2024 = true; // Hay una venta en 2024
            break; // No es necesario seguir verificando
            }
          }
      }

     
      // Si no tiene ventas en 2024 y tiene al menos una venta, lo guardo
        if (tieneVentas && !tieneVenta2024) {
            objPunto1.setearTodo(objVendedor.getCodigoVendedor(), objVendedor.getNombreVendedor());
            objArcPunto1.GuardarArchivo(objPunto1);
        }

    }

  objArcPunto1.mostrarArchivo();  
}


void punto1b(){
    Vendedores objVendedor;
    ArchivoVendedores objArcVendedor;

    Ventas objVentas;
    ArchivoVentas objArcVentas;

    int tam1 = objArcVendedor.contarRegistros();
    int tam2 = objArcVentas.contarRegistros();

    Ventas vec[tam2];

    for(int i=0; i<tam2; i++){
        vec[i] = objArcVentas.leerRegistro(i);
        //vec[i].mostrar();  cout<<endl;
    }

    char valor[30];

    for(int i=0; i<tam2; i++){
        if(vec[i].getFechaVenta().getAnio()==2024){
            strcpy(valor,vec[i].getCodigoVendedor());


            for(int z=0; z<tam2; z++){
                if(strcmp(valor, vec[z].getCodigoVendedor())==0){
                    vec[z].setCodigoVendedor("x");
                }
                
            }
        }

    }

    // for(int i=0; i<tam2; i++){
    //     vec[i].mostrar();  cout<<endl;
    // }


    Punto1 objPunto1;
    ArchivoPunto1 objArcPunto1;

    objArcPunto1.BorrarArchivo();

    for(int i=0; i<tam1; i++){
        objVendedor = objArcVendedor.leerRegistro(i);

        for(int j=0; j<tam2; j++){

            if(strcmp(objVendedor.getCodigoVendedor(), vec[j].getCodigoVendedor())==0){

                if(vec[j].getFechaVenta().getAnio()!=2024){
                    if(objArcPunto1.ExisteDNIchar(objVendedor.getCodigoVendedor())==false){
                        objPunto1.setearTodo(objVendedor.getCodigoVendedor(), objVendedor.getNombreVendedor());
                        objArcPunto1.GuardarArchivo(objPunto1);
                    }
                }
            }

        }
    }

    objArcPunto1.mostrarArchivo();


}

void punto2(){
  Usuarios objUsuario; //solo los del 2015
  ArchivoUsuarios objArUsuario; 

  int contadorUsuarios2015 = 0;
  int tam = objArUsuario.contarRegistros();

  for(int i=0; i<tam; i++){
    objUsuario = objArUsuario.leerRegistro(i);

    if(objUsuario.getFechaRegistracion().getAnio() == 2015){
      contadorUsuarios2015++;
    }
  }  

  cout << "Cantidad de usuarios registrados en 2015: " << contadorUsuarios2015 << endl;
}


void puntoc(){
    Vendedores objVendedor;
    ArchivoVendedores objArcVendedor;

    Ventas objVentas;
    ArchivoVentas objArcVentas;

    int tam1 = objArcVendedor.contarRegistros();
    int tam2 = objArcVentas.contarRegistros();

    int cont=0;

    for(int i=0; i<tam1; i++){
        objVendedor = objArcVendedor.leerRegistro(i);

        if((objVendedor.getProvincia()==8) | (objVendedor.getProvincia()==9) | (objVendedor.getProvincia()==10)){

            for(int j=0; j<tam2; j++){
                objVentas = objArcVentas.leerRegistro(j);

                if((objVentas.getFechaVenta().getAnio()==2024 ) && (objVentas.getFechaVenta().getMes()<=6)){

                    if(strcmp(objVendedor.getCodigoVendedor(), objVentas.getCodigoVendedor())==0){
                        cont++;
                    }

                }

            }

        }

    }

    cout<<"Cantidad de ventas: "<<cont<<endl;
}


int main(){
        
    puntoc();
    return 0;
}
