#include<iostream>
#include<cstring>

using namespace std;

void cargarCadena(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Cadena{

private:
    char *_p;
    int _tam;
public:
    //constructor
    Cadena(const char *palabra){
        _tam = strlen(palabra) + 1;//para el \0
        _p = new char[_tam];
        if(_p == NULL){exit(1);}
        strcpy(_p, palabra);//este le pone solo el \0
        _p[_tam - 1] = '\0'; //por las dudas Kloster lo pone
    }

    //metodos
    int getTam(){return _tam;}

    void mostrar(){
        cout << _p;
    }

    void cargar(){
        cout << "Ingrese la palabra: ";
        cargarCadena(_p, _tam);
        _tam=strlen(_p); //actualizo el tam
    }

    //Agregar un metodo para saber si un caracter existe dentro de la cadena, debe devolver la posicion de la letra
    int existeCaracter(char caracter){
        int index=0;
        while(_p[index] != '\0'){
            if(_p[index] == caracter) return index+1;//por que va de 0 a tam
            index ++;
        }
        return -1;
    }

    //mostrar la ultima repetida
    int existeCaracter1(char caracter){
        int index=0;
        int pos=-1;
        while(_p[index] != '\0'){
            if(_p[index] == caracter){
                pos=index+1;
            }
            index ++;
        }
        return pos;
    }
    

    //Mostrar la letra en el indice buscado
    int MostrarLetraIndiceCadena(int indice){
        indice--;
        _tam--; //le quitamos el \0
        if(indice >= 0 && indice < _tam){
            cout << _p[indice];
            return 0;
        }
        return -1;
    }

    void ponerPrimerLetraMayuscula(){
        for(int i=97; i<123; i++){
            if(_p[0] == i){
                _p[0] -= 32;
                return;
            }
        }
        //sin for => _p[0] -= 32;//32 es la distancia entre 'a' y 'A' o entre 'z' y 'Z'
    }

    //Convertir TODAS a mayuscula (ojo con los espacios)
    void todasAMayuscula(){
        int index=0;
        while(_p[index] != '\0'){
            if(_p[index] != ' '){
                for(int i = 97; i < 123; i ++){
                    if(_p[index] == i){
                        _p[index] -=32;
                    }
                }
            }
            
            index ++;
        }
    }

    //destructor
    ~Cadena(){
        delete [] _p;
    } 
};



int main(){

    Cadena nuevaPalabra("hola como estas");

    nuevaPalabra.cargar();
    // int tam = nuevaPalabra.getTam();
    // cout << "tam " << tam << endl;
    // system ("pause");    


    
    cout << endl;
    // if(nuevaPalabra.MostrarLetraIndiceCadena(4)==-1){
    //     cout << "Indice fuera de rango" << endl;
    // }else{
    //     cout << endl;
    // }

   // nuevaPalabra.ponerPrimerLetraMayuscula();

//    char caracter;
//    cout << "Ingrese el caracter a buscar: "; cin >> caracter; 
//    int pos = nuevaPalabra.existeCaracter1(caracter);
//    if(pos == -1){
//     cout << "No existe el caracter dentro de la cadena" << endl;
//    }else{
//     cout << "La posicion del caracter es: " << pos;
//    }
    
cout << "Convertiendo todo a mayuscula.." << endl;
nuevaPalabra.todasAMayuscula();
nuevaPalabra.mostrar();


    return 0;
}