#pragma once
#include "BaseDatos.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Data;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;

//Singleton

ref class Historial {
private:
	static Historial^ instance;
	SQLiteConnection^ conn;

	Historial()
	{
		Conecta();
		crearTablas();
	}

	void Conecta() {
		String^ dbDireccion = GetRelativeDatabasePath();
		dbDireccion = "Data Source=" + dbDireccion + ";Version=3;";
		this->conn = gcnew SQLiteConnection(dbDireccion);
		abreHistorial();
	}

	void abreHistorial() {
		conn->Open();
	}

	void cierraHistorial() {
		conn->Close();
	}

	String^ GetRelativeDatabasePath()
	{
		// Obtiene el directorio del ejecutable
		String^ exePath = Assembly::GetExecutingAssembly()->Location;
		String^ exeDir = Path::GetDirectoryName(exePath);

		// Construye la ruta relativa a la base de datos
		String^ dbPath = Path::Combine(exeDir, "data", "Historial.db");

		// Asegúrate de que el directorio exista
		Directory::CreateDirectory(Path::GetDirectoryName(dbPath));

		return dbPath;
	}

	void crearTablas() {
		String^ sqlCreaTabla = "CREATE TABLE IF NOT EXISTS Ventas ("
			"Id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"Vendedor TEXT, "
			"Fecha DATETIME, "
			"Total REAL)";

		SQLiteCommand^ comand = gcnew SQLiteCommand(sqlCreaTabla, conn);
		comand->ExecuteNonQuery();

		String^ sqlDetallesVenta = "CREATE TABLE IF NOT EXISTS DetallesVenta ("
			"Id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"VentaId INTEGER, "
			"ProductoId INTEGER, "
			"NombreProducto TEXT, "
			"Cantidad REAL, "
			"PrecioUnitario REAL, "
			"Subtotal REAL,"
			"FOREIGN KEY(VentaId) REFERENCES Ventas(Id))";
		SQLiteCommand^ commandDetallesVenta = gcnew SQLiteCommand(sqlDetallesVenta, conn);
		commandDetallesVenta->ExecuteNonQuery();
	}

public:

	//instancia única
	static property Historial^ Instance
	{
		Historial^ get() {
			if (instance == nullptr) {
				instance = gcnew Historial();
			}
			return instance;
		}
	}

	~Historial() {
		cierraHistorial();
	}

	//retorna la id de la venta
	int InsertarVenta(DateTime fecha, Decimal^ total, String^ vendedor) {
		String^ sql = "INSERT INTO Ventas (Vendedor, Fecha, Total) VALUES (@vendedor, @fecha, @total); "
			"SELECT last_insert_rowid();";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, conn);
		command->Parameters->AddWithValue("@fecha", fecha);
		command->Parameters->AddWithValue("@total", total);
		command->Parameters->AddWithValue("@vendedor", vendedor);
		return Convert::ToInt32(command->ExecuteScalar());
	}

	void InsertarDetalleVenta(int ventaId, int productoId, String^ nombreProducto, Decimal^ cantidad, Decimal^ precioUnitario) {
		String^ sql = "INSERT INTO DetallesVenta (VentaId, ProductoId, NombreProducto, Cantidad, PrecioUnitario, Subtotal) "
			"VALUES (@ventaId, @productoId, @nombreProducto, @cantidad, @precioUnitario, @subtotal)";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, conn);
		command->Parameters->AddWithValue("@ventaId", ventaId);
		command->Parameters->AddWithValue("@productoId", productoId);
		command->Parameters->AddWithValue("@nombreProducto", nombreProducto);
		command->Parameters->AddWithValue("@cantidad", cantidad);
		command->Parameters->AddWithValue("@precioUnitario", precioUnitario);
		command->Parameters->AddWithValue("@subtotal", System::Decimal::Multiply(static_cast<System::Decimal>(cantidad), static_cast<System::Decimal>(precioUnitario)));
		command->ExecuteNonQuery();
	}

	DataTable^ ObtenerVentas() {
		String^ sql = "SELECT Id, Fecha, Total, Vendedor FROM Ventas ORDER BY Fecha DESC";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, conn);
		SQLiteDataAdapter^ adapter = gcnew SQLiteDataAdapter(command);
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);
		return table;
	}

	DataTable^ ObtenerDetallesVenta(int ventaId) {
		String^ sql = "SELECT NombreProducto, Cantidad, PrecioUnitario, Subtotal FROM DetallesVenta WHERE VentaId = @ventaId";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, conn);
		command->Parameters->AddWithValue("@ventaId", ventaId);
		SQLiteDataAdapter^ adapter = gcnew SQLiteDataAdapter(command);
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);
		return table;
	}

};