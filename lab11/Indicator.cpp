#include "Indicator.h"

Indicator::Indicator()
{
	scale = 1;
	x = 0.0f;
	y = 0.0f;
	label = "T";

	minTemp = 0.0f;
	maxTemp = 0.0f;
	temp = 0.0f;
}

Indicator::Indicator(float temp, float minTemp, float maxTemp, float x, float y, byte scale, string label)
{
	SetTemp(temp);
	if (minTemp > maxTemp)
		throw exception("Минимальная температура не может быть больше максимальной!");
	this->minTemp = minTemp;
	this->maxTemp = maxTemp;
	SetXY(x, y);
	SetScale(scale);
	SetLabel(label);
}

Indicator::Indicator(String^ temp, String^ minTemp, String^ maxTemp, String^ x, String^ y, String^ scale, String^ label)
{
	SetTemp(temp);
	float minTempF = float::Parse(minTemp);
	float maxTempF = float::Parse(maxTemp);
	if (minTempF > maxTempF)
		throw exception("Минимальная температура не может быть больше максимальной!");
	this->minTemp = minTempF;
	this->maxTemp = maxTempF;
	SetXY(x, y);
	SetScale(scale);
	SetLabel(marshal_as<string>(label));
}

void Indicator::SetScale(String^ scale)
{
	int value = byte::Parse(scale);
	SetScale(value);
}

void Indicator::SetScale(uint scale)
{
	if (scale >= 0 && scale <= 255)
		this->scale = scale;
	else
		throw exception("Размер должен быть целм числом от 0 до 255!");
}

byte Indicator::GetScale()
{
	return scale;
}

void Indicator::SetX(String^ x)
{
	float value = float::Parse(x);
	SetX(value);
}

void Indicator::SetX(float x)
{
	if (x >= 0)
		this->x = x;
	else
		throw exception("Координата x должна быть >= 0!");
}

float Indicator::GetX()
{
	return x;
}

void Indicator::SetY(String^ y)
{
	float value = float::Parse(y);
	SetY(value);
}

void Indicator::SetY(float y)
{
	if (y >= 0)
		this->y = y;
	else
		throw exception("Координата y должна быть >= 0!");
}

float Indicator::GetY()
{
	return y;
}

void Indicator::SetXY(String^ x, String^ y)
{
	SetX(x);
	SetY(y);
}

void Indicator::SetXY(float x, float y)
{
	SetX(x);
	SetY(y);
}

void Indicator::SetLabel(string label)
{
	this->label = label;
}

string Indicator::GetLabel()
{
	return label;
}

void Indicator::SetMinTemp(String^ temp)
{
	float value = float::Parse(temp);
	SetMinTemp(temp);
}

void Indicator::SetMinTemp(float temp)
{
	if (temp > maxTemp)
		throw exception("Минимальная температура не может быть больше максимальной!");
	minTemp = temp;
	SetColor();
}

float Indicator::GetMinTemp()
{
	return minTemp;
}

void Indicator::SetMaxTemp(String^ temp)
{
	float value = float::Parse(temp);
	SetMaxTemp(value);
}

void Indicator::SetMaxTemp(float temp)
{
	if (temp < minTemp)
		throw exception("Максимальная температура не может быть больше минимальной!");
	maxTemp = temp;
	SetColor();
}

float Indicator::GetMaxTemp()
{
	return maxTemp;
}

void Indicator::SetTemp(String^ temp)
{
	this->temp = float::Parse(temp);
}

void Indicator::SetTemp(float temp)
{
	this->temp = temp;
}

float Indicator::GetTemp()
{
	return temp;
}

bool Indicator::IsOutRange()
{
	return temp < minTemp || temp > maxTemp;
}


bool Indicator::operator>(Indicator*& indicator)
{
	return temp > indicator->GetTemp();
}

bool Indicator::operator<(Indicator*& indicator)
{
	return temp < indicator->GetTemp();
}

bool Indicator::operator==(Indicator*& indicator)
{
	return temp== indicator->GetTemp();
}

void Indicator::operator=(String^ temp)
{
	SetTemp(temp);
}

void Indicator::operator=(float temp)
{
	SetTemp(temp);
}
