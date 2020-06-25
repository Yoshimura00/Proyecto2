#pragma once
#include "servicioLuchador.h"
#include "Ninja.h"
#include "Mago.h"
#include "Caballero.h"
#include<fstream>
class servicioLuchadorConPersistencia : public ServicioLuchador {
private:
	string rutaArchivo;
public:
	servicioLuchadorConPersistencia(string rutaArchivo, servicioNaturaleza* lista);
	void deserializarLuchadores(servicioNaturaleza* lista);
	void serializarLuchadores();
	~servicioLuchadorConPersistencia();


};