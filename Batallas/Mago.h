#pragma once
#include "Caballero.h"
class Mago:public Luchador {
public:
	Mago(string nombre, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD);
	int random();
	int random2();
	void especial();
	string toString();





};