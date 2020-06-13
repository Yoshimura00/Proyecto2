#pragma once
#include "Habilidad.h"
class Curacion : public Habilidad {
private:
	int intervalo;
public: 
	Curacion(string nombre, Naturaleza* naturaleza, int uso, int intervalo);
	int random();
	int calcRecuperacion();
	void ejecutar(Luchador* uno, Luchador* dos);
	string toString();









};