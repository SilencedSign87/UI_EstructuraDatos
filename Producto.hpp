#pragma once

// Producto Gestionada

public ref class Producto
{
private:
	System::String^ _nombre;
	int _id;
	float _precio;

public:
	Producto() : _nombre(""), _id(0), _precio(0.0f) {}
	Producto(System::String^ nombre, int id, float precio) : _nombre(nombre), _id(id), _precio(precio) {}

	// Setters y Getters

	virtual property System::String^ Nombre {
		System::String^ get() {
			return _nombre;
		}

		void set(System::String^ value) {
			_nombre = value;
		}
	}

	virtual property int Id {
		int get() {
			return _id;
		}
		void set(int value) {
			_id = value;
		}
	}

	virtual property float Precio {
		float get() {
			return _precio;
		}
		void set(float value) {
			_precio = value;
		}
	}
};
