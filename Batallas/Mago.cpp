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

Mago::Mago(istream& input, servicioNaturaleza* lista) : Luchador (input, lista)
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
		cout << "HABILIDAD ESPECIAL DE MAGO ACTIVADA" << endl;
		uno->setMAGDEF(getMAGDEF() + 35);
		cout << "MAGDEF + 35%" << endl;
		system("PAUSE");



	}
	if ((Random2 == 2) || (Random2 == 3)) { //40%
		cout << "HABILIDAD ESPECIAL 2 DE MAGO ACTIVADA" << endl;
		uno->setMAGATK(getMAGATK() + 30);
		cout << "MAGATK + 30%" << endl;
		system("PAUSE");
	}
}

string Mago::toString()
{
	stringstream s;
	s << "Luchador mago" << endl;
	s << Luchador::toString() << endl;
	return s.str();
}

void Mago::serializar(ostream& out)
{
	out << "Mago" << ",";
	Luchador::serializar(out);
}
