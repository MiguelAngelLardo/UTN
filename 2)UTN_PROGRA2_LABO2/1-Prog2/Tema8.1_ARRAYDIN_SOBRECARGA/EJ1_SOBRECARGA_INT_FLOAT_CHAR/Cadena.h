#pragma once
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
    void mostrar(); 

    void cargar(); 

    void setP(const char *texto); 

    void setTam(int tam); 
    int getTam() const; 

float EsUnNumeroYConvierteEnDecimal(const char* texto); 

//esta funcion quiero que recora todo sus indices del char
//y si encuentra una letra me retorne true
//y si solo me encuentra numeros me retorne false
//me ayudo la inteligencia con este link = https://chat.openai.com/share/84e06618-3ee4-4ae3-a77e-25c17c9ee725
bool AhiLetra(const char* texto, int tam); 

float VolveraIngresarValor(const char* valor1, int tam,const char* valor2);

int EsUnNumeroYConvierteEnNumero(const char* texto); 

int VolveraIngresarValorEntero(const char* valor1, int tam,const char* valor2); //-

    //constructor
    Cadena(const char *texto="X"); 
    Cadena& operator=(const char *s); 
   // Cadena& operator=(const Cadena &c);
    Cadena& operator=(const Cadena &c);
    const char* getP() const; 

    //SOBRECARGAS
    bool operator==(const Cadena &comparar); 

    bool operator==(const char *c); 

    bool operator!=(const Cadena &comparar); 

    bool operator!=(const char *c); 

    bool operator>=(const Cadena &comparar); 

    bool operator>=(const char *c); 

    bool operator>(const Cadena &comparar); 

    bool operator>(const char *c); 

    bool operator<=(const Cadena &comparar); 

    bool operator<=(const char *c); 

    bool operator<(const Cadena &comparar); 

    bool operator<(const char *c); 

    void concatenarUnCaracter(char letra); 

    bool operator+=(const char *c); 

    bool operator+=(const Cadena &c); 

    // Sobrecarga de operadores de entrada y salida
    // explicacion de IA de como pasar estas 2 funciones al .cpp
    // https://sl.bing.net/gvEPXviYayG
    friend ostream &operator<<(ostream &salida, const Cadena &c); 
    friend istream &operator>>(istream &entrada, Cadena &c); 

    //de esta forma es como utilizar varias veces el mismo constructor
    //https://sl.bing.net/gSdyHflebOC
    void operator()(const char *texto); 

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
    ~Cadena(); 



};