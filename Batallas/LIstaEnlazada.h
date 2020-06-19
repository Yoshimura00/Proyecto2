#pragma once
#include "ObjetoBase.h"
#include "Nodo.h"
class ListaEnlazada {

private:
	Nodo* primero;

public: 
  ListaEnlazada();
  void insertarAlFinal(ObjetoBase* objeto);
  string toString();
  ObjetoBase* consultarPorPosicion(int n);
  void eliminarPrimero();
  void eliminarDato(int n);
  void eliminarUltimo();
  int cantidad();
  bool contiene(ObjetoBase* elemento);
  void clearData();
  bool listaVacia();
  ~ListaEnlazada();

};
