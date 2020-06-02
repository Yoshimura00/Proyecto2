#pragma once
#include "ObjetoBase.h"
class ListasNaturaleza: public ObjetoBase{
private:
	int id;
	string enemigo;
public:
	virtual string toString();
	
};