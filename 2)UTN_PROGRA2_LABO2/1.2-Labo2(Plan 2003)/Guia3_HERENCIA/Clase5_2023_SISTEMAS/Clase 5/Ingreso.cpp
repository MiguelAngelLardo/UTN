#include "Ingreso.h"

Ingreso::Ingreso() : Transaccion(),  _tipo(0), _referencia("")
{
}

Ingreso::Ingreso(int idTransaccion, const std::string& descripcion, const Fecha& fecha, int idCategoria, int tipo, const std::string& referencia, float monto, bool estado)
	: Transaccion(idTransaccion, descripcion, fecha, idCategoria, monto, estado), 
	_tipo(tipo), //_tipo = tipo; pero aca hace mas pasos,crea variable, ejecuta el constructor vacio y desp asigna valor
	_referencia(referencia)
{
}

int Ingreso::getTipo() const
{
	return _tipo;
}

void Ingreso::setTipo(int tipo)
{
	_tipo = tipo;
}

std::string Ingreso::getReferencia() const
{
	return _referencia;
}

void Ingreso::setReferencia(const std::string& referencia)
{
	_referencia = referencia;
}

std::string Ingreso::toString() const
{
	return Transaccion::toString() + " tipo: " + std::to_string(_tipo) + " referencia: " + _referencia;
}

