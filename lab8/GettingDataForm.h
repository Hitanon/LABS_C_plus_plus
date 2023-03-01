#pragma once
#include "Program.h"
#include "SelectIncrementalForm.h"
#include "SelectManualForm.h"

namespace lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GettingDataForm
	/// </summary>
	public ref class GettingDataForm : public System::Windows::Forms::Form
	{
	public:
		GettingDataForm(void)
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
		~GettingDataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ InputCenter;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ FillRandom;
	private: System::Windows::Forms::Button^ FillIncremental;
	private: System::Windows::Forms::Button^ FillManual;




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
			this->InputCenter = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->FillRandom = (gcnew System::Windows::Forms::Button());
			this->FillIncremental = (gcnew System::Windows::Forms::Button());
			this->FillManual = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// InputCenter
			// 
			this->InputCenter->Location = System::Drawing::Point(102, 21);
			this->InputCenter->Name = L"InputCenter";
			this->InputCenter->Size = System::Drawing::Size(87, 20);
			this->InputCenter->TabIndex = 15;
			this->InputCenter->TextChanged += gcnew System::EventHandler(this, &GettingDataForm::InputCenter_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 24);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Размерность:";
			// 
			// FillRandom
			// 
			this->FillRandom->Enabled = false;
			this->FillRandom->Location = System::Drawing::Point(21, 64);
			this->FillRandom->Name = L"FillRandom";
			this->FillRandom->Size = System::Drawing::Size(177, 30);
			this->FillRandom->TabIndex = 16;
			this->FillRandom->Text = L"Случайные числа";
			this->FillRandom->UseVisualStyleBackColor = true;
			this->FillRandom->Click += gcnew System::EventHandler(this, &GettingDataForm::FillRandom_Click);
			// 
			// FillIncremental
			// 
			this->FillIncremental->Enabled = false;
			this->FillIncremental->Location = System::Drawing::Point(21, 100);
			this->FillIncremental->Name = L"FillIncremental";
			this->FillIncremental->Size = System::Drawing::Size(177, 49);
			this->FillIncremental->TabIndex = 17;
			this->FillIncremental->Text = L"По порядку от начального\r\nзначения с шагом k\r\n";
			this->FillIncremental->UseVisualStyleBackColor = true;
			this->FillIncremental->Click += gcnew System::EventHandler(this, &GettingDataForm::FillIncremental_Click);
			// 
			// FillManual
			// 
			this->FillManual->Enabled = false;
			this->FillManual->Location = System::Drawing::Point(21, 156);
			this->FillManual->Name = L"FillManual";
			this->FillManual->Size = System::Drawing::Size(177, 33);
			this->FillManual->TabIndex = 18;
			this->FillManual->Text = L"Вручную";
			this->FillManual->UseVisualStyleBackColor = true;
			this->FillManual->Click += gcnew System::EventHandler(this, &GettingDataForm::FillManual_Click);
			// 
			// GettingDataForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(218, 208);
			this->Controls->Add(this->FillManual);
			this->Controls->Add(this->FillIncremental);
			this->Controls->Add(this->FillRandom);
			this->Controls->Add(this->InputCenter);
			this->Controls->Add(this->label6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"GettingDataForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Заполнение";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void InputCenter_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (InputCenter->Text->Length > 0) {
			FillRandom->Enabled = true;
			FillIncremental->Enabled = true;
			FillManual->Enabled = true;
		}
		else {
			FillRandom->Enabled = false;
			FillIncremental->Enabled = false;
			FillManual->Enabled = false;
		}
	}
	private: System::Void FillRandom_Click(System::Object^ sender, System::EventArgs^ e) {
		if (int::TryParse(InputCenter->Text, size)) {
			if (size > 0) {
				createArray();
				fillArrayRandom();
				this->Close();
			}
			else {
				MessageBox::Show("Размерность массива должна быть больше 0!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Размерность массива - целое неотрицательное число!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void FillIncremental_Click(System::Object^ sender, System::EventArgs^ e) {
		int temp = size;
		if (int::TryParse(InputCenter->Text, size)) {
			if ( size > 0) {
				SelectIncrementalForm^ selectIncrementalForm = gcnew SelectIncrementalForm();
				selectIncrementalForm->ShowDialog();
				if (isUpdateArray) {
					this->Close();
					isUpdateArray = false;
				}
				else {
					size = temp;
				}
			}
			else {
				MessageBox::Show("Размерность массива должна быть больше 0!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Размерность массива - целое неотрицательное число!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: void SetEnable(bool state) {
		this->Enabled = state;
	}
	private: System::Void FillManual_Click(System::Object^ sender, System::EventArgs^ e) {
		int temp = size;
		if (int::TryParse(InputCenter->Text, size)) {
			if (size > 0) {
				SelectManualForm^ selectManualForm = gcnew SelectManualForm();
				selectManualForm->ShowDialog();
				if (isUpdateArray) {
					this->Close();
					isUpdateArray = false;
				}
				else {
					size = temp;
				}
			}
			else {
				MessageBox::Show("Размерность массива должна быть больше 0!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Размерность массива - целое неотрицательное число!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
