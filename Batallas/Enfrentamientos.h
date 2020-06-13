#pragma once

#include "Habilidad.h"

class Enfrentamientos {

private: 
	int rondas;
public: 
	Enfrentamientos();
	void actualizarDatos(ListaEnlazada* uno, ListaEnlazada* dos);
	void mostrarInformacion(Luchador* uno, Luchador* dos);
	Habilidad* seleccionarHabilidades(Luchador* luchador);
	void Batalla(Luchador* uno, Luchador* dos);
	
	
};
