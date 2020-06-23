#include "Alterar.h"

Alteracion::Alteracion(string nombre, Naturaleza* naturaleza, int uso, bool elegido) : Habilidad(nombre, naturaleza, uso ,3)
{
	this->elegido = elegido;
}

Alteracion::Alteracion(istream& input) : Habilidad (input)
{
	input >> elegido;
	input.ignore();
}

int Alteracion::random()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1;
	return random;
}

void Alteracion::ejecutar(Luchador* uno, Luchador* dos)
{    
	int Random = random();
	int operacion=0;
	int alteracion;
	Luchador* luchador;
	
	if ((Random == 1) || (Random == 2)) {                    //40%
		if (elegido == false) { luchador = uno; }
		else { luchador = dos; }

		cout << "Habilidad de alteracion activada" << endl;
		cout << "Puede sumar o restar puntos" << endl;
		cout << " seleccione" << endl;
		cout << " 1 = sumar" << endl;
		cout << " 2 = restar" << endl;
		cout << "Digite la alteracion de las estadisticas" << endl;
		cout << "el valor alterador no puede ser mayor a 30" << endl;
		if (operacion == 1) {
			do {
				cout << "PHYATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
	        luchador->setPHYATK(luchador->getPHYATK() + alteracion);
			cout << "PHYATK + :"<<alteracion << endl;

			do {
				cout << "PHYDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYDEF(luchador->getPHYDEF() + alteracion);
			cout << "PHYDEF + :" << alteracion << endl;

			do {
				cout << "MAGATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGATK(luchador->getMAGATK() + alteracion);
			cout << "MAGATK + :" << alteracion << endl;

			do{
				cout << "MAGDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGDEF(luchador->getMAGDEF() + alteracion);
			cout << "MAGDEF + :" << alteracion << endl;

			do{
				cout << "SPD: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setSPD(luchador->getSPD() + alteracion);
			cout << "SPD + :" << alteracion << endl;

		}

		if (operacion == 2) {
			do {
				cout << "PHYATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYATK(luchador->getPHYATK() - alteracion);
			cout << "PHYATK - :" << alteracion << endl;

			do {
				cout << "PHYDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYDEF(luchador->getPHYDEF() - alteracion);
			cout << "PHYATK - :" << alteracion << endl;

			do {
				cout << "MAGATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGATK(luchador->getMAGATK() - alteracion);
			cout << "PHYATK - :" << alteracion << endl;

			do {
				cout << "MAGDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGDEF(luchador->getMAGDEF() - alteracion);
			cout << "PHYATK - :" << alteracion << endl;

			do {
				cout << "SPD: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setSPD(luchador->getSPD() - alteracion);
			cout << "PHYATK - :" << alteracion << endl;


		}
	}

	else { cout << "La alteracion ha fallado" << endl; }
}

string Alteracion::toString()
{
	stringstream s;
	s << "Habilidad de alteracion" << endl;
	s << Habilidad::toString();
	if (elegido == 1) {
		s << "El luchador a alterar es el del rival (jugador 2)" << endl;
	}
	if (elegido == 0) {
		s << "El luchador a alterar es el del usuario (jugador 1)" << endl;
	}
	return s.str();
}

void Alteracion::serializar(ostream& out)
{
	out << "Alteracion" << ",";
	Habilidad::serializar(out);
	out << elegido;
}
