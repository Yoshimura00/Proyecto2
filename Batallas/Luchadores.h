#pragma once
#include "LIstaEnlazada.h"
#include "Naturaleza.h"

class Luchador: public ObjetoBase {
private:
	string nombre;
	Naturaleza* naturaleza;
	int salud;
	int PHYATK;
	int PHYDEF;
	int MAGATK;
	int MAGDEF;
	int SPD;
public:
	Luchador();
	Luchador(string nombre, Naturaleza* naturaleza, int salud, int PHYATK, int PHYDEF, int MAGATK, int MAGDEF, int SPD);
	void setSalud(int salud);
	void setPHYATK(int PHYATK);
	void setPHYDEF(int PHYDEF);
	void setMAGATK(int MAGATK);
	void setMAGDEF(int MAGDEF);
	void setSPD(int SPD);
	string getNombre(); 
	int getSalud();
	int getPHYATK();
	int getPHYDEF();
	int getMAGATK();
	int getMAGDEF();
	int getSPD();
	Naturaleza* getNaturaleza();
	virtual int random() = 0;
	virtual int random2() = 0;
	virtual void especial(Luchador* uno, Luchador* dos) = 0;
	string toString();
};