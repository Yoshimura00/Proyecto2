#include "Enfrentamientos.h"



Enfrentamientos::Enfrentamientos()
{
	rondas = 1;
}

void Enfrentamientos::actualizarDatos(ListaEnlazada* uno, ListaEnlazada* dos)
{
	rondas = rondas + 1;
	Habilidad* actual;

	for (int i = 0; i < uno->cantidad(); i++) {
		actual = dynamic_cast <Habilidad*>(uno->consultar(i));
		if (actual->getUso() > 0) {
			actual->setUso(actual->getUso() - 1);
		}
	}

}

void Enfrentamientos::mostrarInformacion(Luchador* uno, Luchador* dos)
{
	cout << "Ronda numero " << rondas << endl;
	cout << "Jugador 1: " << endl;
	cout << "El luchador "<<uno->getNombre() <<"tiene una salud de: "<<uno->getSalud()<< endl;
	cout << "Jugador 2: " << endl;
	cout << "El luchador " <<dos->getNombre() << "tiene una salud de: " << dos->getSalud() << endl;

}

Habilidad* Enfrentamientos::seleccionarHabilidades(Luchador* luchador)
{
	string nombre;
	int cantidad = luchador->getHabilidades()->cantidad();
	Habilidad* actual;
	Habilidad* h1 = nullptr;

	do {
		cout << "Habilidades disponibles de este luchador" << endl;
		cout << luchador->getHabilidades()->toString() << endl;
		cout << "Seleccione el nombre la habilidad para utilizar" << endl;
		cout << "Si no tiene habilidades disponibles para usar, y desea pasar de turno, digite 'x'" << endl;
		cin >> nombre;
		if (nombre == "x") {
			return nullptr;
		}
		for (int i = 0; i < cantidad; i++) {
			actual = dynamic_cast <Habilidad*>  (luchador->getHabilidades()->consultar(i));
			if (actual->getNombre() == nombre) {
				h1 = actual;
			}
		}
		if (h1->getUso() == 0) {
			cout << "Habilidad lista para usarse" << endl;
			return h1;
		}
		if (h1->getUso() > 0) {
			cout << "La habilidad necesita mas rondas de recuperacion" << endl;
			cout << "Utilice otra o si no tiene pase de turno" << endl;
		}
	} while (h1->getUso() > 0);
}

void Enfrentamientos::Batalla(Luchador* uno, Luchador* dos)
{
	Habilidad* h1;
	Habilidad* h2;
	Habilidad* primera;
	Habilidad* segunda;

	while (uno->getSalud() > 0 || dos->getSalud() > 0) {
		mostrarInformacion(uno, dos);
		h1 = seleccionarHabilidades(uno);
		system("cls");
		h2 = seleccionarHabilidades(dos);
		system("cls");

		if (uno->getSPD() > dos->getSPD()) {
			primera = h1;
			segunda = h2;
		}
		else {
			primera = h2;
			segunda = h1;
		}
		if (primera != nullptr) {
			primera->setUso(primera->getLimiteDeUso() + 1);
			if (primera = h1) { primera->ejecutar(uno, dos); }
			if (primera = h2) { primera->ejecutar(dos, uno); }
			system("cls");
		}
		else {
			cout << "El luchador " << primera->getNombre() << "salta este turno" << endl;
		}
		if (segunda != nullptr) {
			segunda->setUso(segunda->getLimiteDeUso() + 1);
			if (segunda = h1) { segunda->ejecutar(uno, dos); }
			if (segunda = h2) { segunda->ejecutar(dos, uno); }
			system("cls");
		}
		else {
			cout << "El luchador " << segunda->getNombre() << "salta este turno" << endl;
		}

		actualizarDatos(uno->getHabilidades(), dos->getHabilidades());
	}
	if (uno->getSalud() <= 0) {
		cout << uno->getNombre()<<" ha perdido toda su salud" << endl;
		cout<<"El ganador es"<<dos->getNombre()<<endl;
		cout << " ¡Felicidades, jugador dos!" << endl;
	}
	if (dos->getSalud() <= 0) {
		cout << dos->getNombre() << " ha perdido toda su salud" << endl;
		cout << "El ganador es" << uno->getNombre() << endl;
		cout << " ¡Felicidades, jugador uno!" << endl;
	}
}
