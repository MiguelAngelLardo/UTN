

/*


Todas las funciones reciben el vector de Articulo y la cantidad de elementos del vector, además de los parámetros específicos.
Desarrollar un proyecto de CodeBlock con un menú que llame a cada una de las funciones.

3. Hacer una clase de nombre Fecha con las siguientes propiedades:
Día
Mes
Año
Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.

4. Hacer una clase de nombre Cliente con las siguientes propiedades:
DNI
Fecha de nacimiento
Nombre
Apellido	
Email
Teléfono
 
Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.
Un constructor para asignar valor sólo a la propiedad nombre.
La propiedad fecha de nacimiento debe ser un objeto de la clase Fecha. La clase Fecha debe estar desarrollada dentro de un archivo de cabecera de nombre fecha.h

5. A partir de la clase Cliente del ejercicio anterior desarrollar las siguientes funciones:
a)    Cargar un vector de 10 clientes
b) Listar todos los clientes del vector.
c)     Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado.
d)      A partir de un valor de DNI recibido como parámetro, devolver la posición del objeto que contiene ese DNI. De no encontrarlo devolver -1.
e)    Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el DNI. De no encontrar el código la función debe devolver un objeto Cliente con un valor de -1 en el DNI.
f)     Dado una fecha que se recibe como parámetro devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido.

Todas las funciones reciben el vector de Cliente y la cantidad de elementos del vector, además de los parámetros específicos.
Desarrollar un proyecto de CodeBlock con un menú que llame a cada una de las funciones.

/***************************
ingresar valores de la class Articulo

a1
uno
93
38
a3
tres
75
29
a6
seis
899
23
a9
nueve
968
21
a12
doce
345
32
a15
quince
242
40
a18
dieciocho
773
45
a21
veintiuno
578
19
a24
veinticuatro
148
50
a27
ventisiete
626
27
/***************************

*/


#include <iostream>
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



class Articulo{
private:
  char _codigo[5];
  char _descripcion[30];
  float _precio;
  int _stock;
  bool _estado;

public:
  //setters y getters

  void setCodigo(const char *cod){strcpy(_codigo, cod);}
  void setDescripcion(const char *des){strcpy(_descripcion, des);}
  void setPrecio(const float pre){_precio = pre;}
  void setStock(const int sto){_stock = sto;}
  void setEstado(const bool est){_estado = est;}

  const char * getCodigo(){return _codigo;}
  const char * getDescripcion(){return _descripcion;}
  float getPrecio() const {return _precio;}
  int getStock() const {return _stock;}
  bool getEstado() const {return _estado;}

  //constructor
  Articulo(const char *cod = "X", const char *des = "X", float pre = 0.0, int sto = 0, bool est = true) : _precio(pre ), _stock(sto), _estado(est){
    strcpy(_codigo, cod);
    strcpy(_descripcion, des);    
  }
  
  //destructor
   ~Articulo(){}

  void cargar(){
    cout<<"ingrese el codigo del articulo"<<endl;
    cargarCadena(_codigo, 5);
    cout<<"ingrese la descripción del articulo"<<endl;
    cargarCadena(_descripcion, 30);
    cout<<"ingrese el precio del articulo"<<endl;
    cin>>_precio;
    cout<<"ingrese el stock del articulo"<<endl;
    cin>>_stock;
    _estado=true;
  } 

  void mostrar(){
    cout<<"codigo: "<<_codigo<<endl;
    cout<<"descripcion: "<<_descripcion<<endl;
    cout<<"precio: "<<_precio<<endl;
    cout<<"stock: "<<_stock<<endl;
    //cout<<"estado: "<<_estado<<endl;
  }

  void cargarPTOA(Articulo vec[], int tam=10){
    cout << "CARGAR VECTOR" << endl;
    for(int i=0; i<tam; i++){
        vec[i].cargar();
    }
  }

  void mostrarPTOB(Articulo vec[], int tam=10){
    cout << "MOSTRAR VECTOR" << endl;
    for(int i = 0; i < tam; i ++){
      vec[i].mostrar();
      cout << endl;
    }
  }
    
  void puntoC(Articulo vec[], int tam=10){
    float valor;
    cout << "Ingrese un valor para listar los articulos con precio mayor a: ";
    cin >> valor;

    for(int i = 0; i < tam; i ++){
      if(vec[i].getPrecio() > valor){
        vec[i].mostrar();
      }
    }
  }

  int puntoD(Articulo vec[], int tam, const char *codigo){ //codigo es char
    for(int i = 0; i < tam; i ++){
      if(strcmp(vec[i].getCodigo(), codigo)== 0){
        return i+1;
      }
    }
    return -1;
  }

  Articulo puntoE(Articulo vec[], int tam, const char *codigo){
    for(int i = 0; i < tam; i ++){
      if(strcmp(vec[i].getCodigo(), codigo)== 0){
        return vec[i];
      }       
    }  
    vec[0].setStock(-1);

    return vec[0];     
  }

  int puntoF(Articulo vec[], int tam, int valorStock){
    int contador = 0;
    for(int i = 0; i < tam; i ++){
      if(vec[i].getStock() < valorStock){
        contador ++;    
      }  
    }  
    return contador;
  }

  void puntoG(Articulo vec[], int tam, int porcentajeIncremento){
    for(int i = 0; i < tam; i ++){
     // Calcula el incremento en función del porcentaje
     float incremento = vec[i].getPrecio() * porcentajeIncremento / 100.0;//100 * 20 / 100
        
      // Aumenta el precio del artículo
      vec[i].setPrecio(vec[i].getPrecio() + incremento);

    }
  }

};



void Menu(){
    char opc;
    Articulo objE;
    Articulo vObjE[10];
    
  while(true)
  {
    cout<<"MENU"<<endl;
    cout << "----------------------------------------------------------" << endl;
    cout<<"x. Punto X -> Cargar un ARTICULO (EN MEMORIA)"<<endl;
    cout<<"y. Punto Y -> Mostrar un ARTICULO (EN MEMORIA)"<<endl;
    cout << "----------------------------------------------------------" << endl;
    cout<<"a. Punto A -> Cargar un vector de 10 articulos (EN MEMORIA)"<<endl;
    cout<<"b. Punto B -> Listar todos los articulos del vector (EN MEMORIA)"<<endl;
    cout<<"c. Punto C -> Listar todos los articulos cuyo precio sea mayor a un valor que se ingresa por teclado"<<endl;
    cout<<"d. Punto D -> A partir de un valor de código recibido como parametro, devolver la posición del objeto que contiene ese código. De no encontrarlo devolver -1"<<endl;
    cout<<"e. Punto E -> Igual a la funcion del punto anterior, pero debe devolver el objeto completo que contiene el codigo. De no encontrar el codigo la función debe devolver un objeto Articulo con un valor de -1 en el stock."<<endl;
    cout<<"f. Punto F -> Dado un valor de stock que se recibe como parametro devolver la cantidad de artculos cuyo stock sea inferior a ese valor recibido"<<endl;
    cout<<"g. Punto G -> Dado un porcentaje de incremento que se recibe como parametro, modificar el precio unitario de todos los objetos."<<endl;
    cout<<"z. Salir"<<endl;
    cout << "----------------------------------------------------------" << endl;
    cout<<"ingrese una opcion: ";
    cin >> opc;

    switch (opc)
    {
      /*******************************/
      case 'x': case 'X':{
        objE.cargar();
        }break;
      case 'y': case 'Y':{
        objE.mostrar();
      }break;  
      /*******************************/
      case 'a': case 'A':{
        vObjE->cargarPTOA(vObjE,10);
        }break;
      /*******************************/
      case 'b': case 'B':{
        vObjE->mostrarPTOB(vObjE,10);
      }break;
      /*******************************/
      case 'c': case 'C':{
        vObjE->puntoC(vObjE, 10);        
      }break;
      /*******************************/
      case 'd': case 'D':{
        char cod[5];
        int posicion;
        cout << "Ingrese el codigo del articulo del cual quiere saber la posicion: ";
        cargarCadena(cod, 5);
        posicion = vObjE->puntoD(vObjE, 10, cod);
        cout << "La posicion del articulo es: " << posicion << endl;   
      }break;
      /*******************************/
      case 'e': case 'E':{
        objE = objE.puntoE(vObjE, 10, "aaa"); 
        objE.mostrar();
        }break;
      /*******************************/
      case 'f': case 'F':{
        int cantidadArticulosInferiorAUnValor;
        cantidadArticulosInferiorAUnValor = objE.puntoF(vObjE, 10, 30);
        cout << "La cantidad de articulos inferiores a un valor es: " << cantidadArticulosInferiorAUnValor << endl;
      }break;  
      /*******************************/
      case 'g': case 'G':{
        objE.puntoG(vObjE, 10, 20);        
      }break;


      
      default:{
      
      }break;
      /*******************************/
    }
    system("pause");
  }
}

int main(){

  Menu();

    return 0;
}