#pragma once
#include "ArrayIndecators.h"

namespace lab11 {

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
			ColorDialog^ colorDialog = gcnew ColorDialog();
			//MessageBox::Show("Лабораторная работа №11, вариант 5\nМалышев Максим, 2 курс, гр.ПМИ - 1", "Инфо", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: System::Windows::Forms::TabPage^ tabPage1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::ListBox^ listBoxResult;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::ColorDialog^ colorDialog;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::ComboBox^ comboBoxIndicator2;

	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ buttonResult;
	private: System::Windows::Forms::ComboBox^ comboBoxIndicator1;

	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::TabPage^ tabEdit;
	private: System::Windows::Forms::TabPage^ tabInbut;

	private: System::Windows::Forms::GroupBox^ groupBoxManual;
	private: System::Windows::Forms::Button^ buttonFillArrayManual;
	private: System::Windows::Forms::TextBox^ textBoxSize1;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridView^ dataGridViewInput;

	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ListBox^ listBoxIndicators;
	private: System::Windows::Forms::GroupBox^ groupBoxGraphics;



	private: System::Windows::Forms::Button^ ClearGraphics;





	private: System::Windows::Forms::Button^ ShowIndicator;

	private: System::Windows::Forms::TextBox^ EditTemp;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ EditMaxTemp;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ EditMinTemp;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::TextBox^ EditY;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ EditX;

	private: System::Windows::Forms::Label^ label17;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ EditLabel;

	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::NumericUpDown^ EditScale;

	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::ComboBox^ EditType;
	private: System::Windows::Forms::Button^ CancelEdits;


	private: System::Windows::Forms::Button^ SaveEdits;

	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::Button^ buttonResizeArray;

	private: System::Windows::Forms::TextBox^ textBoxSize3;

	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::GroupBox^ groupBoxIncremental;
	private: System::Windows::Forms::Button^ buttonFillArrayInc;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxTempStep;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBoxTemp;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxMaxTempStep;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxMaxTemp;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxMinTempStep;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxMinTemp;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxSize2;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::TextBox^ textBoxXStep;

	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::TextBox^ textBoxX;

	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBoxScaleStep;

	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::TextBox^ textBoxScale;

	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TextBox^ textBoxYStep;

	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::TextBox^ textBoxY;

	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMinInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMaxInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inputSignalInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unitInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Scale;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Button^ changeColor;


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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxResult = (gcnew System::Windows::Forms::ListBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->comboBoxIndicator2 = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->buttonResult = (gcnew System::Windows::Forms::Button());
			this->comboBoxIndicator1 = (gcnew System::Windows::Forms::ComboBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->tabEdit = (gcnew System::Windows::Forms::TabPage());
			this->CancelEdits = (gcnew System::Windows::Forms::Button());
			this->SaveEdits = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->ClearGraphics = (gcnew System::Windows::Forms::Button());
			this->ShowIndicator = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->EditType = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->changeColor = (gcnew System::Windows::Forms::Button());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->EditScale = (gcnew System::Windows::Forms::NumericUpDown());
			this->EditLabel = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->EditY = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->EditX = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->EditTemp = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->EditMaxTemp = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->EditMinTemp = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxIndicators = (gcnew System::Windows::Forms::ListBox());
			this->groupBoxGraphics = (gcnew System::Windows::Forms::GroupBox());
			this->tabInbut = (gcnew System::Windows::Forms::TabPage());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonResizeArray = (gcnew System::Windows::Forms::Button());
			this->textBoxSize3 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBoxIncremental = (gcnew System::Windows::Forms::GroupBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBoxYStep = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBoxXStep = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBoxScaleStep = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBoxScale = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->buttonFillArrayInc = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxTempStep = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBoxTemp = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxTempStep = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxTemp = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxMinTempStep = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxMinTemp = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxSize2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxManual = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFillArrayManual = (gcnew System::Windows::Forms::Button());
			this->textBoxSize1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewInput = (gcnew System::Windows::Forms::DataGridView());
			this->tempMinInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tempMaxInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inputSignalInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unitInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Scale = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabEdit->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EditScale))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabInbut->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBoxIncremental->SuspendLayout();
			this->groupBoxManual->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInput))->BeginInit();
			this->tabControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(824, 742);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Сравнение";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->listBoxResult);
			this->groupBox4->Location = System::Drawing::Point(403, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(418, 730);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Результат";
			// 
			// listBoxResult
			// 
			this->listBoxResult->FormattingEnabled = true;
			this->listBoxResult->Location = System::Drawing::Point(6, 19);
			this->listBoxResult->Name = L"listBoxResult";
			this->listBoxResult->Size = System::Drawing::Size(409, 706);
			this->listBoxResult->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->buttonClear);
			this->groupBox5->Controls->Add(this->comboBoxIndicator2);
			this->groupBox5->Controls->Add(this->label19);
			this->groupBox5->Controls->Add(this->buttonResult);
			this->groupBox5->Controls->Add(this->comboBoxIndicator1);
			this->groupBox5->Controls->Add(this->label23);
			this->groupBox5->Location = System::Drawing::Point(7, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(396, 730);
			this->groupBox5->TabIndex = 2;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Выбор операции";
			// 
			// buttonClear
			// 
			this->buttonClear->Enabled = false;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->Location = System::Drawing::Point(9, 236);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(253, 41);
			this->buttonClear->TabIndex = 15;
			this->buttonClear->Text = L"Очистить список";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// comboBoxIndicator2
			// 
			this->comboBoxIndicator2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxIndicator2->FormattingEnabled = true;
			this->comboBoxIndicator2->Location = System::Drawing::Point(6, 120);
			this->comboBoxIndicator2->Name = L"comboBoxIndicator2";
			this->comboBoxIndicator2->Size = System::Drawing::Size(372, 21);
			this->comboBoxIndicator2->TabIndex = 12;
			this->comboBoxIndicator2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxIndicator2_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(6, 95);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(81, 15);
			this->label19->TabIndex = 11;
			this->label19->Text = L"Индикатор 2";
			// 
			// buttonResult
			// 
			this->buttonResult->Enabled = false;
			this->buttonResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonResult->Location = System::Drawing::Point(9, 180);
			this->buttonResult->Name = L"buttonResult";
			this->buttonResult->Size = System::Drawing::Size(253, 41);
			this->buttonResult->TabIndex = 10;
			this->buttonResult->Text = L"Сравнить";
			this->buttonResult->UseVisualStyleBackColor = true;
			this->buttonResult->Click += gcnew System::EventHandler(this, &MainForm::buttonResult_Click);
			// 
			// comboBoxIndicator1
			// 
			this->comboBoxIndicator1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxIndicator1->FormattingEnabled = true;
			this->comboBoxIndicator1->Location = System::Drawing::Point(6, 55);
			this->comboBoxIndicator1->Name = L"comboBoxIndicator1";
			this->comboBoxIndicator1->Size = System::Drawing::Size(372, 21);
			this->comboBoxIndicator1->TabIndex = 2;
			this->comboBoxIndicator1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxIndicator1_SelectedIndexChanged);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(6, 31);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(81, 15);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Индикатор 1";
			// 
			// tabEdit
			// 
			this->tabEdit->Controls->Add(this->CancelEdits);
			this->tabEdit->Controls->Add(this->SaveEdits);
			this->tabEdit->Controls->Add(this->groupBox8);
			this->tabEdit->Controls->Add(this->groupBox7);
			this->tabEdit->Controls->Add(this->groupBox6);
			this->tabEdit->Controls->Add(this->groupBox3);
			this->tabEdit->Controls->Add(this->groupBox1);
			this->tabEdit->Controls->Add(this->groupBoxGraphics);
			this->tabEdit->Location = System::Drawing::Point(4, 22);
			this->tabEdit->Name = L"tabEdit";
			this->tabEdit->Padding = System::Windows::Forms::Padding(3);
			this->tabEdit->Size = System::Drawing::Size(824, 742);
			this->tabEdit->TabIndex = 1;
			this->tabEdit->Text = L"Редактирование/Отображение";
			this->tabEdit->UseVisualStyleBackColor = true;
			// 
			// CancelEdits
			// 
			this->CancelEdits->Enabled = false;
			this->CancelEdits->Location = System::Drawing::Point(424, 687);
			this->CancelEdits->Name = L"CancelEdits";
			this->CancelEdits->Size = System::Drawing::Size(163, 38);
			this->CancelEdits->TabIndex = 15;
			this->CancelEdits->Text = L"Отмена";
			this->CancelEdits->UseVisualStyleBackColor = true;
			this->CancelEdits->Click += gcnew System::EventHandler(this, &MainForm::CancelEdits_Click);
			// 
			// SaveEdits
			// 
			this->SaveEdits->Enabled = false;
			this->SaveEdits->Location = System::Drawing::Point(424, 642);
			this->SaveEdits->Name = L"SaveEdits";
			this->SaveEdits->Size = System::Drawing::Size(163, 38);
			this->SaveEdits->TabIndex = 13;
			this->SaveEdits->Text = L"Сохранить";
			this->SaveEdits->UseVisualStyleBackColor = true;
			this->SaveEdits->Click += gcnew System::EventHandler(this, &MainForm::SaveEdits_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->ClearGraphics);
			this->groupBox8->Controls->Add(this->ShowIndicator);
			this->groupBox8->Location = System::Drawing::Point(611, 548);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(208, 188);
			this->groupBox8->TabIndex = 14;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Отображение";
			// 
			// ClearGraphics
			// 
			this->ClearGraphics->Enabled = false;
			this->ClearGraphics->Location = System::Drawing::Point(23, 110);
			this->ClearGraphics->Name = L"ClearGraphics";
			this->ClearGraphics->Size = System::Drawing::Size(163, 59);
			this->ClearGraphics->TabIndex = 12;
			this->ClearGraphics->Text = L"Очистить";
			this->ClearGraphics->UseVisualStyleBackColor = true;
			this->ClearGraphics->Click += gcnew System::EventHandler(this, &MainForm::ClearGraphics_Click);
			// 
			// ShowIndicator
			// 
			this->ShowIndicator->Enabled = false;
			this->ShowIndicator->Location = System::Drawing::Point(23, 41);
			this->ShowIndicator->Name = L"ShowIndicator";
			this->ShowIndicator->Size = System::Drawing::Size(163, 59);
			this->ShowIndicator->TabIndex = 11;
			this->ShowIndicator->Text = L"Отобразить\r\n выбранный индикатор";
			this->ShowIndicator->UseVisualStyleBackColor = true;
			this->ShowIndicator->Click += gcnew System::EventHandler(this, &MainForm::ShowIndicator_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->EditType);
			this->groupBox7->Location = System::Drawing::Point(405, 548);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(199, 83);
			this->groupBox7->TabIndex = 12;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Тип индикатора";
			// 
			// EditType
			// 
			this->EditType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EditType->FormattingEnabled = true;
			this->EditType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Круглый индикатор", L"Термометр", L"Текстовый индикатор" });
			this->EditType->Location = System::Drawing::Point(17, 35);
			this->EditType->Name = L"EditType";
			this->EditType->Size = System::Drawing::Size(165, 21);
			this->EditType->TabIndex = 13;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->changeColor);
			this->groupBox6->Controls->Add(this->label32);
			this->groupBox6->Controls->Add(this->EditScale);
			this->groupBox6->Controls->Add(this->EditLabel);
			this->groupBox6->Controls->Add(this->label21);
			this->groupBox6->Controls->Add(this->label20);
			this->groupBox6->Controls->Add(this->EditY);
			this->groupBox6->Controls->Add(this->label16);
			this->groupBox6->Controls->Add(this->EditX);
			this->groupBox6->Controls->Add(this->label17);
			this->groupBox6->Controls->Add(this->label18);
			this->groupBox6->Location = System::Drawing::Point(149, 548);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(248, 188);
			this->groupBox6->TabIndex = 11;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Параметры отображения";
			// 
			// changeColor
			// 
			this->changeColor->Enabled = false;
			this->changeColor->Location = System::Drawing::Point(161, 37);
			this->changeColor->Name = L"changeColor";
			this->changeColor->Size = System::Drawing::Size(67, 27);
			this->changeColor->TabIndex = 16;
			this->changeColor->Text = L"Выбрать";
			this->changeColor->UseVisualStyleBackColor = true;
			this->changeColor->Click += gcnew System::EventHandler(this, &MainForm::changeColor_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label32->Location = System::Drawing::Point(122, 42);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 15);
			this->label32->TabIndex = 15;
			this->label32->Text = L"Цвет";
			// 
			// EditScale
			// 
			this->EditScale->Location = System::Drawing::Point(65, 41);
			this->EditScale->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->EditScale->Name = L"EditScale";
			this->EditScale->Size = System::Drawing::Size(48, 20);
			this->EditScale->TabIndex = 14;
			this->EditScale->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			// 
			// EditLabel
			// 
			this->EditLabel->Location = System::Drawing::Point(101, 151);
			this->EditLabel->Name = L"EditLabel";
			this->EditLabel->Size = System::Drawing::Size(118, 20);
			this->EditLabel->TabIndex = 13;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(11, 151);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(84, 15);
			this->label21->TabIndex = 12;
			this->label21->Text = L"Обозначение";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(8, 78);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(206, 15);
			this->label20->TabIndex = 11;
			this->label20->Text = L"Коордианты левого верхнего угла";
			// 
			// EditY
			// 
			this->EditY->Location = System::Drawing::Point(145, 106);
			this->EditY->Name = L"EditY";
			this->EditY->Size = System::Drawing::Size(74, 20);
			this->EditY->TabIndex = 10;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(122, 106);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(17, 15);
			this->label16->TabIndex = 9;
			this->label16->Text = L"Y:";
			// 
			// EditX
			// 
			this->EditX->Location = System::Drawing::Point(31, 105);
			this->EditX->Name = L"EditX";
			this->EditX->Size = System::Drawing::Size(74, 20);
			this->EditX->TabIndex = 8;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(8, 106);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(18, 15);
			this->label17->TabIndex = 7;
			this->label17->Text = L"X:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(8, 42);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(51, 15);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Размер";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->EditTemp);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->EditMaxTemp);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->EditMinTemp);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Location = System::Drawing::Point(9, 548);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(134, 188);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Температура";
			// 
			// EditTemp
			// 
			this->EditTemp->Location = System::Drawing::Point(9, 152);
			this->EditTemp->Name = L"EditTemp";
			this->EditTemp->Size = System::Drawing::Size(74, 20);
			this->EditTemp->TabIndex = 10;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(6, 132);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(55, 15);
			this->label13->TabIndex = 9;
			this->label13->Text = L"Текущая";
			// 
			// EditMaxTemp
			// 
			this->EditMaxTemp->Location = System::Drawing::Point(9, 99);
			this->EditMaxTemp->Name = L"EditMaxTemp";
			this->EditMaxTemp->Size = System::Drawing::Size(74, 20);
			this->EditMaxTemp->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 15);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Максимальная";
			// 
			// EditMinTemp
			// 
			this->EditMinTemp->Location = System::Drawing::Point(9, 46);
			this->EditMinTemp->Name = L"EditMinTemp";
			this->EditMinTemp->Size = System::Drawing::Size(74, 20);
			this->EditMinTemp->TabIndex = 6;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(6, 26);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(90, 15);
			this->label15->TabIndex = 5;
			this->label15->Text = L"Минимальная";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBoxIndicators);
			this->groupBox1->Location = System::Drawing::Point(3, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(302, 548);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Индикаторы";
			// 
			// listBoxIndicators
			// 
			this->listBoxIndicators->FormattingEnabled = true;
			this->listBoxIndicators->HorizontalScrollbar = true;
			this->listBoxIndicators->Location = System::Drawing::Point(6, 19);
			this->listBoxIndicators->Name = L"listBoxIndicators";
			this->listBoxIndicators->Size = System::Drawing::Size(290, 524);
			this->listBoxIndicators->TabIndex = 0;
			this->listBoxIndicators->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBoxIndicators_SelectedIndexChanged);
			// 
			// groupBoxGraphics
			// 
			this->groupBoxGraphics->Location = System::Drawing::Point(310, 0);
			this->groupBoxGraphics->Name = L"groupBoxGraphics";
			this->groupBoxGraphics->Size = System::Drawing::Size(523, 548);
			this->groupBoxGraphics->TabIndex = 2;
			this->groupBoxGraphics->TabStop = false;
			this->groupBoxGraphics->Text = L"Отображение индикатора";
			// 
			// tabInbut
			// 
			this->tabInbut->Controls->Add(this->groupBox9);
			this->tabInbut->Controls->Add(this->groupBoxIncremental);
			this->tabInbut->Controls->Add(this->groupBoxManual);
			this->tabInbut->Location = System::Drawing::Point(4, 22);
			this->tabInbut->Name = L"tabInbut";
			this->tabInbut->Padding = System::Windows::Forms::Padding(3);
			this->tabInbut->Size = System::Drawing::Size(824, 742);
			this->tabInbut->TabIndex = 0;
			this->tabInbut->Text = L"Ввод данных";
			this->tabInbut->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->buttonResizeArray);
			this->groupBox9->Controls->Add(this->textBoxSize3);
			this->groupBox9->Controls->Add(this->label22);
			this->groupBox9->Location = System::Drawing::Point(10, 597);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(478, 139);
			this->groupBox9->TabIndex = 2;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Изменить размерность";
			// 
			// buttonResizeArray
			// 
			this->buttonResizeArray->Enabled = false;
			this->buttonResizeArray->Location = System::Drawing::Point(8, 71);
			this->buttonResizeArray->Name = L"buttonResizeArray";
			this->buttonResizeArray->Size = System::Drawing::Size(331, 44);
			this->buttonResizeArray->TabIndex = 20;
			this->buttonResizeArray->Text = L"Применить";
			this->buttonResizeArray->UseVisualStyleBackColor = true;
			this->buttonResizeArray->Click += gcnew System::EventHandler(this, &MainForm::buttonResizeArray_Click);
			// 
			// textBoxSize3
			// 
			this->textBoxSize3->Location = System::Drawing::Point(232, 38);
			this->textBoxSize3->Name = L"textBoxSize3";
			this->textBoxSize3->Size = System::Drawing::Size(107, 20);
			this->textBoxSize3->TabIndex = 3;
			this->textBoxSize3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxSize3_TextChanged);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(9, 38);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(179, 15);
			this->label22->TabIndex = 2;
			this->label22->Text = L"Новая размерность массива:";
			// 
			// groupBoxIncremental
			// 
			this->groupBoxIncremental->Controls->Add(this->label29);
			this->groupBoxIncremental->Controls->Add(this->textBoxYStep);
			this->groupBoxIncremental->Controls->Add(this->label30);
			this->groupBoxIncremental->Controls->Add(this->textBoxY);
			this->groupBoxIncremental->Controls->Add(this->label31);
			this->groupBoxIncremental->Controls->Add(this->label26);
			this->groupBoxIncremental->Controls->Add(this->textBoxXStep);
			this->groupBoxIncremental->Controls->Add(this->label27);
			this->groupBoxIncremental->Controls->Add(this->textBoxX);
			this->groupBoxIncremental->Controls->Add(this->label28);
			this->groupBoxIncremental->Controls->Add(this->label14);
			this->groupBoxIncremental->Controls->Add(this->textBoxScaleStep);
			this->groupBoxIncremental->Controls->Add(this->label24);
			this->groupBoxIncremental->Controls->Add(this->textBoxScale);
			this->groupBoxIncremental->Controls->Add(this->label25);
			this->groupBoxIncremental->Controls->Add(this->buttonFillArrayInc);
			this->groupBoxIncremental->Controls->Add(this->label9);
			this->groupBoxIncremental->Controls->Add(this->textBoxTempStep);
			this->groupBoxIncremental->Controls->Add(this->label10);
			this->groupBoxIncremental->Controls->Add(this->textBoxTemp);
			this->groupBoxIncremental->Controls->Add(this->label11);
			this->groupBoxIncremental->Controls->Add(this->label6);
			this->groupBoxIncremental->Controls->Add(this->textBoxMaxTempStep);
			this->groupBoxIncremental->Controls->Add(this->label7);
			this->groupBoxIncremental->Controls->Add(this->textBoxMaxTemp);
			this->groupBoxIncremental->Controls->Add(this->label8);
			this->groupBoxIncremental->Controls->Add(this->label5);
			this->groupBoxIncremental->Controls->Add(this->textBoxMinTempStep);
			this->groupBoxIncremental->Controls->Add(this->label4);
			this->groupBoxIncremental->Controls->Add(this->textBoxMinTemp);
			this->groupBoxIncremental->Controls->Add(this->label3);
			this->groupBoxIncremental->Controls->Add(this->textBoxSize2);
			this->groupBoxIncremental->Controls->Add(this->label2);
			this->groupBoxIncremental->Location = System::Drawing::Point(494, 6);
			this->groupBoxIncremental->Name = L"groupBoxIncremental";
			this->groupBoxIncremental->Size = System::Drawing::Size(324, 730);
			this->groupBoxIncremental->TabIndex = 1;
			this->groupBoxIncremental->TabStop = false;
			this->groupBoxIncremental->Text = L"По порядку с шагом";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(24, 543);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(88, 15);
			this->label29->TabIndex = 34;
			this->label29->Text = L"Координата Y";
			// 
			// textBoxYStep
			// 
			this->textBoxYStep->Location = System::Drawing::Point(172, 587);
			this->textBoxYStep->Name = L"textBoxYStep";
			this->textBoxYStep->Size = System::Drawing::Size(114, 20);
			this->textBoxYStep->TabIndex = 33;
			this->textBoxYStep->Text = L"0";
			this->textBoxYStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxYStep_TextChanged);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(170, 567);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(30, 13);
			this->label30->TabIndex = 32;
			this->label30->Text = L"Шаг:";
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(26, 587);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->Size = System::Drawing::Size(114, 20);
			this->textBoxY->TabIndex = 31;
			this->textBoxY->Text = L"0";
			this->textBoxY->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxY_TextChanged);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(24, 567);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(115, 13);
			this->label31->TabIndex = 30;
			this->label31->Text = L"Начальное значение:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(23, 450);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(89, 15);
			this->label26->TabIndex = 29;
			this->label26->Text = L"Координата X";
			// 
			// textBoxXStep
			// 
			this->textBoxXStep->Location = System::Drawing::Point(171, 494);
			this->textBoxXStep->Name = L"textBoxXStep";
			this->textBoxXStep->Size = System::Drawing::Size(114, 20);
			this->textBoxXStep->TabIndex = 28;
			this->textBoxXStep->Text = L"15";
			this->textBoxXStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxXStep_TextChanged);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(169, 474);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(30, 13);
			this->label27->TabIndex = 27;
			this->label27->Text = L"Шаг:";
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(25, 494);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(114, 20);
			this->textBoxX->TabIndex = 26;
			this->textBoxX->Text = L"0";
			this->textBoxX->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxX_TextChanged);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(23, 474);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(115, 13);
			this->label28->TabIndex = 25;
			this->label28->Text = L"Начальное значение:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(24, 355);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(61, 15);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Масштаб";
			// 
			// textBoxScaleStep
			// 
			this->textBoxScaleStep->Location = System::Drawing::Point(172, 399);
			this->textBoxScaleStep->Name = L"textBoxScaleStep";
			this->textBoxScaleStep->Size = System::Drawing::Size(114, 20);
			this->textBoxScaleStep->TabIndex = 23;
			this->textBoxScaleStep->Text = L"2";
			this->textBoxScaleStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxScaleStep_TextChanged);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(170, 379);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(30, 13);
			this->label24->TabIndex = 22;
			this->label24->Text = L"Шаг:";
			// 
			// textBoxScale
			// 
			this->textBoxScale->Location = System::Drawing::Point(26, 399);
			this->textBoxScale->Name = L"textBoxScale";
			this->textBoxScale->Size = System::Drawing::Size(114, 20);
			this->textBoxScale->TabIndex = 21;
			this->textBoxScale->Text = L"1";
			this->textBoxScale->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxScale_TextChanged);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(24, 379);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(115, 13);
			this->label25->TabIndex = 20;
			this->label25->Text = L"Начальное значение:";
			// 
			// buttonFillArrayInc
			// 
			this->buttonFillArrayInc->Location = System::Drawing::Point(27, 643);
			this->buttonFillArrayInc->Name = L"buttonFillArrayInc";
			this->buttonFillArrayInc->Size = System::Drawing::Size(261, 42);
			this->buttonFillArrayInc->TabIndex = 19;
			this->buttonFillArrayInc->Text = L"Заполнить массив";
			this->buttonFillArrayInc->UseVisualStyleBackColor = true;
			this->buttonFillArrayInc->Click += gcnew System::EventHandler(this, &MainForm::buttonFillArrayInc_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(24, 261);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 15);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Текуща температура";
			// 
			// textBoxTempStep
			// 
			this->textBoxTempStep->Location = System::Drawing::Point(172, 305);
			this->textBoxTempStep->Name = L"textBoxTempStep";
			this->textBoxTempStep->Size = System::Drawing::Size(114, 20);
			this->textBoxTempStep->TabIndex = 15;
			this->textBoxTempStep->Text = L"3";
			this->textBoxTempStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxTempStep_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(170, 285);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Шаг:";
			// 
			// textBoxTemp
			// 
			this->textBoxTemp->Location = System::Drawing::Point(26, 305);
			this->textBoxTemp->Name = L"textBoxTemp";
			this->textBoxTemp->Size = System::Drawing::Size(114, 20);
			this->textBoxTemp->TabIndex = 13;
			this->textBoxTemp->Text = L"-5";
			this->textBoxTemp->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxTemp_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 285);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(115, 13);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Начальное значение:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(24, 174);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(175, 15);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Максимальная температура";
			// 
			// textBoxMaxTempStep
			// 
			this->textBoxMaxTempStep->Location = System::Drawing::Point(172, 218);
			this->textBoxMaxTempStep->Name = L"textBoxMaxTempStep";
			this->textBoxMaxTempStep->Size = System::Drawing::Size(114, 20);
			this->textBoxMaxTempStep->TabIndex = 10;
			this->textBoxMaxTempStep->Text = L"2";
			this->textBoxMaxTempStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMaxTempStep_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(170, 198);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Шаг:";
			// 
			// textBoxMaxTemp
			// 
			this->textBoxMaxTemp->Location = System::Drawing::Point(26, 218);
			this->textBoxMaxTemp->Name = L"textBoxMaxTemp";
			this->textBoxMaxTemp->Size = System::Drawing::Size(114, 20);
			this->textBoxMaxTemp->TabIndex = 8;
			this->textBoxMaxTemp->Text = L"0";
			this->textBoxMaxTemp->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMaxTemp_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 198);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(115, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Начальное значение:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(24, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(170, 15);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Минимальная температура";
			// 
			// textBoxMinTempStep
			// 
			this->textBoxMinTempStep->Location = System::Drawing::Point(172, 132);
			this->textBoxMinTempStep->Name = L"textBoxMinTempStep";
			this->textBoxMinTempStep->Size = System::Drawing::Size(114, 20);
			this->textBoxMinTempStep->TabIndex = 5;
			this->textBoxMinTempStep->Text = L"2";
			this->textBoxMinTempStep->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMinTempStep_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(170, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Шаг:";
			// 
			// textBoxMinTemp
			// 
			this->textBoxMinTemp->Location = System::Drawing::Point(26, 132);
			this->textBoxMinTemp->Name = L"textBoxMinTemp";
			this->textBoxMinTemp->Size = System::Drawing::Size(114, 20);
			this->textBoxMinTemp->TabIndex = 3;
			this->textBoxMinTemp->Text = L"-10";
			this->textBoxMinTemp->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMinTemp_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Начальное значение:";
			// 
			// textBoxSize2
			// 
			this->textBoxSize2->Location = System::Drawing::Point(25, 53);
			this->textBoxSize2->Name = L"textBoxSize2";
			this->textBoxSize2->Size = System::Drawing::Size(114, 20);
			this->textBoxSize2->TabIndex = 1;
			this->textBoxSize2->Text = L"10";
			this->textBoxSize2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxSize2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(23, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(140, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Размерность массива:";
			// 
			// groupBoxManual
			// 
			this->groupBoxManual->Controls->Add(this->buttonFillArrayManual);
			this->groupBoxManual->Controls->Add(this->textBoxSize1);
			this->groupBoxManual->Controls->Add(this->label12);
			this->groupBoxManual->Controls->Add(this->dataGridViewInput);
			this->groupBoxManual->Location = System::Drawing::Point(10, 6);
			this->groupBoxManual->Name = L"groupBoxManual";
			this->groupBoxManual->Size = System::Drawing::Size(478, 585);
			this->groupBoxManual->TabIndex = 0;
			this->groupBoxManual->TabStop = false;
			this->groupBoxManual->Text = L"Вручную";
			// 
			// buttonFillArrayManual
			// 
			this->buttonFillArrayManual->Enabled = false;
			this->buttonFillArrayManual->Location = System::Drawing::Point(8, 516);
			this->buttonFillArrayManual->Name = L"buttonFillArrayManual";
			this->buttonFillArrayManual->Size = System::Drawing::Size(262, 42);
			this->buttonFillArrayManual->TabIndex = 20;
			this->buttonFillArrayManual->Text = L"Заполнить массив";
			this->buttonFillArrayManual->UseVisualStyleBackColor = true;
			this->buttonFillArrayManual->Click += gcnew System::EventHandler(this, &MainForm::buttonFillArrayManual_Click);
			// 
			// textBoxSize1
			// 
			this->textBoxSize1->Location = System::Drawing::Point(18, 53);
			this->textBoxSize1->Name = L"textBoxSize1";
			this->textBoxSize1->Size = System::Drawing::Size(114, 20);
			this->textBoxSize1->TabIndex = 3;
			this->textBoxSize1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textBoxSize1_KeyDown);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(16, 33);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(140, 15);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Размерность массива:";
			// 
			// dataGridViewInput
			// 
			this->dataGridViewInput->AllowUserToAddRows = false;
			this->dataGridViewInput->AllowUserToDeleteRows = false;
			this->dataGridViewInput->AllowUserToResizeColumns = false;
			this->dataGridViewInput->AllowUserToResizeRows = false;
			this->dataGridViewInput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewInput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->tempMinInput,
					this->tempMaxInput, this->inputSignalInput, this->unitInput, this->Scale, this->X, this->Y
			});
			this->dataGridViewInput->Location = System::Drawing::Point(8, 87);
			this->dataGridViewInput->Name = L"dataGridViewInput";
			this->dataGridViewInput->RowHeadersVisible = false;
			this->dataGridViewInput->Size = System::Drawing::Size(464, 415);
			this->dataGridViewInput->TabIndex = 1;
			// 
			// tempMinInput
			// 
			this->tempMinInput->HeaderText = L"Минимальная температура";
			this->tempMinInput->MaxInputLength = 8;
			this->tempMinInput->Name = L"tempMinInput";
			this->tempMinInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tempMinInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tempMinInput->Width = 80;
			// 
			// tempMaxInput
			// 
			this->tempMaxInput->HeaderText = L"Максимальная температура";
			this->tempMaxInput->MaxInputLength = 8;
			this->tempMaxInput->Name = L"tempMaxInput";
			this->tempMaxInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tempMaxInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tempMaxInput->Width = 80;
			// 
			// inputSignalInput
			// 
			this->inputSignalInput->HeaderText = L"Текущая температура";
			this->inputSignalInput->MaxInputLength = 8;
			this->inputSignalInput->Name = L"inputSignalInput";
			this->inputSignalInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->inputSignalInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->inputSignalInput->Width = 80;
			// 
			// unitInput
			// 
			this->unitInput->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->unitInput->HeaderText = L"Тип Датчика";
			this->unitInput->Name = L"unitInput";
			this->unitInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->unitInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->unitInput->Width = 80;
			// 
			// Scale
			// 
			this->Scale->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Scale->HeaderText = L"Масштаб";
			this->Scale->Name = L"Scale";
			this->Scale->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Scale->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Scale->Width = 60;
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->Name = L"X";
			this->X->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->X->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->X->Width = 40;
			// 
			// Y
			// 
			this->Y->HeaderText = L"Y";
			this->Y->Name = L"Y";
			this->Y->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Y->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Y->Width = 40;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabInbut);
			this->tabControl->Controls->Add(this->tabEdit);
			this->tabControl->Controls->Add(this->tabPage1);
			this->tabControl->ImeMode = System::Windows::Forms::ImeMode::On;
			this->tabControl->Location = System::Drawing::Point(-1, -1);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(832, 768);
			this->tabControl->TabIndex = 1;
			this->tabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::tabControl_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(835, 766);
			this->Controls->Add(this->tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Индикаторы температуры";
			this->tabPage1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabEdit->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EditScale))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tabInbut->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBoxIncremental->ResumeLayout(false);
			this->groupBoxIncremental->PerformLayout();
			this->groupBoxManual->ResumeLayout(false);
			this->groupBoxManual->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInput))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonFillArrayInc_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			uint size = uint::Parse(textBoxSize2->Text);
			float minTemp = float::Parse(textBoxMinTemp->Text);
			float minTempD = float::Parse(textBoxMinTempStep->Text);
			float maxTemp = float::Parse(textBoxMaxTemp->Text);
			float maxTempD = float::Parse(textBoxMaxTempStep->Text);
			float temp = float::Parse(textBoxTemp->Text);
			float tempD = float::Parse(textBoxTempStep->Text);
			uint scale = uint::Parse(textBoxScale->Text);
			uint scaleD = uint::Parse(textBoxScale->Text);
			float x = float::Parse(textBoxX->Text);
			float xD = float::Parse(textBoxXStep->Text);
			float y = float::Parse(textBoxY->Text);
			float yD = float::Parse(textBoxYStep->Text);

			arrayIndicators.Clear();
			arrayIndicators = ArrayIndicators(size);

			for (size_t i = 0; i < size; i++)
			{
				switch (i % 3)
				{
				case ROUND:
					arrayIndicators[i] = new RoundIndicator(temp + tempD * i,
						minTemp + minTempD * i, maxTemp + maxTempD * i, x + xD * i, y + yD * i,
						scale + scaleD * i, "T" + to_string(i + 1));
					break;
				case THERMOMETER:
					arrayIndicators[i] = new Thermometer(temp + tempD * i,
						minTemp + minTempD * i, maxTemp + maxTempD * i, x + xD * i, y + yD * i,
						scale + scaleD * i, "T" + to_string(i + 1));
					break;
				case TEXT:
					arrayIndicators[i] = new TextIndicator(temp + tempD * i,
						minTemp + minTempD * i, maxTemp + maxTempD * i, x + xD * i, y + yD * i,
						scale + scaleD * i, "T" + to_string(i + 1));
					break;
				}
			}

			fillListBoxIndicators(size);
			tabControl->SelectedIndex = 1;
			MessageBox::Show("Массив заполнен успешно", "Инфо",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (exception e)
		{
			MessageBox::Show(gcnew String(e.what()), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: void fillListBoxIndicators(uint size) {
		listBoxIndicators->Items->Clear();
		for (size_t i = 0; i < size; i++)
		{
			String^ indicator = String::Format("{0}) T={1:0.00}; Мин.Т={2:0.00}; Макс.Т={3:0.00}; Тип: ", i + 1, arrayIndicators[i]->GetTemp(),
				arrayIndicators[i]->GetMinTemp(), arrayIndicators[i]->GetMaxTemp());
			if (arrayIndicators.GetType(i) == ROUND) indicator += "круглый";
			else if (arrayIndicators.GetType(i) == THERMOMETER) indicator += "термометр";
			else indicator += "текстовый";
			listBoxIndicators->Items->Add(indicator);
		}
	}

	private: void SetEnableButtonFillArrayInc() {
		buttonFillArrayInc->Enabled = textBoxSize2->Text != "" && textBoxMinTemp->Text != ""
			&& textBoxMinTempStep->Text != "" && textBoxMaxTemp->Text != "" && textBoxMaxTempStep->Text != ""
			&& textBoxTemp->Text != "" && textBoxTempStep->Text != "" && textBoxScale->Text != ""
			&& textBoxScale->Text != "" && textBoxX->Text != "" && textBoxXStep->Text != "" && textBoxY->Text != ""
			&& textBoxY->Text != "" && textBoxYStep->Text != "";
	}
	private: System::Void textBoxSize2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxMinTemp_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxMinTempStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxMaxTemp_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxMaxTempStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxTemp_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxTempStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxScale_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxScaleStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxXStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void textBoxYStep_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnableButtonFillArrayInc();
	}
	private: System::Void listBoxIndicators_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		fillEdits();
		setCancelEdits();
		setSaveEdits();
		setShowIndicator();
		setChangeColor();
	}
	private: void fillEdits() {

		uint i = listBoxIndicators->SelectedIndex;

		EditMinTemp->Text = String::Format("{0:0.00}", arrayIndicators[i]->GetMinTemp());
		EditMaxTemp->Text = String::Format("{0:0.00}", arrayIndicators[i]->GetMaxTemp());
		EditTemp->Text = String::Format("{0:0.00}", arrayIndicators[i]->GetTemp());

		EditScale->Text = String::Format("{0}", arrayIndicators[i]->GetScale());
		EditX->Text = String::Format("{0:0.00}", arrayIndicators[i]->GetX());
		EditY->Text = String::Format("{0:0.00}", arrayIndicators[i]->GetY());
		EditLabel->Text = marshal_as<System::String^>(arrayIndicators[i]->GetLabel());

		EditType->SelectedIndex = arrayIndicators.GetType(i);
	}
	private: void setCancelEdits() {
		CancelEdits->Enabled = listBoxIndicators->SelectedIndex >= 0;
	}
	private: void setChangeColor() {
		int i = listBoxIndicators->SelectedIndex;
		changeColor->Enabled = arrayIndicators.GetType(i) == THERMOMETER;
	}
	private: void setSaveEdits() {
		SaveEdits->Enabled = listBoxIndicators->SelectedIndex >= 0;
	}
	private: void setShowIndicator() {
		ShowIndicator->Enabled = listBoxIndicators->SelectedIndex >= 0;
	}
	private: System::Void CancelEdits_Click(System::Object^ sender, System::EventArgs^ e) {
		fillEdits();
	}
	private: System::Void SaveEdits_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			uint i = listBoxIndicators->SelectedIndex;

			if (EditType->SelectedIndex == ROUND) arrayIndicators[i] = new RoundIndicator(EditTemp->Text, EditMinTemp->Text,
				EditMaxTemp->Text, EditX->Text, EditY->Text, EditScale->Text, EditLabel->Text);

			else if (EditType->SelectedIndex == THERMOMETER)
			{
				arrayIndicators[i] = new Thermometer(EditTemp->Text, EditMinTemp->Text,
					EditMaxTemp->Text, EditX->Text, EditY->Text, EditScale->Text, EditLabel->Text);
				if (colorDialog->Color != Color::Black) arrayIndicators[i]->SetColor(colorDialog->Color.ToArgb());
			}

			else arrayIndicators[i] = new TextIndicator(EditTemp->Text, EditMinTemp->Text,
				EditMaxTemp->Text, EditX->Text, EditY->Text, EditScale->Text, EditLabel->Text);

			fillListBoxIndicators(arrayIndicators.GetSize());
			listBoxIndicators->SelectedIndex = i;
		}
		catch (exception e)
		{
			MessageBox::Show(gcnew String(e.what()), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			fillEdits();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			fillEdits();
		}
	}
	private: System::Void ShowIndicator_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			arrayIndicators[listBoxIndicators->SelectedIndex]->DrawIndicator(groupBoxGraphics);
			setClearGraphics();
		}
		catch (exception e)
		{
			MessageBox::Show("Невозможно отобрзаить индикатор с такими параметарми", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			groupBoxGraphics->Invalidate();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show("Невозможно отобрзаить индикатор с такими параметарми", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			groupBoxGraphics->Invalidate();
		}
	}

	private: void setClearGraphics() {
		ClearGraphics->Enabled = true;
	}
	private: System::Void ClearGraphics_Click(System::Object^ sender, System::EventArgs^ e) {
		groupBoxGraphics->Invalidate();
	}
	private: System::Void changeColor_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog->ShowDialog();
	}
	private: System::Void tabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (tabControl->SelectedIndex == 2)
		{
			fillComboBox(comboBoxIndicator1);
			fillComboBox(comboBoxIndicator2);
			setButtonResult();
		}
	}
	private: void fillComboBox(ComboBox^ comboBox) {
		comboBox->Items->Clear();
		for (size_t i = 0; i < arrayIndicators.GetSize(); i++)
		{
			String^ indicator = String::Format("{0}) T={1:0.00}; Мин.Т={2:0.00}; Макс.Т={3:0.00}; Тип: ", i + 1, arrayIndicators[i]->GetTemp(),
				arrayIndicators[i]->GetMinTemp(), arrayIndicators[i]->GetMaxTemp());
			if (arrayIndicators.GetType(i) == ROUND) indicator += "круглый";
			else if (arrayIndicators.GetType(i) == THERMOMETER) indicator += "термометр";
			else indicator += "текстовый";
			comboBox->Items->Add(indicator);
		}
	}
	private: System::Void comboBoxIndicator1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		setButtonResult();
	}
	private: System::Void comboBoxIndicator2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		setButtonResult();
	}

	private: void setButtonResult() {
		buttonResult->Enabled = comboBoxIndicator1->SelectedIndex != -1 && comboBoxIndicator2->SelectedIndex != -1;
	}
	private: System::Void buttonResult_Click(System::Object^ sender, System::EventArgs^ e) {
		uint ind1 = comboBoxIndicator1->SelectedIndex;
		uint ind2 = comboBoxIndicator2->SelectedIndex;
		String^ result;
		if (arrayIndicators[ind1] == arrayIndicators[ind2])
			result = "Значения индикаторов " + marshal_as<System::String^>(arrayIndicators[ind1]->GetLabel()) + " и "
			+ marshal_as<System::String^>(arrayIndicators[ind2]->GetLabel()) + " равны";
		else if (arrayIndicators[ind1] > arrayIndicators[ind2])
			result = "Значение индикатора " + marshal_as<System::String^>(arrayIndicators[ind1]->GetLabel()) + " больше, чем индикатора "
			+ marshal_as<System::String^>(arrayIndicators[ind2]->GetLabel());
		else
			result = "Значение индикатора " + marshal_as<System::String^>(arrayIndicators[ind1]->GetLabel()) + " меньше, чем индикатора "
			+ marshal_as<System::String^>(arrayIndicators[ind2]->GetLabel());
		listBoxResult->Items->Add(result);
		setButtonClear();
	}
	private: void setButtonClear() {
		buttonClear->Enabled = listBoxResult->Items->Count != 0;
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		listBoxResult->Items->Clear();
		buttonClear->Enabled = false;
	}
	private: System::Void textBoxSize1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int temp;
		if (e->KeyCode == Keys::Enter) {
			if (!int::TryParse(textBoxSize1->Text, temp)) {
				MessageBox::Show("Размерность массива должна быть целым числом!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				dataGridViewInput->Rows->Clear();
				return;
			}
			else if (temp <= 0) {
				MessageBox::Show("Размерность массива должна быть больше 0!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				dataGridViewInput->Rows->Clear();
				return;
			}
			else {
				arrayIndicators.Clear();
				arrayIndicators = ArrayIndicators(temp);
				enableButtonFillArrayManual();
				SetDataGridViewInput();
			}
		}
	}

	private: void enableButtonFillArrayManual() {
		buttonFillArrayManual->Enabled = true;
	}

	private: void SetDataGridViewInput() {
		dataGridViewInput->Rows->Clear();
		for (uint i = 0; i < arrayIndicators.GetSize(); i++) dataGridViewInput->Rows->Add();
	}

	private: System::Void buttonFillArrayManual_Click(System::Object^ sender, System::EventArgs^ e) {
		uint size = arrayIndicators.GetSize();
		try {

			for (uint i = 0; i < size; i++)
			{
				String^ minTemp = dataGridViewInput->Rows[i]->Cells[0]->Value->ToString();
				String^ maxTemp = dataGridViewInput->Rows[i]->Cells[1]->Value->ToString();
				String^ temp = dataGridViewInput->Rows[i]->Cells[2]->Value->ToString();
				uint type = uint::Parse(dataGridViewInput->Rows[i]->Cells[3]->Value->ToString());
				String^ scale = dataGridViewInput->Rows[i]->Cells[4]->Value->ToString();
				String^ x = dataGridViewInput->Rows[i]->Cells[5]->Value->ToString();
				String^ y = dataGridViewInput->Rows[i]->Cells[6]->Value->ToString();
				String^ label = "T" + (i + 1).ToString();
				switch (type - 1)
				{
				case ROUND:
					arrayIndicators[i] = new RoundIndicator(temp, minTemp, maxTemp, x, y, scale, label);
					break;
				case THERMOMETER:
					arrayIndicators[i] = new Thermometer(temp, minTemp, maxTemp, x, y, scale, label);
					break;
				case TEXT:
					arrayIndicators[i] = new TextIndicator(temp, minTemp, maxTemp, x, y, scale, label);
					break;
				default:
					throw exception("Указан неверный тип датчика (тип датичка - число от 1 до 3)");
					break;
				}
			}
			fillListBoxIndicators(size);
			tabControl->SelectedIndex = 1;
			MessageBox::Show("Массив заполнен успешно", "Инфо",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (exception e)
		{
			arrayIndicators.Clear();
			arrayIndicators.SetSize(size);
			MessageBox::Show(gcnew String(e.what()), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (System::Exception^ ex) {
			arrayIndicators.Clear();
			arrayIndicators.SetSize(size);
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void textBoxSize3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		setButtonResizeArray();
	}
	private: void setButtonResizeArray() {
		buttonResizeArray->Enabled = textBoxSize3->Text != "";
	}
	private: System::Void buttonResizeArray_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (arrayIndicators.GetSize() == 0) throw exception("Массив еще не был создан");
			uint size = uint::Parse(textBoxSize3->Text);
			arrayIndicators.SetSize(size);
			fillListBoxIndicators(size);
			tabControl->SelectedIndex = 1;
			MessageBox::Show("Массив перезаполнен успешно", "Инфо",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (exception e)
		{
			arrayIndicators.Clear();
			MessageBox::Show(gcnew String(e.what()), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (System::Exception^ ex) {
			arrayIndicators.Clear();
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}