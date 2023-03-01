#include "MainForm.h"
#include "GettingDataForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace lab8; // »м€ пространства имен из MainForm.h
[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm); // MainForm Ц им€ класса формы
}