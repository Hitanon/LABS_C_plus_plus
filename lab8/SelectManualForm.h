#pragma once
#include "Program.h"

namespace lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SelectManualForm
	/// </summary>
	public ref class SelectManualForm : public System::Windows::Forms::Form
	{
	public:
		SelectManualForm(void)
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
		~SelectManualForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ inputCircles;

	private: System::Windows::Forms::Button^ fillArray;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->inputCircles = (gcnew System::Windows::Forms::TextBox());
			this->fillArray = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ввод полей через пробел";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 37);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(239, 26);
			this->label6->TabIndex = 13;
			this->label6->Text = L"В каждой строке можно вводить только один\r\nэлемнет масива в формате: x y radius\r\n"
				L"";
			// 
			// inputCircles
			// 
			this->inputCircles->Location = System::Drawing::Point(12, 78);
			this->inputCircles->Multiline = true;
			this->inputCircles->Name = L"inputCircles";
			this->inputCircles->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->inputCircles->Size = System::Drawing::Size(282, 208);
			this->inputCircles->TabIndex = 14;
			this->inputCircles->TextChanged += gcnew System::EventHandler(this, &SelectManualForm::inputCircles_TextChanged);
			// 
			// fillArray
			// 
			this->fillArray->Enabled = false;
			this->fillArray->Location = System::Drawing::Point(12, 300);
			this->fillArray->Name = L"fillArray";
			this->fillArray->Size = System::Drawing::Size(285, 33);
			this->fillArray->TabIndex = 30;
			this->fillArray->Text = L"Заполнить массив";
			this->fillArray->UseVisualStyleBackColor = true;
			this->fillArray->Click += gcnew System::EventHandler(this, &SelectManualForm::fillArray_Click);
			// 
			// SelectManualForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(308, 360);
			this->Controls->Add(this->fillArray);
			this->Controls->Add(this->inputCircles);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"SelectManualForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ввод массива";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fillArray_Click(System::Object^ sender, System::EventArgs^ e) {
		if (inputCircles->Lines->Length == size) {
			int x, y, radius;
			array<String^>^ parts;
			createArray();
			for (int i = 0; i < size; i++) {
				if (!splitString(inputCircles->Lines[i], parts))
				{
					deleteArray();
					MessageBox::Show("Есть объект с неверным количество полей!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					break;
				}
				if (parseFilds(parts, x, y, radius)) {
					if (radius > 0) {
						setCircle(arrayCircles[i], x, y, radius);
					}
					else {
						deleteArray();
						MessageBox::Show("Есть объект с неверным значениями!", "Ошибка",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
						break;
					}
				}
				else {
					deleteArray();
					MessageBox::Show("Есть объект с неверным значениями!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					break;
				}
			}
			if (arrayCircles != nullptr) {
				this->Close();
				isUpdateArray = true;
			}
		}
		else {
			MessageBox::Show("Количество введенных объектов должно соответсвовать введенному размеру!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void inputCircles_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		updateButton();
	}
	private: void updateButton() {
		bool enableButton = inputCircles->Text != "";
		fillArray->Enabled = enableButton;
	}

	private: bool splitString(String^ input, array<String^>^% parts) {
		parts = input->Split(gcnew array<wchar_t>{' '}, 3, StringSplitOptions::None);
		if (parts->Length != 3) {
			return false;
		}
		return true;
	}

	private: bool parseFilds(array<String^>^ parts, int& x, int& y, int& radius) {
		if (int::TryParse(parts[0], x) && int::TryParse(parts[1], y) && int::TryParse(parts[2], radius))
			if (radius > 0)
				return true;
		return false;
	}
	};
}
