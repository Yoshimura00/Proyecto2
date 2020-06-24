#include "Caballero.h"

Caballero::Caballero(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD) : Luchador(nombre, naturaleza, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD)
{

}

Caballero::Caballero(istream& input, servicioNaturaleza* lista) : Luchador (input, lista)
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
	int Random = random();
	int Random2 = random2();

	if (Random == 1) { //50%
		cout << "HABILIDAD ESPECIAL DE CABALLERO ACTIVADA" << endl;
		uno->setPHYDEF(getPHYDEF()+35);
		cout << "PHYDEF + 35%" << endl;
		system("PAUSE");

	}
	if ((Random2 == 2) || (Random2 == 3)) { //40%
		cout << "HABILIDAD 2 ESPECIAL DE CABALLERO ACTIVADA" << endl;
		uno->setPHYATK(getPHYATK() + 30);
		cout << "PHYATK + 30%" << endl;
		system("PAUSE");
	}
}

string Caballero::toString()
{
	stringstream s;
	s << "Luchador caballero" << endl;
	s << Luchador::toString()<<endl;
	return s.str();
	
}

void Caballero::serializar(ostream& out)
{
	out << "Caballero" << ",";
	Luchador::serializar(out);
}
