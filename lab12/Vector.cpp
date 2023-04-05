#include "Vector.h"

Vector::Vector()
{
	size = 0;
	data = nullptr;
}

Vector::Vector(uint size)
{
	this->size = size;
	data = new float[size]();
}

Vector::Vector(const Vector& other)
{
	if (data) delete[] data;
	size = other.size;
	data = new float[size];
	for (uint i = 0; i < size; i++) data[i] = other.data[i];
}

Vector::Vector(string value)
{
	(*this).ReadFromString(value);
}

Vector::~Vector()
{
	if (data)
	{
		size = 0;
		delete[] data;
	}
}

void Vector::ReadFromString(const string& str)
{
	uint count = 1;
	for (char c : str) if (c == ';') count++;

	float* tempArray = new float[count];

	stringstream ss(str);
	string token;
	uint i = 0;
	while (getline(ss, token, ';') && i < count)
	{
		try
		{
			tempArray[i++] = stof(token);
		}
		catch (const exception& e)
		{
			delete[] tempArray;
			throw invalid_argument("В строке встречен элемент, который не является вещественным числом! Считывание отменено");
		}
	}
	if (i != count)
	{
		delete[] tempArray;
		throw invalid_argument("Количество разделителей ; в строке не совпадает с количеством элементов! Считывание отменено");
	}

	size = count;
	if (data) delete[] data;
	data = new float[size];
	for (uint i = 0; i < size; i++) data[i] = tempArray[i];
	delete[] tempArray;
}

float& Vector::operator[](uint i)
{
	if (i >= size) throw out_of_range("Индекс больше размера вектора!");
	return data[i];
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		data = new float[size];
		for (uint i = 0; i < size; i++) data[i] = other.data[i];
	}
	return *this;
}

Vector& Vector::operator=(string& value)
{
	(*this).ReadFromString(value);
	return (*this);
}

uint Vector::Size()
{
	return size;
}

float Vector::Length() const
{
	float sum = 0.0f;
	for (uint i = 0; i < size; i++) sum += data[i] * data[i];
	return sqrt(sum);
}

bool Vector::operator>(const Vector& other)
{
	return Length() > other.Length();
}

bool Vector::operator<(const Vector& other)
{
	return Length() < other.Length();
}

bool Vector::operator==(const Vector& other)
{
	return Length() == other.Length();
}

string Vector::toString() const
{
	stringstream ss;
	ss << "(";
	for (uint i = 0; i < size; i++)
	{
		ss << round(data[i]*1000)/1000;
		if (i < size - 1) ss << "; ";
	}
	ss << ")";
	return ss.str();
}
