#pragma once
#include "CurrentTempSensor.h"

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
			MessageBox::Show("Лабораторная работа №9, вариант 5\nМалышев Максим, 2 курс, гр.ПМИ - 1", "Инфо", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
			this->tabControl->SuspendLayout();
			this->tabInbut->SuspendLayout();
			this->groupBoxIncremental->SuspendLayout();
			this->groupBoxManual->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInput))->BeginInit();
			this->tabEdit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabInbut);
			this->tabControl->Controls->Add(this->tabEdit);
			this->tabControl->ImeMode = System::Windows::Forms::ImeMode::On;
			this->tabControl->Location = System::Drawing::Point(3, 12);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(706, 548);
			this->tabControl->TabIndex = 0;
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

	private: System::Void buttonFillArrayInc_Click(System::Object^ sender, System::EventArgs^ e);

	private: void SetDataGridViewDataSource();
	private: System::Void dataGridView_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void textBox8_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

	private: void SetDataGridViewInput();
	private: System::Void buttonFillArrayManual_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
