#include "Ninja.h"

Ninja::Ninja(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, naturaleza, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
{

}

Ninja::Ninja(istream& input) : Luchador (input) 
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
		cout << "HABILIDAD ESPECIAL DE NINJA ACTIVADA" << endl;
		uno->setSPD(getSPD() + 80);  
		cout << "SPD + 80%" << endl;
		system("PAUSE");
	}
		if (Random2 == 8) { //5%
			cout << "HABILIDAD ESPECIAL 2 DE NINJA ACTIVADA" << endl;
			if (dos->getNaturaleza()->getTipo()=="fisica") {
				uno->setPHYDEF(uno->getPHYDEF() + 80);
				cout << "PHYDEF + 80" << endl;
				system("PAUSE");
			}
			if(dos->getNaturaleza()->getTipo() == "magica") {
				uno->setMAGDEF(uno->getMAGDEF() + 80);
				cout << "MAGDEF + 80" << endl;
				system("PAUSE");
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

void Ninja::serializar(ostream& out)
{
	out << "Ninja" << ",";
	Luchador::serializar(out);
}
