/* Лабораторная работа №12, вариант 5
   Малышев Максим, 2 курс, гр. ПМИ-1 */

#include "Main.h"

void ShowInfo()
{
	cout << "\nЛабораторная работа №12, вариант 5";
	cout << "\nМалышев Максим, 2 курс, гр.ПМИ - 1\n\n";
}

void ShowMainMenu()
{
	cout << "Главное меню";
	cout << "\n 1) Выбор действия с матрицами типа short";
	cout << "\n 2) Выбор действия с матрицами типа Vector";
	cout << "\n x) Выход";
	cout << "\nВведите номер пункта: ";
}

void ShowShortMenu()
{
	cout << "Меню действий для матриц типа short:";
	cout << "\n 1) Перезаполнить матрицу";
	cout << "\n 2) Изменить размер матрицы";
	cout << "\n 3) Изменить (i, j) элемент матрицы";
	cout << "\n 4) Сравнить матрицы";
	cout << "\n 5) Скопировать одну матрицу в другую";
	cout << "\n 6) Очистить матрицу";
	cout << "\n 7) Показать матрицу";
	cout << "\n x) В главное меню";
	cout << "\nВведите номер пункта: ";
}

void ShowVectorMenu()
{
	cout << "Меню действий для матриц типа Vector:";
	cout << "\n 1) Перезаполнить матрицу";
	cout << "\n 2) Изменить размер матрицы";
	cout << "\n 3) Изменить (i, j) вектор матрицы";
	cout << "\n 4) Изменить компоненту (i, j) вектора матрицы";
	cout << "\n 5) Вычислить длину (i, j) вектора матрицы";
	cout << "\n 6) Сравнить 2 вектора матрицы";
	cout << "\n 7) Сравнить матрицы";
	cout << "\n 8) Скопировать одну матрицу в другую";
	cout << "\n 9) Очистить матрицу";
	cout << "\n 0) Показать матрицу";
	cout << "\n x) В главное меню";
	cout << "\nВведите номер пункта: ";
}

void ShowFillMatrixMenu()
{
	cout << "\nCпособ заполнения матрицы: ";
	cout << "\n 1) Вручную";
	cout << "\n 2) По порядку с шагом";
	cout << "\n 3) Случайными числами";
	cout << "\nВведите номер пункта: ";
}

template <class T>
TriangularMatrix<T> FillMatrix()
{
	char input;
	TriangularMatrix<T> matrix = TriangularMatrix<T>();
	do
	{
		ShowFillMatrixMenu();
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			matrix = FillMatrixManual<T>();
			break;
		case '2':
			matrix = FillMatrixIncremental<T>();
			break;
		case '3':
			matrix = FillMatrixRandom<T>();
			break;
		default:
			break;
		}
	} while (matrix.IsEmpty());

	system("cls");
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixManual()
{
	string input;
	TriangularMatrix<T> matrix = TriangularMatrix<T>();
	cout << "\nВведите размер матрицы: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "Размер матрицы должен быть целым числом!\n\n";
		return matrix;
	}

	if (size <= 0)
	{
		cout << "Размер матрицы должен быть больше 0!\n\n";
		return matrix;
	}
	if (is_same<T, short>::value) matrix = FillMatrixShortManual<T>(size);
	else if (is_same<T, Vector>::value) matrix = FillMatrixVectorManual<T>(size);
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixShortManual(int size)
{
	string input;
	TriangularMatrix<T> matrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("Введите (%d, %d) элемент: ", i + 1, j + 1);
			cin >> input;
			try
			{
				matrix(i, j) = stoi(input);
			}
			catch (const invalid_argument& e)
			{
				cout << "Значение элемента должно быть целым числом!\n\n";
				j--;
			}
		}
	}
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixVectorManual(int size)
{
	string input;
	TriangularMatrix<T> matrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("\nВведите (%d, %d) вектор: ", i + 1, j + 1);
			getline(cin, input);
			try
			{
				if constexpr (is_same_v<T, Vector>)
				{
					Vector vector(input);
					matrix(i, j) = vector;
				}
			}
			catch (const invalid_argument& e)
			{
				cout << e.what();
				j--;
			}
		}
	}
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixIncremental()
{
	string input;
	TriangularMatrix<T> matrix = TriangularMatrix<T>();
	cout << "\nВведите размер матрицы: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "Размер матрицы должен быть целым числом!\n\n";
		return matrix;
	}

	if (size <= 0)
	{
		cout << "Размер матрицы должен быть больше 0!\n\n";
		return matrix;
	}

	if (is_same<T, short>::value)
	{
		short startValue;
		short step;

		cout << "Введите начальное значение: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			startValue = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Начальное значение матрицы должно быть целым числом!\n\n";
			return matrix;
		}

		cout << "Введите шаг матрицы: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			step = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Шаг матрицы должен быть целым числом!\n\n";
			return matrix;
		}
		matrix = FillMatrixShortIncremental<T>(size, startValue, step);
	}
	else if (is_same<T, Vector>::value)
	{
		float startValue;
		float step;

		cout << "Введите начальное значение: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			startValue = stof(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Начальное значение матрицы должно быть вещественным числом!\n\n";
			return matrix;
		}

		cout << "Введите шаг матрицы: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			step = stof(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Шаг матрицы должен быть вещественным числом!\n\n";
			return matrix;
		}

		int lengthVector, stepLength;
		cout << "Введите начальную длину (кол-во компонент) вектора: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			lengthVector = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Начальная длина (кол-во компонент) вектора должна быть целым числом!\n\n";
			return matrix;
		}

		cout << "Введите шаг изменения длины (кол-ва компонент) вектора: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			stepLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Шаг изменения длины вектора (кол-ва компонент) должен быть целым числом!\n\n";
			return matrix;
		}
		if (lengthVector <= 0 || lengthVector + stepLength * size <= 0)
		{
			cout << "Длина вектора всегда должна быть > 0!\n\n";
			return matrix;
		}
		matrix = FillMatrixVectorIncremental<T>(size, startValue, step, lengthVector, stepLength);
	}
	return matrix;
}


template <class T>
TriangularMatrix<T> FillMatrixShortIncremental(int size, short startValue, short step)
{
	TriangularMatrix<T> matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
		{
			matrix(i, j) = startValue;
			startValue += step;
		}
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixVectorIncremental(int size, float startValue, float step, int lengthVector, int stepLength)
{
	TriangularMatrix<T> matrix(size);
	if constexpr (is_same_v<T, Vector>)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j <= i; j++)
			{
				matrix(i, j) = Vector(lengthVector);
				for (int k = 0; k < lengthVector; k++)
					matrix(i, j)[k] = startValue;
				startValue += step;
				lengthVector += stepLength;
			}
	}
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixRandom()
{
	string input;
	TriangularMatrix<T> matrix = TriangularMatrix<T>();
	cout << "\nВведите размер матрицы: ";
	// Размер
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "Размер матрицы должен быть целым числом!\n\n";
		return matrix;
	}
	if (size <= 0)
	{
		cout << "Размер матрицы должен быть больше 0!\n\n";
		return matrix;
	}
	// Миниммум
	short min;
	cout << "\nВведите минимальное значение: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try
	{
		min = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "Минимум должен быть целым числом!\n\n";
		return matrix;
	}
	// Максимум
	short max;
	cout << "\nВведите максимальное значение: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try
	{
		max = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "Максимум должен быть целым числом!\n\n";
		return matrix;
	}
	if (min > max)
	{
		cout << "Максимум не может быть больше минимума!\n\n";
		return matrix;
	}
	if (is_same<T, short>::value)
	{
		matrix = FillMatrixShortRandom<T>(size, min, max);
	}
	else if (is_same<T, Vector>::value)
	{
		// Минимальная длина
		cout << "\nВведите минимальную длину (кол-во компонент) вектора: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int minLength;
		try
		{
			minLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Минимальная длина (кол-во компонент) вектора должна быть целым числом!\n\n";
			return matrix;
		}
		if (size <= 0)
		{
			cout << "Минимальная длина (кол-во компонент) вектора должна быть больше 0!\n\n";
			return matrix;
		}
		// Максимальная длина
		cout << "\nВведите максимальную длину (кол-во компонент) вектора: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int maxLength;
		try
		{
			maxLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "Максимальная длина (кол-во компонент) вектора должна быть целым числом!\n\n";
			return matrix;
		}
		if (size <= 0)
		{
			cout << "Максимальная длина (кол-во компонент) вектора должна быть больше 0!\n\n";
			return matrix;
		}
		if (minLength > maxLength)
		{
			cout << "Максимальная длина (кол-во компонент) вектора не может быть больше минимального!\n\n";
			return matrix;
		}
		matrix = FillMatrixVectorRandom<T>(size, min, max, minLength, maxLength);
	}
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixShortRandom(int size, short min, short max)
{
	TriangularMatrix<T> matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			matrix(i, j) = rand() % (max - min + 1) + min;
	return matrix;
}

template <class T>
TriangularMatrix<T> FillMatrixVectorRandom(int size, short min, short max, int minLength, int maxLength)
{
	TriangularMatrix<T> matrix(size);
	float range = max - min;
	if constexpr (is_same_v<T, Vector>)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j <= i; j++)
			{
				float lengthVector = rand() % (maxLength - minLength + 1) + minLength;
				matrix(i, j) = Vector(lengthVector);
				for (int k = 0; k < lengthVector; k++)
					matrix(i, j)[k] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			}
	}
	return matrix;
}


void ActionsShortMatrix()
{
	bool isActive = true;
	char input;
	int i, j;
	TriangularMatrix<short>& matrix = matrixShort1;
	TriangularMatrix<short>& matrix2 = matrixShort2;
	system("cls");
	do
	{
		ShowShortMenu();
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			SelectShortMatrix() = FillMatrix<short>();
			break;
		case '2':
			SelectShortMatrix().SetSize(inputValue("новый размер"));
			break;
		case '3':
			matrix = SelectShortMatrix();
			i = inputValue("номер i элемента");
			j = inputValue("номер j элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i элемента должен быть >0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j элемента должен быть >0 и < размера матрицы\n\n";
				break;
			}
			matrix(i - 1, j - 1) = inputValue("значение элемента");
			break;
		case '4':
			matrixShort1 == matrixShort2 ? cout << "Матрицы равны!\n\n" : cout << "Матрицы НЕ равны!\n\n";
			break;
		case '5':
			matrix = SelectShortMatrix();
			matrix == matrixShort1 ? matrix2 = matrixShort2 : matrix2 = matrixShort1;
			matrix = matrix2;
			break;
		case '6':
			SelectShortMatrix().Clear();
			break;
		case '7':
			ShowShortMatrix(SelectShortMatrix());
			break;
		case 'x':
			isActive = false;
			break;
		default:
			cout << "\n\nПункт меню выбран неверно!\n";
			break;
		}
	} while (isActive);
}

void ActionsVectorMatrix()
{
	string vectorStr;
	bool isActive = true;
	char input;
	int i, j, k, i2, j2;
	TriangularMatrix<Vector>& matrix = matrixVector1;
	TriangularMatrix<Vector>& matrix2 = matrixVector2;
	system("cls");
	do
	{
		ShowVectorMenu();
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			SelectVectorMatrix() = FillMatrix<Vector>();
			break;
		case '2':
			SelectVectorMatrix().SetSize(inputValue("новый размер"));
			break;
		case '3':
			matrix = SelectVectorMatrix();
			i = inputValue("номер i элемента");
			j = inputValue("номер j элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			printf("\nВведите (%d, %d) вектор: ", i, j);
			getline(cin, vectorStr);
			try
			{
				matrix(i - 1, j - 1) = vectorStr;
			}
			catch (const invalid_argument& e)
			{
				cout << e.what();
			}
			break;
		case '4':
			matrix = SelectVectorMatrix();
			i = inputValue("номер i элемента");
			j = inputValue("номер j элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i строки элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j стоблца элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			k = inputValue("номер компоненты вектора");
			if (k < 1 || k > matrix(i, j).Size()) cout << "\nНомер k должен быть > 1 и < размера вектора\n\n";
			matrix(i - 1, j - 1)[k - 1] = inputFloatValue("значение компоненты");
			break;
		case '5':
			matrix = SelectVectorMatrix();
			i = inputValue("номер i строки элемента");
			j = inputValue("номер j столбца элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i строки элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j стоблца элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			try
			{
				printf("\nДлина (%d, %d) вектора матрицы = %0.3f\n", i, j, matrix(i, j).Length());
			}
			catch (const exception& e)
			{
				cout << "Ошибка: " << e.what() << "\n";
			}
			break;
		case '6':
			matrix = SelectVectorMatrix();
			i = inputValue("номер i строки 1 элемента");
			j = inputValue("номер j столбца 1 элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i строки элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j стоблца элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			matrix2 = SelectVectorMatrix();
			i2 = inputValue("номер i строки 2 элемента");
			j2 = inputValue("номер j столбца 2 элемента");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\nНомер i строки элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\nНомер j стоблца элемента должен быть > 0 и < размера матрицы\n\n";
				break;
			}
			if (matrix(i, j) > matrix2(i2, j2)) cout << "Длина 1 вектора больше\n";
			if (matrix(i, j) < matrix2(i2, j2)) cout << "Длина 1 вектора меньше\n";
			else cout << "Длины векторов равны\n";
			break;
		case '7':
			matrixVector1 == matrixVector2 ? cout << "Матрицы равны!\n\n" : cout << "Матрицы НЕ равны!\n\n";
			break;
		case '8':
			matrix = SelectVectorMatrix();
			matrix == matrixVector1 ? matrix2 = matrixVector2 : matrix2 = matrixVector1;
			matrix = matrix2;
			break;
		case '9':
			SelectVectorMatrix().Clear();
			break;
		case '0':
			ShowVectorMatrix(SelectVectorMatrix());
			break;
		case 'x':
			isActive = false;
			break;
		default:
			cout << "\n\nПункт меню выбран неверно!\n";
			break;
		}
	} while (isActive);
}

int inputValue(string nameValue)
{
	string input;
	int size;
	do
	{
		cout << "\nВведите " + nameValue + " матрицы:";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			size = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << nameValue + " должен быть целым числом!\n\n";
		}
		if (size <= 0) cout << nameValue + " должен быть больше 0!\n\n";
		else return size;
	} while (true);
}

float inputFloatValue(string nameValue)
{
	string input;
	float size;
	do
	{
		cout << "\nВведите " + nameValue + " матрицы:";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			size = stof(input);
			return size;
		}
		catch (const invalid_argument& e)
		{
			cout << nameValue + " должен быть вещественным числом!\n\n";
		}
	} while (true);
}

TriangularMatrix<short>& SelectShortMatrix()
{
	char number;
	bool isActive = true;
	system("cls");
	do
	{
		cout << "Выберите матрицу (1 или 2): ";
		cin >> number;
		isActive = number != '1' && number != '2';
		if (isActive) cout << "Введен неверный номер матрицы!\n";
	} while (isActive);

	if (number == '1') return matrixShort1;
	else return matrixShort2;
}

TriangularMatrix<Vector>& SelectVectorMatrix()
{
	char number;
	bool isActive = true;
	system("cls");
	do
	{
		cout << "Выберите матрицу (1 или 2): ";
		cin >> number;
		isActive = number != '1' && number != '2';
		if (isActive) cout << "Введен неверный номер матрицы!\n";
	} while (isActive);

	if (number == '1') return matrixVector1;
	else return matrixVector2;
}


void ShowShortMatrix(TriangularMatrix<short>& matrix)
{
	for (uint i = 0; i < matrix.Size(); i++)
	{
		for (uint j = 0; j < i + 1; j++)
		{
			printf("%4d", matrix(i, j));
		}
		printf("\n");
	}
}

void ShowVectorMatrix(TriangularMatrix<Vector>& matrix)
{
	for (uint i = 0; i < matrix.Size(); i++)
	{
		cout << " | ";
		for (uint j = 0; j < i + 1; j++)
		{
			cout << matrix(i, j).toString() << " | ";
		}
		printf("\n");
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	ShowInfo();
	cout << "Заполнение 1-ой матрицы типа short";
	matrixShort1 = FillMatrix<short>();

	cout << "Заполнение 2-ой матрицы типа short";
	matrixShort2 = FillMatrix<short>();

	cout << "Заполнение 1-ой матрицы типа Vector";
	matrixVector1 = FillMatrix<Vector>();

	cout << "Заполнение 2-ой матрицы типа Vector";
	matrixVector2 = FillMatrix<Vector>();

	bool isActive = true;
	char input;
	do
	{
		ShowMainMenu();
		cin >> input;
		switch (input)
		{
		case '1':
			ActionsShortMatrix();
			system("cls");
			break;
		case '2':
			ActionsVectorMatrix();
			system("cls");
			break;
		case 'x':
			isActive = false;
			break;
		default:
			cout << "\n\nПункт меню выбран неверно!\n";
			break;
		}
	} while (isActive);

	return 0;
}