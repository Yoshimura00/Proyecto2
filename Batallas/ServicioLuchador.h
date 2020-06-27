#pragma once
#include "servicioHabilidad.h"
#include "servicioNaturaleza.h"
#include "LIstaEnlazada.h"
#include "Luchadores.h"

class ServicioLuchador {
private: 
	ListaEnlazada* Luchadores; 
public: 
	ServicioLuchador();
	void ingresarLuchador(Luchador* nuevo);
	Luchador* consultarLuchador(string nombre);
	Luchador* consultarLuchadorPorPosicion(int pos);
	bool contieneLuchador(Luchador* luchador);
	int cantidad();
	void consultarDatosLuchador();
	void pedirDatos(servicioNaturaleza*l);
	bool EliminarLuchador(string nombre);
	void eliminarLuchadorpNombre();
	void administrarHabilidades(servicioHabilidad* s);
	string toString();
	string mostrarNombres(ListaEnlazada* lista);
	ListaEnlazada* getLuchadores();
	virtual ~ServicioLuchador();



};