#pragma once
#include <string>
#include "Fecha.h"

class Pelicula
{
private:
	std::string _titulo;
	Fecha _fechaPublicacion;
	int _puntuacion;

public:
	Pelicula();
	Pelicula(std::string titulo, Fecha fechaPublicacion, int puntuacion);

	std::string getTitulo();
	int getPuntuacion();
	Fecha& getFechaPublicacion();

	void setTitulo(std::string titulo);
	void setFechaPublicacion(Fecha fechaPublicacion);
	void setPuntuacion(int puntuacion);

};

