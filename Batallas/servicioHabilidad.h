#pragma once
#include "LIstaEnlazada.h"
#include "Habilidad.h"
class servicioHabilidad {
private: 
	ListaEnlazada* Habilidades;
public:
	servicioHabilidad();
	void ingresarHabilidad(Habilidad* nuevo);
	string consultarHabilidades(Naturaleza* naturaleza);
	~servicioHabilidad();
};