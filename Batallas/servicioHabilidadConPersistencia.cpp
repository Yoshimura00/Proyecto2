#include "servicioHabilidadConPersistencia.h"

servicioHabilidadConPersistencia::servicioHabilidadConPersistencia(string rutaArchivo)
{
	this->rutaArchivo = rutaArchivo;
}

void servicioHabilidadConPersistencia::deserializarHabilidades(servicioNaturaleza* lista )
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
				nuevo = new Alteracion(in, lista);
			}
			else if (tipo == "Ataque")
			{
				nuevo = new Ataque(in, lista);
			}
			else if (tipo == "Curacion")
			{
				nuevo = new Curacion(in, lista);
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


void servicioHabilidadConPersistencia::deserializarHabilidadesLuchador(string rutaArchivo, servicioLuchadorConPersistencia* s1)
{
	ifstream in(rutaArchivo, ios::in);
	int cantidad = s1->cantidad();
	if ((in.good())) {
		for (int i = 0; i < cantidad; i++) {
			ListaEnlazada* l1 = new ListaEnlazada();
			string campo;
			string nombreH1;
			string nombreH2;
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			getline(in, campo, ',');
			//

			getline(in, nombreH1, ',');
			while (nombreH1 != "sin asignar") {
				l1->insertarAlFinal(consultarHabilidad(nombreH1));
				getline(in, nombreH1, ',');
			}
			while (nombreH1 == "sin asignar") {
				getline(in, nombreH1, ',');
			}
			s1->consultarLuchadorPorPosicion(i)->setHabilidades(l1);
		}
	}
	in.close();
	
}
	
servicioHabilidadConPersistencia::~servicioHabilidadConPersistencia(){}
