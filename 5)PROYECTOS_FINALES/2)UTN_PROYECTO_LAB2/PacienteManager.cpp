#include <iostream>
#include "PacienteManager.h"
#include "Validaciones.h"
#include "Disenio.h"
#include "Estudios.h"
#include "EstudiosManager.h"
#include "EstudiosXHistoriaClinicaManager.h"
#include "ProfesionalXPacienteManager.h"

using namespace std;

//FUNCIONES UTILITARIAS
void PacienteManager::validarPacienteGetEstado(int indice, int yActual, int deltaYEstatica, bool modificale){
  Paciente pacienteTemporal = _pacienteArchivo.leer(indice, _pacienteArchivo.getNombreArchivo());//traigo el pac temporal
  int xTitulo = calcularCentradoX("DATOS DEL PACIENTE");
  int xKeyValue = xTitulo - 2;
  int yBody = yActual + 6, yFooter = yActual + 22;


  if(!modificale){ //viene por omision en false y sifgnifica que es CARGA no MODIFICACION => si no es modificable es carga
    if(pacienteTemporal.getEstado()){
      coutCentrado("El paciente ya esta registrado y esta dado de alta. Debe ingresar otro DNI.", yActual, deltaYEstatica);
    }
  }

  if(!pacienteTemporal.getEstado()){
    mostrarPacientePosicionado(pacienteTemporal, xTitulo, xKeyValue, yBody);
    coutCentrado("Ya existe un paciente con ese DNI, pero esta dado de BAJA.", yFooter, deltaYEstatica);
    if(preguntarSiNoRl("Quiere DARLE DE ALTA?", yActual)){ //hace q lo que viene despues este un espacio mas abajo
      pacienteTemporal.setEstado(true);
      (_pacienteArchivo.modificar(pacienteTemporal, indice, _pacienteArchivo.getNombreArchivo())) ? coutCentrado("Paciente dado de alta.", yFooter, deltaYEstatica) : coutCentrado("No se pudo dar de alta al paciente.", yFooter, deltaYEstatica);
    }else{
      coutCentrado("No se ha dado de alta al paciente...", yFooter, deltaYEstatica);
    }
  }
}

bool PacienteManager::validarPacienteGetNroafiliado_OS(string os, string nroAfiliado, int yActual, int deltaYEstatica){
  int cantidadRegs = _pacienteArchivo.getCantidadRegistros(_pacienteArchivo.getNombreArchivo());
  if(cantidadRegs == 0 || cantidadRegs == -1) return true; //en la primer entrada historica no tiene q validar nada => "esta validado en si"
                                                           //en la primer carga historica va a devolder -1 por que no existe el archivo aun

  Paciente *vDinPacientes = nullptr; // Inicializado a nullptr
  vDinPacientes = new Paciente[cantidadRegs]; //vec din del tam total

  if(vDinPacientes == nullptr) {
    coutCentrado("Error de memoria...", yActual, deltaYEstatica);
    return false;
  }

  _pacienteArchivo.leer(vDinPacientes, cantidadRegs, _pacienteArchivo.getNombreArchivo()); //cargo vec din con todos los pacientes

  for(int i = 0; i < cantidadRegs; i++){ //recorro vec din
    Paciente pacienteTemporal = vDinPacientes[i];
    if((pacienteTemporal.getObraSocial() == os) && (pacienteTemporal.getNumeroDeAfiliado() == nroAfiliado)){
      coutCentrado("Ya existe un paciente con esa obra social y numero de afiliado.", yActual, deltaYEstatica);
      delete [] vDinPacientes;
      vDinPacientes = nullptr;
      return false;
    }
  }

  delete [] vDinPacientes;
  vDinPacientes = nullptr;
  return true;
}

bool PacienteManager::seleccionarTipoHabitacion(const string& textoAMostrar, int &yActual) {
  const int colorFondoSeleccionado = rlutil::RED;
  const int colorFondoNoSeleccionado = rlutil::BLACK;
  const int textoSeleccionado = rlutil::WHITE;
  const int textoNoSeleccionado = rlutil::LIGHTGREEN;

  bool esUTI = true;
  bool salir = false;

  string mensaje = string(1, char(175)) + " Seleccione " + textoAMostrar + ":";
  int x = calcularCentradoX(mensaje);

  while(!salir){//lo hago while para cambiar un poco del do while pero es lo mismo
    coutPosicionadoRl(x, yActual, mensaje, rlutil::BLUE, rlutil::WHITE); // Mostrar mensaje principal de toda la vida

    coutPosicionadoRl(x + mensaje.length() + 1, yActual, "[ ] UTI", esUTI ? colorFondoSeleccionado : colorFondoNoSeleccionado, esUTI ? textoSeleccionado : textoNoSeleccionado, false); // Mostrar opción UTI (fondo rojo si está seleccionada, negro si no)
    if(esUTI) coutPosicionadoRl(x + mensaje.length() + 2, yActual, "X", colorFondoSeleccionado, textoSeleccionado, false); // Mostrar X en UTI si está seleccionada

    coutPosicionadoRl(x + mensaje.length() + 10, yActual, "[ ] Piso", !esUTI ? colorFondoSeleccionado : colorFondoNoSeleccionado, !esUTI ? textoSeleccionado : textoNoSeleccionado, false); // Mostrar opción Piso (fondo rojo si está seleccionada, negro si no
    if(!esUTI) coutPosicionadoRl(x + mensaje.length() + 11, yActual, "X",  colorFondoSeleccionado, textoSeleccionado, false); // Mostrar X en Piso si está seleccionada

    switch(rlutil::getkey()){
      case rlutil::KEY_LEFT: esUTI = true; break;
      case rlutil::KEY_RIGHT: esUTI = false; break;
      case rlutil::KEY_ENTER: salir = true; break;
    }
  }

  yActual += 2;//sigue el flujo de 2 en dos por referencia
  return esUTI;
}


void PacienteManager::cargarPaciente(){//usa el validar todo 1=texto, 2=dni, 3=mail, 4=telefono. Usa valirdarFecha. usa validar getEstado, validar Nro y OS, tipoHabitacion
  const int cantidadFilas = 24;
  int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaY = 2, deltaYEstatica = 0;

  string dni = validarTodoRl("el dni", yActual, 2);
  int indice = _pacienteArchivo.buscarPorDni(dni);
  if(indice >= 0){//verifica si esta en .dat
    validarPacienteGetEstado(indice, yActual, deltaYEstatica); // y si esta en el .dat verifica si tiene o no _estado true
    return;
  }
  coutCentrado("El paciente es nuevo, vamos a continuar con su carga.", yActual, deltaYEstatica);

  string nombre = validarTodoRl("el nombre", yActual, 1, deltaY, 3, 25);
  string apellido = validarTodoRl("el apellido", yActual, 1, deltaY, 3, 25);
  string domicilio = validarTodoRl("el domicilio", yActual);
  string mail = validarTodoRl("el mail", yActual, 3);
  string telefono = validarTodoRl("el telefono", yActual, 4);
  Fecha fechaNacimiento = validarFechaRl("la fecha de nacimiento", yActual);

  string obraSocial = validarTodoRl("la obra social", yActual, 1, deltaY, 2, 8);
  string numeroAfiliado = validarTodoRl("el numero de afiliado", yActual, 1, deltaY, 8, 8);
  if(!validarPacienteGetNroafiliado_OS(obraSocial, numeroAfiliado, yActual, deltaYEstatica)) return;  //si no esta validado significa que no se puede pasar y sale del menu

  string antecedenteFamiliar = validarTodoRl("los antecedentes familiares", yActual, 1, deltaY, 7, 35);
  string antecedentePaciente = validarTodoRl("los antecedentes del paciente", yActual, 1, deltaY, 7, 35);
  bool esUTI = seleccionarTipoHabitacion("el tipo de habitacion",yActual);

  Paciente nuevoReg = Paciente (nombre, apellido, domicilio, dni, mail, telefono, obraSocial, numeroAfiliado, antecedenteFamiliar, antecedentePaciente, fechaNacimiento, esUTI);//estado = true por omision
  coutCentrado(_pacienteArchivo.agregarRegistro(nuevoReg, _pacienteArchivo.getNombreArchivo()) ? "Paciente guardado." : "No se pudo guardar el paciente.", yActual);

}
void PacienteManager::listarPacientes() {
  const int cantidadFilas = 0;
  int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaYEstatica = 0;
  
  int cantRegs = 0;
  bool exitoEnCargar = true;
  validarExistenciaDat_CeroReg_ErrorMem(_pacienteArchivo, cantRegs, exitoEnCargar, yActual, deltaYEstatica);
  if(!exitoEnCargar) return;

  Paciente *vDinPac = nullptr;
  vDinPac = new Paciente[cantRegs];//armo array dinamico de paciente
  if(vDinPac == nullptr){
    coutCentrado("Error de memoria.", yActual, deltaYEstatica);
    return;
  }
  
  _pacienteArchivo.leer(vDinPac, cantRegs, _pacienteArchivo.getNombreArchivo());//cargo el vec

  navegarPacientes(vDinPac, cantRegs);
  delete[] vDinPac; 
  vDinPac = nullptr;//borro la dire de la casa demolida
}
void PacienteManager::modificarPaciente(){//valida nro y OS. Valida pro getestado con y especifica
  const int cantidadFilas = 24;
  int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaY = 2, deltaYEstatica = 0;

  string dni = validarTodoRl("el dni del paciente a modificar", yActual, 2);
  int indice = _pacienteArchivo.buscarPorDni(dni);
  if(indice < 0){
    coutCentrado("No existe un paciente con ese DNI.", yActual, deltaYEstatica);
    return;
  }


  Paciente pacModificable = _pacienteArchivo.leer(indice, _pacienteArchivo.getNombreArchivo());
  if(!pacModificable.getEstado()){ //si esta dado de baja preg si lo quiero dar de alta o no, luego sale el menu ppal
    validarPacienteGetEstado(indice, yActual, deltaYEstatica, true); //le pongo true por que hay preg q no tiene q hacer
    return;
  }

  int xTituloAside = 3, xKeyValueAside = 3, yAside = yActual+3;
  coutCentrado("Paciente encontrado....", yActual, deltaYEstatica);
  mostrarPacientePosicionado(pacModificable, xTituloAside, xKeyValueAside, yAside); //muestro pacientes a la izquierda con un "listar especifico con colores retro"
  int yFija = (rlutil::trows() - cantidadFilas) / 2;
  int yFooter = rlutil::trows() - 4;

  int opcion;
  do{
      opcion = crearMenuInteractivo("DNI,Nombre,Apellido,Domicilio,Email,Telefono,Obra Social,N. Afiliado,Ant Fam,Ant Pac,Fec Nac,UTI / Piso,BAJA / ALTA");

      if(opcion != 13) rlutil::cls();//una vez q seleccion borro

      switch(opcion)
      {
        case 1:{
          string nuevoDni = validarTodoRl("el nuevo DNI", yFija, 2);
          pacModificable.setDni(nuevoDni);
        }break;

        case 2:{
          string nombre = validarTodoRl("el nuevo nombre", yFija);
          pacModificable.setNombre(nombre);
        }break;
        case 3:{
          string apellido = validarTodoRl("el nuevo apellido", yFija);
        pacModificable.setApellido(apellido);
        }break;
        case 4:{
          string domicilio = validarTodoRl("el nuevo domicilio", yFija);
          pacModificable.setDomicilio(domicilio);
        }break;
        case 5:{
          string mail = validarTodoRl("el nuevo mail", yFija, 3);
          pacModificable.setMail(mail);
        }break;
        case 6:{
          string telefono = validarTodoRl("el nuevo telefono", yFija, 4);
          pacModificable.setTelefono(telefono);
        }break;

        case 7:{
          string obraSocial = validarTodoRl("la nueva obra social", yFija, 1, deltaY, 2, 8);
          pacModificable.setObraSocial(obraSocial);
        } break;
        case 8:{
          string numeroAfiliado = validarTodoRl("el nuevo numero de afiliado", yFija, 1, deltaY, 8, 8);
          pacModificable.setNumeroDeAfiliado(numeroAfiliado);
        }break;

        case 9:{
          string antecedenteFamiliar = validarTodoRl("los nuevos antecedentes familiares", yFija, 1, deltaY, 10, 35);
          pacModificable.setAntecedenteFamiliar(antecedenteFamiliar);
        }break;
        case 10:{
          string antecedentePaciente = validarTodoRl("los nuevos antecedentes del paciente", yFija, 1, deltaY, 10, 35);
          pacModificable.setAntecedentePaciente(antecedentePaciente);
        }break;
        case 11:{
          Fecha fechaNacimiento = validarFechaRl("la nueva fecha de nacimiento", yFija);
          pacModificable.setFechaNacimiento(fechaNacimiento);
        }break;
        case 12:{
          bool esUTI = seleccionarTipoHabitacion("el nuevo tipo de habitacion",yFija);
          pacModificable.setEsUTI(esUTI);
        }break;
        case 13:{
          if(pacModificable.getEstado()){//preg por las dudas... igual si esta dado de baja se contempla ANTES en validarPacienteGetEstado
            coutCentrado("El paciente fue dado de baja...", yFooter, deltaYEstatica);
            pacModificable.setEstado(false);
          }
        }break;

      }//switch

      if(opcion == 7 || opcion == 8){ // valido que no haya coincidencia de OS y nro Afiliado
        if(!validarPacienteGetNroafiliado_OS(pacModificable.getObraSocial(), pacModificable.getNumeroDeAfiliado(), yFija, deltaYEstatica)) return;
      }

    if(opcion >= 1 && opcion <= 13){
      if (opcion == 13) (_pacienteArchivo.modificar(pacModificable, indice, _pacienteArchivo.getNombreArchivo())) ? coutCentrado("Cambios guardados correctamente....", yFooter, deltaYEstatica) : coutCentrado("Error al guardar los cambios", yFooter , deltaYEstatica);
      else (_pacienteArchivo.modificar(pacModificable, indice, _pacienteArchivo.getNombreArchivo())) ? coutCentrado("Cambios guardados correctamente....", yFija , deltaYEstatica) : coutCentrado("Error al guardar los cambios", yFija , deltaYEstatica);

      return;//muestra el msj especifico y sale
    }//if opcion >= 1 && <= 13

  }while(opcion != 14);
}//fx
void PacienteManager::buscarPaciente(){ //diferencia template persona y paciente.
  const int cantidadFilas = 20;
  int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaY = 2, deltaYEstatica = 0;

  string campoMasLargo = "Ant. Familiares:"; // Campo mas largo para calcular centrado
  int x = calcularCentradoX(campoMasLargo);

  int opcion;
  do {
    opcion = crearMenuInteractivo("BUSCAR POR DNI,BUSCAR POR NOMBRE,BUSCAR POR APELLIDO,BUSCAR POR DOMICILIO,BUCAR POR OBRA SOCIAL,BUSCAR POR NRO AFILIADO");
    rlutil::cls();


  int cantidad = _pacienteArchivo.getCantidadRegistros(_pacienteArchivo.getNombreArchivo());
  switch(opcion)
  {
    case 1:{ // DNI => no hago mas fx para poder mostrarlo comodo para el parcial
      string criterioDeSeleccion = validarTodoRl("el DNI a buscar", yActual, 2);
      int contDeBusqueda = 0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h. igual si no lo inicializo se mambea y trae basura
      Paciente *vDinCargado =  buscarPorAtributoPersona(&Persona::getDni, criterioDeSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr || contDeBusqueda == 0){ //con nullpter solo me abre basura
        coutCentrado("No se encontro el pacientes con ese DNI.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
      }
    }break;

    case 2:{ // Nombre de persona
      string criterioSeleccion = validarTodoRl("el nombre a buscar", yActual);
      int contDeBusqueda = 0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h.
      Paciente *vDinCargado =  buscarPorAtributoPersona(&Persona::getNombre, criterioSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr || contDeBusqueda == 0){
        coutCentrado("No se encontraron pacientes con ese nombre.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
     }
    }break;

    case 3:{ // Apellido de persona
      string criterioDeSeleccion = validarTodoRl("el apellido a buscar", yActual);
      int contDeBusqueda = 0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h.
      Paciente *vDinCargado =  buscarPorAtributoPersona(&Persona::getApellido, criterioDeSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr || contDeBusqueda == 0){
        coutCentrado("No se encontraron pacientes con ese apellido.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
     }
    }break;

    case 4:{ // domicilio es depersona
      string criterioDeSeleccion = validarTodoRl("el domicilio a buscar", yActual);
      int contDeBusqueda =0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h.
      Paciente *vDinCargado =  buscarPorAtributoPersona(&Persona::getDomicilio, criterioDeSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr || contDeBusqueda == 0){
        coutCentrado("No se encontraron pacientes con ese domicilio.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
      }
    }break;

    case 5:{ // OS es paciente
      string criterioDeSeleccion = validarTodoRl("la obra social a buscar", yActual);
      int contDeBusqueda = 0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h.
      Paciente *vDinCargado =  buscarPorAtributoPaciente(&Paciente::getObraSocial, criterioDeSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr || contDeBusqueda == 0){
        coutCentrado("No se encontraron pacientes con esa obra social.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
      }
    }break;

    case 6:{ //nro afiliado es de paciente
      string criterioDeSeleccion = validarTodoRl("el nro de afiliado a buscar", yActual);
      int contDeBusqueda = 0; //lo paso por refercencia y se pone en 0 por omision en la fx en el h.
      Paciente *vDinCargado =  buscarPorAtributoPaciente(&Paciente::getNumeroDeAfiliado, criterioDeSeleccion, contDeBusqueda);
      if(vDinCargado == nullptr){
        coutCentrado("No se encontraron pacientes con ese nro de afiliado.", yActual, deltaYEstatica);
        if(vDinCargado != nullptr){
          delete[] vDinCargado;  //libero contenido de la heap x seguridad
          vDinCargado = nullptr; //elimino la referencia en la stack x seguridad
        }
      }else{
        navegarPacientes(vDinCargado, contDeBusqueda);
        delete[] vDinCargado;  //libero contenido de la heap
        vDinCargado = nullptr; //elimino la referencia en la stack
      }
    }

  }//switch

  opcion = 7; //una vez q vi el buscar salgo del sub menu


  }while(opcion != 7);// 7 es la opcion de salir
}
void PacienteManager::listarEstudios(){
int y = 3;
 string dni= validarTodoRl("el DNI del paciente a buscar",y, 2, 7, 8);

  int indice = _pacienteArchivo.buscarPorDni(dni);
  y+=2;
  if(indice < 0){
    coutCentrado("No existe un paciente con ese DNI.", y);
    return;
  }

  Paciente paciente = _pacienteArchivo.leer(indice, _pacienteArchivo.getNombreArchivo());
  EstudiosXHistoriaClinicaManager estudiosManager;
  EstudiosManager eManager;
  Fecha fechaFiltro;
    std::string codigoFiltro;
    int opcion =0;
    rlutil::cls();
do{

   opcion = crearMenuInteractivo("VER TODOS LOS ESTUDIOS,VER POR TIPO DE ESTUDIO,VER ESTUDIOS POR FECHA");

     switch (opcion) {
        case 1:
            estudiosManager.buscarEstudiosPorDni(paciente.getDni(), 1, Fecha(), "");
            break;

        case 2: {
            rlutil::cls();
            Estudios tipoEstudio = eManager.listaEstudiosActuales();
            codigoFiltro = tipoEstudio.getCodigoEstudio();
            if(codigoFiltro.empty()){
              break;
            }
            estudiosManager.buscarEstudiosPorDni(paciente.getDni(), 2, Fecha(), codigoFiltro);
            break;
        }

        case 3: {
            rlutil::cls();
            fechaFiltro = validarFechaRl("Ingrese la fecha a buscar:", y);
            estudiosManager.buscarEstudiosPorDni(paciente.getDni(), 3, fechaFiltro, "");
            break;
        }
    }

}while(opcion != 4);
  rlutil::cls(); // Limpio la pantalla al finalizar la busqueda de estudios

}
void PacienteManager::listarProfesionales() {
int y = 3;
 string dni= validarTodoRl("el DNI del paciente a buscar",y, 2, 7, 8);
 y+=2;
  int indice = _pacienteArchivo.buscarPorDni(dni);
  if(indice < 0){
    coutCentrado("No existe un paciente con ese DNI.", y);
    return;
  }

  Paciente paciente = _pacienteArchivo.leer(indice, _pacienteArchivo.getNombreArchivo());
  EstudiosXHistoriaClinicaManager estudiosManager;
  ProfesionalXPacienteManager profesionalXPacienteManager;
  profesionalXPacienteManager.bucarProfesionalesPorDniPaciente(paciente.getDni());
  rlutil::cls();

  return;
}



template <typename T>//T = type de dato -  getGeter () por q no recibe param
Paciente *PacienteManager::buscarPorAtributoPersona(T (Persona::*getGeter)() const, const string &criterioSeleccion, int &contDeBusqueda){
  int contRegs = _pacienteArchivo.getCantidadRegistros(_pacienteArchivo.getNombreArchivo());
  Paciente *vDinPxCS; //vDinPacientexCriterioDeSeleccion

  for (int i = 0; i < contRegs; i++){ // Primera pasada: contar coincidencias
    Paciente pBuscado = _pacienteArchivo.leer(i, _pacienteArchivo.getNombreArchivo());
    if(pBuscado.getEstado()){//como lospunteros no pueden manejarse entre herencia debo hacer un casteo a una referencia de persona
     if ((static_cast<const Persona&>(pBuscado).*getGeter)() == criterioSeleccion){
        contDeBusqueda++;
     }
    }
  }

  vDinPxCS = new Paciente[contDeBusqueda];
  if(vDinPxCS == nullptr) return nullptr;

  int pos = 0;
  for (int i = 0; i < contRegs; i++) { // Segunda pasada: llenar vector
    Paciente pBuscado = _pacienteArchivo.leer(i, _pacienteArchivo.getNombreArchivo());
    if (pBuscado.getEstado()){
      if ((static_cast<const Persona&>(pBuscado).*getGeter)() == criterioSeleccion){
        vDinPxCS[pos++] = pBuscado;
      }
    }
  }

  return vDinPxCS;
}

template <typename T>//T = type de dato -  getGeter () por q no recibe param
Paciente *PacienteManager::buscarPorAtributoPaciente(T (Paciente::*getGeter)() const, const string &criterioSeleccion, int &contDeBusqueda){
  int contRegs = _pacienteArchivo.getCantidadRegistros(_pacienteArchivo.getNombreArchivo());
  Paciente *vDinPxCS; //vDinPacientexCriterioDeSeleccion

  for (int i = 0; i < contRegs; i++){ // Primera pasada: contar coincidencias
    Paciente pBuscado = _pacienteArchivo.leer(i, _pacienteArchivo.getNombreArchivo());
    if ((pBuscado.getEstado()) && (pBuscado.*getGeter)() == criterioSeleccion) contDeBusqueda++;//veo cuantos rgs con mi criterio de busqueda hay
  }

  vDinPxCS = new Paciente[contDeBusqueda];
  if(vDinPxCS == nullptr) return nullptr;

  int pos = 0;
  for (int i = 0; i < contRegs; i++) { // Segunda pasada: llenar vector
    Paciente pBuscado = _pacienteArchivo.leer(i, _pacienteArchivo.getNombreArchivo());
    if ((pBuscado.getEstado()) && (pBuscado.*getGeter)() == criterioSeleccion) vDinPxCS[pos++] = pBuscado;
  }

  return vDinPxCS;
}


