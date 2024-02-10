#pragma once
#include "Transaccion.h"

class Ingreso : public Transaccion
{
public:
	Ingreso();
	Ingreso(int idTransaccion, const std::string& descripcion, const Fecha& fecha, int idCategoria, int tipo, const std::string& referencia, float monto, bool estado);
	int getTipo() const;
	void setTipo(int tipo);

	std::string getReferencia() const;
	void setReferencia(const std::string& referencia);

	std::string toString() const;

	int _tipo;
	std::string _referencia;
};

