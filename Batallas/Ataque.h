#pragma once
#include "Habilidad.h"
class Ataque : public Habilidad {
private:
	int da�o;
public: 
	Ataque(string nombre, int uso, int da�o); 
	int random();
    void ejecutar(Luchador* uno, Luchador* dos);
















};