#include "Luchadores.h"

Luchador::Luchador()
{
	this->nombre = "";
	this->naturaleza = nullptr;
	this->salud = 0;
	this->PHYATK = 0;
	this->PHYDEF = 0;
	this->MAGATK = 0;
	this->MAGDEF = 0;
	this->SPD = 0;
	this->habilidades = new ListaEnlazada();
	
}

Luchador::Luchador(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD)
{
	this->nombre = nombre;
	this->naturaleza = naturaleza;
	this->salud = salud;
	this->PHYATK = PHYATK;
	this->PHYDEF = PHYDEF;
	this->MAGATK = MAGATK;
	this->MAGDEF = MAGDEF;
	this->SPD = SPD;
	this->habilidades = new ListaEnlazada();
	
}

Luchador::Luchador(istream& input, servicioNaturaleza* lista)
{
	
	string nombreNaturaleza;
	getline(input, nombre, ',');
	getline(input, nombreNaturaleza, ',');
	if (nombreNaturaleza != "nulo" && (lista->naturalezaVacia()!=true)) {
		this->naturaleza = lista->consultarNaturaleza(nombreNaturaleza);
	}
	else {
		this->naturaleza = nullptr;
	}
	input >> salud;
	input.ignore();
	input >> PHYATK;
	input.ignore();
	input >> PHYDEF;
	input.ignore();
	input >> MAGATK;
	input.ignore();
	input >> MAGDEF;
	input.ignore();
	input >> SPD;
	input.ignore();

}

void Luchador::setSalud(int salud)
{
	this->salud = salud;
}

void Luchador::setPHYATK(int PHYATK)
{
	this->PHYATK = PHYATK;
}

void Luchador::setPHYDEF(int PHYDEF)
{
	this->PHYDEF = PHYDEF;
}

void Luchador::setMAGATK(int MAGATK)
{
	this->MAGATK = MAGATK;
}

void Luchador::setMAGDEF(int MAGDEF)
{
	this->MAGDEF = MAGDEF;
}

void Luchador::setSPD(int SPD)
{
	this->SPD = SPD;
}

string Luchador::getNombre()
{
	return nombre;
}

int Luchador::getSalud()
{
	return salud;
}

int Luchador::getPHYATK()
{
	return PHYATK;
}

int Luchador::getPHYDEF()
{
	return PHYDEF;
}

int Luchador::getMAGATK()
{
	return MAGATK;
}

int Luchador::getMAGDEF()
{
	return MAGDEF;
}

int Luchador::getSPD()
{
	return SPD;
}

Naturaleza* Luchador::getNaturaleza()
{
	return naturaleza;
}

ListaEnlazada* Luchador::getHabilidades()
{
	return habilidades;
}


string Luchador::toString()
{
	stringstream s;
	s << "Informacion del luchador: " << endl;
	s << "Nombre: " <<nombre<< endl;
	s << "Salud: " <<salud<<" %"<< endl;
	s << "Naturaleza asociada: " << naturaleza->getNombre() << endl;
	s << "PHYATK: " << PHYATK << " %" << endl;
	s << "PHYDEF: " << PHYDEF << " %" << endl;
	s << "MAGATK: " << MAGATK << " %" << endl;
	s << "MAGDEF: " << MAGDEF << " %" << endl;
	s << "SPD: " << SPD << " %" << endl;
	if (habilidades==nullptr) {
		s << "NO posee habilidades" << endl;
	}
	else {
		s << "Habilidades del luchador: " << endl;
		s << habilidades->toString() << endl;
	}
	return s.str();
}

void Luchador::setHabilidades(ListaEnlazada* lista)
{
	this->habilidades = lista;
}

 void Luchador::serializar(ostream& out) {
	 out << nombre << ",";
	 if (naturaleza != nullptr) {
		 out << naturaleza->getNombre()<<",";
	 }
	 else {
		 out << "nulo";
	 }
	 	
	 out << salud << ",";
	 out << PHYATK << ",";
	 out << PHYDEF << ",";
	 out << MAGATK << ",";
	 out << MAGDEF << ",";
	 out << SPD ;
	 //como SPD es el ultimo registro me parece que no lleva la coma al final!
	 
}