/* Лабораторная работа №3, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <exception>

bool isProductDivisioBy7(int num)
{
	int product;
	if (num < 0) num = -num;
	for (product = 1; num > 0; num /= 10) product *= (num % 10);
	return product % 7 == 0;
}


int main()
{
	setlocale(LC_ALL, "ru");
	printf("Лабораторная работа №3, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");

	printf("\nЗадание 1");

	int num;
	char key;

	do
	{
		printf("\n\nВведите целое число: ");
		scanf("%d", &num);
		isProductDivisioBy7(num) ? printf("Произведение цифр числа %d делится на 7\n", num)
			: printf("Произведение цифр числа %d НЕ делится на 7\n", num);
		printf("\nПовторить (y/n)? ");
		key = _getch();
	} while (key == 'y' or key == 'Y');


	return 0;
}
