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
	/// Summary for SaveArrayForm
	/// </summary>
	public ref class SaveArrayForm : public System::Windows::Forms::Form
	{
	public:
		SaveArrayForm(void)
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
		~SaveArrayForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Load;
	protected:
	private: System::Windows::Forms::TextBox^ InputFile;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RadioButton^ AddData;
	private: System::Windows::Forms::RadioButton^ RewriteData;

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
			this->AddData = (gcnew System::Windows::Forms::RadioButton());
			this->RewriteData = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// Load
			// 
			this->Load->Enabled = false;
			this->Load->Location = System::Drawing::Point(74, 104);
			this->Load->Name = L"Load";
			this->Load->Size = System::Drawing::Size(177, 30);
			this->Load->TabIndex = 22;
			this->Load->Text = L"Сохранить";
			this->Load->UseVisualStyleBackColor = true;
			this->Load->Click += gcnew System::EventHandler(this, &SaveArrayForm::Load_Click);
			// 
			// InputFile
			// 
			this->InputFile->Location = System::Drawing::Point(60, 24);
			this->InputFile->Name = L"InputFile";
			this->InputFile->Size = System::Drawing::Size(259, 20);
			this->InputFile->TabIndex = 21;
			this->InputFile->TextChanged += gcnew System::EventHandler(this, &SaveArrayForm::InputFile_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 27);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Файл:";
			// 
			// AddData
			// 
			this->AddData->AutoSize = true;
			this->AddData->Location = System::Drawing::Point(203, 66);
			this->AddData->Name = L"AddData";
			this->AddData->Size = System::Drawing::Size(116, 17);
			this->AddData->TabIndex = 23;
			this->AddData->Text = L"Добавить данные";
			this->AddData->UseVisualStyleBackColor = true;
			this->AddData->Click += gcnew System::EventHandler(this, &SaveArrayForm::AddData_Click);
			// 
			// RewriteData
			// 
			this->RewriteData->AutoSize = true;
			this->RewriteData->Location = System::Drawing::Point(18, 66);
			this->RewriteData->Name = L"RewriteData";
			this->RewriteData->Size = System::Drawing::Size(139, 17);
			this->RewriteData->TabIndex = 24;
			this->RewriteData->Text = L"Перезаписать данные";
			this->RewriteData->UseVisualStyleBackColor = true;
			this->RewriteData->Click += gcnew System::EventHandler(this, &SaveArrayForm::RewriteData_Click);
			// 
			// SaveArrayForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 162);
			this->Controls->Add(this->RewriteData);
			this->Controls->Add(this->AddData);
			this->Controls->Add(this->Load);
			this->Controls->Add(this->InputFile);
			this->Controls->Add(this->label6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"SaveArrayForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сохранение";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RewriteData_Click(System::Object^ sender, System::EventArgs^ e) {
		RewriteData->Checked = true;
		AddData->Checked = false;
	}

	private: System::Void AddData_Click(System::Object^ sender, System::EventArgs^ e) {
		AddData->Checked = true;
		RewriteData->Checked = false;
	}
	private: void UploadButton() {
		bool enableButton = InputFile->Text != "";
		Load->Enabled = enableButton;
	}
	private: System::Void InputFile_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UploadButton();
	}
	private: System::Void Load_Click(System::Object^ sender, System::EventArgs^ e) {
		if (RewriteData->Checked) {
			char* fileName = convertString(InputFile->Text);
			writeDataToFile(fileName);
			delete[] fileName;
			this->Close();
		}
		else {
			char* fileName = convertString(InputFile->Text);
			if (isExistFile(fileName)) {
				addDataToFile(fileName);
				this->Close();
			}
			else {
				MessageBox::Show("Файл с таким именем не сущетсвует!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			delete[] fileName;
		}
	}
	private: char* convertString(String^ str) {
		msclr::interop::marshal_context context;
		const char* chars = context.marshal_as<const char*>(str);
		char* result = new char[strlen(chars) + 1];
		strcpy(result, chars);
		return result;
	}
	};
}
