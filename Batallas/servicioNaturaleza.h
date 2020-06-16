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
	bool contieneNaturaleza(Naturaleza* nat);
	int cantidad();
	string toString();
	void pedirDatos();
	void administrarNaturalezas();
	~servicioNaturaleza();
	bool naturalezaVacia();
	string naturalezasEnLIsta();

};