#include "Mago.h"

Mago::Mago(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, naturaleza, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
{
}

int Mago::random()
{
	int random;
	srand(time(0));
	random = rand() % 2 + 1;
	return random;
}

int Mago::random2()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1;
	return random;
}

void Mago::especial(Luchador* uno, Luchador* dos)
{
	if (random() == 1) { //50%
		cout << "Habilidad especial de mago" << endl;
		uno->setMAGDEF(getMAGDEF() + 35);
		cout << "MAGDEF + 35%" << endl;


	}
	if ((random2() == 1) || (random2() == 2)) { //40%
		cout << "Habilidad especial de mago" << endl;
		uno->setMAGATK(getMAGATK() + 30);
		cout << "MAGATK + 30%" << endl;
	}
}

string Mago::toString()
{
	stringstream s;
	s << "Luchador mago" << endl;
	s << Luchador::toString() << endl;
	return s.str();
}
