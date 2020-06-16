#include "LIstaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
	this->primero = nullptr;
}

void ListaEnlazada::insertarAlFinal(ObjetoBase* objeto)
{
	Nodo* nuevo = new Nodo(objeto, nullptr);

	if (this->primero == nullptr)
	{
		this->primero = nuevo;
	}
	else
	{
		Nodo* actual = this->primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}

string ListaEnlazada::toString()
{
	stringstream s;
	Nodo* actual = this->primero;

	while (actual != nullptr)
	{
		s << actual->getDato()->toString() << endl;
		actual = actual->getSiguiente();
	}

	return s.str();
}


ObjetoBase* ListaEnlazada::consultar(int n)
{
	if (primero == nullptr)
	{
		return nullptr;
	}
	else
	{
		Nodo* actual = this->primero;
		int i = 0;
		while (actual != nullptr && i < n)
		{
			actual = actual->getSiguiente();
			i++;
		}

		if (actual != nullptr)
		{
			return actual->getDato();
		}

		return nullptr;
	}
}

void ListaEnlazada::eliminarPrimero()
{
	if (primero == nullptr)
	{
		return;
	}
	else
	{
		Nodo* eliminar = primero;
		primero = primero->getSiguiente();
		delete eliminar;
	}
}

void ListaEnlazada::eliminarNodo(int n)
{
	if (this->primero == nullptr) 
	{
		return; 
	}
	else
	{
		Nodo* temp; 
		if (n == 0)
		{
			temp = this->primero;
			this->primero = this->primero->getSiguiente();
			delete temp;
		}
		else
		{
		
			Nodo* actual = this->primero;
			int i = 0;
			while (actual->getSiguiente() != nullptr && i < n - 1) 
			{
				actual = actual->getSiguiente();
				i++;
			}
			if (actual->getSiguiente() != nullptr)
			{
				temp = actual->getSiguiente();
				actual->setSiguiente(temp->getSiguiente());
				delete temp;
			}
		}
	}
}

void ListaEnlazada::eliminarUltimo()
{
	if (this->primero == nullptr)
	{
		return;
	}
	else
	{
		Nodo* eliminar;

		if (this->primero->getSiguiente() == nullptr)
		{
			eliminar = this->primero;
			this->primero = this->primero->getSiguiente();
			delete eliminar;
		}
		else
		{
			Nodo* actual = this->primero;
			while (actual->getSiguiente()->getSiguiente() != nullptr)
			{
				actual = actual->getSiguiente();
			}

			if (actual->getSiguiente() != nullptr) {
				eliminar = actual->getSiguiente();
				actual->setSiguiente(eliminar->getSiguiente());
				delete eliminar;
			}
		}
	}
}

int ListaEnlazada::cantidad()
{
	int total = 0;
	Nodo* actual = this->primero;

	while (actual != nullptr)
	{
		actual = actual->getSiguiente();
		total++;
	}
	return total;
}
bool ListaEnlazada::listaVacia() {
	if (primero == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
bool ListaEnlazada::contiene(ObjetoBase* elemento)
{
	Nodo* actual = this->primero;
	while (actual != nullptr)
	{
		if (actual->getDato() == elemento)
			return true;
		actual = actual->getSiguiente();
	}
	return false;
}

void ListaEnlazada::clearData()
{
	Nodo* actual = this->primero;

	while (actual != nullptr)
	{
		delete actual->getDato();
		actual = actual->getSiguiente();
	}
}

ListaEnlazada::~ListaEnlazada()
{
	while (primero != nullptr)
	{
		eliminarPrimero();
	}
}
