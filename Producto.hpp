#pragma once

// Producto Gestionada

public ref class Producto
{
private:
	System::String^ _nombre;
	int _id;
	System::Decimal^ _precio;

public:

	Producto(System::String^ nombre, int id, System::Decimal^ precio)
	{
		this->_nombre = nombre->ToLower();
		this->_id = id; //asegurarse que sea solo la parte entera
		this->_precio = precio; //con parte decimal
	}

	// Setters y Getters

	virtual property System::String^ Nombre {
		System::String^ get() {
			return _nombre;
		}

		void set(System::String^ value) {
			_nombre = value->ToLower();
		}
	}

	virtual property int Id {
		int get() {
			return _id;
		}
		void set(int value) {
			_id =value; //asegura que sea solo la parte entera
		}
	}

	virtual property System::Decimal^ Precio {
		System::Decimal^ get() {
			return _precio;
		}
		void set(System::Decimal^ value) {
			_precio = value;
		}
	}
};
