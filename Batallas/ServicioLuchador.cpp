#include "ServicioLuchador.h"

ServicioLuchador::ServicioLuchador()
{
	this->Luchadores = new ListaEnlazada();
}

void ServicioLuchador::ingresarLuchador(Luchador* nuevo)
{
	Luchadores->insertarAlFinal(nuevo);
}

Luchador* ServicioLuchador::ConsultarLuchador(string nombre)
{
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultar(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}

bool ServicioLuchador::EliminarLuchador(string nombre)
{
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultar(i));
		if (actual->getNombre() == nombre)
		{
			Luchadores->eliminarNodo(i);
			return true;
		}
	}
	return false;
}

ServicioLuchador::~ServicioLuchador()
{
	Luchadores->clearData();
	delete Luchadores;
}
