#include "Habilidad.h"

Habilidad::Habilidad()
{
	this->nombre = "";
	this->uso = true; 
}

Habilidad::Habilidad(string nombre, bool uso)
{
	this->nombre = nombre;
	this->uso = uso;
}

void Habilidad::setUso(bool uso)
{
	this->uso = uso;
}

int Habilidad::getUso()
{
	return uso;
}
