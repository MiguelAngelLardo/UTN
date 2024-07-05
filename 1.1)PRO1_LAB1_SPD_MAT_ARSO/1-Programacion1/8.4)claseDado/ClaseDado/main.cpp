#include <iostream>
#include "rlutil.h"
using namespace std;

void dibubjarCuadrado(int posX, int posY);

int main()
{
    rlutil::hidecursor();
    rlutil::saveDefaultColor();;

    dibubjarCuadrado(1,1);
    rlutil::locate(4,2);
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    cout << (char)254;

    dibubjarCuadrado(10,1);

    rlutil::resetColor();
    return 0;
}

void dibubjarCuadrado(int posX, int posY){
   rlutil::setColor(rlutil::WHITE);
    for(int x = posX; x <= posX+6; x ++){
      for(int y = posY; y <=posY+2; y++){
        rlutil::locate(x,y);//columna(X)(HORIZONTAL) fila (Y)
        cout << (char)219;
      }
    }
}
