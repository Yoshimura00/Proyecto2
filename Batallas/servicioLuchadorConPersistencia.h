#pragma once
#include "servicioLuchador.h"
#include<fstream>
class servicioLuchadorConPersistencia : public ServicioLuchador {
private:
	string rutaArchivo;
public:
	servicioLuchadorConPersistencia(string rutaArchivo);
	void deserializarLuchadores();
	void serializarLuchadores();
	~servicioLuchadorConPersistencia();


};