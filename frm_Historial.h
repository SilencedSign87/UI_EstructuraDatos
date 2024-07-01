#pragma once
#include "frm_MenuPrincipal.h"

namespace GUIEstructuraDeDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frm_Historial
	/// </summary>
	public ref class frm_Historial : public System::Windows::Forms::Form
	{
	public:
		frm_Historial(frm_MenuPrincipal formAnterior)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frm_Historial()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ Historial_Completo;
	private: System::Windows::Forms::TabPage^ Historial_Detalles;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tablaH_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tablaH_nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tablaH_cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tablaH_subtotal;
	private: System::Windows::Forms::DataGridView^ dataGridView2;




	private: System::Windows::Forms::Label^ label_totalDetalles;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Historial_ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Historial_Comentarios;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Historial_Fecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Historial_Total;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label6;






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_Historial::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Historial_Detalles = (gcnew System::Windows::Forms::TabPage());
			this->Historial_Completo = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tablaH_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tablaH_nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tablaH_cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tablaH_subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label_totalDetalles = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Historial_ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Historial_Comentarios = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Historial_Fecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Historial_Total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->Historial_Detalles->SuspendLayout();
			this->Historial_Completo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Fira Code", 10.86792F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(1, -1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(264, 661);
			this->panel2->TabIndex = 1;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->Historial_Completo);
			this->tabControl1->Controls->Add(this->Historial_Detalles);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Fira Code", 10));
			this->tabControl1->Location = System::Drawing::Point(271, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(712, 661);
			this->tabControl1->TabIndex = 1;
			// 
			// Historial_Detalles
			// 
			this->Historial_Detalles->Controls->Add(this->label_totalDetalles);
			this->Historial_Detalles->Controls->Add(this->textBox1);
			this->Historial_Detalles->Controls->Add(this->dataGridView1);
			this->Historial_Detalles->Location = System::Drawing::Point(4, 33);
			this->Historial_Detalles->Name = L"Historial_Detalles";
			this->Historial_Detalles->Padding = System::Windows::Forms::Padding(3);
			this->Historial_Detalles->Size = System::Drawing::Size(704, 624);
			this->Historial_Detalles->TabIndex = 1;
			this->Historial_Detalles->Text = L"Detalles de ventas";
			this->Historial_Detalles->UseVisualStyleBackColor = true;
			// 
			// Historial_Completo
			// 
			this->Historial_Completo->Controls->Add(this->dataGridView2);
			this->Historial_Completo->Location = System::Drawing::Point(4, 33);
			this->Historial_Completo->Name = L"Historial_Completo";
			this->Historial_Completo->Padding = System::Windows::Forms::Padding(3);
			this->Historial_Completo->Size = System::Drawing::Size(704, 624);
			this->Historial_Completo->TabIndex = 0;
			this->Historial_Completo->Text = L"Historial";
			this->Historial_Completo->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->tablaH_id,
					this->tablaH_nombre, this->tablaH_cantidad, this->tablaH_subtotal
			});
			this->dataGridView1->Location = System::Drawing::Point(38, 69);
			this->dataGridView1->MaximumSize = System::Drawing::Size(625, 500);
			this->dataGridView1->MinimumSize = System::Drawing::Size(625, 500);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 45;
			this->dataGridView1->Size = System::Drawing::Size(625, 500);
			this->dataGridView1->TabIndex = 1;
			// 
			// tablaH_id
			// 
			this->tablaH_id->HeaderText = L"ID";
			this->tablaH_id->MinimumWidth = 6;
			this->tablaH_id->Name = L"tablaH_id";
			this->tablaH_id->ReadOnly = true;
			this->tablaH_id->Width = 110;
			// 
			// tablaH_nombre
			// 
			this->tablaH_nombre->HeaderText = L"Nombre";
			this->tablaH_nombre->MinimumWidth = 6;
			this->tablaH_nombre->Name = L"tablaH_nombre";
			this->tablaH_nombre->ReadOnly = true;
			this->tablaH_nombre->Width = 240;
			// 
			// tablaH_cantidad
			// 
			this->tablaH_cantidad->HeaderText = L"Cantidad";
			this->tablaH_cantidad->MinimumWidth = 6;
			this->tablaH_cantidad->Name = L"tablaH_cantidad";
			this->tablaH_cantidad->ReadOnly = true;
			this->tablaH_cantidad->Width = 117;
			// 
			// tablaH_subtotal
			// 
			this->tablaH_subtotal->HeaderText = L"SubTotal";
			this->tablaH_subtotal->MinimumWidth = 6;
			this->tablaH_subtotal->Name = L"tablaH_subtotal";
			this->tablaH_subtotal->ReadOnly = true;
			this->tablaH_subtotal->Width = 110;
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->Location = System::Drawing::Point(38, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(395, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Ingrese la ID de la venta";
			// 
			// label_totalDetalles
			// 
			this->label_totalDetalles->AutoSize = true;
			this->label_totalDetalles->Location = System::Drawing::Point(514, 583);
			this->label_totalDetalles->Name = L"label_totalDetalles";
			this->label_totalDetalles->Size = System::Drawing::Size(145, 24);
			this->label_totalDetalles->TabIndex = 3;
			this->label_totalDetalles->Text = L"Total: S/. 0.00";
			this->label_totalDetalles->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Historial_ID,
					this->Historial_Comentarios, this->Historial_Fecha, this->Historial_Total
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(3, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 45;
			this->dataGridView2->Size = System::Drawing::Size(698, 618);
			this->dataGridView2->TabIndex = 0;
			// 
			// Historial_ID
			// 
			this->Historial_ID->HeaderText = L"ID";
			this->Historial_ID->MinimumWidth = 6;
			this->Historial_ID->Name = L"Historial_ID";
			this->Historial_ID->ReadOnly = true;
			this->Historial_ID->Width = 110;
			// 
			// Historial_Comentarios
			// 
			this->Historial_Comentarios->HeaderText = L"Comentarios";
			this->Historial_Comentarios->MinimumWidth = 6;
			this->Historial_Comentarios->Name = L"Historial_Comentarios";
			this->Historial_Comentarios->ReadOnly = true;
			this->Historial_Comentarios->Width = 250;
			// 
			// Historial_Fecha
			// 
			this->Historial_Fecha->HeaderText = L"Fecha";
			this->Historial_Fecha->MinimumWidth = 6;
			this->Historial_Fecha->Name = L"Historial_Fecha";
			this->Historial_Fecha->ReadOnly = true;
			this->Historial_Fecha->Width = 110;
			// 
			// Historial_Total
			// 
			this->Historial_Total->HeaderText = L"Total";
			this->Historial_Total->MinimumWidth = 6;
			this->Historial_Total->Name = L"Historial_Total";
			this->Historial_Total->ReadOnly = true;
			this->Historial_Total->Width = 110;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(49, 33);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 150);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(21, 191);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 56);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Sistema de Almacén\r\ny Ventas";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(72, 598);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 42);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Volver";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// frm_Historial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 659);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->tabControl1);
			this->Name = L"frm_Historial";
			this->Text = L"frm_Historial";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->Historial_Detalles->ResumeLayout(false);
			this->Historial_Detalles->PerformLayout();
			this->Historial_Completo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
