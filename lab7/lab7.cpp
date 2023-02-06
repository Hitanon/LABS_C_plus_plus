/* Лабораторная работа №7, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define MAIN
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#ifdef MAIN

void showInfo();
void showTask();
int setSize();
void setVariable(int& value, const char* name);
unsigned short* createArray(int size);
void fillArrayIncremental(unsigned short* arr, int size);
void fillArrayRandom(unsigned short* arr, int size);
bool isEvenNumberBitsUnequalTo1(unsigned short var);
double calculateMeanValue(const unsigned short* arr, int size);
void showArray(const unsigned short* arr, int size);
void printDecArray(const unsigned short* arr, int size);
void printDecArray(const unsigned short* arr, int size);
void printBinArray(const unsigned short* arr, int size);
void convertShortToBin(unsigned short value, char string[]);
void printHexArray(const unsigned short* arr, int size);
void showMenu();

void showInfo()
{
	printf("Лабораторная работа №7, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");
	showTask();
}

void showTask()
{
	printf("\nЗадание 1\n");
	printf("В массиве положительных целых двухбайтовых чисел подсчитать среднее\n"
		"арифметическое тех элементов, что содержат четное число битов не равных 1.\n"
		"Вывести массив в десятичном, шестнадцатеричном и двоичном форматах.Программа\n"
		"должна содержать меню и позволять проводить повторные вычисления.Все\n"
		"алгоритмы должны быть реализованы с помощью функций.В программе необходимо\n"
		"задавать размер массива и выделять под него память динамически.Заполнять\n"
		"исходный массив двумя способами : случайными числами и по порядку от x1 с шагом k.\n"
		"Выводить массивы и другую информацию на дисплей.\n");
}

int setSize()
{
	int size;
	printf("\nВведите длину массива: ");
	scanf("%d", &size);
	return size;
}

void setVariable(int& value, const char* name)
{
	printf("\nВведите значеие %s: ", name);
	scanf("%d", &value);
}

unsigned short* createArray(int size)
{
	char choice;
	unsigned short* arr = new unsigned short[size];

	printf("Способ заполнения массива:\n");
	printf("1) От x1 с шагом k;\n");
	printf("2) Случайными числами.\n");
	do
	{
		printf("\nВведите номер пункта: ");
		choice = _getch();
		switch (choice)
		{
		case'1':
			fillArrayIncremental(arr, size);
			break;
		case'2':
			fillArrayRandom(arr, size);
			break;
		default:
			printf("\nНомер пункта введен неверно");
			break;
		}

	} while (choice != '1' && choice != '2');

	return arr;
}


void fillArrayIncremental(unsigned short* arr, int size)
{
	int x1, k;
	setVariable(x1, "x1");
	setVariable(k, "k");
	for (size_t i = 0; i < size; i++) arr[i] = x1 + k * i;
}

void fillArrayRandom(unsigned short* arr, int size)
{
	// Случайный числа от 0 до 99
	for (size_t i = 0; i < size; i++) arr[i] = rand() % 100;
}

bool isEvenNumberBitsUnequalTo1(unsigned short var)
{
	unsigned short mask = 0x8000;
	unsigned short count = 0;
	for (int i = 0; i < 16; i++)
	{
		if ((var & mask) == 0) count++;
		mask >> 1;
	}
	return count % 2 == 0;
}

double calculateMeanValue(const unsigned short* arr, int size)
{
	if (size == 0) return 0;
	double sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (isEvenNumberBitsUnequalTo1(arr[i]))
		{
			sum += arr[i];
			count++;
		}
	}
	return sum / count;
}


void showArray(const unsigned short* arr, int size)
{
	char choice;
	printf("\nФормат вывод массива\n");
	printf("1) Десятичный;\n");
	printf("2) Двоичный;\n");
	printf("3) Шестнадцатеричный;\n");
	printf("4) Вывести во всех форматах.\n");
	do
	{
		printf("Выберите формат: ");
		choice = _getch();
		switch (choice)
		{
		case '1':
			printDecArray(arr, size);
			break;
		case '2':
			printBinArray(arr, size);
			break;
		case '3':
			printHexArray(arr, size);
			break;
		case '4':
			printDecArray(arr, size);
			printBinArray(arr, size);
			printHexArray(arr, size);
			break;
		default:
			printf("\nПункт выбран неверно\n");
			break;
		}
	} while (choice < '1' || choice > '4');
}

void printDecArray(const unsigned short* arr, int size)
{
	printf("\n+-----------------+\n");
	printf("|  i  |   arr(i)  |\n");
	printf("|-----+-----------|\n");
	for (int i = 0; i < size; i++)
		printf("| %3d | %9d |\n", i, arr[i]);
	printf("+-----------------+\n");
}

void printBinArray(const unsigned short* arr, int size)
{
	char string[21];
	printf("\n+----------------------------+\n");
	printf("|  i  |         arr(i)       |\n");
	printf("|-----+----------------------|\n");
	for (int i = 0; i < size; i++)
	{
		convertShortToBin(arr[i], string);
		printf("| %3d | %s |\n", i, string);
	}
	printf("+----------------------------+\n");
}

void convertShortToBin(unsigned short value, char string[])
{
	unsigned short mask = 0x8000;

	for (int i = 0, ind = 0; i < 16; i++)
	{
		if (!(i % 4)) string[ind++] = ' ';
		string[ind++] = value & mask ? '1' : '0';
		mask >>= 1;
	}
	string[20] = 0;
}

void printHexArray(const unsigned short* arr, int size)
{
	printf("\n+------------------+\n");
	printf("|  i  |   arr(i)   |\n");
	printf("|-----+------------|\n");
	for (int i = 0; i < size; i++)
		printf("| %3d | 0x%08x |\n", i, arr[i]);
	printf("+------------------+\n");
}

void showMenu()
{
	printf("\nМеню:\n");
	printf("1) Показать задание;\n");
	printf("2) Перезаполнить массив;\n");
	printf("3) Подсчитать среднее арифметическое тех элементов,\n"
		"   что содержат четное число битов не равных 1;\n");
	printf("4) Показать массив;\n");
	printf("ESC - выйти из программы.\n");
	printf("\nВыберите пункт: ");
}


int main()
{
	char choice;
	int size;
	unsigned short* arr, averageValue;
	setlocale(LC_ALL, "ru");
	srand(time(0));

	showInfo();
	size = setSize();
	arr = createArray(size);
	system("cls");
	do
	{
		showMenu();
		choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			showTask();
			break;
		case '2':
			system("cls");
			delete[] arr;
			size = setSize();
			arr = createArray(size);
			break;
		case '3':
			system("cls");
			printf("Ср. арифм = %.3lf", calculateMeanValue(arr, size));
			break;
		case '4':
			system("cls");
			showArray(arr, size);
			break;
		case 27:
			break;
		default:
			system("cls");
			printf("\nПункт выбран неверно\n");
			break;
		}
	} while (choice != 27);
	delete[] arr;

	return 0;
}
#else

const int CODE_WORD_LENGTH = 8;

void showTask();


void showInfo()
{
	printf("Лабораторная работа №7, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");
	showTask();
}

void showTask()
{
	printf("\nДополнительное задание\n");
	printf("Написать программу, содержащую функции шифрования информации с\n"
		"помощью операции исключающее ИЛИ. Кодовое слово состоит из 8 десятичных цифр.\n"
		"Программа должна содержать меню и позволять: вводить кодовое слово с клавиатуры,\n"
		"задавать имя шифруемого файла и файла, куда должна выводиться зашифрованная\n"
		"информация, сохранять зашифрованные данные в заданный файл, читать\n"
		"зашифрованные данные из файла и выводить в расшифрованном виде на дисплей.\n");
}
void showMenu()
{
	printf("\nМеню:\n");
	printf("1) Показать задание;\n");
	printf("2) Открыть другой файл;\n");
	printf("3) Показать данные;\n");
	printf("4) Зашифровать/расшифорвать данные;\n");
	printf("5) Сохранить данные в файл;\n");
	printf("ESC - выйти из программы.\n");
	printf("\nВыберите пункт: ");
}

int isExistFile(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL) return 0;
	fclose(file);
	return 1;
}

void selectFile(char fileName[])
{
	bool isFailure;
	do
	{
		printf("\nВведите имя файла (подготовлен файл - input.txt): ");
		scanf("%s", fileName);
		if (!isExistFile(fileName))
		{
			isFailure = true;
			printf("Имя файла введно неверно!");
		}
		else isFailure = false;
	} while (isFailure);
}

int countCharactersFromFile(FILE* file)
{
	int count;
	fseek(file, 0L, SEEK_END);
	count = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return count;
}

void readFile(FILE* file, int fileLength, char* string)
{
	int n = fread(string, sizeof(char), fileLength, file);
	string[n] = 0;
}

char* loadData(FILE* file)
{
	int fileLength = countCharactersFromFile(file);
	char* string = new char[fileLength + 1];
	readFile(file, fileLength, string);
	return string;
}

void printData(char* string)
{
	printf("\nДанные из файла:\n");
	if (strlen(string) == 0) printf("Файл пустой");
	else printf("%s", string);
}

bool isNumber(char string[])
{
	for (int i = 0; i < strlen(string); i++)
		if (!isdigit(string[i])) return false;
	return true;
}


void setKeyWord(int keyWord[])
{
	bool isFailure;
	char input[255];
	do
	{
		isFailure = false;
		printf("\nВведите кодовое слово (8 цифр): ");
		scanf("%s", input);
		if (strlen(input) != CODE_WORD_LENGTH)
		{
			printf("\nНеверная длина кодового слова\n");
			isFailure = true;
		}
		else if (!isNumber(input))
		{
			printf("\nКодове слово должно состоять только из цифр\n");
			isFailure = true;
		}
	} while (isFailure);
}

void encryptDecryptData(char* data, int keyWord[])
{
	for (int i = 0; i < strlen(data); i++)
		data[i] ^= keyWord[i % CODE_WORD_LENGTH];
	printf("\nШифрование/дешифрование выполнено успешно\n");
}

void writeDataToFile(char* data)
{
	FILE* file;
	char fileName[256];
	printf("\nВведите имя файла: ");
	scanf("%s", fileName);
	file = fopen(fileName, "w");
	fprintf(file, "%s", data);
	printf("\nДанные записаны в файл %s", fileName);
	fclose(file);
}

int main()
{
	FILE* file;
	char* data;
	char choice;
	char fileName[256];
	int kewWord[CODE_WORD_LENGTH];
	setlocale(LC_ALL, "ru");

	showInfo();
	selectFile(fileName);
	file = fopen(fileName, "r");
	data = loadData(file);
	fclose(file);
	system("cls");
	do
	{
		showMenu();
		choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			showTask();
			break;
		case '2':
			system("cls");
			delete[] data;
			selectFile(fileName);
			file = fopen(fileName, "r");
			data = loadData(file);
			fclose(file);
			break;
		case '3':
			system("cls");
			printData(data);
			break;
		case '4':
			system("cls");
			setKeyWord(kewWord);
			encryptDecryptData(data, kewWord);
			break;
		case '5':
			system("cls");
			writeDataToFile(data);
			break;
		case 27:
			break;
		default:
			system("cls");
			break;
		}
	} while (choice != 27);

	delete[] data;
	return 0;
}
#endif // MAIN