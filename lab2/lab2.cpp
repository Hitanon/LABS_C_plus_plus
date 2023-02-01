/* Лабораторная работа №2, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

int main()
{
	// Задание №1
	int n, k1, k2;
	int count;
	double eps, sumEps, sumCount, term;

	setlocale(LC_ALL, "ru");
	printf("Задание 1\n");

	// Ввод точности
	do
	{
		printf("\nВведите предел точности: ");
		scanf("%lf", &eps);
		if (eps <= 0)
		{
			printf("Точность должна быть > 0\n");
			while (getchar() != '\n');
		}
	} while (eps <= 0);

	// Ввод количества членов ряда
	do
	{
		printf("Ведите количество членов ряда: ");
		while (getchar() != '\n');
		scanf("%d", &count);
		if (count < 0)
		{
			printf("Количество членов должно быть целым числом >= 0\n");
			while (getchar() != '\n');
		}
	} while (count < 0);

	printf("\nРяд a(n) = (-1)^n * (n^2 + 1) / (n^2 + 2^n)\n");
	printf("------------------------------\n");
	printf("|  n  |   a(n)   |   Сумма   |\n");
	printf("|-----|----------|-----------|\n");


	for (n = 0, sumEps = sumCount = 0, k1 = 1, k2 = 1; ; n++, k2 *= 2, k1 = -k1)
	{
		term = (double)k1 * (n * n + 1) / (n * n + k2);
		if (fabs(term) < eps && (n >= count)) break;
		sumEps += term;
		if (n + 1 == count) sumCount = sumEps;
		printf("| %3d | %8.5lf | %9.5lf |\n", n, term, sumEps);
	}

	printf("------------------------------\n");
	printf("Сумма членов ряда с точностью = %.4lf: %.5lf\n", eps, sumEps);
	printf("Сумма первых %d членов ряда: %.5lf\n", count, sumCount);
	printf("Press any key to continue...\n");
	_getch();

	// Задание №2
	n = 0;
	float x, y;
	float xForTable;
	short offset;


	printf("\nЗадание 2\n");
	printf("-------------------------\n");
	printf("|     x     |     y     |\n");
	printf("|-----------|-----------|\n");

	for (n = 0; n < 5; n++)
	{
		for (x = 0; x < 4; x += 0.25)
		{
			(x < 2) ? y = -x + 2 : y = 2 - sqrt(4 - (x - 2) * (x - 2));
			xForTable = x + 4 * n;
			printf("| %9.2f | %9.7f |", xForTable, y);
			offset = (y + 1) * 10 + 0.5;
			for (; offset > 0; offset--) printf(" ");
			printf("*\n");
		}
		printf("Press any key to continue drawing...\r");
		_getch();
	}
	printf("-------------------------               \n");

	return 0;
}