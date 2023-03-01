#ifndef CIRCLE_H
#define CIRCLE_H

struct Circle
{
	int X;
	int Y;
	int Radius;
};

extern int size;
extern Circle* arrayCircles;
extern bool isUpdateArray;

void createArray();
void setCircle(Circle& circle, int x, int y, int radius);
void fillArrayRandom();
float getSquare(Circle item);
float getLength(Circle item);
float getMeanSquare();
void moveCirclesToEnd(float minSquare);
void deleteCircles(float maxLength);
void fillArrayIncremental(int x0, int y0, int radius0, int stepX, int stepY, int stepRadius);
void deleteArray();
bool isExistFile(char* fileName);
int countStringInFile(char* fileName);
void loadDataFromFile(char* fileName);
void writeDataToFile(char* fileName);
void addDataToFile(char* fileName);

#endif // CIRCLE_H