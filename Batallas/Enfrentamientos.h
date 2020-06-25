#pragma once
#include "servicioLuchadorConPersistencia.h"
#include "Habilidad.h"

class Enfrentamientos {

private: 
	int rondas;
public: 
	Enfrentamientos();
	Luchador* seleccionarLuchadores(servicioLuchadorConPersistencia* servicio, int n);
	void actualizarDatos(ListaEnlazada* uno);
	void mostrarInformacion(Luchador* uno, Luchador* dos);
	Habilidad* seleccionarHabilidades(Luchador* luchador);
	void Batalla(Luchador* uno, Luchador* dos);
	
	
};
