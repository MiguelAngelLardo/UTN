///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Pila{
private:
     int *_pPila;
     int  _tope, _tam;

public:
    Pila(int tamanio){
        _tam=tamanio;
        _pPila=new int[_tam];
        if(_pPila==NULL)exit(1);
        _tope=0;
    }
    
    bool agregarValor(int numero){
        if(_tope==_tam){return false;}//3 = 3 da false
        _pPila[_tope] = numero;//[0] = 1, [1] = 22, [2] = 45;
        _tope++ ;
        return true;
    }

    bool sacarValor(int &numero){
        if(_tope==0){return false;}

        numero = _pPila[--_tope];//numero = _pPila[--3]//va de 0 a 4 pero queda en 5 por eso hago -- primero
        ///--_tope;
        ///numero = pPila[_tope];
        return true;
    }

    ~Pila(){
        delete []_pPila;
    }
};


int main(){
    Pila pilaLifo(3);
    int ingreso, salida;

    // Ingresar valores en la cola
    for(int i=1;i<=2;i++){
            cout<<"INGRESE UN VALOR PARA LA PILA: ";
            cin>>ingreso;
            pilaLifo.agregarValor(ingreso);          
    }

    cout<<"INGRESE UN VALOR PARA LA PILA: ";
    cin>>ingreso;
    if(!pilaLifo.agregarValor(ingreso)){
            cout<<"VALOR NO ACEPTADO. PILA LLENA"<<endl;
    }

    while(pilaLifo.sacarValor(salida)){
        cout << salida << endl;
    }

    cout<<"INGRESE UN VALOR PARA LA PILA: ";
    cin>>ingreso;
    if(!pilaLifo.agregarValor(ingreso)){
            cout<<"VALOR NO ACEPTADO. PILA LLENA"<<endl;
    }


     while(pilaLifo.sacarValor(salida)){
        cout << salida << endl;
    }
    
	system("pause");
	return 0;
}
