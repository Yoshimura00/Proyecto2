#include "Menu.h"
#include "servicioNaturaleza.h"
#include "servicioHabilidad.h"
#include "Ataque.h"
#include "Curacion.h"
#include "Alterar.h"

void Menu::mostrar()
{
	cout << "Bienvenido al emulador de batallas" << endl;
	int uso, daño = 0, intervalo = 0;
	int opcion, opcion1, opcion2, opcion3, opcionGC;
	char op1 = 'x', op2 = 'x', op3 = 'x';
	servicioNaturaleza* servivicioN = new servicioNaturaleza();
	servicioHabilidad* servicioH = new servicioHabilidad();
	string nombreNaturaleza, buscarN, nDebil, nResistente, nInmune, naturaleza;
	string nombreHabilidad;
	Naturaleza* actual;
	Naturaleza* nat;
	Naturaleza* naturalezaDeHabilidad;
	Habilidad* habilidad;
	bool alterado;

	int opcionDeN, opcionDeH;
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
							nat = servivicioN->consultarNaturaleza(nDebil);
							if (actual->adminDebiles(nat) == true) { cout << "Se inserto con exito" << endl; }
								else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }
							break;

						case 2:
							cout << "Digite el nombre de la naturaleza con la que" << actual->getNombre() << " sea resistente" << endl;
							cin >> nResistente;
							nat = servivicioN->consultarNaturaleza(nResistente);
							if (actual->adminResistentes(nat) == true) { cout << "Se inserto con exito" << endl; }
								else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }
							break;

						case 3:
							cout << "Digite el nombre de la naturaleza con la que" << actual->getNombre() << " sea inmune" << endl;
							cin >> nInmune;
						    nat = servivicioN->consultarNaturaleza(nInmune);
							if (actual->adminInmunes(nat) == true) { cout << "Se inserto con exito" << endl; }
								else { cout << "No se pudo insertar porque ya existe en otra lista de esta naturaleza" << endl; }	
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
				while (op3 != 'n') {
			case 1:
				cout << "Digite el tipo de habilidad que desea ingresar" << endl;
				cout << "1 = Ofensiva (necesita 2 turnos de recuperacion)" << endl;
				cout << "2 = Sanadora (necesita 3 turnos de recuperacion)" << endl;
				cout << "3 = Alteradora (necesita 4 turnos de recuperacion)" << endl;
				cin >> opcionDeH;
				cout << "Digite el nombre de la habilidad" << endl;
				cin >> nombreHabilidad;
				cout << "Digite la naturaleza de la habilidad" << endl;
				cin >> naturaleza;
				naturalezaDeHabilidad = servivicioN->consultarNaturaleza(naturaleza);
				switch (opcionDeH) {
				case 1:
					while (daño != 50 && daño != 100 && daño != 150 && daño != 200) {
						cout << "Digite el daño del ataque" << endl;
						cout << "Digite una de las siguientes cuatro opciones: " << endl;
						cout << "(Mientras mas daño tenga, menos posibilidad tendra de acierto)" << endl;
						cout << "50" << endl;
						cout << "100" << endl;
						cout << "150" << endl;
						cout << "200" << endl;
						cin >> daño;
						if (daño != 50 && daño != 100 && daño != 150 && daño != 200) {
							cout << "Digite un daño que este en las opciones" << endl;
						}
					}
					habilidad = new Ataque(nombreHabilidad, naturalezaDeHabilidad, 2, daño);
					servicioH->ingresarHabilidad(habilidad);
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
							cout << "Digite un intervalo que este en las opciones" << endl;
						}
					}
					habilidad = new Curacion(nombreHabilidad, naturalezaDeHabilidad, 3, intervalo);
					servicioH->ingresarHabilidad(habilidad);
					break;

				case 3:
					cout << "Las habilidades de alteracion poseen menor probabilidad de ser acertadas" << endl;
					cout << "Puede alterar estadisticas del luchador elegido o el del rival" << endl;
					cout << "El limite para alterar cada estadistica es de 30%" << endl;
					cout << "Digite a quien desea aplicarle las alteraciones" << endl;
					cout << "0 = luchador elegido" << endl;
					cout << "1 = luchador rival" << endl;
					cin >> alterado;
					habilidad = new Alteracion(nombreHabilidad, naturalezaDeHabilidad, 4, alterado);
					servicioH->ingresarHabilidad(habilidad);
					break;
				default:
					cout << "Opcion invalida" << endl;
				}
				cout << "Desea agregar mas habilidades a las listas?" << endl;
				cout << "s = Si" << endl;
				cout << "n = NO" << endl;
				cin >> op3;
				}
					break;

				case 2:
					cout << "Digite la naturaleza de la que desea ver habilidades" << endl;
					cin >> buscarN;
					nat = servivicioN->consultarNaturaleza(buscarN);
					cout << "Las habilidades asociadas a dicha naturaleza son: " << endl;
					cout<<servicioH->consultarHabilidadesPorNaturaleza(nat)<<endl;
					system("PAUSE");
					break;
				case 3:
					cout<<"Saliendo..."<<endl;
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
