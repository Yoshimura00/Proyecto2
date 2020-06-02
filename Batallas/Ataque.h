#pragma once
#include "Habilidad.h"
class Ataque : public Habilidad {
private:
	int daño;
public: 
	Ataque(string nombre, int uso, int daño); 
	int random();
    void ejecutar(Luchador* uno, Luchador* dos);
















};