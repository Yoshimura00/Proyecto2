#pragma once
#include "ServicioLuchador.h"
#include<fstream>
class servicioNaturalezasConPersistencia : public ServicioLuchador {
private: 
	string rutaArchivo;
public: 
	void deserializarPersonas();
	void serializarPersonas();
};