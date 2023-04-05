#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <type_traits>
#include "TriangularMatrix.h"
#include "Vector.h"

void ShowMainMenu();
void ShowInfo();
void ShowShortMenu();
void ShowVectorMenu();
void ActionsShortMatrix();
void ActionsVectorMatrix();
template <class T>
TriangularMatrix<T> FillMatrix();
void ShowFillMatrixMenu();
template <class T>
TriangularMatrix<T> FillMatrixManual();
template <class T>
TriangularMatrix<T> FillMatrixShortManual(int size);
template <class T>
TriangularMatrix<T> FillMatrixVectorManual(int size);
template <class T>
TriangularMatrix<T> FillMatrixIncremental();
template <class T>
TriangularMatrix<T> FillMatrixShortIncremental(int size, short startValue, short step);
template <class T>
TriangularMatrix<T> FillMatrixVectorIncremental(int size, float startValue, float step, int lengthVector, int stepLength);
template <class T>
TriangularMatrix<T> FillMatrixRandom();
template <class T>
TriangularMatrix<T> FillMatrixShortRandom(int size, short min, short max);
template <class T>
TriangularMatrix<T> FillMatrixVectorRandom(int size, short min, short max, int minLength, int maxLength);
TriangularMatrix<short>& SelectShortMatrix();
TriangularMatrix<Vector>& SelectVectorMatrix();
void ShowShortMatrix(TriangularMatrix<short>& matrix);
void ShowVectorMatrix(TriangularMatrix<Vector>& matrix);
int inputValue(string nameValue);
float inputFloatValue(string nameValue);


TriangularMatrix<short> matrixShort1;
TriangularMatrix<short> matrixShort2;

TriangularMatrix<Vector> matrixVector1;
TriangularMatrix<Vector> matrixVector2;