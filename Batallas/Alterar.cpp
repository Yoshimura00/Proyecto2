#include "Alterar.h"

Alteracion::Alteracion(string nombre, Naturaleza* naturaleza, int uso, bool elegido) : Habilidad(nombre, naturaleza, uso)
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
	int operacion;
	int alteracion;
	Luchador* luchador;
	
	if ((random() == 1) || (random() == 2)) {
		if (elegido = true) { luchador = uno; }
		else { luchador = dos; }

		cout << "Habilidad de alteracion activada" << endl;
		cout << "Puede sumar o restar puntos" << endl;
		cout << " seleccione" << endl;
		cout << " 1 = sumar" << endl;
		cout << " 2 = restar" << endl;
		cout << "Digite la alteracion de las estadisticas" << endl;
		cout << "el valor alterador no puede ser mayor a 30" << endl;
		if (operacion = 1) {
			do {
				cout << "PHYATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
	        luchador->setPHYATK(luchador->getPHYATK() + alteracion);
			
			do {
				cout << "PHYDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYDEF(luchador->getPHYDEF() + alteracion);

			do {
				cout << "MAGATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGATK(luchador->getMAGATK() + alteracion);

			do{
				cout << "MAGDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGDEF(luchador->getMAGDEF() + alteracion);

			do{
				cout << "SPD: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setSPD(luchador->getSPD() + alteracion);

		}

		if (operacion == 2) {
			do {
				cout << "PHYATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYATK(luchador->getPHYATK() - alteracion);

			do {
				cout << "PHYDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setPHYDEF(luchador->getPHYDEF() - alteracion);

			do {
				cout << "MAGATK: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGATK(luchador->getMAGATK() - alteracion);

			do {
				cout << "MAGDEF: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setMAGDEF(luchador->getMAGDEF() - alteracion);

			do {
				cout << "SPD: " << endl;
				cin >> alteracion;
				if (alteracion > 30) { cout << "La alteracion no puede ser mayor a 30" << endl; }
			} while (alteracion > 30);
			luchador->setSPD(luchador->getSPD() - alteracion);


		}
	}


	else { cout << "La alteracion ha fallado" << endl; }
}

string Alteracion::toString()
{
	stringstream s;
	s << "Habilidad de alteracion" << endl;
	s << Habilidad::toString() << endl;
	return s.str();
}
