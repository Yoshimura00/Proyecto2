#include "servicioNaturaleza.h"


servicioNaturaleza::servicioNaturaleza()
{
	this->Naturalezas = new ListaEnlazada();
}

void servicioNaturaleza::ingresarNaturaleza(Naturaleza* nuevo)
{
	Naturalezas->insertarAlFinal(nuevo);
}

Naturaleza* servicioNaturaleza::consultarNaturaleza(string nombre)
{
	for (int i = 0; i < Naturalezas->cantidad(); i++)
	{
		Naturaleza* actual = dynamic_cast<Naturaleza*>(Naturalezas->consultar(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}
bool servicioNaturaleza::naturalezaVacia()
{
	return (Naturalezas->listaVacia() == true) ? true : false;
}

int servicioNaturaleza::cantidad()
{
	return Naturalezas->cantidad();
}

string servicioNaturaleza::toString()
{
	stringstream s;
	for (int i = 0; i < cantidad(); i++) {
		Naturaleza* actual = dynamic_cast <Naturaleza*>(Naturalezas->consultar(i));
		s<<actual->toString()<<endl;
	}
	return s.str();
}

void servicioNaturaleza::pedirDatos()
{
	string nombreNaturaleza, tipoNaturaleza;
	cout << "Digite el nombre de la naturaleza que desea ingresar" << endl;
	cin >> nombreNaturaleza;
	cout << "Digite el tipo de la naturaleza" << endl;
	cout << "1)fisica" << endl;
	cout << "2)magica" << endl;
	cin >> tipoNaturaleza;
	if (tipoNaturaleza == "1") { tipoNaturaleza = "fisica"; }
	if (tipoNaturaleza == "2") { tipoNaturaleza = "magica"; }
	Naturaleza* naturaleza = new Naturaleza(nombreNaturaleza, tipoNaturaleza);
	ingresarNaturaleza(naturaleza);
}

void servicioNaturaleza::administrarNaturalezas()
{
	string buscarN, nDebil, nResistente, nInmune;
	Naturaleza* actual;
	Naturaleza* nat;
	int opcion;
	cout << "Digite el nombre de la naturaleza que desea administrar" << endl;
	cin >> buscarN;
	if (consultarNaturaleza(buscarN) == nullptr) {
		cout << "ERROR: Debe ingresar una naturaleza que exista en el sistema" << endl;
		return;
	}
	actual = consultarNaturaleza(buscarN);


	cout << "Digite la lista de naturalezas que le desea agregar" << endl;
	cout << "1 = Debiles" << endl;
	cout << "2 = Resistentes" << endl;
	cout << "3 = Inmunes" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1:
		cout << "Digite el nombre de la naturaleza con la que " << actual->getNombre() << " sea debil" << endl;
		cin >> nDebil;
		nat = consultarNaturaleza(nDebil);
		if (nat == nullptr) {
			cout << "ERROR: Esta naturaleza no existe" << endl;
			return;
		}
		if (actual->adminDebiles(nat) == true) { cout << "Se inserto con exito" << endl; }
		else { cout << " ERROR: No se pudo insertar porque ya existe en alguna lista de esta naturaleza" << endl; }
		break;

	case 2:
		cout << "Digite el nombre de la naturaleza con la que " << actual->getNombre() << " sea resistente" << endl;
		cin >> nResistente;
		nat = consultarNaturaleza(nResistente);
		if (nat == nullptr) {
			cout << "ERROR: Esta naturaleza no existe" << endl;
			return;
		}
		if (actual->adminResistentes(nat) == true) { cout << "Se inserto con exito" << endl; }
		else { cout << " ERROR: No se pudo insertar porque ya existe en alguna lista de esta naturaleza" << endl; }
		break;

	case 3:
		cout << "Digite el nombre de la naturaleza con la que " << actual->getNombre() << " sea inmune" << endl;
		cin >> nInmune;
		nat = consultarNaturaleza(nInmune);
		if (nat == nullptr) {
			cout << "ERROR: Esta naturaleza no existe" << endl;
			return;
		}
		if (actual->adminInmunes(nat) == true) { cout << "Se inserto con exito" << endl; }
		else { cout << " ERROR: No se pudo insertar porque ya existe en alguna lista de esta naturaleza" << endl; }
		break;

	default:
		cout << "Opcion invalida" << endl;
	}
}

servicioNaturaleza::~servicioNaturaleza()
{
	Naturalezas->clearData();
	delete Naturalezas;
}
