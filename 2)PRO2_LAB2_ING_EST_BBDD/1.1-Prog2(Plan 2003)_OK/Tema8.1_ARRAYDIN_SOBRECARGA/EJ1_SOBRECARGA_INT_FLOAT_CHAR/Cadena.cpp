#include<iostream>
#include<cstring>

using namespace std;

#include"funcionesGlobales.h"
#include"Cadena.h"

void Cadena::mostrar(){
    cout<<p<<endl;
}

void Cadena::cargar(){
    cargarCadena(p, tam);
}

void Cadena::setP(const char *texto){
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


void Cadena::setTam(int tam){
    this->tam = tam;
}
int Cadena::getTam() const{
    return tam-1;
}

float Cadena::EsUnNumeroYConvierteEnDecimal(const char* texto){
char* end;
float numeroFloat = std::strtof(texto, &end);
if (end != texto) { // Si se pudo convertir a float
return numeroFloat;
} else { // Si no se pudo convertir a float
    return -1;
}
}

//esta funcion quiero que recora todo sus indices del char
//y si encuentra una letra me retorne true
//y si solo me encuentra numeros me retorne false
//me ayudo la inteligencia con este link = https://chat.openai.com/share/84e06618-3ee4-4ae3-a77e-25c17c9ee725
bool Cadena::AhiLetra(const char* texto, int tam) {
    for (int i = 0; i < tam && texto[i] != '\0'; i++) {
        if (isdigit(texto[i])) {
            continue; // Si es un dígito, continuamos con la próxima iteración
        } else {
            return true; // Si encontramos un carácter que no es un dígito, devolvemos true
        }
    }
    return false; // Si recorremos toda la cadena sin encontrar ningún carácter que no sea un dígito, devolvemos false
}

float Cadena::VolveraIngresarValor(const char* valor1, int tam,const char* valor2){ //esta funcion se utiliza para EsUnNumeroYConvierteEnNumero

    bool band=true;
    float numF;

    char *valor = new char[tam];
    if(valor==NULL){
        cout<<"No hay memoria suficiente para la funcion VolveraIngresarValor"<<endl;
        exit(1);
    }

    strcpy(valor, valor1);

    do{
        if(AhiLetra(valor, tam)==false){
        numF = EsUnNumeroYConvierteEnDecimal(valor);
            band=true;
            delete[] valor;
            return numF;

        }else{
            cout<<valor<<" Error. El valor ingresado no es un numero"<<endl;
            band=false;
        }

        if(band==false){
            cout<<valor2<<endl;
            cargarCadena(valor, tam);
        }
    }while(band==false);

    delete[] valor;
    return EsUnNumeroYConvierteEnDecimal(valor);
}

int Cadena::EsUnNumeroYConvierteEnNumero(const char* texto){
    char* end;
    int numeroFloat = std::strtof(texto, &end);

    if (end != texto) { // Si se pudo convertir a float
        return numeroFloat;
    } else { // Si no se pudo convertir a float
        return -1;
    }
}

int Cadena::VolveraIngresarValorEntero(const char* valor1, int tam,const char* valor2){ //esta funcion se utiliza para EsUnNumeroYConvierteEnNumero

    bool band=true;
    int numF;

    char *valor = new char[tam];
    if(valor==NULL){
        cout<<"No hay memoria suficiente para la funcion VolveraIngresarValor"<<endl;
        exit(1);
    }

    strcpy(valor, valor1);

    do{
        if(AhiLetra(valor, tam)==false){
        numF = EsUnNumeroYConvierteEnDecimal(valor);
            band=true;
            delete[] valor;
            return numF;

        }else{
            cout<<valor<<" Error. El valor ingresado no es un numero"<<endl;
            band=false;
        }

        if(band==false){
            cout<<valor2<<endl;
            cargarCadena(valor, tam);
        }
    }while(band==false);

    delete[] valor;
    return EsUnNumeroYConvierteEnDecimal(valor);
}

    Cadena::Cadena(const char *texto){          
        tam = strlen(texto) + 1;
        setTam(tam);
        p = new char[tam];//4
        if(p == NULL){
            cout<<"No hay memoria"<<endl;
            cout<<"linea: "<<__LINE__<<endl;
            exit(1);
        }
        
        strcpy(this->p, texto);
        p[tam - 1] = '\0';//0 a 3
    }

Cadena& Cadena::operator=(const char *s){
            delete[] p;
            p = new char[strlen(s)+1];
            strcpy(p, s);
            return *this;
        }
// Cadena& Cadena::operator=(const Cadena &c){
//             delete[] p;
//             p = new char[strlen(c.p)+1];
//             strcpy(p, c.p);
//             return *this;
// }
Cadena& Cadena::operator=(const Cadena &c){
            delete[] p;
            p = new char[strlen(c.p)+1];
            strcpy(p, c.p);
            return *this;
}


const char* Cadena::getP() const{
            return p;
        }


    bool Cadena::operator==(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) == 0) return true;
        return false;
    }

bool Cadena::operator==(const char *c){
        if(strcmp(this->p, c) == 0) return true;
        return false;
    }

bool Cadena::operator!=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) == 0) return false;
        return true;
    }

bool Cadena::operator!=(const char *c){
        if(strcmp(this->p, c) == 0) return false;
        return true;
    }

bool Cadena::operator>=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) >= 0) return true;
        return false;
    }

bool Cadena::operator>=(const char *c){
        if(strcmp(this->p, c) >= 0) return true;
        return false;
    }

bool Cadena::operator>(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) > 0) return true;
        return false;
    }

bool Cadena::operator>(const char *c){
        if(strcmp(this->p, c) > 0) return true;
        return false;
    }

bool Cadena::operator<=(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) <= 0) return true;
        return false;
    }

bool Cadena::operator<=(const char *c){
        if(strcmp(this->p, c) <= 0) return true;
        return false;
    }

bool Cadena::operator<(const Cadena &comparar){
        if(strcmp(this->p, comparar.p) < 0) return true;
        return false;
    }

bool Cadena::operator<(const char *c){
        if(strcmp(this->p, c) < 0) return true;
        return false;
    }


void Cadena::concatenarUnCaracter(char letra){
    char *aux = new char[tam+1];
    if(aux == NULL){
        cout<<"No hay memoria"<<endl;
        cout<<"linea: "<<__LINE__<<endl;
        exit(1);
    }
    strcpy(aux, p);
    aux[tam-1] = letra;
    aux[tam] = '\0';

    delete[] p;
    p = aux;
    tam++;
}

// bool Cadena::operator+=(const char *c){
//         int hasta = strlen(c);
//         for(int i=0; i<hasta; i++){
//             this->concatenarUnCaracter(c[i]);
//         }
//         return true;
//     }

// bool Cadena::operator+=(const Cadena &c){
//         int hasta = strlen(c.p);
//         for(int i=0; i<hasta; i++){
//             this->concatenarUnCaracter(c.p[i]);
//         }
//         return true;
//     }

bool Cadena::operator+=(const Cadena &aux){
		Cadena original(p); //necesita un constructor que reciba un const char*
		///original=p;
		tam+=aux.tam-1;
		delete []p;
		p=new char[tam];
		if(p==NULL){
            exit(1);
            return false;
        }
		strcpy(p, original.p);
		strcat(p, aux.p);
        return true;
}

bool Cadena::operator+=(const char *aux){
        Cadena original(p); //necesita un constructor que reciba un const char*
        ///original=p;
        tam+=strlen(aux);
        delete []p;
        p=new char[tam];
        if(p==NULL){
            exit(1);
            return false;
        }
        strcpy(p, original.p);
        strcat(p, aux);
        return true;
}

ostream &operator<<(ostream &salida, const Cadena &c){
        salida<<c.p;
        return salida;
    }

istream &operator>>(istream &entrada, Cadena &c){
        int tam = 200;
        cargarCadena(c.p, tam);
        return entrada;
    }

void Cadena::operator()(const char *texto){
    setP(texto);
}

Cadena::~Cadena(){
        delete[] p;
    }











