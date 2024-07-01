#pragma once
#include <vector>
#include <string>
#include "Producto.hpp"
#include "Granel.hpp"
#include "Unitario.hpp"
#include "BaseDatos.h"

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
	AdministradorDB^ dbManager;

	Datos() //constructor privado
	{
		this->Username = "admin";
		this->Password = "admin";
		this->raiz = nullptr;
		this->nombre2id = gcnew System::Collections::Generic::Dictionary<System::String^, int>();
		this->cantidad = 0;
		this->dbManager = gcnew AdministradorDB("Inventario.db");
		dbManager->abreConexion();
		dbManager->creaTabla();
		CargarDatos();
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
			nodo->derecha = insertarNuevo(nodo->derecha, producto);
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
	//--------------------------------------------------------------------------------------- Valor minimo de un nodo
	Nodo^ minValorNodo(Nodo^ nodo) {
		Nodo^ actual = nodo;
		while (actual->izquierda != nullptr) {
			actual = actual->izquierda;
		}
		return actual;
	}
	//--------------------------------------------------------------------------------------- Eliminar un nodo
	Nodo^ borrarNodo(Nodo^ nodo, int id) {
		if (nodo == nullptr) {
			return nodo;
		}
		if (id < nodo->producto->Id) {
			nodo->izquierda = borrarNodo(nodo->izquierda, id);
		}
		else if (nodo->producto->Id < id) {
			nodo->derecha = borrarNodo(nodo->derecha, id);
		}
		else {
			if (nodo->izquierda == nullptr || nodo->derecha == nullptr) {
				Nodo^ temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;

				if (temp == nullptr) {
					temp = nodo;
					nodo = nullptr;
				}
				else {
					nodo = temp;
				}

				delete temp;
			}
			else {
				Nodo^ temp = minValorNodo(nodo->izquierda);
				nodo->producto = temp->producto;

				nodo->derecha = borrarNodo(nodo->derecha, temp->producto->Id);
			}
		}

		if (nodo == nullptr) {
			return nullptr;
		}

		nodo->altura = 1 + System::Math::Max(getAltura(nodo->izquierda), getAltura(nodo->derecha));

		int balance = getBalance(nodo);

		if (balance > 1 && getBalance(nodo->izquierda) >= 0) {
			return rotarDerecha(nodo);
		}
		if (balance > 1 && getBalance(nodo->izquierda) < 0) {
			nodo->izquierda = rotarIzquierda(nodo->izquierda);
			return rotarDerecha(nodo);
		}
		if (balance < -1 && getBalance(nodo->derecha) <= 0) {
			return rotarIzquierda(nodo);
		}
		if (balance < -1 && getBalance(nodo->derecha)>0) {
			nodo->derecha = rotarDerecha(nodo->derecha);
			return rotarIzquierda(nodo);
		}

		return nodo;

	}

	//--------------------------------------------------------------------------------------- Buscar

	Nodo^ buscarNodoId(Nodo^ nodo, int id)
	{
		if (nodo == nullptr || nodo->producto->Id == id) {
			return nodo; // Retorna nullptr si no lo encuentra, si lo encuentra retorna el nodo.
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

	~Datos() {
		GuardarDatos();
		dbManager->cierraConexion();
	}

	void addProducto(Producto^ producto) {
		raiz = insertarNuevo(raiz, producto);
		this->nombre2id[producto->Nombre] = producto->Id;
	}

	void borrarPorId(int id) {
		raiz = borrarNodo(raiz, id);

		for each (auto kvp in nombre2id) {
			if (kvp.Value == id) {
				nombre2id->Remove(kvp.Key);
				break;
			}
		}
	}

	void borrarPorNombre(System::String^ nombre) {
		nombre = nombre->ToLower();
		if (nombre2id->ContainsKey(nombre)) {
			int id = nombre2id[nombre];
			borrarPorId(id);
		}
	}

	int nombre_Id(System::String^ nombre) {
		if (nombre2id->ContainsKey(nombre)) {
			return nombre2id[nombre];
		}
		else {
			return -1;
		}
	}

	Producto^ buscarProductoId(int id) {
		Nodo^ aux = buscarNodoId(raiz, id);
		return aux->producto;
	}

	Producto^ buscarProductoNombre(System::String^ nombre) {
		Nodo^ aux = buscarNodoNombre(raiz, nombre);
		return aux->producto;
	}

	void actualizaDatos(System::String^ nuevoNombre, int id) {
		Nodo^ nodo = buscarNodoId(raiz, id);
		if (nodo != nullptr) {
			System::String^ antiguoNombre = nodo->producto->Nombre;
			nombre2id->Remove(antiguoNombre);
			nombre2id[nuevoNombre] = id;
		}
	}

	System::Collections::Generic::List<Producto^ >^ buscarDinamico(System::String^ segmento) {
		segmento = segmento->ToLower();
		System::Collections::Generic::List<Producto^ >^ productos = gcnew System::Collections::Generic::List<Producto^ >();
		System::Collections::Generic::List<Producto^ >^ productosEncontrados = gcnew System::Collections::Generic::List<Producto^ >();
		ObtenerProductos(raiz, productos);
		for each (Producto ^ e in productos)
		{
			System::String^ aux = e->Nombre->ToLower();
			if (aux->Contains(segmento)) {
				productosEncontrados->Add(e);
			}
		}
		return productosEncontrados;
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

	//--------------------------------------------------------------------------------------- Carga los datos de la Base de Datos
	void CargarDatos()
	{
		List<Producto^>^ productosGranel = dbManager->LoadGranel();
		for each (Producto ^ producto in productosGranel)
		{
			addProducto(producto);
		}

		List<Producto^>^ productosUnitario = dbManager->LoadUnitario();
		for each (Producto ^ producto in productosUnitario)
		{
			addProducto(producto);
		}
	}
	//--------------------------------------------------------------------------------------- Guarda los datos a la Base de Datos
	void GuardarDatos()
	{
		List<Producto^>^ productos = obtenerTodosProducto();
		for each (Producto ^ producto in productos)
		{
			if (Granel^ granel = dynamic_cast<Granel^>(producto))
			{
				dbManager->InsertGranel(granel->Id, granel->Nombre, granel->Precio, granel->cantidad, granel->unidad);
			}
			else if (Unitario^ unitario = dynamic_cast<Unitario^>(producto))
			{
				dbManager->InsertUnitario(unitario->Id, unitario->Nombre, unitario->Precio, unitario->cantidad);
			}
		}
	}

	void borrarGranelDB(int id) {
		dbManager->DeleteGranel(id);
	}
	void borrarUnitarioDB(int id) {
		dbManager->DeleteUnitario(id);
	}

};