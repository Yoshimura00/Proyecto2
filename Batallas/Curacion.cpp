#include "Curacion.h"

Curacion::Curacion(string nombre, int uso, int intervalo) : Habilidad(nombre, uso)
{
	this->intervalo = intervalo;
}

int Curacion::random()
{
	int random;
	srand(time(0));
	random = rand() % 5 + 1;
	return random;
  
}

void Curacion::ejecutar(Luchador* uno, Luchador* dos)
{
	int recuperacion;
	srand(time(0));

  if (intervalo == 1) {
	 if ((random() == 1) || (random() == 2) || (random() == 3) || (random() == 4)) {
		 recuperacion = rand() % 50 + 1;
		 uno->setSalud(uno->getSalud() + recuperacion);
		cout << "Recuperacion ejecutada" << endl;
		cout << "+ " << recuperacion << "de salud" << endl;
	}
	else { cout << "La recuperacion ha fallado" << endl; }
  }

  if (intervalo == 2) {
	if ((random() == 1) || (random() == 2) || (random() == 3)) {
		recuperacion = 50 + (rand() % (100 + 1 - 50));
		uno->setSalud(uno->getSalud() + recuperacion);
		cout << "Recuperacion ejecutada" << endl;
		cout << "+ "<<recuperacion << "de salud"<< endl;
	}
	else { cout << "La recuperacion ha fallado" << endl; }
  }

  if (intervalo == 3) {
	 if ((random() == 1) || (random() == 2)) {
		 recuperacion = 100 + (rand() % (150 + 1 - 100));
		 uno->setSalud(uno->getSalud() + recuperacion);
		 cout << "Recuperacion ejecutada" << endl;
		 cout << "+ " << recuperacion << "de salud" << endl;
	 }
	 else { cout << "La recuperacion ha fallado" << endl; }
 }

  if (intervalo == 4) {
	  recuperacion = 150 + (rand() % (200 + 1 - 150));
	  uno->setSalud(uno->getSalud() + recuperacion);
	  cout << "Recuperacion ejecutada" << endl;
	  cout << "+ " << recuperacion << "de salud" << endl;
  }
  else { cout << "La recuperacion ha fallado" << endl; }
 
}

	
