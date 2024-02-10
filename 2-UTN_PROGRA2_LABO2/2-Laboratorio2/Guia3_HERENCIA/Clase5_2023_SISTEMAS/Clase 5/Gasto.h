#pragma once
#include <string>
#include "Fecha.h"
#include "Transaccion.h"

class Gasto: public Transaccion{
private:
	int _idMetodoPago;
	std::string _establecimiento;
	
public:
	Gasto();
	Gasto(int idTransaccion, const std::string& descripcion, const Fecha& fecha, int idCategoria, int idMetodoPago, const std::string& establecimiento, float monto, bool estado);
	int getIdTransaccion() const;
	void setIdTransaccion(int idTransaccion);

	std::string getDescripcion() const;
	void setDescripcion(std::string descripcion);

	Fecha getFecha() const;
	void setFecha(const Fecha& fecha);

	int getIdCategoria() const;	
	void setIdCategoria(int idCategoria);

	int getIdMetodoPago() const;
	void setIdMetodoPago(int idMetodoPago);
	
	std::string getEstablecimiento() const;
	void setEstablecimiento(const std::string& establecimiento);

	float getMonto() const;
	void setMonto(float monto);

	bool getEstado() const;
	void setEstado(bool estado);

	std::string toString() const;
};

