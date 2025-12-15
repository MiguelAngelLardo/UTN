#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void cantidadPorTipo();
void tipoMayor();
void cantidadPorAntiguedad();
void antiguedadMenor();
void cantidadPorPropietario();
int contarPropiedades(const char *dni);

int menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "****** MENU REPORTES ******" << endl;
        cout << "1. CANTIDAD DE INMUEBLES REGISTRADOS DE CADA TIPO" << endl;
        cout << "2. TIPO DE INMUEBLE CON MAS CANTIDAD DE PROPIEDADES REGISTRADAS" << endl;
        cout << "3. CANTIDAD DE PROPIEDADES POR ANTIGÜEDAD " << endl;
        cout << "4. ANTIGÜEDAD CON MENOS CANTIDAD DE INMUEBLES" << endl;
        cout << "5. CANTIDAD DE INMUEBLES POR CADA PROPIETARIO " << endl;
        cout << "0. REGRESAR AL MENU PRINCIPAL" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cantidadPorTipo();
                    break;
            case 2: tipoMayor();
                    break;
            case 3: cantidadPorAntiguedad();
                    break;
            case 4: antiguedadMenor();
                    break;
            case 5: cantidadPorPropietario();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return 0;

}

///Desarrollo de funciones
void cantidadPorTipo(){
    ///1: casa; 2: departamento; 3: local comercial; 4: terreno 5: PH
    string tipos[]={"casa","departamento","local comercial","terreno","PH"};
    int vecTipos[5]={0};
    ArchivoPropiedades archiP;
    Inmueble reg;
    int cantRegistros=archiP.contarRegistros();
    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        if(reg.getEstado()) vecTipos[reg.getTipoPropiedad()-1]++;

    }
    for(int i=0;i<5;i++){
        cout<<"TIPO DE INMUEBLE "<<tipos[i]<<" CANTIDAD DE PROPIEDADES "<<vecTipos[i]<<endl;
    }

}

void tipoMayor(){}
/*void cantidadPorAntiguedad(){
    ///suponer que la antigüedad máxima es 80
    int vecAntiguedad[80]={0};
    ArchivoPropiedades archiP;
    Inmueble reg;
    int cantRegistros=archiP.contarRegistros();
    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        if(reg.getEstado()) vecAntiguedad[reg.getAntiguedad()-1]++;

    }
    for(int i=0;i<80;i++){
        if(vecAntiguedad[i]>0)
            cout<<"ANTIGUEDAD "<<i+1<<" CANTIDAD DE PROPIEDADES "<<vecAntiguedad[i]<<endl;
    }
} */



void cantidadPorAntiguedad(){
    int *vecAntiguedad;
    ArchivoPropiedades archiP;
    Inmueble reg;
    int maxAntiguedad=0;
    int cantRegistros=archiP.contarRegistros();
    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        if(reg.getEstado()){
                if(reg.getAntiguedad()>maxAntiguedad) maxAntiguedad=reg.getAntiguedad();
        }
    }

    vecAntiguedad=new int[maxAntiguedad];
    if(vecAntiguedad==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }
    for(int i=0;i<maxAntiguedad;i++) vecAntiguedad[i]=0;

    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        if(reg.getEstado()){
                vecAntiguedad[reg.getAntiguedad()-1]++;
        }
    }


    for(int i=0;i<maxAntiguedad;i++){
        if(vecAntiguedad[i]>0)
            cout<<"ANTIGUEDAD "<<i+1<<" CANTIDAD DE PROPIEDADES "<<vecAntiguedad[i]<<endl;
    }

    delete []vecAntiguedad;

}

void antiguedadMenor(){}

void cantidadPorPropietario(){
    ArchivoPropietario archiP;
    Propietario reg;

    int cantRegistros=archiP.contarRegistros();
    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        cout<<"PARA "<<reg.getNombre()<<" "<<reg.getApellido()<<" CANTIDAD DE PROPIEDADES ";
        cout<<contarPropiedades(reg.getDni())<<endl;
    }


}

int contarPropiedades(const char *dni){
    ArchivoPropiedades archiP;
    Inmueble reg;

    int contPropiedades=0;

    int cantRegistros=archiP.contarRegistros();
    for(int i=0;i<cantRegistros;i++) {
        reg=archiP.leerRegistro(i);
        if(reg.getEstado()){
                if(strcmp(reg.getDniPropietario(),dni)==0) contPropiedades++;
        }
    }
    return contPropiedades;

}
#endif // MENUREPORTES_H_INCLUDED
