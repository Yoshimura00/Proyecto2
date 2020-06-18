#include "Ataque.h"

Ataque::Ataque(string nombre, Naturaleza* naturaleza, int uso, int dañoBase) : Habilidad (nombre, naturaleza, uso, 1)
{
	this->dañoBase = dañoBase;
}

int Ataque::random()
{ 
	int random;
	srand(time(0));
	random = rand() % 5 + 1; 
	return random;
}

float Ataque::random2()
{
	float random;
	srand(time(0));
	random = 85 + (rand() % (100 + 1 - 85));
	return random / 100;
}

float Ataque::calcDaño(Luchador* uno, Luchador* dos)
{
	
	float r = random2();
	float dañoTotal;
	int ataque, defensa;
	if (getNaturaleza()->getTipo() == "fisica") { ataque = uno->getPHYATK(); defensa = dos->getPHYDEF(); }
	if (getNaturaleza()->getTipo() == "magica") { ataque = uno->getMAGATK(); defensa = dos->getMAGDEF(); }
	dañoTotal = dañoBase * (ataque / defensa) * r;
	return dañoTotal;
}

float Ataque::dañoFinal(Luchador* uno, Luchador* dos)
{
	float dañoFinal = calcDaño(uno, dos);
	Naturaleza* nat = getNaturaleza();

	if (dos->getNaturaleza()->comprobarDebiles(nat) == true) {
		dañoFinal = dañoFinal * 2;
		cout << "Daño aumentado por interaccion de naturalezas" << endl;
	}
	if (dos->getNaturaleza()->comprobarResistentes(nat) == true) {
		dañoFinal = dañoFinal / 2;
		cout << "Daño reducido por interaccion de naturalezas" << endl;
	}
	if (dos->getNaturaleza()->comprobarInmunes(nat) == true) {
		dañoFinal = dañoFinal = 0;
		cout << "Daño neutralizado por interaccion de naturalezas" << endl;
	}
	
      return dañoFinal;
}



void Ataque::ejecutar(Luchador* uno, Luchador* dos)
{
	int Random = random();
	float daño = dañoFinal(uno, dos);

	if (dañoBase == 50) {
		
		if ((Random == 1) || (Random == 2) || (Random == 3) || (Random == 4)) {   //80% prob
			dos->setSalud(dos->getSalud() - daño);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (dañoBase == 100) {
		if ((Random == 1) || (Random == 2) || (Random == 3)) {            //60% prob
			dos->setSalud(dos->getSalud() - daño);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (dañoBase == 150) {
		if ((Random == 1) || (Random == 2)) {                       //40% prob
			dos->setSalud(dos->getSalud() - daño);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (dañoBase == 200) {
		if ((Random == 1)) {                                //20% prob
			dos->setSalud(dos->getSalud() - daño);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}


}

string Ataque::toString()
{
	stringstream s;
	s << "Habilidad de ataque" << endl;
	s << Habilidad::toString();
	s << "Daño base de la habilidad: "<<dañoBase<< endl;
	return s.str();
}
