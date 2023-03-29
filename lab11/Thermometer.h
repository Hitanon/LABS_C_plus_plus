#pragma once
#include"Indicator.h"

class Thermometer : public Indicator
{
public:
	Thermometer() : Indicator() {};

	Thermometer(float temp,
		float minTemp,
		float maxTemp,
		float x,
		float y,
		byte scale,
		string label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{};

	Thermometer(String^ temp,
		String^ minTemp,
		String^ maxTemp,
		String^ x,
		String^ y,
		String^ scale,
		String^ label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{};

	Thermometer(const Thermometer& other)
	{
		temp = other.temp;
		minTemp = other.minTemp;
		maxTemp = other.maxTemp;
		x = other.x;
		y = other.y;
		scale = other.scale;
		label = other.label;
		color = other.color;
	}

	Thermometer* clone() const
	{
		return new Thermometer(*this);
	}

	void SetColor(uint value)
	{
		color = value;
	}

	void DrawIndicator(Windows::Forms::GroupBox^ groupBox)
	{
		float shiftX = 10;
		float shiftY = 20;



		Graphics^ g = groupBox->CreateGraphics();
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		// Calculate dimensions of the thermometer scale
		float width = 30 * scale;
		float height = 110 * scale;
		float x = this->x + shiftX;
		float y = this->y + shiftY;
		float scaleWidth = width / 4;
		float scaleHeight = height - 20;
		float scaleX = x + width - scaleWidth;
		float scaleY = y + 10;

		// Прямоугольник
		Pen^ blackPen = gcnew Pen(Color::Black, 1.0f);
		g->DrawArc(blackPen, x, y, 20.0f, 20.0f, 180.0f, 90.0f);
		g->DrawArc(blackPen, x + width - 20.0f, y, 20.0f, 20.0f, 270.0f, 90.0f);
		g->DrawArc(blackPen, x, y + height - 20.0f, 20.0f, 20.0f, 90.0f, 90.0f);
		g->DrawArc(blackPen, x + width - 20.0f, y + height - 20.0f, 20.0f, 20.0f, 0.0f, 90.0f);
		g->DrawLine(blackPen, x + 10.0f, y, x + width - 10.0f, y);
		g->DrawLine(blackPen, x + 10.0f, y + height, x + width - 10.0f, y + height);
		g->DrawLine(blackPen, x, y + 10.0f, x, y + height - 10.0f);
		g->DrawLine(blackPen, x + width, y + 10.0f, x + width, y + height - 10.0f);

		// Шкала
		blackPen->Width = 2.0f;
		g->DrawLine(blackPen, scaleX, scaleY, scaleX, scaleY + scaleHeight);
		float divHeight = scaleHeight / 4;

		StringFormat^ format = gcnew StringFormat();
		format->Alignment = StringAlignment::Far;

		int step = max(1, (maxTemp - minTemp) / 4);
		for (int i = minTemp; i <= maxTemp; i += step) {
			float divY = scaleY + ((maxTemp - minTemp) - (i - minTemp)) * scaleHeight / (maxTemp - minTemp) - blackPen->Width / 2;
			g->DrawLine(blackPen, scaleX - 5 * scale, divY, scaleX, divY);
			g->DrawString(i.ToString(), gcnew Font("Arial", 6 * scale - 3), Brushes::Black, scaleX - 10 * scale, divY - 3 * scale, format);
		}

		// Индикатор температуры
		blackPen->Width = scale;
		if (this->temp < minTemp) temp = minTemp;
		if (this->temp > maxTemp) temp = maxTemp;
		float indicatorY = scaleY + (maxTemp - temp) * scaleHeight / (maxTemp - minTemp);
		g->DrawLine(gcnew Pen(Color::FromArgb(color), 2 * scale), scaleX, indicatorY, scaleX, scaleY + scaleHeight);

		// Метка индикатора
		String^ text = marshal_as<System::String^>(label);
		g->DrawString(text, gcnew Font("Arial", 8 * scale - 3, FontStyle::Bold), Brushes::Black, scaleX + 25 * scale, scaleY, format);
	}

};