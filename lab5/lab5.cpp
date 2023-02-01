/* Лабораторная работа №5, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <iostream>


void showInfo();
void showTask();
void showMenu();
void setSize(int& size);
void allocateMemoryForArray(int** dArr, int size);
void fillArray(int** dArr, int size);
void fillArrayIncremental(int** dArr, int size);
void setValue(int* value, const char* str);
void fillArrayRandom(int** dArr, int size);
void showArray(int** dArr, int size);
void reflectArray(int** dArr, int size);
void deleteArray(int** dArr, int size);
template <class T>
void showVarAddress(const T* var, const char* c);
void showArrayAdresses(int** dArr, int size);


void showInfo()
{
	printf("Лабораторная работа №5, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");
	showTask();
}

void showTask()
{
	printf("\nЗадание 1\n");
	printf("Заполнить двумерный массив размером NxN по\n"
		"возрастанию строк и столбцов или случайными числами.\n"
		"Отобразить двумерный массив симметрично относительно\n"
		"побочной диагонали.\n");
}

void showMenu()
{
	printf("\nМеню:\n");
	printf("1) Перезаполнить двумерный массив NxN;\n");
	printf("2) Отобразить массив симметрично относительно побочной диагонал;\n");
	printf("3) Показать адреса переменных;\n");
	printf("4) Показать адреса массивов;\n");
	printf("5) Показать данные двумерного массива.\n");
	printf("-- Для выхода нажмите любую другую клавишу\n");
	printf("\nВведите номер пункта: ");
}

void setSize(int& size)
{
	printf("\nВведите размер N массива: ");
	scanf("%d", &size);
}

void allocateMemoryForArray(int** dArr, int size)
{
	for (int i = 0; i < size; i++)
		dArr[i] = new int[size];
}

void fillArray(int** dArr, int size)
{
	char choice;
	printf("\nВыбор способа заполнения:\n");
	printf("1) Начиная с x0, с шагом k;\n");
	printf("2) Случайными числами;\n");
	do {
		printf("\nВведите номер пункта: ");
		choice = _getch();
		switch (choice)
		{
		case '1':
			fillArrayIncremental(dArr, size);
			break;
		case '2':
			fillArrayRandom(dArr, size);
			break;
		default:
			printf("Номер пункта введен неверно!\n");
		}
	} while (choice != '1' && choice != '2');
}

void fillArrayIncremental(int** dArr, int size)
{
	int x0, k;
	setValue(&x0, "x0");
	setValue(&k, "k");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			dArr[i][j] = x0 + (i * size + j) * k;
}

void setValue(int* value, const char* str)
{
	printf("\nВведите значение %s: ", str);
	scanf("%d", value);
}

void fillArrayRandom(int** dArr, int size)
{
	srand(time(0));
	// случайные числа от -50 до 49
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			dArr[i][j] = rand() % 100 - 50;
}

void reflectArray(int** dArr, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			temp = dArr[i][j];
			dArr[i][j] = dArr[size - i - 1][size - j - 1];
			dArr[size - i - 1][size - j - 1] = temp;
		}
	}
	printf("\nОтражение массива выполнено.\n");
}

void showArray(int** dArr, int size)
{
	printf("\n\nДанные из массива:");
	printf("\n|");
	for (int j = 0; j < size; j++) printf("-----|");
	for (int i = 0; i < size; i++)
	{
		printf("\n|");
		for (int j = 0; j < size; j++) printf(" %3d |", dArr[i][j]);
		printf("\n|");
		for (int j = 0; j < size; j++) printf("-----|");
	}
	printf("\n");
}

template <class T>
void showVarAddress(const T* var, const char* c)
{
	printf("%s = %p\n", c, var);
}

void showArrayAdresses(int** dArr, int size)
{	
	printf("\n\nАдреса массивов\n");
	printf("dArr = %p\n", dArr);
	for (int i = 0; i < size; i++)
	{
		printf("dArr[%d] = %p; адрес dArr[%d] = %p\n",
			i, dArr[i], i, &dArr[i]);
	}
}

void deleteArray(int** dArr, int size)
{
	for (int i = 0; i < size; i++) delete[] dArr[i];
	delete[] dArr;
}


int main()
{
	int size;
	int** dArr;
	char action;
	bool isAction = true;

	setlocale(LC_ALL, "ru");

	showInfo();

	setSize(size);
	dArr = new int* [size];
	allocateMemoryForArray(dArr, size);
	fillArray(dArr, size);

	do
	{
		showMenu();
		action = _getch();
		switch (action)
		{
		case '1':
			deleteArray(dArr, size);
			setSize(size);
			dArr = new int* [size];
			allocateMemoryForArray(dArr, size);
			fillArray(dArr, size);
			break;
		case '2':
			reflectArray(dArr, size);
			break;
		case '3':
			printf("\n\nАдреса переменных:\n");
			showVarAddress(&size, "size");
			showVarAddress(&action, "action");
			showVarAddress(&isAction, "action");
			break;
		case '4':
			showArrayAdresses(dArr, size);
			break;
		case '5':
			showArray(dArr, size);
			break;
		default:
			isAction = false;
		}
	} while (isAction);

	deleteArray(dArr, size);
	return 0;
}