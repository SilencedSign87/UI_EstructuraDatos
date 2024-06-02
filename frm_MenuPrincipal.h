#pragma once
#include "frm_CambiarCred.h"

namespace GUIEstructuraDeDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frm_MenuPrincipal
	/// </summary>
	public ref class frm_MenuPrincipal : public System::Windows::Forms::Form
	{
	public:

		frm_MenuPrincipal(System::Windows::Forms::Form^ previousForm) //para el puntero al form anterior
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->previousForm = previousForm;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frm_MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ previousForm; //form anterior

	private: System::Windows::Forms::TabControl^ tab_Control;
	private: System::Windows::Forms::TabPage^ tab_Registro;
	private: System::Windows::Forms::TabPage^ tab_Lista;

	protected:

	protected:


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ es_Unitario;
	private: System::Windows::Forms::RadioButton^ es_Granel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bttn_CambiarCredenciales;
	private: System::Windows::Forms::TextBox^ txt_Unidad;


	private: System::Windows::Forms::Label^ label_unidad;

	private: System::Windows::Forms::TextBox^ txt_Precio;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_CantProd;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_prodName;
	private: System::Windows::Forms::Button^ bttn_Registrar;


	private: System::Windows::Forms::Button^ bttn_Borrar;
	private: System::Windows::Forms::TabPage^ tab_venta;
	private: System::Windows::Forms::TextBox^ txt_busqueda;
	private: System::Windows::Forms::ListBox^ list_busqueda;





	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_MenuPrincipal::typeid));
			this->tab_Control = (gcnew System::Windows::Forms::TabControl());
			this->tab_venta = (gcnew System::Windows::Forms::TabPage());
			this->list_busqueda = (gcnew System::Windows::Forms::ListBox());
			this->txt_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->tab_Lista = (gcnew System::Windows::Forms::TabPage());
			this->tab_Registro = (gcnew System::Windows::Forms::TabPage());
			this->bttn_Borrar = (gcnew System::Windows::Forms::Button());
			this->bttn_Registrar = (gcnew System::Windows::Forms::Button());
			this->txt_Unidad = (gcnew System::Windows::Forms::TextBox());
			this->label_unidad = (gcnew System::Windows::Forms::Label());
			this->txt_Precio = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_CantProd = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_prodName = (gcnew System::Windows::Forms::TextBox());
			this->es_Unitario = (gcnew System::Windows::Forms::RadioButton());
			this->es_Granel = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bttn_CambiarCredenciales = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tab_Control->SuspendLayout();
			this->tab_venta->SuspendLayout();
			this->tab_Registro->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tab_Control
			// 
			this->tab_Control->Controls->Add(this->tab_venta);
			this->tab_Control->Controls->Add(this->tab_Lista);
			this->tab_Control->Controls->Add(this->tab_Registro);
			this->tab_Control->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tab_Control->Location = System::Drawing::Point(256, 1);
			this->tab_Control->Name = L"tab_Control";
			this->tab_Control->SelectedIndex = 0;
			this->tab_Control->Size = System::Drawing::Size(629, 567);
			this->tab_Control->TabIndex = 0;
			// 
			// tab_venta
			// 
			this->tab_venta->Controls->Add(this->list_busqueda);
			this->tab_venta->Controls->Add(this->txt_busqueda);
			this->tab_venta->Location = System::Drawing::Point(4, 34);
			this->tab_venta->Name = L"tab_venta";
			this->tab_venta->Size = System::Drawing::Size(621, 529);
			this->tab_venta->TabIndex = 2;
			this->tab_venta->Text = L"Venta";
			this->tab_venta->UseVisualStyleBackColor = true;
			// 
			// list_busqueda
			// 
			this->list_busqueda->FormattingEnabled = true;
			this->list_busqueda->ItemHeight = 25;
			this->list_busqueda->Location = System::Drawing::Point(23, 54);
			this->list_busqueda->Name = L"list_busqueda";
			this->list_busqueda->Size = System::Drawing::Size(407, 104);
			this->list_busqueda->TabIndex = 1;
			// 
			// txt_busqueda
			// 
			this->txt_busqueda->ForeColor = System::Drawing::Color::Silver;
			this->txt_busqueda->Location = System::Drawing::Point(23, 19);
			this->txt_busqueda->Name = L"txt_busqueda";
			this->txt_busqueda->Size = System::Drawing::Size(407, 28);
			this->txt_busqueda->TabIndex = 0;
			this->txt_busqueda->Text = L"Ingrese el nombre del producto...";
			this->txt_busqueda->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::txt_busqueda_Click);
			this->txt_busqueda->TextChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::txt_busqueda_TextChanged);
			// 
			// tab_Lista
			// 
			this->tab_Lista->Location = System::Drawing::Point(4, 34);
			this->tab_Lista->Name = L"tab_Lista";
			this->tab_Lista->Padding = System::Windows::Forms::Padding(3);
			this->tab_Lista->Size = System::Drawing::Size(621, 529);
			this->tab_Lista->TabIndex = 1;
			this->tab_Lista->Text = L"Lista";
			this->tab_Lista->UseVisualStyleBackColor = true;
			// 
			// tab_Registro
			// 
			this->tab_Registro->Controls->Add(this->bttn_Borrar);
			this->tab_Registro->Controls->Add(this->bttn_Registrar);
			this->tab_Registro->Controls->Add(this->txt_Unidad);
			this->tab_Registro->Controls->Add(this->label_unidad);
			this->tab_Registro->Controls->Add(this->txt_Precio);
			this->tab_Registro->Controls->Add(this->label4);
			this->tab_Registro->Controls->Add(this->txt_CantProd);
			this->tab_Registro->Controls->Add(this->label3);
			this->tab_Registro->Controls->Add(this->label2);
			this->tab_Registro->Controls->Add(this->txt_prodName);
			this->tab_Registro->Controls->Add(this->es_Unitario);
			this->tab_Registro->Controls->Add(this->es_Granel);
			this->tab_Registro->Location = System::Drawing::Point(4, 34);
			this->tab_Registro->Name = L"tab_Registro";
			this->tab_Registro->Padding = System::Windows::Forms::Padding(3);
			this->tab_Registro->Size = System::Drawing::Size(621, 529);
			this->tab_Registro->TabIndex = 0;
			this->tab_Registro->Text = L"Registro";
			this->tab_Registro->UseVisualStyleBackColor = true;
			// 
			// bttn_Borrar
			// 
			this->bttn_Borrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bttn_Borrar->Location = System::Drawing::Point(310, 418);
			this->bttn_Borrar->Name = L"bttn_Borrar";
			this->bttn_Borrar->Size = System::Drawing::Size(110, 40);
			this->bttn_Borrar->TabIndex = 11;
			this->bttn_Borrar->Text = L"Borrar";
			this->bttn_Borrar->UseVisualStyleBackColor = false;
			this->bttn_Borrar->Visible = false;
			this->bttn_Borrar->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_Borrar_Click);
			// 
			// bttn_Registrar
			// 
			this->bttn_Registrar->Location = System::Drawing::Point(175, 418);
			this->bttn_Registrar->Name = L"bttn_Registrar";
			this->bttn_Registrar->Size = System::Drawing::Size(110, 40);
			this->bttn_Registrar->TabIndex = 10;
			this->bttn_Registrar->Text = L"Registrar";
			this->bttn_Registrar->UseVisualStyleBackColor = true;
			this->bttn_Registrar->Visible = false;
			// 
			// txt_Unidad
			// 
			this->txt_Unidad->Location = System::Drawing::Point(107, 354);
			this->txt_Unidad->Name = L"txt_Unidad";
			this->txt_Unidad->Size = System::Drawing::Size(382, 28);
			this->txt_Unidad->TabIndex = 9;
			this->txt_Unidad->Visible = false;
			// 
			// label_unidad
			// 
			this->label_unidad->AutoSize = true;
			this->label_unidad->Location = System::Drawing::Point(107, 324);
			this->label_unidad->Name = L"label_unidad";
			this->label_unidad->Size = System::Drawing::Size(362, 25);
			this->label_unidad->TabIndex = 8;
			this->label_unidad->Text = L"Unidad del producto: (Kg, g, L, mL)";
			this->label_unidad->Visible = false;
			// 
			// txt_Precio
			// 
			this->txt_Precio->Location = System::Drawing::Point(107, 284);
			this->txt_Precio->Name = L"txt_Precio";
			this->txt_Precio->Size = System::Drawing::Size(382, 28);
			this->txt_Precio->TabIndex = 7;
			this->txt_Precio->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(107, 254);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Precio:";
			this->label4->Visible = false;
			// 
			// txt_CantProd
			// 
			this->txt_CantProd->Location = System::Drawing::Point(107, 214);
			this->txt_CantProd->Name = L"txt_CantProd";
			this->txt_CantProd->Size = System::Drawing::Size(387, 28);
			this->txt_CantProd->TabIndex = 5;
			this->txt_CantProd->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(107, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(292, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Cantidad total del producto:";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(107, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(212, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nombre del producto:";
			this->label2->Visible = false;
			// 
			// txt_prodName
			// 
			this->txt_prodName->Location = System::Drawing::Point(107, 144);
			this->txt_prodName->Name = L"txt_prodName";
			this->txt_prodName->Size = System::Drawing::Size(387, 28);
			this->txt_prodName->TabIndex = 2;
			this->txt_prodName->Visible = false;
			// 
			// es_Unitario
			// 
			this->es_Unitario->AutoSize = true;
			this->es_Unitario->Location = System::Drawing::Point(300, 42);
			this->es_Unitario->Name = L"es_Unitario";
			this->es_Unitario->Size = System::Drawing::Size(200, 29);
			this->es_Unitario->TabIndex = 1;
			this->es_Unitario->Text = L"Producto Unitario";
			this->es_Unitario->UseVisualStyleBackColor = true;
			this->es_Unitario->CheckedChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::es_Unitario_CheckedChanged);
			// 
			// es_Granel
			// 
			this->es_Granel->AutoSize = true;
			this->es_Granel->Checked = true;
			this->es_Granel->Location = System::Drawing::Point(113, 42);
			this->es_Granel->Name = L"es_Granel";
			this->es_Granel->Size = System::Drawing::Size(180, 29);
			this->es_Granel->TabIndex = 0;
			this->es_Granel->TabStop = true;
			this->es_Granel->Text = L"Producto Granel";
			this->es_Granel->UseVisualStyleBackColor = true;
			this->es_Granel->CheckedChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::es_Granel_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel1->Controls->Add(this->bttn_CambiarCredenciales);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(253, 567);
			this->panel1->TabIndex = 1;
			// 
			// bttn_CambiarCredenciales
			// 
			this->bttn_CambiarCredenciales->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_CambiarCredenciales->Location = System::Drawing::Point(47, 155);
			this->bttn_CambiarCredenciales->Name = L"bttn_CambiarCredenciales";
			this->bttn_CambiarCredenciales->Size = System::Drawing::Size(156, 64);
			this->bttn_CambiarCredenciales->TabIndex = 1;
			this->bttn_CambiarCredenciales->Text = L"Cambiar Credenciales";
			this->bttn_CambiarCredenciales->UseVisualStyleBackColor = true;
			this->bttn_CambiarCredenciales->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_CambiarCredenciales_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(60, 8);
			this->label1->MinimumSize = System::Drawing::Size(125, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 125);
			this->label1->TabIndex = 0;
			// 
			// frm_MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tab_Control);
			this->MaximumSize = System::Drawing::Size(900, 600);
			this->MinimumSize = System::Drawing::Size(900, 600);
			this->Name = L"frm_MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frm_MenuPrincipal";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_MenuPrincipal::frm_MenuPrincipal_FormClosing);
			this->tab_Control->ResumeLayout(false);
			this->tab_venta->ResumeLayout(false);
			this->tab_venta->PerformLayout();
			this->tab_Registro->ResumeLayout(false);
			this->tab_Registro->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void es_Unitario_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		label2->Visible = true;
		txt_prodName->Visible = true;

		label3->Visible = true;
		txt_Precio->Visible = true;

		label4->Visible = true;
		txt_CantProd->Visible = true;

		label_unidad->Visible = false;
		txt_Unidad->Visible = false;

		bttn_Borrar->Visible = true;
		bttn_Registrar->Visible = true;
	}
	private: System::Void es_Granel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		label2->Visible = true;
		txt_prodName->Visible = true;

		label3->Visible = true;
		txt_Precio->Visible = true;

		label4->Visible = true;
		txt_CantProd->Visible = true;

		label_unidad->Visible = true;
		txt_Unidad->Visible = true;

		bttn_Borrar->Visible = true;
		bttn_Registrar->Visible = true;
	}
	private: System::Void frm_MenuPrincipal_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) { //si presiona la "x"
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
		}
	}
	private: System::Void bttn_Borrar_Click(System::Object^ sender, System::EventArgs^ e) {
		txt_CantProd->Text = "";
		txt_Precio->Text = "";
		txt_prodName->Text = "";
		txt_Unidad->Text = "";
	}
	private: System::Void bttn_CambiarCredenciales_Click(System::Object^ sender, System::EventArgs^ e) {
		frm_CambiarCred^ cambiarCredencial = gcnew frm_CambiarCred(this);
		cambiarCredencial->Show();
		this->Hide();
	}

	private: System::Void txt_busqueda_TextChanged(System::Object^ sender, System::EventArgs^ e) { //cuando el texto cambia

	}
	private: System::Void txt_busqueda_Click(System::Object^ sender, System::EventArgs^ e)
	{
		txt_busqueda->Text = "";
		txt_busqueda->ForeColor = System::Drawing::Color::Black;
	}
	};
}
