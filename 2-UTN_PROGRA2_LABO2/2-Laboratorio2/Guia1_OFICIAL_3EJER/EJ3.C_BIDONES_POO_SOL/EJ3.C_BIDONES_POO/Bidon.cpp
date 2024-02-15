#include "Bidon.h"

std::string Bidon::getSabor() { return _sabor; }
void Bidon::setSabor(std::string sabor) { _sabor = sabor; }

float Bidon::getCapacidad() {return _capacidad;}
void Bidon::setCapaciad(float capacidad) { _capacidad = capacidad;}

Bidon::Bidon() {
	_sabor = "Sin sabor";
	_capacidad = 1.0f;
}


void Bidon::extraer(float cantidad){
	if (cantidad > 0) {
		_capacidad -= cantidad;
		if (_capacidad < 0) {
			_capacidad = 0; 
		}
	}
}
