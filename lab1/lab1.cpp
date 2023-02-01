/* Лабораторная работа №1, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{
	const int LENGTH = 3;
	const int K = 1 + 5 % 5;
	setlocale(LC_ALL, "ru");


	// Задание 1
	printf("Задание №1\n");
	int x[LENGTH]{}, y[LENGTH]{}, z[LENGTH]{};
	int result1;
	bool result2;

	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d. Введите целые числа x, y, z:\n", i + 1);
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
	}

	printf("-----------------------------------------------------------------\n");
	printf("|  N  |   x   |   y   |   z   | x %%= y + z | x = x %% y || x %% z |\n");
	printf("|-----|-------|-------|-------|------------|--------------------|\n");
	for (int i = 0; i < LENGTH; i++)
	{
		result1 = x[i] % (y[i] + z[i]);
		result2 = x[i] % y[i] || x[i] % z[i];
		printf("|  %d  | %5d | %5d | %5d | %10d | %18d |\n",
			i + 1, x[i], y[i], z[i], result1, result2);
	}
	printf("-----------------------------------------------------------------\n");


	// Задание 2
	printf("\nЗадание №2\n");
	float fx[LENGTH]{}, fy[LENGTH]{}, fz[LENGTH]{};
	int result;

	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d. Введите вещественные числа fx, fy, fz:\n", i + 1);
		scanf("%f %f %f", &fx[i], &fy[i], &fz[i]);
	}
	printf("--------------------------------------------\n");
	printf("|  N  |   x   |   y   |   z   | x %%= y + z |\n");
	printf("|-----|-------|-------|-------|------------|\n");
	for (int i = 0; i < LENGTH; i++)
	{
		result = int(fx[i]) % int(fy[i] + fz[i]);
		printf("|  %d  | %5.*f | %5.*f | %5.*f | %10d |\n",
			i + 1, K, fx[i], K, fy[i], K, fz[i], result);
	}
	printf("--------------------------------------------\n");

	_getch();
	return 0;
}