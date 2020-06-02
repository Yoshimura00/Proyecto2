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

servicioNaturaleza::~servicioNaturaleza()
{
	Naturalezas->clearData();
	delete Naturalezas;
}
