#pragma once
#include "Habilidad.h"
class Curacion : public Habilidad {
private:
	int intervalo;
public: 
	Curacion(string nombre, int uso, int intervalo);
	int random();
	void ejecutar(Luchador* uno, Luchador* dos);










};