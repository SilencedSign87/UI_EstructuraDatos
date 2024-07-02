#pragma once
#include "frm_CambiarCred.h"
#include "frm_Historial.h"
#include "Datos.h"
#include "Historial.h"
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
		// ---------------------------- Estructura lista enlazada ----------------------------------------------
	private: ref struct itemVenta
	{
		Producto^ producto;
		System::String^ unidad;
		System::Decimal^ cantidad;

		System::Decimal^ subtotal;

		itemVenta^ next; //siguiente

		itemVenta() {
			this->producto = nullptr;
			this->next = nullptr;
		}
		itemVenta(Producto^ prod, System::Decimal^ cantidad) {
			this->producto = prod;
			this->cantidad = cantidad;
			this->subtotal = System::Decimal::Multiply(static_cast<System::Decimal>(this->cantidad), static_cast<System::Decimal>(this->producto->Precio));
			this->next = nullptr;
		}

		void recalcularSubtotal() {
			this->subtotal = System::Decimal::Multiply(static_cast<System::Decimal>(this->cantidad), static_cast<System::Decimal>(this->producto->Precio));
		}
	};

	private: ref class ListaVenta {
	public:
		itemVenta^ item;
		int longitud;

		ListaVenta() {
			this->item = nullptr;
			this->longitud = 0;
		}

		void agregarUnitario(Producto^ prod, System::Decimal cantidad) {
			cantidad = System::Decimal::Truncate(cantidad);
			itemVenta^ nuevo = gcnew itemVenta(prod, cantidad);
			nuevo->unidad = "";
			itemVenta^ aux1 = gcnew itemVenta();
			aux1 = item;
			itemVenta^ aux2 = nullptr;

			while (aux1 != nullptr && aux1->subtotal->CompareTo(nuevo->subtotal) > 0)
			{
				aux2 = aux1;
				aux1 = aux1->next;
			}
			if (item == aux1) {
				item = nuevo;
			}
			else {
				aux2->next = nuevo;
			}
			longitud++;
			nuevo->next = aux1;
		}

		void agregarGranel(Producto^ prod, System::Decimal cantidad) {

			itemVenta^ nuevo = gcnew itemVenta(prod, cantidad);

			Granel^ aux = dynamic_cast<Granel^>(prod);

			if (aux != nullptr) {
				nuevo->unidad = aux->unidad;
			}
			itemVenta^ aux1 = gcnew itemVenta();
			aux1 = item;

			itemVenta^ aux2 = nullptr;

			while (aux1 != nullptr && aux1->subtotal->CompareTo(nuevo->subtotal) > 0)
			{
				aux2 = aux1;
				aux1 = aux1->next;
			}
			if (item == aux1) {
				item = nuevo;
			}
			else {
				aux2->next = nuevo;
			}
			longitud++;
			nuevo->next = aux1;
		}

		itemVenta^ getItem(int id) {
			itemVenta^ aux = gcnew itemVenta();
			aux = item;
			while (aux != nullptr)
			{
				if (aux->producto->Id == id) {
					return aux;
				}
				else {
					aux = aux->next;
				}
			}
			return nullptr;
		}

		void borraItem(int id) {
			//TODO: revisar que se borre correctamente el elemento

			itemVenta^ aux_borrar;
			itemVenta^ anterior = nullptr;
			aux_borrar = item;
			while (aux_borrar != nullptr && aux_borrar->producto->Id != id) {
				anterior = aux_borrar;
				aux_borrar = aux_borrar->next;
			}
			if (aux_borrar == nullptr) {
				return;
			}
			else if (aux_borrar == item) {
				item = item->next;
				longitud--;
				delete item;
			}
			else {
				anterior->next = aux_borrar->next;
				longitud--;
				delete aux_borrar;
			}
		}

		void vaciarLista() {
			while (longitud > 0) {
				itemVenta^ aux = item;
				item = aux->next;
				delete aux;
				longitud--;
			}
		}

	};

		   // -------------------------- Datos Globales --------------------------------------------
	private: System::Windows::Forms::Form^ previousForm; //form anterior

	private: ListaVenta^ lista = gcnew ListaVenta();
		   // --------------------------------------------------------------------------------------

	private: System::Windows::Forms::TabControl^ tab_Control;
	private: System::Windows::Forms::TabPage^ tab_Registro;
	private: System::Windows::Forms::TabPage^ tab_Lista;

	protected:

	protected:


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ es_Unitario;
	private: System::Windows::Forms::RadioButton^ es_Granel;

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
	private: System::Windows::Forms::DataGridView^ tabla_venta;
	private: System::Windows::Forms::Button^ bttn_guardaCambiosVenta;












	private: System::Windows::Forms::Button^ bttn_salir;
	private: System::Windows::Forms::Button^ bttn_cancelaVenta;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ bttn_realizaVenta;





	private: System::Windows::Forms::DataGridView^ Tabla_productos;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numero_total_venta;

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
	private: System::Windows::Forms::TableLayoutPanel^ tablePanel_Registro;





	private: System::Windows::Forms::Button^ bttn_cancelarCambiosVenta;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c_subtotal;
	private: System::Windows::Forms::Button^ button1;




























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
			this->bttn_cancelarCambiosVenta = (gcnew System::Windows::Forms::Button());
			this->numero_total_venta = (gcnew System::Windows::Forms::NumericUpDown());
			this->bttn_cancelaVenta = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bttn_realizaVenta = (gcnew System::Windows::Forms::Button());
			this->tabla_venta = (gcnew System::Windows::Forms::DataGridView());
			this->c_nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c_subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bttn_guardaCambiosVenta = (gcnew System::Windows::Forms::Button());
			this->list_busqueda = (gcnew System::Windows::Forms::ListBox());
			this->txt_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->tab_Lista = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->bttn_cancelarCambios = (gcnew System::Windows::Forms::Button());
			this->bttn_actualizarDatosTabla = (gcnew System::Windows::Forms::Button());
			this->Tabla_productos = (gcnew System::Windows::Forms::DataGridView());
			this->data_nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_precio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tab_Registro = (gcnew System::Windows::Forms::TabPage());
			this->tablePanel_Registro = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->es_Granel = (gcnew System::Windows::Forms::RadioButton());
			this->es_Unitario = (gcnew System::Windows::Forms::RadioButton());
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->bttn_salir = (gcnew System::Windows::Forms::Button());
			this->bttn_CambiarCredenciales = (gcnew System::Windows::Forms::Button());
			this->tab_Control->SuspendLayout();
			this->tab_venta->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numero_total_venta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabla_venta))->BeginInit();
			this->tab_Lista->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_productos))->BeginInit();
			this->tab_Registro->SuspendLayout();
			this->tablePanel_Registro->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_precio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_cantidad))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->tab_Control->Size = System::Drawing::Size(726, 657);
			this->tab_Control->TabIndex = 0;
			this->tab_Control->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::tab_Control_SelectedIndexChanged);
			// 
			// tab_venta
			// 
			this->tab_venta->Controls->Add(this->bttn_cancelarCambiosVenta);
			this->tab_venta->Controls->Add(this->numero_total_venta);
			this->tab_venta->Controls->Add(this->bttn_cancelaVenta);
			this->tab_venta->Controls->Add(this->label5);
			this->tab_venta->Controls->Add(this->bttn_realizaVenta);
			this->tab_venta->Controls->Add(this->tabla_venta);
			this->tab_venta->Controls->Add(this->bttn_guardaCambiosVenta);
			this->tab_venta->Controls->Add(this->list_busqueda);
			this->tab_venta->Controls->Add(this->txt_busqueda);
			this->tab_venta->Location = System::Drawing::Point(4, 37);
			this->tab_venta->Name = L"tab_venta";
			this->tab_venta->Size = System::Drawing::Size(718, 616);
			this->tab_venta->TabIndex = 2;
			this->tab_venta->Text = L"Venta";
			this->tab_venta->UseVisualStyleBackColor = true;
			// 
			// bttn_cancelarCambiosVenta
			// 
			this->bttn_cancelarCambiosVenta->Location = System::Drawing::Point(479, 118);
			this->bttn_cancelarCambiosVenta->Name = L"bttn_cancelarCambiosVenta";
			this->bttn_cancelarCambiosVenta->Size = System::Drawing::Size(199, 39);
			this->bttn_cancelarCambiosVenta->TabIndex = 8;
			this->bttn_cancelarCambiosVenta->Text = L"Cancelar Cambios";
			this->bttn_cancelarCambiosVenta->UseVisualStyleBackColor = true;
			this->bttn_cancelarCambiosVenta->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_cancelarCambiosVenta_Click);
			// 
			// numero_total_venta
			// 
			this->numero_total_venta->DecimalPlaces = 2;
			this->numero_total_venta->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numero_total_venta->Location = System::Drawing::Point(603, 564);
			this->numero_total_venta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numero_total_venta->Name = L"numero_total_venta";
			this->numero_total_venta->ReadOnly = true;
			this->numero_total_venta->Size = System::Drawing::Size(106, 31);
			this->numero_total_venta->TabIndex = 7;
			this->numero_total_venta->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// bttn_cancelaVenta
			// 
			this->bttn_cancelaVenta->BackColor = System::Drawing::Color::Red;
			this->bttn_cancelaVenta->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bttn_cancelaVenta->Location = System::Drawing::Point(17, 557);
			this->bttn_cancelaVenta->Name = L"bttn_cancelaVenta";
			this->bttn_cancelaVenta->Size = System::Drawing::Size(92, 43);
			this->bttn_cancelaVenta->TabIndex = 6;
			this->bttn_cancelaVenta->Text = L"Borrar";
			this->bttn_cancelaVenta->UseVisualStyleBackColor = false;
			this->bttn_cancelaVenta->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_cancelaVenta_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(423, 566);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(199, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Precio final: S/.";
			// 
			// bttn_realizaVenta
			// 
			this->bttn_realizaVenta->Location = System::Drawing::Point(207, 557);
			this->bttn_realizaVenta->Name = L"bttn_realizaVenta";
			this->bttn_realizaVenta->Size = System::Drawing::Size(189, 43);
			this->bttn_realizaVenta->TabIndex = 2;
			this->bttn_realizaVenta->Text = L"Realizar venta";
			this->bttn_realizaVenta->UseVisualStyleBackColor = true;
			this->bttn_realizaVenta->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_realizaVenta_Click);
			// 
			// tabla_venta
			// 
			this->tabla_venta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tabla_venta->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->c_nombre,
					this->c_id, this->c_cantidad, this->c_subtotal
			});
			this->tabla_venta->Location = System::Drawing::Point(5, 185);
			this->tabla_venta->Name = L"tabla_venta";
			this->tabla_venta->RowHeadersWidth = 51;
			this->tabla_venta->Size = System::Drawing::Size(708, 355);
			this->tabla_venta->TabIndex = 4;
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
			this->c_id->Width = 110;
			// 
			// c_cantidad
			// 
			this->c_cantidad->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->c_cantidad->HeaderText = L"Cantidad";
			this->c_cantidad->MinimumWidth = 6;
			this->c_cantidad->Name = L"c_cantidad";
			this->c_cantidad->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->c_cantidad->Width = 150;
			// 
			// c_subtotal
			// 
			this->c_subtotal->HeaderText = L"Sub total";
			this->c_subtotal->MinimumWidth = 6;
			this->c_subtotal->Name = L"c_subtotal";
			this->c_subtotal->ReadOnly = true;
			this->c_subtotal->Width = 125;
			// 
			// bttn_guardaCambiosVenta
			// 
			this->bttn_guardaCambiosVenta->Location = System::Drawing::Point(479, 66);
			this->bttn_guardaCambiosVenta->Name = L"bttn_guardaCambiosVenta";
			this->bttn_guardaCambiosVenta->Size = System::Drawing::Size(199, 39);
			this->bttn_guardaCambiosVenta->TabIndex = 3;
			this->bttn_guardaCambiosVenta->Text = L"Guardar Cambios";
			this->bttn_guardaCambiosVenta->UseVisualStyleBackColor = true;
			this->bttn_guardaCambiosVenta->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_añadir2Lista_Click);
			// 
			// list_busqueda
			// 
			this->list_busqueda->FormattingEnabled = true;
			this->list_busqueda->ItemHeight = 28;
			this->list_busqueda->Location = System::Drawing::Point(23, 79);
			this->list_busqueda->Name = L"list_busqueda";
			this->list_busqueda->Size = System::Drawing::Size(407, 60);
			this->list_busqueda->TabIndex = 1;
			this->list_busqueda->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_MenuPrincipal::list_busqueda_MouseDoubleClick);
			// 
			// txt_busqueda
			// 
			this->txt_busqueda->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_busqueda->ForeColor = System::Drawing::Color::Silver;
			this->txt_busqueda->Location = System::Drawing::Point(23, 25);
			this->txt_busqueda->Name = L"txt_busqueda";
			this->txt_busqueda->Size = System::Drawing::Size(407, 31);
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
			this->tab_Lista->Location = System::Drawing::Point(4, 37);
			this->tab_Lista->Name = L"tab_Lista";
			this->tab_Lista->Padding = System::Windows::Forms::Padding(3);
			this->tab_Lista->Size = System::Drawing::Size(718, 616);
			this->tab_Lista->TabIndex = 1;
			this->tab_Lista->Text = L"Lista";
			this->tab_Lista->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Fira Code", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->label7->Location = System::Drawing::Point(5, 5);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(784, 48);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Para modificar los productos cambie los valores en la tabla y presione guardar ca"
				L"mbios\r\nsino, cancele los cambios";
			// 
			// bttn_cancelarCambios
			// 
			this->bttn_cancelarCambios->Location = System::Drawing::Point(76, 575);
			this->bttn_cancelarCambios->Margin = System::Windows::Forms::Padding(2);
			this->bttn_cancelarCambios->Name = L"bttn_cancelarCambios";
			this->bttn_cancelarCambios->Size = System::Drawing::Size(155, 30);
			this->bttn_cancelarCambios->TabIndex = 2;
			this->bttn_cancelarCambios->Text = L"Cancelar Cambios";
			this->bttn_cancelarCambios->UseVisualStyleBackColor = true;
			this->bttn_cancelarCambios->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_cancelarCambios_Click);
			// 
			// bttn_actualizarDatosTabla
			// 
			this->bttn_actualizarDatosTabla->Location = System::Drawing::Point(440, 575);
			this->bttn_actualizarDatosTabla->Margin = System::Windows::Forms::Padding(2);
			this->bttn_actualizarDatosTabla->Name = L"bttn_actualizarDatosTabla";
			this->bttn_actualizarDatosTabla->Size = System::Drawing::Size(179, 30);
			this->bttn_actualizarDatosTabla->TabIndex = 1;
			this->bttn_actualizarDatosTabla->Text = L"Guardar cambios";
			this->bttn_actualizarDatosTabla->UseVisualStyleBackColor = true;
			this->bttn_actualizarDatosTabla->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_actualizarDatosTabla_Click);
			// 
			// Tabla_productos
			// 
			this->Tabla_productos->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Tabla_productos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla_productos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->data_nombre,
					this->data_ID, this->data_Cantidad, this->data_precio
			});
			this->Tabla_productos->Location = System::Drawing::Point(6, 58);
			this->Tabla_productos->Name = L"Tabla_productos";
			this->Tabla_productos->RowHeadersWidth = 51;
			this->Tabla_productos->Size = System::Drawing::Size(706, 502);
			this->Tabla_productos->TabIndex = 0;
			// 
			// data_nombre
			// 
			this->data_nombre->HeaderText = L"Nombre";
			this->data_nombre->MinimumWidth = 6;
			this->data_nombre->Name = L"data_nombre";
			this->data_nombre->Width = 300;
			// 
			// data_ID
			// 
			this->data_ID->HeaderText = L"ID";
			this->data_ID->MinimumWidth = 6;
			this->data_ID->Name = L"data_ID";
			this->data_ID->ReadOnly = true;
			this->data_ID->Width = 110;
			// 
			// data_Cantidad
			// 
			this->data_Cantidad->HeaderText = L"Cantidad";
			this->data_Cantidad->MinimumWidth = 6;
			this->data_Cantidad->Name = L"data_Cantidad";
			this->data_Cantidad->Width = 150;
			// 
			// data_precio
			// 
			this->data_precio->HeaderText = L"Precio";
			this->data_precio->MinimumWidth = 6;
			this->data_precio->Name = L"data_precio";
			this->data_precio->Width = 110;
			// 
			// tab_Registro
			// 
			this->tab_Registro->Controls->Add(this->tablePanel_Registro);
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
			this->tab_Registro->Location = System::Drawing::Point(4, 37);
			this->tab_Registro->Name = L"tab_Registro";
			this->tab_Registro->Padding = System::Windows::Forms::Padding(3);
			this->tab_Registro->Size = System::Drawing::Size(718, 616);
			this->tab_Registro->TabIndex = 0;
			this->tab_Registro->Text = L"Registro";
			this->tab_Registro->UseVisualStyleBackColor = true;
			// 
			// tablePanel_Registro
			// 
			this->tablePanel_Registro->ColumnCount = 2;
			this->tablePanel_Registro->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tablePanel_Registro->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tablePanel_Registro->Controls->Add(this->es_Granel, 0, 0);
			this->tablePanel_Registro->Controls->Add(this->es_Unitario, 1, 0);
			this->tablePanel_Registro->Location = System::Drawing::Point(138, 44);
			this->tablePanel_Registro->Name = L"tablePanel_Registro";
			this->tablePanel_Registro->RowCount = 1;
			this->tablePanel_Registro->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tablePanel_Registro->Size = System::Drawing::Size(455, 38);
			this->tablePanel_Registro->TabIndex = 17;
			// 
			// es_Granel
			// 
			this->es_Granel->AutoSize = true;
			this->es_Granel->Location = System::Drawing::Point(3, 3);
			this->es_Granel->Name = L"es_Granel";
			this->es_Granel->Size = System::Drawing::Size(195, 32);
			this->es_Granel->TabIndex = 0;
			this->es_Granel->Text = L"Producto Granel";
			this->es_Granel->UseVisualStyleBackColor = true;
			this->es_Granel->CheckedChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::es_Granel_CheckedChanged);
			// 
			// es_Unitario
			// 
			this->es_Unitario->AutoSize = true;
			this->es_Unitario->Location = System::Drawing::Point(230, 3);
			this->es_Unitario->Name = L"es_Unitario";
			this->es_Unitario->Size = System::Drawing::Size(217, 32);
			this->es_Unitario->TabIndex = 1;
			this->es_Unitario->Text = L"Producto Unitario";
			this->es_Unitario->UseVisualStyleBackColor = true;
			this->es_Unitario->CheckedChanged += gcnew System::EventHandler(this, &frm_MenuPrincipal::es_Unitario_CheckedChanged);
			// 
			// L_unidadPrecio
			// 
			this->L_unidadPrecio->AutoSize = true;
			this->L_unidadPrecio->Location = System::Drawing::Point(496, 275);
			this->L_unidadPrecio->Name = L"L_unidadPrecio";
			this->L_unidadPrecio->Size = System::Drawing::Size(0, 28);
			this->L_unidadPrecio->TabIndex = 16;
			// 
			// L_unidad
			// 
			this->L_unidad->AutoSize = true;
			this->L_unidad->Location = System::Drawing::Point(491, 206);
			this->L_unidad->Name = L"L_unidad";
			this->L_unidad->Size = System::Drawing::Size(0, 28);
			this->L_unidad->TabIndex = 15;
			// 
			// seleccionador_unidad
			// 
			this->seleccionador_unidad->Items->Add(L"Kilogramo\t");
			this->seleccionador_unidad->Items->Add(L"Gramo");
			this->seleccionador_unidad->Items->Add(L"Litro");
			this->seleccionador_unidad->Items->Add(L"Mililitro");
			this->seleccionador_unidad->Location = System::Drawing::Point(168, 345);
			this->seleccionador_unidad->Name = L"seleccionador_unidad";
			this->seleccionador_unidad->Size = System::Drawing::Size(276, 31);
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
			this->incrementador_precio->Location = System::Drawing::Point(168, 275);
			this->incrementador_precio->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->incrementador_precio->Name = L"incrementador_precio";
			this->incrementador_precio->Size = System::Drawing::Size(313, 31);
			this->incrementador_precio->TabIndex = 13;
			this->incrementador_precio->Visible = false;
			// 
			// incrementador_cantidad
			// 
			this->incrementador_cantidad->Location = System::Drawing::Point(168, 205);
			this->incrementador_cantidad->Name = L"incrementador_cantidad";
			this->incrementador_cantidad->Size = System::Drawing::Size(313, 31);
			this->incrementador_cantidad->TabIndex = 12;
			this->incrementador_cantidad->Visible = false;
			// 
			// bttn_Borrar
			// 
			this->bttn_Borrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bttn_Borrar->Location = System::Drawing::Point(290, 500);
			this->bttn_Borrar->Name = L"bttn_Borrar";
			this->bttn_Borrar->Size = System::Drawing::Size(128, 40);
			this->bttn_Borrar->TabIndex = 11;
			this->bttn_Borrar->Text = L"Borrar";
			this->bttn_Borrar->UseVisualStyleBackColor = false;
			this->bttn_Borrar->Visible = false;
			this->bttn_Borrar->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_Borrar_Click);
			// 
			// bttn_Registrar
			// 
			this->bttn_Registrar->Location = System::Drawing::Point(290, 426);
			this->bttn_Registrar->Name = L"bttn_Registrar";
			this->bttn_Registrar->Size = System::Drawing::Size(128, 40);
			this->bttn_Registrar->TabIndex = 10;
			this->bttn_Registrar->Text = L"Registrar";
			this->bttn_Registrar->UseVisualStyleBackColor = true;
			this->bttn_Registrar->Visible = false;
			this->bttn_Registrar->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_Registrar_Click);
			// 
			// label_unidad
			// 
			this->label_unidad->AutoSize = true;
			this->label_unidad->Location = System::Drawing::Point(168, 315);
			this->label_unidad->Name = L"label_unidad";
			this->label_unidad->Size = System::Drawing::Size(397, 28);
			this->label_unidad->TabIndex = 8;
			this->label_unidad->Text = L"Unidad del producto: (Kg, g, L, mL)";
			this->label_unidad->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(168, 245);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Precio:";
			this->label4->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(168, 175);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(320, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Cantidad total del producto:";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(168, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(232, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nombre del producto:";
			this->label2->Visible = false;
			// 
			// txt_prodName
			// 
			this->txt_prodName->Location = System::Drawing::Point(168, 135);
			this->txt_prodName->Name = L"txt_prodName";
			this->txt_prodName->Size = System::Drawing::Size(393, 31);
			this->txt_prodName->TabIndex = 2;
			this->txt_prodName->Visible = false;
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
			this->panel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(48, 312);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 70);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Historial de Ventas";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::button1_Click);
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
			// bttn_salir
			// 
			this->bttn_salir->Location = System::Drawing::Point(47, 585);
			this->bttn_salir->Name = L"bttn_salir";
			this->bttn_salir->Size = System::Drawing::Size(156, 43);
			this->bttn_salir->TabIndex = 2;
			this->bttn_salir->Text = L"Cerrar Sesión";
			this->bttn_salir->UseVisualStyleBackColor = true;
			this->bttn_salir->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_salir_Click);
			// 
			// bttn_CambiarCredenciales
			// 
			this->bttn_CambiarCredenciales->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_CambiarCredenciales->Location = System::Drawing::Point(47, 463);
			this->bttn_CambiarCredenciales->Name = L"bttn_CambiarCredenciales";
			this->bttn_CambiarCredenciales->Size = System::Drawing::Size(156, 64);
			this->bttn_CambiarCredenciales->TabIndex = 1;
			this->bttn_CambiarCredenciales->Text = L"Cambiar Credenciales";
			this->bttn_CambiarCredenciales->UseVisualStyleBackColor = true;
			this->bttn_CambiarCredenciales->Click += gcnew System::EventHandler(this, &frm_MenuPrincipal::bttn_CambiarCredenciales_Click);
			// 
			// frm_MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 659);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tab_Control);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1000, 700);
			this->MinimumSize = System::Drawing::Size(1000, 700);
			this->Name = L"frm_MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sistema de almacén y ventas";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_MenuPrincipal::frm_MenuPrincipal_FormClosing);
			this->tab_Control->ResumeLayout(false);
			this->tab_venta->ResumeLayout(false);
			this->tab_venta->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numero_total_venta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabla_venta))->EndInit();
			this->tab_Lista->ResumeLayout(false);
			this->tab_Lista->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla_productos))->EndInit();
			this->tab_Registro->ResumeLayout(false);
			this->tab_Registro->PerformLayout();
			this->tablePanel_Registro->ResumeLayout(false);
			this->tablePanel_Registro->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_precio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->incrementador_cantidad))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
		   //---------------------------------------------------------------------------------------------------- cuando el texto cambia
	private: System::Void txt_busqueda_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		list_busqueda->Items->Clear();
		list_busqueda->Enabled = true;
		if (txt_busqueda->Text->Length < 2) {
			return;
		}

		System::Collections::Generic::List<Producto^ >^ aux = Datos::Instance->buscarDinamico(txt_busqueda->Text);

		if (aux != nullptr)
		{
			for each (Producto ^ p in aux)
			{
				list_busqueda->Items->Add(p->Nombre);
			}
		}
	}
		   //--------------------------------------------------------------------------------------------------------
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
		   //----------------------------------------------------------------------------------------------------------- Cuando cambia de pestaña
	private: System::Void tab_Control_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (tab_Control->SelectedIndex == 1) { //selecciona la lista de productos
			dibujaListaProducto();
		}
		if (tab_Control->SelectedIndex != 2)
		{
			es_Granel->Checked = false;
			es_Unitario->Checked = false;
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
		   //--------------------------------------------------------------------------------------------------- realizar venta
	private: System::Void bttn_realizaVenta_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Historial::Instance->abreHistorial();
		System::DateTime ahora = System::DateTime::Now; //obten la hora
		System::Decimal totalVenta = numero_total_venta->Value; //obten el total

		int idventa = Historial::Instance->InsertarVenta(ahora, System::Decimal(totalVenta), "Vendedor");

		itemVenta^ temp = lista->item;
		for (int i = 0; i < lista->longitud; i++) { // Recorre la lista
			Granel^ refG = dynamic_cast<Granel^>(temp->producto);

			Unitario^ refU = dynamic_cast<Unitario^>(temp->producto);

			if (refG != nullptr) {
				Historial::Instance->InsertarDetalleVenta(idventa, refG->Id, refG->Nombre, temp->cantidad, refG->Precio);
				refG->cantidad = System::Decimal::Add(System::Decimal::Negate(static_cast<System::Decimal>(temp->cantidad)), static_cast<System::Decimal>(refG->cantidad));
				if (refG->cantidad->CompareTo(System::Decimal::Zero) == 0) {
					Datos::Instance->borrarPorId(refG->Id);
				}
			}
			else if (refU != nullptr) {
				refU->cantidad -= System::Convert::ToInt32(temp->cantidad);
				if (refU->cantidad == 0) {
					Datos::Instance->borrarPorId(refU->Id);
				}
				Historial::Instance->InsertarDetalleVenta(idventa, refU->Id, refU->Nombre, temp->cantidad, refU->Precio);
			}

			temp = temp->next;
		}
		MessageBox::Show("Venta realizada correctamente, total a cobrar: S/." + totalVenta);

		lista->vaciarLista();
		DibujaListaVenta();
		Historial::Instance->cierraHistorial();
	}
		   //---------------------------------------------------------------------------------------------------
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

				System::String^ unidad = "";

				switch (seleccionador_unidad->SelectedIndex)
				{
				case 0:
					unidad = "Kg";
					break;
				case 1:
					unidad = "g";
					break;
				case 2:
					unidad = "L";
					break;
				case 3:
					unidad = "mL";
					break;
				}

				Granel^ nuevo = gcnew Granel(txt_prodName->Text, id, incrementador_precio->Value, incrementador_cantidad->Value, unidad);
				Datos::Instance->addProducto(nuevo);
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
				Datos::Instance->addProducto(nuevo);
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
		seleccionador_unidad->SelectedIndex = 0;;
		seleccionador_unidad->Text = "Seleccione una unidad...";
		L_unidadPrecio->Text = "";
		L_unidad->Text = "";
	}

		   // ---------------------------------------------------------------------------------------------------- Guarda los cambios tabla de productos
	private: System::Void bttn_actualizarDatosTabla_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Collections::Generic::List<Producto^>^ productos = Datos::Instance->obtenerTodosProducto(); //obten los productos

		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^\\s*(\\d+(?:\\.\\d+)?)\\s*(\\w*)\\s*$"); //Regex para obtener la unidad

		for (int i = 0; i < Tabla_productos->Rows->Count; i++)
		{
			System::String^ nombre = System::Convert::ToString(Tabla_productos->Rows[i]->Cells["data_nombre"]->Value);
			int id = System::Convert::ToInt32(Tabla_productos->Rows[i]->Cells["data_ID"]->Value);
			System::Decimal^ precio = System::Convert::ToDecimal(Tabla_productos->Rows[i]->Cells["data_precio"]->Value);

			System::String^ cantidadString = System::Convert::ToString(Tabla_productos->Rows[i]->Cells["data_Cantidad"]->Value);
			System::Text::RegularExpressions::Match^ match = regex->Match(cantidadString);
			System::Decimal^ cantidadG;
			System::String^ unidad;
			int cantidadU;

			if (match->Success) { //es granel?
				cantidadG = System::Convert::ToDecimal(match->Groups[1]->Value); //obten el numero detectado
				unidad = System::Convert::ToString(match->Groups[2]->Value);

				if (unidad->Equals("Kg") || unidad->Equals("g") || unidad->Equals("L") || unidad->Equals("mL")) //Es granel
				{
					Producto^ e = Datos::Instance->buscarProductoId(id); //obten el producto

					Granel^ auxG = dynamic_cast<Granel^>(e); //castealo a un granel

					if (cantidadG->CompareTo(System::Decimal::Zero) == 0) { // Si la cantidad es 0 borra el producto
						Datos::Instance->borrarPorId(id);
						Datos::Instance->borrarGranelDB(id);
					}

					if (auxG != nullptr) {
						auxG->cantidad = cantidadG;
						auxG->Nombre = nombre;
						auxG->Precio = precio;
						auxG->unidad = unidad;
						Datos::Instance->actualizaDatos(nombre, id);
					}
					delete e;
				}
				else if (unidad->Equals("")) { //Es unitario
					cantidadU = System::Convert::ToInt32(Tabla_productos->Rows[i]->Cells["data_Cantidad"]->Value);
					Producto^ e = Datos::Instance->buscarProductoId(id);

					Unitario^ auxU = dynamic_cast<Unitario^>(e);

					if (cantidadU == 0) { // Si la cantidad es 0 borra el producto
						Datos::Instance->borrarPorId(id);
						Datos::Instance->borrarUnitarioDB(id);
					}

					if (auxU != nullptr) {
						auxU->Nombre = nombre;
						auxU->cantidad = cantidadU;
						auxU->Precio = precio;
						Datos::Instance->actualizaDatos(nombre, id);
					}
					delete e;
				}
				else {
					MessageBox::Show("Unidad desconocida en el producto: " + nombre + "\nporfavor intente con las unidades aceptadas:\nKg, g, L, mL");
				}
			}


		}
		MessageBox::Show("Datos actualizados\n(Si se le notifico un error, ese producto no se modificó)");
		Datos::Instance->GuardarDatos();
		dibujaListaProducto();
		delete regex;
	}
		   //------------------------------------------------------------ Boton de cancelar cambios lista
	private: System::Void bttn_cancelarCambios_Click(System::Object^ sender, System::EventArgs^ e)
	{
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
		   //------------------------------------- click del boton de guardar cambios en Ventas -------------------------------------------------
	private: System::Void bttn_añadir2Lista_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^\\s*(\\d+(?:\\.\\d+)?)\\s*(\\w*)\\s*$");

		for (int i = 0; i < lista->longitud; i++) {
			int id = System::Convert::ToInt32(tabla_venta->Rows[i]->Cells["c_id"]->Value);
			System::String^ cantidad = System::Convert::ToString(tabla_venta->Rows[i]->Cells["c_cantidad"]->Value);
			System::Text::RegularExpressions::Match^ match = regex->Match(cantidad);

			itemVenta^ auxiliar = lista->getItem(id);

			if (auxiliar != nullptr) {
				System::String^ unidad = auxiliar->unidad;

				if (match->Success) {
					System::Decimal^ canti_extraida = gcnew Decimal(0.0);
					canti_extraida = System::Convert::ToDecimal(match->Groups[1]->Value);

					if (!unidad->Equals("")) {		// Granel

						if (canti_extraida->CompareTo(System::Decimal::Zero) == 0) {
							lista->borraItem(id);
							Datos::Instance->borrarGranelDB(id);
						}
						if (compruebaCantidad(auxiliar, canti_extraida) == 0) {
							auxiliar->cantidad = canti_extraida;
							auxiliar->recalcularSubtotal();
						}
					}
					else if (unidad->Equals("")) {	//Unitario

						canti_extraida = System::Decimal::Truncate(static_cast<System::Decimal>(canti_extraida));

						if (canti_extraida->CompareTo(System::Decimal::Zero) == 0) {
							lista->borraItem(id);
							Datos::Instance->borrarUnitarioDB(id);
						}

						if (compruebaCantidad(auxiliar, canti_extraida) == 0)
						{
							auxiliar->cantidad = canti_extraida;
							auxiliar->recalcularSubtotal();
						}
					}

				}
			}

		}
		Datos::Instance->GuardarDatos();
		DibujaListaVenta();
	}
		   //------------------------------------- doble click en la lista de busqueda -------------------------------------------------
	private: System::Void list_busqueda_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		int index = list_busqueda->IndexFromPoint(e->Location);
		if (index == -1) {
			txt_busqueda->Text = "";
			return;
		}

		System::String^ aux = list_busqueda->SelectedItem->ToString();

		aux = aux->ToLower();

		if (compruebaRepeticion(aux) == 1) {
			list_busqueda->Enabled = false;
			txt_busqueda->Text = "";
			return;
		}

		Producto^ productoAux = Datos::Instance->buscarProductoNombre(aux);

		if (productoAux != nullptr) {
			Granel^ tempGra = dynamic_cast<Granel^>(productoAux);
			if (tempGra != nullptr) {
				lista->agregarGranel(tempGra, 1);
				DibujaListaVenta();
				list_busqueda->Enabled = false;
				txt_busqueda->Text = "";
				return;
			}
			Unitario^ tempgUni = dynamic_cast<Unitario^>(productoAux);
			if (tempgUni != nullptr) {
				lista->agregarUnitario(tempgUni, 1);
				DibujaListaVenta();
				list_busqueda->Enabled = false;
				txt_busqueda->Text = "";
				return;
			}

		}
		else {
			MessageBox::Show("Ocurrio un error inesperado, nada a cambiado");
			list_busqueda->Enabled = false;
			txt_busqueda->Text = "";
			return;
		}

	}
	private: void DibujaListaVenta() {

		ListaVenta^ temp = lista;
		itemVenta^ itemActual = temp->item;

		System::Decimal total;

		tabla_venta->Rows->Clear();

		while (itemActual != nullptr) {
			System::String^ nombre = itemActual->producto->Nombre;
			int id = itemActual->producto->Id;
			System::Decimal^ cantidad = itemActual->cantidad;
			System::Decimal^ subtotal = itemActual->subtotal;
			System::String^ unidad = itemActual->unidad;
			System::String^ cantidad_compuesta;

			total = System::Decimal::Add(total, static_cast<System::Decimal>(subtotal));

			if (!unidad->Equals("")) {
				cantidad_compuesta = cantidad->ToString() + " " + unidad;
			}
			else
			{
				cantidad_compuesta = cantidad->ToString();
			}

			tabla_venta->Rows->Add(nombre, id, cantidad_compuesta, subtotal);

			itemActual = itemActual->next; //siguiente item en la lista
		}

		numero_total_venta->Value = total;
	}
	private: int compruebaRepeticion(System::String^ nombre) {
		int idAux = Datos::Instance->nombre_Id(nombre);

		itemVenta^ temp = gcnew itemVenta();
		temp = lista->item;

		if (idAux != -1) {
			while (temp != nullptr) {
				if (temp->producto->Id == idAux) {// es producto seleccionado ya está en la lista
					MessageBox::Show("El producto ya se encuentra en la lista, si desea cambiar la cantidad hágalo en la tabla de ventas");
					return 1; // se encontró una repetición
				}
				temp = temp->next;
			}
		}
		return 0; // no se encontró repetición.
	}

	private: int compruebaCantidad(itemVenta^ item, System::Decimal^ cantidad)
	{
		Granel^ auxG = dynamic_cast<Granel^>(item->producto);
		Unitario^ auxU = dynamic_cast<Unitario^>(item->producto);
		if (auxG != nullptr) {
			if (auxG->cantidad->CompareTo(cantidad) < 0) { // Nueva cantidad inválida
				MessageBox::Show("Cantidad máxima disponible excedida\n El producto \"" + auxG->Nombre + "\" solo tiene disponibles: " + auxG->cantidad + " " + auxG->unidad);
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (auxU != nullptr) {
			if (auxU->cantidad < System::Convert::ToInt32(cantidad)) {
				MessageBox::Show("Cantidad máxima disponible excedida\n El producto \"" + auxU->Nombre + "\" solo tiene disponibles: " + auxU->cantidad + " Unidades");
				return 1;
			}
			else {
				return 0;
			}
		}
		return -1;
	}

	private: System::Void bttn_cancelarCambiosVenta_Click(System::Object^ sender, System::EventArgs^ e) {
		DibujaListaVenta();
	}
	private: System::Void bttn_cancelaVenta_Click(System::Object^ sender, System::EventArgs^ e) {
		lista->vaciarLista();
		DibujaListaVenta();
	}

	private: void dibujaListaProducto() {
		Tabla_productos->Rows->Clear(); //limpia los datos
		System::Collections::Generic::List<Producto^>^ productos = Datos::Instance->obtenerTodosProducto();
		for each (Producto ^ prod in  productos) {
			Granel^ gra = dynamic_cast<Granel^>(prod);
			if (gra != nullptr) { //es granel
				System::String^ cantidad = gra->cantidad->ToString() + " " + gra->unidad;
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

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		frm_Historial^ frm = gcnew frm_Historial(this);
		frm->Show();
		this->Hide();
	}
	};
}
