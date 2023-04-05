#pragma once
#include <string>
#include <sstream>

using namespace std;
typedef unsigned int uint;

class Vector
{
	uint size;
	float* data;
public:
	Vector();
	Vector(uint size);
	Vector(const Vector& other);
	Vector(string value);
	~Vector();

	void ReadFromString(const string& str);
	float& operator[] (uint i);
	Vector& operator= (const Vector& other);
	Vector& operator= (string& value);
	uint Size();
	float Length() const;
	bool operator> (const Vector& other);
	bool operator< (const Vector& other);
	bool operator== (const Vector& other);
	string toString() const;
};

