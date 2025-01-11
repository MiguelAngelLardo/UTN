#pragma once

class Int{

private:
    int *val;
public:

Int(int v);

~Int();

void mostrar();
void cargar();

//SOBRECARGAS

bool operator==(int v);

bool operator==(Int v);

Int operator+(int v);

Int operator+(Int v);

Int operator-(int v);

Int operator-(Int v);

Int operator*(int v);

Int operator*(Int v);

Int operator/(int v);

Int operator/(Int v);

bool operator>(int v);

bool operator>(Int v);

bool operator<(int v);

bool operator<(Int v);

bool operator>=(int v);

bool operator>=(Int v);

bool operator<=(int v);

bool operator<=(Int v);

bool operator!=(int v);

bool operator!=(Int v);

Int operator++();

Int operator--();

Int operator++(int);

int operator%(int v);

int operator%(Int v);

Int& operator=(Int f);

Int& operator=(int f);

// Sobrecarga de operadores de entrada y salida
// explicacion de IA de como pasar estas 2 funciones al .cpp
// https://sl.bing.net/gvEPXviYayG
friend ostream &operator<<(ostream &salida, const Int &c);
friend istream &operator>>(istream &entrada, Int &c);


};
