#include "Enfrentamientos.h"



Enfrentamientos::Enfrentamientos()
{
}

Habilidad* Enfrentamientos::seleccionarHabilidades(Luchador* luchador)
{
	
	string nombre;
	int cantidad = luchador->getHabilidades()->cantidad();
	Habilidad* actual;
	Habilidad* h1 = nullptr;

	do{
		cout << "Habilidades disponibles de este luchador" << endl;
		cout << luchador->getHabilidades()->toString() << endl;
		cout << "Seleccione el nombre la habilidad para utilizar" << endl;
		cout << "Si no tiene habilidades disponibles para usar, y desea pasar de turno, digite 'x'" << endl;
		cin >> nombre;
		if (nombre == "x") {
			return nullptr;
		}
		for (int i = 0; i < cantidad; i++) {
			actual = dynamic_cast <Habilidad*>  (luchador->getHabilidades()->consultar(i));
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
		}
	} while (h1->getUso() > 0);
}


void Enfrentamientos::Batalla(Luchador* uno, Luchador* dos)
{
	Habilidad* h1;
	Habilidad* h2;
	Habilidad* actual;

	h1 = seleccionarHabilidades(uno);
	h2 = seleccionarHabilidades(dos);
    
	if (uno->getSPD() > dos->getSPD()) {
		actual = h1;
	}
	else {
		actual = h2;
	}
	if (h1 != nullptr) {
		actual->ejecutar(uno, dos);
	}
	

	
}
