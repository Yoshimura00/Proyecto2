#pragma once
#include "ObjetoBase.h"
#include "LIstaEnlazada.h"
class Naturaleza: public ObjetoBase {
private: 
	string nombre;
	bool tipo; 
	ListaEnlazada* debiles;
	ListaEnlazada* resistentes;
	ListaEnlazada* inmunes;
public: 
	Naturaleza();
	Naturaleza(string nombre, bool tipo);
	bool adminDebiles(Naturaleza* naturaleza); 
	bool adminResistentes(Naturaleza* naturaleza);
	bool adminInmunes(Naturaleza* naturaleza);
	bool comprobarDebiles(Naturaleza* naturaleza);
	bool comprobarResistentes(Naturaleza* naturaleza);
	bool comprobarInmunes(Naturaleza* naturaleza);
	string getNombre();
	bool getTipo();
	string toString();
	

};