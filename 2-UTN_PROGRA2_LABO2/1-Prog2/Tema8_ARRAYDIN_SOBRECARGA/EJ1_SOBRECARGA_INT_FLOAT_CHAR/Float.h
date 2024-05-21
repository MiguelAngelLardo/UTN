#pragma once
#include<iostream>

using namespace std;


class Float{

    private:
        float *val;
    public:
        Float(float v){
            val = new float(v);
            if(val == NULL){
                cout << "Error en la memoria" << endl;
                cout<<"Fila: "<<__LINE__<<endl;
                exit(1);
            }
        }

        ~Float(){
            delete val;
        }

        void mostrar(){
            cout << *val << endl;
        }

        void cargar(){
            float v;
            cin >> v;
            *val = v;
        }
    //SOBRECARGAS

//Aviso no se puede utilizar el % en floats

    bool operator==(Float f){
        if(*val == *f.val){
            return true;
        }
        return false;
    }

    bool operator==(float f){
        if(*val == f){
            return true;
        }
        return false;
    }

    bool operator>=(Float f){
        if(*val >= *f.val){
            return true;
        }
        return false;
    }

    bool operator>=(float f){
        if(*val >= f){
            return true;
        }
        return false;
    }

    bool operator>(Float f){
        if(*val > *f.val){
            return true;
        }
        return false;
    }

    bool operator>(float f){
        if(*val > f){
            return true;
        }
        return false;
    }

    bool operator<=(Float f){
        if(*val <= *f.val){
            return true;
        }
        return false;
    }

    bool operator<=(float f){
        if(*val <= f){
            return true;
        }
        return false;
    }

    bool operator<(Float f){
        if(*val < *f.val){
            return true;
        }
        return false;
    }

    bool operator<(float f){
        if(*val < f){
            return true;
        }
        return false;
    }

    Float operator+(Float f){
        Float aux(*val + *f.val);
        return aux;
    }

    Float operator+(float f){
        Float aux(*val + f);
        return aux;
    }

    Float operator-(Float f){
        Float aux(*val - *f.val);
        return aux;
    }

    Float operator-(float f){
        Float aux(*val - f);
        return aux;
    }

    Float operator*(Float f){
        Float aux(*val * *f.val);
        return aux;
    }

    Float operator*(float f){
        Float aux(*val * f);
        return aux;
    }

    Float operator/(Float f){
        Float aux(*val / *f.val);
        return aux;
    }

    Float operator/(float f){
        Float aux(*val / f);
        return aux;
    }

    Float operator++(){
        *val = *val + 1;
        return *this;
    }

    Float operator++(int){
        Float aux(*val);
        *val = *val + 1;
        return aux;
    }

    Float operator--(){
        *val = *val - 1;
        return *this;
    }

    Float operator--(int){
        Float aux(*val);
        *val = *val - 1;
        return aux;
    }

    Float& operator=(Float f){
        *val = *f.val;
        return *this;
    }

    Float& operator=(float f){
        *val = f;
        return *this;
    }

    Float& operator+=(Float f){
        *val = *val + *f.val;
        return *this;
    }

    Float& operator+=(float f){
        *val = *val + f;
        return *this;
    }

    Float& operator-=(Float f){
        *val = *val - *f.val;
        return *this;
    }

    Float& operator-=(float f){
        *val = *val - f;
        return *this;
    }

    Float& operator*=(Float f){
        *val = *val * *f.val;
        return *this;
    }

    Float& operator*=(float f){
        *val = *val * f;
        return *this;
    }

    Float& operator/=(Float f){
        *val = *val / *f.val;
        return *this;
    }

    Float& operator/=(float f){
        *val = *val / f;
        return *this;
    }

};
