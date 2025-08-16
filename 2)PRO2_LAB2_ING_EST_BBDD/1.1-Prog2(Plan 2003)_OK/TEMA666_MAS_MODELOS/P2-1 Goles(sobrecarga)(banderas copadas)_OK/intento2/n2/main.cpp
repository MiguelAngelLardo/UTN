#include<iostream>
#include<cstring>

using namespace std;

#include"Float.h"
#include"Int.h"

int main(){

    Float pepe(5.5);

    pepe = 10.5;

    cin>>pepe;

    pepe.cargar();

    return 0;
}