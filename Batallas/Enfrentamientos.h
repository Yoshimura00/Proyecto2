#pragma once

#include "Habilidad.h"

class Enfrentamientos {
public: 
	Enfrentamientos();
	Habilidad* seleccionarHabilidades(Luchador* luchador);
	void Batalla(Luchador* uno, Luchador* dos);
};
