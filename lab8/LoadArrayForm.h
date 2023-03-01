#pragma once
#include "Program.h"
#include <msclr/marshal.h>

namespace lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoadArrayForm
	/// </summary>
	public ref class LoadArrayForm : public System::Windows::Forms::Form
	{
	public:
		LoadArrayForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoadArrayForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Load;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ InputFile;
	protected:

	private: System::Windows::Forms::Label^ label6;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Load = (gcnew System::Windows::Forms::Button());
			this->InputFile = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Load
			// 
			this->Load->Enabled = false;
			this->Load->Location = System::Drawing::Point(96, 67);
			this->Load->Name = L"Load";
			this->Load->Size = System::Drawing::Size(177, 30);
			this->Load->TabIndex = 19;
			this->Load->Text = L"Загрузить";
			this->Load->UseVisualStyleBackColor = true;
			this->Load->Click += gcnew System::EventHandler(this, &LoadArrayForm::Load_Click);
			// 
			// InputFile
			// 
			this->InputFile->Location = System::Drawing::Point(70, 24);
			this->InputFile->Name = L"InputFile";
			this->InputFile->Size = System::Drawing::Size(259, 20);
			this->InputFile->TabIndex = 18;
			this->InputFile->TextChanged += gcnew System::EventHandler(this, &LoadArrayForm::InputFile_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 27);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Файл:";
			// 
			// LoadArrayForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(359, 116);
			this->Controls->Add(this->Load);
			this->Controls->Add(this->InputFile);
			this->Controls->Add(this->label6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"LoadArrayForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Загрузка массива";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoadArrayForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void InputFile_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UploadButton();
	}
	private: void UploadButton() {
		bool enableButton = InputFile->Text != "";
		Load->Enabled = enableButton;
	}

	private: char* convertString(String^ str) {
		msclr::interop::marshal_context context;
		const char* chars = context.marshal_as<const char*>(str);
		char* result = new char[strlen(chars) + 1];
		strcpy(result, chars);
		return result;
	}
	private: System::Void Load_Click(System::Object^ sender, System::EventArgs^ e) {
		char* fileName = convertString(InputFile->Text);
		if (isExistFile(fileName)) {
			size = countStringInFile(fileName);
			if (size != 0) {
				loadDataFromFile(fileName);
				this->Close();
			}
			else {
				MessageBox::Show("Файл пустой!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Файл с таким именем не сущетсвует!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		delete[] fileName;
	}
};
}
