#include<iostream>
#include<cstring>

using namespace std;

#include"Cadena.h"
#include"Float.h"
#include"Int.h"

int main(){

    
    Int a(10);
    Float b(10.5);
    Float b2(10.5);
    Cadena c("hola s");
    Cadena c2("holas");
    char c3[10] = "oles";

    c+=c3;
    cout<<"c: "<<c<<endl;
    cout<<"c2: "<<c2<<endl;

    return 0;
}