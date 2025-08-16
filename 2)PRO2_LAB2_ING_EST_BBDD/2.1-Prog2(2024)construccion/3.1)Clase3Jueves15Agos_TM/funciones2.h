#pragma once

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

int* cargarVector(int cantidad){
  int *vec = new int[cantidad];
  if(vec == nullptr){
      cout<<"No se pudo reservar memoria"<<endl;
      exit(1);
  }
  
  for(int i = 0; i < cantidad; i++){
      cout<<"Ingrese el valor para la posicion "<<i<<": "; cin>>vec[i];
  }

  return vec;//retorno el puntero del vec
}

// int* cargarVector(int *vec, int cantidad){
    
//     int *vec2 = new int[cantidad];
    
//     if(vec2 == nullptr){
//         cout<<"No se pudo reservar memoria"<<endl;
//         exit(1);
//     }

//     for(int i = 0; i < cantidad; i++){
//         vec2[i] = vec[i];
//     }

//     return vec2;

// }

int* cargarVectorPares(int *vec,int cantidad, int tam){
    
    int *vec2 = new int[cantidad];
    
    if(vec2 == nullptr){
        cout<<"No se pudo reservar memoria"<<endl;
        exit(1);
    }
    int cont=0;

    for(int i = 0; i < tam; i++){
        if(vec[i]%2==0){
            vec2[cont] = vec[i];
            if(cont<cantidad){
                cont++;
            }
        }
    }

    return vec2;

}

void mostrarVector(int *vec, int cantidad){
  cout << "Mostrando vector: " << endl;
  for(int x = 0; x < cantidad; x++){
    cout<<vec[x]<<" ";
  }
  cout<<endl;
}

void liberarVector(int *vec){
  delete[] vec;
  vec = nullptr;
}

void punto2(int vec[], int tam){

    int cont=0;
    int *vec2;
    
    for(int i=0; i<tam; i++){
        if(vec[i]%2==0){
            cont++;
        }
    }
    
    if(cont==0){
        cout<<"No hay numeros pares en el vector"<<endl;
    }else{
        cout<<"La cantidad de numeros pares en el vector es: "<<cont<<endl;
        vec2 = cargarVectorPares(vec,cont,tam);
    }

    mostrarVector(vec2,cont);

    liberarVector(vec2);
}

void punto3(int vec[], int tam){
    int cont = 0;
    for(int i=0; i<tam; i++){
        if(vec[i] > 0){
            cont ++;
        }
    }    
    

    int *vecPos = nullptr; //0x000 = 0
    vecPos = new int[cont];
    if(vecPos == nullptr){
        cout<<"No se pudo reservar memoria"<<endl;
        exit(1);
    }

    int indice = 0;
    for(int i=0; i<tam; i++){
        if(vec[i] > 0){
            vecPos[indice] = vec[i];
            indice++;
        }    
    }   
    
    cout << "Mostrar Vector Positivos" << endl;
    for(int i=0; i<cont; i++){
        cout << vecPos[i] << " ";
    }    

    liberarVector(vecPos);
}

void punto4(const char* val1, const char* val2){
    char val3[40]; //este char debe unir el val1 y val2 en val3
    strcpy(val3, val1);
    strcat(val3, val2);
    cout<<val3<<endl;
}


void punto4B(const char* vec1, const char* vec2){
    int tamA= strlen(vec1);
    int tamB= strlen(vec2);

    char *vec3 = nullptr;
    vec3 = new char[tamA+tamB];
    strcpy(vec3, vec1);
    strcat(vec3, vec2);
    cout<<vec3<<endl;
}

void punto4C(const char* vec1, const char* vec2){
  int tam1=0;
  int indice = 0;
  while(vec1[indice] != '\0'){ 
    tam1++;
    indice++;
  }

  int tam2=0;
  int indice2 = 0;
  while(vec2[indice2] != '\0'){ 
    tam2++;
    indice2++;
  }

  char *vec3 = nullptr;
  vec3 = new char[tam1+tam2+1];//4+4+1
  if(vec3 == nullptr){
      cout<<"No se pudo reservar memoria"<<endl;
      exit(1);
  }
                               //1 2 3 4
  for(int x= 0; x < tam1; x++){//0 1 2 3
    vec3[x] = vec1[x];  
  }  

  for (int x = 0; x < tam2; x++) //5 6 7 8
  {                              //4 5 6 7
    vec3[tam1+x] = vec2[x];
  }

  vec3[tam1 + tam2] = '\0'; // 👈 Añade el terminador nulo
        //en el indice 8 que seria posicion 9 
  
  cout<<vec3<<endl;
  delete[] vec3;
}
   
void punto5(const char* val1, const char* val2, int indice){
  char val3[40]; //este char debe unir el val1 y val2 en val3
  
  if(indice ==1){
    strcpy(val3, val1);
    strcat(val3, val2);
  }else if(indice == 2){
    strcpy(val3, val2);
    strcat(val3, val1);
  }
  cout<<val3<<endl;
}



















