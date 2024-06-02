#pragma once
#include "Producto.hpp"

public ref class Unitario : public Producto
{
private:
	int _cantidad;
public:

	Unitario(System::String^ nombre, int id, float precio, int cantidad) :Producto(nombre, id, precio) //constructor
	{
		this->_cantidad = cantidad;
	}

	// Setters y Getters

	property int cantidad {
		int get() {
			return _cantidad;
		}
		void set(int cantidad) {
			this->_cantidad = cantidad;
		}
	}

};