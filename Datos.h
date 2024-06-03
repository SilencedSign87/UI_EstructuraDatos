#pragma once
#include <vector>
#include <string>
#include "Producto.hpp"
#include "Granel.hpp"
#include "Unitario.hpp"

public ref class Datos
{
private:

	ref struct Nodo  //arbol
	{
		Producto^ producto;
		Nodo^ derecha;
		Nodo^ izquierda;
		int  altura;

		Nodo(Producto^ prod) {
			this->producto = prod;
			this->derecha = nullptr;
			this->izquierda = nullptr;
			this->altura = 1;
		}
	};

	Nodo^ raiz; //raiz del arbol
	int cantidad;
	System::Collections::Generic::Dictionary<System::String^, int>^ nombre2id; //dicionadio de nombres a id's


	static Datos^ instance; //instancia estática

	Datos() //constructor privado
	{
		this->Username = "admin";
		this->Password = "admin";
		this->raiz = nullptr;
		this->nombre2id = gcnew System::Collections::Generic::Dictionary<System::String^, int>();
		this->cantidad = 0;
	}

	//--------------------------------------------------------------------------------------- obtener datos de los nodos

	int getAltura(Nodo^ nodo) {
		return (nodo == nullptr) ? 0 : nodo->altura;
	};

	int getBalance(Nodo^ nodo) { //positivo -> rotar a la derecha; negativo->rotar a la izquierda
		return (nodo == nullptr) ? 0 : getAltura(nodo->izquierda) - getAltura(nodo->derecha);
	}

	//--------------------------------------------------------------------------------------- Rotación del arbol

	Nodo^ rotarIzquierda(Nodo^ x) { //rota el arbol a ra izquierda, retorna la nueva raiz
		Nodo^ y = x->derecha;
		Nodo^ Arbol2 = y->izquierda;

		y->izquierda = x;
		x->derecha = Arbol2;

		x->altura = System::Math::Max(getAltura(x->izquierda), getAltura(x->derecha)) + 1;
		y->altura = System::Math::Max(getAltura(y->izquierda), getAltura(y->derecha)) + 1;

		return y;
	}

	Nodo^ rotarDerecha(Nodo^ y) {
		Nodo^ x = y->izquierda;
		Nodo^ arbol2 = x->derecha;

		x->derecha = y;
		y->izquierda = arbol2;

		y->altura = System::Math::Max(getAltura(y->izquierda), getAltura(y->derecha)) + 1;
		x->altura = System::Math::Max(getAltura(x->izquierda), getAltura(x->derecha)) + 1;

		return x;
	}

	//--------------------------------------------------------------------------------------- insertar nuevo nodo

	Nodo^ insertarNuevo(Nodo^ nodo, Producto^ producto)
	{
		cantidad++;
		if (nodo == nullptr) {
			return gcnew Nodo(producto);
		}
		if (producto->Id < nodo->producto->Id) {
			nodo->izquierda = insertarNuevo(nodo->izquierda, producto);
		}
		else if (producto->Id > nodo->producto->Id)
		{
			nodo->derecha = insertarNuevo(nodo->izquierda, producto);
		}
		else {
			cantidad--;
			return nodo;
		}

		nodo->altura = 1 + System::Math::Max(getAltura(nodo->izquierda), getAltura(nodo->derecha));

		int balance = getBalance(nodo); //obtener el balance del nodo (#ramas izquierdas - #derechas)

		if (balance > 1 && producto->Id < nodo->izquierda->producto->Id) {
			return rotarDerecha(nodo);
		}

		if (balance<-1 && producto->Id > nodo->derecha->producto->Id) {
			return rotarIzquierda(nodo);
		}

		if (balance > 1 && producto->Id > nodo->izquierda->producto->Id) {
			nodo->izquierda = rotarIzquierda(nodo->izquierda);
			return rotarDerecha(nodo);
		}

		if (balance < -1 && producto->Id < nodo->derecha->producto->Id) {
			nodo->derecha = rotarDerecha(nodo->derecha);
			return rotarIzquierda(nodo);
		}

		return nodo;
	}

	//--------------------------------------------------------------------------------------- Buscar

	Nodo^ buscarNodoId(Nodo^ nodo, int id)
	{
		if (nodo == nullptr || nodo->producto->Id == id) {
			return nodo;
		}
		if (id < nodo->producto->Id) {
			return buscarNodoId(nodo->izquierda, id);
		}
		else {
			return buscarNodoId(nodo->derecha, id);
		}
	}

	Nodo^ buscarNodoNombre(Nodo^ nodo, System::String^ nombre) {
		if (!nombre2id->ContainsKey(nombre)) {
			return nullptr;
		}
		int id = nombre2id[nombre];
		return buscarNodoId(nodo, id);
	}

	void ObtenerProductos(Nodo^ nodo, System::Collections::Generic::List<Producto^ >^ lista) {
		if (nodo != nullptr) {
			ObtenerProductos(nodo->izquierda, lista);
			lista->Add(nodo->producto);
			ObtenerProductos(nodo->derecha, lista);
		}
	}

public:

	//datos publicos
	property System::String^ Username;
	property System::String^ Password;

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
	void añadeProducto(Producto^ producto) {
		raiz = insertarNuevo(raiz, producto);
		this->nombre2id[producto->Nombre] = producto->Id;
	}

	Producto^ buscarProductoId(int id) {
		Nodo^ aux = buscarNodoId(raiz, id);
		return aux->producto;
	}

	Producto^ buscarProductoNombre(System::String^ nombre) {
		Nodo^ aux = buscarNodoNombre(raiz, nombre);
		return aux->producto;
	}

	System::Collections::Generic::List< Producto^>^ obtenerTodosProducto() { //Obtiene todos los productos
		System::Collections::Generic::List<Producto^ >^ productos = gcnew System::Collections::Generic::List<Producto^ >();
		ObtenerProductos(raiz, productos);
		return productos;
	}

	property int CantidadProducto {
		int get() {
			return cantidad;
		}
	}

};