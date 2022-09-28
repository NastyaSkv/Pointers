#include<iostream>
#include<ctime>  //���������� ��� ��������� �������
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------\n"
#define DATA_TYPE int //��� � �
template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T>void Print(T* arr, const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, T value);
template<typename T>T* pop_back(T* arr, int& n);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);

//#define EXECUTION_TIME

void main()
{
	setlocale(LC_ALL, "");

	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ��������� ������: "; cin >> cols;

	typedef double DataType;
	DataType** arr = Allocate<DataType>(rows, cols); // ��� �++
	//DATA_TYPE** arr = Allocate<DATA_TYPE>(rows, cols); // ��� �

#ifdef EXECUTION_TIME
	cout << "Memory allocated!" << endl;
	system("pause");
#endif //EXECUTION_TIME

#ifndef EXECUTION_TIME
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

	cout << "��������� ������ � ����� �������: " << endl;
	clock_t start = clock();
	arr = push_row_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	FillRand(arr[rows - 1], cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "������ ���������! Mission complete :-)" << endl;
	clock_t end = clock();
	cout << "����� ���������� ��������: " << end - start << " ������" << endl;
#endif //EXECUTION_TIME

	arr = pop_row_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
	cout << delimiter << endl;
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "��� ���������� ������� ������� ����� �������...\n";
	system("pause");
	start = clock();
#endif //EXECUTION_TIME

	push_col_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand();
	Print(arr, rows, cols);
	cout << delimiter << endl;
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	end = clock();
	CLOCK_PER_SEC;
	cout << "������� ��������! Mission complete :-)" << endl;
	cout << "����� ���������� ��������: " << end - start << " ������" << endl;
#endif //EXECUTION_TIME

	pop_col_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

	Clear(arr, rows);
}

template<typename T>T** Allocate(const int rows, const int cols)
{
	//1) ������� ������ ����������:
	T** arr = new T * [rows];
	//2) �������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand();
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T>void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template<typename T>T* push_back(T* arr, int& n, T value)
{
	//1) ������� �������� ������ ������� �������:
	T* buffer = new T[n + 1];

	//2) �������� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ����� ���� ��� ��� ������ ����������� �� ��������� ������� � ��������,
	//	 �������� ������ ������ �� �����, � ��� ����� �������:
	delete[] arr;

	//4) ��������� ����� ��������� ������� � ��������� 'arr' ������� ������ �������:
	arr = buffer;

	//5) � ������ ����� ����� ����� ����� �������� ��� ���:
	arr[n] = value;
	//��������� ������ ������ � ������� 'arr' �������� ��� ���� �������, 
	//� ������� ����� ��������� ��������.

	//6) ����� ���� ��� �� �������� � ������ �������, ���������� ��������� ������� ������������� �� 1
	n++;
	//7) Mission complete - ������� ��������!
	return arr;
}

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	/*//1) ������� �������� ������ ���������� ������� �������:
	T** buffer = new T * [rows + 1];
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ������� ����� (����������� ������):
	buffer[rows] = new T[cols]{};
	//5) ����� ���������� ������ � ������, ���������� ����� ������� ������������� �� 1:
	rows++;
	//6) ���������� ����� ������ �������:
	return buffer;*/ 
	//������������ ->
	return push_back(arr, rows, new T[cols]{});
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� ������ �� ������:
	delete[] arr[rows - 1];
	/*//2) �������������� ������ ����������:
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;*/ 
	//������������ ->
	return pop_back(arr, rows);
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		/*//1) ������� ����� ������ ������� ������� (1 ������� ������):
		T* buffer = new T[cols + 1]{};
		//2) �������� ��� �������� i-� ������ � ����� ������ (buffer)
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������:
		delete[] arr[i];
		//4) ��������� �������� ������ �����:
		arr[i] = buffer;*/
		//������������ ->
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	//5) ����� ���� ��� � ������ ������ �������� �������, 
	//	 � ������� ���������� ��� ���� �������
	cols++;
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;*/
		//������������ ->
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}