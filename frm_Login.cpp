#include "frm_Login.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
//[STAThreadAttribute]

//void main(array<String^>^ args) {
//	Application::SetCompatibleTextRenderingDefault(false);
//	Application::EnableVisualStyles();
//	GUIEstructuraDeDatos::frm_Login frm;
//	Application::Run(% frm);
//}

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    GUIEstructuraDeDatos::frm_Login form;
    Application::Run(% form);
    return 0;
}
