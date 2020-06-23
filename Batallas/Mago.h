#pragma once
#include "Caballero.h"
class Mago : public Luchador {
public:
	Mago(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD);
	Mago(istream& input);
	int random();
	int random2();
	void especial(Luchador* uno, Luchador* dos);
	string toString();
	virtual void serializar(ostream& out);





};