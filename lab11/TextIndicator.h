#pragma once
#include"Indicator.h"

class TextIndicator : public Indicator
{
public:
	TextIndicator() : Indicator() {};

	TextIndicator(float temp,
		float minTemp,
		float maxTemp,
		float x,
		float y,
		byte scale,
		string label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{
		SetColor();
	}

	TextIndicator(String^ temp,
		String^ minTemp,
		String^ maxTemp,
		String^ x,
		String^ y,
		String^ scale,
		String^ label) : Indicator(temp, minTemp, maxTemp, x, y, scale, label)
	{
		SetColor();
	}

	TextIndicator(const TextIndicator& other)
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

	TextIndicator* clone() const
	{
		return new TextIndicator(*this);
	}

	void SetColor()
	{
		color = 0xFF000000;
	}

	void DrawIndicator(Windows::Forms::GroupBox^ groupBox)
	{
		float shiftX = 10;
		float shiftY = 20;

		float x = this->x + shiftX;
		float y = this->y + shiftY;

		Color bgColor = Color::FromArgb(color);
		Font^ font = gcnew Font("Arial", scale * 10, FontStyle::Bold);
		SolidBrush^ brush = gcnew SolidBrush(bgColor);
		Pen^ pen = gcnew Pen(bgColor, scale);

		Graphics^ g = groupBox->CreateGraphics();
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		String^ text;
		ostringstream oss;
		float rounded_num = roundf(temp * 100) / 100;
		oss << std::fixed << std::setprecision(2) << rounded_num;
		string str_num = oss.str();

		if (IsOutRange()) text = "Ошибка";
		else text = marshal_as<System::String^>(label + " = " + str_num + " °С");

		// расчет размеров прямоугольинка
		SizeF textSize = g->MeasureString(text, font);
		float rectWidth = textSize.Width + scale * 20;
		float rectHeight = textSize.Height + scale * 20;

		Drawing::Drawing2D::GraphicsPath^ roundedRect = gcnew Drawing::Drawing2D::GraphicsPath();
		roundedRect->AddArc(x, y, scale * 20.0f, scale * 20.0f, 180.0f, 90.0f);
		roundedRect->AddLine(x + scale * 10.0f, y, x + rectWidth - scale * 10.0f, y);
		roundedRect->AddArc(x + rectWidth - scale * 20, y, scale * 20.0f, scale * 20.0f, 270.0f, 90.0f);
		roundedRect->AddLine(x + rectWidth, y + scale * 10, x + rectWidth, y + rectHeight - scale * 10);
		roundedRect->AddArc(x + rectWidth - scale * 20, y + rectHeight - scale * 20, scale * 20.0f, scale * 20.0f, 0.0f, 90.0f);
		roundedRect->AddLine(x + rectWidth - scale * 10, y + rectHeight, x + scale * 10, y + rectHeight);
		roundedRect->AddArc(x, y + rectHeight - scale * 20, scale * 20.0f, scale * 20.0f, 90.0f, 90.0f);
		roundedRect->AddLine(x, y + rectHeight - scale * 10, x, y + scale * 10);
		roundedRect->CloseFigure();

		// рисование прямоугольника
		g->DrawPath(pen, roundedRect);

		// рисование текста в цетре прямоугольника
		StringFormat^ format = gcnew StringFormat();
		format->Alignment = StringAlignment::Center;
		format->LineAlignment = StringAlignment::Center;
		PointF textPos = PointF(x + rectWidth / 2, y + rectHeight / 2);
		g->DrawString(text, font, brush, textPos, format);
	}
};