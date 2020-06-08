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

servicioHabilidad::~servicioHabilidad()
{
	Habilidades->clearData();
	delete Habilidades;
}
