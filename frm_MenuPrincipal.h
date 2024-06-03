#pragma once
#include "frm_CambiarCred.h"
#include "Datos.h"
#include "Granel.hpp"
#include "Unitario.hpp"

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



	private: System::Windows::Forms::Label^ label_unidad;


	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_prodName;
	private: System::Windows::Forms::Button^ bttn_Registrar;


	private: System::Windows::Forms::Button^ bttn_Borrar;
	private: System::Windows::Forms::TabPage^ tab_venta;
	private: System::Windows::Forms::TextBox^ txt_busqueda;
	private: System::Windows::Forms::ListBox^ list_busqueda;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ bttn_añadir2Lista;









	private: System::Windows::Forms::Button^ bttn_salir;
	private: System::Windows::Forms::Button^ bttn_cancelaVenta;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ bttn_realizaVenta;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_precio;
	private: System::Windows::Forms::DataGridView^ Tabla_productos;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ incrementador_precio;

	private: System::Windows::Forms::NumericUpDown^ incrementador_cantidad;
	private: System::Windows::Forms::DomainUpDown^ seleccionador_unidad;
	private: System::Windows::Forms::Label^ L_unidad;
	private: System::Windows::Forms::Label^ L_unidadPrecio;
	private: System::Windows::Forms::Button^ bttn_cancelarCambios;

	private: System::Windows::Forms::Button^ bttn_actualizarDatosTabla;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_Cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_precio;











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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->bttn_cancelaVenta = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bttn_realizaVenta = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->c_nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_precio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bttn_añadir2Lista = (gcnew System::Windows::Forms::Button());
			this->list_busqueda = (gcnew System::Windows::Forms::ListBox());
			this->txt_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->tab_Lista = (gcnew System::Windows::Forms::TabPage());
			this->Tabla_productos = (gcnew System::Windows::Forms::DataGridView());
			this->tab_Registro = (gcnew System::Windows::Forms::TabPage());
			this->L_unidadPrecio = (gcnew System::Windows::Forms::Label());
			this->L_unidad = (gcnew System::Windows::Forms::Label());
			this->seleccionador_unidad = (gcnew System::Windows::Forms::DomainUpDown());
			this->incrementador_precio = (gcnew System::Windows::Forms::NumericUpDown());
			this->incrementador_cantidad = (gcnew System::Windows::Forms::NumericUpDown());
			this->bttn_Borrar = (gcnew System::Windows::Forms::Button());
			this->bttn_Registrar = (gcnew System::Windows::Forms::Button());
			this->label_unidad = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_prodName = (gcnew System::Windows::Forms::TextBox());
			this->es_Unitario = (gcnew System::Windows::Forms::RadioButton());
			this->es_Granel = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->bttn_salir = (gcnew System::Windows::Forms::Button());
			this->bttn_CambiarCredenciales = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bttn_actualizarDatosTabla = (gcnew System::Windows::Forms::Button());
			this->bttn_cancelarCambios = (gcnew System::Windows::Forms::Button());
			this->data_nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_precio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tab_Control->SuspendLayout();
			this->tab_venta->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tab_Lista->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_productos))->BeginInit();
			this->tab_Registro->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_precio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_cantidad))->BeginInit();
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
			this->tab_Control->Location = System::Drawing::Point(341, 1);
			this->tab_Control->Margin = System::Windows::Forms::Padding(4);
			this->tab_Control->Name = L"tab_Control";
			this->tab_Control->SelectedIndex = 0;
			this->tab_Control->Size = System::Drawing::Size(839, 809);
			this->tab_Control->TabIndex = 0;
			this->tab_Control->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::tab_Control_SelectedIndexChanged);
			// 
			// tab_venta
			// 
			this->tab_venta->Controls->Add(this->numericUpDown1);
			this->tab_venta->Controls->Add(this->bttn_cancelaVenta);
			this->tab_venta->Controls->Add(this->label5);
			this->tab_venta->Controls->Add(this->bttn_realizaVenta);
			this->tab_venta->Controls->Add(this->dataGridView1);
			this->tab_venta->Controls->Add(this->bttn_añadir2Lista);
			this->tab_venta->Controls->Add(this->list_busqueda);
			this->tab_venta->Controls->Add(this->txt_busqueda);
			this->tab_venta->Location = System::Drawing::Point(4, 34);
			this->tab_venta->Margin = System::Windows::Forms::Padding(4);
			this->tab_venta->Name = L"tab_venta";
			this->tab_venta->Size = System::Drawing::Size(831, 771);
			this->tab_venta->TabIndex = 2;
			this->tab_venta->Text = L"Venta";
			this->tab_venta->UseVisualStyleBackColor = true;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown1->Location = System::Drawing::Point(683, 687);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(141, 28);
			this->numericUpDown1->TabIndex = 7;
			// 
			// bttn_cancelaVenta
			// 
			this->bttn_cancelaVenta->BackColor = System::Drawing::Color::Red;
			this->bttn_cancelaVenta->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bttn_cancelaVenta->Location = System::Drawing::Point(31, 678);
			this->bttn_cancelaVenta->Margin = System::Windows::Forms::Padding(4);
			this->bttn_cancelaVenta->Name = L"bttn_cancelaVenta";
			this->bttn_cancelaVenta->Size = System::Drawing::Size(123, 53);
			this->bttn_cancelaVenta->TabIndex = 6;
			this->bttn_cancelaVenta->Text = L"Borrar";
			this->bttn_cancelaVenta->UseVisualStyleBackColor = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(443, 689);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(182, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Precio final: S/.";
			// 
			// bttn_realizaVenta
			// 
			this->bttn_realizaVenta->Location = System::Drawing::Point(183, 678);
			this->bttn_realizaVenta->Margin = System::Windows::Forms::Padding(4);
			this->bttn_realizaVenta->Name = L"bttn_realizaVenta";
			this->bttn_realizaVenta->Size = System::Drawing::Size(252, 53);
			this->bttn_realizaVenta->TabIndex = 2;
			this->bttn_realizaVenta->Text = L"Realizar venta";
			this->bttn_realizaVenta->UseVisualStyleBackColor = true;
			this->bttn_realizaVenta->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_realizaVenta_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->c_nombre,
					this->c_id, this->c_cantidad, this->c_precio
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 188);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(820, 427);
			this->dataGridView1->TabIndex = 4;
			// 
			// c_nombre
			// 
			this->c_nombre->HeaderText = L"Nombre";
			this->c_nombre->MinimumWidth = 6;
			this->c_nombre->Name = L"c_nombre";
			this->c_nombre->ReadOnly = true;
			this->c_nombre->Width = 300;
			// 
			// c_id
			// 
			this->c_id->HeaderText = L"ID";
			this->c_id->MinimumWidth = 6;
			this->c_id->Name = L"c_id";
			this->c_id->ReadOnly = true;
			this->c_id->Width = 50;
			// 
			// c_cantidad
			// 
			this->c_cantidad->HeaderText = L"Cantidad";
			this->c_cantidad->MinimumWidth = 6;
			this->c_cantidad->Name = L"c_cantidad";
			this->c_cantidad->Width = 125;
			// 
			// c_precio
			// 
			this->c_precio->HeaderText = L"Sub total";
			this->c_precio->MinimumWidth = 6;
			this->c_precio->Name = L"c_precio";
			this->c_precio->ReadOnly = true;
			this->c_precio->Width = 125;
			// 
			// bttn_añadir2Lista
			// 
			this->bttn_añadir2Lista->Location = System::Drawing::Point(599, 66);
			this->bttn_añadir2Lista->Margin = System::Windows::Forms::Padding(4);
			this->bttn_añadir2Lista->Name = L"bttn_añadir2Lista";
			this->bttn_añadir2Lista->Size = System::Drawing::Size(205, 73);
			this->bttn_añadir2Lista->TabIndex = 3;
			this->bttn_añadir2Lista->Text = L"Añadir a la lista";
			this->bttn_añadir2Lista->UseVisualStyleBackColor = true;
			// 
			// list_busqueda
			// 
			this->list_busqueda->FormattingEnabled = true;
			this->list_busqueda->ItemHeight = 25;
			this->list_busqueda->Location = System::Drawing::Point(31, 66);
			this->list_busqueda->Margin = System::Windows::Forms::Padding(4);
			this->list_busqueda->Name = L"list_busqueda";
			this->list_busqueda->Size = System::Drawing::Size(541, 79);
			this->list_busqueda->TabIndex = 1;
			// 
			// txt_busqueda
			// 
			this->txt_busqueda->ForeColor = System::Drawing::Color::Silver;
			this->txt_busqueda->Location = System::Drawing::Point(31, 23);
			this->txt_busqueda->Margin = System::Windows::Forms::Padding(4);
			this->txt_busqueda->Name = L"txt_busqueda";
			this->txt_busqueda->Size = System::Drawing::Size(541, 28);
			this->txt_busqueda->TabIndex = 0;
			this->txt_busqueda->Text = L"Ingrese el nombre del producto...";
			this->txt_busqueda->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::txt_busqueda_Click);
			this->txt_busqueda->TextChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::txt_busqueda_TextChanged);
			// 
			// tab_Lista
			// 
			this->tab_Lista->Controls->Add(this->label7);
			this->tab_Lista->Controls->Add(this->bttn_cancelarCambios);
			this->tab_Lista->Controls->Add(this->bttn_actualizarDatosTabla);
			this->tab_Lista->Controls->Add(this->Tabla_productos);
			this->tab_Lista->Location = System::Drawing::Point(4, 34);
			this->tab_Lista->Margin = System::Windows::Forms::Padding(4);
			this->tab_Lista->Name = L"tab_Lista";
			this->tab_Lista->Padding = System::Windows::Forms::Padding(4);
			this->tab_Lista->Size = System::Drawing::Size(831, 771);
			this->tab_Lista->TabIndex = 1;
			this->tab_Lista->Text = L"Lista";
			this->tab_Lista->UseVisualStyleBackColor = true;
			// 
			// Tabla_productos
			// 
			this->Tabla_productos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Tabla_productos->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Tabla_productos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla_productos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->data_nombre,
					this->data_ID, this->data_Cantidad, this->data_precio
			});
			this->Tabla_productos->Location = System::Drawing::Point(8, 72);
			this->Tabla_productos->Margin = System::Windows::Forms::Padding(4);
			this->Tabla_productos->Name = L"Tabla_productos";
			this->Tabla_productos->RowHeadersWidth = 51;
			this->Tabla_productos->Size = System::Drawing::Size(812, 618);
			this->Tabla_productos->TabIndex = 0;
			// 
			// tab_Registro
			// 
			this->tab_Registro->Controls->Add(this->L_unidadPrecio);
			this->tab_Registro->Controls->Add(this->L_unidad);
			this->tab_Registro->Controls->Add(this->seleccionador_unidad);
			this->tab_Registro->Controls->Add(this->incrementador_precio);
			this->tab_Registro->Controls->Add(this->incrementador_cantidad);
			this->tab_Registro->Controls->Add(this->bttn_Borrar);
			this->tab_Registro->Controls->Add(this->bttn_Registrar);
			this->tab_Registro->Controls->Add(this->label_unidad);
			this->tab_Registro->Controls->Add(this->label4);
			this->tab_Registro->Controls->Add(this->label3);
			this->tab_Registro->Controls->Add(this->label2);
			this->tab_Registro->Controls->Add(this->txt_prodName);
			this->tab_Registro->Controls->Add(this->es_Unitario);
			this->tab_Registro->Controls->Add(this->es_Granel);
			this->tab_Registro->Location = System::Drawing::Point(4, 34);
			this->tab_Registro->Margin = System::Windows::Forms::Padding(4);
			this->tab_Registro->Name = L"tab_Registro";
			this->tab_Registro->Padding = System::Windows::Forms::Padding(4);
			this->tab_Registro->Size = System::Drawing::Size(831, 771);
			this->tab_Registro->TabIndex = 0;
			this->tab_Registro->Text = L"Registro";
			this->tab_Registro->UseVisualStyleBackColor = true;
			// 
			// L_unidadPrecio
			// 
			this->L_unidadPrecio->AutoSize = true;
			this->L_unidadPrecio->Location = System::Drawing::Point(580, 350);
			this->L_unidadPrecio->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->L_unidadPrecio->Name = L"L_unidadPrecio";
			this->L_unidadPrecio->Size = System::Drawing::Size(0, 25);
			this->L_unidadPrecio->TabIndex = 16;
			// 
			// L_unidad
			// 
			this->L_unidad->AutoSize = true;
			this->L_unidad->Location = System::Drawing::Point(573, 265);
			this->L_unidad->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->L_unidad->Name = L"L_unidad";
			this->L_unidad->Size = System::Drawing::Size(0, 25);
			this->L_unidad->TabIndex = 15;
			// 
			// seleccionador_unidad
			// 
			this->seleccionador_unidad->Items->Add(L"Kilogramo\t");
			this->seleccionador_unidad->Items->Add(L"Gramo");
			this->seleccionador_unidad->Items->Add(L"Litro");
			this->seleccionador_unidad->Items->Add(L"Mililitro");
			this->seleccionador_unidad->Location = System::Drawing::Point(143, 436);
			this->seleccionador_unidad->Margin = System::Windows::Forms::Padding(4);
			this->seleccionador_unidad->Name = L"seleccionador_unidad";
			this->seleccionador_unidad->Size = System::Drawing::Size(368, 28);
			this->seleccionador_unidad->TabIndex = 14;
			this->seleccionador_unidad->Text = L"Seleccione una unidad...";
			this->seleccionador_unidad->Visible = false;
			this->seleccionador_unidad->Wrap = true;
			this->seleccionador_unidad->SelectedItemChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::seleccionador_unidad_SelectedItemChanged);
			// 
			// incrementador_precio
			// 
			this->incrementador_precio->DecimalPlaces = 1;
			this->incrementador_precio->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->incrementador_precio->Location = System::Drawing::Point(143, 350);
			this->incrementador_precio->Margin = System::Windows::Forms::Padding(4);
			this->incrementador_precio->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->incrementador_precio->Name = L"incrementador_precio";
			this->incrementador_precio->Size = System::Drawing::Size(417, 28);
			this->incrementador_precio->TabIndex = 13;
			this->incrementador_precio->Visible = false;
			// 
			// incrementador_cantidad
			// 
			this->incrementador_cantidad->Location = System::Drawing::Point(143, 263);
			this->incrementador_cantidad->Margin = System::Windows::Forms::Padding(4);
			this->incrementador_cantidad->Name = L"incrementador_cantidad";
			this->incrementador_cantidad->Size = System::Drawing::Size(417, 28);
			this->incrementador_cantidad->TabIndex = 12;
			this->incrementador_cantidad->Visible = false;
			// 
			// bttn_Borrar
			// 
			this->bttn_Borrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bttn_Borrar->Location = System::Drawing::Point(413, 514);
			this->bttn_Borrar->Margin = System::Windows::Forms::Padding(4);
			this->bttn_Borrar->Name = L"bttn_Borrar";
			this->bttn_Borrar->Size = System::Drawing::Size(147, 49);
			this->bttn_Borrar->TabIndex = 11;
			this->bttn_Borrar->Text = L"Borrar";
			this->bttn_Borrar->UseVisualStyleBackColor = false;
			this->bttn_Borrar->Visible = false;
			this->bttn_Borrar->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_Borrar_Click);
			// 
			// bttn_Registrar
			// 
			this->bttn_Registrar->Location = System::Drawing::Point(233, 514);
			this->bttn_Registrar->Margin = System::Windows::Forms::Padding(4);
			this->bttn_Registrar->Name = L"bttn_Registrar";
			this->bttn_Registrar->Size = System::Drawing::Size(147, 49);
			this->bttn_Registrar->TabIndex = 10;
			this->bttn_Registrar->Text = L"Registrar";
			this->bttn_Registrar->UseVisualStyleBackColor = true;
			this->bttn_Registrar->Visible = false;
			this->bttn_Registrar->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_Registrar_Click);
			// 
			// label_unidad
			// 
			this->label_unidad->AutoSize = true;
			this->label_unidad->Location = System::Drawing::Point(143, 399);
			this->label_unidad->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_unidad->Name = L"label_unidad";
			this->label_unidad->Size = System::Drawing::Size(362, 25);
			this->label_unidad->TabIndex = 8;
			this->label_unidad->Text = L"Unidad del producto: (Kg, g, L, mL)";
			this->label_unidad->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(143, 313);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Precio:";
			this->label4->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(143, 226);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(292, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Cantidad total del producto:";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(143, 140);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(212, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nombre del producto:";
			this->label2->Visible = false;
			// 
			// txt_prodName
			// 
			this->txt_prodName->Location = System::Drawing::Point(143, 177);
			this->txt_prodName->Margin = System::Windows::Forms::Padding(4);
			this->txt_prodName->Name = L"txt_prodName";
			this->txt_prodName->Size = System::Drawing::Size(523, 28);
			this->txt_prodName->TabIndex = 2;
			this->txt_prodName->Visible = false;
			// 
			// es_Unitario
			// 
			this->es_Unitario->AutoSize = true;
			this->es_Unitario->Location = System::Drawing::Point(400, 52);
			this->es_Unitario->Margin = System::Windows::Forms::Padding(4);
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
			this->es_Granel->Location = System::Drawing::Point(151, 52);
			this->es_Granel->Margin = System::Windows::Forms::Padding(4);
			this->es_Granel->Name = L"es_Granel";
			this->es_Granel->Size = System::Drawing::Size(180, 29);
			this->es_Granel->TabIndex = 0;
			this->es_Granel->Text = L"Producto Granel";
			this->es_Granel->UseVisualStyleBackColor = true;
			this->es_Granel->CheckedChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::es_Granel_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->bttn_salir);
			this->panel1->Controls->Add(this->bttn_CambiarCredenciales);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(337, 809);
			this->panel1->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(71, 196);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(192, 50);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Sistema de Almacén\r\ny Ventas";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bttn_salir
			// 
			this->bttn_salir->Location = System::Drawing::Point(63, 720);
			this->bttn_salir->Margin = System::Windows::Forms::Padding(4);
			this->bttn_salir->Name = L"bttn_salir";
			this->bttn_salir->Size = System::Drawing::Size(208, 53);
			this->bttn_salir->TabIndex = 2;
			this->bttn_salir->Text = L"Cerrar Sesión";
			this->bttn_salir->UseVisualStyleBackColor = true;
			this->bttn_salir->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_salir_Click);
			// 
			// bttn_CambiarCredenciales
			// 
			this->bttn_CambiarCredenciales->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_CambiarCredenciales->Location = System::Drawing::Point(63, 570);
			this->bttn_CambiarCredenciales->Margin = System::Windows::Forms::Padding(4);
			this->bttn_CambiarCredenciales->Name = L"bttn_CambiarCredenciales";
			this->bttn_CambiarCredenciales->Size = System::Drawing::Size(208, 79);
			this->bttn_CambiarCredenciales->TabIndex = 1;
			this->bttn_CambiarCredenciales->Text = L"Cambiar Credenciales";
			this->bttn_CambiarCredenciales->UseVisualStyleBackColor = true;
			this->bttn_CambiarCredenciales->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_CambiarCredenciales_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(80, 10);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->MinimumSize = System::Drawing::Size(167, 154);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 154);
			this->label1->TabIndex = 0;
			// 
			// bttn_actualizarDatosTabla
			// 
			this->bttn_actualizarDatosTabla->Location = System::Drawing::Point(516, 711);
			this->bttn_actualizarDatosTabla->Name = L"bttn_actualizarDatosTabla";
			this->bttn_actualizarDatosTabla->Size = System::Drawing::Size(239, 37);
			this->bttn_actualizarDatosTabla->TabIndex = 1;
			this->bttn_actualizarDatosTabla->Text = L"Guardar cambios";
			this->bttn_actualizarDatosTabla->UseVisualStyleBackColor = true;
			// 
			// bttn_cancelarCambios
			// 
			this->bttn_cancelarCambios->Location = System::Drawing::Point(8, 711);
			this->bttn_cancelarCambios->Name = L"bttn_cancelarCambios";
			this->bttn_cancelarCambios->Size = System::Drawing::Size(207, 37);
			this->bttn_cancelarCambios->TabIndex = 2;
			this->bttn_cancelarCambios->Text = L"Cancelar Cambios";
			this->bttn_cancelarCambios->UseVisualStyleBackColor = true;
			// 
			// data_nombre
			// 
			this->data_nombre->HeaderText = L"Nombre";
			this->data_nombre->MinimumWidth = 6;
			this->data_nombre->Name = L"data_nombre";
			this->data_nombre->Width = 97;
			// 
			// data_ID
			// 
			this->data_ID->HeaderText = L"ID";
			this->data_ID->MinimumWidth = 6;
			this->data_ID->Name = L"data_ID";
			this->data_ID->ReadOnly = true;
			this->data_ID->Width = 57;
			// 
			// data_Cantidad
			// 
			this->data_Cantidad->HeaderText = L"Cantidad";
			this->data_Cantidad->MinimumWidth = 6;
			this->data_Cantidad->Name = L"data_Cantidad";
			this->data_Cantidad->Width = 117;
			// 
			// data_precio
			// 
			this->data_precio->HeaderText = L"Precio";
			this->data_precio->MinimumWidth = 6;
			this->data_precio->Name = L"data_precio";
			this->data_precio->Width = 97;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->label7->Location = System::Drawing::Point(20, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(782, 50);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Para modificar los productos cambie los valores en la tabla y presione guarda\r\nsi"
				L"no, cancele los cambios";
			// 
			// frm_MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 812);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tab_Control);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(1194, 851);
			this->MinimumSize = System::Drawing::Size(1194, 851);
			this->Name = L"frm_MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sistema de almacén y ventas";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_MenuPrincipal::frm_MenuPrincipal_FormClosing);
			this->tab_Control->ResumeLayout(false);
			this->tab_venta->ResumeLayout(false);
			this->tab_venta->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tab_Lista->ResumeLayout(false);
			this->tab_Lista->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_productos))->EndInit();
			this->tab_Registro->ResumeLayout(false);
			this->tab_Registro->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_precio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_cantidad))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void es_Unitario_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		L_unidad->Text = "Unidades";
		L_unidadPrecio->Text = "/ Unidad";
		label2->Visible = true;
		txt_prodName->Visible = true;

		label3->Visible = true;
		incrementador_precio->Visible = true;

		label4->Visible = true;
		incrementador_cantidad->Visible = true;
		incrementador_cantidad->DecimalPlaces = 0;
		incrementador_cantidad->Increment = 1;

		label_unidad->Visible = false;
		seleccionador_unidad->Visible = false;

		bttn_Borrar->Visible = true;
		bttn_Registrar->Visible = true;
	}
	private: System::Void es_Granel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		L_unidad->Text = "";
		L_unidadPrecio->Text = "";
		label2->Visible = true;
		txt_prodName->Visible = true;

		label3->Visible = true;
		incrementador_precio->Visible = true;

		label4->Visible = true;
		incrementador_cantidad->Visible = true;
		incrementador_cantidad->DecimalPlaces = 2;
		incrementador_cantidad->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });

		label_unidad->Visible = true;
		seleccionador_unidad->Visible = true;

		bttn_Borrar->Visible = true;
		bttn_Registrar->Visible = true;
	}

	private: System::Void frm_MenuPrincipal_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) { //si presiona la "x"
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
		}
	}

	private: System::Void bttn_Borrar_Click(System::Object^ sender, System::EventArgs^ e) {
		incrementador_cantidad->Value = 0;
		incrementador_precio->Value = 0;
		txt_prodName->Text = "";
		seleccionador_unidad->Text = "Seleccione una unidad...";
		L_unidadPrecio->Text = "";
		L_unidad->Text = "";
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
	private: System::Void bttn_salir_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
			this->Close();
		}
	}
	private: System::Void tab_Control_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) //cuando cambia de pestaña
	{
		if (tab_Control->SelectedIndex == 1) { //selecciona la lista de productos
			Tabla_productos->Rows->Clear(); //limpia los datos
			System::Collections::Generic::List<Producto^>^ productos = Datos::Instance->obtenerTodosProducto();
			for each (Producto ^ prod in  productos) {
				Granel^ gra = dynamic_cast<Granel^>(prod);
				if (gra != nullptr) { //es granel
					System::String^ cantidad = gra->cantidad->ToString() + " Kg";
					Tabla_productos->Rows->Add(gra->Nombre, gra->Id, cantidad, gra->Precio);
				}
				else {
					Unitario^ un = dynamic_cast<Unitario^>(prod);
					if (un != nullptr) { //es Unitario
						Tabla_productos->Rows->Add(un->Nombre, un->Id, un->cantidad.ToString(), un->Precio);
					}
				}
			}
		}
		if (tab_Control->SelectedIndex != 2)
		{
			L_unidadPrecio->Text = "";
			L_unidad->Text = "";
			incrementador_cantidad->Value = 0;
			incrementador_precio->Value = 0;
			txt_prodName->Text = "";
			seleccionador_unidad->Text = "";
			label2->Visible = false;
			txt_prodName->Visible = false;

			label3->Visible = false;
			incrementador_cantidad->Visible = false;

			label4->Visible = false;
			incrementador_precio->Visible = false;

			label_unidad->Visible = false;
			seleccionador_unidad->Visible = false;

			bttn_Borrar->Visible = false;
			bttn_Registrar->Visible = false;
		}

	}
	private: System::Void bttn_realizaVenta_Click(System::Object^ sender, System::EventArgs^ e) //realizar venta
	{

	}
	private: System::Void seleccionador_unidad_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (seleccionador_unidad->SelectedIndex)
		{
		case 0:
			L_unidadPrecio->Text = "/ Kg";
			L_unidad->Text = "Kg";
			break;
		case 1:
			L_unidadPrecio->Text = "/ g";
			L_unidad->Text = "g";
			break;
		case 2:
			L_unidadPrecio->Text = "/ L";
			L_unidad->Text = "L";
			break;
		case 3:
			L_unidadPrecio->Text = "/ mL";
			L_unidad->Text = "mL";
		}
	}
	private: System::Void bttn_Registrar_Click(System::Object^ sender, System::EventArgs^ e) //Botón de registrar
	{
		if (es_Granel->Checked) {
			if (!System::String::IsNullOrEmpty(txt_prodName->Text) && incrementador_precio->Value != 0 && incrementador_cantidad->Value != 0 && !System::String::IsNullOrEmpty(seleccionador_unidad->Text)) {
				int id = 10000 + Datos::Instance->CantidadProducto;
				Granel^ nuevo = gcnew Granel(txt_prodName->Text, id, incrementador_precio->Value, incrementador_cantidad->Value, seleccionador_unidad->Text);
				Datos::Instance->añadeProducto(nuevo);
				MessageBox::Show(L"Producto registrado correctamente!");
				Borrar();
			}
			else {
				MessageBox::Show(L"No puede registrar valores nulos o vacios");
				Borrar();
			}
		}
		if (es_Unitario->Checked) {
			if (!System::String::IsNullOrEmpty(txt_prodName->Text) && incrementador_precio->Value != 0 && incrementador_cantidad->Value != 0) {
				int id = Datos::Instance->CantidadProducto + 10000;
				int cantidad = System::Decimal::ToInt32(incrementador_cantidad->Value); //castea a un int
				Unitario^ nuevo = gcnew Unitario(txt_prodName->Text, id, incrementador_precio->Value, cantidad);
				Datos::Instance->añadeProducto(nuevo);
				MessageBox::Show(L"Producto registrado correctamente!");
				Borrar();
			}
			else {
				MessageBox::Show(L"No puede registrar valores nulos o vacios");
				Borrar();
			}
		}

	}
	private: void Borrar() {
		incrementador_cantidad->Value = 0;
		incrementador_precio->Value = 0;
		txt_prodName->Text = "";
		seleccionador_unidad->Text = "Seleccione una unidad...";
		L_unidadPrecio->Text = "";
		L_unidad->Text = "";
	}
	};
}
