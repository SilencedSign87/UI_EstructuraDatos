#pragma once
#include"Datos.h"
namespace GUIEstructuraDeDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frm_CambiarCred
	/// </summary>
	public ref class frm_CambiarCred : public System::Windows::Forms::Form
	{
	public:
		frm_CambiarCred(System::Windows::Forms::Form^ previousForm)
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
		~frm_CambiarCred()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ previousForm; //form anterior

	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bttn_Confirmar;
	private: System::Windows::Forms::TextBox^ txt_pass;

	private: System::Windows::Forms::TextBox^ txt_user;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ L_Nuser;
	private: System::Windows::Forms::TextBox^ txt_Npass;


	private: System::Windows::Forms::Label^ L_Npass;
	private: System::Windows::Forms::TextBox^ txt_Nuser;
	private: System::Windows::Forms::Button^ bttn_cambiar;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frm_CambiarCred::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bttn_cambiar = (gcnew System::Windows::Forms::Button());
			this->txt_Npass = (gcnew System::Windows::Forms::TextBox());
			this->L_Npass = (gcnew System::Windows::Forms::Label());
			this->txt_Nuser = (gcnew System::Windows::Forms::TextBox());
			this->L_Nuser = (gcnew System::Windows::Forms::Label());
			this->bttn_Confirmar = (gcnew System::Windows::Forms::Button());
			this->txt_pass = (gcnew System::Windows::Forms::TextBox());
			this->txt_user = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Fira Code", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(260, 560);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 505);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 27);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frm_CambiarCred::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(65, 41);
			this->label1->MinimumSize = System::Drawing::Size(125, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 125);
			this->label1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->bttn_cambiar);
			this->panel2->Controls->Add(this->txt_Npass);
			this->panel2->Controls->Add(this->L_Npass);
			this->panel2->Controls->Add(this->txt_Nuser);
			this->panel2->Controls->Add(this->L_Nuser);
			this->panel2->Controls->Add(this->bttn_Confirmar);
			this->panel2->Controls->Add(this->txt_pass);
			this->panel2->Controls->Add(this->txt_user);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Fira Code", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(270, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(460, 560);
			this->panel2->TabIndex = 1;
			// 
			// bttn_cambiar
			// 
			this->bttn_cambiar->Enabled = false;
			this->bttn_cambiar->Location = System::Drawing::Point(100, 475);
			this->bttn_cambiar->Name = L"bttn_cambiar";
			this->bttn_cambiar->Size = System::Drawing::Size(253, 33);
			this->bttn_cambiar->TabIndex = 9;
			this->bttn_cambiar->Text = L"Cambiar Credenciales";
			this->bttn_cambiar->UseVisualStyleBackColor = true;
			this->bttn_cambiar->Visible = false;
			this->bttn_cambiar->Click += gcnew System::EventHandler(this, &frm_CambiarCred::bttn_cambiar_Click);
			// 
			// txt_Npass
			// 
			this->txt_Npass->Enabled = false;
			this->txt_Npass->Location = System::Drawing::Point(50, 425);
			this->txt_Npass->Name = L"txt_Npass";
			this->txt_Npass->PasswordChar = '*';
			this->txt_Npass->Size = System::Drawing::Size(351, 28);
			this->txt_Npass->TabIndex = 8;
			this->txt_Npass->UseSystemPasswordChar = true;
			this->txt_Npass->Visible = false;
			// 
			// L_Npass
			// 
			this->L_Npass->AutoSize = true;
			this->L_Npass->Enabled = false;
			this->L_Npass->Location = System::Drawing::Point(50, 400);
			this->L_Npass->Name = L"L_Npass";
			this->L_Npass->Size = System::Drawing::Size(182, 25);
			this->L_Npass->TabIndex = 7;
			this->L_Npass->Text = L"Nueva contraseña:";
			this->L_Npass->Visible = false;
			// 
			// txt_Nuser
			// 
			this->txt_Nuser->Enabled = false;
			this->txt_Nuser->Location = System::Drawing::Point(50, 350);
			this->txt_Nuser->Name = L"txt_Nuser";
			this->txt_Nuser->Size = System::Drawing::Size(351, 28);
			this->txt_Nuser->TabIndex = 6;
			this->txt_Nuser->Visible = false;
			// 
			// L_Nuser
			// 
			this->L_Nuser->AutoSize = true;
			this->L_Nuser->Enabled = false;
			this->L_Nuser->Location = System::Drawing::Point(50, 325);
			this->L_Nuser->Name = L"L_Nuser";
			this->L_Nuser->Size = System::Drawing::Size(152, 25);
			this->L_Nuser->TabIndex = 5;
			this->L_Nuser->Text = L"Nuevo usuario:";
			this->L_Nuser->Visible = false;
			// 
			// bttn_Confirmar
			// 
			this->bttn_Confirmar->Location = System::Drawing::Point(100, 200);
			this->bttn_Confirmar->Name = L"bttn_Confirmar";
			this->bttn_Confirmar->Size = System::Drawing::Size(253, 33);
			this->bttn_Confirmar->TabIndex = 4;
			this->bttn_Confirmar->Text = L"Confirmar Credenciales";
			this->bttn_Confirmar->UseVisualStyleBackColor = true;
			this->bttn_Confirmar->Click += gcnew System::EventHandler(this, &frm_CambiarCred::bttn_Confirmar_Click);
			// 
			// txt_pass
			// 
			this->txt_pass->Location = System::Drawing::Point(50, 150);
			this->txt_pass->Name = L"txt_pass";
			this->txt_pass->PasswordChar = '*';
			this->txt_pass->Size = System::Drawing::Size(351, 28);
			this->txt_pass->TabIndex = 3;
			this->txt_pass->UseSystemPasswordChar = true;
			// 
			// txt_user
			// 
			this->txt_user->Location = System::Drawing::Point(50, 75);
			this->txt_user->Name = L"txt_user";
			this->txt_user->Size = System::Drawing::Size(351, 28);
			this->txt_user->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Contraseña actual:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Usuario actual:";
			// 
			// frm_CambiarCred
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 561);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(750, 600);
			this->MinimumSize = System::Drawing::Size(750, 600);
			this->Name = L"frm_CambiarCred";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cambio de Credenciales";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frm_CambiarCred::frm_CambiarCred_FormClosing);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
			this->Close();
		}
	}
	private: System::Void frm_CambiarCred_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
		}
	}
	private: System::Void bttn_Confirmar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (txt_user->Text == Datos::Instance->Username && txt_pass->Text == Datos::Instance->Password) {
			L_Nuser->Enabled = true;
			L_Nuser->Visible = true;
			L_Npass->Enabled = true;
			L_Npass->Visible = true;
			txt_Npass->Enabled = true;
			txt_Npass->Visible = true;
			txt_Nuser->Enabled = true;
			txt_Nuser->Visible = true;
			bttn_cambiar->Enabled = true;
			bttn_cambiar->Visible = true;
		}
		else {
			MessageBox::Show("Usuario o contraseña incorrectos");
			txt_user->Text = "";
			txt_pass->Text = "";
		}
	}
	private: System::Void bttn_cambiar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Datos::Instance->Password = txt_Npass->Text;
		Datos::Instance->Username = txt_Nuser->Text;
		if (this->previousForm != nullptr) {
			this->previousForm->Show();
			MessageBox::Show("Usuario o contraseña actualizados");
			this->Close();
		}
	}
	};
}
