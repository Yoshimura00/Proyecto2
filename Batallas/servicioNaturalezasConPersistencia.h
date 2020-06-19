#pragma once
#include "servicioNaturaleza.h"
#include<fstream>
class servicioNaturalezasConPersistencia : public servicioNaturaleza {
private: 
	string rutaArchivo;
public: 
	servicioNaturalezasConPersistencia(string rutaArchivo);
	void deserializarNaturalezas();
	void serializarNaturalezas();
	~servicioNaturalezasConPersistencia();
	

};