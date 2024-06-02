#pragma once
#include "Producto.hpp"

public ref class Granel : public Producto
{
private:
	System::String^ _unidad;
	float _cantidad;
public:
	Granel(System::String^ nombre, int id, float precio, float cantidad, System::String^ unidad) :Producto(nombre, id, precio) //constructor
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
	property float cantidad
	{
		float get() {
			return _cantidad;
		}
		void set(float cantidad) {
			this->_cantidad = cantidad;
		}
	}
};