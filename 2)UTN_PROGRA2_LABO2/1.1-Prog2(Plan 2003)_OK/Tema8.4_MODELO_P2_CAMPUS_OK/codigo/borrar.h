/*

void punto1(){//probar con excel 
    Punto1 objP;
    ArchivoPunto1 ARobjP;
    ARobjP.BorrarArchivo();

    Proveedor objPro;
    ArchivoProveedores ARobjPro("proveedores.dat");

    Compra objCom;
    ArchivoCompras ARobjCom("compras.dat");

    int tam1 = ARobjPro.contarRegistros();
    int tam2 = ARobjCom.contarRegistros();
    int contAnioActual=0;

    bool bandera;
    for(int i=0; i<tam1; i++){
        objPro = ARobjPro.leerRegistro(i);
        
        bandera = true;
        for(int j=0; j<tam2; j++){
            objCom = ARobjCom.leerRegistro(j);
        
            if((objPro.getNumeroProveedor()==objCom.getNumeroproveedor()) && (objCom.getFechaCompra().getAnio()!=2024)){//por que es 2022
                bandera = false;
            }else if((objPro.getNumeroProveedor()==objCom.getNumeroproveedor()) && (objCom.getFechaCompra().getAnio()==2024)){
                bandera = true;
                break;
            }
        }

        if(!bandera){
            objP.setearTodo(objPro.getNumeroProveedor(),objPro.getNombre(),objPro.getProvincia(),objCom.getFechaCompra().getAnio());
            ARobjP.GuardarArchivo(objP);
        }
    }
    ARobjP.mostrarArchivo();
}

*/