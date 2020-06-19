#include "Naturaleza.h"

Naturaleza::Naturaleza()
{
	this->nombre = "";
	this->tipo = "";
	this->debiles = new ListaEnlazada();
	this->resistentes = new ListaEnlazada();
	this->inmunes = new ListaEnlazada();
}



Naturaleza::Naturaleza(string nombre, string tipo)
{
	this->nombre = nombre;
	this->tipo = tipo;
	this->debiles = new ListaEnlazada();
	this->resistentes = new ListaEnlazada();
	this->inmunes = new ListaEnlazada();
}

Naturaleza::Naturaleza(istream& input)
{
	getline(input, nombre, ',');
	getline(input, nombre);
}

bool Naturaleza::adminDebiles(Naturaleza* naturaleza)
{
	if (resistentes->contiene(naturaleza) == true) 
	 { 
		return false; 
	 }
	
	if (inmunes->contiene(naturaleza) == true)
	{
		return false;
	}
	if (debiles->contiene(naturaleza) == true)
	{
		return false;
	}
	
	debiles->insertarAlFinal(naturaleza);
	return true;

}


bool Naturaleza::adminResistentes(Naturaleza* naturaleza)
{
	if (debiles->contiene(naturaleza) == true)
	{
		return false;
	}

	if (inmunes->contiene(naturaleza) == true)
	{
		return false;
	}
	if (resistentes->contiene(naturaleza) == true)
	{
		return false;
	}

	resistentes->insertarAlFinal(naturaleza);
	return true;
}

bool Naturaleza::adminInmunes(Naturaleza* naturaleza)
{
	if (resistentes->contiene(naturaleza) == true)
	{
		return false;
	}

	if (debiles->contiene(naturaleza) == true)
	{
		return false;
	}
	if (inmunes->contiene(naturaleza) == true)
	{
		return false;
	}

	inmunes->insertarAlFinal(naturaleza);
	return true;
}

bool Naturaleza::comprobarDebiles(Naturaleza* naturaleza)
{
	if (debiles->contiene(naturaleza) == true) 
	{
		return true;
	}
	return false;
}

bool Naturaleza::comprobarResistentes(Naturaleza* naturaleza)
{
	if (resistentes->contiene(naturaleza) == true)
	{
		return true;
	}
	return false;
}

bool Naturaleza::comprobarInmunes(Naturaleza* naturaleza)
{
	if (inmunes->contiene(naturaleza) == true)
	{
		return true;
	}
	return false;
}

void Naturaleza::serializar(ostream& out)
{
	out << nombre << ",";
	out << tipo;
}

string Naturaleza::getNombre()
{
	return nombre;
}

string Naturaleza::getTipo()
{
	return tipo;
}

string Naturaleza::toString()
{
	stringstream s;
	s << "Informacion de la naturaleza: " << endl;
	s << "Nombre: " << nombre << endl;
	s << "Tipo: " << tipo << endl;
    s << "La naturaleza " << nombre << " tiene las siguientes interacciones: " << endl;

		if (debiles->listaVacia() == true) { s << "No existen naturalezas debiles para esta naturaleza" << endl; }
		else {
			s << "Naturalezas debiles: " << endl;
			for (int i = 0; i < debiles->cantidad(); i++) {
				Naturaleza* actual = dynamic_cast <Naturaleza*>(debiles->consultarPorPosicion(i));
				s << actual->getNombre() << endl;
			}
			s << endl;
		}
		if (resistentes->listaVacia() == true) { s << "No existen naturalezas resistentes para esta naturaleza" << endl; }
		else {
			s << "Naturalezas resistentes: " << endl;
			for (int i = 0; i < resistentes->cantidad(); i++) {
				Naturaleza* actual2 = dynamic_cast <Naturaleza*>(resistentes->consultarPorPosicion(i));
				s << actual2->getNombre() << endl;
			}
			s << endl;
		}
		if (inmunes->listaVacia() == true) { s << "No existen naturalezas inmunes para esta naturaleza" << endl; }
		else {
			s << "Naturalezas inmunes: " << endl;
			for (int i = 0; i < inmunes->cantidad(); i++) {
				Naturaleza* actual3 = dynamic_cast <Naturaleza*>(inmunes->consultarPorPosicion(i));
				s << actual3->getNombre() << endl;
			}
		}
	return s.str();
}

