#ifndef SENSOR
#define SENSOR
#include <stdexcept>
#include <locale.h>

using namespace std;
using namespace System;

enum Temp { C, K };
const float MIN_SIGNAL = 4.0;
const float MAX_SIGNAL = 20.0;
const float RANGE_SIGNAL = 16.0;
const float CONVERT_TEMP = 273.15;
const int COUNT_OPS = 4;



class CurrentTempSensor
{
private:
	Temp unit = Temp::C;
	float tempMin;
	float tempMax;
	float inputSignal;
public:
	CurrentTempSensor(char t = 'C',
		float tempMin = 0.0, float tempMax = 0.0, float inputSignal = 4.0)
	{
		if (t == 'K' || t == 'k')
			unit = Temp::K;
		else if (t == 'C' || t == 'c')
			unit = Temp::C;
		else throw invalid_argument("Неверно введены еденицы измерения!");

		if (unit == Temp::K && (tempMax < 0.0 || tempMin < 0.0))
			throw invalid_argument("Максимальная или минимальная температура не соответсвует единице измерения К!");
		else if (tempMin > tempMax)
			throw invalid_argument("Минимальная температура не может быть больше максимальной!");
		this->tempMin = tempMin;
		this->tempMax = tempMax;
		setInputSignal(inputSignal);
	}

	void setUnit(char t);
	char getUnit() { return unit == Temp::C ? 'C' : 'K'; }

	void setTempMin(float temp);
	float getTempMin() { return round(tempMin * 10000) / 10000; }

	void setTempMax(float temp);
	float getTempMax() { return round(tempMax * 10000) / 10000; }

	void setInputSignal(float inputSignal);
	float getInputSignal() { return round(inputSignal * 10000) / 10000; }

	float getTempCurrent();
	String^ ToString();

	bool isOutRange();

	float operator/ (CurrentTempSensor& sensor);
	float operator- (CurrentTempSensor& sensor);
	void operator+= (float k);
	bool operator< (CurrentTempSensor& sensor);
	bool operator> (CurrentTempSensor& sensor);
	bool operator== (CurrentTempSensor& sensor);;
};

extern CurrentTempSensor* arraySensors;
extern int SIZE;
extern char* dataOps[];
void createArraySensors();
void deletArraySensors();
void fillArraySensorsInc(float tempMin, float stepTempMin, float tempMax, float stepTempMax, float inputS, float stepInputS, char unit);
double calcSin(int index, float A, float T, double x);
double calcSinTemp(int index, float A, float T, double x);
#endif