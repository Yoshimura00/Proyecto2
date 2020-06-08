#include "Habilidad.h"

Habilidad::Habilidad()
{
	this->nombre = "";
	this->naturaleza = nullptr;
	this->uso = true; 
}

Habilidad::Habilidad(string nombre, Naturaleza* naturaleza, int uso)
{
	this->nombre = nombre;
	this->naturaleza = naturaleza;
	this->uso = uso;
}

void Habilidad::setUso(int uso)
{
	this->uso = uso;
}

int Habilidad::getUso()
{
	return uso;
}

Naturaleza* Habilidad::getNaturaleza()
{
	return naturaleza;
}

string Habilidad::toString()
{
	stringstream s;
	s << "Datos de habilidad: " << endl;
	s << "Nombre: "<<nombre<< endl;
	s << "Rondas restantes para utilizarse: "<<uso<< endl;
	s << "Naturaleza asociada: " <<naturaleza<< endl;
	return s.str();
}

