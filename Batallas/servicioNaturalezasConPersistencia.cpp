#include "servicioNaturalezasConPersistencia.h"

servicioNaturalezasConPersistencia::servicioNaturalezasConPersistencia(string rutaArchivo)
{
	this->rutaArchivo = rutaArchivo;
}

void servicioNaturalezasConPersistencia::deserializarNaturalezas()
{
	ifstream in(rutaArchivo, ios::in);
	if (in.good())
	{
		while (!in.eof() && in.good())
		{
			ingresarNaturaleza(new Naturaleza(in));
		}
		in.close();
	}
}

void servicioNaturalezasConPersistencia::serializarNaturalezas()
{
	int cantidad = getNaturalezas()->cantidad();
	if (cantidad > 0) {
		ofstream out(this->rutaArchivo, ios::out);

		if (out.good())
		{
			for (int i = 0; i < cantidad; i++)
			{
				Naturaleza* nat = (Naturaleza*)getNaturalezas()->consultarPorPosicion(i);
				nat->serializar(out);

				if (i != cantidad - 1)
					out << endl;
			}

			out.close();
		}
	}
}

servicioNaturalezasConPersistencia::~servicioNaturalezasConPersistencia()
{
}
