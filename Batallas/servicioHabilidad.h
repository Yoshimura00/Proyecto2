#pragma once
#include "servicioNaturaleza.h"
#include "Habilidad.h"
#include "Alterar.h"
#include "Ataque.h"
#include "Curacion.h"
class servicioHabilidad {
private: 
	ListaEnlazada* Habilidades;
public:
	servicioHabilidad();
	void ingresarHabilidad(Habilidad* nuevo);
	Naturaleza* pedirNaturaleza(servicioNaturaleza* naturaleza);
	string consultarHabilidadesPorNaturaleza(Naturaleza* naturaleza);
	void pedirDatos(servicioNaturaleza* servicioN);
	Habilidad* obtenerHabilidad(int n);
	~servicioHabilidad();
};