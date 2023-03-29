#pragma once
#include"Indicator.h"

class RoundIndicator : public Indicator
{
public:
	RoundIndicator() : Indicator()
	{
		SetColor();
	}

	RoundIndicator(float temp,
		float minTemp,
		float maxTemp,
		float x,
		float y,
		byte scale,
		string label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{
		SetColor();
	}

	RoundIndicator(String^ temp,
		String^ minTemp,
		String^ maxTemp,
		String^ x,
		String^ y,
		String^ scale,
		String^ label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{
		SetColor();
	}

	RoundIndicator(const RoundIndicator& other)
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

	RoundIndicator* clone() const
	{
		return new RoundIndicator(*this);
	}

	void SetColor()
	{
		if (IsOutRange())
		{
			color = 0xFF000000;
			return;
		}
		uint value;
		float unit;
		int alpha;
		if (temp >= 0)
		{
			value = 0xFF0000;
			minTemp < 0 ? unit = abs(maxTemp) / 255, alpha = abs(temp) / unit :
				unit = abs(maxTemp - minTemp) / 255, alpha = abs(temp-minTemp) / unit;
		}
		else
		{
			value = 0x0000FF;
			maxTemp > 0 ? unit = abs(minTemp) / 255, alpha = abs(temp) / unit :
				unit = abs(maxTemp-minTemp) / 255, alpha = abs(temp - maxTemp) / unit;
		}
		color = (alpha << 24) | (value);
	}

	void DrawIndicator(Windows::Forms::GroupBox^ groupBox)
	{
		float shiftX = 10;
		float shiftY = 20;

		Color^ col = gcnew Color;
		Graphics^ graphics = groupBox->CreateGraphics();
		graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		Pen^ pen = gcnew Pen(col->Black);
		pen->Width = 2;
		SolidBrush^ brush = gcnew SolidBrush(col->FromArgb(color));

		Font^ font = gcnew Font("Arial", 4 * scale, FontStyle::Bold);
		SolidBrush^ textBrush = gcnew SolidBrush(Color::Black);

		String^ text = marshal_as<System::String^>(label);

		graphics->FillEllipse(brush, x + shiftX, y + shiftY, float(10 * scale), float(10 * scale));
		graphics->DrawEllipse(pen, x + shiftX, y + shiftY, float(10 * scale), float(10 * scale));
		graphics->DrawString(text, font, textBrush, x + shiftX + float(10 * scale), y + shiftY);
	}
};