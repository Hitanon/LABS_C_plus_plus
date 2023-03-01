#include "GettingDataForm.h"
#include "LoadArrayForm.h"
#include "SaveArrayForm.h"
#include "Program.h"
#include <cmath>

#pragma once

namespace lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Menu;
	private: System::Windows::Forms::ToolStripMenuItem^ RefillArray;
	private: System::Windows::Forms::ToolStripMenuItem^ LoadArrayFromFile;
	private: System::Windows::Forms::ListBox^ ListBoxCircles;





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ InputRadius;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ SaveCircle;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RadioButton^ SearchMeanS;
	private: System::Windows::Forms::RadioButton^ MoveCircles;


	private: System::Windows::Forms::TextBox^ InputX;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ InputS2;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ InputLength;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::RadioButton^ DeleteCircles;
	private: System::Windows::Forms::TextBox^ InputS1;
	private: System::Windows::Forms::Button^ DoAction;



	private: System::Windows::Forms::ToolStripMenuItem^ SaveArrayToFile;
	private: System::Windows::Forms::TextBox^ InputY;

	private: System::Windows::Forms::Label^ label7;




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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RefillArray = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadArrayFromFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveArrayToFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ListBoxCircles = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->InputRadius = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SaveCircle = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SearchMeanS = (gcnew System::Windows::Forms::RadioButton());
			this->MoveCircles = (gcnew System::Windows::Forms::RadioButton());
			this->InputX = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->InputS2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->InputLength = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->DeleteCircles = (gcnew System::Windows::Forms::RadioButton());
			this->InputS1 = (gcnew System::Windows::Forms::TextBox());
			this->DoAction = (gcnew System::Windows::Forms::Button());
			this->InputY = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Menu });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(749, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Menu
			// 
			this->Menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->RefillArray, this->LoadArrayFromFile,
					this->SaveArrayToFile
			});
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(53, 20);
			this->Menu->Text = L"Меню";
			// 
			// RefillArray
			// 
			this->RefillArray->Name = L"RefillArray";
			this->RefillArray->Size = System::Drawing::Size(224, 22);
			this->RefillArray->Text = L"Заполнить массив";
			this->RefillArray->Click += gcnew System::EventHandler(this, &MainForm::RefillArray_Click);
			// 
			// LoadArrayFromFile
			// 
			this->LoadArrayFromFile->Name = L"LoadArrayFromFile";
			this->LoadArrayFromFile->Size = System::Drawing::Size(224, 22);
			this->LoadArrayFromFile->Text = L"Загрузить массив из файла";
			this->LoadArrayFromFile->Click += gcnew System::EventHandler(this, &MainForm::LoadArrayFromFile_Click);
			// 
			// SaveArrayToFile
			// 
			this->SaveArrayToFile->Name = L"SaveArrayToFile";
			this->SaveArrayToFile->Size = System::Drawing::Size(224, 22);
			this->SaveArrayToFile->Text = L"Сохранить массив в файл";
			this->SaveArrayToFile->Click += gcnew System::EventHandler(this, &MainForm::SaveArrayToFile_Click);
			// 
			// ListBoxCircles
			// 
			this->ListBoxCircles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ListBoxCircles->FormattingEnabled = true;
			this->ListBoxCircles->ItemHeight = 15;
			this->ListBoxCircles->Location = System::Drawing::Point(266, 64);
			this->ListBoxCircles->Name = L"ListBoxCircles";
			this->ListBoxCircles->Size = System::Drawing::Size(471, 484);
			this->ListBoxCircles->TabIndex = 1;
			this->ListBoxCircles->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ListBoxCircles_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Редактировать:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(263, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(211, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Массив структур \"Окружность\"\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 289);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Площадь:";
			// 
			// InputRadius
			// 
			this->InputRadius->Enabled = false;
			this->InputRadius->Location = System::Drawing::Point(74, 129);
			this->InputRadius->Name = L"InputRadius";
			this->InputRadius->Size = System::Drawing::Size(173, 20);
			this->InputRadius->TabIndex = 7;
			this->InputRadius->TextChanged += gcnew System::EventHandler(this, &MainForm::InputRadius_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 132);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Радиус:";
			// 
			// SaveCircle
			// 
			this->SaveCircle->Enabled = false;
			this->SaveCircle->Location = System::Drawing::Point(42, 163);
			this->SaveCircle->Name = L"SaveCircle";
			this->SaveCircle->Size = System::Drawing::Size(177, 30);
			this->SaveCircle->TabIndex = 8;
			this->SaveCircle->Text = L"Сохранить изменения";
			this->SaveCircle->UseVisualStyleBackColor = true;
			this->SaveCircle->Click += gcnew System::EventHandler(this, &MainForm::SaveCircle_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 16);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Действия с массивом:";
			// 
			// SearchMeanS
			// 
			this->SearchMeanS->AutoSize = true;
			this->SearchMeanS->Enabled = false;
			this->SearchMeanS->Location = System::Drawing::Point(15, 250);
			this->SearchMeanS->Name = L"SearchMeanS";
			this->SearchMeanS->Size = System::Drawing::Size(222, 30);
			this->SearchMeanS->TabIndex = 10;
			this->SearchMeanS->TabStop = true;
			this->SearchMeanS->Text = L"Найти среднюю площадь окружностей\r\nмассива, которые перескаются";
			this->SearchMeanS->UseVisualStyleBackColor = true;
			this->SearchMeanS->CheckedChanged += gcnew System::EventHandler(this, &MainForm::SearchMeanS_CheckedChanged);
			// 
			// MoveCircles
			// 
			this->MoveCircles->AutoSize = true;
			this->MoveCircles->Enabled = false;
			this->MoveCircles->Location = System::Drawing::Point(12, 322);
			this->MoveCircles->Name = L"MoveCircles";
			this->MoveCircles->Size = System::Drawing::Size(248, 30);
			this->MoveCircles->TabIndex = 11;
			this->MoveCircles->TabStop = true;
			this->MoveCircles->Text = L"Переместить в конец массива окружности,\r\nу которых площадь меньше заданной\r\n";
			this->MoveCircles->UseVisualStyleBackColor = true;
			this->MoveCircles->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MoveCircles_CheckedChanged);
			// 
			// InputX
			// 
			this->InputX->Enabled = false;
			this->InputX->Location = System::Drawing::Point(74, 64);
			this->InputX->Name = L"InputX";
			this->InputX->Size = System::Drawing::Size(173, 20);
			this->InputX->TabIndex = 13;
			this->InputX->TextChanged += gcnew System::EventHandler(this, &MainForm::InputX_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 67);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Центр (X):";
			// 
			// InputS2
			// 
			this->InputS2->Enabled = false;
			this->InputS2->Location = System::Drawing::Point(74, 359);
			this->InputS2->Name = L"InputS2";
			this->InputS2->Size = System::Drawing::Size(89, 20);
			this->InputS2->TabIndex = 16;
			this->InputS2->TextChanged += gcnew System::EventHandler(this, &MainForm::InputS2_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 362);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Площадь:";
			// 
			// InputLength
			// 
			this->InputLength->Enabled = false;
			this->InputLength->Location = System::Drawing::Point(75, 437);
			this->InputLength->Name = L"InputLength";
			this->InputLength->Size = System::Drawing::Size(89, 20);
			this->InputLength->TabIndex = 19;
			this->InputLength->TextChanged += gcnew System::EventHandler(this, &MainForm::InputLength_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(11, 440);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Длина:";
			// 
			// DeleteCircles
			// 
			this->DeleteCircles->AutoSize = true;
			this->DeleteCircles->Enabled = false;
			this->DeleteCircles->Location = System::Drawing::Point(12, 398);
			this->DeleteCircles->Name = L"DeleteCircles";
			this->DeleteCircles->Size = System::Drawing::Size(229, 30);
			this->DeleteCircles->TabIndex = 17;
			this->DeleteCircles->TabStop = true;
			this->DeleteCircles->Text = L"Удалить из массива окружности, длина\r\nкоторых больше заданной";
			this->DeleteCircles->UseVisualStyleBackColor = true;
			this->DeleteCircles->CheckedChanged += gcnew System::EventHandler(this, &MainForm::DeleteCircles_CheckedChanged);
			// 
			// InputS1
			// 
			this->InputS1->Enabled = false;
			this->InputS1->Location = System::Drawing::Point(75, 286);
			this->InputS1->Name = L"InputS1";
			this->InputS1->ReadOnly = true;
			this->InputS1->Size = System::Drawing::Size(89, 20);
			this->InputS1->TabIndex = 20;
			// 
			// DoAction
			// 
			this->DoAction->Enabled = false;
			this->DoAction->Location = System::Drawing::Point(42, 479);
			this->DoAction->Name = L"DoAction";
			this->DoAction->Size = System::Drawing::Size(177, 45);
			this->DoAction->TabIndex = 21;
			this->DoAction->Text = L"Выполнить выбранное действие";
			this->DoAction->UseVisualStyleBackColor = true;
			this->DoAction->Click += gcnew System::EventHandler(this, &MainForm::DoAction_Click);
			// 
			// InputY
			// 
			this->InputY->Enabled = false;
			this->InputY->Location = System::Drawing::Point(74, 97);
			this->InputY->Name = L"InputY";
			this->InputY->Size = System::Drawing::Size(173, 20);
			this->InputY->TabIndex = 23;
			this->InputY->TextChanged += gcnew System::EventHandler(this, &MainForm::InputY_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 100);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Центр (Y):";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 560);
			this->Controls->Add(this->InputY);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->DoAction);
			this->Controls->Add(this->InputS1);
			this->Controls->Add(this->InputLength);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->DeleteCircles);
			this->Controls->Add(this->InputS2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->InputX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->MoveCircles);
			this->Controls->Add(this->SearchMeanS);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->SaveCircle);
			this->Controls->Add(this->InputRadius);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ListBoxCircles);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вариант 5";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void RefillArray_Click(System::Object^ sender, System::EventArgs^ e) {
		GettingDataForm^ gettindDataForm = gcnew GettingDataForm();
		gettindDataForm->ShowDialog();
		if (arrayCircles != nullptr) {
			UpdateListBoxCircles();
			EnableActions(size != 0);
		}
	}

	private: void UpdateListBoxCircles() {
		ListBoxCircles->Items->Clear();
		for (int i = 0; i < size; i++)
		{
			String^ item = L"" + (i + 1) + ")  " + "X = " + arrayCircles[i].X + ";  "
				+ "Y = " + arrayCircles[i].Y + ";  " + "Радиус = " + arrayCircles[i].Radius + ";  "
				+ "Площадь = " + round(getSquare(arrayCircles[i]) * 100) / 100 + ";  "
				+ "Длина = " + round(getLength(arrayCircles[i]) * 100) / 100;
			ListBoxCircles->Items->Add(item);
		}
	}

	private: void EnableActions(bool state) {
		SearchMeanS->Enabled = state;
		MoveCircles->Enabled = state;
		DeleteCircles->Enabled = state;
	}

	private: System::Void ListBoxCircles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int index = ListBoxCircles->SelectedIndex;
		SetInput(index);
	}

	private: void SetInput(int index)
	{
		InputX->Enabled = true;
		InputX->Text = L"" + arrayCircles[index].X;

		InputY->Enabled = true;
		InputY->Text = L"" + arrayCircles[index].Y;

		InputRadius->Enabled = true;
		InputRadius->Text = L"" + arrayCircles[index].Radius;

		SaveCircle->Enabled = false;
	}
	private: System::Void InputX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SaveCircle->Enabled = true;
	}
	private: System::Void InputY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SaveCircle->Enabled = true;
	}
	private: System::Void InputRadius_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SaveCircle->Enabled = true;
	}
	private: System::Void SaveCircle_Click(System::Object^ sender, System::EventArgs^ e) {
		int x, y, radius;
		int index = ListBoxCircles->SelectedIndex;
		if (!int::TryParse(InputX->Text, x)) {
			SaveCircle->Enabled = false;
			MessageBox::Show("Координата X должна быть целым числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			SetInput(index);
		}
		else if (!int::TryParse(InputY->Text, y)) {
			SaveCircle->Enabled = false;
			MessageBox::Show("Координата Y должна быть целым числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			SetInput(index);
		}
		else if (!int::TryParse(InputRadius->Text, radius)) {
			SaveCircle->Enabled = false;
			MessageBox::Show("Радиус должен быть целым числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			SetInput(index);
		}
		else if (radius < 0)
		{
			SaveCircle->Enabled = false;
			MessageBox::Show("Радиус должен быть больше 0!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			SetInput(index);
		}
		else {
			setCircle(arrayCircles[index], x, y, radius);
			String^ item = L"" + (index + 1) + ")  " + "X = " + x + ";  "
				+ "Y = " + y + ";  " + "Радиус = " + radius + ";  "
				+ "Площадь = " + round(getSquare(arrayCircles[index]) * 100) / 100 + ";  "
				+ "Длина = " + round(getLength(arrayCircles[index]) * 100) / 100;
			this->ListBoxCircles->Items[index] = item;
		}
	}
	private: void DisableInputActions()
	{
		InputS1->Enabled = false;
		InputS1->Clear();
		InputS2->Enabled = false;
		InputS2->Clear();
		InputLength->Enabled = false;
		InputLength->Clear();
		DoAction->Enabled = false;
	}
	private: System::Void SearchMeanS_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		DisableInputActions();
		DoAction->Enabled = true;
	}

	private: System::Void MoveCircles_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		DisableInputActions();
		InputS2->Enabled = true;
	}
	private: System::Void DeleteCircles_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		DisableInputActions();
		InputLength->Enabled = true;
	}
	private: System::Void InputS2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		DoAction->Enabled = true;
	}
	private: System::Void InputLength_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		DoAction->Enabled = true;
	}
	private: System::Void DoAction_Click(System::Object^ sender, System::EventArgs^ e) {
		float square, length;
		if (SearchMeanS->Checked) {
			InputS1->Enabled = true;
			InputS1->Text = L"" + getMeanSquare();
		}
		else if (MoveCircles->Checked) {
			if (float::TryParse(InputS2->Text, square)) {
				if (square > 0) {
					moveCirclesToEnd(square);
					UpdateListBoxCircles();
				}
				else {
					MessageBox::Show("Площадь окружности должна быть больше 0!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					InputS2->Clear();
					DoAction->Enabled = false;
				}
			}
			else {
				MessageBox::Show("Площадь окружности - целое неотрицательное число!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				InputS2->Clear();
				DoAction->Enabled = false;
			}
		}
		else if (DeleteCircles->Checked) {
			if (float::TryParse(InputLength->Text, length)) {
				if (length > 0) {
					deleteCircles(length);
					UpdateListBoxCircles();
				}
				else {
					MessageBox::Show("Длина окружности должна быть больше 0!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					InputLength->Clear();
					DoAction->Enabled = false;
				}
			}
			else {
				MessageBox::Show("Длина окружности - целое неотрицательное число!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				InputLength->Clear();
				DoAction->Enabled = false;
			}
		}
	}
	private: System::Void LoadArrayFromFile_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadArrayForm^ loadArrayForm = gcnew LoadArrayForm();
		loadArrayForm->ShowDialog();
		if (arrayCircles != nullptr) {
			UpdateListBoxCircles();
			EnableActions(size != 0);
		}
	}
private: System::Void SaveArrayToFile_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveArrayForm^ saveArrayForm = gcnew SaveArrayForm();
	saveArrayForm->ShowDialog();
}
};
}
