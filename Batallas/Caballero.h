#pragma once

#include "Luchadores.h"
class Caballero: public Luchador {
public:
	Caballero(string nombre, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD);
	int random();
	int random2();
	void especial();
	string toString();



};