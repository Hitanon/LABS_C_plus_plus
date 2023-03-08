#include "MainForm.h"

System::Void lab9::MainForm::buttonFillArrayInc_Click(System::Object^ sender, System::EventArgs^ e)
{
	int temp;
	float tempMin, stepTempMin, tempMax, stepTempMax, inputSignal, stepInputSignal;
	String^ strUnit;
	char unit;

	if (!int::TryParse(textBox1->Text, temp)) {
		MessageBox::Show("Размерность массива должна быть целым числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (temp < 1) {
		MessageBox::Show("Размерность массива должна быть больше 0!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox2->Text, tempMin)) {
		MessageBox::Show("Минимальная температуры должна быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox3->Text, stepTempMin)) {
		MessageBox::Show("Шаг минимальной температура должен быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox5->Text, tempMax)) {
		MessageBox::Show("Максимальная температуры должна быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox4->Text, stepTempMax)) {
		MessageBox::Show("Шаг максимальной температура должен быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox7->Text, inputSignal)) {
		MessageBox::Show("Входной сигнал должен быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	else if (!float::TryParse(textBox6->Text, stepInputSignal)) {
		MessageBox::Show("Шаг входного сигнала должен быть вещественным числом!", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	strUnit = textBox9->Text;
	if (strUnit == "град.К") unit = 'K';
	else if (strUnit == "град.С") unit = 'C';
	else if (strUnit->Length == 1) {
		strUnit == "К" || strUnit == "к" || strUnit == "K" || strUnit == "k" ? unit = 'K'  : ' ';
		strUnit == "С" || strUnit == "с" || strUnit == "C" || strUnit == "c" ? unit = 'C' : ' ';
	}

	SIZE = temp;
	createArraySensors();
	try {
		fillArraySensorsInc(tempMin, stepTempMin, tempMax, stepTempMax, inputSignal, stepInputSignal, unit);
	}
	catch (exception& e) {
		MessageBox::Show(gcnew String(e.what()), "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	SetDataGridViewDataSource();
	MessageBox::Show("Массив заполнен успешно!", "Выполнено",
		MessageBoxButtons::OK, MessageBoxIcon::Information);
	tabControl->SelectedIndex = 1;
}

void lab9::MainForm::SetDataGridViewDataSource()
{
	dataGridView->Rows->Clear();
	float tempMin, tempMax, inputSignal;
	String^ tempCurrent, ^ isOutRange, ^ unit;
	for (int i = 0; i < SIZE; i++)
	{
		tempMin = arraySensors[i].getTempMin();
		tempMax = arraySensors[i].getTempMax();
		inputSignal = arraySensors[i].getInputSignal();
		tempCurrent = arraySensors[i].ToString();
		unit = arraySensors[i].getUnit() == 'K' ? "K" : "C";
		isOutRange = arraySensors[i].isOutRange() ? "Да" : "Нет";
		dataGridView->Rows->Add(tempMin, tempMax, inputSignal, tempCurrent, unit, isOutRange);
	}
}

System::Void lab9::MainForm::dataGridView_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->ColumnIndex == 0) {
		int index = e->RowIndex;
		String^ value = dataGridView->Rows[index]->Cells[e->ColumnIndex]->Value->ToString();
		try {
			float tempMin = float::Parse(value);
			arraySensors[index].setTempMin(tempMin);
			dataGridView->Rows[index]->Cells["tempMin"]->Value = tempMin;
			dataGridView->Rows[index]->Cells["tempCurrent"]->Value = arraySensors[index].ToString();
		}
		catch (System::FormatException^ ex) {
			dataGridView->Rows[index]->Cells["tempMin"]->Value = arraySensors[index].getTempMin();
			MessageBox::Show("Минимальная температура должна быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (exception& ex) {
			dataGridView->Rows[index]->Cells["tempMin"]->Value = arraySensors[index].getTempMin();
			MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	if (e->ColumnIndex == 1) {
		int index = e->RowIndex;
		String^ value = dataGridView->Rows[index]->Cells[e->ColumnIndex]->Value->ToString();
		try {
			float tempMax = float::Parse(value);
			arraySensors[index].setTempMax(tempMax);
			dataGridView->Rows[index]->Cells["tempMax"]->Value = tempMax;
			dataGridView->Rows[index]->Cells["tempCurrent"]->Value = arraySensors[index].ToString();
		}
		catch (System::FormatException^ ex) {
			dataGridView->Rows[index]->Cells["tempMax"]->Value = arraySensors[index].getTempMax();
			MessageBox::Show("Максимальная температура должна быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (exception& ex) {
			dataGridView->Rows[index]->Cells["tempMin"]->Value = arraySensors[index].getTempMin();
			MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	if (e->ColumnIndex == 2) {
		int index = e->RowIndex;
		String^ value = dataGridView->Rows[index]->Cells[e->ColumnIndex]->Value->ToString();
		try {
			float inputSignal = float::Parse(value);
			arraySensors[index].setInputSignal(inputSignal);
			dataGridView->Rows[index]->Cells["inputSignal"]->Value = arraySensors[index].getInputSignal();
			dataGridView->Rows[index]->Cells["tempCurrent"]->Value = arraySensors[index].ToString();
			dataGridView->Rows[index]->Cells["isOutRange"]->Value = arraySensors[index].isOutRange() ? "Да": "Нет";
		}
		catch (System::FormatException^ ex) {
			dataGridView->Rows[index]->Cells["inputSignal"]->Value = arraySensors[index].getInputSignal();
			MessageBox::Show("Входной сигнал должен быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	if (e->ColumnIndex == 4) {
		int index = e->RowIndex;
		char unit;
		String^ value = dataGridView->Rows[index]->Cells[e->ColumnIndex]->Value->ToString();
		try {
			if (value == "град.К") unit = 'K';
			else if (value == "град.С") unit = 'C';
			if (value->Length == 1){
				value == "К" || value == "к" || value == "K" || value == "k" ? unit = 'K' : ' ';
				value == "С" || value == "с" || value == "C" || value == "c" ? unit = 'C' : ' ';
			}
			arraySensors[index].setUnit(unit);
			dataGridView->Rows[index]->Cells["tempMin"]->Value = arraySensors[index].getTempMin();
			dataGridView->Rows[index]->Cells["tempMax"]->Value = arraySensors[index].getTempMax();
			dataGridView->Rows[index]->Cells["tempCurrent"]->Value = arraySensors[index].ToString();
		}
		catch (exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		finally {
			dataGridView->Rows[index]->Cells["unit"]->Value = arraySensors[index].getUnit() == 'K' ? "K" : "C";
		}
	}
}

System::Void lab9::MainForm::textBox8_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	int temp;
	if (e->KeyCode == Keys::Enter) {
		if (!int::TryParse(textBox8->Text, temp)) {
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
			SIZE = temp;
			enableButtonFillArrayManual();
			SetDataGridViewInput();
		}
	}
}

void lab9::MainForm::SetDataGridViewInput()
{
	dataGridViewInput->Rows->Clear();
	for (int i = 0; i < SIZE; i++)
		dataGridViewInput->Rows->Add();
}

System::Void lab9::MainForm::buttonFillArrayManual_Click(System::Object^ sender, System::EventArgs^ e)
{
	int SIZE = dataGridViewInput->RowCount;
	try {
		float tempMin, tempMax, inputSignal;
		char unit;
		createArraySensors();
		for (int i = 0; i < SIZE; i++)
		{
			tempMin = float::Parse(dataGridViewInput->Rows[i]->Cells["tempMinInput"]->Value->ToString());
			tempMax = float::Parse(dataGridViewInput->Rows[i]->Cells["tempMaxInput"]->Value->ToString());
			inputSignal = float::Parse(dataGridViewInput->Rows[i]->Cells["inputSignalInput"]->Value->ToString());
			String^ value = dataGridViewInput->Rows[i]->Cells["unitInput"]->Value->ToString();
			unit = ' ';
			if (value == "град.К") unit = 'K';
			else if (value == "град.С") unit = 'C';
			else if (value->Length == 1) {
				value == "К" || value == "к" ? unit = 'K' : ' ';
				value == "С" || value == "с" ? unit = 'C' : ' ';
				value == "K" || value == "k" ? unit = 'K' : ' ';
				value == "C" || value == "c" ? unit = 'C' : ' ';
			}
			arraySensors[i] = CurrentTempSensor(unit, tempMin, tempMax, inputSignal);
		}
		SetDataGridViewDataSource();
		MessageBox::Show("Массив заполнен успешно!", "Выполнено",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		tabControl->SelectedIndex = 1;
	}
	catch (System::FormatException^ ex) {
		deletArraySensors();
		MessageBox::Show("Значения температуры и входного сигнала должны быть вещественными числами!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (exception& ex) {
		deletArraySensors();
		MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
