#pragma once
#include "frm_MenuPrincipal.h"
#include "Datos.h"

namespace GUIEstructuraDeDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class frm_Login : public System::Windows::Forms::Form
	{
	public:
		frm_Login(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frm_Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ L_inicioSesion;
	private: System::Windows::Forms::TextBox^ txt_User;
	private: System::Windows::Forms::Label^ L_user;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_Pass;
	private: System::Windows::Forms::Button^ bttn_inicar;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ L_estadoSesion;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_Login::typeid));
			this->L_inicioSesion = (gcnew System::Windows::Forms::Label());
			this->txt_User = (gcnew System::Windows::Forms::TextBox());
			this->L_user = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_Pass = (gcnew System::Windows::Forms::TextBox());
			this->bttn_inicar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->L_estadoSesion = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// L_inicioSesion
			// 
			this->L_inicioSesion->AutoSize = true;
			this->L_inicioSesion->Font = (gcnew System::Drawing::Font(L"Fira Code", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_inicioSesion->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->L_inicioSesion->Location = System::Drawing::Point(43, 46);
			this->L_inicioSesion->MinimumSize = System::Drawing::Size(275, 43);
			this->L_inicioSesion->Name = L"L_inicioSesion";
			this->L_inicioSesion->Size = System::Drawing::Size(275, 43);
			this->L_inicioSesion->TabIndex = 0;
			this->L_inicioSesion->Text = L"Inicio de Sesión";
			this->L_inicioSesion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_User
			// 
			this->txt_User->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_User->Location = System::Drawing::Point(45, 154);
			this->txt_User->Name = L"txt_User";
			this->txt_User->Size = System::Drawing::Size(267, 23);
			this->txt_User->TabIndex = 1;
			// 
			// L_user
			// 
			this->L_user->AutoSize = true;
			this->L_user->Font = (gcnew System::Drawing::Font(L"Fira Code", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_user->Location = System::Drawing::Point(45, 118);
			this->L_user->Name = L"L_user";
			this->L_user->Size = System::Drawing::Size(106, 33);
			this->L_user->TabIndex = 2;
			this->L_user->Text = L"Usuario";
			this->L_user->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Fira Code", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(45, 210);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Contraseña";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txt_Pass
			// 
			this->txt_Pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Pass->Location = System::Drawing::Point(45, 246);
			this->txt_Pass->Name = L"txt_Pass";
			this->txt_Pass->PasswordChar = '*';
			this->txt_Pass->Size = System::Drawing::Size(267, 23);
			this->txt_Pass->TabIndex = 4;
			this->txt_Pass->UseSystemPasswordChar = true;
			// 
			// bttn_inicar
			// 
			this->bttn_inicar->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_inicar->Location = System::Drawing::Point(100, 295);
			this->bttn_inicar->Name = L"bttn_inicar";
			this->bttn_inicar->Size = System::Drawing::Size(165, 37);
			this->bttn_inicar->TabIndex = 5;
			this->bttn_inicar->Text = L"Iniciar Sesión";
			this->bttn_inicar->UseVisualStyleBackColor = true;
			this->bttn_inicar->Click += gcnew System::EventHandler(this, &frm_Login::bttn_inicar_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->L_estadoSesion);
			this->panel1->Controls->Add(this->L_inicioSesion);
			this->panel1->Controls->Add(this->L_user);
			this->panel1->Controls->Add(this->bttn_inicar);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->txt_Pass);
			this->panel1->Controls->Add(this->txt_User);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(393, 420);
			this->panel1->TabIndex = 6;
			// 
			// L_estadoSesion
			// 
			this->L_estadoSesion->AutoSize = true;
			this->L_estadoSesion->Font = (gcnew System::Drawing::Font(L"Fira Code", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_estadoSesion->ForeColor = System::Drawing::Color::Red;
			this->L_estadoSesion->Location = System::Drawing::Point(111, 350);
			this->L_estadoSesion->Name = L"L_estadoSesion";
			this->L_estadoSesion->Size = System::Drawing::Size(0, 19);
			this->L_estadoSesion->TabIndex = 6;
			this->L_estadoSesion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Fira Code", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(400, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(456, 420);
			this->panel2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Fira Code", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(78, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(269, 76);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Sistema de Almacén\r\ny Venta";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(166, 51);
			this->label2->MinimumSize = System::Drawing::Size(125, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 125);
			this->label2->TabIndex = 0;
			// 
			// frm_Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 421);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(870, 460);
			this->MinimumSize = System::Drawing::Size(870, 460);
			this->Name = L"frm_Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inicio de Sesión";
			this->Activated += gcnew System::EventHandler(this, &frm_Login::frm_Login_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_Login::frm_Login_FormClosing);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bttn_inicar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = txt_User->Text;
		String^ pass = txt_Pass->Text;
		if (user == Datos::Instance->Username && pass == Datos::Instance->Password) {
			L_estadoSesion->Text = "Sesión iniciada!";
			frm_MenuPrincipal^ menuPrincipal = gcnew frm_MenuPrincipal(this); // Inicializa la nueva ventana
			menuPrincipal->Show();
			this->Hide();
		}
		else {
			L_estadoSesion->Text = "Usuario o Contraseña Incorrecto";
			txt_User->Text = "";
			txt_Pass->Text = "";
		}
	}
	private: System::Void frm_Login_Activated(System::Object^ sender, System::EventArgs^ e) { // Reinicia los contenedores y labels al cargar
		L_estadoSesion->Text = "";
		txt_User->Text = "";
		txt_Pass->Text = "";
	}
	private: System::Void frm_Login_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Datos::Instance->~Datos();
	}
};
}
