#include "servicioLuchadorConPersistencia.h"

servicioLuchadorConPersistencia::servicioLuchadorConPersistencia(string rutaArchivo)
{
	
}

void servicioLuchadorConPersistencia::deserializarLuchadores()
{
	ifstream in(rutaArchivo, ios::in);
	if (in.good())
	{
		while (!in.eof() && in.good())
		{
			//ingresarLuchador(new Luchador(in));//
		}
		in.close();
	}
}

void servicioLuchadorConPersistencia::serializarLuchadores()
{
}

servicioLuchadorConPersistencia::~servicioLuchadorConPersistencia()
{
}
