#include "Ataque.h"

Ataque::Ataque(string nombre, Naturaleza* naturaleza, int uso, int da�o) : Habilidad (nombre, naturaleza, uso, 2)
{
	this->da�o = da�o;
}

int Ataque::random()
{ 
	int random;
	srand(time(0));
	random = rand() % 5 + 1; 
	return random;
}

void Ataque::ejecutar(Luchador* uno, Luchador* dos)
{
	if (da�o == 50) {
		if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4)) {  
			dos->setSalud(dos->getSalud() - 50);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�o == 100) {
		if ((random() == 1) || (random() == 2) || (random() == 3)) {
			dos->setSalud(dos->getSalud() - 100);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�o == 150) {
		if ((random() == 1) || (random() == 2)) {
			dos->setSalud(dos->getSalud() - 150);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�o == 200) {
		if ((random() == 1)) {
			dos->setSalud(dos->getSalud() - 200);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}





}

string Ataque::toString()
{
	stringstream s;
	s << "Habilidad de ataque" << endl;
	s << Habilidad::toString() << endl;
	return s.str();
}
