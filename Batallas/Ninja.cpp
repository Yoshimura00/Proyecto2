#include "Ninja.h"

Ninja::Ninja(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, naturaleza, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
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


void Ninja::especial(Luchador* uno, Luchador* dos)
{
	if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4) || (random() == 5) || (random() == 6) || (random() == 7)) { //35%
		cout << "Habilidad especial de ninja" << endl;
		uno->setSPD(getSPD() + 80);  
		cout << "SPD + 80%" << endl;
	}
		if (random2() == 1) { //5%
			cout << "Habilidad especial de ninja" << endl;
			if (dos->getNaturaleza()->getTipo()==true) {
				uno->setPHYDEF(uno->getPHYDEF() + 80);
				cout << "PHYDEF + 80" << endl;
			}
			else {
				uno->setMAGDEF(uno->getMAGDEF() + 80);
				cout << "MAGDEF + 80" << endl;
			}
		}
}

string Ninja::toString()
{
	stringstream s;
	s << "Luchador Ninja" << endl;
	s << Luchador::toString() << endl;
	return s.str();
}
