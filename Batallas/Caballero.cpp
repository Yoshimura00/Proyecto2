#include "Caballero.h"

Caballero::Caballero(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD, ListaEnlazada* habilidades) : Luchador(nombre, naturaleza, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD, habilidades)
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

void Caballero::especial(Luchador* uno, Luchador* dos)
{
	if (random() == 1) { //50%
		cout << "Habilidad especial de caballero" << endl;
		uno->setPHYDEF(getPHYDEF()+35);
		cout << "PHYDEF + 35%" << endl;


	}
	if ((random2() == 1) || (random2() == 2)) { //40%
		cout << "Habilidad especial de caballero" << endl;
		uno->setPHYATK(getPHYATK() + 30);
		cout << "PHYATK + 30%" << endl;
	}
}

string Caballero::toString()
{
	stringstream s;
	s << "Luchador caballero" << endl;
	s << Luchador::toString()<<endl;
	return s.str();
}
