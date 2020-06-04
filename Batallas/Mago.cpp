#include "Mago.h"
//prueba de cambio en el proyecto

Mago::Mago(string nombre, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
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

void Mago::especial()
{
	if (random() == 1) {
		cout << "Habilidad especial de mago" << endl;
		setMAGDEF(getMAGDEF() + 35);
		cout << "MAGDEF + 35%" << endl;


	}
	if ((random2() == 1) || (random2() == 2)) {
		cout << "Habilidad especial de mago" << endl;
		setMAGATK(getMAGATK() + 30);
		cout << "MAGATK + 30%" << endl;
	}
}

string Mago::toString()
{
	stringstream s;
	s << "luchador caballero" << endl;
	s << Luchador::toString() << endl;
	return s.str();
}
