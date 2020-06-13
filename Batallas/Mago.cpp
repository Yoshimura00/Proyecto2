#include "Luchadores.h"
#include "Mago.h"


int Mago::random()
{
	int random;
	srand(time(0));
	random = rand() % 2 + 1;
	return random;
}

Mago::Mago(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD):Luchador( nombre,naturaleza,salud,PHYATK, PHYDEF,MAGATK,MAGDEF,SPD)
{
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
	int Random = random();
	int Random2 = random2();

	if (Random == 1) { //50%
		cout << "Habilidad especial de mago" << endl;
		uno->setMAGDEF(getMAGDEF() + 35);
		cout << "MAGDEF + 35%" << endl;


	}
	if ((Random2 == 1) || (Random2 == 2)) { //40%
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
