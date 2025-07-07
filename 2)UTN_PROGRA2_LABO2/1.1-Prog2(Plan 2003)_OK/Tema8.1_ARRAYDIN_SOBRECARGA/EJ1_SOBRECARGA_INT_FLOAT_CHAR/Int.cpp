#include<iostream>

using namespace std;

#include"Int.h"

Int::Int(int v){
    val = new int(v);
    if(val == nullptr){
        cout<<"Error al asignar memoria"<<endl;
        cout<<"Fila: "<<__LINE__<<endl;
        exit(1);
    }
}

Int::~Int(){
    delete val;
}

void Int::mostrar(){cout<<*val<<endl;}

void Int::cargar(){cin>>*val;}

bool Int::operator==(int v){
    if(*val == v){
        return true;
    }
    return false;
}

bool Int::operator==(Int v){
    if(*val == *v.val){
        return true;
    }
    return false;
}

Int Int::operator+(int v){
    Int aux(*val + v);
    return aux;
}

Int Int::operator+(Int v){
    Int aux(*val + *v.val);
    return aux;
}

Int Int::operator-(int v){
    Int aux(*val - v);
    return aux;
}

Int Int::operator-(Int v){
    Int aux(*val - *v.val);
    return aux;
}

Int Int::operator*(int v){
    Int aux(*val * v);
    return aux;
}

Int Int::operator*(Int v){
    Int aux(*val * *v.val);
    return aux;
}

Int Int::operator/(int v){
    Int aux(*val / v);
    return aux;
}

Int Int::operator/(Int v){
    Int aux(*val / *v.val);
    return aux;
}

bool Int::operator>(int v){
    if(*val > v){
        return true;
    }
    return false;
}

bool Int::operator>(Int v){
    if(*val > *v.val){
        return true;
    }
    return false;
}

bool Int::operator<(int v){
    if(*val < v){
        return true;
    }
    return false;
}

bool Int::operator<(Int v){
    if(*val < *v.val){
        return true;
    }
    return false;
}

bool Int::operator>=(int v){
    if(*val >= v){
        return true;
    }
    return false;
}

bool Int::operator>=(Int v){
    if(*val >= *v.val){
        return true;
    }
    return false;
}

bool Int::operator<=(int v){
    if(*val <= v){
        return true;
    }
    return false;
}

bool Int::operator<=(Int v){
    if(*val <= *v.val){
        return true;
    }
    return false;
}

bool Int::operator!=(int v){
    if(*val != v){
        return true;
    }
    return false;
}

bool Int::operator!=(Int v){
    if(*val != *v.val){
        return true;
    }
    return false;
}

Int Int::operator++(){
    *val = *val + 1;
    return *this;
}

Int Int::operator--(){
    *val = *val - 1;
    return *this;
}

Int Int::operator++(int){
    Int aux(*val);
    *val = *val + 1;
    return aux;
}

int Int::operator%(int v){
    return *val % v;
}

int Int::operator%(Int v){
    return *val % *v.val;
}

// Sobrecarga de operadores de entrada y salida
// explicacion de IA de como pasar estas 2 funciones al .cpp
// https://sl.bing.net/gvEPXviYayG
ostream &operator<<(ostream &salida, const Int &c){
    salida<<*c.val;
    return salida;
}

istream &operator>>(istream &entrada, Int &c){
    cin>>*c.val;
    return entrada;
}








