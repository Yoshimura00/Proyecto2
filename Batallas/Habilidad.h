#pragma once
#include "Luchadores.h"
#include "Naturaleza.h"
class Habilidad : public ObjetoBase {
private: 
	string nombre; 
	int uso;
	Naturaleza* naturaleza;
	
public: 
	Habilidad();
	Habilidad(string nombre, Naturaleza* naturaleza, int uso);
	void setUso(int uso);
	int getUso();
	Naturaleza* getNaturaleza();
	virtual int random() = 0;
	virtual void ejecutar(Luchador* uno, Luchador * dos) = 0;
	string toString();





};