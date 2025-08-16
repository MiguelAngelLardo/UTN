#include<iostream>

using namespace std;

#include"Float.h"

Float::Float(float v){
            val = new float(v);
            if(val == NULL){
                cout << "Error en la memoria" << endl;
                cout<<"Fila: "<<__LINE__<<endl;
                exit(1);
            }
        }

Float::~Float(){
            delete val;
        }

void Float::mostrar(){
    cout << *val << endl;
}

void Float::cargar(){
            float v;
            cin >> v;
            *val = v;
        }

bool Float::operator==(Float f){
    if(*val == *f.val){
        return true;
    }
    return false;
}

bool Float::operator==(float f){
    if(*val == f){
        return true;
    }
    return false;
}

bool Float::operator>=(Float f){
if(*val >= *f.val){
return true;
}
return false;
}

bool Float::operator>=(float f){
if(*val >= f){
return true;
}
return false;
}

bool Float::operator>(Float f){
if(*val > *f.val){
return true;
}
return false;
}

bool Float::operator>(float f){
if(*val > f){
return true;
}
return false;
}

bool Float::operator<=(Float f){
if(*val <= *f.val){
return true;
}
return false;
}

bool Float::operator<=(float f){
if(*val <= f){
return true;
}
return false;
}

bool Float::operator<(Float f){
if(*val < *f.val){
return true;
}
return false;
}

bool Float::operator<(float f){
if(*val < f){
return true;
}
return false;
}

Float Float::operator+(Float f){
Float aux(*val + *f.val);
return aux;
}

Float Float::operator+(float f){
Float aux(*val + f);
return aux;
}

Float Float::operator-(Float f){
Float aux(*val - *f.val);
return aux;
}

Float Float::operator-(float f){
Float aux(*val - f);
return aux;
}

Float Float::operator*(Float f){
Float aux(*val * *f.val);
return aux;
}

Float Float::operator*(float f){
Float aux(*val * f);
return aux;
}

Float Float::operator/(Float f){
Float aux(*val / *f.val);
return aux;
}

Float Float::operator/(float f){
Float aux(*val / f);
return aux;
}

Float Float::operator++(){
*val = *val + 1;
return *this;
}

Float Float::operator++(int){
Float aux(*val);
*val = *val + 1;
return aux;
}

Float Float::operator--(){
*val = *val - 1;
return *this;
}

Float Float::operator--(int){
Float aux(*val);
*val = *val - 1;
return aux;
}

Float& Float::operator=(Float f){
*val = *f.val;
return *this;
}

Float& Float::operator=(float f){
*val = f;
return *this;
}

Float& Float::operator+=(Float f){
*val = *val + *f.val;
return *this;
}

Float& Float::operator+=(float f){
*val = *val + f;
return *this;
}

Float& Float::operator-=(Float f){
*val = *val - *f.val;
return *this;
}

Float& Float::operator-=(float f){
*val = *val - f;
return *this;
}

Float& Float::operator*=(Float f){
*val = *val * *f.val;
return *this;
}

Float& Float::operator*=(float f){
*val = *val * f;
return *this;
}

Float& Float::operator/=(Float f){
*val = *val / *f.val;
return *this;
}

Float& Float::operator/=(float f){
*val = *val / f;
return *this;
}

// Sobrecarga de operadores de entrada y salida
// explicacion de IA de como pasar estas 2 funciones al .cpp
// https://sl.bing.net/gvEPXviYayG
ostream &operator<<(ostream &salida, const Float &c){
    salida<<*c.val;
    return salida;
}
istream &operator>>(istream &entrada, Float &c){
    cin>>*c.val;
    return entrada;
}

// Float& Float::operator=(const Float& other) {
//     if (this != &other) { // Evitar auto-asignación
//         delete val;       // Liberar memoria existente
//         val = new float(*other.val); // Copiar el valor del otro objeto
//     }
//     return *this; // Retornar la referencia al objeto actual
// }


// Float& Float::operator=(float f) {
//     *val = f; // Asignar el valor float directamente al contenido de `val`
//     return *this; // Retornar la referencia al objeto actual
// }















