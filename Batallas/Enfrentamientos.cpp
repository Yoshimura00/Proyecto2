#include "Enfrentamientos.h"



Enfrentamientos::Enfrentamientos()
{
	rondas = 1;
}

Luchador* Enfrentamientos::seleccionarLuchadores(servicioLuchadorConPersistencia* servicio, int n)
{
	Luchador* luchador;
	string nombre;
	cout << "Mostrando luchadores disponibles" << endl;
	cout << servicio->mostrarNombres(servicio->getLuchadores()) << endl;

	cout << "Seleccione el luchador a utilizar para la batalla (Jugador "<<n<<")" << endl;
	cin >> nombre;
	luchador = servicio->consultarLuchador(nombre);
	if (luchador == nullptr) {
		cout << "ERROR: el luchador seleccionado no existe" << endl;
		system("PAUSE");
	}
    
	return luchador;
}

void Enfrentamientos::actualizarDatos(ListaEnlazada* lista)
{
	rondas = rondas + 1;
	Habilidad* actual;

	for (int i = 0; i < lista->cantidad(); i++) {
		actual = dynamic_cast <Habilidad*>(lista->consultarPorPosicion(i));
		if (actual->getUso() > 0) {
			actual->setUso(actual->getUso() - 1);
		}
	}

}

void Enfrentamientos::mostrarInformacion(Luchador* uno, Luchador* dos)
{
	cout << "Ronda numero " << rondas << endl;
	cout << "Jugador 1: " << endl;
	cout << "El luchador "<<uno->getNombre() <<" tiene una salud de: "<<uno->getSalud()<< endl;
	cout << "Jugador 2: " << endl;
	cout << "El luchador " <<dos->getNombre() << " tiene una salud de: " << dos->getSalud() << endl;
	cout << endl;
}

Habilidad* Enfrentamientos::seleccionarHabilidades(Luchador* luchador)
{
	string nombre;
	int cantidad = luchador->getHabilidades()->cantidad();
	Habilidad* actual;
	Habilidad* h1 = nullptr;

	do {
		cout << "SELECCIONANDO HABLIDADES" << endl;
		cout << "Habilidades disponibles de este luchador" << endl;
		cout << luchador->getHabilidades()->toString() << endl;
		cout << "Seleccione el nombre la habilidad para utilizar" << endl;
		cout << "Si no tiene habilidades disponibles para usar, y desea pasar de turno, digite 'x'" << endl;
		cin >> nombre;
		if (nombre == "x") {
			return nullptr;
		}
		for (int i = 0; i < cantidad; i++) {
			actual = dynamic_cast <Habilidad*>  (luchador->getHabilidades()->consultarPorPosicion(i));
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
			cout << endl;
		}
	} while (h1->getUso() > 0);
}

void Enfrentamientos::Batalla(Luchador* uno, Luchador* dos)
{
	Habilidad* h1;
	Habilidad* h2;
	Habilidad* primera;
	Habilidad* segunda;
	int identificador;

	while (uno->getSalud() > 0 && dos->getSalud() > 0) {
		mostrarInformacion(uno, dos);
		cout << "JUGADOR 1" << endl;
		h1 = seleccionarHabilidades(uno);
		system("PAUSE");
		system("cls");
		cout << "JUGADOR 2" << endl;
		h2 = seleccionarHabilidades(dos);
		system("PAUSE");
		system("cls");

		uno->especial(uno, dos);
		dos->especial(dos, uno);

		if (uno->getSPD() > dos->getSPD()) {
			primera = h1;
			segunda = h2;
			identificador = 1;
			cout << "Jugador 1 ataca primero" << endl;
		}
		else {
			primera = h2;
			segunda = h1;
			identificador = 2;
			cout << "Jugador 2 ataca primero" << endl;
		}
		if (primera != nullptr) {
			primera->setUso(primera->getLimiteDeUso() + 1);
			if (primera == h1) { cout << "Turno del jugador 1" << endl; primera->ejecutar(uno, dos); }
			if (primera == h2) { cout << "Turno del jugador 2" << endl; primera->ejecutar(dos, uno); }
			system("PAUSE");
			system("cls");
		}
		else {
			cout << "El jugador "<<identificador<<" salta este turno" << endl;
			system("PAUSE");
			system("cls");
		}
		if (segunda != nullptr) {
			segunda->setUso(segunda->getLimiteDeUso() + 1);
			if (segunda == h1) { cout << "Turno del jugador 1" << endl; segunda->ejecutar(uno, dos); }
			if (segunda == h2) { cout << "Turno del jugador 2" << endl; segunda->ejecutar(dos, uno); }
			system("PAUSE");
			system("cls");
		}
		else {
			if (identificador == 1) { identificador = 2; }
			else { identificador = 1; }
			cout << "El jugador " << identificador << " salta este turno" << endl;
			system("PAUSE");
			system("cls");
		}

		actualizarDatos(uno->getHabilidades());
		actualizarDatos(dos->getHabilidades());
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
