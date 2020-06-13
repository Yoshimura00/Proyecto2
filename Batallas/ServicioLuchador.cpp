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
void ServicioLuchador :: consultarDatosLuchador() {
	string nombre;
	cout << "Digite el nombre de luchador a consultar !! " << endl;
	cin >> nombre;

	Luchador* consultado = ConsultarLuchador(nombre);

	if (consultado!=nullptr) {
		cout << consultado->toString();
	}
	else {
		cout << "El luchador "<<" : " << nombre <<"consultado no se ha encontrado " << endl;
	}

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
void ServicioLuchador::eliminarLuchadorpNombre() {
	string nombre = "";
	cout << "Digite el nombre del Luchador a eliminar!! " << endl;
	cin >> nombre;

	if (ConsultarLuchador(nombre)!=nullptr) {
		EliminarLuchador(nombre);
		cout << "Se ha elminado el luchador " << ":" << nombre << endl;
	}
	else {
		cout << "El luchador Ingresado no se ha encontrado!! " << endl;
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
		cout << Luchadores->toString();
		cout << " Digite el nombre del luchador deseado " << endl;
		cin >> nombre;
		Luchador* l1 = ConsultarLuchador(nombre);
		if (l1 != nullptr) {
			cout << " Agregando las habilidades del luchador:   " << l1->getNombre() << " " << endl;
			if (s1->habilidadVacia()==false) {
				cout << "Habilidades disponibles : " << endl;
				cout << s1->toString();
				cout << "A continuacion elija cuantas habilidades desea aniadir, MIN 1 , MAX 4"<<endl;
				cin >> numMax;

				if (numMax >= 1 && numMax<= 4) {


					for (int i = 1; i <= numMax;) {
						cout << "Digite el nombre de la habilidad que desee agregar al luchador " << endl;
						cin >> hab;
						h = s1->consultarHabilidad(hab);
						if (h!=nullptr) {
							list->insertarAlFinal(h);
							i++;
						}
						else {
							cout << "ERR::La habilidad buscada  NO existe!!" << endl;
						}
						l1->setHabilidades(list);
					}


				}
				else {
					cout << "ERR::Ha digitado un valor incorrecto para el numero de habilidades (MIN=1 MAX=4)" << endl;
				}
			}
			else {
				cout << "ERR::Aun no se han agragado habilidades al sistema " << endl;
			}

			}
			
		
		
		else {
			cout << "El luchador ingresado no existe!! " << endl;
		}

	}
}



ServicioLuchador::~ServicioLuchador()
{
	Luchadores->clearData();
	delete Luchadores;
}
