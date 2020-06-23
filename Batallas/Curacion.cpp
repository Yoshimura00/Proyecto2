#include "Curacion.h"

Curacion::Curacion(string nombre, Naturaleza* naturaleza, int uso, int intervalo) : Habilidad(nombre, naturaleza, uso, 2)
{
	this->intervalo = intervalo;
}

Curacion::Curacion(istream& input) : Habilidad (input)
{
	input >> intervalo;
	input.ignore();
}

int Curacion::random()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1;
	return random;
  
}

int Curacion::calcRecuperacion()
{
	int recuperacion;
	srand(time(0));
	if (intervalo == 1) { recuperacion = rand() % 50 + 1; }
	if (intervalo == 2) { recuperacion = 50 + (rand() % (100 + 1 - 50)); }
	if (intervalo == 3) { recuperacion = 100 + (rand() % (150 + 1 - 100)); }
	if (intervalo == 4) { recuperacion = 150 + (rand() % (200 + 1 - 150)); }
	return recuperacion;
}

void Curacion::ejecutar(Luchador* uno, Luchador* dos)
{
	int Random = random();
	int recuperacion = calcRecuperacion();
	

  if (intervalo == 1) {
	 if ((Random == 1) || (Random == 2) || (Random == 3) || (Random == 4)) {  //80 prob%
		 uno->setSalud(uno->getSalud() + recuperacion);
		cout << "Recuperacion ejecutada" << endl;
		cout << "+ " << recuperacion << " de salud" << endl;
	}
	else { cout << "La recuperacion ha fallado" << endl; }
  }

  if (intervalo == 2) {
	if ((Random == 1) || (Random == 2) || (Random == 3)) {      //60 prob%
		uno->setSalud(uno->getSalud() + recuperacion);
		cout << "Recuperacion ejecutada" << endl;
		cout << "+ "<<recuperacion << " de salud"<< endl;
	}
	else { cout << "La recuperacion ha fallado" << endl; }
  }

  if (intervalo == 3) {
	 if ((Random == 1) || (Random == 2)) {                     //40 prob%
		 uno->setSalud(uno->getSalud() + recuperacion);
		 cout << "Recuperacion ejecutada" << endl;
		 cout << "+ " << recuperacion << " de salud" << endl;
	 }
	 else { cout << "La recuperacion ha fallado" << endl; }
  }

  if (intervalo == 4) {
	  if (Random == 1) {                                      //20 prob%
		  uno->setSalud(uno->getSalud() + recuperacion);
		  cout << "Recuperacion ejecutada" << endl;
		  cout << "+ " << recuperacion << " de salud" << endl;
	  }
	  else { cout << "La recuperacion ha fallado" << endl; }
  }

}

string Curacion::toString()
{
	stringstream s;
	s << "Habilidad de curacion" << endl;
	s << Habilidad::toString();
	if (intervalo == 1) {
		s << "El intervalo de la habilidad es (1-50)" << endl;
	}
	if (intervalo == 2) {
		s << "El intervalo de la habilidad es (50-100)" << endl;
	}
	if (intervalo == 3) {
		s << "El intervalo de la habilidad es (100-150)" << endl;
	}
	if (intervalo == 4) {
		s << "El intervalo de la habilidad es (150-200)" << endl;
	}
	return s.str();
}

void Curacion::serializar(ostream& out)
{
	out << "Curacion" << ",";
	Habilidad::serializar(out);
	out << intervalo;
}

	
