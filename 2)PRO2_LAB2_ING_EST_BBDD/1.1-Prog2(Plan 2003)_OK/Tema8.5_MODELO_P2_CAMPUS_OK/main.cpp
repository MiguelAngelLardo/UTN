#include<iostream>
#include<cstring>

using namespace std;
#include "parcial2.h"


class Punto1{
private:
  int _codigoMaterial;
  int _tipo;//1 al 6
  float _importeTotal;//PU de material * cantidad de Compras

public:
  void setearTodo(int codigoMaterial, int tipo, float importeTotal){
    _codigoMaterial = codigoMaterial;
    _tipo = tipo;
    _importeTotal = importeTotal;
  }

  void mostrar(){
    cout<<"Material: "<<_codigoMaterial<<endl;
    cout<<"Tipo: "<<_tipo<<endl;
    cout<<"Importe Total: "<<_importeTotal<<endl;
  }
};


class ArchivoPunto1{
private:
  char _nombre[20];

public:
  ArchivoPunto1(const char *nombre = "Punto1.dat"){strcpy(_nombre, nombre);}  
  
  void borrarRegistrosPunto1(){
   FILE *p = fopen(_nombre,"wb");
   if(p == NULL){cout<<"No se pudo borrar el archivo";}
   fclose(p);
  }

  void GuardarRegistroPunto1(Punto1& obj){
   FILE *p = fopen(_nombre,"ab");
   if(p == NULL){return;}
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
   return;
  }

  void listarRegistrosPunto1(){
  Punto1 obj;
  FILE *p= fopen(_nombre, "rb");
  if (p == NULL){cout << "Error de apertura";return;}

  while (fread(&obj, sizeof(Punto1), 1, p) == 1){obj.mostrar();cout << endl;}
  fclose(p);
  }

  int contarRegistrosPunto1(){//cuantos registros tengo
  FILE *p = fopen(_nombre, "rb");
  if(p==NULL) return -1;  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Punto1); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  }

  Punto1 leerPorIndicePunto1(int index){
   Punto1 reg;
   FILE *pFile = fopen(_nombre, "rb");   
   if(pFile == nullptr){return reg;}   
   fseek(pFile, index * sizeof (Punto1), SEEK_SET);   
   fread(&reg, sizeof(Punto1), 1, pFile);
   fclose(pFile);
   return reg;   
  }

};

//1-archivo nuevo con codigo material, tipo y importe total
void punto1(){
  Material objM; // **codigooMaterial (PK)**, **Tipo**, pu(**importeTotal**)
  ArchivoMateriales ARobjM("materiales.dat");

  Compra objC; //codigoMateral (fk), cantidad(**importeTotal**), -> getFecha.getanio == 2024
  ArchivoCompras ARobjC("compras.dat");

  Punto1 objPunto1;
  ArchivoPunto1 ARobjPunto1;
  ARobjPunto1.borrarRegistrosPunto1();

  int tam1 = ARobjM.contarRegistros();
  int tam2 = ARobjC.contarRegistros();
  
  float importeTotal;

  for(int i = 0; i < tam1; i++){
    objM = ARobjM.leerRegistro(i);
    if(objM.getActivo()){
      for(int j = 0; j < tam2; j++){
        objC = ARobjC.leerRegistro(j);
        if((objC.getActivo()) && (objM.getCodigoMaterial() == objC.getCodigoMaterial()) && (objC.getFechaCompra().getAnio() == 2022)){
          importeTotal += objM.getPU() * objC.getCantidad();
          
        }  
      }

      if(importeTotal != 0){
        objPunto1.setearTodo(objM.getCodigoMaterial(), objM.getTipo(), importeTotal);
        ARobjPunto1.GuardarRegistroPunto1(objPunto1);
      }
      importeTotal = 0;
    }
  
  }  

  ARobjPunto1.listarRegistrosPunto1();


}


void setearVector(int v[], int tam, int valor=-1){

  for(int i = 0; i < tam; i++){
    v[i] = valor;
  }  
}

//cantidad de obras de cada provincia (son 24 provincias)
void punto2(){
  Obra objO;
  ArchivoObras ARobjO("obras.dat");

  int vAcumObras[24] = {0};

  //setearVector(vAcumObras, 24);

  int tam = ARobjO.contarRegistros();
  for(int i = 0; i < tam; i++){
    objO = ARobjO.leerRegistro(i);
    if(objO.getActivo()){
      vAcumObras[objO.getProvincia() - 1]++;
    }
  } 

  cout << "Cantidad de obras por provincia" << endl;
  for(int i = 0; i < 24; i++){
    if(vAcumObras[i] != 0){
      cout << "Provincia " << i + 1 << ": " << vAcumObras[i] << endl;
    }
  }  
}

//3-generar vector dinamico con todos los materiales y listar luego los materiales del vector que sean del valor ingresado
void punto3(){
  Material objM;
  ArchivoMateriales ARobjM("materiales.dat");
  Material *vObjM;

  int tam = ARobjM.contarRegistros();
  vObjM = new Material[tam];
  if(vObjM == nullptr){return;}

  for (int i = 0; i < tam; i++){
    vObjM[i] = ARobjM.leerRegistro(i);
  }
  
  int codigoMaterial;
  cout << "Ingrese el valor del codigo del material: ";
  cin >> codigoMaterial;

  for (int i = 0; i < tam; i++){
   if(vObjM[i].getCodigoMaterial() == codigoMaterial){
    vObjM[i].Mostrar();
   } 
    
  }

}


int main(){

  punto3();

  


    return 0;
}