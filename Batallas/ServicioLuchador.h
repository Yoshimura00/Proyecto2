#pragma once
#include "servicioNaturaleza.h"
#include "LIstaEnlazada.h"
#include "Luchadores.h"
class servicioNaturaleza;
class Luchador;
class ServicioLuchador {
private: 
	ListaEnlazada* Luchadores; 
public: 
	ServicioLuchador();
	void ingresarLuchador(Luchador* nuevo);
	Luchador* ConsultarLuchador(string nombre);
	void pedirDatos(servicioNaturaleza*l);
	bool EliminarLuchador(string nombre);
	~ServicioLuchador();



};