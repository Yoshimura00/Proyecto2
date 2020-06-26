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
	string consultarHabilidadesPorNaturaleza(servicioNaturaleza* servicioN, Naturaleza* naturaleza);
	void pedirDatos(servicioNaturaleza* servicioN);
	bool contieneHabilidad(Habilidad* habilidad);
	Habilidad* obtenerHabilidad(int n);
	string toString();
	bool habilidadVacia();
	Habilidad* consultarHabilidad(string nombre);
	ListaEnlazada* getHabilidades();
	virtual ~servicioHabilidad();
};