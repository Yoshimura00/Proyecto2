#include "Ninja.h"

Ninja::Ninja(string nombre, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
{

}

int Ninja::random()
{
	int random;
	srand(time(0));
	random = rand() % 20 + 1;
	return random;
}

int Ninja::random2()
{
	int random;
	srand(time(0));
	random = rand() % 20 + 1;
	return random;
}


void Ninja::especial()
{
	if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4) || (random() == 5) || (random() == 6) || (random() == 7)) {
		cout << "Habilidad especial de ninja" << endl;
		setSPD(getSPD() + 80);
		cout << "SPD + 80%" << endl;
	}
		if (random2() == 1) {
		}
}

string Ninja::toString()
{
	stringstream s;
	s << "luchador Ninja" << endl;
	s << Luchador::toString() << endl;
	return s.str();
}
