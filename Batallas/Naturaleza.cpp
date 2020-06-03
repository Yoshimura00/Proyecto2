#include "Naturaleza.h"

Naturaleza::Naturaleza()
{
	this->nombre = "";
	this->tipo = 0;
}

Naturaleza::Naturaleza(string nombre, bool tipo)
{
	this->nombre = nombre;
	this->tipo = tipo;
}

bool Naturaleza::adminDebiles(Naturaleza* naturaleza)
{
	for (int i = 0; i < resistentes->cantidad(); i++) {
		if (resistentes->consultar(i) == naturaleza) { return false; }
	}
	for (int i = 0; i < inmunes->cantidad(); i++) {
		if (inmunes->consultar(i) == naturaleza) { return false; }
	}
	debiles->insertarAlFinal(naturaleza);
	return true;

}


bool Naturaleza::adminResistentes(Naturaleza* naturaleza)
{
	for (int i = 0; i < debiles->cantidad(); i++) {
		if (debiles->consultar(i) == naturaleza) { return false; }
	}
	for (int i = 0; i < inmunes->cantidad(); i++) {
		if (inmunes->consultar(i) == naturaleza) { return false; }
	}
	resistentes->insertarAlFinal(naturaleza);
	return true;
}

bool Naturaleza::adminInmunes(Naturaleza* naturaleza)
{
	for (int i = 0; i < debiles->cantidad(); i++) {
		if (debiles->consultar(i) == naturaleza) { return false; }
	}
	for (int i = 0; i < resistentes->cantidad(); i++) {
		if (resistentes->consultar(i) == naturaleza) { return false; }
	}
	inmunes->insertarAlFinal(naturaleza);
	return true;
}

bool Naturaleza::comprobarDebiles(Naturaleza* naturaleza)
{
	for (int i = 0; i < debiles->cantidad(); i++) {
		if (debiles->consultar(i) == naturaleza) {
			return true;
		}
	}
	return false;
}

bool Naturaleza::comprobarResistentes(Naturaleza* naturaleza)
{
	for (int i = 0; i < resistentes->cantidad(); i++) {
		if (resistentes->consultar(i) == naturaleza) {
			return true;
		}
	}
	return false;
}

bool Naturaleza::comprobarInmunes(Naturaleza* naturaleza)
{
	for (int i = 0; i < inmunes->cantidad(); i++) {
		if (inmunes->consultar(i) == naturaleza) {
			return true;
		}
	}
	return false;
}

string Naturaleza::getNombre()
{
	return nombre;
}

bool Naturaleza::getTipo()
{
	return tipo;
}

string Naturaleza::toString()
{
	stringstream s; 
	s << "Informacion de la naturaleza: "<< endl;
	s << "Nombre: " <<nombre<<endl;
	s << "Tipo: " <<tipo<<endl;
	s << "La naturaleza " << nombre << "tiene las siguientes interacciones: " << endl;

	s << "Naturalezas debiles: " << endl;
	for (int i = 0; i < debiles->cantidad(); i++) {
		Naturaleza* actual = dynamic_cast <Naturaleza*>(debiles->consultar(i));
		s << actual->getNombre() << endl;
	}
    s << endl;

	s << "Naturalezas resistentes" << endl;
	for (int i = 0; i < resistentes->cantidad(); i++) {
		Naturaleza* actual2 = dynamic_cast <Naturaleza*>(resistentes->consultar(i));
		s << actual2->getNombre() << endl;
	}
	s << endl;

	s << "Naturalezas inmunes" << endl;
	for (int i = 0; i < inmunes->cantidad(); i++) {
		Naturaleza* actual3 = dynamic_cast <Naturaleza*>(inmunes->consultar(i));
		s << actual3->getNombre() << endl;
	}
	s << endl;
	return s.str();
}
