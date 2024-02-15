#pragma once
#include <string>

class Bidon
{
private:
	std::string _sabor;
	float _capacidad;

public:
	std::string getSabor();
	void setSabor(std::string sabor);
	float getCapacidad();
	void setCapaciad(float capacidad);

	Bidon();

	//void llenar();
	void extraer(float cantidad);
};

