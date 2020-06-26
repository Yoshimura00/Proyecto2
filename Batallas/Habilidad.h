#pragma once
#include "Luchadores.h"
#include "servicioNaturaleza.h"
class Luchador;
class Habilidad : public ObjetoBase {
private: 
	string nombre; 
	int uso;
	int limiteDeUso;
	Naturaleza* naturaleza;
	
public: 
	Habilidad();
	Habilidad(string nombre, Naturaleza* naturaleza, int uso, int limiteDeUso);
	Habilidad(istream& input, servicioNaturaleza* lista);
	void setUso(int uso);
	int getUso();
	int getLimiteDeUso();
	string getNombre();
	Naturaleza* getNaturaleza();
	virtual int random() = 0;
	virtual void ejecutar(Luchador* uno, Luchador * dos) = 0;
	string toString();
	virtual void serializar(ostream& out) = 0;

};
