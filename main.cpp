#include "pch.h"
#include "FrmJuego.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew JuegoDesdeCero::FrmJuego());
    return 0;
}