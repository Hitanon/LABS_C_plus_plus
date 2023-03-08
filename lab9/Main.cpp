#include "MainForm.h"
#include "CurrentTempSensor.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace lab9;

[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm^ mainForm = gcnew MainForm();
	Application::Run(mainForm);
	deletArraySensors();
}