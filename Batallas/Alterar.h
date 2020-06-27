#pragma once
#include "Habilidad.h"
class Alteracion : public Habilidad {
private: 
	bool elegido; 
public: 
	Alteracion(string nombre, Naturaleza* naturaleza, int uso, bool elegido);
	Alteracion(istream& input, servicioNaturaleza* lista);
	int random();
	void ejecutar(Luchador* uno, Luchador* dos);
	string toString();
	virtual void serializar(ostream& out);
};