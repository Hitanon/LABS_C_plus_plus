/* Лабораторная работа №8, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */


#include <time.h>
#include <cstdlib>
#include "Program.h"
#include <cmath>
#include <stdio.h>
#include <string>


int size;
const float pi = 3.1415;
bool isUpdateArray = false;
Circle* arrayCircles = nullptr;

void createArray()
{
	arrayCircles = new Circle[size];
}

void setCircle(Circle& circle, int x, int y, int radius)
{
	circle.X = x;
	circle.Y = y;
	circle.Radius = radius;
}

void fillArrayRandom()
{
	srand(time(0));
	for (size_t i = 0; i < size; i++)
	{
		setCircle(arrayCircles[i], rand() % 100 - 50, rand() % 100 - 50, rand() % 50 + 1);
	}
}


void fillArrayIncremental(int x0, int y0, int radius0, int stepX, int stepY, int stepRadius)
{
	for (int i = 0; i < size; i++)
	{
		setCircle(arrayCircles[i], x0 + i * stepX, y0 + i * stepY, radius0 + i * stepRadius);
	}
}

float getSquare(Circle item)
{
	return pi * item.Radius * item.Radius;
}

float getLength(Circle item)
{
	return 2 * pi * item.Radius;
}

bool isIntersection(Circle item1, Circle item2)
{
	int distance = sqrt((item1.X - item2.X) * (item1.X - item2.X) + (item1.Y - item2.Y) * (item1.Y - item2.Y));
	return distance < item1.Radius + item2.Radius;
}

float getMeanSquare()
{
	float totalSquare = 0.0;
	int count = 0;
	bool hasIntersection;

	for (int i = 0; i < size - 1; i++)
	{
		hasIntersection = false;
		for (int j = i + 1; j < size; j++)
			if (isIntersection(arrayCircles[i], arrayCircles[j]))
			{
				hasIntersection = true;
				break;
			}
		if (hasIntersection)
		{
			totalSquare += getSquare(arrayCircles[i]);
			count++;
		}
	}

	return count != 0 ? totalSquare / count : 0;
}


void moveCirclesToEnd(float minSquare)
{
	int i = 0, j = size - 1;

	while (i <= j)
	{
		while (i <= j && getSquare(arrayCircles[i]) >= minSquare) i++;
		while (j >= i && getSquare(arrayCircles[j]) < minSquare) j--;
		if (i < j)
		{
			Circle temp = arrayCircles[i];
			arrayCircles[i++] = arrayCircles[j];
			arrayCircles[j--] = temp;
		}
	}
}

int countCircles(float maxLength)
{
	int count = 0;

	for (int i = 0; i < size; i++)
		if (getLength(arrayCircles[i]) <= maxLength) count++;

	return count;
}

void deleteCircles(float maxLength)
{
	int count = countCircles(maxLength);
	Circle* temp = new Circle[count];
	for (int i = 0, j = 0; i < size && j < count; i++)
		if (getLength(arrayCircles[i]) <= maxLength) temp[j++] = arrayCircles[i];
	size = count;
	arrayCircles = temp;
}

bool isExistFile(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL) return false;
	fclose(file);
	return true;
}

int countStringInFile(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	const int len = 256;
	int cnt = 0;
	char str[len];
	while (fgets(str, len, file) != NULL) cnt++;
	fclose(file);
	return cnt;
}

void parseStr(char* str, int result[3])
{
	char* pch;
	pch = strtok(str, " ");
	for (int i = 0; i < 3 && pch != nullptr; i++) {
		result[i] = atoi(pch);
		pch = strtok(nullptr, " ");
	}
}

void loadDataFromFile(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	const int len = 256;
	int parts[3];
	char str[len];
	int i = 0;
	createArray();
	while (fgets(str, len, file) != NULL)
	{
		parseStr(str, parts);
		setCircle(arrayCircles[i++], parts[0], parts[1], parts[2]);
	}
}

void writeDataToFile(char* fileName)
{
	FILE* file = fopen(fileName, "w");
	if (file != NULL)
	{
		for (int i = 0; i < size; i++)
			fprintf(file, "%d %d %d\n", arrayCircles[i].X, arrayCircles[i].Y, arrayCircles[i].Radius);
		fclose(file);
	}
}

void addDataToFile(char* fileName)
{
	FILE* file = fopen(fileName, "a");
	if (file != NULL)
	{
		for (int i = 0; i < size; i++)
			fprintf(file, "%d %d %d\n", arrayCircles[i].X, arrayCircles[i].Y, arrayCircles[i].Radius);
		fclose(file);
	}
}

void deleteArray()
{
	delete[] arrayCircles;
	arrayCircles = nullptr;
}