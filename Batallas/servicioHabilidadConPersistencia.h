#pragma once
#include "servicioHabilidad.h"
#include "servicioLuchadorConPersistencia.h"
#include<fstream>

class servicioHabilidadConPersistencia : public servicioHabilidad {
private:
	string rutaArchivo;
	servicioNaturaleza* lista;
public:

	servicioHabilidadConPersistencia(string rutaArchivo);
	void deserializarHabilidades(servicioNaturaleza* lista);
	void serializarHabilidades();
	~servicioHabilidadConPersistencia();

};
