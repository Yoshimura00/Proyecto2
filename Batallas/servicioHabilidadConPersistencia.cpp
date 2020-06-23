#include "servicioHabilidadConPersistencia.h"

servicioHabilidadConPersistencia::servicioHabilidadConPersistencia(string rutaArchivo)
{
	this->rutaArchivo = rutaArchivo;
}

void servicioHabilidadConPersistencia::deserializarHabilidades()
{
	ifstream in(rutaArchivo, ios::in);
	if (in.good())
	{
		string tipo;
		Habilidad* nuevo = nullptr;
		while (!in.eof() && in.good())
		{
			getline(in, tipo, ',');
			if (tipo == "Alteracion")
			{
				nuevo = new Alteracion(in);
			}
			else if (tipo == "Ataque")
			{
				nuevo = new Ataque(in);
			}
			else if (tipo == "Curacion")
			{
				nuevo = new Curacion(in);
			}

			this->ingresarHabilidad(nuevo);
		}
		in.close();
	}
}

void servicioHabilidadConPersistencia::serializarHabilidades()
{
	int cantidad = getHabilidades()->cantidad();
	if (cantidad > 0) {
		ofstream out(this->rutaArchivo, ios::out);

		if (out.good())
		{
			for (int i = 0; i < cantidad; i++)
			{
				Habilidad* h = (Habilidad*)getHabilidades()->consultarPorPosicion(i);
				h->serializar(out);

				if (i != cantidad - 1)
					out << endl;
			}
			out.close();
		}
	}
}

servicioHabilidadConPersistencia::~servicioHabilidadConPersistencia()
{
}
