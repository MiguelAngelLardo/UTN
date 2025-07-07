#ifndef PAIS_H
#define PAIS_H


class Pais{
    private:
        char _codigo[4];
        char _codigo2[3];
        char _nombre[45];
        char _continente[20];
        float _superficie;
        int _poblacion;
        short _independencia;
        float _expectativaDeVida;
        int _capital;
    public:
        void mostrar();

        void setCodigo(const char *);
        void setCodigo2(const char *);
        void setNombre(const char *);
        void setContinente(const char *);
        void setSuperficie(float);
        void setPoblacion(int);
        void setIndependencia(short);
        void setExpectativaDeVida(float);
        void setIDCapital(int);
        char * getCodigo();
        char * getCodigo2();
        char * getNombre();
        char * getContinente();
        float getSuperficie();
        int getPoblacion();
        short getIndependencia();
        float getExpectativaDeVida();
        int getIDCapital();
};

#endif // PAIS_H
