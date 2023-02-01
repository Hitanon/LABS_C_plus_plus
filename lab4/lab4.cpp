/* Лабораторная работа №3, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <cstdlib>
#include <time.h>


enum arrs { A = 'A', B = 'B', C = 'C' };

void showMenu();
void fillArrays(int* A, int* B, int* C, unsigned int* size);
int calculateMean(int a, int b);
void fillArrayMean(int* A, int* B, int* C, int size);
void setValue(int* value, const char* str);
void fillArrayRandom(int* arr, unsigned int size);
void fillArrayIncremental(int* arr, unsigned int size, int x1, int k);
void setSize(unsigned int& size);
void showArray(int* arr, arrs arrName, unsigned int size);
arrs selectArray();
void deleteArrays(int* A, int* B, int* C);
void copyArray(int* A, int* B, int size);
int searchMaxValueInArray(int* arr, int size);
int searchMinValueInArray(int* arr, int size);
int searchMaxValueInAllArrays(int* A, int* B, int* C, int size);
int searchMinValueInAllArrays(int* A, int* B, int* C, int size);
void showVarAddress(const int* var, char c);
void showArrayAddress(const int* arr, char c);


void showMenu()
{
	printf("\nМеню:\n");
	printf("1) Пересоздать массивы A, B, C;\n");
	printf("2) Скопировать массив A в массив B;\n");
	printf("3) Найти max и min элементы с нечетными индексами в массиве;\n");
	printf("4) Найти max и min элементы с нечетными индексами среди всех массивов;\n");
	printf("5) Вывести адрес переменной масива;\n");
	printf("6) Вывести адрес массива;\n");
	printf("7) Вывести все элементы массива.\n");
	printf("--Для выхода нажмите любую другую клавишу\n");
	printf("\nВведите номер пункта: ");
}


void fillArrays(int* A, int* B, int* C, unsigned int* size)
{
	int x1, k;
	setValue(&x1, "x1");
	setValue(&k, "k");
	fillArrayRandom(A, *size);
	fillArrayIncremental(B, *size, x1, k);
	fillArrayMean(A, B, C, *size);
}


int calculateMean(int a, int b)
{
	return (a + b) / 2;
}


void fillArrayMean(int* A, int* B, int* C, int size)
{
	for (unsigned int i = 0; i < size; i++)
		C[i] = calculateMean(A[i], B[i]);
}


void setValue(int* value, const char* str)
{
	printf("Введите значение %s: ", str);
	scanf("%d", value);
}


void fillArrayRandom(int* arr, unsigned int size)
{
	srand(time(0));
	// случайные числа от -50 до 49
	for (unsigned int i = 0; i < size; i++) arr[i] = rand() % 100 - 50;
}


void fillArrayIncremental(int* arr, unsigned int size, int x1, int k)
{
	for (unsigned int i = 0; i < size; i++) arr[i] = x1 + i * k;
}


void copyArray(int* A, int* B, int size)
{
	int poz = 0;
	for (unsigned int i = 0; i < size; i++)
		if (A[i] > 0) B[poz++] = A[i];
	for (unsigned int i = 0; i < size; i++)
		if (A[i] == 0) B[poz++] = A[i];
	for (unsigned int i = 0; i < size; i++)
		if (A[i] < 0) B[poz++] = A[i];
}


int searchMaxValueInArray(int* arr, int size)
{
	int maxValue = arr[1];
	for (unsigned int i = 3; i < size; i+=2)
		if (arr[i] > maxValue) maxValue = arr[i];
	return maxValue;
}


int searchMinValueInArray(int* arr, int size)
{
	int minValue = arr[1];
	for (unsigned int i = 3; i < size; i += 2)
		if (arr[i] < minValue) minValue = arr[i];
	return minValue;
}


int searchMaxValueInAllArrays(int* A, int* B, int* C, int size)
{
	int maxA = searchMaxValueInArray(A, size);
	int maxB = searchMaxValueInArray(B, size);
	int maxC = searchMaxValueInArray(C, size);
	if (maxA < maxB) maxA = maxB;
	if (maxA < maxC) maxA = maxC;
	return maxA;
}


int searchMinValueInAllArrays(int* A, int* B, int* C, int size)
{
	int minA = searchMinValueInArray(A, size);
	int minB = searchMinValueInArray(B, size);
	int minC = searchMinValueInArray(C, size);
	if (minA > minB) minA = minB;
	if (minA > minC) minA = minC;
	return minA;
}

void setSize(unsigned int& size)
{
	printf("\nВведите размерность массивов: ");
	scanf("%d", &size);
}


void showArray(int* arr, arrs arrName, unsigned int size)
{
	printf("\n-------------------\n");
	printf("|  i  |    %c(i)   |\n", arrName);
	printf("|-----|-----------|\n");
	for (unsigned int i = 0; i < size; i++)
	{
		printf("| %3d | %9d |\n", i, arr[i]);
	}
	printf("-------------------\n");
}

void showVarAddress(const int* var, char c)
{
	printf("\nАдрес %c: %p\n", c, &var);
}

void showArrayAddress(const int* arr, char c)
{
	printf("\nАдрес %c[0]: %p\n", c, arr);
}

arrs selectArray()
{
	do
	{
		printf("\nВыберите массив (A, B, C): ");
		char choice = _getch();
		if (choice == 'a' or choice == 'A') return A;
		else if (choice == 'b' or choice == 'B') return B;
		else if (choice == 'c' or choice == 'C') return C;
		printf("Массив выбран неверно\n");
	} while (true);
}

void deleteArrays(int* A, int* B, int* C)
{
	delete[] A;
	delete[] B;
	delete[] C;
}

int main()
{
	setlocale(LC_ALL, "ru");

	printf("Лабораторная работа №3, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");
	printf("\nЗадание 1\n");

	char action;
	unsigned int size;
	int* A, * B, * C;
	bool isAction = true;
	arrs choice;

	setSize(size);
	A = new int[size];
	B = new int[size];
	C = new int[size];
	fillArrays(A, B, C, &size);

	do
	{
		showMenu();
		action = _getch();
		switch (action)
		{
		case '1':
			deleteArrays(A, B, C);
			setSize(size);
			A = new int[size];
			B = new int[size];
			C = new int[size];
			fillArrays(A, B, C, &size);
			break;
		case '2':
			copyArray(A, B, size);
			break;
		case '3':
			choice = selectArray();
			if (choice == arrs::A) printf("\nМассив A (нечетные индексы):\n max = %d; min = %d\n",
				searchMaxValueInArray(A, size), searchMinValueInArray(A, size));
			else if (choice == arrs::B) printf("\nМассив B (нечетные индексы):\n max = %d; min = %d\n",
				searchMaxValueInArray(B, size), searchMinValueInArray(B, size));
			else printf("\nМассив C (нечетные индексы):\n max = %d; min = %d\n",
				searchMaxValueInArray(C, size), searchMinValueInArray(C, size));
			break;
		case '4':
			printf("\nСреди всех массивов (нечетные индексы):\n max = %d; min = %d\n",
				searchMaxValueInAllArrays(A, B, C, size), searchMinValueInAllArrays(A, B, C, size));
			break;
		case '5':
			choice = selectArray();
			if (choice == arrs::A) showVarAddress(A, arrs::A);
			else if (choice == arrs::B) showVarAddress(B, arrs::B);
			else showVarAddress(C, arrs::C);
			break;
		case '6':
			choice = selectArray();
			if (choice == arrs::A) showArrayAddress(A, arrs::A);
			else if (choice == arrs::B) showArrayAddress(B, arrs::B);
			else showArrayAddress(C, arrs::C);
			break;
		case '7':
			choice = selectArray();
			if (choice == arrs::A) showArray(A, choice, size);
			else if (choice == arrs::B) showArray(B, choice, size);
			else showArray(C, choice, size);
			break;
		default:
			isAction = false;
		}

	} while (isAction);

	deleteArrays(A, B, C);

	return 0;
}
