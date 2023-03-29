#pragma once
#include "Indicator.h"
#include "RoundIndicator.h"
#include "Thermometer.h"
#include "TextIndicator.h"
#include <typeinfo>



class ArrayIndicators
{
	Indicator** array;
	uint length;

public:
	
	ArrayIndicators() { array = 0; length = 0; }
	ArrayIndicators(uint length);
	ArrayIndicators(String^ length);
	~ArrayIndicators() { Clear(); }

	void SetSize(uint length);
	void SetSize(String^ length);
	uint GetSize();

	void SetType(uint i, uint type);
	void SetType(String^ i, String^ type);
	uint GetType(uint i) const;

	Indicator*& operator[] (uint i);
	Indicator*& operator[] (String^ i);

	ArrayIndicators& operator= (const ArrayIndicators& A);

	void Clear();
};

extern ArrayIndicators arrayIndicators;