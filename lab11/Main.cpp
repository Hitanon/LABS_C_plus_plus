#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace lab11;

[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
}