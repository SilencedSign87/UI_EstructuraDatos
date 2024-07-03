#pragma once

#include "Producto.hpp"
#include "Granel.hpp"
#include "Unitario.hpp"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Data;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;

public ref class AdministradorDB {
private:
	SQLiteConnection^ dbConexion;

	String^ GetRelativeDatabasePath()
	{
		// Obtiene el directorio del ejecutable
		String^ exePath = Assembly::GetExecutingAssembly()->Location;
		String^ exeDir = Path::GetDirectoryName(exePath);

		// Construye la ruta relativa a la base de datos
		String^ dbPath = Path::Combine(exeDir, "data", "Inventario.db");

		// Asegúrate de que el directorio exista
		Directory::CreateDirectory(Path::GetDirectoryName(dbPath));

		return dbPath;
	}

public:

	

	//Crea la clase adminitrativa de la base de datos inventario, la conexión esta cerrada por defecto
	AdministradorDB()
	{
		String^ dbPath = GetRelativeDatabasePath(); //obten la ruta relativa.
		String^ connectionString = "Data Source=" + dbPath + ";Version=3;";
		dbConexion = gcnew SQLiteConnection(connectionString);
	}
	void abreConexion() {
		if (dbConexion->State == ConnectionState::Closed) {
			dbConexion->Open();
		}
	}

	void cierraConexion() {
		if (dbConexion->State == ConnectionState::Open) {
			dbConexion->Close();
		}
	}

	void creaTabla() {
		String^ sqlGranel = "CREATE TABLE IF NOT EXISTS Granel (Id INTEGER PRIMARY KEY, Nombre TEXT, Precio REAL, Cantidad REAL, Unidad TEXT)";
		SQLiteCommand^ commandGranel = gcnew SQLiteCommand(sqlGranel, dbConexion);
		commandGranel->ExecuteNonQuery();

		String^ sqlUnitario = "CREATE TABLE IF NOT EXISTS Unitario (Id INTEGER PRIMARY KEY, Nombre TEXT, Precio REAL, Cantidad INTEGER)";
		SQLiteCommand^ commandUnitario = gcnew SQLiteCommand(sqlUnitario, dbConexion);
		commandUnitario->ExecuteNonQuery();

		String^ sqlUsuarios = "CREATE TABLE IF NOT EXISTS Usuarios (Id INTEGER PRIMARY KEY, Usuario TEXT, Password TEXT, Vendedor TEXT)";
		SQLiteCommand^ commandUsuarios = gcnew SQLiteCommand(sqlUsuarios, dbConexion);
		commandUsuarios->ExecuteNonQuery();
		//Crear usuario por defecto si esta vacía:
		String^ defaultU = "SELECT COUNT(*) FROM Usuarios";
		SQLiteCommand^ comm = gcnew SQLiteCommand(defaultU, dbConexion);
		int cantidadU = Convert::ToInt32(comm->ExecuteScalar());
		if (cantidadU == 0) {
			nuevoUsuario(1, "admin", "admin", "admin");
		}
	}

	void InsertGranel(int id, String^ nombre, Decimal^ precio, Decimal^ cantidad, String^ unidad)
	{
		String^ sql = "INSERT OR REPLACE INTO Granel (Id, Nombre, Precio, Cantidad, Unidad) VALUES (@id, @nombre, @precio, @cantidad, @unidad)";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);
		command->Parameters->AddWithValue("@nombre", nombre);
		command->Parameters->AddWithValue("@precio", precio);
		command->Parameters->AddWithValue("@cantidad", cantidad);
		command->Parameters->AddWithValue("@unidad", unidad);
		command->ExecuteNonQuery();
		delete sql;
		delete command;
	}

	void InsertUnitario(int id, String^ nombre, Decimal^ precio, int cantidad)
	{
		String^ sql = "INSERT OR REPLACE INTO Unitario (Id, Nombre, Precio, Cantidad) VALUES (@id, @nombre, @precio, @cantidad)";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);
		command->Parameters->AddWithValue("@nombre", nombre);
		command->Parameters->AddWithValue("@precio", precio);
		command->Parameters->AddWithValue("@cantidad", cantidad);
		command->ExecuteNonQuery();
		delete sql;
		delete command;
	}

	//Añade un usuario usando la id del usuario
	void nuevoUsuario(int id, String^ usuario, String^ contraseña, String^ vendedor) {
		String^ sql = "INSERT OR REPLACE INTO Usuarios (Id, Usuario, Password, Vendedor) VALUES (@id, @usuario, @password, @vendedor)";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);
		command->Parameters->AddWithValue("@usuario", usuario);
		command->Parameters->AddWithValue("@password", contraseña);
		command->Parameters->AddWithValue("@vendedor", vendedor);
		command->ExecuteNonQuery();
		delete sql;
		delete command;
	}

	int obtenerUsuarioId(String^ user, String^ password) {
		String^ sql = "SELECT Id FROM Usuarios WHERE Usuario = @usuario AND Password = @password";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@usuario", user);
		command->Parameters->AddWithValue("@password", password);

		SQLiteDataReader^ lector = command->ExecuteReader();
		if (lector->Read()) {
			return lector->GetInt32(0);
		}
		else {
			return -1;
		}
		delete sql;
		delete command;
		delete lector;
	}

	String^ obtenerVendedor(int id) {
		String^ sql = "SELECT Vendedor FROM Usuarios WHERE Id = @id";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);

		SQLiteDataReader^ lector = command->ExecuteReader();
		if (lector->Read()) {
			return lector->GetString(0);
		}
		else {
			return nullptr;
		}
		delete sql;
		delete command;
		delete lector;
	}


	List<Producto^>^ LoadGranel()
	{
		String^ sql = "SELECT * FROM Granel";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		SQLiteDataReader^ reader = command->ExecuteReader();
		List<Producto^>^ productos = gcnew List<Producto^>();
		while (reader->Read())
		{
			Granel^ granel = gcnew Granel(
				reader->GetString(1),
				reader->GetInt32(0),
				reader->GetDecimal(2),
				reader->GetDecimal(3),
				reader->GetString(4)
			);
			productos->Add(granel);
		}
		reader->Close();
		return productos;
	}

	List<Producto^>^ LoadUnitario()
	{
		String^ sql = "SELECT * FROM Unitario";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		SQLiteDataReader^ reader = command->ExecuteReader();
		List<Producto^>^ productos = gcnew List<Producto^>();
		while (reader->Read())
		{
			Unitario^ unitario = gcnew Unitario(
				reader->GetString(1),
				reader->GetInt32(0),
				reader->GetDecimal(2),
				reader->GetInt32(3)
			);
			productos->Add(unitario);
		}
		reader->Close();
		return productos;
	}

	void DeleteGranel(int id)
	{
		String^ sql = "DELETE FROM Granel WHERE Id = @id";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);
		command->ExecuteNonQuery();
	}

	void DeleteUnitario(int id)
	{
		String^ sql = "DELETE FROM Unitario WHERE Id = @id";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConexion);
		command->Parameters->AddWithValue("@id", id);
		command->ExecuteNonQuery();
	}

};