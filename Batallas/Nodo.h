#pragma once
#include"ObjetoBase.h"

class Nodo
{
private:
	ObjetoBase* dato;
	Nodo* siguiente;
public:
	Nodo(ObjetoBase* dato, Nodo* siguiente);
	ObjetoBase* getDato();
	void setDato(ObjetoBase* dato);
	Nodo* getSiguiente();
	void setSiguiente(Nodo* siguiente);


};