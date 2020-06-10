#pragma once
#include "LIstaEnlazada.h"
#include "Naturaleza.h"
class servicioNaturaleza {
private:
	ListaEnlazada* Naturalezas;
public: 
	servicioNaturaleza();
	void ingresarNaturaleza(Naturaleza* nuevo);
	void pedirDatos();
	Naturaleza* consultarNaturaleza(string nombre);
	void mostrarNaturalezas();
	~servicioNaturaleza();

};