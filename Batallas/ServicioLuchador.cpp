#include "ServicioLuchador.h"
#include "servicioNaturaleza.h"
#include "Mago.h"
#include "Ninja.h"
#include "Caballero.h"
ServicioLuchador::ServicioLuchador()
{
	this->Luchadores = new ListaEnlazada();
}

void ServicioLuchador::ingresarLuchador(Luchador* nuevo)
{
	Luchadores->insertarAlFinal(nuevo);
}


Luchador* ServicioLuchador::ConsultarLuchador(string nombre)
{
	
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultar(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}

void ServicioLuchador::pedirDatos(servicioNaturaleza* s1)
{

	string nombre;
	Naturaleza* nat;
	string naturaleza;
	int salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD, opc;
	cout << "Ingresar un nuevo luchador !!" << endl;

	if (s1->naturalezaVacia() == false) {
		cout << "Nombre: " << endl;
		cin >> nombre;
		cout << "Introduzca las estadisticas de su luchador" << endl;

		cout << "SALUD" << endl;
		cin >> salud;

		cout << "PHYATK" << endl;
		cin >> PHYATK;

		cout << "PHYDEF" << endl;
		cin >> PHYDEF;

		cout << "MAGATK" << endl;
		cin >> MAGATK;

		cout << "MAGDEF" << endl;
		cin >> MAGDEF;

		cout << "SPD" << endl;
		cin >> SPD;
		cout << "MOSTRANDO NATURALEZAS DISPONIBLES " << endl;
		cout << s1->toString();
		cout << "A continuacion digite el nombre de la naturaleza de escogencia " << endl;
		cin >> naturaleza;
		nat = s1->consultarNaturaleza(naturaleza);
		cout << "A continuacion digite el numero desaedo para el tipo de luchador desado " << endl;
		cout << "1- Mago " << endl;
		cout << "2- Ninja " << endl;
		cout << "3- Caballero " << endl;
		cout << "Digite su opcion y presione enter " << endl;
		cin >> opc;
		Luchador* l1;
		switch (opc) {
		case 1:
			l1 = new Mago(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			break;
		case 2:
			 l1 = new Ninja(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			break;
		case 3:
			l1 = new Caballero(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			break;
		default:
			cout << "ERR: Datos erroneos No se creo el luchador " << endl;

		}


	}
	else {

		cout << "ERR: Datos erroneos No Existen naturalezas registradas!!! " << endl;
	}

}


bool ServicioLuchador::EliminarLuchador(string nombre)
{
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultar(i));
		if (actual->getNombre() == nombre)
		{
			Luchadores->eliminarNodo(i);
			return true;
		}
	}
	return false;
}

ServicioLuchador::~ServicioLuchador()
{
	Luchadores->clearData();
	delete Luchadores;
}
