#pragma once
#include "Historial.h"

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
		frm_Historial(System::Windows::Forms::Form^ formAnterior)
		{
			this->prevForm = formAnterior;
			InitializeComponent();
			this->CargarVentas();//carga la tabla 

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

	private: System::Windows::Forms::Form^ prevForm;

	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ Historial_Completo;
	private: System::Windows::Forms::TabPage^ Historial_Detalles;
	private: System::Windows::Forms::DataGridView^ TablaDetallesVenta;






	private: System::Windows::Forms::DataGridView^ TablaHistorial;





	private: System::Windows::Forms::Label^ label_totalDetalles;




	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label6;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_Historial::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Historial_Completo = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TablaHistorial = (gcnew System::Windows::Forms::DataGridView());
			this->Historial_Detalles = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_totalDetalles = (gcnew System::Windows::Forms::Label());
			this->TablaDetallesVenta = (gcnew System::Windows::Forms::DataGridView());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->Historial_Completo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaHistorial))->BeginInit();
			this->Historial_Detalles->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaDetallesVenta))->BeginInit();
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(72, 598);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 42);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Volver";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frm_Historial::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(59, 33);
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
			this->label6->Location = System::Drawing::Point(28, 198);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 56);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Sistema de Almacén\r\ny Ventas";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// Historial_Completo
			// 
			this->Historial_Completo->Controls->Add(this->label3);
			this->Historial_Completo->Controls->Add(this->TablaHistorial);
			this->Historial_Completo->Location = System::Drawing::Point(4, 33);
			this->Historial_Completo->Name = L"Historial_Completo";
			this->Historial_Completo->Padding = System::Windows::Forms::Padding(3);
			this->Historial_Completo->Size = System::Drawing::Size(704, 624);
			this->Historial_Completo->TabIndex = 0;
			this->Historial_Completo->Text = L"Historial";
			this->Historial_Completo->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Default;
			this->label3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label3->Location = System::Drawing::Point(6, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(541, 24);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Presione la celda de la izquierda para seleccionar la venta";
			// 
			// TablaHistorial
			// 
			this->TablaHistorial->AllowUserToAddRows = false;
			this->TablaHistorial->AllowUserToDeleteRows = false;
			this->TablaHistorial->AllowUserToOrderColumns = true;
			this->TablaHistorial->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->TablaHistorial->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TablaHistorial->Location = System::Drawing::Point(3, 51);
			this->TablaHistorial->Name = L"TablaHistorial";
			this->TablaHistorial->ReadOnly = true;
			this->TablaHistorial->RowHeadersWidth = 45;
			this->TablaHistorial->Size = System::Drawing::Size(701, 573);
			this->TablaHistorial->TabIndex = 0;
			this->TablaHistorial->SelectionChanged += gcnew System::EventHandler(this, &frm_Historial::TablaHistorial_SelectionChanged);
			// 
			// Historial_Detalles
			// 
			this->Historial_Detalles->Controls->Add(this->label2);
			this->Historial_Detalles->Controls->Add(this->label1);
			this->Historial_Detalles->Controls->Add(this->label_totalDetalles);
			this->Historial_Detalles->Controls->Add(this->TablaDetallesVenta);
			this->Historial_Detalles->Location = System::Drawing::Point(4, 33);
			this->Historial_Detalles->Name = L"Historial_Detalles";
			this->Historial_Detalles->Padding = System::Windows::Forms::Padding(3);
			this->Historial_Detalles->Size = System::Drawing::Size(704, 624);
			this->Historial_Detalles->TabIndex = 1;
			this->Historial_Detalles->Text = L"Detalles de ventas";
			this->Historial_Detalles->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkGray;
			this->label2->Font = (gcnew System::Drawing::Font(L"Fira Code", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(513, 568);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 26);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Total:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(622, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Aqui se muestran los detalles de la venta selecciona en el historial";
			// 
			// label_totalDetalles
			// 
			this->label_totalDetalles->AutoSize = true;
			this->label_totalDetalles->BackColor = System::Drawing::Color::DarkGray;
			this->label_totalDetalles->Font = (gcnew System::Drawing::Font(L"Fira Code", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_totalDetalles->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label_totalDetalles->Location = System::Drawing::Point(583, 568);
			this->label_totalDetalles->Name = L"label_totalDetalles";
			this->label_totalDetalles->Size = System::Drawing::Size(92, 26);
			this->label_totalDetalles->TabIndex = 3;
			this->label_totalDetalles->Text = L"S/. 0.00";
			this->label_totalDetalles->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TablaDetallesVenta
			// 
			this->TablaDetallesVenta->AllowUserToAddRows = false;
			this->TablaDetallesVenta->AllowUserToDeleteRows = false;
			this->TablaDetallesVenta->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->TablaDetallesVenta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TablaDetallesVenta->Location = System::Drawing::Point(40, 65);
			this->TablaDetallesVenta->MaximumSize = System::Drawing::Size(625, 500);
			this->TablaDetallesVenta->MinimumSize = System::Drawing::Size(625, 500);
			this->TablaDetallesVenta->Name = L"TablaDetallesVenta";
			this->TablaDetallesVenta->ReadOnly = true;
			this->TablaDetallesVenta->RowHeadersWidth = 45;
			this->TablaDetallesVenta->Size = System::Drawing::Size(625, 500);
			this->TablaDetallesVenta->TabIndex = 1;
			// 
			// frm_Historial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 659);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"frm_Historial";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frm_Historial";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_Historial::frm_Historial_FormClosing);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->Historial_Completo->ResumeLayout(false);
			this->Historial_Completo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaHistorial))->EndInit();
			this->Historial_Detalles->ResumeLayout(false);
			this->Historial_Detalles->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaDetallesVenta))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TablaHistorial_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (TablaHistorial->SelectedRows->Count > 0) {
			int ventaid = System::Convert::ToInt32(TablaHistorial->SelectedRows[0]->Cells["ID"]->Value);
			cargarDetalles(ventaid);
			tabControl1->SelectedTab = Historial_Detalles;
		}
	}
	private: void CargarVentas() {
		this->TablaHistorial->DataSource = Historial::Instance->ObtenerVentas();
		
	}
	private: void cargarDetalles(int id) {
		
		this->TablaDetallesVenta->DataSource = Historial::Instance->ObtenerDetallesVenta(id);
		

		Double total = 0.0;
		for (int i = 0; i < TablaDetallesVenta->Rows->Count; i++) {
			System::Object^ celda = TablaDetallesVenta->Rows[i]->Cells["Subtotal"]->Value;
			if (celda != nullptr) {
				double subtotal = System::Convert::ToDouble(celda);
				total += subtotal;
			}
		}
		label_totalDetalles->Text="S/. " + total;
	}
	private: System::Void frm_Historial_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (this->prevForm != nullptr) {
			prevForm->Show();
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->prevForm != nullptr) {
			prevForm->Show();
			this->Close();
		}
	}
	};
}
