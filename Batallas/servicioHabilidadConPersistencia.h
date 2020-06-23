#pragma once
#include "Alterar.h"
#include "Ataque.h"
#include "Curacion.h"
#include "servicioHabilidad.h"
#include<fstream>

class servicioHabilidadConPersistencia : public servicioHabilidad {
private:
	string rutaArchivo;
public:
	servicioHabilidadConPersistencia(string rutaArchivo);
	void deserializarHabilidades();
	void serializarHabilidades();
	~servicioHabilidadConPersistencia();

};
