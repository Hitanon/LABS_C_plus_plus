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
		strUnit == "К" || strUnit == "к" || strUnit == "K" || strUnit == "k" ? unit = 'K' : ' ';
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
			dataGridView->Rows[index]->Cells["isOutRange"]->Value = arraySensors[index].isOutRange() ? "Да" : "Нет";
		}
		catch (System::FormatException^ ex) {
			dataGridView->Rows[index]->Cells["inputSignal"]->Value = arraySensors[index].getInputSignal();
			MessageBox::Show("Входной сигнал должен быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	if (e->ColumnIndex == 4) {
		int index = e->RowIndex;
		char unit = ' ';
		String^ value = dataGridView->Rows[index]->Cells[e->ColumnIndex]->Value->ToString();
		try {
			if (value == "град.К") unit = 'K';
			else if (value == "град.С") unit = 'C';
			if (value->Length == 1) {
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

void lab9::MainForm::SetEnabledShowGraphs()
{
	if (InputT->Text != "" && InputA->Text != "" && SelectSensor->SelectedItem
		&& (radioButton1->Checked || radioButton2->Checked))
		buttonShowGraphs->Enabled = true;
	else
		buttonShowGraphs->Enabled = false;
}

System::Void lab9::MainForm::tabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (tabControl->SelectedIndex == 3)
	{
		SelectSensor->Items->Clear();
		for (int i = 0; i < SIZE; i++)
		{
			String^ sensor = String::Format("I={0}, T={1}; T1={2}; T2={3}, Ед.Изм=",
				arraySensors[i].getInputSignal(), arraySensors[i].getTempCurrent(), arraySensors[i].getTempMin(), arraySensors[i].getTempMax())
				+ (arraySensors[i].getUnit() == 'K' ? "K" : "C");
			SelectSensor->Items->Add(sensor);
		}
		tabControl->SelectedIndex = 3;
	}
	if (tabControl->SelectedIndex == 2)
	{
		updateCombBoxSensors();
		tabControl->SelectedIndex = 2;
	}
}

System::Void lab9::MainForm::buttonShowGraphs_Click(System::Object^ sender, System::EventArgs^ e)
{
	float T, A;
	int index = SelectSensor->SelectedIndex;
	bool isSin = radioButton1->Checked;
	if (!float::TryParse(InputT->Text, T))
	{
		MessageBox::Show("Период должен быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (!float::TryParse(InputA->Text, A))
	{
		MessageBox::Show("Амплитуда должна быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (T < 0)
	{
		MessageBox::Show("Период должен быть вещественным числом!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int scaleI = int(numericScale->Value);
	int scaleT = int(numericScaleTemp->Value);
	if (radioButton1->Checked)
	{
		ShowGraphSinI(index, T, A, scaleI);
		ShowGraphSinTemp(arraySensors[index], index, T, A, scaleT);
	}
	else
	{
		ShowGraphsSawI(arraySensors[index].getInputSignal(), T, A, scaleI);
		ShowGraphsSawTemp(arraySensors[index], T, A, scaleT);
	}
}

void lab9::MainForm::ShowGraphSinI(int index, float T, float A, int unit)
{
	int width = GraphI->Width, height = GraphI->Height;
	Bitmap^ image = gcnew Bitmap(width, height);
	Graphics^ g = Graphics::FromImage(image);
	Pen^ pen = gcnew Pen(Color::Black, 1);

	int midY = int(height / 2);
	g->ScaleTransform(1, -1);
	g->TranslateTransform(0, -midY);

	// сетка
	for (int i = unit; i < width; i += unit)
		g->DrawLine(pen, i, -height / 2, i, height / 2);
	for (int i = 0; i < height / 2; i += unit)
	{
		g->DrawLine(pen, 0, i, width, i);
		g->DrawLine(pen, 0, -i, width, -i);
	}

	// оси координат
	pen->Width = 2;
	g->DrawLine(pen, 0, 0, width, 0);
	g->DrawLine(pen, unit, -height / 2, unit, height / 2);

	// график
	double x1 = 0, x2 = width, step = 0.1;
	double x = x1;
	double y;
	System::Collections::Generic::List<PointF>^ Points =
		gcnew System::Collections::Generic::List<PointF>();

	int i = 0;
	while (x < x2)
	{
		y = calcSin(index, A, T, x);
		Points->Add(PointF(x * unit + unit, y * unit));
		x = x1 + step * i++;
	}

	pen->Color = Color::Red;
	pen->Width = 3;

	g->DrawLines(pen, Points->ToArray());

	delete g;

	GraphI->Image = image;
}


void lab9::MainForm::ShowGraphSinTemp(CurrentTempSensor sensor, int index, float T, float A, int unit)
{
	int width = GraphTemp->Width, height = GraphTemp->Height;
	Bitmap^ image = gcnew Bitmap(width, height);
	Graphics^ g = Graphics::FromImage(image);
	Pen^ pen = gcnew Pen(Color::Black, 1);

	int midY = int(height / 2);
	g->ScaleTransform(1, -1);
	g->TranslateTransform(0, -midY);

	// сетка
	for (int i = unit; i < width; i += unit)
		g->DrawLine(pen, i, -height / 2, i, height / 2);
	for (int i = 0; i < height / 2; i += unit)
	{
		g->DrawLine(pen, 0, i, width, i);
		g->DrawLine(pen, 0, -i, width, -i);
	}

	// оси координат
	pen->Width = 2;
	g->DrawLine(pen, 0, 0, width, 0);
	g->DrawLine(pen, unit, -height / 2, unit, height / 2);

	// график
	double x1 = 0, x2 = width, step = 0.1;
	double x = x1;
	double y;
	System::Collections::Generic::List<PointF>^ Points =
		gcnew System::Collections::Generic::List<PointF>();

	int i = 0;
	while (x < x2)
	{
		y = calcSin(index, A, T, x);
		sensor.setInputSignal(y);
		Points->Add(PointF(x * unit + unit, sensor.getTempCurrent() * unit));
		x = x1 + step * i++;
	}

	pen->Color = Color::Red;
	pen->Width = 3;

	g->DrawLines(pen, Points->ToArray());

	delete g;

	GraphTemp->Image = image;
}


void lab9::MainForm::ShowGraphsSawI(float y0, float T, float A, int unit)
{
	int width = GraphI->Width, height = GraphI->Height;
	Bitmap^ image = gcnew Bitmap(width, height);
	Graphics^ g = Graphics::FromImage(image);
	Pen^ pen = gcnew Pen(Color::Black, 1);

	int midY = int(height / 2);
	g->ScaleTransform(1, -1);
	g->TranslateTransform(0, -midY);

	// сетка
	for (int i = unit; i < width; i += unit)
		g->DrawLine(pen, i, -height / 2, i, height / 2);
	for (int i = 0; i < height / 2; i += unit)
	{
		g->DrawLine(pen, 0, i, width, i);
		g->DrawLine(pen, 0, -i, width, -i);
	}

	// оси координат
	pen->Width = 2;
	g->DrawLine(pen, 0, 0, width, 0);
	g->DrawLine(pen, unit, -height / 2, unit, height / 2);

	// график
	double x1 = 0, x2 = width;
	double x = x1;
	double y;
	System::Collections::Generic::List<PointF>^ Points =
		gcnew System::Collections::Generic::List<PointF>();

	int i = 0;
	while (x < x2)
	{
		Points->Add(PointF(x * unit + unit, y0 * unit));
		Points->Add(PointF((x + T) * unit + unit, (A + y0) * unit));
		x = x1 + T * i++;
	}

	pen->Color = Color::Red;
	pen->Width = 3;
	g->DrawLines(pen, Points->ToArray());

	delete g;
	GraphI->Image = image;
}

void lab9::MainForm::ShowGraphsSawTemp(CurrentTempSensor sensor, float T, float A, int unit)
{
	int width = GraphTemp->Width, height = GraphTemp->Height;
	Bitmap^ image = gcnew Bitmap(width, height);
	Graphics^ g = Graphics::FromImage(image);
	Pen^ pen = gcnew Pen(Color::Black, 1);

	int midY = int(height / 2);
	g->ScaleTransform(1, -1);
	g->TranslateTransform(0, -midY);

	// сетка
	for (int i = unit; i < width; i += unit)
		g->DrawLine(pen, i, -height / 2, i, height / 2);
	for (int i = 0; i < height / 2; i += unit)
	{
		g->DrawLine(pen, 0, i, width, i);
		g->DrawLine(pen, 0, -i, width, -i);
	}

	// оси координат
	pen->Width = 2;
	g->DrawLine(pen, 0, 0, width, 0);
	g->DrawLine(pen, unit, -height / 2, unit, height / 2);

	// график
	double x1 = 0, x2 = width;
	double x = x1;
	double y;
	double y0 = sensor.getInputSignal();
	System::Collections::Generic::List<PointF>^ Points =
		gcnew System::Collections::Generic::List<PointF>();

	int i = 0;
	while (x < x2)
	{
		sensor.setInputSignal(y0);
		Points->Add(PointF(x * unit + unit, sensor.getTempCurrent() * unit));
		sensor.setInputSignal(A + y0);
		Points->Add(PointF((x + T) * unit + unit, sensor.getTempCurrent() * unit));
		x = x1 + T * i++;
	}

	pen->Color = Color::Red;
	pen->Width = 3;
	g->DrawLines(pen, Points->ToArray());

	delete g;
	GraphTemp->Image = image;
}

System::Void lab9::MainForm::buttonResult_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ resultStr;
	buttonClear->Enabled = listBoxResult->Items->Count;
	if (comboBoxOp->SelectedIndex == 0)
	{
		if (arraySensors[comboBoxSensor2->SelectedIndex].getTempCurrent() != 0)
		{
			float result = arraySensors[comboBoxSensor1->SelectedIndex] / arraySensors[comboBoxSensor2->SelectedIndex];
			resultStr = String::Format("Отношение T двух выбранных датчиков = {0:F3}", result);
		}
		else
		{
			resultStr = "Ошибка! T датчика 2 = 0";
		}
		listBoxResult->Items->Add(resultStr);
	}
	else if (comboBoxOp->SelectedIndex == 1)
	{
		float result = arraySensors[comboBoxSensor1->SelectedIndex] - arraySensors[comboBoxSensor2->SelectedIndex];
		resultStr = String::Format("Разность T двух выбранных датчиков = {0:F3}", result);
		listBoxResult->Items->Add(resultStr);
	}
	else if (comboBoxOp->SelectedIndex == 2)
	{
		float k;
		if (!float::TryParse(InputK->Text, k))
		{
			resultStr = "Параметр операции должен быть вещественным числом!";
		}
		else
		{
			arraySensors[comboBoxSensor1->SelectedIndex] += k;
			CurrentTempSensor sensor = arraySensors[comboBoxSensor1->SelectedIndex];
			resultStr = String::Format("Датчик 1: Входной сигнал = {0:F3}, Температура = {1}\n",
				sensor.getInputSignal(), sensor.ToString());
			enableButtonResult();
		}
		updateCombBoxSensors();
		listBoxResult->Items->Add(resultStr);
	}
	else if (comboBoxOp->SelectedIndex == 3)
	{
		CurrentTempSensor sensor1 = arraySensors[comboBoxSensor1->SelectedIndex];
		CurrentTempSensor sensor2 = arraySensors[comboBoxSensor2->SelectedIndex];
		if (sensor1 == sensor2)
			resultStr = "Значения T двух датчиков равны";
		else if (sensor1 > sensor2)
			resultStr = "T датчика 1 больше";
		else if (sensor1 < sensor2)
			resultStr = "T датчика 1 меньше";
		else
			resultStr = "Неопознанная ситуация";
		listBoxResult->Items->Add(resultStr);
	}
}

void lab9::MainForm::updateCombBoxSensors()
{
	comboBoxSensor1->Items->Clear();
	comboBoxSensor2->Items->Clear();
	for (int i = 0; i < SIZE; i++)
	{
		String^ sensor = String::Format("I={0}, T={1}; T1={2}; T2={3}, Ед.Изм=",
			arraySensors[i].getInputSignal(), arraySensors[i].getTempCurrent(), arraySensors[i].getTempMin(), arraySensors[i].getTempMax())
			+ (arraySensors[i].getUnit() == 'K' ? "K" : "C");
		comboBoxSensor1->Items->Add(sensor);
		comboBoxSensor2->Items->Add(sensor);
	}
}

