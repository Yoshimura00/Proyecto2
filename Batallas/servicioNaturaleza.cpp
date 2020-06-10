#include "servicioNaturaleza.h"

servicioNaturaleza::servicioNaturaleza()
{
	this->Naturalezas = new ListaEnlazada();
}

void servicioNaturaleza::ingresarNaturaleza(Naturaleza* nuevo)
{
	Naturalezas->insertarAlFinal(nuevo);
}
void servicioNaturaleza::pedirDatos() {
	Naturaleza* nueva = new Naturaleza;
	string nombre, tipo;
	cout << "Ingrese a continuacion los datos de la nueva naturaleza!! " << endl;
	cout << "Nombre" << endl;
	cin >> nombre;
	cout << "Tipo" << endl;
	cin >> tipo;
	nueva->setNombre(nombre);
	nueva->setTipo(tipo);
	ingresarNaturaleza(nueva);
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
void servicioNaturaleza::mostrarNaturalezas() {
	for (int i = 0; i < Naturalezas->cantidad(); i++) {
		cout << Naturalezas->toString();
	}
}
servicioNaturaleza::~servicioNaturaleza()
{
	Naturalezas->clearData();
	delete Naturalezas;
}
