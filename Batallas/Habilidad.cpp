#include "Habilidad.h"

Habilidad::Habilidad()
{
	this->nombre = "";
	this->naturaleza = nullptr;
	this->uso = 0; 
}

Habilidad::Habilidad(string nombre, Naturaleza* naturaleza, int uso, int limiteDeUso)
{
	this->nombre = nombre;
	this->naturaleza = naturaleza;
	this->uso = uso;
	this->limiteDeUso = limiteDeUso;
}

void Habilidad::setUso(int uso)
{
	this->uso = uso;
}

int Habilidad::getUso()
{
	return uso;
}

int Habilidad::getLimiteDeUso()
{
	return limiteDeUso;
}

string Habilidad::getNombre()
{
	return nombre;
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
	s << "Rondas necesarias para volverse a usar" <<limiteDeUso<< endl;
	s << "Rondas restantes para utilizarse: "<<uso<< endl;
	s << "Naturaleza asociada: " <<naturaleza<< endl;
	return s.str();
}

