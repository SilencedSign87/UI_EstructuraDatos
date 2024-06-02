#pragma once
#include <vector>
#include <cliext/vector>
#include "Producto.hpp"
#include "Granel.hpp"
#include "Unitario.hpp"

public ref class Datos
{
private:
	static Datos^ instance;

	Datos() //constructor privado
	{
		this->Username = "admin";
		this->Password = "admin";
		this->listaProductos = gcnew cliext::vector<Producto^>();
		this->longitud = 0;
	}

public:
	//datos
	property System::String^ Username;
	property System::String^ Password;
	property cliext::vector <Producto^>^ listaProductos;
	property int longitud;

	//instancia estática (única)
	static property Datos^ Instance
	{
		Datos^ get()
		{
			if (instance == nullptr)
			{
				instance = gcnew Datos();
			}
			return instance;
		}
	}

	void agregarGranel(System::String^ nombre, float precio, float cantidad, System::String^ unidad) {
		Granel^ nuevo = gcnew Granel(nombre, this->longitud + 10000, precio, cantidad, unidad);
		this->listaProductos->push_back(nuevo);
		this->longitud++;

	}

	void agregarUnitario(System::String^ nombre, float precio, int cantidad) {
		Unitario^ nuevo = gcnew Unitario(nombre, this->longitud + 10000, precio, cantidad);
		this->listaProductos->push_back(nuevo);
		this->longitud++;
	}

	Producto^ obtenerProducto(int index)
	{
		if (index >= 0 && index < this->longitud) {
			return this->listaProductos[index];
		}
		else //manejo de errores
		{
			return nullptr;
		}
	}
};