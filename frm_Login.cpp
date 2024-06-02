#include "frm_Login.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	GUIEstructuraDeDatos::frm_Login frm;
	Application::Run(% frm);
}
