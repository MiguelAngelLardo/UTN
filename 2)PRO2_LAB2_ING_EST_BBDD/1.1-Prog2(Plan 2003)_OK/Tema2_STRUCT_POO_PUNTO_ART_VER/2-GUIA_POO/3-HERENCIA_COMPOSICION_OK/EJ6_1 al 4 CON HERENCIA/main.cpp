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


/*
1) Una empresa de tecnología registra a sus 
empleados : DNI, nombre,  apellido, domicilio, email, fecha de nacimiento y cargo (número entre 1 y 10).

b) Hacer un programa para cargar y mostrar un vector de 5 empleados. Hacer un menú y usar funciones.

2) El área de investigación de la UTN tiene registrados a sus 
investigadores :DNI, nombre, apellido, fecha de nacimiento, unidad académica a la que pertenece (entero entre 1 y 30), categoría (1 a 5) y especialidad(1 a 10).

3) Un comercio guarda los siguientes datos de cada una de las 
compras:Número de compra, fecha, nombre del producto comprado, tipo de producto (entero entre 1 y 15), forma de pago acordada (1 a 5) , cantidad e importe total.

4) La NASA guarda los siguientes datos de las 
misiones : Número de misión, nombre de la misión, nombre del astronauta  a cargo, fecha de inicio, fecha de fin, presupuesto disponible. 
A partir de los señalado desarrollar los siguientes puntos.
*/

/*
6) Analizar si en los ejercicios del 1 al 4 puede aplicarse el mecanismo de la herencia para resolver varios ejercicios de manera conjunta. Ver si corresponde también la composición. 
*/
int main() {
  cout << "Hello, World!" << endl;
  return 0;
}