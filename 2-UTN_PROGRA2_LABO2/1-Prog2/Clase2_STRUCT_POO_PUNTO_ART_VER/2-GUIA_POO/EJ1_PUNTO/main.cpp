//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;


///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int getAnchoPantalla() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


///CLASE PUNTO
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){
            x=a;
            y=b;
            color=nuevoColor;
        }
        void Mostrar(){
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<(char)219;
        }
        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void setX(int valor){
            if(valor>=0 && valor<=166)  x=valor;
        }
        void setY(int valor){
            if(valor>=0)  y=valor;
        }

        void setColor(int nuevo){
            if(nuevo>0 && nuevo<=15){
                color=nuevo;
            }else{
                color=nuevo%16;
            }
        }
        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(cNEGRO,cBLANCO);
        }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }

// X= 0 a 166

void punto1(){
    Punto obj(10,5, cAZUL), obj2(5, 5, cROJO);
    int x, y;
    cout<<"INGRESE LA COORDENADA X: ";
    cin>>x;
    cout<<"INGRESE LA COORDENADA Y: ";
    cin>>y;
    obj.setX(x);
    obj.setY(y);
    system("cls");
    obj.Mostrar();
    obj2.Mostrar();
}

void punto2(){//linea horizontal en eje Y definida
    Punto inicio(1, 5 , cROJO);
    Punto fin(20, 5 , cROJO);
    //inicio.Mostrar();
    //fin.Mostrar();

    int y;
    cout << "Ingrese la coordenada Y: ";
    cin >> y;

    int posXInicio = inicio.getX(); // Obtener la coordenada X del punto de inicio
    int posXFin = fin.getX();
    int posY = y;

     // Dibujar la línea horizontal entre los puntos de inicio y fin
    for (int i = posXInicio + 1; i < posXFin; ++i) {
        Punto punto(i, posY, cROJO); // Crear un objeto Punto para cada punto de la línea horizontal
        // Pausar la ejecución durante 100 milisegundos (0.1 segundos) para hacerlo más lento
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        punto.Mostrar();
    }
}

void punto3(){//linea vertical en eje X definida
    Punto inicio(1, 6, cROJO); //de 6 hasta 12
    Punto fin(1, 20, cROJO);

    int x;
    cout << "Ingrese la coordenada x: "; //piso el 1 del constructor
    cin >> x;

    int posYInicio = inicio.getY(); // Obtener la coordenada Y del punto de inicio
    int posYFin = fin.getY();
    int posX = x;

     // Dibujar la línea VERTICUAL entre los puntos de inicio y fin
    for (int i = posYInicio + 1; i < posYFin; ++i) {
        Punto aux(posX, i, cROJO); // Crear un objeto Punto para cada punto de la línea vertical
        // Pausar la ejecución durante 100 milisegundos (0.1 segundos) para hacerlo más lento
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        aux.Mostrar();
    }
}

void punto4(){
    Punto inicio(5, 10, cROJO);//inicio en x = 5
    Punto fin(40, 10, cAZUL);//fin x = 10

    int posXInicio = inicio.getX();
    int posXFin = fin.getX();

    //determinar los colores a alternar
    int color1 = cROJO;
    int color2 = cAZUL;

     // Dibujar la línea horizontal alternando entre los dos colores
    for (int i = posXInicio + 1; i < posXFin; ++i) {
        // Alternar entre los dos colores en cada iteración
        int color = (i % 2 == 0) ? color1 : color2;
        Punto punto(i, inicio.getY(), color); // Crear un objeto Punto con el color correspondiente
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        punto.Mostrar();
    }
}

void punto5(){//dibujar vertical => fijos son las x, los Y son distintos
    Punto inicio(10, 5, cROJO);
    Punto fin(10, 40, cAZUL);

    int posYInicio = inicio.getY();
    int posYFin = fin.getY();
    int xFija = inicio.getX();

    int color1 = cROJO;
    int color2 = cAZUL;

    //dibujar linea vertical
    for(int i = posYInicio; i < posYFin; i ++){
        int colorAlter = (i%2 == 0 ? color1 :color2);
        Punto aux(xFija, i, colorAlter);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        aux.Mostrar();
    }
}

void punto6(){// 6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA y se encuentren en centro
    int centroPantalla = getAnchoPantalla() / 2;
    Punto inicioA(5, 10, cROJO);
    Punto finA(centroPantalla, 10, cROJO);

    Punto inicioB(116, 10, cAZUL);
    Punto finB(centroPantalla, 10, cAZUL);

   // Obtener las coordenadas X de los puntos de inicio y fin de cada línea
    int inicioAX = inicioA.getX();
    int finAX = finA.getX();
    int inicioBX = inicioB.getX();
    int finBX = finB.getX();

    // Obtener la coordenada Y de la línea
    int fijarAY = inicioA.getY();

    Punto auxB(inicioBX, fijarAY, cAZUL);
    for(int i = inicioAX; i <= centroPantalla; i ++) {
      Punto auxA(i , fijarAY, cROJO);
      std::this_thread::sleep_for(std::chrono::milliseconds(25));
      auxA.Mostrar();
      auxB.Mostrar();
      auxB.setX(inicioBX-=1);
    }
}



int main() {
    srand(time(NULL));
    ocultarCursor();
    textcolor(0,15);
    int opc;
    while(true){
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE Y DEFINIDA"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X DEFINIDA"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<"7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<" AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 DE Y "<<endl;
        cout<<"8. HACER UN PUNTO QUE PARPADEE EN LA PANTALLA EN UNA POSICION DADA"<<endl;
        cout<<"9. HACER UN RECTANGULO A PARTIR DE DOS VALORES DE 2 LADOS"<<endl;
        cout<<"10. HACER UN PUNTO QUE CAMINE POR LA PANTALLA DE MANERA HORIZONTAL"<<endl;
        cout<<"11. HACER UN PUNTO QUE SE DESPLAZE POR LA PANTALLA DE MANERA VERTICAL"<<endl;
        cout<<"12. DIBUJAR UNA LLUVIA DE PUNTOS"<<endl;
        cout<<"13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                punto1();
                break;
            case 2:
                punto2();
                break;
            case 3:
                punto3();
                break;
            case 4:
                punto4();
                break;
            case 5:
                punto5();
                break;
            case 6:
                punto6();
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 0:
                return 0;

        }
        system("pause>nul");

    }
    return 0;
}

/**
A partir de la clase Punto resolver lo siguiente:

8) Hacer un punto que parpadee en la pantalla en una posición dada.
9) Hacer un rectangulo, a partir de los valores de 2 lados
10) Hacer un punto que camine por la pantalla de manera horizontal
11) Hacer un punto que se desplaze por la pantalla de manera vertical
12) Hacer una lluvia de puntos aleatoria en la pantalla.
13) Igual que el anterior, pero debe terminar el programa cuando se
toca una tecla
Para este último hay una función que se llama kbhit()

Pueden agregar los métodos que consideren necesarios.
**/
