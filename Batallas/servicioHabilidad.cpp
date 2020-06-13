#include "servicioHabilidad.h"

servicioHabilidad::servicioHabilidad()
{
	this->Habilidades = new ListaEnlazada();
}

void servicioHabilidad::ingresarHabilidad(Habilidad* nuevo)
{
	Habilidades->insertarAlFinal(nuevo);
}

string servicioHabilidad::consultarHabilidadesPorNaturaleza(Naturaleza* naturaleza)
{
	stringstream s;
	s << "Habilidades con esta naturaleza: " << endl;
	for (int i = 0; i < Habilidades->cantidad(); i++) {
		Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultar(i));
		if (actual->getNaturaleza() == naturaleza) {
			s << actual->toString() << endl;
		}
	}
	return s.str();
}

Habilidad* servicioHabilidad::obtenerHabilidad(int n)
{
	Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultar(n));
	return actual;
}
//Mete en el stream solo el nombre..
string servicioHabilidad::toString() {
	stringstream s;
	for (int i = 0; i < Habilidades->cantidad(); i++) {
		Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultar(i));
			s << actual->getNombre() << endl;
	}
	return s.str();
}
bool servicioHabilidad::habilidadVacia()
{
	return (Habilidades->listaVacia() == true) ? true : false;
}
//Busca una habilidad por nombre y retorna su puntero .
Habilidad* servicioHabilidad::consultarHabilidad(string nombre)
{

	for (int i = 0; i < Habilidades->cantidad(); i++)
	{
		Habilidad* actual = dynamic_cast<Habilidad*>(Habilidades->consultar(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}
servicioHabilidad::~servicioHabilidad()
{
	Habilidades->clearData();
	delete Habilidades;
}
