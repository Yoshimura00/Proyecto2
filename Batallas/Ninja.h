#pragma once
#include "Mago.h"
class Ninja : public Luchador {
public:
	Ninja(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD);
	int random();
	int random2();
	void especial(Luchador* uno, Luchador* dos);
	string toString();



};