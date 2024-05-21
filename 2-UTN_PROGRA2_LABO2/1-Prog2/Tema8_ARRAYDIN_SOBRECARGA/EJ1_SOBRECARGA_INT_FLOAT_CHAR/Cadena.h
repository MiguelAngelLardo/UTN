#pragma once

#include<iostream>
#include<cstring>

using namespace std;

#include"funcionesGlobales.h"
//sobre cargar el operador != de manera tal que sea verdadero cuando los dos objetos a comaprar sean distintos
//sobrecarga el operador <= para dos casos: comparar las cadenas de caracteres y para comparar el largo d ela cadena
//sobrecargar el operador += de manera tal que se concatenen las dos cadenas. 



class Cadena{



    private:
        char *p;
        int tam;
    public:

    //setters y getters

    //metodos
    void mostrar(){
        cout<<p<<endl;
    }

    void cargar(){
        cargarCadena(p, tam);
    }




    void setP(const char *texto){
        tam = strlen(texto) + 1;
        delete[] p;
        p = new char[tam];
        if(p == NULL){
            cout<<"No hay memoria"<<endl;
            cout<<"linea: "<<__LINE__<<endl;
            exit(1);
        }
        strcpy(p, texto);
        p[tam - 1] = '\0';
    }

    //constructor
    Cadena(const char *texto="X"){          
        tam = strlen(texto) + 1;
        p = new char[tam];//4
        if(p == NULL){
            cout<<"No hay memoria"<<endl;
            cout<<"linea: "<<__LINE__<<endl;
            exit(1);
        }
        
        strcpy(this->p, texto);
        p[tam - 1] = '\0';//0 a 3
    }

    //SOBRECARGAS
    bool operator==(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) == 0) return true;
        return false;
    }

    bool operator==(const char *c){
        if(strcmp(this->p, c) == 0) return true;
        return false;
    }

    bool operator!=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) == 0) return false;
        return true;
    }

    bool operator!=(const char *c){
        if(strcmp(this->p, c) == 0) return false;
        return true;
    }

    bool operator>=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) >= 0) return true;
        return false;
    }

    bool operator>=(const char *c){
        if(strcmp(this->p, c) >= 0) return true;
        return false;
    }

    bool operator>(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) > 0) return true;
        return false;
    }

    bool operator>(const char *c){
        if(strcmp(this->p, c) > 0) return true;
        return false;
    }

    bool operator<=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) <= 0) return true;
        return false;
    }

    bool operator<=(const char *c){
        if(strcmp(this->p, c) <= 0) return true;
        return false;
    }

    bool operator<(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) < 0) return true;
        return false;
    }

    bool operator<(const char *c){
        if(strcmp(this->p, c) < 0) return true;
        return false;
    }

    void concatenarUnCaracter(char letra){
        system("pause");
        char *aux = new char[tam];
        if(aux == NULL){
            cout<<"No hay memoria"<<endl;
            cout<<"linea: "<<__LINE__<<endl;
            exit(1);
        }
        strcpy(aux, p);
        aux[tam-2] = letra;
        aux[tam-1] = '\0';

        delete[] p;
        p = aux;
    }

    bool operator+=(const char *c){
        int hasta = strlen(c);
        for(int i=0; i<hasta; i++){
            this->concatenarUnCaracter(c[i]);
        }
        return true;
    }

    bool operator+=(const Cadena &c){
        int hasta = strlen(c.p);
        for(int i=0; i<hasta; i++){
            this->concatenarUnCaracter(c.p[i]);
        }
        return true;
    }

    // Sobrecarga de operadores de entrada y salida
    friend ostream &operator<<(ostream &salida, const Cadena &c){
        salida<<c.p;
        return salida;
    }
    friend istream &operator>>(istream &entrada, Cadena &c){
        int tam = 100;
        cargarCadena(c.p, tam);
        return entrada;
    }

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
    ~Cadena(){
        delete[] p;
    }



};