#include "servicioLuchadorConPersistencia.h"

servicioLuchadorConPersistencia::servicioLuchadorConPersistencia(string rutaArchivo)
{
	this->rutaArchivo = rutaArchivo;
}

void servicioLuchadorConPersistencia::deserializarLuchadores(servicioNaturaleza* lista)
{
	ifstream in(rutaArchivo, ios::in);
	if (in.good())
	{
		string tipo;
		Luchador* nuevo = nullptr;
		while (!in.eof() && in.good())
		{
			getline(in, tipo, ',');
			if (tipo == "Caballero")
			{
				nuevo = new Caballero(in, lista);
			}
			else if (tipo == "Ninja")
			{
				nuevo = new Ninja(in, lista);
			}
			else if (tipo == "Mago")
			{
				nuevo = new Mago(in, lista);
			}
			ingresarLuchador(nuevo);
		}
		in.close();
	}
}

void servicioLuchadorConPersistencia::serializarLuchadores()
{
	int cantidad =  getLuchadores()->cantidad();
	if (cantidad > 0) {
		ofstream out(this->rutaArchivo, ios::out);

		if (out.good())
		{
			for (int i = 0; i < cantidad; i++)
			{
				Luchador* l = (Luchador*)getLuchadores()->consultarPorPosicion(i);
				l->serializar(out);

				if (i != cantidad - 1)
					out << endl;
			}

			out.close();
		}

	}
}

servicioLuchadorConPersistencia::~servicioLuchadorConPersistencia()
{

}
