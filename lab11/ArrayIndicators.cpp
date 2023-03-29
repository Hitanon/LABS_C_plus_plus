#include "ArrayIndecators.h"



ArrayIndicators::ArrayIndicators(uint length) : ArrayIndicators()
{
	Clear();
	this->length = length;
	array = new Indicator * [length];
	for (uint i = 0; i < length; i++)
	{
		array[i] = 0;
	}
}

ArrayIndicators::ArrayIndicators(String^ length)
{
	ArrayIndicators(uint::Parse(length));
}

void ArrayIndicators::SetSize(uint length)
{
	Indicator** tempArray = new Indicator * [length];
	uint i = 0;
	for (i; i < min(length, this->length); i++)
	{
		tempArray[i] = array[i]->clone();
	}
	for (i; i < length; i++)
	{
		tempArray[i] = new RoundIndicator();
	}

	Clear();
	this->length = length;
	array = new Indicator * [length];
	for (uint i = 0; i < length; i++)
	{
		array[i] = tempArray[i]->clone();
	}

	for (size_t i = 0; i < length; i++)
		delete tempArray[i];
	delete[] tempArray;
}

void ArrayIndicators::SetSize(String^ length)
{
	SetSize(uint::Parse(length));
}

uint ArrayIndicators::GetSize()
{
	return length;
}

void ArrayIndicators::SetType(uint i, uint type)
{
	if (type >= 3) throw exception("Неверный тип!");
	if (i >= length) throw exception("Выход за границы массива!");
	if (array[i]) delete array[i];
	switch (type)
	{
	case ROUND:
		array[i] = new RoundIndicator;
		break;
	case THERMOMETER:
		array[i] = new Thermometer;
		break;
	case TEXT:
		array[i] = new TextIndicator;
		break;
	}
}

void ArrayIndicators::SetType(String^ i, String^ type)
{
	SetType(uint::Parse(i), uint::Parse(type));
}

uint ArrayIndicators::GetType(uint i) const
{
	if (i >= length) throw exception("Выход за границы массива");
	if (typeid(*array[i]) == typeid(RoundIndicator)) return ROUND;
	if (typeid(*array[i]) == typeid(Thermometer)) return THERMOMETER;
	if (typeid(*array[i]) == typeid(TextIndicator)) return TEXT;
	throw exception("Неизвестный тип");
}

Indicator*& ArrayIndicators::operator[](uint i)
{
	if (i >= length) throw exception("Выход за границы массива!");
	return array[i];
}

Indicator*& ArrayIndicators::operator[](String^ i)
{
	return array[uint::Parse(i)];
}

ArrayIndicators& ArrayIndicators::operator=(const ArrayIndicators& A)
{
	if (this == &A) return *this;

	Clear();
	SetSize(A.length);
	if (!A.array[0]) return *this;
	for (size_t i = 0; i < length; i++)
	{
		SetType(i, A.GetType(i));
		*(array[i]) = *(A.array[i]);
	}
	return *this;
}


void ArrayIndicators::Clear()
{
	if (array)
	{
		for (size_t i = 0; i < length; i++)
			if (array[i]) delete array[i];
		delete[] array;
		array = 0;
		length = 0;
	}
}

ArrayIndicators arrayIndicators;