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
	int Random=random();
	int Random2 = random2();

	if ((Random == 1) || (Random == 2) || (Random == 3) || (Random == 4) || (Random == 5) || (Random == 6) || (Random == 7)) { //35%
		cout << "Habilidad especial de ninja" << endl;
		uno->setSPD(getSPD() + 80);  
		cout << "SPD + 80%" << endl;
	}
		if (Random2 == 1) { //5%
			cout << "Habilidad especial de ninja" << endl;
			if (dos->getNaturaleza()->getTipo()=="fisica") {
				uno->setPHYDEF(uno->getPHYDEF() + 80);
				cout << "PHYDEF + 80" << endl;
			}
			if(dos->getNaturaleza()->getTipo() == "magica") {
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
