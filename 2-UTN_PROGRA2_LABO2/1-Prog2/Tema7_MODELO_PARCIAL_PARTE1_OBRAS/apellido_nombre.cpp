#include <iostream>
#include <cstring>


using namespace std;
#include "parcialm1.h"

void SaltoDeLinea(int tam1=1000, int tam2=5)
{
    for (int i = 0; i < tam1; i++)
    {
        for(int j = 0; j < tam2; j++){
            cout << endl;
        }
    }
}

//a1) Para cada material la cantidad de compras que se hayan realizado entre todas las compras
void puntoa1(){
  Material objM; //codMateria, nombre, marca, tipo (1 al 6), precioUnitario
  ArchivoMateriales ARobjM("materiales.dat");

  Compra objC;//numeroCompra, numProveedor, codigoMaterial, codigoObra, cantidad, importe, fecha(dia, mes, anio)
  ArchivoCompras ARobjC("compras.dat");

  int tam1 = ARobjM.contarRegistros();
  int tam2 = ARobjC.contarRegistros();

  int cantidadCompras = 0;

  for (int i = 0; i < tam1; i++){
    objM = ARobjM.leerRegistro(i);

    
    for(int j = 0; j < tam2; j++){
      objC = ARobjC.leerRegistro(j);

      if((objC.getActivo()) && (objM.getActivo()) && (objM.getCodigoMaterial() == objC.getCodigoMaterial()))
        cantidadCompras ++;
    } 

    cout << "Material: " << objM.getNombre() << " -> Compras: " << cantidadCompras << endl;
    cantidadCompras = 0;    
  }
}  

//6-a2) El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron."
void puntoa2(){
  Proveedor objP;//numProv (1 a 60), nombre, telefono, direccion, provincia (1 a 24)
  ArchivoProveedores ARobjP("proveedores.dat");

  Compra objC;//numeroCompra, numProveedor, codigoMaterial, codigoObra, cantidad, importe, fecha(dia, mes, anio)
  ArchivoCompras ARobjC("compras.dat");

  int tam1 = ARobjP.contarRegistros();
  int tam2 = ARobjC.contarRegistros();

  float vProveedor[60] = {0.0};

  for (int i = 0; i < tam1; i++){
    objP = ARobjP.leerRegistro(i);

    for(int j = 0; j < tam2; j++){
      objC = ARobjC.leerRegistro(j);

      if((objC.getActivo()) && (objP.getActivo()) && (objP.getNumeroProveedor() == objC.getNumeroproveedor())){
        vProveedor[objP.getNumeroProveedor()-1] += objC.getImporte();
      }
    }  
  }

  //BUSCAR MAX

  int maximo = 0;
  for(int i = 1; i < 60; i++){
    (vProveedor[i] > vProveedor[maximo]) ? maximo = i : maximo = maximo;
  }  

  cout << "El nombre del proveedor que mas importe obtuvo es : " << ARobjP.leerRegistro(maximo).getNombre() << endl;
  cout << "El importe es : " << vProveedor[maximo] << endl;
}

void PonerCeroVector(int vec[], int tam, int valor=0){
    for(int i=0; i<tam; i++){
        vec[i]=valor;
    }
}


//a3) Los número de los proveedores a los que no se les compró nada el año pasado.
void puntoa3(){
  Proveedor objP;//numProv (1 a 60), nombre, telefono, direccion, provincia (1 a 24)
  ArchivoProveedores ARobjP("proveedor.dat");

  Compra objC;//numeroCompra, numProveedor, codigoMaterial, codigoObra, cantidad, importe, fecha(dia, mes, anio)
  ArchivoCompras ARobjC("compras.dat");

  int tam1 = ARobjP.contarRegistros();
  int tam2 = ARobjC.contarRegistros();

  int anioPasado = 2023;
  int vProveedor[60]; //<-----1 se rompe
  
  PonerCeroVector(vProveedor, 60, -1);


  for(int i = 0; i < tam1; i++){
    objP = ARobjP.leerRegistro(i);//proveedor

    for(int j = 0; j < tam2; j++){
      objC = ARobjC.leerRegistro(j);//compra con fecha

      if((objC.getActivo()) && (objP.getActivo()) && (objP.getNumeroProveedor() == objC.getNumeroproveedor())){
        if(objC.getFechaCompra().getAnio() == anioPasado){
          vProveedor[objP.getNumeroProveedor()-1] = 1;
        }
      }  
    }  
  }  

  cout << "Proveedores sin ventas en el anio pasado: " << endl;
  for(int i = 0; i < 60; i++){
    if(vProveedor[i] == -1){
      cout << "Proveedor numero: " << i+1 << endl;
    }  
  }  
}

//a4) El gasto en obra gruesa para cada uno de las obras. (analizar bien. Es el punto más complejo porque requiere del uso de 3 archivos)
void puntoa4(){
  Obra objO; //codObra(char), direccion (char), provincia (1 a 24), estado ejecuciom (1 a 5)
  ArchivoObras ARobjO("obras.dat");

  Material objM;//codMateria, nombre, marca, tipo (1-gruesa - al 6), precioUnitario -> va con objCompra
  ArchivoMateriales ARobjM("materiales.dat");

  Compra objC;//numeroCompra, numProveedor, codigoMaterial, codigoObra, cantidad, importe, fecha(dia, mes, anio) -> va con objO
  ArchivoCompras ARobjC("compras.dat");

  int tam1 = ARobjO.contarRegistros();
  int tam2 = ARobjM.contarRegistros();//material va con compra
  int tam3 = ARobjC.contarRegistros();//coompra va con obra

  float gastoEnCadaObra = 0.0;

  cout << "***Obras****"<< endl;
  for(int i = 0; i < tam1; i++){//obra
    objO = ARobjO.leerRegistro(i);

    for (int j = 0; j < tam3; j++){//compra
      objC = ARobjC.leerRegistro(j);

      if((objC.getActivo()) && (objO.getActivo()) && ((strcmp(objC.getCodigoObra(), objO.getCodigoObra())==0))){

        for (int k = 0; k < tam2; k++){//material
          objM = ARobjM.leerRegistro(k);

          if((objM.getActivo()) && (objC.getCodigoMaterial() == objM.getCodigoMaterial()) && (objM.getTipo() == 1)){
            gastoEnCadaObra += (objM.getPU() * objC.getCantidad());//el importe de objC ya trae la multiplicacion hecha
          }
        } 
      }  
    }

    objO.Mostrar();
    cout << "Gasto en obra gruesa para cada obra: " << gastoEnCadaObra << endl << endl;
    gastoEnCadaObra = 0.0;

  }  

}


//a5) La/s provincia/s con más de 22 proveedores
//ver
void puntoa5(){
  Proveedor objP;//numProv (1 a 60), nombre, telefono, direccion, provincia (1 a 24)
  ArchivoProveedores ARobjP("proveedores.dat");

  int tam = ARobjP.contarRegistros();
  int vProvAcumProv[24] = {0}; //mostrar los que tiene mas de 22 proveedores

  for (int i = 0; i < tam; i++){
    objP = ARobjP.leerRegistro(i);

    if(objP.getActivo()){
      vProvAcumProv[objP.getProvincia()-1]++;
    }  
  }  

  

   for(int i = 0; i < 24; i++){
     cout << "provincia " << i+1 << ": " << vProvAcumProv[i] << endl;
   }  

   cout << "///////////////////////////" << endl;

  for(int i = 0; i < 24; i++){
    if(vProvAcumProv[i] == 2){
      cout << "Provincia con 2 proveedores: " << i+1 << endl;
    }  
  }
}

bool reemplazarRegistro(Compra& reg, int posicionAReemplazar){
    FILE *p = fopen("compras.dat", "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Compra), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return pudoEscribir;
}

//a6) Dar de baja lógica a todas las compras del año 2020.
void puntoa6(){
  Compra objC;//numeroCompra, numProveedor, codigoMaterial, codigoObra, cantidad, importe, fecha(dia, mes, anio) -> va con objO
  ArchivoCompras ARobjC("compras.dat");

  int tam = ARobjC.contarRegistros();

  for(int i = 0; i < tam; i++){
    objC = ARobjC.leerRegistro(i);

    if((objC.getFechaCompra().getAnio()) == 2020 && (objC.getActivo())){
      objC.setActivo(false);
      cout << (reemplazarRegistro(objC, i) ? "" : "No se reemplazo\n");    
    }  
  }

  cout << "MOSTRANDO  COMPRAS NO BORRADAS" << endl;
  for (int i = 0; i < tam; i++){ 
    objC = ARobjC.leerRegistro(i);
    if(objC.getActivo()){
      objC.Mostrar();
      cout << endl;
    }
  }   
}

bool reemplazarRegistro2(Material& reg, int posicionAReemplazar){
    FILE *p = fopen("materiales.dat", "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Material), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Material), 1, p);
    fclose(p);
    return pudoEscribir;
}
//a7) Modificar el precio de las aberturas en el archivo de materiales. Incrementar un 10% todos los materiales de ese tipo.
//ver
void puntoa7(){
  Material objM;//codMateria, nombre, marca, tipo (1- 3 aberturas al 6), precioUnitario 
  ArchivoMateriales ARobjM("materiales.dat");

  int tam = ARobjM.contarRegistros();

  for (int i = 0; i < tam; i++){
    objM = ARobjM.leerRegistro(i); //se rompe aca pero el mostrar anda bien

    if((objM.getActivo()) && (objM.getTipo() == 3)){
      
      objM.setPU(objM.getPU() * 1.1);
      if(reemplazarRegistro2(objM, i)){
        cout << "Se reemplazo" << endl;
        system("pause");
      }
    }  
  }  

  cout << "Mostrando Modificados" << endl;
  for (int i = 0; i < tam; i++){
    objM = ARobjM.leerRegistro(i);
    objM.Mostrar();
    cout << endl;
  }
}


//LISTAR 4 DAT
void mostrarArchivoObras(){
    Obra obj;
    FILE *p;
    p = fopen("obras.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&obj, sizeof(Obra), 1, p) == true){
    obj.Mostrar();
    cout << endl;
}
    fclose(p);
}

void mostrarArchivoMaterial(){
    Material obj;
    FILE *p;
    p = fopen("materiales.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&obj, sizeof(Material), 1, p) == true){
    obj.Mostrar();
    cout << endl;
}
    fclose(p);
}

void mostrarArchivoCompra(){
    Compra obj;
    FILE *p;
    p = fopen("compras.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&obj, sizeof(Compra), 1, p) == true){
    obj.Mostrar();
    cout << endl;
}
    fclose(p);
}

void mostrarArchivoProveedor(){
    Proveedor obj;
    FILE *p;
    p = fopen("proveedores.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&obj, sizeof(Proveedor), 1, p) == true){
    obj.Mostrar();
    cout << endl;
}
    fclose(p);
}

void menu(){
  
  int opc;
  while (true)
  { 
    system("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Mostrar Obras" << endl;
    cout << "2-Mostrar Materiales" << endl;
    cout << "3-Mostrar Compras" << endl;
    cout << "4-Mostrar Proveedores" << endl;
    cout << "---------------------" << endl;
    cout << "5-a1) Para cada material la cantidad de compras que se hayan realizado entre todas las compras." << endl;
    cout << "6-a2) El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron." << endl;
    cout << "7-a3) Los número de los proveedor a los que no se les compró nada el año pasado." << endl;
    cout << "8-a4) El gasto en obra gruesa para cada uno de las obras." << endl;
    cout << "9-a5) La/s provincia/s con más de 22 proveedor" << endl;
    cout << "10-a6) Dar de baja lógica a todas las compras del año 2020." << endl;
    cout << "11-a7) Modificar el precio de las aberturas en el archivo de materiales. Incrementar un 10% todos los materiales de ese tipo." << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {

    /**********************/
    case 1:
      mostrarArchivoObras();      
      break;
    /**********************/
    case 2:
      mostrarArchivoMaterial();
      break;
    /**********************/
    case 3:{
      mostrarArchivoCompra();
      }break;

    /**********************/
    case 4:
      mostrarArchivoProveedor();
      break;
    /**********************/

    case 5:{
      puntoa1();
    }break;

    case 6:{
      puntoa2();
    }break;

    case 7:{
      puntoa3();
    }break;

    case 8:{
      puntoa4();
    }break;

    case 9:{
      puntoa5();
    }break;

    case 10:{
      puntoa6();
    }break;

    case 11:{
      puntoa7();
    }break;

    case 0:
      return;

    default:
      cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
      break;
    }
    system("pause");

  } 
}

int main() {
  menu();

  return 0;
}