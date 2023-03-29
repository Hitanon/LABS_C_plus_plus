#pragma once
#include "CurrentTempSensor.h"
#include <functional>

namespace lab9 {

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
			setComboBoxOp();
			MessageBox::Show("Лабораторная работа №10, вариант 5\nМалышев Максим, 2 курс, гр.ПМИ - 1", "Инфо", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::TabPage^ tabInbut;
	private: System::Windows::Forms::TabPage^ tabEdit;
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::Label^ label1;






	private: System::Windows::Forms::GroupBox^ groupBoxIncremental;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBoxManual;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonFillArrayInc;
	private: System::Windows::Forms::DataGridView^ dataGridViewInput;

















	private: System::Windows::Forms::Button^ buttonFillArrayManual;

	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMinInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMaxInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inputSignalInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unitInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempMax;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inputSignal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tempCurrent;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ unit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ isOutRange;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::PictureBox^ GraphTemp;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::PictureBox^ GraphI;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonShowGraphs;

	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ InputA;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ InputT;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::ComboBox^ SelectSensor;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::NumericUpDown^ numericScale;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ buttonResult;
	private: System::Windows::Forms::TextBox^ InputK;


	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::ComboBox^ comboBoxSensor1;

	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::ListBox^ listBoxResult;

	private: System::Windows::Forms::ComboBox^ comboBoxOp;

	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::ComboBox^ comboBoxSensor2;


	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::NumericUpDown^ numericScaleTemp;
	private: System::Windows::Forms::Label^ label22;

















































	protected:

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
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabInbut = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxIncremental = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFillArrayInc = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxManual = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFillArrayManual = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewInput = (gcnew System::Windows::Forms::DataGridView());
			this->tempMinInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tempMaxInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inputSignalInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unitInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabEdit = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->tempMin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tempMax = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inputSignal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tempCurrent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->isOutRange = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxResult = (gcnew System::Windows::Forms::ListBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->comboBoxOp = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSensor2 = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->buttonResult = (gcnew System::Windows::Forms::Button());
			this->InputK = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSensor1 = (gcnew System::Windows::Forms::ComboBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->GraphTemp = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->GraphI = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericScaleTemp = (gcnew System::Windows::Forms::NumericUpDown());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->numericScale = (gcnew System::Windows::Forms::NumericUpDown());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->buttonShowGraphs = (gcnew System::Windows::Forms::Button());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->InputA = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->InputT = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->SelectSensor = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tabControl->SuspendLayout();
			this->tabInbut->SuspendLayout();
			this->groupBoxIncremental->SuspendLayout();
			this->groupBoxManual->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInput))->BeginInit();
			this->tabEdit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphTemp))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphI))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericScaleTemp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericScale))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabInbut);
			this->tabControl->Controls->Add(this->tabEdit);
			this->tabControl->Controls->Add(this->tabPage1);
			this->tabControl->Controls->Add(this->tabPage2);
			this->tabControl->ImeMode = System::Windows::Forms::ImeMode::On;
			this->tabControl->Location = System::Drawing::Point(3, 12);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(706, 548);
			this->tabControl->TabIndex = 0;
			this->tabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::tabControl_SelectedIndexChanged);
			// 
			// tabInbut
			// 
			this->tabInbut->Controls->Add(this->groupBoxIncremental);
			this->tabInbut->Controls->Add(this->groupBoxManual);
			this->tabInbut->Location = System::Drawing::Point(4, 22);
			this->tabInbut->Name = L"tabInbut";
			this->tabInbut->Padding = System::Windows::Forms::Padding(3);
			this->tabInbut->Size = System::Drawing::Size(698, 522);
			this->tabInbut->TabIndex = 0;
			this->tabInbut->Text = L"Ввод данных";
			this->tabInbut->UseVisualStyleBackColor = true;
			this->tabInbut->Click += gcnew System::EventHandler(this, &MainForm::tabInbut_Click);
			// 
			// groupBoxIncremental
			// 
			this->groupBoxIncremental->Controls->Add(this->buttonFillArrayInc);
			this->groupBoxIncremental->Controls->Add(this->textBox9);
			this->groupBoxIncremental->Controls->Add(this->label14);
			this->groupBoxIncremental->Controls->Add(this->label9);
			this->groupBoxIncremental->Controls->Add(this->textBox6);
			this->groupBoxIncremental->Controls->Add(this->label10);
			this->groupBoxIncremental->Controls->Add(this->textBox7);
			this->groupBoxIncremental->Controls->Add(this->label11);
			this->groupBoxIncremental->Controls->Add(this->label6);
			this->groupBoxIncremental->Controls->Add(this->textBox4);
			this->groupBoxIncremental->Controls->Add(this->label7);
			this->groupBoxIncremental->Controls->Add(this->textBox5);
			this->groupBoxIncremental->Controls->Add(this->label8);
			this->groupBoxIncremental->Controls->Add(this->label5);
			this->groupBoxIncremental->Controls->Add(this->textBox3);
			this->groupBoxIncremental->Controls->Add(this->label4);
			this->groupBoxIncremental->Controls->Add(this->textBox2);
			this->groupBoxIncremental->Controls->Add(this->label3);
			this->groupBoxIncremental->Controls->Add(this->textBox1);
			this->groupBoxIncremental->Controls->Add(this->label2);
			this->groupBoxIncremental->Location = System::Drawing::Point(379, 6);
			this->groupBoxIncremental->Name = L"groupBoxIncremental";
			this->groupBoxIncremental->Size = System::Drawing::Size(310, 508);
			this->groupBoxIncremental->TabIndex = 1;
			this->groupBoxIncremental->TabStop = false;
			this->groupBoxIncremental->Text = L"По порядку с шагом";
			this->groupBoxIncremental->Enter += gcnew System::EventHandler(this, &MainForm::groupBoxIncremental_Enter);
			// 
			// buttonFillArrayInc
			// 
			this->buttonFillArrayInc->Enabled = false;
			this->buttonFillArrayInc->Location = System::Drawing::Point(25, 431);
			this->buttonFillArrayInc->Name = L"buttonFillArrayInc";
			this->buttonFillArrayInc->Size = System::Drawing::Size(261, 42);
			this->buttonFillArrayInc->TabIndex = 19;
			this->buttonFillArrayInc->Text = L"Заполнить массив";
			this->buttonFillArrayInc->UseVisualStyleBackColor = true;
			this->buttonFillArrayInc->Click += gcnew System::EventHandler(this, &MainForm::buttonFillArrayInc_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(26, 382);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(114, 20);
			this->textBox9->TabIndex = 18;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox9_TextChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(24, 362);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(155, 13);
			this->label14->TabIndex = 17;
			this->label14->Text = L"Ед. измерения температуры:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(24, 261);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(125, 15);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Входной сигнал (мА)";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(172, 305);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(114, 20);
			this->textBox6->TabIndex = 15;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox6_TextChanged);
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
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(26, 305);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(114, 20);
			this->textBox7->TabIndex = 13;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox7_TextChanged);
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
			this->label6->Click += gcnew System::EventHandler(this, &MainForm::label6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(172, 218);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(114, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox4_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(170, 198);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Шаг:";
			this->label7->Click += gcnew System::EventHandler(this, &MainForm::label7_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(26, 218);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(114, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox5_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 198);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(115, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Начальное значение:";
			this->label8->Click += gcnew System::EventHandler(this, &MainForm::label8_Click);
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
			this->label5->Click += gcnew System::EventHandler(this, &MainForm::label5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(172, 132);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(114, 20);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox3_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(170, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Шаг:";
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(26, 132);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(114, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Начальное значение:";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(114, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
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
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// groupBoxManual
			// 
			this->groupBoxManual->Controls->Add(this->buttonFillArrayManual);
			this->groupBoxManual->Controls->Add(this->textBox8);
			this->groupBoxManual->Controls->Add(this->label12);
			this->groupBoxManual->Controls->Add(this->dataGridViewInput);
			this->groupBoxManual->Location = System::Drawing::Point(10, 6);
			this->groupBoxManual->Name = L"groupBoxManual";
			this->groupBoxManual->Size = System::Drawing::Size(361, 508);
			this->groupBoxManual->TabIndex = 0;
			this->groupBoxManual->TabStop = false;
			this->groupBoxManual->Text = L"Вручную";
			this->groupBoxManual->Enter += gcnew System::EventHandler(this, &MainForm::groupBoxManual_Enter);
			// 
			// buttonFillArrayManual
			// 
			this->buttonFillArrayManual->Enabled = false;
			this->buttonFillArrayManual->Location = System::Drawing::Point(46, 431);
			this->buttonFillArrayManual->Name = L"buttonFillArrayManual";
			this->buttonFillArrayManual->Size = System::Drawing::Size(261, 42);
			this->buttonFillArrayManual->TabIndex = 20;
			this->buttonFillArrayManual->Text = L"Заполнить массив";
			this->buttonFillArrayManual->UseVisualStyleBackColor = true;
			this->buttonFillArrayManual->Click += gcnew System::EventHandler(this, &MainForm::buttonFillArrayManual_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(28, 53);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(114, 20);
			this->textBox8->TabIndex = 3;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox8_TextChanged);
			this->textBox8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textBox8_KeyDown);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(26, 33);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(140, 15);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Размерность массива:";
			this->label12->Click += gcnew System::EventHandler(this, &MainForm::label12_Click);
			// 
			// dataGridViewInput
			// 
			this->dataGridViewInput->AllowUserToAddRows = false;
			this->dataGridViewInput->AllowUserToDeleteRows = false;
			this->dataGridViewInput->AllowUserToResizeColumns = false;
			this->dataGridViewInput->AllowUserToResizeRows = false;
			this->dataGridViewInput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewInput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->tempMinInput,
					this->tempMaxInput, this->inputSignalInput, this->unitInput
			});
			this->dataGridViewInput->Location = System::Drawing::Point(28, 91);
			this->dataGridViewInput->Name = L"dataGridViewInput";
			this->dataGridViewInput->RowHeadersVisible = false;
			this->dataGridViewInput->Size = System::Drawing::Size(324, 311);
			this->dataGridViewInput->TabIndex = 1;
			this->dataGridViewInput->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridViewInput_CellContentClick);
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
			this->inputSignalInput->HeaderText = L"Входной сигнал (мА)";
			this->inputSignalInput->MaxInputLength = 8;
			this->inputSignalInput->Name = L"inputSignalInput";
			this->inputSignalInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->inputSignalInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->inputSignalInput->Width = 80;
			// 
			// unitInput
			// 
			this->unitInput->HeaderText = L"Единицы измерения Температуры";
			this->unitInput->Name = L"unitInput";
			this->unitInput->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->unitInput->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->unitInput->Width = 80;
			// 
			// tabEdit
			// 
			this->tabEdit->Controls->Add(this->label1);
			this->tabEdit->Controls->Add(this->dataGridView);
			this->tabEdit->Location = System::Drawing::Point(4, 22);
			this->tabEdit->Name = L"tabEdit";
			this->tabEdit->Padding = System::Windows::Forms::Padding(3);
			this->tabEdit->Size = System::Drawing::Size(698, 522);
			this->tabEdit->TabIndex = 1;
			this->tabEdit->Text = L"Редактирование";
			this->tabEdit->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(283, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Массив датчиков";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->tempMin,
					this->tempMax, this->inputSignal, this->tempCurrent, this->unit, this->isOutRange
			});
			this->dataGridView->Location = System::Drawing::Point(8, 28);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(682, 484);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView_CellEndEdit);
			// 
			// tempMin
			// 
			this->tempMin->HeaderText = L"Минимальная температура";
			this->tempMin->MaxInputLength = 6;
			this->tempMin->Name = L"tempMin";
			this->tempMin->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tempMin->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tempMax
			// 
			this->tempMax->HeaderText = L"Максимальная температура";
			this->tempMax->MaxInputLength = 6;
			this->tempMax->Name = L"tempMax";
			this->tempMax->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tempMax->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// inputSignal
			// 
			this->inputSignal->HeaderText = L"Входной сигнал (мА)";
			this->inputSignal->MaxInputLength = 6;
			this->inputSignal->Name = L"inputSignal";
			this->inputSignal->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->inputSignal->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tempCurrent
			// 
			this->tempCurrent->HeaderText = L"Выходной сигнал (температура)";
			this->tempCurrent->MaxInputLength = 20;
			this->tempCurrent->MinimumWidth = 20;
			this->tempCurrent->Name = L"tempCurrent";
			this->tempCurrent->ReadOnly = true;
			this->tempCurrent->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tempCurrent->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tempCurrent->Width = 120;
			// 
			// unit
			// 
			this->unit->HeaderText = L"Единицы измерения температуры";
			this->unit->MaxInputLength = 8;
			this->unit->Name = L"unit";
			this->unit->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->unit->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// isOutRange
			// 
			this->isOutRange->HeaderText = L"Выход за пределы измерения (4-20 мА)";
			this->isOutRange->MaxInputLength = 8;
			this->isOutRange->MinimumWidth = 8;
			this->isOutRange->Name = L"isOutRange";
			this->isOutRange->ReadOnly = true;
			this->isOutRange->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->isOutRange->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->isOutRange->Width = 118;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(698, 522);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Операции";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->listBoxResult);
			this->groupBox4->Location = System::Drawing::Point(298, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(394, 513);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Результат";
			// 
			// listBoxResult
			// 
			this->listBoxResult->FormattingEnabled = true;
			this->listBoxResult->Location = System::Drawing::Point(6, 19);
			this->listBoxResult->Name = L"listBoxResult";
			this->listBoxResult->Size = System::Drawing::Size(382, 485);
			this->listBoxResult->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->buttonClear);
			this->groupBox5->Controls->Add(this->comboBoxOp);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Controls->Add(this->comboBoxSensor2);
			this->groupBox5->Controls->Add(this->label19);
			this->groupBox5->Controls->Add(this->buttonResult);
			this->groupBox5->Controls->Add(this->InputK);
			this->groupBox5->Controls->Add(this->label21);
			this->groupBox5->Controls->Add(this->comboBoxSensor1);
			this->groupBox5->Controls->Add(this->label23);
			this->groupBox5->Location = System::Drawing::Point(7, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(285, 516);
			this->groupBox5->TabIndex = 2;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Выбор операции";
			// 
			// buttonClear
			// 
			this->buttonClear->Enabled = false;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->Location = System::Drawing::Point(9, 351);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(253, 42);
			this->buttonClear->TabIndex = 15;
			this->buttonClear->Text = L"Очистить список";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// comboBoxOp
			// 
			this->comboBoxOp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxOp->FormattingEnabled = true;
			this->comboBoxOp->Location = System::Drawing::Point(6, 173);
			this->comboBoxOp->Name = L"comboBoxOp";
			this->comboBoxOp->Size = System::Drawing::Size(256, 21);
			this->comboBoxOp->TabIndex = 14;
			this->comboBoxOp->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxOp_SelectedIndexChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(6, 147);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(65, 15);
			this->label20->TabIndex = 13;
			this->label20->Text = L"Операция";
			// 
			// comboBoxSensor2
			// 
			this->comboBoxSensor2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSensor2->FormattingEnabled = true;
			this->comboBoxSensor2->Location = System::Drawing::Point(6, 108);
			this->comboBoxSensor2->Name = L"comboBoxSensor2";
			this->comboBoxSensor2->Size = System::Drawing::Size(256, 21);
			this->comboBoxSensor2->TabIndex = 12;
			this->comboBoxSensor2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxSensor2_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(6, 83);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 15);
			this->label19->TabIndex = 11;
			this->label19->Text = L"Датчик 2";
			// 
			// buttonResult
			// 
			this->buttonResult->Enabled = false;
			this->buttonResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonResult->Location = System::Drawing::Point(9, 298);
			this->buttonResult->Name = L"buttonResult";
			this->buttonResult->Size = System::Drawing::Size(253, 42);
			this->buttonResult->TabIndex = 10;
			this->buttonResult->Text = L"Показать результат";
			this->buttonResult->UseVisualStyleBackColor = true;
			this->buttonResult->Click += gcnew System::EventHandler(this, &MainForm::buttonResult_Click);
			// 
			// InputK
			// 
			this->InputK->Enabled = false;
			this->InputK->Location = System::Drawing::Point(162, 227);
			this->InputK->Name = L"InputK";
			this->InputK->Size = System::Drawing::Size(100, 20);
			this->InputK->TabIndex = 6;
			this->InputK->TextChanged += gcnew System::EventHandler(this, &MainForm::InputK_TextChanged);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(6, 217);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(126, 30);
			this->label21->TabIndex = 5;
			this->label21->Text = L"Параметр операции\r\n(если есть)\r\n";
			// 
			// comboBoxSensor1
			// 
			this->comboBoxSensor1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSensor1->FormattingEnabled = true;
			this->comboBoxSensor1->Location = System::Drawing::Point(6, 43);
			this->comboBoxSensor1->Name = L"comboBoxSensor1";
			this->comboBoxSensor1->Size = System::Drawing::Size(256, 21);
			this->comboBoxSensor1->TabIndex = 2;
			this->comboBoxSensor1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxSensor1_SelectedIndexChanged);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(6, 19);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(59, 15);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Датчик 1";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(698, 522);
			this->tabPage2->TabIndex = 3;
			this->tabPage2->Text = L"Графики";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->GraphTemp);
			this->groupBox3->Location = System::Drawing::Point(250, 260);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(440, 256);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"График выходного сигнала T(t)";
			// 
			// GraphTemp
			// 
			this->GraphTemp->Location = System::Drawing::Point(6, 19);
			this->GraphTemp->Name = L"GraphTemp";
			this->GraphTemp->Size = System::Drawing::Size(428, 227);
			this->GraphTemp->TabIndex = 0;
			this->GraphTemp->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->GraphI);
			this->groupBox2->Location = System::Drawing::Point(250, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(440, 259);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"График входного сигнала I(t)";
			// 
			// GraphI
			// 
			this->GraphI->Location = System::Drawing::Point(6, 19);
			this->GraphI->Name = L"GraphI";
			this->GraphI->Size = System::Drawing::Size(428, 234);
			this->GraphI->TabIndex = 0;
			this->GraphI->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numericScaleTemp);
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->numericScale);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->buttonShowGraphs);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->InputA);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->InputT);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->SelectSensor);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Location = System::Drawing::Point(5, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(239, 516);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры графика";
			// 
			// numericScaleTemp
			// 
			this->numericScaleTemp->Location = System::Drawing::Point(93, 320);
			this->numericScaleTemp->Name = L"numericScaleTemp";
			this->numericScaleTemp->Size = System::Drawing::Size(67, 20);
			this->numericScaleTemp->TabIndex = 14;
			this->numericScaleTemp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			this->numericScaleTemp->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericScaleTemp_ValueChanged);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(6, 320);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(85, 15);
			this->label22->TabIndex = 13;
			this->label22->Text = L"Масштаб T(t):";
			// 
			// numericScale
			// 
			this->numericScale->Location = System::Drawing::Point(93, 294);
			this->numericScale->Name = L"numericScale";
			this->numericScale->Size = System::Drawing::Size(67, 20);
			this->numericScale->TabIndex = 12;
			this->numericScale->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			this->numericScale->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericScale_ValueChanged);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(6, 294);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(81, 15);
			this->label18->TabIndex = 11;
			this->label18->Text = L"Масштаб I(t):";
			// 
			// buttonShowGraphs
			// 
			this->buttonShowGraphs->Enabled = false;
			this->buttonShowGraphs->Location = System::Drawing::Point(9, 393);
			this->buttonShowGraphs->Name = L"buttonShowGraphs";
			this->buttonShowGraphs->Size = System::Drawing::Size(163, 42);
			this->buttonShowGraphs->TabIndex = 10;
			this->buttonShowGraphs->Text = L"Отобразить\r\nграфики";
			this->buttonShowGraphs->UseVisualStyleBackColor = true;
			this->buttonShowGraphs->Click += gcnew System::EventHandler(this, &MainForm::buttonShowGraphs_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(9, 259);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 17);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Пилообразный";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &MainForm::radioButton2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(9, 236);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(117, 17);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Синусиоидальный";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &MainForm::radioButton1_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(6, 210);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(112, 15);
			this->label17->TabIndex = 7;
			this->label17->Text = L"Закон изменения:";
			// 
			// InputA
			// 
			this->InputA->Location = System::Drawing::Point(9, 162);
			this->InputA->Name = L"InputA";
			this->InputA->Size = System::Drawing::Size(100, 20);
			this->InputA->TabIndex = 6;
			this->InputA->TextChanged += gcnew System::EventHandler(this, &MainForm::InputA_TextChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(6, 144);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(70, 15);
			this->label16->TabIndex = 5;
			this->label16->Text = L"Амплитуда";
			// 
			// InputT
			// 
			this->InputT->Location = System::Drawing::Point(9, 105);
			this->InputT->Name = L"InputT";
			this->InputT->Size = System::Drawing::Size(100, 20);
			this->InputT->TabIndex = 4;
			this->InputT->TextChanged += gcnew System::EventHandler(this, &MainForm::InputT_TextChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(6, 87);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(51, 15);
			this->label15->TabIndex = 3;
			this->label15->Text = L"Период";
			// 
			// SelectSensor
			// 
			this->SelectSensor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SelectSensor->FormattingEnabled = true;
			this->SelectSensor->Location = System::Drawing::Point(6, 41);
			this->SelectSensor->Name = L"SelectSensor";
			this->SelectSensor->Size = System::Drawing::Size(227, 21);
			this->SelectSensor->TabIndex = 2;
			this->SelectSensor->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectSensor_SelectedIndexChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(6, 19);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 15);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Датчик";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(709, 552);
			this->Controls->Add(this->tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Токовый датчик температуры";
			this->tabControl->ResumeLayout(false);
			this->tabInbut->ResumeLayout(false);
			this->groupBoxIncremental->ResumeLayout(false);
			this->groupBoxIncremental->PerformLayout();
			this->groupBoxManual->ResumeLayout(false);
			this->groupBoxManual->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInput))->EndInit();
			this->tabEdit->ResumeLayout(false);
			this->tabEdit->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphTemp))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphI))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericScaleTemp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericScale))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonFillArrayInc();
	}
	private: void enableButtonFillArrayInc() {
		bool enableButton = textBox1->Text != "" && textBox2->Text != ""
			&& textBox3->Text != "" && textBox4->Text != "" && textBox5->Text != ""
			&& textBox6->Text != "" && textBox7->Text != "" && textBox9->Text != "";
		buttonFillArrayInc->Enabled = enableButton;
	}

	private: void enableButtonFillArrayManual() {
		bool enableButton = textBox8->Text != "";
		buttonFillArrayManual->Enabled = enableButton;
	}

	private: void enableButtonResult() {
		if (comboBoxSensor1->SelectedItem && comboBoxSensor2->SelectedItem
			&& comboBoxOp->SelectedItem && comboBoxOp->SelectedItem == 2)
			buttonResult->Enabled = InputK->Text->Length > 0;
		else if (comboBoxSensor1->SelectedItem && comboBoxSensor2->SelectedItem && comboBoxOp->SelectedItem)
			buttonResult->Enabled = true;
		else  buttonResult->Enabled = false;
	}

	private: System::Void buttonFillArrayInc_Click(System::Object^ sender, System::EventArgs^ e);

	private: void SetDataGridViewDataSource();
	private: System::Void dataGridView_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void textBox8_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

	private: void SetDataGridViewInput();
	private: System::Void buttonFillArrayManual_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void radioButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		radioButton1->Checked = true;
		SetEnabledShowGraphs();
		if (radioButton2->Checked) radioButton2->Checked = false;
	}
	private: System::Void radioButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		radioButton2->Checked = true;
		SetEnabledShowGraphs();
		if (radioButton1->Checked) radioButton1->Checked = false;
	}
	private: System::Void InputT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnabledShowGraphs();
	}
	private: System::Void InputA_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnabledShowGraphs();
	}
	private: System::Void SelectSensor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SetEnabledShowGraphs();
	}

	private: void SetEnabledShowGraphs();
	private: System::Void tabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonShowGraphs_Click(System::Object^ sender, System::EventArgs^ e);

	private: void ShowGraphSinI(int index, float T, float A, int unit);
	private: void ShowGraphSinTemp(CurrentTempSensor sensor, int index, float T, float A, int unit);
	private: void ShowGraphsSawI(float y0, float T, float A, int unit);
	private: void ShowGraphsSawTemp(CurrentTempSensor sensor, float T, float A, int unit);

	private: System::Void numericScale_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (numericScale->Value < 1) numericScale->Value = 1;
	}

	private: void setComboBoxOp() {
		for (int i = 0; i < COUNT_OPS; i++)
		{
			String^ item = gcnew String(dataOps[i]);
			comboBoxOp->Items->Add(item);
		}
	}
	private: System::Void comboBoxOp_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		InputK->Enabled = comboBoxOp->SelectedIndex == 2;
		enableButtonResult();
	}
	private: System::Void comboBoxSensor1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonResult();
	}
	private: System::Void comboBoxSensor2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonResult();
	}
	private: System::Void InputK_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		enableButtonResult();
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		listBoxResult->Items->Clear();
		buttonClear->Enabled = false;
	}
	private: System::Void buttonResult_Click(System::Object^ sender, System::EventArgs^ e);
	private: void updateCombBoxSensors();
	private: System::Void numericScaleTemp_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (numericScaleTemp->Value < 1) numericScaleTemp->Value = 1;
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridViewInput_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tabInbut_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBoxIncremental_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBoxManual_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
