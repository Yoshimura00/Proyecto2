#include "Alterar.h"

Alteracion::Alteracion(string nombre, int uso, bool elegido) : Habilidad(nombre, uso)
{
	this->elegido = elegido;
}

int Alteracion::random()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1; //40%
	return random;
}

void Alteracion::ejecutar(Luchador* uno, Luchador* dos)
{ 
	Luchador* luchador;
	int alt1, alt2, alt3, alt4, alt5;
	if ((random() == 1) || (random() == 2)) {
		if (elegido == true) { luchador = uno; }
		else { luchador = dos; }

		cout << "Habilidad de alteracion activada" << endl;
		cout << "Digite la alteracion de las estadisticas" << endl;
		cout << "Puede sumar o restar puntos" << endl;
		cout << "PHYATK: " << endl;
		cin >> alt1;
		cout << "PHYDEF: " << endl;
		cin >> alt2;
		cout << "MAGATK: " << endl;
		cin >> alt3;
		cout << "MAGDEF: " << endl;
		cin >> alt4;
		cout << "SPD: " << endl;
		cin >> alt5;
		luchador->setPHYATK(luchador->getPHYATK() + alt1);
		luchador->setPHYDEF(luchador->getPHYDEF() + alt2);
		luchador->setMAGATK(luchador->getMAGATK() + alt3);
		luchador->setMAGDEF(luchador->getMAGDEF() + alt4);
		luchador->setSPD(luchador->getSPD() + alt5);
	}
	else { cout << "La alteracion ha fallado" << endl; }
}
