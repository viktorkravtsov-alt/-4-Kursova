#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LB4Forms::MyForm^ form = gcnew LB4Forms::MyForm();
    Application::Run(form);
    return 0;
}
