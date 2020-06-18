#pragma once
#include "ObjetoBase.h"
#include "LIstaEnlazada.h"
class Naturaleza: public ObjetoBase {
private: 
	string nombre;
	string tipo; 
	ListaEnlazada* debiles;
	ListaEnlazada* resistentes;
	ListaEnlazada* inmunes;
public: 
	Naturaleza();
	Naturaleza(string nombre, string tipo);
	Naturaleza(istream& input);
	bool adminDebiles(Naturaleza* naturaleza); 
	bool adminResistentes(Naturaleza* naturaleza);
	bool adminInmunes(Naturaleza* naturaleza);
	bool comprobarDebiles(Naturaleza* naturaleza);
	bool comprobarResistentes(Naturaleza* naturaleza);
	bool comprobarInmunes(Naturaleza* naturaleza);
	void serializar(ostream& out);
	string getNombre();
	string getTipo();
	string toString();

};