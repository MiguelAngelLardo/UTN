#pragma once
#include "string"
#include "rlutil.h"
#include "Paciente.h" //para pacientePosicionado
#include "HistoriaClinica.h"


void dibujarTabla(int xInicial, int yInicial, int xFinal, int yFinal, int altoEncabezado);
void dibujarCuadro(int xInicial, int yInicial, int xFinal, int yFinal);
void dibujarLogo();
void mostrarReloj();
void dibujarMarcoPrincipal();


//funcionalidades
void seleccionadorDeOpcion(std::string output, int x, int y, bool seleccionado);
int crearMenuInteractivo(std::string tituloOpcionesSeparadoConComa);

//centrados perfectos
int calcularCentradoEnY(int cantidadDeFilas); //se usa en agregarRegistro
int calcularCentradoX(std::string output);
void calcularCentradoXY(int &x, int &y, std::string output, int cantidadFilas);//se usa en coutCentrado y validarTodoRls

//usado en cout normal
void coutCentrado(const std::string &mensaje, int &yActual, int deltaY = 2);

//usados en validarTodoRl
void coutPosicionadoRl(int x, int y, const std::string &texto, int fondo = ::rlutil::BLACK, int textoColor = ::rlutil::WHITE, bool conLineaDecorativa = true, char caracterLinea = char(238));
std::string cinPosicionadoRl(int x, int y, int fondo = ::rlutil::BLACK, int textoColor = ::rlutil::LIGHTGREEN);

//metodos para mostrar paciente e HC en el modificar
struct KeyValue {
  std::string clave;
  std::string valor;//titulo es clave
};
void mostrarPacientePosicionado(Paciente &pac, int xTitulo, int xKeyValue, int y);//dentro usa mostrarLlavesValoresPosicionado
void mostrarHCPosicionada(HistoriaClinica &hc, int xTitulo, int xKeyValue, int y);//dentro usa mostrarLlavesValoresPosicionado
void mostrarClavesValoresPosicionado(int xTitulo, int xKeyValue, int y, const std::string &titulo, KeyValue vDinKeyValue[], int tamKeyValue);//dentro usa coutClaveValor
void coutClaveValor(int x, int y, const std::string &key, const std::string &value, int colorBackKeyValue, int colorKey, int colorValue, int separacion = 14);//dentro usa coutPosicionadoRl




/***********************************************************/
//para mostrar los pacientes en forma de ficha y por pagina
void mostrarFichaPaciente(const Paciente& p);
void limpiarFicha(int x, int y, int alto);
void navegarPacientes(Paciente* pacientes, int cantidad);//dentro usa mostrarFicha y LimpiarFicha


//para mostrar las Historias Clinicasvoid mostrarFichaHistoriaClinica(const HistoriaClinica& hc)
void mostrarFichaHistoriaClinica(const HistoriaClinica& hc);
void navegarHistoriasClinicas(HistoriaClinica* historias, int cantidad, const std::string dniPaciente);



// mensaje de salida

void mensajeSalida();
