#include <iostream>
#include <iomanip>

#include "EstudiosXHistoriaClinicaManager.h"
#include "EstudiosManager.h"
#include "Disenio.h"

using namespace std;


bool EstudiosXHistoriaClinicaManager::agregarRegistro(string dni, string idHc, string codigoEstudio, string matriculaMedico, string apellidoMedico, string nombreMedico, string resultadoEstudio) {


    EstudiosXHistoriasClinicas nuevoEstudio(dni, idHc, codigoEstudio, matriculaMedico, apellidoMedico, nombreMedico, resultadoEstudio);
    if (_estudiosXHistoriaClinica.agregarRegistro(nuevoEstudio, _estudiosXHistoriaClinica.getNombreArchivo())) {

        return true;
    } else {

        return false;
    }

}


void EstudiosXHistoriaClinicaManager::buscarEstudiosPorDni(const std::string& dniPaciente, int opcion, Fecha fechaFiltro, const std::string& codigoFiltro) {
    int cantidadRegistros = _estudiosXHistoriaClinica.contarRegistrosPorDNI(dniPaciente); //cant de reg con ese dni en estudio x HC
    int cantidadRegistrosXcodigo = _estudiosXHistoriaClinica.contarRegistrosPorDNIyCodigo(dniPaciente, codigoFiltro);
    int cantidadRegistrosXfecha = _estudiosXHistoriaClinica.contarRegistrosPorDNIyFecha(dniPaciente, fechaFiltro);

    PacienteArchivo pArchivo;
    Paciente paciente = pArchivo.buscarPacientePorDni(dniPaciente);//traigo el obj paciente del dni X
     system ("cls");
    if (cantidadRegistros == 0) {
        string mensaje = "No hay estudios registrados para el paciente con DNI: " + dniPaciente;
        int y = rlutil::trows() / 2;
        coutCentrado(mensaje,y);
        return;
    }


        EstudiosXHistoriasClinicas* vecEstudiosDNI = nullptr;
        vecEstudiosDNI = new EstudiosXHistoriasClinicas[cantidadRegistros];

        EstudiosXHistoriasClinicas* vecEstudiosCodigo = nullptr;
        vecEstudiosCodigo = new EstudiosXHistoriasClinicas[cantidadRegistros];

        EstudiosXHistoriasClinicas* vecEstudiosFecha = nullptr;
        vecEstudiosFecha = new EstudiosXHistoriasClinicas[cantidadRegistros];

    if( vecEstudiosDNI==nullptr|| vecEstudiosCodigo==nullptr || vecEstudiosFecha==nullptr) {
        cout<< "No se pudo asignar memoria" << endl;
        return;
    }
     _estudiosXHistoriaClinica.buscarRegistrosPorDNI(dniPaciente, vecEstudiosDNI, cantidadRegistros);
     int j=0;
     int h=0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if( vecEstudiosDNI[i].getCodigoEstudio() == codigoFiltro) {
            vecEstudiosCodigo[j] = vecEstudiosDNI[i];
            j++;
        }
        if( vecEstudiosDNI[i].getFechaEstudio() == fechaFiltro) {
            vecEstudiosFecha[h] = vecEstudiosDNI[i];
            h++;
        }
    }

    string encabezado = "PACIENTE: " + paciente.getNombre() + " " + paciente.getApellido() + " (DNI: " + paciente.getDni() + ")";

    EstudiosManager eManager;
    Estudios est = eManager.buscarEstudioPorCodigo(codigoFiltro);
    std::string descripcion = est.getDescripcion().empty() ? codigoFiltro : est.getDescripcion();

    switch(opcion) {
        case 1: // Todos los estudios
           mostrarEstudios(encabezado, vecEstudiosDNI, cantidadRegistros);
            break;
        case 2: // Estudios por código

            if (cantidadRegistrosXcodigo == 0) {
                string mensaje = "No hay registrados estudios del tipo: " + descripcion + " para el DNI: " + dniPaciente;
                int y = rlutil::trows() / 2;
                coutCentrado(mensaje,y);
                rlutil::cls();
                return;
            }
            mostrarEstudios(encabezado, vecEstudiosCodigo, cantidadRegistrosXcodigo);
            break;
        case 3: // Estudios por fecha
            if (cantidadRegistrosXfecha == 0) {
                string mensaje =  "No hay estudios registrados para la fecha: " + fechaFiltro.toString() + " para el DNI: " + dniPaciente;
                int y = rlutil::trows() / 2;
                coutCentrado(mensaje,y);
                rlutil::cls();
                return;

            }
            mostrarEstudios(encabezado, vecEstudiosFecha, cantidadRegistrosXfecha);
            break;
    }

    delete[] vecEstudiosDNI;
    delete[] vecEstudiosCodigo;
    delete[] vecEstudiosFecha;
}




void EstudiosXHistoriaClinicaManager::mostrarEstudios(const string& encabezado, EstudiosXHistoriasClinicas* vecEstudiosXHC, int cantidadRegistros) {
    system("cls");

    int anchoConsola = rlutil::tcols();
    int altoConsola = rlutil::trows() - 1;
    dibujarCuadro(1, 1, anchoConsola, altoConsola);

    // Fecha arriba a la derecha
    Fecha fecha;
    rlutil::locate(anchoConsola - 15, 2);
    cout << fecha.toString();

    // Mostrar encabezado personalizado (PACIENTE o HC)
    rlutil::locate(3, 2);
    rlutil::setColor(rlutil::CYAN);
    cout << encabezado;

    // Título centrado
    std::string titulo = cantidadRegistros == 1 ? "ESTUDIO ASOCIADO" : "ESTUDIOS ASOCIADOS";
    int centro = (anchoConsola - titulo.length()) / 2;
    rlutil::locate(centro, 4);
    rlutil::setColor(rlutil::WHITE);
    cout << titulo;

    // Encabezado tabla
    int yInicio = 6;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(3, yInicio);
    cout << left
         << setw(25) << "Tipo Estudio"
         << setw(12) << "Fecha"
         << setw(35) << "Resultado"
         << setw(30) << "Profesional"
         << setw(12) << "Matricula";

    // Línea divisoria
    rlutil::locate(2, yInicio + 1);
    cout << string(anchoConsola - 2, '-');
    rlutil::setColor(rlutil::WHITE);

    // Filas de estudios
    for (int i = 0; i < cantidadRegistros; i++) {
        EstudiosManager estudioManager;
        Estudios estudio = estudioManager.buscarEstudioPorCodigo(vecEstudiosXHC[i].getCodigoEstudio());
        std::string nombreCompleto = vecEstudiosXHC[i].getApellidoMedico() + " " + vecEstudiosXHC[i].getNombreMedico();

        rlutil::locate(3, yInicio + 2 + i);
        cout << left
             << setw(25) << estudio.getDescripcion()
             << setw(12) << vecEstudiosXHC[i].getFechaEstudio().toString()
             << setw(35) << vecEstudiosXHC[i].getResultadoEstudio()
             << setw(30) << nombreCompleto
             << setw(12) << vecEstudiosXHC[i].getMatriculaMedico();
    }

    // Botón [SALIR]
    int xSalir = calcularCentradoX("[ SALIR ]");
    int ySalir = 26;
    bool salir = false;
    int tecla;

    while (!salir) {
        rlutil::locate(xSalir, ySalir);
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout << "[ SALIR ]";

        tecla = rlutil::getkey();
        if (tecla == rlutil::KEY_ENTER) salir = true;

    }

   // Restaurar colores y limpiar pantalla luego de salir
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();

}


 void EstudiosXHistoriaClinicaManager::buscarEstudiosHC(const std::string& codigoHC, const std::string& dniPaciente) {
    int cantidadRegistros = _estudiosXHistoriaClinica.contarRegistrosHistoriaClinica(codigoHC, dniPaciente);
    if (cantidadRegistros == 0) {
        string mensaje = "No hay estudios registrados para la HC: " + codigoHC;
        int y = rlutil::trows() / 2;

        coutCentrado(mensaje, y);
        return;
    }

    EstudiosXHistoriasClinicas* vecEstudios = new EstudiosXHistoriasClinicas[cantidadRegistros];
    if (vecEstudios == nullptr) {
        cout << "No se pudo asignar memoria" << endl;
        return;
    }

    _estudiosXHistoriaClinica.buscarRegistrosPorHistoriaClinica(codigoHC, vecEstudios, cantidadRegistros, dniPaciente);


    std::string encabezado = "HISTORIA CLINICA: " + codigoHC;
    mostrarEstudios(encabezado, vecEstudios, cantidadRegistros);

    delete[] vecEstudios;
}

