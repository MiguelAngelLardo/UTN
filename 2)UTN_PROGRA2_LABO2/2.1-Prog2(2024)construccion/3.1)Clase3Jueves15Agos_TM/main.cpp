#include<iostream>

using namespace std;

#include"funciones2.h"

void menu(){

    
    
    int opcion;
    int *vec = nullptr;//0x0000
    
    int vecPunto2[10] = {1,2,3,4,5,6,7,8,9,10};
    int vecPunto3[12]= {-1,2,-2,3,-3,4,-4,5,-5,6,-6,7};//son 6 positivos
    
    do{
        cout<<"opcion 1 - Cargar y Mostrar Vector Dinamico"<<endl;
        cout<<"opcion 2 - Punto 2"<<endl;
        cout<<"opcion 3 - Punto 3"<<endl;
        cout<<"opcion 4 - Punto 4"<<endl;
        cout<<"opcion 5 - Punto 5"<<endl;

        cout<<"opcion 0 - fin del programa"<<endl;
        
        cin>>opcion;
        
        switch (opcion)
        {
            case 1:{
                cout << "Ingrese el tamaño del vector: "; cin>>opcion;
                vec = cargarVector(opcion);
                mostrarVector(vec, opcion);
                
            }break;
            case 2:{
                punto2(vecPunto2, 10);
            }break;
            
            case 3:{
                punto3(vecPunto3, 12);
                
            }break;
            case 4:{
                //punto4("hola","chau");
                //punto4B("hola"," mundo");
                punto4C("hola","chau");
                
            }break;
            case 5:{
                punto5("hola","chau", 1);
                punto5("hola","chau", 2);

            }break;
            
            
            case 0:{
                liberarVector(vec);
                exit(1);
            }break;
            
            
            
        }
        
    }while(true);
}

int main(){

    menu();

    // int *vecPos2;
    
    // if(vecPos2 == nullptr){
    //     cout<<"Es verdadero"<<endl;
    // }else{
    //     cout<<"Es falso"<<endl;
    // }

    // int *vecPos3 = nullptr;
    
    // if(vecPos3== nullptr){
    //     cout<<"Es verdadero"<<endl;
    // }else{
    //     cout<<"Es falso"<<endl;
    // }

        return 0;
}