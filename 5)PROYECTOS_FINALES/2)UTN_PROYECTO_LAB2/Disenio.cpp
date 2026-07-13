#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

#include "EstudiosXHistoriaClinicaManager.h"
#include "Disenio.h"
#include "Fecha.h"

#include <thread> // Incluye la biblioteca de hilos para reproducir la musica separadamente

using namespace std;
void dibujarTabla(int xInicial, int yInicial, int xFinal, int yFinal, int altoEncabezado)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    int borderBottom = yInicial + altoEncabezado;

    for (int i = xInicial; i <= xFinal; i++)
    {
        rlutil::locate(i, yInicial);
        std::cout << char(205);
        rlutil::locate(i, borderBottom);
        std::cout << char(205);
        rlutil::locate(i, yFinal);
        std::cout << char(205);
    }


    for (int i = yInicial; i <= yFinal; i++)
    {
        rlutil::locate(xInicial, i);
        std::cout << char(186);
        rlutil::locate(xFinal, i);
        std::cout << char(186);
    }

    rlutil::locate(xInicial, yInicial);
    std::cout << char(201);
    rlutil::locate(xFinal, yInicial);
    std::cout << char(187);
    rlutil::locate(xInicial, yFinal);
    std::cout << char(200);
    rlutil::locate(xFinal, yFinal);
    std::cout << char(188);


    rlutil::locate(xInicial, borderBottom);
    std::cout << char(204);
    rlutil::locate(xFinal, borderBottom);
    std::cout << char(185);

}
void dibujarCuadro(int xInicial, int yInicial, int xFinal, int yFinal)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    for (int i = xInicial + 1; i < xFinal; i++)
    {
        rlutil::locate(i, yInicial);
        std::cout << char(205);
        rlutil::locate(i, yFinal);
        std::cout << char(205);
    }


    for (int i = yInicial + 1; i < yFinal; i++)
    {
        rlutil::locate(xInicial, i);
        std::cout << char(186);
        rlutil::locate(xFinal, i);
        std::cout << char(186);
    }


    rlutil::locate(xInicial, yInicial);
    std::cout << char(201);
    rlutil::locate(xInicial, yFinal);
    std::cout << char(200);
    rlutil::locate(xFinal, yInicial);
    std::cout << char(187);
    rlutil::locate(xFinal, yFinal);
    std::cout << char(188);
    rlutil::hidecursor(); //
}
void dibujarLogo()
{

    std::vector<std::string> logo =
    {
        " _______  _______  _______  _        _______  _______ _________ _______ ",
        "(  ___  )(  ____ \\(  ____ \\( \\      (  ____ \\(  ____ )\\__   __/(  ___  )",
        "| (   ) || (    \\/| (    \\/| (      | (    \\/| (    )|   ) (   | (   ) |",
        "| (___) || (_____ | |      | |      | (__    | (____)|   | |   | |   | |",
        "|  ___  |(_____  )| |      | |      |  __)   |  _____)   | |   | |   | |",
        "| (   ) |      ) || |      | |      | (      | (         | |   | |   | |",
        "| )   ( |/\\____) || (____/\\| (____/\\| (____/\\| )      ___) (___| (___) |",
        "|/     \\|\\_______)(_______/(_______/(_______/|/       \\_______/(_______)"
    };

    int altoLogo = logo.size();
    int anchoLogo = logo[0].length();

    int anchoConsola = rlutil::tcols();
    int altoConsola = rlutil::trows();

    int xInicial = (anchoConsola - anchoLogo) / 2;
    int yInicial = (altoConsola - altoLogo) / 2;


    rlutil::hidecursor(); //

    for (int i = 0; i < altoLogo; ++i)
    {
        rlutil::locate(xInicial, yInicial + i);
        std::cout << logo[i];
        rlutil::msleep(200);
    }
}
void dibujarMarcoPrincipal(){
   int anchoConsola = rlutil::tcols();
   int altoConsola = rlutil::trows()-1;

   dibujarCuadro(1,1, anchoConsola,altoConsola);

    Fecha fecha;
    rlutil::locate(3, altoConsola - 1);
    cout << fecha.toString();
}


void seleccionadorDeOpcion(string output, int x, int y, bool seleccionado){
  rlutil::locate(x, y);
  if(seleccionado){
    rlutil::setBackgroundColor(rlutil::BLUE);
    cout << (char)175 << " " << output << " " << (char)174;
  }else{
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout << "  " << output << "  ";
  }
}

int crearMenuInteractivo(std::string tituloOpcionesSeparadoConComa){
  int pos = 0;
  int contadorPalabras = 0;

  //si hay coma cuenta una palabra
  while(tituloOpcionesSeparadoConComa[pos] != '\0'){
    if(tituloOpcionesSeparadoConComa[pos] == ','){
      contadorPalabras++;
    }
    pos++;
  }

  //carga de V Dim
  contadorPalabras = contadorPalabras + 1;// +1 para la ultima palabra que no tiene coma al final
  string *vDinPalabras = nullptr;
  vDinPalabras = new string[contadorPalabras];
  if(vDinPalabras == nullptr){
    cout << "Error al reservar memoria dinamica" << endl;
    return -1;
  }

  //cargar palabras en el vector dinamico
  pos = 0;
  int indexVect = 0;
  string palabraActual = "";
  while(tituloOpcionesSeparadoConComa[pos] != '\0') {
    if(tituloOpcionesSeparadoConComa[pos] != ',') {
      palabraActual += tituloOpcionesSeparadoConComa[pos];
    }else{
      vDinPalabras[indexVect++] = palabraActual;
      palabraActual = "";
    }
  pos++;
  }

  vDinPalabras[indexVect] = palabraActual;// Guardar la última palabra

  //cantidad de letras de maxima palabra
  int contadorCaracteres;
  int contCaracteresMaximo = 0;
  for(int i = 0; i < contadorPalabras; i++){
    contadorCaracteres = 0; //reseteo contador de caracteres por palabra
    while(vDinPalabras[i][contadorCaracteres] != '\0'){//recorre palabra0[0] - palabra1[1] - palabra2[2]
      contadorCaracteres++;
    }

    if(contCaracteresMaximo == 0){
      contCaracteresMaximo = contadorCaracteres; //inicializo con la primera palabra
    }else if(contadorCaracteres > contCaracteresMaximo){
      contCaracteresMaximo = contadorCaracteres; //actualizo si es mayor
    }
  }

  //centramos el menu                 7/2 = 3
  contCaracteresMaximo += 4; //sumo 2 ASCII de las flechitas y 2 por los espacios
  int totalOpciones = contadorPalabras + 1;  // +1 para SALIR
  int anchoUtil = rlutil::tcols() - 6 - 4; //=> con esto quito esos dos espacio de sobra que no se por que los deja rlutil
  int x = (anchoUtil - contCaracteresMaximo) / 2 + 6;
  //int x = (rlutil::tcols() / 2) - (contCaracteresMaximo / 2); // lo quito pro que me deja 2 espacios mas a la derecha
  int y = (rlutil::trows() / 2) - (totalOpciones / 2); // Centrado verticalmente
  int yJoystick = 0;
  int opcion = -1; // Variable para almacenar la opción seleccionada


  dibujarMarcoPrincipal(); // Dibuja el marco principal antes de mostrar el menú
  do
  {
    //dibujo el menu
    for(int i = 0; i < contadorPalabras; i++){
      seleccionadorDeOpcion(vDinPalabras[i], x, y+i, yJoystick == i); //seleccionadorDeOpcion(" HC MENU ", x, y, yJoystick == 0);
    }

    seleccionadorDeOpcion("SALIR", x, y+contadorPalabras, yJoystick == contadorPalabras);

   switch(rlutil::getkey())
   {
    case 14: yJoystick = (yJoystick == 0) ? contadorPalabras  : yJoystick-1; break; //si es == 0 y apreto up
    case 15: yJoystick = (yJoystick == contadorPalabras ) ?  0 : yJoystick+1; break; //si es == 0 y apreto up
    case 1: opcion = yJoystick; break; //enter
   }
  } while (opcion == -1); // Mientras no se presione ENTER

  delete []vDinPalabras;

  rlutil::setBackgroundColor(rlutil::BLACK); //si saco esto cuando sale se vuelve azul por un momento
  return opcion+1; //retorno la opcion seleccionada +1 para que no sea 0, sino 1
}


void calcularCentradoXY(int &x, int &y, std::string output, int cantidadFilas){
  int anchoUtil = rlutil::tcols() - 6 - 4; // 120 - 6 - 4 = 110
  x = (anchoUtil - output.length()) / 2 + 6; // Centrado en área útil + margen izquierdo
  y = (rlutil::trows() - cantidadFilas) / 2;
}

int calcularCentradoEnY(int cantidadDeFilas){
  int y = (rlutil::trows() - cantidadDeFilas) / 2;
  return y;
}

int calcularCentradoX(string output){
  int anchoUtil = rlutil::tcols() - 6 - 4; // 120 - 6 - 4 = 110
  int x = (anchoUtil - output.length()) / 2 + 6; // Centrado en área útil + margen izquierdo
  return x;
}


 void coutCentrado(const string& mensaje, int &yActual, int deltaY) {
    int x = calcularCentradoX(mensaje);

    coutPosicionadoRl(x, yActual, mensaje, rlutil::BLACK, rlutil::YELLOW, false); // false sin linea decorativa
    rlutil::msleep(2500); //muesto el msj del IF por 2 segundos
    coutPosicionadoRl(x, yActual, string(mensaje.length(), ' '), rlutil::BLACK, rlutil::BLACK, false); // false sin linea decorativa.. borro el msj anterior

    yActual += deltaY;    // Actualizar Y para el próximo elemento
}

void coutPosicionadoRl(int x, int y, const std::string& texto, int fondo, int textoColor, bool conLineaDecorativa, char caracterLinea)
{
    rlutil::locate(x, y);
    rlutil::setBackgroundColor(fondo);
    rlutil::setColor(textoColor);

    cout << texto;

    if (conLineaDecorativa) {// Línea decorativa opcional
      rlutil::locate(x, y + 1);
      rlutil::setBackgroundColor(rlutil::BLACK);
      rlutil::setColor(rlutil::WHITE);
      cout << string(texto.length(), caracterLinea);
    }

    if(!conLineaDecorativa){
      rlutil::setBackgroundColor(rlutil::BLACK);
      rlutil::setColor(rlutil::WHITE);
    }
}

string cinPosicionadoRl(int x, int y, int fondo, int textoColor) {
  rlutil::locate(x, y);
  rlutil::setBackgroundColor(fondo);
  rlutil::setColor(textoColor);

  string input;
  getline(cin, input);

  // Restaurar colores por defecto
  rlutil::setBackgroundColor(rlutil::BLACK);
  rlutil::setColor(rlutil::WHITE);

  return input;
}

/*modificar pacioente y Hc*/
void mostrarPacientePosicionado(Paciente &pac, int xTitulo, int xKeyValue, int y){
  const int tamKeyValue = 14;
  KeyValue vKeyValue[tamKeyValue] = {
    {"DNI:", pac.getDni()},
    {"Nombre:", pac.getNombre()},
    {"Apellido:", pac.getApellido()},
    {"Domicilio:", pac.getDomicilio()},
    {"Email:", pac.getMail()},
    {"Telefono:", pac.getTelefono()},
    {"Obra Social:", pac.getObraSocial()},
    {"Nro Afiliado:", pac.getNumeroDeAfiliado()},
    {"Ant Fam:", pac.getAntecedenteFamiliar()},
    {"Ant Pac:", pac.getAntecedentePaciente()},
    {"Fecha Nac:", pac.getFechaNacimiento().toString()},
    {"UTI/Piso:", pac.getEsUTIStr()},
    {"Estado:", pac.getEstadoStr()},
    {"Edad:", to_string(pac.getEdad())}
  };

  mostrarClavesValoresPosicionado(xTitulo, xKeyValue, y, "DATOS DEL PACIENTE", vKeyValue, tamKeyValue);
}
void mostrarHCPosicionada(HistoriaClinica &hc, int xTitulo, int xKeyValue, int y){//la hc la desgloso en key value
  const int tamKeyValue = 15;
  KeyValue vKeyValue[tamKeyValue] = {
   {"Codigo HC:", hc.getCodigoHC()},
    {
      (!hc.getAltaMedica() && hc.getAltaSistema()) ? "Ingreso:" :
      (!hc.getAltaMedica() && !hc.getAltaSistema()) ? "Internacion:" :
      (hc.getAltaMedica() && !hc.getAltaSistema()) ? "Alta Medica:" :
      "Fecha Último Registro:",
      hc.getFecha().toString()
    },
    {"Matricula:", hc.getMatriculaProfesional()},
    {"Sistolica:", hc.getSignosVitales().getSistolica()},
    {"Diastolica:", hc.getSignosVitales().getDiastolica()},
    {"FC (lpm):", hc.getSignosVitales().getFrecuenciaCardiaca()},
    {"FR (rpm):", hc.getSignosVitales().getFrecuenciaRespiratoria()},
    {"SpO2 (%):", hc.getSignosVitales().getSaturacionOxigeno()},
    {"Temperatura:", hc.getSignosVitales().getTemperatura()},
    {"Diagnostico:", hc.getDiagnostico()},
    {"Tratamiento", hc.getTratamiento()},
    {"Medicacion:", hc.getMedicacion()},
    {"Estado Pac:", hc.getAltaMedica() ? "Alta Medica" : "En Tratamiento"},
    {"Ingreso:", hc.getAltaSistemaStr()},
    {"Registro:", hc.getEstadoRegistroStr()}
  };

  mostrarClavesValoresPosicionado(xTitulo, xKeyValue, y, "DATOS DE LA HISTORIA CLINICA", vKeyValue, tamKeyValue); //muestro llave y valor con diferetnes colores
}


void mostrarClavesValoresPosicionado(int xTitulo, int xKeyValue, int y, const string& titulo, KeyValue vDinKeyValue[], int tamKeyValue){
  int yMarginBottomTitulo = y-2; //margen inferior
  coutPosicionadoRl(xTitulo, yMarginBottomTitulo, titulo, rlutil::BLUE, rlutil::WHITE, true); //titulo posicionado hardcodeado

  for(int i = 0; i < tamKeyValue; i++){                                            //fondo          //key           //value
    coutClaveValor(xKeyValue, y, vDinKeyValue[i].clave, vDinKeyValue[i].valor, rlutil::BLACK, rlutil::GREEN, rlutil::YELLOW);//muestro cada segmento de Y
    y++;// Avanzar linea
  }
  rlutil::setBackgroundColor(rlutil::BLACK);// Restablecer colores
  rlutil::setColor(rlutil::WHITE);// Restablecer colores
}
void coutClaveValor(int x, int y, const string &key, const string &value, int colorBackKeyValue, int colorKey, int colorValue, int separacion){
  coutPosicionadoRl(x, y, key, colorBackKeyValue, colorKey, false); // Mostrar llave hardcodeada
  coutPosicionadoRl(x + separacion, y, value, colorBackKeyValue, colorValue, false);  // Mostrar valor el get
}

//listar paciente
void mostrarFichaPaciente(const Paciente &pac){
 dibujarMarcoPrincipal();
 
 string titulo = "BASE DE DATOS DE PACIENTES";
 int xCentrada = calcularCentradoX (titulo), xPrimerMitad = xCentrada - (titulo.length() /2), xSegundaMitad = xCentrada + (titulo.length() /2);   //48-13= 35
 
 int yHeader = 2, yBody = 6, yEndl = 0;
 
 const int tamKeyValue = 14;
  KeyValue vKeyValue[tamKeyValue] = {
    {"DNI:", pac.getDni()},
    {"Nombre:", pac.getNombre()},
    {"Apellido:", pac.getApellido()},
    {"Fecha Nac:", pac.getFechaNacimiento().toString()},
    {"Edad:", to_string(pac.getEdad())},
    {"Domicilio:", pac.getDomicilio()},
    {"Email:", pac.getMail()},
    {"Telefono:", pac.getTelefono()},
    {"Obra Social:", pac.getObraSocial()},
    {"Nro Afiliado:", pac.getNumeroDeAfiliado()},
    {"Ant Fam:", pac.getAntecedenteFamiliar()},
    {"Ant Pac:", pac.getAntecedentePaciente()},
    {"UTI/Piso:", pac.getEsUTIStr()},
    {"Estado:", pac.getEstadoStr()}
  };
  

  coutPosicionadoRl(xCentrada, yHeader, "BASE DE DATOS DE PACIENTES", rlutil::BLUE, rlutil::WHITE, true);
  
  for(int i = 0; i < tamKeyValue; i++){
    coutClaveValor(xCentrada, yBody+yEndl, vKeyValue[i].clave, vKeyValue[i].valor, rlutil::BLACK, rlutil::WHITE, rlutil::YELLOW, vKeyValue[i].clave.length()+1);
    yEndl++;
    if(i == 2 || i == 7 || i == 12){//significa q pase 3 renglones
      yEndl++;
    }  
  }
}
void limpiarFicha(int x, int y, int alto){
    for (int i = 0; i < alto; i++) {
      rlutil::locate(x, y+i);
      cout << string(rlutil::tcols()-4, ' ');
    }
}

void navegarPacientes(Paciente* pacientes, int cantidad) {
  int indice = 0;
  int opcion = 0; // 0 = Anterior, 1 = Siguiente, 2 = Salir
  const int TOTAL_OPCIONES = 3;
  int tecla;
  //setColor(rlutil::WHITE);
  rlutil::cls();
  do{
    //setBackgroundColor(rlutil::BLACK);
    mostrarFichaPaciente(pacientes[indice]);

    const char* opciones[] = { "[Anterior ]", "[ Siguiente ]", "[ Salir ]" };
    int y = 26;//footer
    string texto = "Paciente " + to_string(indice + 1) + " de " + to_string(cantidad);
    int xTexto = (rlutil::tcols() - texto.length()) / 2;

    int xInicio = (rlutil::tcols() - 39)/2;//13 de cada boton * 3 = 39
    rlutil::locate(xTexto, y);//voy al footer y centrado
    setColor(rlutil::WHITE);//pinto blanco
    cout << texto; //"paciente 1 de 3"

        // Limpio la línea porque si son mas de dos diggitos me queda escrito uno de mas
        cout << std::string(texto.size(), ' ');
        rlutil::locate(xTexto, y);
        rlutil::setColor(rlutil::WHITE);
        cout << texto;
          rlutil::resetColor();

    for (int i = 0; i < TOTAL_OPCIONES; i++) {
      rlutil::locate(xInicio + i * 20, y+2);//20 espacios es la separacion de cada boton
      if (i == opcion) {
        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLUE);
      }else{
        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);
      }

      cout << opciones[i];
      rlutil::resetColor();
   }


    tecla = rlutil::getkey();
    if (tecla == rlutil::KEY_RIGHT) {
        opcion = (opcion + 1) % TOTAL_OPCIONES;//0,1,2 -> 3%3 = 0(vuelve inicio)
    }else if(tecla == rlutil::KEY_LEFT){
      opcion = (opcion - 1 + TOTAL_OPCIONES) % TOTAL_OPCIONES;
    } else if (tecla == rlutil::KEY_ENTER) {
      limpiarFicha(3,2,24);

      switch (opcion){
        case 0:
          if (indice > 0) indice--;
        break;
        case 1:
          if (indice < cantidad - 1) indice++;
        break;
        case 2:
          return;
      }
    }
  }while (true);
}


//mostrar ficha de hc
void mostrarFichaHistoriaClinica(const HistoriaClinica& hc, Fecha fechaInternacionSegmentaria) {
    int x = 3;
    int y = 2;
    int espacio = 2;
    Fecha fecha;
    dibujarMarcoPrincipal();  // Reutilizá tu marco de pantalla

    rlutil::locate(x, y); setColor(rlutil::LIGHTCYAN); cout << "Codigo HC: ";  setColor(rlutil::WHITE); cout << hc.getCodigoHC();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Fecha de Internacion: ";  setColor(rlutil::WHITE); cout << fechaInternacionSegmentaria.toString();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Fecha de Registro: "; setColor(rlutil::WHITE); cout << hc.getFecha().toString();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Matricula Profesional: ";
    setColor(rlutil::WHITE); cout << hc.getMatriculaProfesional();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Diagnostico: ";
    setColor(rlutil::WHITE); cout << hc.getDiagnostico();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Tratamiento: ";
    setColor(rlutil::WHITE); cout << hc.getTratamiento();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Medicacion: ";
    setColor(rlutil::WHITE); cout << hc.getMedicacion();

    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Alta Medica: "; setColor(rlutil::WHITE); cout << (hc.getAltaMedica() && !hc.getAltaSistema() ? hc.getFecha().toString() : "-");


    // Mostrar signos vitales justo después
    rlutil::locate(x, y += espacio); setColor(rlutil::LIGHTCYAN); cout << "Signos Vitales:";
    y++;  // Espacio antes de mostrar los valores
    setColor(rlutil::WHITE);
    hc.getSignosVitales().mostrar(x + 2, y);

    rlutil::locate(x, y+1); setColor(rlutil::LIGHTCYAN); cout << "Estudios: ";
    setColor(rlutil::WHITE);
    rlutil::resetColor();


}

Fecha obtenerFechaInternacion(int indiceActual, const int *indicesInternacion, const Fecha *fechasInternacion, int totalInternaciones){
  // Caso especial: si no hay internaciones registradas
  if(totalInternaciones == 0) return Fecha();

  for(int i = 0; i < totalInternaciones; i++) {
    if(indiceActual < indicesInternacion[i + 1] || i == totalInternaciones - 1){
        return fechasInternacion[i];
    }else if(indiceActual == indicesInternacion[i + 1]){
        return fechasInternacion[i + 1];
    }
  }

  return Fecha();
}

void navegarHistoriasClinicas(HistoriaClinica* historias, int cantidad, const string dniPaciente){
  int indice = 0;
  int opcion = 0;
  const int TOTAL_OPCIONES = 3;
  int tecla;
  bool salir = false;

  /**************logica para la fechas de internacion */
  int y = 3;
  int contInternaciones = 0;
  for(int i = 0; i < cantidad; i++){
    if(!historias[i].getAltaMedica() && historias[i].getAltaSistema()){
      contInternaciones++;
    }
  }

  Fecha *vDinDeFechaIntern = nullptr;
  vDinDeFechaIntern = new Fecha[contInternaciones];
  if(vDinDeFechaIntern == nullptr){
    coutCentrado("Error de memoria.", y);
    return;
  }

  int *vDinIndicesParaFechasIntern = nullptr;
  vDinIndicesParaFechasIntern = new int[contInternaciones];
  if(vDinIndicesParaFechasIntern == nullptr){
    coutCentrado("Error de memoria.", y);
    return;
  }

  int index = 0;
  for(int i = 0; i < cantidad; i++){
    if(!historias[i].getAltaMedica() && historias[i].getAltaSistema()){
      vDinIndicesParaFechasIntern[index] = i;
      vDinDeFechaIntern[index] = historias[i].getFecha();
      index++;
    }
  }




  while (!salir) {
    setBackgroundColor(rlutil::BLACK);

    Fecha fechaInternacionSegmentaria = obtenerFechaInternacion(indice, vDinIndicesParaFechasIntern, vDinDeFechaIntern, contInternaciones);

    mostrarFichaHistoriaClinica(historias[indice], fechaInternacionSegmentaria);



        // Dibujar el botón [ Mostrar ] arriba, al lado de "Estudios"
        int xBoton = 13, yBoton = 25;
        rlutil::locate(xBoton, yBoton);
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        cout << "[ M - Mostrar ]";
        rlutil::resetColor();

        // Mostrar menú principal (Abajo)
        const char* opciones[] = {"[ Anterior ]", "[ Siguiente ]", "[ Salir ]"};
        int y = 26;
        int xInicio = (rlutil::tcols() - 39) / 2;

            std::string texto = "Historia " + std::to_string(indice + 1) + " de " + std::to_string(cantidad);
        int xTexto = (rlutil::tcols() - 3) / 2;
        rlutil::locate(xTexto,y -1);
        rlutil::setColor(rlutil::WHITE); cout << texto;
        // Limpio la línea porque si son mas de dos diggitos me queda escrito uno de mas
        cout << std::string(texto.size(), ' ');
        rlutil::locate(xTexto, y-1);
        cout << texto;



        for (int i = 0; i < TOTAL_OPCIONES; i++) {
            rlutil::locate(xInicio + i * 20, y+1);
            if (i == opcion) {
                rlutil::setColor(rlutil::WHITE);
                rlutil::setBackgroundColor(rlutil::BLUE);
            } else {
                rlutil::setColor(rlutil::WHITE);
                rlutil::setBackgroundColor(rlutil::BLACK);
            }
            cout << opciones[i];
            rlutil::resetColor();
        }

        tecla = rlutil::getkey();
        if (tecla == rlutil::KEY_RIGHT) {
            opcion = (opcion + 1) % TOTAL_OPCIONES;
        } else if (tecla == rlutil::KEY_LEFT) {
            opcion = (opcion - 1 + TOTAL_OPCIONES) % TOTAL_OPCIONES;
        } else if (tecla == rlutil::KEY_ENTER) {
            limpiarFicha(3,2,24);
            switch (opcion) {
                case 0: if (indice > 0) indice--; break;
                case 1: if (indice < cantidad - 1) indice++; break;
                case 2: salir = true; break;
            }
        } else if (tecla == 'm' || tecla == 'M') {
            system("cls");
            dibujarMarcoPrincipal();
            EstudiosXHistoriaClinicaManager ehcm;
            ehcm.buscarEstudiosHC(historias[indice].getCodigoHC(), dniPaciente);
            system("cls");

        }
    }

    delete[] vDinDeFechaIntern;
    delete[] vDinIndicesParaFechasIntern;
}


void mensajeSalida() {

 int anchoConsola = rlutil::tcols();
   int altoConsola = rlutil::trows()-1;

   dibujarCuadro(1,1, anchoConsola,altoConsola);
  // Mensaje principal centrado
  string mensajePrincipal = "GRACIAS POR USAR ASCLEPIO...";
  int yCentrado = calcularCentradoEnY(3);
  int xCentrado = calcularCentradoX(mensajePrincipal);
  coutPosicionadoRl(xCentrado, yCentrado, mensajePrincipal, rlutil::BLACK, rlutil::CYAN, false);

  // Créditos en la parte inferior
  std::string linea1 = std::string(1, (char)169) + " TODOS LOS DERECHOS RESERVADOS - PROGRAMACION II 2025";
  string linea2 = "Miguel Angel Lardo M:29812 - Natalia Patricia Mucci M:30490 - Ella Lo Re Mansilla M:28232";
  int x1 = calcularCentradoX(linea1);
  int x2 = calcularCentradoX(linea2);

  coutPosicionadoRl(x1, 26, linea1, rlutil::BLACK, rlutil::YELLOW, false);
  coutPosicionadoRl(x2, 27, linea2, rlutil::BLACK, rlutil::YELLOW, false);

  rlutil::msleep(3000);
}

