/* ������������ ������ �12, ������� 5
   ������� ������, 2 ����, ��. ���-1 */

#include "Main.h"

void ShowInfo()
{
	cout << "\n������������ ������ �12, ������� 5";
	cout << "\n������� ������, 2 ����, ��.��� - 1\n\n";
}

void ShowMainMenu()
{
	cout << "������� ����";
	cout << "\n 1) ����� �������� � ��������� ���� short";
	cout << "\n 2) ����� �������� � ��������� ���� Vector";
	cout << "\n x) �����";
	cout << "\n������� ����� ������: ";
}

void ShowShortMenu()
{
	cout << "���� �������� ��� ������ ���� short:";
	cout << "\n 1) ������������� �������";
	cout << "\n 2) �������� ������ �������";
	cout << "\n 3) �������� (i, j) ������� �������";
	cout << "\n 4) �������� �������";
	cout << "\n 5) ����������� ���� ������� � ������";
	cout << "\n 6) �������� �������";
	cout << "\n 7) �������� �������";
	cout << "\n x) � ������� ����";
	cout << "\n������� ����� ������: ";
}

void ShowVectorMenu()
{
	cout << "���� �������� ��� ������ ���� Vector:";
	cout << "\n 1) ������������� �������";
	cout << "\n 2) �������� ������ �������";
	cout << "\n 3) �������� (i, j) ������ �������";
	cout << "\n 4) �������� ���������� (i, j) ������� �������";
	cout << "\n 5) ��������� ����� (i, j) ������� �������";
	cout << "\n 6) �������� 2 ������� �������";
	cout << "\n 7) �������� �������";
	cout << "\n 8) ����������� ���� ������� � ������";
	cout << "\n 9) �������� �������";
	cout << "\n 0) �������� �������";
	cout << "\n x) � ������� ����";
	cout << "\n������� ����� ������: ";
}

void ShowFillMatrixMenu()
{
	cout << "\nC����� ���������� �������: ";
	cout << "\n 1) �������";
	cout << "\n 2) �� ������� � �����";
	cout << "\n 3) ���������� �������";
	cout << "\n������� ����� ������: ";
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
	cout << "\n������� ������ �������: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "������ ������� ������ ���� ����� ������!\n\n";
		return matrix;
	}

	if (size <= 0)
	{
		cout << "������ ������� ������ ���� ������ 0!\n\n";
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
			printf("������� (%d, %d) �������: ", i + 1, j + 1);
			cin >> input;
			try
			{
				matrix(i, j) = stoi(input);
			}
			catch (const invalid_argument& e)
			{
				cout << "�������� �������� ������ ���� ����� ������!\n\n";
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
			printf("\n������� (%d, %d) ������: ", i + 1, j + 1);
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
	cout << "\n������� ������ �������: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "������ ������� ������ ���� ����� ������!\n\n";
		return matrix;
	}

	if (size <= 0)
	{
		cout << "������ ������� ������ ���� ������ 0!\n\n";
		return matrix;
	}

	if (is_same<T, short>::value)
	{
		short startValue;
		short step;

		cout << "������� ��������� ��������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			startValue = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��������� �������� ������� ������ ���� ����� ������!\n\n";
			return matrix;
		}

		cout << "������� ��� �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			step = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��� ������� ������ ���� ����� ������!\n\n";
			return matrix;
		}
		matrix = FillMatrixShortIncremental<T>(size, startValue, step);
	}
	else if (is_same<T, Vector>::value)
	{
		float startValue;
		float step;

		cout << "������� ��������� ��������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			startValue = stof(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��������� �������� ������� ������ ���� ������������ ������!\n\n";
			return matrix;
		}

		cout << "������� ��� �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			step = stof(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��� ������� ������ ���� ������������ ������!\n\n";
			return matrix;
		}

		int lengthVector, stepLength;
		cout << "������� ��������� ����� (���-�� ���������) �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			lengthVector = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��������� ����� (���-�� ���������) ������� ������ ���� ����� ������!\n\n";
			return matrix;
		}

		cout << "������� ��� ��������� ����� (���-�� ���������) �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			stepLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "��� ��������� ����� ������� (���-�� ���������) ������ ���� ����� ������!\n\n";
			return matrix;
		}
		if (lengthVector <= 0 || lengthVector + stepLength * size <= 0)
		{
			cout << "����� ������� ������ ������ ���� > 0!\n\n";
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
	cout << "\n������� ������ �������: ";
	// ������
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int size;
	try
	{
		size = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "������ ������� ������ ���� ����� ������!\n\n";
		return matrix;
	}
	if (size <= 0)
	{
		cout << "������ ������� ������ ���� ������ 0!\n\n";
		return matrix;
	}
	// ��������
	short min;
	cout << "\n������� ����������� ��������: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try
	{
		min = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "������� ������ ���� ����� ������!\n\n";
		return matrix;
	}
	// ��������
	short max;
	cout << "\n������� ������������ ��������: ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try
	{
		max = stoi(input);
	}
	catch (const invalid_argument& e)
	{
		cout << "�������� ������ ���� ����� ������!\n\n";
		return matrix;
	}
	if (min > max)
	{
		cout << "�������� �� ����� ���� ������ ��������!\n\n";
		return matrix;
	}
	if (is_same<T, short>::value)
	{
		matrix = FillMatrixShortRandom<T>(size, min, max);
	}
	else if (is_same<T, Vector>::value)
	{
		// ����������� �����
		cout << "\n������� ����������� ����� (���-�� ���������) �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int minLength;
		try
		{
			minLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "����������� ����� (���-�� ���������) ������� ������ ���� ����� ������!\n\n";
			return matrix;
		}
		if (size <= 0)
		{
			cout << "����������� ����� (���-�� ���������) ������� ������ ���� ������ 0!\n\n";
			return matrix;
		}
		// ������������ �����
		cout << "\n������� ������������ ����� (���-�� ���������) �������: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int maxLength;
		try
		{
			maxLength = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << "������������ ����� (���-�� ���������) ������� ������ ���� ����� ������!\n\n";
			return matrix;
		}
		if (size <= 0)
		{
			cout << "������������ ����� (���-�� ���������) ������� ������ ���� ������ 0!\n\n";
			return matrix;
		}
		if (minLength > maxLength)
		{
			cout << "������������ ����� (���-�� ���������) ������� �� ����� ���� ������ ������������!\n\n";
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
			SelectShortMatrix().SetSize(inputValue("����� ������"));
			break;
		case '3':
			matrix = SelectShortMatrix();
			i = inputValue("����� i ��������");
			j = inputValue("����� j ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i �������� ������ ���� >0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j �������� ������ ���� >0 � < ������� �������\n\n";
				break;
			}
			matrix(i - 1, j - 1) = inputValue("�������� ��������");
			break;
		case '4':
			matrixShort1 == matrixShort2 ? cout << "������� �����!\n\n" : cout << "������� �� �����!\n\n";
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
			cout << "\n\n����� ���� ������ �������!\n";
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
			SelectVectorMatrix().SetSize(inputValue("����� ������"));
			break;
		case '3':
			matrix = SelectVectorMatrix();
			i = inputValue("����� i ��������");
			j = inputValue("����� j ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			printf("\n������� (%d, %d) ������: ", i, j);
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
			i = inputValue("����� i ��������");
			j = inputValue("����� j ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i ������ �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j ������� �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			k = inputValue("����� ���������� �������");
			if (k < 1 || k > matrix(i, j).Size()) cout << "\n����� k ������ ���� > 1 � < ������� �������\n\n";
			matrix(i - 1, j - 1)[k - 1] = inputFloatValue("�������� ����������");
			break;
		case '5':
			matrix = SelectVectorMatrix();
			i = inputValue("����� i ������ ��������");
			j = inputValue("����� j ������� ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i ������ �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j ������� �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			try
			{
				printf("\n����� (%d, %d) ������� ������� = %0.3f\n", i, j, matrix(i, j).Length());
			}
			catch (const exception& e)
			{
				cout << "������: " << e.what() << "\n";
			}
			break;
		case '6':
			matrix = SelectVectorMatrix();
			i = inputValue("����� i ������ 1 ��������");
			j = inputValue("����� j ������� 1 ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i ������ �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j ������� �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			matrix2 = SelectVectorMatrix();
			i2 = inputValue("����� i ������ 2 ��������");
			j2 = inputValue("����� j ������� 2 ��������");
			if (i < 1 || i > matrix.Size())
			{
				cout << "\n����� i ������ �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (j < 1 || j > matrix.Size())
			{
				cout << "\n����� j ������� �������� ������ ���� > 0 � < ������� �������\n\n";
				break;
			}
			if (matrix(i, j) > matrix2(i2, j2)) cout << "����� 1 ������� ������\n";
			if (matrix(i, j) < matrix2(i2, j2)) cout << "����� 1 ������� ������\n";
			else cout << "����� �������� �����\n";
			break;
		case '7':
			matrixVector1 == matrixVector2 ? cout << "������� �����!\n\n" : cout << "������� �� �����!\n\n";
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
			cout << "\n\n����� ���� ������ �������!\n";
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
		cout << "\n������� " + nameValue + " �������:";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			size = stoi(input);
		}
		catch (const invalid_argument& e)
		{
			cout << nameValue + " ������ ���� ����� ������!\n\n";
		}
		if (size <= 0) cout << nameValue + " ������ ���� ������ 0!\n\n";
		else return size;
	} while (true);
}

float inputFloatValue(string nameValue)
{
	string input;
	float size;
	do
	{
		cout << "\n������� " + nameValue + " �������:";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		try
		{
			size = stof(input);
			return size;
		}
		catch (const invalid_argument& e)
		{
			cout << nameValue + " ������ ���� ������������ ������!\n\n";
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
		cout << "�������� ������� (1 ��� 2): ";
		cin >> number;
		isActive = number != '1' && number != '2';
		if (isActive) cout << "������ �������� ����� �������!\n";
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
		cout << "�������� ������� (1 ��� 2): ";
		cin >> number;
		isActive = number != '1' && number != '2';
		if (isActive) cout << "������ �������� ����� �������!\n";
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
	cout << "���������� 1-�� ������� ���� short";
	matrixShort1 = FillMatrix<short>();

	cout << "���������� 2-�� ������� ���� short";
	matrixShort2 = FillMatrix<short>();

	cout << "���������� 1-�� ������� ���� Vector";
	matrixVector1 = FillMatrix<Vector>();

	cout << "���������� 2-�� ������� ���� Vector";
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
			cout << "\n\n����� ���� ������ �������!\n";
			break;
		}
	} while (isActive);

	return 0;
}