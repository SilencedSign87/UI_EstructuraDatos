#pragma once
#include "Producto.hpp"

public ref class Granel : public Producto
{
private:
	System::String^ _unidad; //esto guarda la unidad del producto
	System::Decimal^ _cantidad;
public:
	Granel(System::String^ nombre, int id, System::Decimal^ precio, System::Decimal^ cantidad, System::String^ unidad) :Producto(nombre, id, precio) //constructor
	{
		this->_cantidad = cantidad;
		this->_unidad = unidad;
	}

	// Setters y Getters

	property System::String^ unidad
	{
		System::String^ get() {
			return _unidad;
		}
		void set(System::String^ unidad) {
			this->_unidad = unidad;
		}
	}
	property System::Decimal^ cantidad
	{
		System::Decimal^ get() {
			return _cantidad;
		}
		void set(System::Decimal^ cantidad) {
			this->_cantidad = cantidad;
		}
	}
};
