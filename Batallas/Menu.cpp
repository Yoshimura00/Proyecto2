#include "Menu.h"
servicioNaturaleza* s1 = new servicioNaturaleza;
void Menu::mostrar()
{
	cout << "Bienvenido al emulador de batallas" << endl;
	int opcion, opcion1, opcion2, opcion3, opcionGC;
	do {
		system("cls");
		opcion = opcionesPrincipales();//Muestra las opc disponibles del menu principal y las guarda
		switch (opcion) {
		case 1:
			do {
				opcion1 = adminNaturalezas();
				switch (opcion1) {
				case 1:
					s1->pedirDatos();
					break;
				case 2:
					break;
				case 3:
					s1->mostrarNaturalezas();
					break;
				case 4:
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
