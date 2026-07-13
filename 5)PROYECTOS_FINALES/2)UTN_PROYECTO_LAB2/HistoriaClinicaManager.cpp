#include <iostream>
#include "HistoriaClinicaManager.h"
#include "HistoriaClinica.h"
#include "Validaciones.h"
#include "PacienteArchivo.h"
#include "Disenio.h"
//#include "rlutil.h"
using namespace std;

//utilitarias => //26³ × 1000 = 17.576.000
string HistoriaClinicaManager::generarCodigoHC(string nombreArchivo){
  int cantidad = _historiaClinicaArchivo.getCantidadRegistros(nombreArchivo);

  string ultimoCodigo;
  if (cantidad == 0) {
      return "A000";
  }else{
    ultimoCodigo = _historiaClinicaArchivo.leer(cantidad-1, nombreArchivo).getCodigoHC();
  }

  //separar letras
  string letras = "";
  letras += ultimoCodigo[0];


  //separar numeros
  string numerosString = "";
  for(int x = 1 ; x < 4 ; x++){
    numerosString += ultimoCodigo[x];
  }

  //convertir a entero sin usar stoi
  //Cuando hacés una resta entre dos char, el compilador gestiona implícitamente esos caracteres a int, porque está realizando una operación aritmética.
  int numerosStringANumerosInt[3];//[0] es centena [1] es decena [2] es unidad
  for(int i = 0; i < 3; i ++){     //el numero '2' es un int 50
    numerosStringANumerosInt[i] = numerosString[i] - 48; // podria ser - '0' - ASCII 48 es 0 y ASCII 57 es 9
  }

  //ahora paso cada numero individual a uno solo para mejor manejo
  //int numeroCompletoInt = numerosStringANumerosInt[0]*100 + numerosStringANumerosInt[1]*10 + numerosStringANumerosInt[2];
  //no me sirve por que no me guarda el 023

  //sumo #1 en cada registro
  int contadorArrayCompleto = 0;//si es 3 reseteo a CERO e incremento una letra
  for(int i = 2; i >= 0 ; i --){//lo probe con for de 1000 y suma corerecta
    if(numerosStringANumerosInt[i] != 9){
      numerosStringANumerosInt[i] ++;
      break;
    }else{
      numerosStringANumerosInt[i] = 0;
      contadorArrayCompleto ++;
    }
  }

  //#999 sumo una letra
  if(contadorArrayCompleto == 3){
    (letras[0] != 'Z') ? letras[0] ++ : letras[0] = 'A';
  }

  //ahora junto letras + numerosStringANumerosInt[i] => lo convierto a string
  //pasar de int a char si necesita casteo explicito
  //si tengo un int 2 le sumo int 48 para que me de int 50 y lo paso a char dando '2'
  string codigoNuevo = "";
  codigoNuevo += letras[0]; // solo una letra

  for(int i = 0; i < 3; i++){
    codigoNuevo += (char)(numerosStringANumerosInt[i] + '0');
  }

  if(ultimoCodigo == "Z999"){
    cout << "El codigo llego a su limite, comuniquese con los programadores que estudiaron en la UTN Regional pacheco con Ariel Tapia." << endl;
    exit(1);
  }

 return codigoNuevo;
}
string HistoriaClinicaManager::obtenerDniDelPuntoDat(string nombreArchivo){
  int pos = 0;
  string dni = "";
  while (nombreArchivo[pos] != '.'){
    dni += nombreArchivo[pos];
    pos ++;
  }
  return dni;
}

void HistoriaClinicaManager::replicarY3(string dni){
  dibujarMarcoPrincipal();
  string mensaje = string(1, char(175)) + " " + "Ingrese el DNI:";
  int x = calcularCentradoX(mensaje);
  int y3 = 3;
  coutPosicionadoRl(x, y3, mensaje, rlutil::BLUE, rlutil::WHITE);//pinto hasta ":"
  coutPosicionadoRl(x + mensaje.length() + 1, y3, dni, rlutil::BLACK, rlutil::LIGHTGREEN, false);//dejo 1 espacio y muestro dni
}

void  HistoriaClinicaManager::cargarRegistro(){
  PacienteArchivo pacienteArchivo;

  const int cantidadFilas = 23; // Total de mensajes que voy a mostrar, lo sabe el programador, le pongo +1 a lso subrayados que se que va a tener
  int yActual = (rlutil::trows() - cantidadFilas) / 2; // Centrado inicial para 4 filas (3 inputs + 1 mensaje)
  int deltaYEstatica = 0;

  string dniPaciente = validarTodoRl("el DNI",  yActual, 2); ///la X lo calcula interno, la y => se que tengo un cout para el dni y un cout del msj de validacion

  int indiceDelDniBuscado;//lo paso por referencia
  if(!validarGetEstadoPaciente_cargaIndice(dniPaciente, indiceDelDniBuscado, yActual, deltaYEstatica)) return; //si !getEstado() en paciente.dat retorna, y me carga el indice de yapa

  if(indiceDelDniBuscado >= 0){
    string nombreArchivo = dniPaciente + ".dat";

    if(!_historiaClinicaArchivo.existeArchivo(nombreArchivo)){//si no hay .dat del paciente
      coutCentrado("El paciente no tiene un archivo de HC asociado. Se va a crear uno.", yActual, deltaYEstatica);// deltaY pasa por omision con valor 2 por cout a char subrayado
      primeraCargaHistorica(nombreArchivo, yActual);
    }else{
      HistoriaClinica ultimoRegistro = _historiaClinicaArchivo.leer(_historiaClinicaArchivo.getCantidadRegistros(nombreArchivo) - 1, nombreArchivo); //si existe el archivo veo si esta dado de alta la ultima HC
      if(!ultimoRegistro.getAltaMedica()){
        coutCentrado("El paciente ya tiene un archivo de HC asociado, se va a agregar un nuevo registro.", yActual, deltaYEstatica);//fila 2+1 por q dentro no resto
        adicionarRegistro(nombreArchivo, yActual);
      }else{
        coutCentrado("El paciente esta dado de ALTA MEDICA. Debe re-ingresarlo en el menu de altas medicas.", yActual, deltaYEstatica);//fila 2+1 por q dentro no resto
      }
    }
  }else{
    coutCentrado("El paciente no esta registrado. Agreguelo desde el menu de Pacientes.", yActual, deltaYEstatica);//fila 2+1 por q dentro no resto
  }
 // return; //me vuelve al menu de Historias Clinicas Men
}

bool HistoriaClinicaManager::validarGetEstadoPaciente_cargaIndice(string dniPaciente, int &indiceDelDniBuscado, int &yActual, int deltaYEstatica){
  PacienteArchivo pacienteArchivo;
  indiceDelDniBuscado = pacienteArchivo.buscarPorDni(dniPaciente); //aca veo que el dni esta en el dat de pacientes ->aca puedo obtener un obj paciente con el Leer() para tomar el nombre y apellido
  Paciente pacienteGetEstado = pacienteArchivo.leer(indiceDelDniBuscado, pacienteArchivo.getNombreArchivo());
  if(!pacienteGetEstado.getEstado()){
     coutCentrado("El paciente se encuentra dado de baja. Actualice su estado en el menu de Pacientes.", yActual, deltaYEstatica);// deltaY pasa por omision con valor 2 por cout a char subrayado
     return false;
  }
  return true;
}
void HistoriaClinicaManager::primeraCargaHistorica(string nombreArchivo, int &yActual){
  int deltaYEstatica = 0;
  (_historiaClinicaArchivo.primerCreacionHistorica(nombreArchivo)) ? coutCentrado("Archivo creado: " + nombreArchivo, yActual, deltaYEstatica) : coutCentrado("Archivo no creado: " + nombreArchivo, yActual, deltaYEstatica);//fila 2+1 por q dentro no resto => total de fila le paso 2 - filaRelativa 2

  HistoriaClinica obj = HistoriaClinica();//creo un objeto vacio y le seteo los primeros valores
  string codigoHC = generarCodigoHC(nombreArchivo);
  obj.setCodigoHC(codigoHC);
  obj.setAltaSistema(true);

  int cantidadRegistros = _historiaClinicaArchivo.getCantidadRegistros(nombreArchivo);//si la crea con PrimeracreacionHistorica tiene q tener registros CERO

  (cantidadRegistros == 0) ? coutCentrado((_historiaClinicaArchivo.agregarRegistro(obj, nombreArchivo) ? "Historia Clinica cargada correctamente" : "Error al cargar historia clínica"), yActual, deltaYEstatica)
   : (cantidadRegistros == -1) ? coutCentrado("Error: Archivo inaccesible o corrupto", yActual, deltaYEstatica)
   : coutCentrado("Archivo ya contiene registros - No se realizo carga", yActual, deltaYEstatica);

}

void HistoriaClinicaManager::adicionarRegistro(string nombreArchivo, int &yActual){
  int tipoValidacion = 1, deltaY = 2, deltaYEstatica = 0;
  string codigoHC = generarCodigoHC(nombreArchivo);   //se automatiza
  string dniPaciente = obtenerDniDelPuntoDat(nombreArchivo);   //se automatiza

  /****************SUB APARTADO => PROFESIONAL****************/
  coutCentrado("Ingrese el profesional tratante.", yActual, deltaYEstatica);
  Profesional profesional =  _profesionalManager.listaProfesionalesActuales();//string matriculaProfesional = validarTodo("el legajo del profesional", 1);  //la matricula va en el reg de la clase hs
  if(profesional.getMatricula()[0] == '\0') return;//si pone salir sale del menu
  replicarY3(dniPaciente);//pego la screenshot de Y3



  /****************SUB APARTADO => ESTUDIOS x HC => dni + regs + codEst + matricula + apellidoProf + nombreProf + resultado + fecha(omision) ****************/
  Estudios estudioComplementario;
  int yPregunta = yActual;  // Comienza en Y=5
  int yResultado = yActual-2; //aparece en Y=3 para hacer un "enrroque"
  bool esPrimerEstudio = true;
  do{
    string pregunta = esPrimerEstudio ? "Quiere ingresar un estudio complementario?" : "Quiere ingresar otro estudio complementario?";
    if(preguntarSiNoRl(pregunta, yPregunta, deltaYEstatica)){ //siempre en Y 5
      estudioComplementario = _estudiosManager.listaEstudiosActuales();  //me da el objeto estudio complementario
      string resultadoEstudio = validarTodoRl("el resultado del estudio", yResultado, tipoValidacion, deltaYEstatica, 8, 35);//siempre en Y = 3 tapa el dni por q sino hay desborde
      esPrimerEstudio = false;//no poner fecha en el constructor asi lo setea solo
     (_estudiosXHistoriaClinicaManager.agregarRegistro(dniPaciente, codigoHC, estudioComplementario.getCodigoEstudio(), profesional.getMatricula(), profesional.getApellido(), profesional.getNombre(), resultadoEstudio)) ? coutCentrado("Estudio agregado correctamente.", yActual, deltaYEstatica) : coutCentrado("Error al agregar el estudio.", yActual, deltaYEstatica);
    }else{
      estudioComplementario = Estudios(); // para que corte while
    }
  }while(estudioComplementario.getCodigoEstudio()[0] != '\0');
  /**************** FIN SUB APARTADO => ESTUDIOS x HC *****************/


  yActual = yPregunta + 2; //5 + 2 => vuelvo la Y donde siempre va a dar el encuadre
  SignosVitales signosVitales;
  if(preguntarSiNoRl("Quiere ingresar signos vitales?", yActual)){
    string sistolica = validarTodoRl("la presion sistolica", yActual, tipoValidacion, deltaY, 2, 3);
    string diastolica = validarTodoRl("la presion diastolica", yActual, tipoValidacion, deltaY, 2, 3);
    string frecuenciaCardiaca = validarTodoRl("la frecuencia cardiaca", yActual, tipoValidacion, deltaY, 2, 3);
    string frecuenciaRespiratoria = validarTodoRl("la frecuencia respiratoria", yActual, tipoValidacion, deltaY, 1, 2);
    string saturacion = validarTodoRl("la saturacion", yActual, tipoValidacion, deltaY, 2, 2);
    string temperatura = validarTodoRl("la temperatura", yActual, 5, deltaY, 2, 2);

    signosVitales = SignosVitales(sistolica, diastolica, frecuenciaCardiaca, frecuenciaRespiratoria, saturacion, temperatura);
  }

  string diagnostico = validarTodoRl("el diagnostico", yActual, tipoValidacion, deltaY, 10, 35);
  string tratamiento = validarTodoRl("el tratamiento", yActual, tipoValidacion, deltaY, 10, 35);
  string medicacion = validarTodoRl("la medicacion", yActual, tipoValidacion, deltaY, 10, 35);

   /****************SUB APARTADO => Prof x Pac => va con matricula****************/
  bool fallaPorMemoria = false; //como dentro se arma vDin mando un bool por referencia
  bool agregoReg =  _profesionalXPacienteManager.agregarRegistro(dniPaciente, profesional.getMatricula(), fallaPorMemoria); //dentro se encarga solo de no guardar los PK repetidos
  if(fallaPorMemoria){
    coutCentrado("Falla de memoria.", yActual, deltaYEstatica);
  } else{
    if(agregoReg) coutCentrado("Profesional tratante cargado correctamente.", yActual, deltaYEstatica);
  }

  /***************** FIN SUB APARTADO => Prof x Pac *****************/

  HistoriaClinica nuevoRegistro = HistoriaClinica(codigoHC, profesional.getMatricula(), signosVitales, diagnostico, tratamiento, medicacion);//omision fecha actual, altaMedica = false, altaSistema = false, estadoRegistro = true
  coutCentrado(_historiaClinicaArchivo.agregarRegistro(nuevoRegistro, nombreArchivo) ? "Historia Clinica cargada correctamente." : "Error al cargar la historia clinica.",  yActual, deltaYEstatica);
}

void HistoriaClinicaManager::listarHistoriasClinicas(){
  string dniPaciente, nombreArchivo;
  PacienteArchivo pacienteArchivo;

  int yActual = 3, deltaYEstatica = 0;

  dniPaciente= validarTodoRl("el DNI del paciente a buscar",yActual, 2);

  nombreArchivo = dniPaciente + ".dat";
  int indice = pacienteArchivo.buscarPorDni(dniPaciente);
  if(indice < 0){
      coutCentrado("No existe un paciente con ese DNI.", yActual, deltaYEstatica); // no exite el paciente
      return;
   }else if(!_historiaClinicaArchivo.existeArchivo(nombreArchivo)){// hay paciente pero no hay .dat del paciente
      coutCentrado("El paciente no tiene un archivo de HC asociado, dirijase a la opcion CARGA DE REGISTRO", yActual, deltaYEstatica);
      return;
    }

    int cantidad = _historiaClinicaArchivo.getCantidadRegistros(nombreArchivo);
    HistoriaClinica *vHC = new HistoriaClinica[cantidad];
    if(vHC == nullptr){
      coutCentrado("Error de memoria.", yActual, deltaYEstatica);
      return;
    }
    system("cls");

    _historiaClinicaArchivo.leer(vHC,cantidad,nombreArchivo);
    navegarHistoriasClinicas(vHC,cantidad,dniPaciente);

    delete[] vHC;
  }


 void HistoriaClinicaManager::altaMedica(){
    PacienteArchivo pacienteArchivo;//con esto busco por dni en la PacienteArchivo.h
    const int cantidadFilas = 4;
    int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaYEstatica = 0;

    string dniPaciente = validarTodoRl("el DNI", yActual, 2); //pido dni

    string nombreDelArchivo = dniPaciente + ".dat";//puede ser que exista el dni y no tenga registro en HC

    int indice = pacienteArchivo.buscarPorDni(dniPaciente);
    if(indice < 0){
      coutCentrado("No existe un paciente con ese DNI.", yActual); // no exite el paciente
      return;
    }else if(!_historiaClinicaArchivo.existeArchivo(nombreDelArchivo)){// hay paciente pero no hay .dat del paciente
      coutCentrado("El paciente no tiene un archivo de HC asociado, dirijase a la opcion CARGA DE REGISTRO", yActual);
      return;
    }

    int indiceDelDniBuscado;//lo paso por referencia
    if(!validarGetEstadoPaciente_cargaIndice(dniPaciente, indiceDelDniBuscado, yActual, deltaYEstatica)) return; //si !getEstado() en paciente.dat retorna

    if(indiceDelDniBuscado >= 0){

      Paciente paciente = pacienteArchivo.leer(indiceDelDniBuscado, pacienteArchivo.getNombreArchivo());//leeme en el indice de ese dni en el archivo pacientes.dat y me traigo el objeto
      string nombreArchivo = dniPaciente + ".dat";//otengo el nombre del .dat
      HistoriaClinica ultimoRegistro = _historiaClinicaArchivo.leer(_historiaClinicaArchivo.getCantidadRegistros(nombreArchivo) - 1, nombreArchivo);  //ahora con el nombre.dat veo si en la ultima HC alta = false

      adicionarAlta_Reingreso(paciente, nombreArchivo, yActual, deltaYEstatica, ultimoRegistro.getAltaMedica());//yo le paso el bool _altaMedica y la fx sola se encarga de ver si es true o false

    }else{//if(indiceDelDniBuscado >= 0)
      coutCentrado("El paciente no esta registrado. Agreguelo desde el menu de Pacientes.", yActual, deltaYEstatica);//fila 2+1 por q dentro no resto
   }
 }

 void HistoriaClinicaManager::adicionarAlta_Reingreso(Paciente paciente, string nombreArchivo, int &yActual, int deltaYEstatica, bool altaMedica){
  if(!altaMedica){
      if(preguntarSiNoRl("Quiere dar de alta a medica al paciente " + paciente.getNombre() + " " + paciente.getApellido() + "?", yActual)){
      HistoriaClinica nuevoRegistro; //creo objeto por omision => _varuiable =  "no ingresado"
      string codigoHC = generarCodigoHC(nombreArchivo); //genero un nuevo codigo
      nuevoRegistro.setCodigoHC(codigoHC);
      nuevoRegistro.setAltaMedica(true);
      coutCentrado(_historiaClinicaArchivo.agregarRegistro(nuevoRegistro, nombreArchivo) ? "Se ha dado de alta medica a " + paciente.getNombre() + " " + paciente.getApellido() + "." : "Error al cargar la alta medica.",  yActual, deltaYEstatica);
    }
  }else{
    if(preguntarSiNoRl("El paciente " + paciente.getNombre() + " " + paciente.getApellido() +  " esta dado de alta medica, quiere RE-INGRESARLO al sistema de historias clinicas?", yActual)){
      string codigoHC = generarCodigoHC(nombreArchivo);
      HistoriaClinica nuevoRegistro;
      nuevoRegistro.setCodigoHC(codigoHC);
      nuevoRegistro.setAltaSistema(true);     // ya tuvo una historia anterior
      coutCentrado(_historiaClinicaArchivo.agregarRegistro(nuevoRegistro, nombreArchivo) ? "El paciente fue reingresado correctamente al sistema." :  "Error al reingresar al paciente.", yActual, deltaYEstatica);
    }
  } //fin else if(altaMedica)
}


void HistoriaClinicaManager::modificarHistoriaClinica(){//se fija el getEstado
  const int cantidadFilas = 26;
  int yActual = (rlutil::trows() - cantidadFilas) / 2, deltaY = 2, deltaYEstatica = 0;

  PacienteArchivo pacienteArchivo;
  string dniDelPuntoDat = validarTodoRl("el DNI PARA BUSCAR EL ARCHIVO",  yActual, 2);//busco el dni
  string nombreDelArchivo = dniDelPuntoDat + ".dat";

  //aca no valido que esta !getEstado() en paciente .dat => por que puedo modificar sus registros del pasado
  //en cambio, cargar registro o dar de alta no puedo a un paciente !getEstado() en pacientes.dat


  int indice = pacienteArchivo.buscarPorDni(dniDelPuntoDat);
  if(indice < 0){
    coutCentrado("No existe un paciente con ese DNI.", yActual); // no exite el paciente
    return;
   }else if(!_historiaClinicaArchivo.existeArchivo(nombreDelArchivo)){// hay paciente pero no hay .dat del paciente
    coutCentrado("El paciente no tiene un archivo de HC asociado, dirijase a la opcion CARGA DE REGISTRO", yActual);
    return;
  }

  string registroAModificar = validarTodoRl("el REGISTRO A MODIFICAR (Ej. A001)",  yActual, 1, deltaY, 4, 4);//busco el registro a modificar=> viene con y = 7 y me suma 2

  int indiceAModificar = _historiaClinicaArchivo.buscarPorCodigoHC(nombreDelArchivo, registroAModificar);//busco el registro a modificar
  if(indiceAModificar >= 0){//1ro saber si el registro existe

    if (validarAlta_Medica_Sistema_Estado(nombreDelArchivo, indiceAModificar, yActual, deltaYEstatica)){//si es alta o ingreso solo muestra
      return; //si esta dado de altaMedica o fue un Re-ingreso o esta dado de bajaEstado y no quiso darle de alta me devuelve al menu anterior
    }

    HistoriaClinica hcModificable = _historiaClinicaArchivo.leer(indiceAModificar, nombreDelArchivo);// si paso el "campo minado" creo un obj para modificar
    coutCentrado("Registro encontrado....", yActual, deltaYEstatica); //y = 9
    int xTituloAside = 6;
    int xKeyValueAside = 3;
    int yAside = yActual +1; //y = 9 aca pero es enueve lo posiciona con el keyvalue y no con el titulo ya que tiene marginbottom y-3. Por eso le sumo 1
    mostrarHCPosicionada(hcModificable, xTituloAside, xKeyValueAside, yAside);

    int yFija = (rlutil::trows() - cantidadFilas) / 2; //para que esta a la misma altura del "Ingrese dni"
    int yFooter = rlutil::trows() - 4;
    int opcion;
    do{
      opcion = crearMenuInteractivo("SISTOLICA,DIASTOLICA,FC,FR,SATURACION,TEMPERATURA,DIAGNOSTICO,TRATAMIENTO,MEDICACION,BAJA / ALTA");
      if(opcion != 10) rlutil::cls();//una vez q seleccion borro
      switch(opcion){ //case 1 al 6 son signosVitales
        case 1:{
          string sistolica = validarTodoRl("la nueva presion sistolica", yFija, 1, deltaY, 2, 3);
          SignosVitales svModificable = hcModificable.getSignosVitales();//traigo el objeto entero
          svModificable.setSistolica(sistolica);//seteo un atributo del sub objeto
          hcModificable.setSignosVitales(svModificable);//le paso el sub objeto entero con un atributo modificado
        }break;

        case 2:{
          string diastolica = validarTodoRl("la nueva presion diastolica", yFija, 1, deltaY, 2, 3);
          SignosVitales svModificable = hcModificable.getSignosVitales();
          svModificable.setDiastolica(diastolica);
          hcModificable.setSignosVitales(svModificable);
        }break;

        case 3:{
          string frecuenciaCardiaca = validarTodoRl("la nueva frecuencia cardiaca", yFija, 1, deltaY, 2, 3);
          SignosVitales svModificable = hcModificable.getSignosVitales();
          svModificable.setFrecuenciaCardiaca(frecuenciaCardiaca);
          hcModificable.setSignosVitales(svModificable);
        }break;

        case 4:{
          string frecuenciaRespiratoria = validarTodoRl("la nueva frecuencia respiratoria", yFija, 1, deltaY, 1, 2);
          SignosVitales svModificable = hcModificable.getSignosVitales();
          svModificable.setFrecuenciaRespiratoria(frecuenciaRespiratoria);
          hcModificable.setSignosVitales(svModificable);
        }break;

        case 5:{
          string saturacionOxigeno = validarTodoRl("la nueva saturacion de oxigeno", yFija, 1, deltaY, 2, 3);
          SignosVitales svModificable = hcModificable.getSignosVitales();
          svModificable.setSaturacionOxigeno(saturacionOxigeno);
          hcModificable.setSignosVitales(svModificable);
        }break;

        case 6:{
          string temperatura = validarTodoRl("la nueva temperatura", yFija, 5, deltaY, 2, 2);
          SignosVitales svModificable = hcModificable.getSignosVitales();
          svModificable.setTemperatura(temperatura);
          hcModificable.setSignosVitales(svModificable);
        }break;

        case 7:{
          string dx = validarTodoRl("el nuevo diagnostico", yFija, 1, deltaY, 10, 35);
          hcModificable.setDiagnostico(dx);
        }break;

        case 8:{
          string tto = validarTodoRl("el nuevo tratamiento", yFija, 1, deltaY, 10, 35);
          hcModificable.setTratamiento(tto);
        }break;

        case 9:{
          string medicacion = validarTodoRl("la nueva medicacion", yFija, 1, deltaY, 10, 35);
          hcModificable.setMedicacion(medicacion);
        }break;

        case 10:{
          if(hcModificable.getEstadoRegistro()){//preg por las dudas... si llega esta aca es pro que esta en estado = true
            coutCentrado("El registro fue dado de baja...", yFooter, deltaYEstatica);
            hcModificable.setEstadoRegistro(false);
          }
        }break;
      }

      if(opcion >= 1 && opcion <= 10){
        if(opcion == 10){//si da alta o baja se ve en footer
          (_historiaClinicaArchivo.modificar(hcModificable, indiceAModificar, nombreDelArchivo)) ? coutCentrado("Cambios guardados correctamente....", yFooter, deltaYEstatica) : coutCentrado("Error al guardar los cambios",  yFooter, deltaYEstatica);
        }else{//si es modificacion normal se ve en subtitulo
          (_historiaClinicaArchivo.modificar(hcModificable, indiceAModificar, nombreDelArchivo)) ? coutCentrado("Cambios guardados correctamente....", yFija, deltaYEstatica) : coutCentrado("Error al guardar los cambios",  yFija, deltaYEstatica);
        }
        rlutil::cls();
        return;
      }

    }while(opcion != 11);

  }else if(indiceAModificar == -2){
    coutCentrado("El registro no existe.", yActual, deltaYEstatica);
  }else if(indiceAModificar == -1){
    coutCentrado("Error al abrir el archivo.", yActual, deltaYEstatica);
  }
}


bool HistoriaClinicaManager::validarAlta_Medica_Sistema_Estado(string nombreDelArchivo, int indice, int yActual, int deltaYEstatica){
  HistoriaClinica historiaClinicaTemporal = _historiaClinicaArchivo.leer(indice, nombreDelArchivo);
  int xTitulo = calcularCentradoX("DATOS DE LA HISTORIA CLINICA");//truquito para verlo mas simetrico = x = 46 para key value y  titulo
  int xKeyValue = xTitulo + 2;
  int yBody = yActual + 4, yFooter = yActual + 20;

  if(historiaClinicaTemporal.getAltaMedica()){
    mostrarHCPosicionada(historiaClinicaTemporal, xTitulo, xKeyValue, yBody);
    coutCentrado("No se puede MODIFICAR o dar de baja un registro dado de alta medica.", yFooter, deltaYEstatica);
    rlutil::anykey();//asi puede ver esa HC no modificable
    return true;  // Retorno inmediato
  }

  if(historiaClinicaTemporal.getAltaSistema()){
    mostrarHCPosicionada(historiaClinicaTemporal, xTitulo, xKeyValue, yBody);
    coutCentrado("No se puede MODIFICAR o dar de baja un registro que fue un INGRESO o un RE-INGRESO.", yFooter, deltaYEstatica);
    rlutil::anykey();
    return true; // Retorno inmediato
  }

  if(!historiaClinicaTemporal.getEstadoRegistro()){ //significa que (!_altaMedica && !_altaSistema) => Fecha de Atencion Medica
    yBody += 2;
    yFooter = rlutil::trows() - 2;
    mostrarHCPosicionada(historiaClinicaTemporal, xTitulo, xKeyValue, yBody);
    coutCentrado("Existe el registro #" + historiaClinicaTemporal.getCodigoHC() + " pero esta dado de baja.", yActual, deltaYEstatica);
    if(preguntarSiNoRl("Quiere DARLE DE ALTA?", yActual)){ //hace q lo que viene despues este un espacio mas abajo
      historiaClinicaTemporal.setEstadoRegistro(true);
      (_historiaClinicaArchivo.modificar(historiaClinicaTemporal, indice, nombreDelArchivo)) ? coutCentrado("Registro dado de alta.", yFooter, deltaYEstatica) : coutCentrado("No se pudo dar de alta el registro.", yActual, deltaYEstatica);
    }else{
      coutCentrado("No se ha dado de alta el registro...", yFooter, deltaYEstatica);
    }

    return true; //se cual fuere sale y da true
  }

  return false; // si no es alta medica, si no es reingreso y si no esta dado de baja puede modificarlo
}


