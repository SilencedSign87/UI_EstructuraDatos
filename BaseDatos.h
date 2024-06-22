#pragma once
#include "Datos.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

public ref class AdministradorDB {
private:
	SQLiteConnection^ dbConexion;
public:
	AdministradorDB(String^ dbPath)
	{
		String^ connectionString = "Data Source=" + dbPath + ";Version=3;";
		dbConexion = gcnew SQLiteConnection(connectionString);
	}
	void abreConexion() {
		dbConexion->Open();
	}

	void cierraConexion() {
		dbConexion->Close();
	}

	void creaTabla() {
		String^ sqlGranel = "CREATE TABLE IF NOT EXISTS Granel (Id INTEGER PRIMARY KEY, Nombre TEXT, Precio REAL, Cantidad REAL, Unidad TEXT)";
		SQLiteCommand^ commandGranel = gcnew SQLiteCommand(sqlGranel, dbConexion);
		commandGranel->ExecuteNonQuery();

		String^ sqlUnitario = "CREATE TABLE IF NOT EXISTS Unitario (Id INTEGER PRIMARY KEY, Nombre TEXT, Precio REAL, Cantidad INTEGER)";
		SQLiteCommand^ commandUnitario = gcnew SQLiteCommand(sqlUnitario, dbConexion);
		commandUnitario->ExecuteNonQuery();
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