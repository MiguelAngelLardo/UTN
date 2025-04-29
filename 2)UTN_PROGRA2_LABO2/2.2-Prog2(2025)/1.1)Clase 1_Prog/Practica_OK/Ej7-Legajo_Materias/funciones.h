#pragma once

#include<iostream>
#include<cstring>

using namespace std;

void SaltoDeLinea(int tam1=1000, int tam2=5);

void menu();

void ingresarDatos(int &Legajo, int &dia, int &mes, int &NumeroMateria, int &Horas, int *Vec, int *vPto2, int matriz[5][31], bool *vAccesosPorMateria, int matriz2[5][31]);

void Punto1(int *Vec);

void Punto2(int *vecPto2);

void mostrarVector(int *Vec);

void Punto3(int matriz[5][31]);

void Punto4(bool *vAccesosPorMateria);

void ingresarDatos2(int &nMateria, char mNombreMateria[5][20], int *cantAlumnos, int *cantProfesores);

void Punto6(int matriz[5][31]);



///////////////////////////////////////////////////////////////////////////////////////////


void SaltoDeLinea(int tam1, int tam2)
{
    for (int i = 0; i < tam1; i++)
    {
        for(int j = 0; j < tam2; j++){
            cout << endl;
        }
    }
}

void menu(){

    int opcion;

    int Legajo;
    int dia;
    int mes;
    int NumeroMateria;
    int Horas;

    int Vec[5]={0};
    int vMateriaAcumHs[5]={0};
    int matriz[5][31] = {0}; //5 == N° materia y 31 == dias del mes
    bool vAccesosPorMateria[5]= {0};

    int nMateria;
    char mNombreMateria[5][20];
    int cantAlumnos[5];
    int cantProfesores[5];

    int matriz2[5][31] = {0};

    do{
        cout<<"1. Ingresar datos"<<endl;
        cout<<"2. Punto 1"<<endl;
        cout<<"3. Punto 2"<<endl;
        cout<<"4. Punto 3"<<endl;
        cout<<"5. Punto 4"<<endl;
        cout << "6. Ingresar datos 2 y mostrar punto 5" << endl;
        cout << "7. Punto 6" << endl;
        cout<<"30. Salir"<<endl<<endl;

        cout<<"ingrese una opcion: "; cin>>opcion;
        //SaltoDeLinea();

        switch(opcion){
            case 1:{
                ingresarDatos(Legajo, dia, mes, NumeroMateria, Horas, Vec, vMateriaAcumHs, matriz, vAccesosPorMateria, matriz2);
            }break;
            case 2:{
                Punto1(Vec);
            }break;
            case 3:{
                Punto2(vMateriaAcumHs);

            }break;
            case 4:{
                Punto3(matriz);
            }break;

            case 5:{
              Punto4(vAccesosPorMateria);
            }break;
             case 6:{
              ingresarDatos2(nMateria, mNombreMateria, cantAlumnos, cantProfesores);
            }break;

            case 7:{
              Punto6(matriz2);
            }break;

            case 30:{
                cout<<"Saliendo..."<<endl;
                exit(0);
            }break;


            default:{
                cout<<"opcion incorrecta"<<endl;
            }break;
        }

        system("pause");
    }while(opcion!=30);
}

void ingresarDatos(int &Legajo, int &dia, int &mes, int &NumeroMateria, int &Horas, int *Vec, int *vPto2, int matriz[5][31], bool *vAccesosPorMateria, int matriz2[5][31]){

    cout<<"ingrese legajo: "; cin>>Legajo;
    cout<<"ingrese dia: "; cin>>dia;
    cout<<"ingrese mes: "; cin>>mes;
    cout<<"ingrese numero de materia: "; cin>>NumeroMateria;
    cout<<"ingrese horas: "; cin>>Horas;

    while(Legajo!=0){

            //// Punto1
            Vec[NumeroMateria-1]++;
            //// Punto2
            vPto2[NumeroMateria-1] += Horas;
            //// Punto3
                if(mes==3){
                    matriz[NumeroMateria-1][dia-1]++;
                }
            ////

            //punto 4
            vAccesosPorMateria[NumeroMateria-1] = true;

            //punto 6
            if(mes==3){
              matriz2[NumeroMateria-1][dia-1] += Horas;
            }

        cout<<"ingrese legajo: "; cin>>Legajo;

        if(Legajo==0){break;}

        cout<<"ingrese dia: "; cin>>dia;
        cout<<"ingrese mes: "; cin>>mes;
        cout<<"ingrese numero de materia: "; cin>>NumeroMateria;
        cout<<"ingrese horas: "; cin>>Horas;
    }
}

void mostrarVector(int *Vec){
    for(int i=0; i<5; i++){
        cout<<"Materia "<<i+1<<": "<<Vec[i]<<endl;
    }
}

void Punto1(int *Vec){
    for(int i=0; i<5; i++){
        if(Vec[i]==0){
            cout<<"Materia "<<i+1<<": No se rindio"<<endl;
        }
    }
}

void Punto2(int *vecPto2){
int maxHsMateria = vecPto2[0]; //horas
int maxMateria = 0; //num materia
    for(int x = 1; x < 5; x ++){
        if(vecPto2 [x] > maxHsMateria) {//hs
            maxHsMateria = vecPto2[x];
            maxMateria = x; //num materia 
        }
    }

    for(int i=0; i<5; i++){
        if(vecPto2[i]==maxHsMateria){
            cout << "La materia con max hs registradas es: " << i+1 <<endl<< " y tiene cargado " << maxHsMateria << " horas."<<endl;
        }
    }

    cout<<endl;
}

void Punto3(int matriz[5][31]){
    for(int i=0; i<5; i++){
        for(int j=0; j<31; j++){
            if(matriz[i][j]>0){
                cout<<i+1<<"-"<<j+1<<" "<<matriz[i][j]<<" ";
            }
        }
    }
}

void Punto4(bool *vAccesosPorMateria){
  int contadorAccesosPorMateria = 0;
  for(int x = 0; x < 5; x++){
    if(vAccesosPorMateria[x]){
      contadorAccesosPorMateria++;
    }
  }

  cout << "Se registran " << contadorAccesosPorMateria << " materias con acceso." << endl;
}

void ingresarDatos2(int &nMateria, char mNombreMateria[5][20], int *cantAlumnos, int *cantProfesores){
  for(int i = 4; i >= 0; i--){
    cout << "ingrese el numero de la materia " << i+1 << endl;
    cin >> nMateria;

    cout << "Ingrese el nombre de la materia " << i+1 << endl;
    cin >> mNombreMateria[i];

    cout << "Ingrese la cantidad de alumnos de la materia " << i+1 << endl;
    cin >> cantAlumnos[i];

    cout << "Ingrese la cantidad de profesores de la materia " << i+1 << endl;
    cin >> cantProfesores[i];
  }
  cout << endl << endl;
  system("pause");

  for (int i = 0; i < 5; i++){
    cout << "Materia " << i+1 << ": " << mNombreMateria[i] << endl;
    cout << "Cantidad de alumnos: " << cantAlumnos[i] << endl;
    cout << "Cantidad de profesores: " << cantProfesores[i] << endl;
    cout << "Tiene " << cantAlumnos[i] / cantProfesores[i] << " alumnos por profesor." << endl;
  }
}

void Punto6(int matriz[5][31]){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 31; j++){
      if(matriz[i][j] > 0){
        cout << "Materia " << i+1 << " dia " << j+1 << " tiene " << matriz[i][j] << " horas." << endl;
      }
    }
  }
}
