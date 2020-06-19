#include "Ataque.h"

Ataque::Ataque(string nombre, Naturaleza* naturaleza, int uso, int da�oBase) : Habilidad (nombre, naturaleza, uso, 1)
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
	float random;
	srand(time(0));
	random = 85 + (rand() % (100 + 1 - 85));
	return random / 100;
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
		system("PAUSE");
	}
	if (dos->getNaturaleza()->comprobarResistentes(nat) == true) {
		da�oFinal = da�oFinal / 2;
		cout << "Da�o reducido por interaccion de naturalezas" << endl;
		system("PAUSE");
	}
	if (dos->getNaturaleza()->comprobarInmunes(nat) == true) {
		da�oFinal = da�oFinal = 0;
		cout << "Da�o neutralizado por interaccion de naturalezas" << endl;
		system("PAUSE");
	}
	
      return da�oFinal;
}



void Ataque::ejecutar(Luchador* uno, Luchador* dos)
{
	int Random = random();
	float da�o = da�oFinal(uno, dos);

	if (da�oBase == 50) {
		
		if ((Random == 1) || (Random == 2) || (Random == 3) || (Random == 4)) {   //80% prob
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
			cout << "Salud del oponente - :" << da�o << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 100) {
		if ((Random == 1) || (Random == 2) || (Random == 3)) {            //60% prob
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
			cout << "Salud del oponente - :" << da�o << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 150) {
		if ((Random == 1) || (Random == 2)) {                       //40% prob
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
			cout << "Salud del oponente - :" << da�o << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}
	if (da�oBase == 200) {
		if ((Random == 1)) {                                //20% prob
			dos->setSalud(dos->getSalud() - da�o);
			cout << "Ataque ejecutado" << endl;
			cout << "Salud del oponente - :" << da�o << endl;
		}
		else { cout << "El ataque ha fallado" << endl; }
	}


}

string Ataque::toString()
{
	stringstream s;
	s << "Habilidad de ataque" << endl;
	s << Habilidad::toString();
	s << "Da�o base de la habilidad: "<<da�oBase<< endl;
	return s.str();
}
