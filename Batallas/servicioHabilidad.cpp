#include "servicioHabilidad.h"

servicioHabilidad::servicioHabilidad()
{
	this->Habilidades = new ListaEnlazada();
}

void servicioHabilidad::ingresarHabilidad(Habilidad* nuevo)
{
	Habilidades->insertarAlFinal(nuevo);
}

Naturaleza* servicioHabilidad::pedirNaturaleza(servicioNaturaleza* servicioN)
{
	string buscarN;
	Naturaleza* naturaleza;
	cout << "MOSTRANDO NATURALEZAS DISPONIBLES " << endl;
	cout << servicioN->naturalezasEnLIsta();
	cout << "Digite la naturaleza de la que desea ver habilidades" << endl;
	cin >> buscarN;
	naturaleza = servicioN->consultarNaturaleza(buscarN);
	return naturaleza;
}

string servicioHabilidad::consultarHabilidadesPorNaturaleza(servicioNaturaleza* servicioN, Naturaleza* naturaleza)
{	
	stringstream s;
	if (servicioN->contieneNaturaleza(naturaleza)==false) {
		s << "ERROR: la naturaleza ingresada no existe en el sistema" << endl;
		return s.str();
	}

	s << "Habilidades con esta naturaleza: " << endl;
	for (int i = 0; i < Habilidades->cantidad(); i++) {
		Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultarPorPosicion(i));
		if (actual->getNaturaleza() == naturaleza) {
			s << actual->toString() << endl;
		}
	}
	return s.str();
}

void servicioHabilidad::pedirDatos(servicioNaturaleza* servicioN)
{
	int opcion;
	string nombreHabilidad;
	string naturaleza;
	Naturaleza* naturalezaDeHabilidad;
	int daño = 0, intervalo = 0;
	bool alterado = 0;
	Habilidad* habilidad;

	if (servicioN->naturalezaVacia() == true) {
		cout << "ADVERTENCIA: se recomienda agregar naturalezas" << endl;
	  }
		cout << "Digite el tipo de habilidad que desea ingresar" << endl;
		cout << "1 = Ofensiva (necesita 1 turno de recuperacion)" << endl;
		cout << "2 = Sanadora (necesita 2 turnos de recuperacion)" << endl;
		cout << "3 = Alteradora (necesita 3 turnos de recuperacion)" << endl;
		cin >> opcion;
		cout << "Digite el nombre de la habilidad" << endl;
		cin >> nombreHabilidad;
		cout << "MOSTRANDO NATURALEZAS DISPONIBLES " << endl;
		cout << servicioN->naturalezasEnLIsta();
		cout << "Digite la naturaleza de la habilidad" << endl;
		cin >> naturaleza;
		naturalezaDeHabilidad = servicioN->consultarNaturaleza(naturaleza);
		if (naturalezaDeHabilidad == nullptr) {
			cout << "ERROR: la naturaleza ingresada no existe en el sistema" << endl;
			return;
		}
		switch (opcion) {
		case 1:
			while (daño != 50 && daño != 100 && daño != 150 && daño != 200) {
				cout << "Digite el daño del ataque" << endl;
				cout << "Digite una de las siguientes cuatro opciones: " << endl;
				cout << "(Mientras mas daño tenga, menos posibilidad tendra de acierto)" << endl;
				cout << "1 = 50" << endl;
				cout << "2 = 100" << endl;
				cout << "3 = 150" << endl;
				cout << "4 = 200" << endl;
				cin >> daño;
				if (daño == 1) { daño = 50; }
				if (daño == 2) { daño = 100; }
				if (daño == 3) { daño = 150; }
				if (daño == 4) { daño = 200; }
				if (daño != 50 && daño != 100 && daño != 150 && daño != 200) {
					cout << "ERROR: Digite un daño que este en las opciones" << endl;
				}
			}
			habilidad = new Ataque(nombreHabilidad, naturalezaDeHabilidad, 0, daño);
			ingresarHabilidad(habilidad);
			cout << "Se agrego con exito" << endl;
			break;

		case 2:
			while (intervalo != 1 && intervalo != 2 && intervalo != 3 && intervalo != 4) {
				cout << "Digite el intervalo de curacion" << endl;
				cout << "El luchador recuperara un porcentaje de salud al azar dentro de dicho intervalo" << endl;
				cout << "Digite una de las siguientes cuatro opciones: " << endl;
				cout << "(Mientras mas alto el intervalo, menos posibilidad tendra de acierto)" << endl;
				cout << " 1 = (0 - 50)" << endl;
				cout << " 2 = (50 - 100)" << endl;
				cout << " 3 = (100 - 150)" << endl;
				cout << " 4 = (150 - 200)" << endl;
				cin >> intervalo;
				if (intervalo != 1 && intervalo != 2 && intervalo != 3 && intervalo != 4) {
					cout << "ERROR: Digite un intervalo que este en las opciones" << endl;
				}
			}
			habilidad = new Curacion(nombreHabilidad, naturalezaDeHabilidad, 0, intervalo);
			ingresarHabilidad(habilidad);
			cout << "Se agrego con exito" << endl;
			break;

		case 3:
			do {
				cout << "Las habilidades de alteracion poseen menor probabilidad de ser acertadas" << endl;
				cout << "Puede alterar estadisticas del luchador elegido o el del rival" << endl;
				cout << "El limite para alterar cada estadistica es de 30%" << endl;
				cout << "Digite a quien desea aplicarle las alteraciones" << endl;
				cout << "0 = luchador del usuario" << endl;
				cout << "1 = luchador rival" << endl;
				cin >> alterado;
				if (alterado != 0 && alterado != 1) {
					cout << "ERROR: Digite un valor valido" << endl;
				}
			} while (alterado != 0 && alterado != 1);
				habilidad = new Alteracion(nombreHabilidad, naturalezaDeHabilidad, 0, alterado);
				ingresarHabilidad(habilidad);
				cout << "Se agrego con exito" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
		}
}

Habilidad* servicioHabilidad::obtenerHabilidad(int n)
{
	Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultarPorPosicion(n));
	return actual;
}
string servicioHabilidad::toString() {
	stringstream s;
	for (int i = 0; i < Habilidades->cantidad(); i++) {
		Habilidad* actual = dynamic_cast <Habilidad*>(Habilidades->consultarPorPosicion(i));
			s << actual->toString() << endl;
	}
	return s.str();
}

bool servicioHabilidad::habilidadVacia()
{
	return (Habilidades->listaVacia() == true) ? true : false;
}
//Busca una habilidad por nombre y retorna su puntero .
Habilidad* servicioHabilidad::consultarHabilidad(string nombre)
{

	for (int i = 0; i < Habilidades->cantidad(); i++)
	{
		Habilidad* actual = dynamic_cast<Habilidad*>(Habilidades->consultarPorPosicion(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}
servicioHabilidad::~servicioHabilidad()
{
	Habilidades->clearData();
	delete Habilidades;
}
