#pragma once
#include "LIstaEnlazada.h"
#include "Naturaleza.h"
class servicioNaturaleza {
private:
	ListaEnlazada* Naturalezas;
public: 
	servicioNaturaleza();
	void ingresarNaturaleza(Naturaleza* nuevo);
	Naturaleza* consultarNaturaleza(string nombre);
	int cantidad();
	string toString();
	~servicioNaturaleza();

};