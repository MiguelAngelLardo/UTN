///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

///la clase Cadena tiene que servir para manejar cadenas de caracteres.
///El vector de char que contenga la cadena de caracteres debe ajustar su tama�o a lo estrictamente necesario.


class Cadena{
private:
    char *cad;
    int tam;
public:
    Cadena(const char *valorIni){
        tam=strlen(valorIni)+1;
        cad=new char[tam];
        if(cad==NULL)exit(1);
        strcpy(cad,valorIni);
        cad[tam-1]='\0';
    }
    void Mostrar(){
        cout<<cad<<endl;
    }
    ~Cadena(){
        delete []cad;
    }
    int getTam(){return tam;}
    char getCaracter(int pos){
        ///ver que habr�a que hacer para validar esta
        return cad[pos];
    }
    void aMayuscula(int cuantas=2){
        int i;
        if(cuantas==1){
                if(cad[0]!= 32) cad[0]-=32;
        }
        else{
            for(i=0;i<tam-1;i++){
                if(cad[i] != 32)cad[i]-=32;
            }
        }
    }
    bool operator ==(const Cadena &obj){
       if(strcmp(cad, obj.cad)==0) return true;
       return false;
    }
    bool operator ==(unsigned int caracteres){
       if(strlen(cad)==caracteres) return true;
       return false;
    }
    void operator=(Cadena obj){//no se suma +1 por q ya lo trae el objeto
        ///cad->quiero asignar lo que contiene obj.cad
        delete cad;
        tam=obj.tam;
        cad=new char[tam];
        if(cad==NULL) exit(1);
        strcpy(cad, obj.cad);
        cad[tam-1]='\0';  
    }

    void operator =(const char *obj){//aca si va el +1
        delete cad;
        tam=strlen(obj)+1;
        cout << tam << endl;
        cad=new char (tam);
        if(cad==NULL) exit(1);
        strcpy(cad, obj);
        cad[tam-1]='\0';
    }

    bool operator >(Cadena &obj){
        if(strcmp(cad, obj.cad)>0) return true;
        return false;
    }



    void operator+=(const Cadena &c){
        int hasta = strlen(c.cad);
        int tamTotal = tam+hasta+1; //9+5+1
        char *aux = new char[tamTotal]; //hola+chau+1
        if(aux==NULL) exit(1);
        strcpy(aux, this->cad); //hola lo paso a aux
        strcat(aux, c.cad);//aux+chau
        delete []cad;
        cad = new char[tamTotal];
        if(cad==NULL) exit(1);
        strcpy(cad, aux);
        delete []aux;

        /*
        int hasta = strlen(c.cad);
        char *aux = new char[tam+hasta+1];

        if(aux==NULL) exit(1);
        strcpy(aux, cad);
        strcat(aux, c.cad);
        delete []cad;
        tam = strlen(aux)+1;
        cad = new char[tam];
        if(cad==NULL) exit(1);
        strcpy(cad, aux);
        delete []aux;  */     
    }

};

///Sobrecargar el operador = para que se asigne de manera directa un vector de caracteres a un objeto cadena
///Sobrecargar el operador > para comparar 2 objetos Cadena. Debe devolver true si el objeto que llama contiene
/// una cadena "mayor" a la del objeto que se recibe como par�metro (orden lexicogr�fico: posici�n en el diccionario; m�s grande
/// es el que est� m�s cerca del final del diccionario)
//+= usando strcat o a mano 


int main(){

    Cadena palabra("fola"), otra("ghau");
   otra = "hola";
    
    palabra += otra;
    palabra.Mostrar();
   
    // if(palabra > otra){
    //     cout << "El objeto que llama es mayor que el llamado" << endl;
    // }else{
    //     cout << "El objeto que llama es menor que el llamado" << endl;
    // }
   
   
    // palabra=otra;
    // otra="Hallo!";

    // palabra.Mostrar();
    // if(palabra==otra){
    // ///if(palabra.operator==(otra)){
    //     cout<<"SON IGUALES";
    // }
    // else{
    //     cout<<"SON DISTINTAS";
    // }
    // cout<<endl<<endl;
    // if(palabra==4){///comparar con un n�mero para saber si la cantidad de caracteres es igual a ese n�mero
    //     cout<<"EL OBJETO TIENE 4 CARACTERES";
    // }
    // else{
    //     cout<<"EL OBJETO NO TIENE 4 CARACTERES";
    // }
	// cout<<endl<<endl;
	// system("pause");


	return 0;
}
