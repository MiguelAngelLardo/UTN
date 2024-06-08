/*10 Hacer un programa para ingresar cinco números y listar el máximo y el mínimo
de ellos.*/

#include <iostream>
using namespace std;


int main(){
    int num1,num2,num3,num4,num5,maxi,mini;

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

    if(num1>num2){
        maxi = num2;
        mini = num2;
    }else{
        maxi=num2;
        mini=num1;
    };
    if(num3>maxi){
        maxi=num3;
    }else if(num3<mini){
        mini=num3;
    };
        if(num4>maxi){
        maxi=num4;
    }else if(num4<mini){
        mini=num4;
    };
        if(num5>maxi){
        maxi=num5;
    }else if(num5<mini){
        mini=num5;
    };

    cout << "Numero maximo = " << maxi << endl;
    cout << "Numero minimo = " << mini << endl;
return 0;
}
