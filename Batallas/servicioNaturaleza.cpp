#include "servicioNaturaleza.h"


servicioNaturaleza::servicioNaturaleza()
{
	this->Naturalezas = new ListaEnlazada();
}

void servicioNaturaleza::ingresarNaturaleza(Naturaleza* nuevo)
{
	Naturalezas->insertarAlFinal(nuevo);
}

Naturaleza* servicioNaturaleza::consultarNaturaleza(string nombre)
{
	for (int i = 0; i < Naturalezas->cantidad(); i++)
	{
		Naturaleza* actual = dynamic_cast<Naturaleza*>(Naturalezas->consultar(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}
bool servicioNaturaleza::naturalezaVacia()
{
	return (Naturalezas->listaVacia() == true) ? true : false;
}

int servicioNaturaleza::cantidad()
{
	return Naturalezas->cantidad();
}

string servicioNaturaleza::toString()
{
	stringstream s;
	for (int i = 0; i < cantidad(); i++) {
		Naturaleza* actual = dynamic_cast <Naturaleza*>(Naturalezas->consultar(i));
		s<<actual->toString()<<endl;
	}
	return s.str();
}

servicioNaturaleza::~servicioNaturaleza()
{
	Naturalezas->clearData();
	delete Naturalezas;
}
