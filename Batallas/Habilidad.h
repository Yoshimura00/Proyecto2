#pragma once
#include "ObjetoBase.h"
#include "Luchadores.h"
class Habilidad : public ObjetoBase {
private: 
	string nombre; 
	int uso;
	
public: 
	Habilidad();
	Habilidad(string nombre, bool uso);
	void setUso(bool uso);
	int getUso();
	virtual int random() = 0;
	virtual void ejecutar(Luchador* uno, Luchador * dos) = 0;
	





};