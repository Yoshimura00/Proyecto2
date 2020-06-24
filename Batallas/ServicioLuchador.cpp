#include "ServicioLuchador.h"
#include "servicioNaturaleza.h"
#include "servicioHabilidad.h"
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


Luchador* ServicioLuchador::consultarLuchador(string nombre)
{
	
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultarPorPosicion(i));
		if (actual->getNombre() == nombre)
		{
			return actual;
		}
	}
	return nullptr;
}
bool ServicioLuchador::contieneLuchador(Luchador* luchador)
{
	if (Luchadores->contiene(luchador)) {
		return true;
	}
	else {
		return false;
	}
}
int ServicioLuchador::cantidad()
{
	return Luchadores->cantidad();
}
void ServicioLuchador :: consultarDatosLuchador() {
	cout << "Luchadores disponibles: " << endl;
	cout << mostrarNombres(Luchadores) << endl;
	string nombre;
	cout << "Digite el nombre de luchador a consultar " << endl;
	cin >> nombre;

	Luchador* consultado = consultarLuchador(nombre);

	if (consultado!=nullptr) {
		cout << consultado->toString();
	}
	else {
		cout << "El luchador "<<" : " << nombre <<"consultado no se ha encontrado !!" << endl;
	}

}
void ServicioLuchador::pedirDatos(servicioNaturaleza* s1)
{
	string nombre;
	Naturaleza* nat;
	string naturaleza;
	int salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD, opc=0;
	cout << "Ingresar un nuevo luchador !!" << endl;

	if (s1->naturalezaVacia() == true) { cout << "ADVERTENCIA: se recomiendan agregar naturalezas " << endl; }
		cout << "Nombre: " << endl;
		cin >> nombre;
		if (contieneLuchador(consultarLuchador(nombre))) {
			cout << "Ya existe un luchador con ese nombre, digite otro" << endl;
			return;
		}
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
		cout << s1->naturalezasEnLIsta();
		cout << "A continuacion digite el nombre de la naturaleza de escogencia " << endl;
		cin >> naturaleza;
		nat = s1->consultarNaturaleza(naturaleza);
		if (nat == nullptr) {
			cout << "ERROR: la naturaleza no existe en el sistema" << endl;
			return;
		}
		while (opc != 1 && opc != 2 && opc != 3) {
			cout << "A continuacion digite el numero correspodiente al tipo de luchador deseado " << endl;
			cout << "1 = Mago " << endl;
			cout << "2 = Ninja " << endl;
			cout << "3 = Caballero " << endl;
			cin >> opc;
			if (opc != 1 && opc != 2 && opc != 3) {
				cout << "Opcion invalida, digite una de las mostradas" << endl;
			}
		}
		Luchador* l1;
		switch (opc) {
		case 1:
			l1 = new Mago(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			cout << "Se agrego con exito" << endl;
			break;
		case 2:
			l1 = new Ninja(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			cout << "Se agrego con exito" << endl;
			break;
		case 3:
			l1 = new Caballero(nombre, nat, salud, PHYATK, PHYDEF, MAGATK, MAGDEF, SPD);
			ingresarLuchador(l1);
			cout << "Se agrego con exito" << endl;
			break;
		default:
			cout << "ERROR: la opcion es invalida " << endl;
		}
		
	}



bool ServicioLuchador::EliminarLuchador(string nombre)
{
	for (int i = 0; i < Luchadores->cantidad(); i++)
	{
		Luchador* actual = dynamic_cast<Luchador*>(Luchadores->consultarPorPosicion(i));
		if (actual->getNombre() == nombre)
		{
			Luchadores->eliminarDato(i);
			return true;
		}
	}
	return false;
}
void ServicioLuchador::eliminarLuchadorpNombre() {
	string nombre = "";
	cout << "Mostrando luchadores: "<< endl;
	cout << mostrarNombres(Luchadores) << endl;
	cout << "Digite el nombre del Luchador a eliminar" << endl;
	cin >> nombre;

	if (consultarLuchador(nombre)!=nullptr) {
		EliminarLuchador(nombre);
		cout << "Se ha eliminado el luchador " << ":" << nombre << endl;
	}
	else {
		cout << "ERROR: El luchador ingresado no se ha encontrado!! " << endl;
	}
}
void ServicioLuchador::administrarHabilidades(servicioHabilidad* s1)
{
	string nombre = "";
	string hab = "";
	int numMax = 0;
	Habilidad* h = nullptr;
	ListaEnlazada* list = new ListaEnlazada;
	if (Luchadores->listaVacia() == false) {
		cout << "Mostrando Luchadores disponibles" << endl;
		cout << mostrarNombres(Luchadores) << endl;
		cout << "Digite el nombre del luchador deseado " << endl;
		cin >> nombre;
		Luchador* l1 = consultarLuchador(nombre);
		if (l1 != nullptr) {
			cout << "Agregando las habilidades del luchador:   " << l1->getNombre() << " " << endl;
			if (s1->habilidadVacia()==false) {
				cout << "Habilidades disponibles : " << endl;
				cout << s1->toString();
					cout << "A continuacion elija cuantas habilidades desea aniadir, MIN 1 , MAX 4" << endl;
					cin >> numMax;

					if (numMax >= 1 && numMax <= 4) {


						for (int i = 1; i <= numMax;) {
							cout << "Digite el nombre de la habilidad que desee agregar al luchador " << endl;
							cin >> hab;
							h = s1->consultarHabilidad(hab);
							Luchador* l;
							if (h != nullptr) {
								for (i = 0; i < cantidad(); i++) {
									 Luchador * l = dynamic_cast<Luchador*>(Luchadores->consultarPorPosicion(i));
									if (l->getHabilidades()->contiene(h)==true ) {
										cout << "ERROR: no se puede agregar esta habilidad porque ya existe en la lista de algun luchador" << endl;
										return;
									}
									list->insertarAlFinal(h);
									i++;
								}
							}
							else {
								cout << "ERROR: La habilidad buscada  NO existe !" << endl;
							}
							l1->setHabilidades(list);
						}
						cout << "Se han agregado las habilidades a lista del luchador" << endl;
					}
					else {
						cout << "ERROR: Ha digitado un valor incorrecto para el numero de habilidades (MIN=1 MAX=4)" << endl;
					}
			}
			else {
				cout << "ERROR: Aun no se han agragado habilidades al sistema !" << endl;
			}

			}	
		
		else {
			cout << "ERROR: El luchador ingresado no existe! " << endl;
		}

	}
	else {cout<<"ERROR: No existen luchadores para agregarles habilidades"<<endl;}
}

string ServicioLuchador::toString()
{ 
	stringstream s;
	for (int i = 0; i < Luchadores->cantidad(); i++) {
		Luchador* actual = dynamic_cast <Luchador*>(Luchadores->consultarPorPosicion(i));
		s << actual->toString() << endl;
	}
	return s.str();
}

string ServicioLuchador::mostrarNombres(ListaEnlazada* lista)
{
	stringstream s;
	for (int i = 0; i < lista->cantidad(); i++) {
		Luchador* actual = dynamic_cast <Luchador*>(lista->consultarPorPosicion(i));
		s << actual->getNombre() << endl;
	}
	return s.str();
}

ListaEnlazada* ServicioLuchador::getLuchadores()
{
	return Luchadores;
}



ServicioLuchador::~ServicioLuchador()
{
	Luchadores->clearData();
	delete Luchadores;
}
