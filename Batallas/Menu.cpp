#include "Menu.h"
#include "servicioNaturaleza.h"

void Menu::mostrar()
{
	cout << "Bienvenido al emulador de batallas" << endl;
	int opcion, opcion1, opcion2, opcion3, opcionGC;
	char op1='x', op2 = 'x';
	servicioNaturaleza* servivicioN = new servicioNaturaleza();
	string nombreNaturaleza, buscarN, nDebil, nResistente, nInmune;
	Naturaleza* actual;
	Naturaleza* nat;
	int opcionDeN;
	bool tipoNaturaleza;
	do {
		system("cls");
		opcion = opcionesPrincipales();
		switch (opcion) {
		case 1:
			do {
				opcion1 = adminNaturalezas();
				switch (opcion1) {
				case 1:
					while (op1 != 'n') {
						cout << "Digite el nombre de la naturaleza que desea ingresar" << endl;
						cin >> nombreNaturaleza;
						cout << "Digite el tipo de la naturaleza" << endl;
						cout << "1 = Fisica" << endl;
						cout << "0 = Magica" << endl;
						cin >> tipoNaturaleza;
						Naturaleza* naturaleza = new Naturaleza(nombreNaturaleza, tipoNaturaleza);
						servivicioN->ingresarNaturaleza(naturaleza);
						cout << "Desea agregar otra naturaleza?" << endl;
						cout << "s = Si" << endl;
						cout << "n = NO" << endl;
						cin >> op1;
					}
					break;
				case 2:
					cout << "Digite el nombre de la naturaleza que desea administrar" << endl;
					cin >> buscarN;
					actual = servivicioN->consultarNaturaleza(buscarN);
					
					while (op2 != 'n') {
						cout << "Digite la lista de naturalezas que le desea agregar" << endl;
						cout << "1 = Debiles" << endl;
						cout << "2 = Resistentes" << endl;
						cout << "3 = Inmunes" << endl;
						cin >> opcionDeN;

						switch (opcionDeN) {
						case 1:
							cout << "Digite el nombre de la naturaleza con la que" << actual->getNombre() << " sea debil" << endl;
							cin >> nDebil;
							for (int i = 0; i < servivicioN->cantidad(); i++) {
								nat = servivicioN->consultarNaturaleza(nDebil);
								if (nat->getNombre() == nDebil) {
									if (actual->adminDebiles(nat) == true) { cout << "Se inserto con exito" << endl; }
									else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }
								}
							}
							break;
						case 2:
							cout << "Digite el nombre de la naturaleza con la que" << actual->getNombre() << " sea resistente" << endl;
							cin >> nResistente;
							for (int i = 0; i < servivicioN->cantidad(); i++) {
								nat = servivicioN->consultarNaturaleza(nResistente);
								if (nat->getNombre() == nResistente) {
									if (actual->adminResistentes(nat) == true) { cout << "Se inserto con exito" << endl; }
									else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }
								}
							}
							break;
						case 3:
							cout << "Digite el nombre de la naturaleza con la que" << actual->getNombre() << " sea inmune" << endl;
							cin >> nInmune;
							for (int i = 0; i < servivicioN->cantidad(); i++) {
								nat = servivicioN->consultarNaturaleza(nInmune);
								if (nat->getNombre() == nInmune) {
									if (actual->adminInmunes(nat) == true) { cout << "Se inserto con exito" << endl; }
									else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }
								}
							}
							break;
							
						default:
							cout << "Opcion invalida" << endl;
						}
						cout << "Desea agregar mas naturalezas a las listas?" << endl;
						cout << "s = Si" << endl;
						cout << "n = NO" << endl;
						cin >> op2;
					}
					break;

				case 3:
					cout<<servivicioN->toString()<<endl;
					system("PAUSE");
					break;

				case 4:
					cout << "saliendo..." << endl;
					break;
				default:
					cout << "Opcion invalida" << endl;
                 }

			} while (opcion1!=4);
            break;

		case 2: 
			do {
				opcion2 = adminHabilidades();
				switch (opcion2) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				default:
					cout << "Opcion invalida" << endl;
				}

			} while (opcion2 != 3);
			break;

		case 3:
			do {
				opcion3 = adminLuchadores();
				switch (opcion3) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				default:
					cout << "Opcion invalida" << endl;
                }

            } while (opcion3 != 5);
			break;

		case 4:
			break;

		case 5:
			do {
				opcionGC = CargSalvDatos();
				switch (opcionGC) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				default:
					cout << "Opcion invalida" << endl;
                }

			} while (opcionGC != 3);
			break;

		case 6:
			break;
		default: 

			cout << "Opcion invalida" << endl;
		}

	} while (opcion != 6);
}

int Menu::opcionesPrincipales()
{
	int opcion;
	cout << "Digite la opcion que desea seleccionar" << endl;
	cout << "1) Administrar naturalezas " << endl;
	cout << "2) Administrar habilidades de batalla" << endl;
	cout << "3) Administrar luchadores" << endl;
	cout << "4) Emular batalla " << endl;
	cout << "5) Cargar y salvar datos" << endl;
	cout << "6) Salir" << endl;
	cin >> opcion;
	return opcion;
}

int Menu::adminNaturalezas()
{
	int opcion1;
	cout << "Digite la opcion que desea seleccionar" << endl;
	cout << "1) Ingresar Naturaleza" << endl;
	cout << "2) Administrar Interacciones" << endl;
	cout << "3) Mostrar todas las Naturalezas" << endl;
	cout << "4) Salir" << endl;
	cin >> opcion1;
	return opcion1;
}

int Menu::adminHabilidades()
{
	int opcion2;
	cout << "1) Ingresar habilidad de batalla" << endl;
	cout << "2) Mostrar todas las habilidades de cierta naturaleza" << endl;
	cout << "3) Salir" << endl;
	cin >> opcion2;
	return opcion2;
}

int Menu::adminLuchadores()
{
	int opcion3;
	cout << "1) Ingresar luchador" << endl;
	cout << "2) Administrar habilidades de batalla" << endl;
	cout << "3) Eliminar luchador" << endl;
	cout << "4) Consultar luchador" << endl;
	cout << "5) Salir" << endl;
	cin >> opcion3;
	return opcion3;
}

int Menu::CargSalvDatos()
{
	int opcionGC;
	cout << "1) Salvar datos" << endl;
	cout << "2) Cargar datos" << endl;
	cout << "3) Salir" << endl;
	cin >> opcionGC;
	return opcionGC;
}
