#pragma once
#include "LIstaEnlazada.h"
#include "Luchadores.h"
class ServicioLuchador {
private: 
	ListaEnlazada* Luchadores; 
public: 
	ServicioLuchador();
	void ingresarLuchador(Luchador* nuevo);
	Luchador* ConsultarLuchador(string nombre);
	bool EliminarLuchador(string nombre);
	~ServicioLuchador();



};