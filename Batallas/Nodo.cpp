#include "Nodo.h"

Nodo::Nodo(ObjetoBase* dato, Nodo* siguiente)
{
	this->dato = dato;
	this->siguiente = siguiente;
}

ObjetoBase* Nodo::getDato()
{
	return this->dato;
}

void Nodo::setDato(ObjetoBase* dato)
{
	this->dato = dato;
}

Nodo* Nodo::getSiguiente()
{
	return nullptr;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}
