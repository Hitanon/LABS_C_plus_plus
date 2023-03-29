#pragma once
#include<string>
#include <msclr/marshal_cppstd.h>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace System;
using namespace System::Drawing;

using namespace msclr::interop;
typedef unsigned char byte;
typedef unsigned int uint;

enum {ROUND, THERMOMETER, TEXT};

class Indicator
{
protected:

	byte scale;
	float x, y;
	unsigned int color = 0xFFFF0000;
	string label;

	float minTemp, maxTemp, temp;

public:

	Indicator();
	
	Indicator(float temp,
		float minTemp,
		float maxTemp,
		float x,
		float y,
		byte scale,
		string label);

	Indicator(String^ temp,
		String^ minTemp,
		String^ maxTemp,
		String^ x,
		String^ y,
		String^ scale,
		String^ label);

	void SetScale(String^ scale);
	void SetScale(uint scale);
	byte GetScale();

	void SetX(String^ x);
	void SetX(float x);
	float GetX();

	void SetY(String^ y);
	void SetY(float y);
	float GetY();

	void SetXY(String^ x, String^ y);
	void SetXY(float x, float y);

	void SetLabel(string label);
	string GetLabel();

	void SetMinTemp(String^ temp);
	void SetMinTemp(float temp);
	float GetMinTemp();

	void SetMaxTemp(String^ temp);
	void SetMaxTemp(float temp);
	float GetMaxTemp();

	void SetTemp(String^ temp);
	void SetTemp(float temp);
	float GetTemp();

	bool IsOutRange();

	bool operator>(Indicator*& indicator);
	bool operator<(Indicator*& indicator);
	bool operator==(Indicator*& indicator);
	void operator=(String^ temp);
	void operator=(float temp);

	virtual void SetColor() {};
	virtual void SetColor(uint value) {};
	virtual void DrawIndicator(Windows::Forms::GroupBox^ groupBox) = 0;
	virtual ~Indicator() {}
	virtual Indicator* clone() const = 0;
};