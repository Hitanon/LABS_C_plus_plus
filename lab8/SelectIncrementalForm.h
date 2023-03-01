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
	/// Summary for SelectIncrementalForm
	/// </summary>
	public ref class SelectIncrementalForm : public System::Windows::Forms::Form
	{
	public:
		SelectIncrementalForm(void)
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
		~SelectIncrementalForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ InputKX;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ InputX0;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ fillArray;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ inputKY;

	private: System::Windows::Forms::TextBox^ InputY0;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ InputKRadius;

	private: System::Windows::Forms::TextBox^ InputRadius0;


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
			this->InputKX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->InputX0 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fillArray = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inputKY = (gcnew System::Windows::Forms::TextBox());
			this->InputY0 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->InputKRadius = (gcnew System::Windows::Forms::TextBox());
			this->InputRadius0 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// InputKX
			// 
			this->InputKX->Location = System::Drawing::Point(84, 96);
			this->InputKX->Name = L"InputKX";
			this->InputKX->Size = System::Drawing::Size(73, 20);
			this->InputKX->TabIndex = 28;
			this->InputKX->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::InputK_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 27;
			this->label7->Text = L"Шаг:";
			// 
			// InputX0
			// 
			this->InputX0->Location = System::Drawing::Point(84, 53);
			this->InputX0->Name = L"InputX0";
			this->InputX0->Size = System::Drawing::Size(73, 20);
			this->InputX0->TabIndex = 26;
			this->InputX0->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::InputX0_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 47);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 26);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Начальное\r\nзначение:\r\n";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Введите:";
			// 
			// fillArray
			// 
			this->fillArray->Enabled = false;
			this->fillArray->Location = System::Drawing::Point(15, 136);
			this->fillArray->Name = L"fillArray";
			this->fillArray->Size = System::Drawing::Size(319, 33);
			this->fillArray->TabIndex = 29;
			this->fillArray->Text = L"Заполнить массив";
			this->fillArray->UseVisualStyleBackColor = true;
			this->fillArray->Click += gcnew System::EventHandler(this, &SelectIncrementalForm::fillArray_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(109, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 30;
			this->label2->Text = L"X:";
			this->label2->Click += gcnew System::EventHandler(this, &SelectIncrementalForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(197, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 33;
			this->label3->Text = L"Y:";
			// 
			// inputKY
			// 
			this->inputKY->Location = System::Drawing::Point(172, 96);
			this->inputKY->Name = L"inputKY";
			this->inputKY->Size = System::Drawing::Size(72, 20);
			this->inputKY->TabIndex = 32;
			this->inputKY->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::inputKY_TextChanged);
			// 
			// InputY0
			// 
			this->InputY0->Location = System::Drawing::Point(172, 53);
			this->InputY0->Name = L"InputY0";
			this->InputY0->Size = System::Drawing::Size(72, 20);
			this->InputY0->TabIndex = 31;
			this->InputY0->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::InputY0_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(273, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Радиус:";
			// 
			// InputKRadius
			// 
			this->InputKRadius->Location = System::Drawing::Point(261, 96);
			this->InputKRadius->Name = L"InputKRadius";
			this->InputKRadius->Size = System::Drawing::Size(73, 20);
			this->InputKRadius->TabIndex = 35;
			this->InputKRadius->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::InputKRadius_TextChanged);
			// 
			// InputRadius0
			// 
			this->InputRadius0->Location = System::Drawing::Point(261, 53);
			this->InputRadius0->Name = L"InputRadius0";
			this->InputRadius0->Size = System::Drawing::Size(73, 20);
			this->InputRadius0->TabIndex = 34;
			this->InputRadius0->TextChanged += gcnew System::EventHandler(this, &SelectIncrementalForm::InputRadius0_TextChanged);
			// 
			// SelectIncrementalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(346, 181);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->InputKRadius);
			this->Controls->Add(this->InputRadius0);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->inputKY);
			this->Controls->Add(this->InputY0);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->fillArray);
			this->Controls->Add(this->InputKX);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->InputX0);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"SelectIncrementalForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ввод параметров";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void fillArray_Click(System::Object^ sender, System::EventArgs^ e) {
		int x0, y0, radius0, stepX, stepY, stepRadius;
		if (int::TryParse(InputX0->Text, x0) && int::TryParse(InputY0->Text, y0)
			&& int::TryParse(InputRadius0->Text, radius0) && int::TryParse(InputKX->Text, stepX)
			&& int::TryParse(inputKY->Text, stepY) && int::TryParse(InputKRadius->Text, stepRadius)) {
			if (radius0 > 0) {
				if (radius0 + stepRadius * size > 0) {
					createArray();
					fillArrayIncremental(x0, y0, radius0, stepX, stepY, stepRadius);
					this->Close();
					isUpdateArray = true;
				}
				else {
					MessageBox::Show("При таком шаге и размерности радиус становится меньше 0!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

			}
			else {
				MessageBox::Show("Радиус и шаг его изменения должны быть больше 0!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Должны быть введены только целые числа!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: void UpdateButton() {
		bool enableButton = InputX0->Text != "" && InputKX->Text != ""
			&& InputY0->Text != "" && inputKY->Text != ""
			&& InputRadius0->Text != "" && InputKRadius->Text != "";
		fillArray->Enabled = enableButton;
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void InputK_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void InputX0_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void InputY0_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void InputRadius0_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void inputKY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	private: System::Void InputKRadius_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateButton();
	}
	};
}
