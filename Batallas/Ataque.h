#pragma once
#include "Habilidad.h"
class Ataque : public Habilidad {
private:
	int dañoBase;
public: 
	Ataque(string nombre, Naturaleza* naturaleza, int uso, int daño);
	Ataque(istream& input, servicioNaturaleza* lista);
	int random();
	float random2();
	float calcDaño(Luchador* uno, Luchador* dos);
	float dañoFinal(Luchador* uno, Luchador* dos);
    void ejecutar(Luchador* uno, Luchador* dos);
	string toString();
	virtual void serializar(ostream& out);















};