#pragma once
#include "LIstaEnlazada.h"
#include "Habilidad.h"
class servicioHabilidad {
private: 
	ListaEnlazada* Habilidades;
public:
	servicioHabilidad();
	void ingresarHabilidad(Habilidad* nuevo);
	string consultarHabilidadesPorNaturaleza(Naturaleza* naturaleza);
	Habilidad* obtenerHabilidad(int n);
	~servicioHabilidad();
};