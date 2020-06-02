#include "Caballero.h"

Caballero::Caballero(string nombre, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
{

}

int Caballero::random()
{
	int random;
	srand(time(0));
	random = rand() % 2 + 1;
	return random;
}

int Caballero::random2()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1;
	return random;
}

void Caballero::especial()
{
	if (random() == 1) {
		cout << "Habilidad especial de caballero" << endl;
		setPHYDEF(getPHYDEF()+35);
		cout << "PHYDEF + 35%" << endl;


	}
	if ((random2() == 1) || (random2() == 2)) {
		cout << "Habilidad especial de caballero" << endl;
		setPHYATK(getPHYATK() + 30);
		cout << "PHYATK + 30%" << endl;
	}
}

string Caballero::toString()
{
	stringstream s;
	s << "luchador caballero" << endl;
	s << Luchador::toString()<<endl;
	return s.str();
}
