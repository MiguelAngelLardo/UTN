/*11 Hacer un programa para ingresar cinco números y listar cuantos de esos cinco
números son positivos, cuantos son negativos y cuantos son iguales a 0.*/

#include <iostream>
using namespace std;


int main(){
      int num1,num2,num3,num4,num5,positivo =0, negativo=0, ceros=0;

    cout << "Ingrese el primer numero" << endl;
    cin >> num1;
    cout << "Ingrese el segundo numero" << endl;
    cin >> num2;
    cout << "Ingrese el tercer numero" << endl;
    cin >> num3;
     cout << "Ingrese el cuarto numero" << endl;
    cin >> num4;
     cout << "Ingrese el quinto numero" << endl;
    cin >> num5;

    if(num1>0){
        positivo++;
    }else if(num1<0){
        negativo++;
    }else{
        ceros++;
    };
       if(num2>0){
        positivo++;
    }else if(num2<0){
        negativo++;
    }else{
        ceros++;
    };
       if(num3>0){
        positivo++;
    }else if(num3<0){
        negativo++;
    }else{
        ceros++;
    };
       if(num4>0){
        positivo++;
    }else if(num4<0){
        negativo++;
    }else{
        ceros++;
    };
       if(num5>0){
        positivo++;
    }else if(num5<0){
        negativo++;
    }else{
        ceros++;
    };

    cout <<"-----------------------------------------------" << endl;
    cout << "Cantidad de numeros positivos   = " << positivo <<endl;
    cout << "Cantidad de numeros negativos   = " << negativo <<endl;
    cout << "Cantidad de numeros iguales a 0 = " << ceros <<endl;
    cout <<"-----------------------------------------------" << endl;




return 0;
}
