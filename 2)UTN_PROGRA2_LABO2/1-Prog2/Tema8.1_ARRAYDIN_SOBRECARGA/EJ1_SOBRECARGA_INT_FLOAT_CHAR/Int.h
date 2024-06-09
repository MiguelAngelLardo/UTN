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

friend ostream &operator<<(ostream &salida, const Int &c);
friend istream &operator>>(istream &entrada, Int &c);


};
