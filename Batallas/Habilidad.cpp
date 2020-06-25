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

Habilidad::Habilidad(istream& input, servicioNaturaleza* lista)
{
	string nombreNaturaleza;
	getline(input, nombre, ',');
	getline(input, nombreNaturaleza, ',');
	if (nombreNaturaleza != "nulo") {
		naturaleza = lista->consultarNaturaleza(nombreNaturaleza);
	}
	else {
		naturaleza = nullptr;
	}
	input >> uso;
	input.ignore();
	input >> limiteDeUso;
	input.ignore();
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
	s << "Rondas necesarias para que la habilidad se vuelva a habilitar: " <<limiteDeUso<< endl;
	s << "Rondas restantes para utilizarse actualmente: "<<uso<< endl;
	s << "Naturaleza asociada: " <<naturaleza->getNombre()<< endl;
	return s.str();
}

void Habilidad::serializar(ostream& out)
{
	out << nombre << ",";
	if (naturaleza != nullptr) {
		out << naturaleza->getNombre()<<",";
	}
	else {
		out << "nulo"<<",";
	}
	out << uso << ",";
	out << limiteDeUso << ",";
}