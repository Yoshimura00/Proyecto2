#include "Ataque.h"

Ataque::Ataque(string nombre, Naturaleza* naturaleza, int uso, int daño) : Habilidad (nombre, naturaleza, uso, 2)
{
	this->daño = daño;
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
	if (daño == 50) {
		if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4)) {  
			dos->setSalud(dos->getSalud() - 50);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (daño == 100) {
		if ((random() == 1) || (random() == 2) || (random() == 3)) {
			dos->setSalud(dos->getSalud() - 100);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (daño == 150) {
		if ((random() == 1) || (random() == 2)) {
			dos->setSalud(dos->getSalud() - 150);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (daño == 200) {
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
