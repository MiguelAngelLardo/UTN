///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Cola{//nace con inicio=0 y fin=0 osea que sin fin == inicio esta vacia 
private:
    int *_pCola;
    int _indexInicio, _indexFin, _tam;

public:
    Cola(int tamanio){
        _tam = tamanio;
        _pCola = new int [_tam];
        if(_pCola == NULL)exit(1);
        _indexInicio = _indexFin = 0;
    }


    bool agregarValor1a(int numero) {
        return (_indexFin < _tam) ? (_pCola[_indexFin++] = numero, true) : false;
    }

    bool agregarValor1b(int numero) {
        if (_indexFin < _tam) {
            _pCola[_indexFin] = numero;
            _indexFin ++;
            return true;
        } else {
            return false;
        }
    }   

    bool agregarValor2(int numero){
        if(_indexFin == _tam){return false;}
        _pCola[_indexFin] = numero; //fin vale 0 en indice 1
        _indexFin ++;
        return true;
    }

    bool sacarValor1a(int &numero){
        return (_indexInicio < _indexFin) ? (numero = _pCola[_indexInicio++], true) : false;
    }

    bool sacarValor1b(int &numero){
        if(_indexInicio < _indexFin){
            numero = _pCola[_indexInicio];
            _indexInicio ++;
            return true;
        }else{
            return false;
        }
    }

    bool sacarValor2(int &numero){
        if(_indexInicio == _indexFin){return false;}
        numero = _pCola[_indexInicio];
        _indexInicio ++;
        return true;
    }

    ~Cola(){
        delete []_pCola;
    }
};


int main(){
    Cola cola(2);    
    int ingreso, salida;

    // Ingresar valores en la cola
    for (int i = 0; i < 3; ++i) {
        cout << "Ingrese valor para la cola: ";
        cin >> ingreso;
        cout << (cola.agregarValor1b(ingreso) ? "Valor agregado a la cola.\n" : "No hay espacio en la cola.\n");
    }

    // Eliminar valores de la cola
    cout << "\nEliminando valores de la cola:\n";
    while (cola.sacarValor1b(salida)) {
        cout << "Valor eliminado: " << salida << endl;
    }

    cout << "La cola estavacia.\n";


    
    
	cout<<endl;
	system("pause");
	return 0;
}

