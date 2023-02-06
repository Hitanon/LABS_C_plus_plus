/* Лабораторная работа №6, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


enum ResourseType { constString, fileString, inputString };
void showInfo();
void showTask();
void showMenu();
ResourseType selectResource();
int openFile(char* fileName, FILE* file);
void readFile(FILE* file, int fileLength, char* string);
void selectFile(char* fileName, FILE* file);
int countCharactersFromFile(FILE* file);
int isInString(const char* source, char c);
int countVowelWords(const char* string);
void extractVowelWords(char* inputString, char** words);
void showWords(char** words, int size);
void writeWordsInFile(char** words, int size);
void deleteAllPointers(char* string, char** words, int size);


const char separators[] = ",. !?:;:'\n\0\"\\";
const char vowels[] = "aAeEyYuUiIoOаАоОуУыЫиИеЕёЁюЮэЭяЯ";
const char letters[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюяABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


void showInfo()
{
	printf("Лабораторная работа №6, вариант 5\n");
	printf("Малышев Максим, 2 курс, гр. ПМИ-1\n");
	showTask();
}

void showTask()
{
	printf("\nЗадание 1\n");
	printf("Выделить из текста слова, которые начинаются с гласной буквы, и записать\n"
		"их в отдельный массив слов. Вывести на дисплей слова из массива и количество\n"
		"символов в каждом из них.\n");
}

ResourseType selectResource()
{
	char choice;
	printf("\nВыбор источника текста для анализа:\n");
	printf("1) Строка константа в тексте программы;\n");
	printf("2) Текстовый файл;\n");
	printf("3) Ввести текст с клавиатуры.\n");
	do {
		printf("\nВведите номер пункта: ");
		choice = _getch();
		switch (choice)
		{
		case '1': return constString;
		case '2': return fileString;
		case '3': return inputString;
		default: printf("Номер пункта введен неверно!\n");
		}
	} while (choice < '1' || choice > '3');
}


int openFile(char* fileName, FILE* file)
{
	file = fopen(fileName, "r");
	if (file == NULL) return 0;
	fclose(file);
	return 1;
}

void readFile(FILE* file, int fileLength, char* string)
{
	int n = fread(string, sizeof(char), fileLength, file);
	string[n] = 0;
}


void selectFile(char* fileName, FILE* file)
{
	bool isFailure;
	do
	{
		printf("\nВведите имя файла (подготовлен файл - input.txt): ");
		scanf("%s", fileName);
		if (!openFile(fileName, file))
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

int isInString(const char* source, char c)
{
	while (*source)
		if (c == *source++) return 1;
	return 0;
}


int countVowelWords(const char* string)
{
	int len, count = 0;
	len = strlen(string);
	int i = 0;
	while (i < len)
	{
		while (!isInString(letters, string[i]) && i < len) i++;
		if (isInString(vowels, string[i])) count++;
		while (isInString(letters, string[i]) && i < len) i++;
	}
	return count;
}

void extractVowelWords(char* inputString, char** words)
{
	char word[81];
	int flag = -1, i = 0, k = 0;
	int len = strlen(inputString);
	while (i < len)
	{
		while (!isInString(letters, inputString[i]) && i < len)
			i++;
		while (isInString(letters, inputString[i]) && i < len)
			word[++flag] = inputString[i++];
		if (flag != -1)
		{
			word[++flag] = '\0';
			if (isInString(vowels, word[0]))
			{
				words[k] = new char[flag + 1];
				strcpy(words[k++], word);
			}
			flag = -1;
		}
	
	}
}


void showWords(char** words, int size)
{
	printf("\n\nВсе слова, начинающиеся с гласных букв");
	for (int i = 0; i < size; i++)
	{
		printf("\n%d) Слово: %s\n", i + 1, words[i]);
		printf("   Количество cимволов: %d", int(strlen(words[i])));
	}
}

void writeWordsInFile(char** words, int size)
{
	FILE* file;
	char fileName[81];
	printf("\nВведите имя файла: ");
	scanf("%s", fileName);
	file = fopen(fileName, "w");
	fprintf(file, "Все слова, начинающиеся с гласных букв");
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "\n%d) Слово: %s\n", i + 1, words[i]);
		fprintf(file, "   Количество cимволов: %d", int(strlen(words[i])));
	}
	printf("\nДанные записаны в файл %s", fileName);
	fclose(file);
}


void showMenu()
{
	printf("\n\nМеню:\n");
	printf("1) Изменить источник текста для анализа;\n");
	printf("2) Показать данные из источника текста;\n");
	printf("3) Показать слова из текста, которые начинаются с гласной буквы\n"
		"   и количество символов в каждом из них;\n");
	printf("4) Записать результат в текстовый файл.\n");
	printf("-- Для выхода нажмите любую другую клавишу\n");
	printf("\nВведите номер пункта: ");
}

void deleteAllPointers(char* string, char** words, int size)
{
	delete[] string;
	for (int i = 0; i < size; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

int main()
{
	int size = 0, fileLength;
	char* mainString = nullptr;
	char fileName[81];
	FILE* file = nullptr;
	char** words = nullptr;
	ResourseType choice;
	char action;
	bool isAction = true;

	const char* resource = "An elephant never forgets and a bird always sings.\n"
		"The quick brown fox jumps over the lazy dog.\n"
		"A rainbow is formed after rain in the sky.";

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	showInfo();
	switch (selectResource())
	{
	case constString:
		mainString = new char[strlen(resource) + 1];
		strcpy(mainString, resource);
		size = countVowelWords(mainString);
		words = new char* [size];
		extractVowelWords(mainString, words);
		break;
	case fileString:
		selectFile(fileName, file);
		file = fopen(fileName, "r");
		fileLength = countCharactersFromFile(file);
		mainString = new char[fileLength + 1];
		readFile(file, fileLength, mainString);
		fclose(file);
		size = countVowelWords(mainString);
		words = new char* [size];
		extractVowelWords(mainString, words);
		break;
	case inputString:
		size = 128;
		mainString = new char[size * 2];
		printf("\nВведите строку: ");
		gets_s(mainString, size);
		size = countVowelWords(mainString);
		words = new char* [size];
		extractVowelWords(mainString, words);
		break;
	default:
		printf("Ошибка");
	}

	do
	{
		showMenu();
		action = _getch();
		switch (action)
		{
		case '1':
			deleteAllPointers(mainString, words, size);
			choice = selectResource();
			if (choice == constString)
			{
				mainString = new char[strlen(resource) + 1];
				strcpy(mainString, resource);
				size = countVowelWords(mainString);
				words = new char* [size];
				extractVowelWords(mainString, words);
			}
			else if (choice == fileString)
			{
				selectFile(fileName, file);
				file = fopen(fileName, "r");
				fileLength = countCharactersFromFile(file);
				mainString = new char[fileLength + 1];
				readFile(file, fileLength, mainString);
				fclose(file);
				size = countVowelWords(mainString);
				words = new char* [size];
				extractVowelWords(mainString, words);
			}
			else
			{
				size = 128;
				mainString = new char[size * 2];
				printf("\nВведите строку: ");
				gets_s(mainString, size);
				size = countVowelWords(mainString);
				words = new char* [size];
				extractVowelWords(mainString, words);
			}
			break;
		case '2':
			printf("\n\n%s\n", mainString);
			break;
		case '3':
			showWords(words, size);
			break;
		case '4':
			writeWordsInFile(words, size);
			break;
		default:
			isAction = false;
			break;
		}
	} while (isAction);

	deleteAllPointers(mainString, words, size);
	return 0;
}
