#pragma once
#include "Alterar.h"
#include "Ataque.h"
#include "Curacion.h"
#include "servicioHabilidad.h"
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
