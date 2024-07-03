#pragma once
#include "Datos.h"

namespace GUIEstructuraDeDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frm_NuevoVendedor
	/// </summary>
	public ref class frm_NuevoVendedor : public System::Windows::Forms::Form
	{
	public:
		frm_NuevoVendedor(System::Windows::Forms::Form^ prevForm)
		{
			InitializeComponent();

			this->prevForm = prevForm;
		}
	private: System::Windows::Forms::Form^ prevForm;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frm_NuevoVendedor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ bttn_salir;
	private: System::Windows::Forms::Button^ bttn_CambiarCredenciales;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tab_nuevoV;
	private: System::Windows::Forms::TabPage^ tab_listaV;
	private: System::Windows::Forms::DataGridView^ Tabla_vendedores;
	private: System::Windows::Forms::Label^ label1;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_NuevoVendedor::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bttn_salir = (gcnew System::Windows::Forms::Button());
			this->bttn_CambiarCredenciales = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tab_nuevoV = (gcnew System::Windows::Forms::TabPage());
			this->tab_listaV = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Tabla_vendedores = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tab_listaV->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_vendedores))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(48, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 150);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(20, 192);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 56);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Sistema de Almacén\r\ny Ventas";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->bttn_salir);
			this->panel1->Controls->Add(this->bttn_CambiarCredenciales);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(253, 657);
			this->panel1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 307);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 45);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Registrar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// bttn_salir
			// 
			this->bttn_salir->Location = System::Drawing::Point(47, 585);
			this->bttn_salir->Name = L"bttn_salir";
			this->bttn_salir->Size = System::Drawing::Size(156, 43);
			this->bttn_salir->TabIndex = 2;
			this->bttn_salir->Text = L"Cerrar Sesión";
			this->bttn_salir->UseVisualStyleBackColor = true;
			this->bttn_salir->Click += gcnew System::EventHandler(this, &frm_NuevoVendedor::bttn_salir_Click);
			// 
			// bttn_CambiarCredenciales
			// 
			this->bttn_CambiarCredenciales->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_CambiarCredenciales->Location = System::Drawing::Point(48, 391);
			this->bttn_CambiarCredenciales->Name = L"bttn_CambiarCredenciales";
			this->bttn_CambiarCredenciales->Size = System::Drawing::Size(156, 39);
			this->bttn_CambiarCredenciales->TabIndex = 1;
			this->bttn_CambiarCredenciales->Text = L"Cancelar";
			this->bttn_CambiarCredenciales->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tab_nuevoV);
			this->tabControl1->Controls->Add(this->tab_listaV);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Fira Code", 11));
			this->tabControl1->Location = System::Drawing::Point(261, 1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(722, 657);
			this->tabControl1->TabIndex = 3;
			// 
			// tab_nuevoV
			// 
			this->tab_nuevoV->Location = System::Drawing::Point(4, 34);
			this->tab_nuevoV->Name = L"tab_nuevoV";
			this->tab_nuevoV->Padding = System::Windows::Forms::Padding(3);
			this->tab_nuevoV->Size = System::Drawing::Size(714, 619);
			this->tab_nuevoV->TabIndex = 0;
			this->tab_nuevoV->Text = L"Registrar nuevo vendedor";
			this->tab_nuevoV->UseVisualStyleBackColor = true;
			// 
			// tab_listaV
			// 
			this->tab_listaV->Controls->Add(this->label1);
			this->tab_listaV->Controls->Add(this->Tabla_vendedores);
			this->tab_listaV->Location = System::Drawing::Point(4, 34);
			this->tab_listaV->Name = L"tab_listaV";
			this->tab_listaV->Padding = System::Windows::Forms::Padding(3);
			this->tab_listaV->Size = System::Drawing::Size(714, 619);
			this->tab_listaV->TabIndex = 1;
			this->tab_listaV->Text = L"Lista de vendedores";
			this->tab_listaV->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(16, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(492, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"A continuación se muestra la lista de vendedores";
			// 
			// Tabla_vendedores
			// 
			this->Tabla_vendedores->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->Tabla_vendedores->ColumnHeadersHeight = 25;
			this->Tabla_vendedores->Location = System::Drawing::Point(6, 67);
			this->Tabla_vendedores->Name = L"Tabla_vendedores";
			this->Tabla_vendedores->RowHeadersWidth = 45;
			this->Tabla_vendedores->Size = System::Drawing::Size(701, 493);
			this->Tabla_vendedores->TabIndex = 0;
			// 
			// frm_NuevoVendedor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 659);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1000, 700);
			this->Name = L"frm_NuevoVendedor";
			this->Text = L"Gestion de Vendedores";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tab_listaV->ResumeLayout(false);
			this->tab_listaV->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_vendedores))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bttn_salir_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->prevForm != nullptr) {
			prevForm->Show();
			this->Close();
		}
	}
};
}
