#pragma once

class Float{

    private:
        float *val;
    public:
        Float(float v);

        ~Float();

        void mostrar();

        void cargar();
//SOBRECARGAS

//Aviso no se puede utilizar el % en floats

bool operator==(Float f);

bool operator==(float f);

bool operator>=(Float f);

bool operator>=(float f);

bool operator>(Float f);

bool operator>(float f);

bool operator<=(Float f);

bool operator<=(float f);

bool operator<(Float f);

bool operator<(float f);

Float operator+(Float f);

Float operator+(float f);

Float operator-(Float f);

Float operator-(float f);

Float operator*(Float f);

Float operator*(float f);

Float operator/(Float f);

Float operator/(float f);

Float operator++();

Float operator++(int);

Float operator--();

Float operator--(int);

Float& operator=(Float f);

Float& operator=(float f);

Float& operator+=(Float f);

Float& operator+=(float f);

Float& operator-=(Float f);

Float& operator-=(float f);

Float& operator*=(Float f);

Float& operator*=(float f);

Float& operator/=(Float f);

Float& operator/=(float f);




// Sobrecarga de operadores de entrada y salida
// explicacion de IA de como pasar estas 2 funciones al .cpp
// https://sl.bing.net/gvEPXviYayG
friend ostream &operator<<(ostream &salida, const Float &c);
friend istream &operator>>(istream &entrada, Float &c);

// Float& operator=(const Float& other);
// Float& operator=(float f);


};
