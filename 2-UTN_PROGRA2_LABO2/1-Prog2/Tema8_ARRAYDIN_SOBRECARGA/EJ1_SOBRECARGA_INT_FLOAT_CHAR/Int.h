#pragma once
#include<iostream>

using namespace std;


class Int{
    private:
        int *val;
    public:
        Int(int v){
            val = new int(v);
            if(val == nullptr){
                cout<<"Error al asignar memoria"<<endl;
                cout<<"Fila: "<<__LINE__<<endl;
                exit(1);
            }
        }

        ~Int(){
            delete val;
        }

        void mostrar(){cout<<*val<<endl;}
        void cargar(){cin>>*val;}

//SOBRECARGAS

bool operator==(int v){
    if(*val == v){
        return true;
    }
    return false;
}

bool operator==(Int v){
    if(*val == *v.val){
        return true;
    }
    return false;
}

Int operator+(int v){
    Int aux(*val + v);
    return aux;
}

Int operator+(Int v){
    Int aux(*val + *v.val);
    return aux;
}

Int operator-(int v){
    Int aux(*val - v);
    return aux;
}

Int operator-(Int v){
    Int aux(*val - *v.val);
    return aux;
}

Int operator*(int v){
    Int aux(*val * v);
    return aux;
}

Int operator*(Int v){
    Int aux(*val * *v.val);
    return aux;
}

Int operator/(int v){
    Int aux(*val / v);
    return aux;
}

Int operator/(Int v){
    Int aux(*val / *v.val);
    return aux;
}

bool operator>(int v){
    if(*val > v){
        return true;
    }
    return false;
}

bool operator>(Int v){
    if(*val > *v.val){
        return true;
    }
    return false;
}

bool operator<(int v){
    if(*val < v){
        return true;
    }
    return false;
}

bool operator<(Int v){
    if(*val < *v.val){
        return true;
    }
    return false;
}

bool operator>=(int v){
    if(*val >= v){
        return true;
    }
    return false;
}

bool operator>=(Int v){
    if(*val >= *v.val){
        return true;
    }
    return false;
}

bool operator<=(int v){
    if(*val <= v){
        return true;
    }
    return false;
}

bool operator<=(Int v){
    if(*val <= *v.val){
        return true;
    }
    return false;
}

bool operator!=(int v){
    if(*val != v){
        return true;
    }
    return false;
}

bool operator!=(Int v){
    if(*val != *v.val){
        return true;
    }
    return false;
}

Int operator++(){
    *val = *val + 1;
    return *this;
}

Int operator--(){
    *val = *val - 1;
    return *this;
}

Int operator++(int){
    Int aux(*val);
    *val = *val + 1;
    return aux;
}

int operator%(int v){
    return *val % v;
}

int operator%(Int v){
    return *val % *v.val;
}


};
