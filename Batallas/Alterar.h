#pragma once
#include "Habilidad.h"
class Alteracion : public Habilidad {
private: 
	bool elegido; 
public: 
	Alteracion(string nombre, int uso, bool elegido);
	int random();
	void ejecutar(Luchador* uno, Luchador* dos);
};