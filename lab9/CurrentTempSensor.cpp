#include "CurrentTempSensor.h"

CurrentTempSensor* arraySensors = nullptr;
int SIZE = 0;
char* dataOps[] = { "Отношение измеряемых величин (/)",
"Разность измеряемых величин (-)",
"Увеличить значение сигнала Датчика 1 (+=)",
"Сравнение датчиков по изм.величине (<, >, ==)" };

void CurrentTempSensor::setUnit(char t)
{
	setlocale(LC_ALL, "ru");
	if (t == 'K' || t == 'k')
	{
		if (unit == Temp::C)
		{
			tempMin += CONVERT_TEMP;
			tempMax += CONVERT_TEMP;
		}
		unit = Temp::K;
	}
	else if (t == 'C' || t == 'c')
	{
		if (unit == Temp::K)
		{
			tempMin -= CONVERT_TEMP;
			tempMax -= CONVERT_TEMP;
		}
		unit = Temp::C;
	}
	else throw invalid_argument("Неверно введены еденицы измерения!");
}

void CurrentTempSensor::setTempMin(float temp)
{
	if (unit == Temp::K && temp < 0.0 || temp > tempMax || unit == Temp::C && temp < -CONVERT_TEMP)
		throw invalid_argument("Неверно введена минимальная темепература!");
	tempMin = temp;
}

void CurrentTempSensor::setTempMax(float temp)
{
	if (unit == Temp::K && temp < 0.0 || temp < tempMin || unit == Temp::C && temp < -CONVERT_TEMP)
		throw invalid_argument("Неверно введена максимальная температура!");
	tempMax = temp;
}

void CurrentTempSensor::setInputSignal(float inputSignal)
{
	this->inputSignal = inputSignal;
}

float CurrentTempSensor::getTempCurrent()
{
	if (inputSignal <= MIN_SIGNAL) return tempMin;
	else if (inputSignal >= MAX_SIGNAL) return tempMax;
	else return tempMin + (tempMax - tempMin) * (inputSignal - MIN_SIGNAL) / (RANGE_SIGNAL);
}

String^ CurrentTempSensor::ToString()
{
	return unit == Temp::C ? getTempCurrent().ToString("F3") + " град.С"
		: getTempCurrent().ToString("F2") + " град.К";
}

bool CurrentTempSensor::isOutRange()
{
	return inputSignal < MIN_SIGNAL || inputSignal > MAX_SIGNAL;
}


float CurrentTempSensor::operator/(CurrentTempSensor& sensor)
{
	if (sensor.getUnit() != getUnit()) sensor.setUnit(getUnit());
	return getTempCurrent() / sensor.getTempCurrent();
}

float CurrentTempSensor::operator-(CurrentTempSensor& sensor)
{
	if (sensor.getUnit() != getUnit()) sensor.setUnit(getUnit());
	return getTempCurrent() - sensor.getTempCurrent();
}

void CurrentTempSensor::operator+=(float k)
{
	inputSignal += k;
}

bool CurrentTempSensor::operator<(CurrentTempSensor& sensor)
{
	if (sensor.getUnit() != getUnit()) sensor.setUnit(getUnit());
	return getTempCurrent() < sensor.getTempCurrent();
}

bool CurrentTempSensor::operator>(CurrentTempSensor& sensor)
{
	if (sensor.getUnit() != getUnit()) sensor.setUnit(getUnit());
	return getTempCurrent() > sensor.getTempCurrent();
}

bool CurrentTempSensor::operator==(CurrentTempSensor& sensor)
{
	if (sensor.getUnit() != getUnit()) sensor.setUnit(getUnit());
	return getTempCurrent() == sensor.getTempCurrent();
}



void createArraySensors()
{
	if (arraySensors != nullptr) deletArraySensors();
	arraySensors = new CurrentTempSensor[SIZE];
}

void deletArraySensors()
{
	delete[] arraySensors;
	arraySensors = nullptr;
}

void fillArraySensorsInc(float tempMin, float stepTempMin, float tempMax, float stepTempMax, float inputS, float stepInputS, char unit)
{
	for (int i = 0; i < SIZE; i++)
	{
		arraySensors[i] = CurrentTempSensor(unit, tempMin + i * stepTempMin, tempMax + i * stepTempMax, inputS + i * stepInputS);
	}
}

double calcSin(int index, float A, float T, double x)
{
	const double defaultT = 2 * Math::PI;
	float shift = arraySensors[index].getInputSignal();
	return (double)A * Math::Sin(T / defaultT * x) + shift;
}

double calcSinTemp(int index, float A, float T, double x)
{
	const double defaultT = 2 * Math::PI;
	float shift = arraySensors[index].getTempCurrent();
	return (double)A * Math::Sin(T / defaultT * x) + shift;
}
