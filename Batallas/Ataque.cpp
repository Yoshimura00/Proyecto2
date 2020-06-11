#include "Ataque.h"

Ataque::Ataque(string nombre, Naturaleza* naturaleza, int uso, int da�oBase) : Habilidad (nombre, naturaleza, uso, 2)
{
	this->da�oBase = da�oBase;
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
	//calcular aleatorio
	return 1;
}

float Ataque::calcDa�o(Luchador* uno, Luchador* dos)
{
	
	float r = random2();
	float da�oTotal;
	int ataque, defensa;
	if (getNaturaleza()->getTipo() == "fisica") { ataque = uno->getPHYATK(); defensa = dos->getPHYDEF(); }
	if (getNaturaleza()->getTipo() == "magica") { ataque = uno->getMAGATK(); defensa = dos->getMAGDEF(); }
	da�oTotal = da�oBase * (ataque / defensa) * r;
	return da�oTotal;
}

float Ataque::da�oFinal(Luchador* uno, Luchador* dos)
{
	float da�oFinal = calcDa�o(uno, dos);
	Naturaleza* nat = getNaturaleza();

	if (dos->getNaturaleza()->comprobarDebiles(nat) == true) {
		da�oFinal = da�oFinal * 2;
		cout << "Da�o aumentado por interaccion de naturalezas" << endl;
	}
	if (dos->getNaturaleza()->comprobarResistentes(nat) == true) {
		da�oFinal = da�oFinal / 2;
		cout << "Da�o reducido por interaccion de naturalezas" << endl;
	}
	if (dos->getNaturaleza()->comprobarInmunes(nat) == true) {
		da�oFinal = da�oFinal = 0;
		cout << "Da�o neutralizado por interaccion de naturalezas" << endl;
	}
	
      return da�oFinal;
}



void Ataque::ejecutar(Luchador* uno, Luchador* dos)
{
	float da�o = da�oFinal(uno, dos);

	if (da�oBase == 50) {
		
		if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4)) {  
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 100) {
		if ((random() == 1) || (random() == 2) || (random() == 3)) {
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 150) {
		if ((random() == 1) || (random() == 2)) {
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 200) {
		if ((random() == 1)) {
			dos->setSalud(dos->getSalud() - da�o);
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
