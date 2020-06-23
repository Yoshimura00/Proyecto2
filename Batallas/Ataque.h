#pragma once
#include "Habilidad.h"
class Ataque : public Habilidad {
private:
	int da�oBase;
public: 
	Ataque(string nombre, Naturaleza* naturaleza, int uso, int da�o);
	Ataque(istream& input);
	int random();
	float random2();
	float calcDa�o(Luchador* uno, Luchador* dos);
	float da�oFinal(Luchador* uno, Luchador* dos);
    void ejecutar(Luchador* uno, Luchador* dos);
	string toString();
	virtual void serializar(ostream& out);















};